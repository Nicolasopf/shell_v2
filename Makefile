SHELL:=/bin/bash
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic -std=gnu90
SRC=*.c
OUT=hsh

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
