# Rudolf and CodeVid-23

> ID: CF 1846G \
> Level: 1900

## Description

We are given $m$ pairs of $(a, b)$ where both $a$ and $b$ are bit strings of the
same length. For a pair, we can transform an input bit string $x$ into $x$ by
removing the 1 bits set in $a$ and adding the 1 bits set in $b$. We want to find
the minimum number of transformations needed to transform a given bit string $s$
into another bit string $t$ using the given pairs of transformations.

## Solution

### Dijkstra's Algorithm

> Implementation: [C++ (46ms, 100KB)](./src/a.cpp)
