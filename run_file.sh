#!/bin/bash

file=${1/%".cpp"}
g++ $1 -o $file && ./$file
rm $file
