#!/bin/bash

read -e -p "Enter path to file  " FILEPATH
#read -p "Enter n  " n

sed "2!D" $FILEPATH



<< 'MULTILINE-COMMENT'
numOfLines = wc -l $FILEPATH
if  [ numOfLines -eq 0 ]; then 
	echo Empty file 
else
	while [ "$i" -ls "$numOfLines" ]; do
		
 



<< 'MULTILINE-COMMENT'

#!/bin/bash
read -e -p "Enter path to file  " FILEPATH
flag=false
while [ "$flag" ==  false ]
do
        echo heeey

        if  [ ! -r $FILEPATH ] ||  [ -z $FILEPATH ]; then
                echo You entered incorrect filename
                read -e -p "Enter path to file  " FILEPATH
        else
                flag=true
        fi
done
echo $FILEPATH
read -p "Enter the line to change  " lineToChange
echo $linetoChange
read -p "Enter the new line  " newLine
echo $newLine
sed -i "" "s/$lineToChange/$newLine/" $FILEPATH

#path = $(git ls-files --full-name history_of_vim.txt)


stat -f "%z - %Sm"  -t "%Y-%m-%d %H:%M" history_of_vim.txt

shasum --algorithm 256 history_of_vim.txt

wc -l #number of lines 

MULTILINE-COMMENT
