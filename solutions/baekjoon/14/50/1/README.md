# 퇴사

> ID: BOJ 14501 \
> Level: Silver 3

## Description

Given two arrays $T$ and $P$, select a set of indices such that the sum of the
values in $P$ at those indices is maximized, and for each selected index $i$,
the next selected index must be greater than or equal to $i + T[i]$.

## Solution

### Dynamic Programming

> Implementation: [C++ (0ms, 2020KB)](./src/a.cpp)
