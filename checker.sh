#!/usr/bin/env bash

TESTS_PATH="/home/runner/shellv2/tests"

function main()
{
    checker "$@"; exit
}

function checker()
{
    cd "$TESTS_PATH"
    for file in ./checker/*.bash; do
        echo -n "$file "
        ./checker/checker.sh ../hsh "$file" || exit
        echo;
    done
}

## Entry point
main "$@"
