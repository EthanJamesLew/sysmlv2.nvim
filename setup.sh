#!/bin/bash

# Ensure we're in the plugin root directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$SCRIPT_DIR"

# Navigate to grammar directory
cd lua/sysmlv2/treesitter/grammar

# Clean any existing files
if [ -d "build" ]; then
    rm -rf build
fi
rm -rf src/parser.c src/tree_sitter node_modules

# Install dependencies and generate parser
#npm install
npx tree-sitter generate

# Verify parser.c was generated
if [ -f "src/parser.c" ]; then
    echo "Parser generated successfully!"
else
    echo "Error: parser.c was not generated!"
    exit 1
fi

echo "Parser setup complete!"
