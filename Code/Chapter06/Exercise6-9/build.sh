#! /bin/bash

build()
{
	g++ -c main.cpp chapter6.cpp
	g++ main.o chapter6.o -o main
}

clean()
{
	rm -f *.o main
}

if [ "$1" = "clean" ]; then
	clean
else
	build
fi

exit 0
