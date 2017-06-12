#!/bin/bash

cd ..
for i in {0..10}
do
	./client output 10 int:$i
	sleep 5
done
