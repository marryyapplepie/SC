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

