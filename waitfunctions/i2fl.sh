#!/bin/bash
startline=$1
filename=$2
labels=( $(cat signal1.txt) )
number=${#labels[@]}

#add comment

for i in `seq $number`
do

sed -i "$((startline+i))a\\  signal(${labels[$i]},myfunction);" $filename

done


