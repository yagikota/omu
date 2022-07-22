#!/bin/sh

# -----sample1-----
VAR1=1
VAR2=`expr 1 + 2`
VAR3=`date`

echo $VAR1 
echo $VAR2 
echo $VAR3

SCRIPT_NAME=$0 
ARGUMENTS=$* 
NUM_OF_ARGUMENTS=$# 
ARG_1=$1
ARG_2=$2

echo "This script name is $SCRIPT_NAME."
echo "These all arguments are [$ARGUMENTS]."
echo "The number of the arguments is $NUM_OF_ARGUMENTS." 
echo "The 1st argument is $ARG_1."
echo "The 2nd argument is $ARG_2."


# ----sample2-----
# if else
# if [ $1 -lt 0 ]
# then
# 	echo "input number $1 is less than 0."
# elif [ $1 -gt 0 ]
# then
# 	echo "input number $1 is greater than 0."
# else
# 	echo "input number $1 is equal to 0."
# fi

# -----sample3-----
# for loop
# for i in 0 1 2 3 4 5 6 7 8 9 10
# do
# 	echo "\$i is $i."
# done

# for VAR in Oh "It's fine" today.
# do
# 	echo $VAR
# done

# FILES="0 1 2 3 4 5"
# for i in $FILES
# do
# 	echo "\$$i is $i."
# done

# while loop
MESSAGE="0" 
NVAR=0
while test $NVAR -lt 10
do
	NVAR=`expr $NVAR + 1`
	MESSAGE="$MESSAGE $NVAR" 
	echo $NVAR
done
echo $MESSAGE

# infinite loop
# MESSAGE="0"
# NVAR=0
# while test true
# do
# 	NVAR=`expr $NVAR + 1`
# 	MESSAGE="$MESSAGE $NVAR"
# 	echo $NVAR
# 	if test $NVAR -ge 10
# 	then
# 		break
# 	fi
# done
# echo $MESSAGE

# read
# read VAR_1 VAR_2 VAR_3
# echo $VAR_1
# echo $VAR_2
# echo $VAR_3

# sleep
# INTERVAL=3
# while true
# do
# 	echo "Hello!"
# 	sleep $INTERVAL
# done
