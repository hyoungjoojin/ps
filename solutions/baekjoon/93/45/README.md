# 디지털 비디오 디스크 (DVDs)

> ID: BOJ 9345 \
> Level: Platinum 3

## Description

Given an array of integers 1 to $N$, we perform $M$ operations which are either
of the following.

- Swap two elements in the array.
- Find if between two given indices $i$ and $j$, check if all integers between
  $i$ and $j$ are present in the subarray of the array between $i$ and $j$
  regardless of the order.

## Solution

### Segment Tree

> Implementation: [C++ (156ms, 4460KB)](./src/a.cpp)
