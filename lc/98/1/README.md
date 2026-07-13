# Time Based Key-Value Store

> ID: LC 981 \
> Level: Medium

## Description

Design a structure supporting `set(key, value, timestamp)` (timestamps given in
strictly increasing order per key) and `get(key, timestamp)`, which returns the
value stored for key at the largest stored timestamp $\le$ the query timestamp.

## Solution

### Hash Table + Binary Search

> Implementation: [C++ (42ms, 136.40MB)](./src/a.cpp)
