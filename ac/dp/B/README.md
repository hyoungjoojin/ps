# Frog 2

> ID: AC DP-B

## Description

Given an array of integers and $k$, the cost of moving from position $i$ to $j$
is $|h_i - h_j|$. If we can only move from position $i$ to any position within
the range between $i + 1$ and $i + k$, find the minimum cost to move from the
start to the end.

## Solution

### Dynamic Programming

> Implementation: [C++ (13ms, 4460KB)](./src/a.cpp)
