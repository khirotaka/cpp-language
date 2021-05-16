#!/usr/bin/env bash

if [ $# -ne 0 ]; then
    clang++ -std=c++17 "$@"
else
    echo "ファイル名が指定されていません" >&2
fi

