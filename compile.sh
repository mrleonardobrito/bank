#!/bin/sh
gcc -c ./src/utils/utils.c -o utils.o
gcc -c ./src/cliente/cliente.c -o cliente.o
gcc -c ./src/report/report.c -o report.o
gcc -c ./src/node/node.c -o node.o
gcc -c main.c -o main.o

gcc utils.o cliente.o node.o report.o main.o -o main

rm *.o
