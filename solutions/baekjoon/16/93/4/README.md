# 게임 닉네임

> ID: BOJ 16934 \
> Level: Gold 3

## Description

Given a list of nicknames, we shorten each nickname by making it the shortest
possible prefix of the original nickname that is not a prefix of any other
nickname. If there are multiple such prefixes, we choose the shortest one. If
there is no such prefix, we use the original nickname appended with the number
of times it has appeared so far.

## Solution

### Trie

> Implementation: [C++ (51ms, 5920KB)](./src/a.cpp)
