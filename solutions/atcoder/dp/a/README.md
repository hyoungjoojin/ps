# A - Frog 1

> ID: ATCODER DP-A \
> Level: ??

## Description

Given are $N$ stones numbered from $1$ to $N$. The frog is on the stone $1$ and
wants to reach the stone $N$. The frog can jump from the stone $i$ to the stone
$j$ if and only if $j - i \leq K$. The cost of a jump from the stone $i$ to the
stone $j$ is $\lvert h_i - h_j \rvert$, where $h_i$ is the height of the stone
$i$. Find the minimum total cost for the frog to reach the stone $N$.

## Solution

### Dynamic Programming

> Implementation: [C++ (6ms, 6836KB)](./src/a.cpp)
