#!/bin/bash

for i in {1..10}
	do
		echo "================THREAD=================="
		./Assignment1 thread 100000000 11
		echo "================PROCESS================="
		./Assignment1 process 100000000 11
	done
