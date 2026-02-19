# Problems

## Data Structures

### Stack

### Queue

### Priority Queue

- Find the minimum value in a sliding window of size $k$ as it moves through a
  sequence of numbers.
  - This problem can also be solved using a deque data structure.
  - Related Problems

    |     Problem ID     | Notes |
    | :----------------: | :---: |
    | BOJ 11003 (Gold 1) |       |

- Given $n$ intervals, find the minimum number of slots required to place the
  intervals without overlapping.
  - Related Problems

    |   Problem ID   |               Notes               |
    | :------------: | :-------------------------------: |
    | CSES 1164 (??) | Find the slot index for each pair |

- Given an array of integers $A$, we can construct a sequence of integers $s$
  such that $s_0 = 1$ and $s_i = s_{i-1} A[k] (i\gt 0)$. For a target number
  $t$, find the minimum elements selected from any $s$ such that their sum is
  equal to $t$.
  - Related Problems

    |   Problem ID    | Notes |
    | :-------------: | :---: |
    | SWEA 10806 (D6) |       |

#### Double-Ended Priority Queue

- Implement a priority queue that can insert elements and extract the maximum
  and minimum elements.
  - Related Problems

    |    Problem ID     | Notes |
    | :---------------: | :---: |
    | BOJ 7662 (Gold 4) |       |

### Hash Table

- Given two sets of strings, find the intersection of the two sets.
  - Related Problems

    |   Problem ID   |               Notes               |
    | :------------: | :-------------------------------: |
    | SWEA 2948 (D3) | Find the size of the intersection |

- Given a grid of characters and a list of words, count how many times each word
  can be formed by starting from any cell in the grid and moving to adjacent
  cells.
  - Related Problems

    |     Problem ID     | Notes |
    | :----------------: | :---: |
    | BOJ 20166 (Gold 4) |       |

### Union-Find

Union-find is the problem of maintaining a collection of disjoint sets and
supporting two operations, union and find. Disjoint sets are sets where no two
sets have any elements in common. Union merges two sets into a single set and
find returns the set that contains a given element.

Union-find can be implemented using a forest of trees. Path compression and
union-by-rank can be used to optimize the union-find data structure to make the
graph less skewed.

Union-find operations can be reversed when using union-by-rank methods. This can
be used for undoing union operations.

- Given $n$ disjoint sets, perform union and find operations.
  - Related Problems

    |    Problem ID     | Notes |
    | :---------------: | :---: |
    | BOJ 1717 (Gold 5) |       |

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

- Given a value $N$ and a function $f(x)$, find the value $k$ such that
  $f(k) = N$.
  - Related Problems

    |   Problem ID   |            Notes            |
    | :------------: | :-------------------------: |
    | SWEA 9843 (D5) | $f(x) = \frac{x(x + 1)}{2}$ |

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

- Given an undirected graph, find the number of connected components in the
  graph.
  - If the graph is given as a list of edges, we can also use union-find to
    solve this problem.

  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 7465 (D4) |       |

- Given an unweighted undirected graph, find the minimum number of edges
  required to make the graph connected.
  - Related Problems

    |   Problem ID   |                        Notes                        |
    | :------------: | :-------------------------------------------------: |
    | CSES 1666 (??) | Return any valid set of edges that need to be added |

#### Depth First Search (DFS)

#### Breadth First Search (BFS)

#### Bipartite Graph Check

- Given an undirected graph, split the nodes into two sets such that there is no
  edge between two nodes in the same set.
  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | CSES 1668 (??) |       |

### Topological Sort

- Given a directed acyclic graph, find a topological ordering of its vertices.
  - Related Problems

    | Problem ID | Notes |
    | :--------: | :---: |
    |  BOJ 2252  |       |

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

- Given $n$ coordinates, find the minimum spanning tree of the complete graph
  formed by the Euclidean distances between the coordinates.
  - Related Problems

    |   Problem ID   | Notes |
    | :------------: | :---: |
    | SWEA 1251 (D4) |       |

## Tree Algorithms

### Tree Diameter

### Binary Lifting

### Lowest Common Ancestor (LCA)

### Euler Tour Technique

## Range Query

- Given an array of integers, answer multiple queries of point updates and range
  queries.
  - Related Problems

    |   Problem ID    |                     Notes                     |
    | :-------------: | :-------------------------------------------: |
    | SWEA 14726 (??) | Range queries ask for the maximum and minimum |

### Prefix Sum

- Given an array of integers, count the number of subarrays that have a sum
  equal to a target value.
  - Related Problems

    |   Problem ID   |                         Notes                          |
    | :------------: | :----------------------------------------------------: |
    | CSES 1661 (??) |                                                        |
    | CSES 1662 (??) | Count the number of subarrays where $\sum{S}\mod n =0$ |

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
