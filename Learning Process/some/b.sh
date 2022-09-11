#!/bin/bash

c++ main.cpp

for ((i=0; i<100; i++))
do
	./a.out >> f
done
cat f | grep -c "1"
