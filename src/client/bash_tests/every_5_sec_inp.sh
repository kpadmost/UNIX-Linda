#!/bin/bash

cd ..
for i in {0..10}
do
	./client input 10 int:*
	sleep 5
done
