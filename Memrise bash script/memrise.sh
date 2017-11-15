#!/bin/bash
lesson_no=4
num=0
IFS='
'
cd ~/Documents/memrise/lesson$lesson_no
while read line
do
	((num++))
	say -v Nora -r 175 -o $num'_'$line.aac "$line"
done < ~/Documents/memrise/lesson$lesson_no.txt