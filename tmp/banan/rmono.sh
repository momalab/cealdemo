#!/bin/sh

if [ "$1" = "" ] ; then
echo "Use filename"
exit
fi

./h2ban $1 > $1.bn
./monkeyDo $1.bn
rm $1.bn

