#!/bin/sh
gcc -c ./utils/utils.c -o utils.o
gcc -c ./cliente/cliente.c -o cliente.o
gcc -c ./node/node.c -o node.o
gcc -c ./report/report.c -o report.o
gcc -c main.c -o main.o


gcc utils.o cliente.o node.o report.o main.o -o main

rm *.o main
