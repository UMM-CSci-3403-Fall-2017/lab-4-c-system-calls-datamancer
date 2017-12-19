#!/usr/bin/bash

cd $1
num2=$(find . -type f|wc -1)

num=$(find . -type d|wc -1)

echo "There were $num directories."
echo "There were $num2 regular files."
