#!/bin/bash

counter=0

for dir in "$@"
do
	pdftotext "$dir" ./1.txt
	./words
	./stripper
	./sort
	./reversi
	today=`date +%Y-%m-%d.%H:%M`_$counter
	mv 5.txt data/"$today".txt
	let "counter++"
	rm *.txt
done
