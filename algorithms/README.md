# Algorithms

## Data Structures

### Stack

### Queue

### Hash Table

- Given two sets of strings, find the intersection of the two sets.
  - Related Problems

    |   Problem ID   |               Notes               |
    | :------------: | :-------------------------------: |
    | SWEA 2948 (D3) | Find the size of the intersection |

### Disjoint Set Union (DSU)

## Complete Search Algorithms

## Greedy Algorithms

## Dynamic Programming

### Longest Increasing Subsequence

### 0-1 Knapsack Problem

- Solve the 0-1 knapsack problem.
  - Related Problems

    |     Problem ID     | Notes |
    | :----------------: | :---: |
    | BOJ 12865 (Gold 5) |       |

## Binary Search

### Parametric Search

- Given integer arrays $A$ and $S$, we select $|S|$ non-overlapping intervals
  from $A$ where the $i$-th interval has a size of $S_i$. Find the minimum value
  of the maximum element selected from $A$.
  - The problem can be solved by doing a parametric search on the maximum
    allowed element and then taking a greedy approach to check if it's possible
    to select the required intervals.

  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 3813 (D6) |       |

## Graph Algorithms

### Graph Traversal Algorithms

#### Depth First Search (DFS)

#### Breadth First Search (BFS)

### Shortest Path Algorithms

#### Dijkstra's Algorithm

- Given a $n\times m$ grid of numbers, find the path from the top-left corner to
  the bottom-right corner such that the sum of numbers along the path is
  minimized, and return the sum.
  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 1249 (D4) |       |

- Given a directed graph with non-negative edge weights and a starting node $x$,
  find $\sum_{v\in V}{d_{xv}} + \sum_{v\in V}{d_{vx}}$, where $d_{ij}$ is the
  shortest path from node $i$ to node $j$.
  - Dijkstra's algorithm can be applied twice, once on the original graph and
    once on the reversed graph.

  - Related Problems

    | Problem ID | Notes |
    | :--------: | :---: |
    |            |       |

### Spanning Tree Algorithms

## Tree Algorithms

## String Algorithms

### Suffix Array

- Given a string $s$, find the $k$-th lexicographically smallest suffix of $s$.
  - This can also be solved in $O(N^2\log N)$ by generating all suffixes of the
    input string and then sorting the array of suffixes.

  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 1256 (D5) |       |

## Number Theory

## Combinatorics

## Geometry
