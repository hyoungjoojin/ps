# Problems

## Data Structures

### Stack

### Queue

### Priority Queue

- Find the minimum value in a sliding window of size $k$ as it moves through a
  sequence of numbers.
  - This problem can also be solved using a deque data structure.
  - Related Problems

    |     Problem ID     |    Notes    |
    | :----------------: | :---------: |
    | BOJ 11003 (Gold 1) | 최솟값 찾기 |

#### Double-Ended Priority Queue

- Implement a priority queue that can insert elements and extract the maximum
  and minimum elements.
  - Related Problems

    |    Problem ID     |      Notes       |
    | :---------------: | :--------------: |
    | BOJ 7662 (Gold 4) | 이중 우선순위 큐 |

### Hash Table

- Given two sets of strings, find the intersection of the two sets.
  - Related Problems

    |   Problem ID   |               Notes               |
    | :------------: | :-------------------------------: |
    | SWEA 2948 (D3) | Find the size of the intersection |

### Disjoint Set Union (DSU)

- Given $n$ disjoint sets, perform union and find operations.
  - Related Problems

    |    Problem ID     |    Notes    |
    | :---------------: | :---------: |
    | BOJ 1717 (Gold 5) | 집합의 표현 |

## Complete Search Algorithms

### Backtracking

#### Traveling Salesman Problem (TSP)

- Given a set of points and a starting point, find the length of the shortest
  possible route that visits every point.
  - Related Problems

    |    Problem ID     |                        Notes                        |
    | :---------------: | :-------------------------------------------------: |
    | BOJ 4991 (Gold 1) | The points are on a $N\times M$ grid with obstacles |

## Greedy Algorithms

- Related Problems

  |          Problem ID          | Notes |
  | :--------------------------: | :---: |
  | CODETREE VIRUS-DETECTOR (L4) |       |

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

- Given a weighted directed graph with non-negative edges and a starting node
  $x$, find the shortest path from node $x$ to all other nodes.
  - Related Problems

    |     Problem ID     |                       Notes                       |
    | :----------------: | :-----------------------------------------------: |
    | BOJ 1753 (Gold 4)  |                                                   |
    | BOJ 11779 (Gold 3) | Construct the path from $x$ to a destination node |

- Given a weighted directed graph with non-negative edges, find the maximum
  round-trip distance from a node $x$ to all other nodes and back to $x$.
  - Related Problems

    |    Problem ID     | Notes |
    | :---------------: | :---: |
    | BOJ 1238 (Gold 3) |       |

- Given a weighted undirected graph with non-negative edges, find the shortest
  path from a starting node to an ending node that passes through two specific
  nodes.
  - Related Problems

    |    Problem ID     | Notes |
    | :---------------: | :---: |
    | BOJ 1504 (Gold 4) |       |

- Given a $n\times m$ grid of numbers, find the path from the top-left corner to
  the bottom-right corner such that the sum of numbers along the path is
  minimized, and return the sum.
  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 1249 (D4) |       |

### Spanning Tree Algorithms

## Tree Algorithms

## Range Query

- Given an array of integers, answer multiple queries of point updates and range
  queries.
  - Related Problems

    |   Problem ID    |                     Notes                     |
    | :-------------: | :-------------------------------------------: |
    | SWEA 14726 (??) | Range queries ask for the maximum and minimum |

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
