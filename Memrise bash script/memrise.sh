#!/bin/bash
lesson=lesson1
num=0
IFS='
'
cd ~/Documents/memrise/$lesson
while read line
do
	((num++))
	say -v Nora -r 150 -o $num'_'$line.aac "$line"
done < ~/Documents/memrise/$lesson.txt