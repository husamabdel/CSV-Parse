#!/bin/bash

echo "Compiling csvParse...."
gcc csvParse.c charList.c -o csvParse

if [[ $? ]]
    then
        echo "Error in compilation! make sure you have GCC installed!"
        exit 1
fi

echo "Compilation Complete!"