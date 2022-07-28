#!/bin/sh

$1
if test $? -eq 0
then
echo "<$1> succeeded."
else
echo "<$1> failed."
fi