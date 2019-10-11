#!/bin/bash
if ! ls | grep "target.txt" > /dev/null; then
    echo "File does not exist"
    touch target.txt
    echo "File target.txt was created"
    echo "1" >> target.txt
fi
while true; do
    if ln -s target.txt target.txt.lock &> /dev/null; then
        LAST=`tail -1 target.txt.lock`
        echo $((LAST+1)) >> target.txt.lock
        rm target.txt.lock
    fi
done