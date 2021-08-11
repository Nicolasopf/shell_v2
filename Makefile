SHELL:=/bin/bash
betty-style="/home/runner/shellv2/.bin/betty/betty-style.pl"
betty-doc="/home/runner/shellv2/.bin/betty/betty-doc.pl"
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic -std=gnu90
SRC=*.c
OUT=hsh

all:
	@$(betty-style) $(SRC) *.h
	@$(betty-doc) $(SRC) *.h 1> /dev/null
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

test:
	@rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	valgrind -q ./$(OUT)
	@betty-style $(SRC) *.h
	@betty-doc $(SRC) *.h 1> /dev/null

