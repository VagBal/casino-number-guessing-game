#!/bin/bash

# Navigate to the project root directory
cd "$(dirname "$0")/.."

# Configure the project
cmake --preset debug

# Build the project
cmake --build --preset debug
