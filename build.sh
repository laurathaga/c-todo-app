#!/bin/bash

date
echo "Building Todo App"

gcc -o3 main.c ./lib/task.c ./lib/common.c ./lib/db.c -o main

echo "Builded successfuly"
