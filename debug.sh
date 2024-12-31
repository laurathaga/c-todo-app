#!/bin/bash

echo "Building debug info..."
gcc -o0 main.c ./lib/task.c ./lib/common.c ./lib/db.c -ggdb -o debug_main
mv debug_main ./debug/
echo "Finished!"
