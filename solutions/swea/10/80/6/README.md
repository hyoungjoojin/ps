# 수 만들기

> ID: SWEA 10806 \
> Level: D6

## Description

Given starting values $x = 0$ and $d = 1$, with an array of integers $A$, we
iteratively perform either one of two operations for $x$: $x = x + d$ or
$d = A[i] d$. Find the minimum number of sum operations required to make $x$
equal to a target value $T$.

## Solution

### Priority Queue

> Implementation: [C++ (349ms, 6548KB)](./src/a.cpp)
