#!/bin/bash

date
echo "Building Todo App"

gcc main.c ./lib/task.c ./lib/common.c ./lib/db.c -o main
