#!/usr/bin/env node

const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs');

// Handle version and help flags
if (process.argv.includes('--version') || process.argv.includes('-v')) {
    console.log('SysMLv2 Language Server v1.0.0');
    process.exit(0);
}

if (process.argv.includes('--help') || process.argv.includes('-h')) {
    console.log(`
SysMLv2 Language Server Wrapper

Usage:
  server-wrapper.js [options]

Options:
  --version, -v     Show version information
  --help, -h        Show this help message
  --stdio           Use stdio for communication (default)
`);
    process.exit(0);
}

// Create log directory
const logDir = '/tmp/sysmlv2-logs';
if (!fs.existsSync(logDir)) {
    fs.mkdirSync(logDir);
}

// Create log file
const timestamp = new Date().toISOString().replace(/[:.]/g, '-');
const logFile = fs.createWriteStream(`${logDir}/sysmlv2_${timestamp}.log`);

// Start the actual language server
const serverPath = path.join(__dirname, 'syside-languageserver.js');
const server = spawn('node', [serverPath, '--stdio'], {
    stdio: ['pipe', 'pipe', 'pipe']
});

let buffer = '';
let contentLength = null;

// Handle server's stdout
server.stdout.on('data', (data) => {
    logFile.write(`[stdout] ${data.toString()}\n`);
    
    try {
        buffer += data.toString();
        
        while (buffer.length > 0) {
            if (contentLength === null) {
                const match = buffer.match(/^Content-Length: (\d+)\r\n\r\n/);
                if (!match) break;
                
                contentLength = parseInt(match[1], 10);
                buffer = buffer.substring(match[0].length);
            }
            
            if (buffer.length >= contentLength) {
                const message = buffer.substring(0, contentLength);
                buffer = buffer.substring(contentLength);
                contentLength = null;
                
                // Try to parse the message to ensure it's valid JSON
                JSON.parse(message);
                
                // Forward LSP message
                const headers = `Content-Length: ${message.length}\r\n\r\n`;
                process.stdout.write(headers + message);
            } else {
                break;
            }
        }
    } catch (err) {
        logFile.write(`[error] Error processing message: ${err.message}\n`);
    }
});

// Forward stdin to server
process.stdin.pipe(server.stdin);

// Log stderr
server.stderr.on('data', (data) => {
    logFile.write(`[stderr] ${data.toString()}\n`);
});

// Handle process exit
server.on('exit', (code, signal) => {
    logFile.end(`Server exited with code ${code} and signal ${signal}\n`);
    process.exit(code);
});

process.on('SIGTERM', () => {
    server.kill('SIGTERM');
});

process.on('SIGINT', () => {
    server.kill('SIGINT');
});