#!/usr/bin/bash

DIR=$1

num=$(find "$DIR"/ -type d | wc -1)
num2=$(find "$DIR"/ -type f | wac -1)

echo "$num directories"
echo "$num2 regular files"
