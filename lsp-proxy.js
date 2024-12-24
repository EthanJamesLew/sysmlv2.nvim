#!/usr/bin/env node

const { spawn } = require('child_process');
const fs = require('fs');

const serverPath = process.argv[2];
if (!serverPath) {
    console.error('Server path must be provided');
    process.exit(1);
}

const server = spawn('node', [serverPath, '--stdio']);
const logFile = fs.createWriteStream('/tmp/syside-lsp-filtered.log');

// Log and forward server output
server.stdout.on('data', (data) => {
    // skip if jsonrpc is not in the string
    if (!data.toString().includes('\{') && !data.toString().includes('Content-Length:')) {
        return;
    }
    logFile.write(`From Server: ${data}\n---\n`);
    process.stdout.write(data);
});

// Log stderr
server.stderr.on('data', (data) => {
    logFile.write(`[stderr] ${data}\n`);
});

// Log and forward stdin to server
process.stdin.on('data', (data) => {
    logFile.write(`From Client: ${data}\n---\n`);
    server.stdin.write(data);
});

server.on('exit', (code) => {
    logFile.end();
    process.exit(code);
});

process.on('uncaughtException', (err) => {
    logFile.write(`[error] ${err.toString()}\n`);
});
