# Problems

## Simulation

- Simulate the state of a system over time based on the given rules and initial
  conditions.
  - Related Problems
    - [ ] BOJ 23290 (Gold 1)

- Find the optimal solution by simulating all possible configurations of a
  system.
  - Related Problems
    - [ ] BOJ 15683 (Gold 3)

## Complete Search Algorithms

### Backtracking

#### Traveling Salesman Problem (TSP)

- Given a set of points and a starting point, find the length of the shortest
  possible route that visits every point.
  - Related Problems
    - [ ] BOJ 4991 (Gold 1): The points are on a $N\times M$ grid with
          obstacles.

## Greedy Algorithms

- Make locally optimal choices at each step with the hope of finding a global
  optimum.
  - Related Problems
    - [ ] CODETREE VIRUS-DETECTOR (L4)
    - [ ] BOJ 13458 (Bronze 2): Duplicate of CODETREE VIRUS-DETECTOR.

## Data Structures

### Stack

### Queue

### Priority Queue

- Find the minimum value in a sliding window of numbers.
  - Algorithm
    1. This can be solved using a lazy deletion priority queue by maintaining a
       priority queue of pairs of values and indices.
  - Related Problems
    - [ ] BOJ 11003 (Gold 1)

- Find the minimum number of slots required to place $n$ intervals without
  overlapping.
  - Algorithm
    1. Take a greedy approach by sorting the intervals by their starting time
       and then taking the earliest finishing interval using a priority queue on
       each iteration.
  - Related Problems
    - [ ] CSES 1164 (??): For each interval, find the slot index it is placed
          in.

- Given an array of integers $A$, we can construct a sequence of integers $s$
  such that $s_0 = 1$ and $s_i = s_{i-1} A[k] (i\gt 0)$. For a target number
  $t$, find the minimum elements selected from any $s$ such that their sum is
  equal to $t$.
  - Related Problems
    - [ ] SWEA 10806 (D6)

#### Double-Ended Priority Queue

- Implement a priority queue that can insert elements and extract the maximum
  and minimum elements.
  - Algorithm
    1. This can be implemented using two priority queues with lazy deletion.
  - Related Problems
    - [ ] BOJ 7662 (Gold 4)

### Hash Table

- Given two sets of strings, find the intersection of the two sets.
  - Related Problems
    - [ ] SWEA 2948 (D3): Find the size of the intersection set.

- Given a grid of characters and a list of words, count how many times each word
  can be formed by starting from any cell in the grid and moving to adjacent
  cells.
  - Related Problems
    - [ ] BOJ 20166 (Gold 4)

### Union-Find

- Given $n$ disjoint sets, perform union and find operations.
  - Related Problems
    - [ ] BOJ 1717 (Gold 5)

## Dynamic Programming

### Longest Increasing Subsequence

### 0-1 Knapsack Problem

- Solve the 0-1 knapsack problem.
  - Related Problems
    - [ ] BOJ 12865 (Gold 5)

## Binary Search

### Parametric Search

- Given a function $f(x)$, find the maximum value of $x$ such that $f(x)$
  becomes true.
  - Related Problems
    - [ ] CF 1201C (1400): Find the maximum median of an array after performing
          at most $k$ increments.

- Given a value $N$ and a function $f(x)$, find the value $k$ such that
  $f(k) = N$.
  - Related Problems
    - [ ] SWEA 9843 (D5): $f(x) = \frac{x(x + 1)}{2}$

- Given integer arrays $A$ and $S$, we select $|S|$ non-overlapping intervals
  from $A$ where the $i$-th interval has a size of $S_i$. Find the minimum value
  of the maximum element selected from $A$.
  - Algorithm
    1. The problem can be solved by doing a parametric search on the maximum
       allowed element and then taking a greedy approach to check if it's
       possible to select the required intervals.
  - Related Problems
    - [ ] SWEA 3813 (D6)

## Graph Algorithms

### Graph Traversal Algorithms

- Given an undirected graph, find the number of connected components in the
  graph.
  - Algorithm
    1. This can be solved by doing a graph traversal on the graph and counting
       the number of times we need to start a new DFS/BFS to visit all nodes.
    2. This can also be solved using union-find by performing union operations
       for each edge and then counting the number of unique sets at the end.
  - Related Problems
    - [ ] SWEA 7465 (D4)

- Given an unweighted undirected graph, find the minimum number of edges
  required to make the graph connected.
  - Related Problems
    - [ ] CSES 1666 (??): Return any valid set of edges that need to be added.

#### Graph Traversal On Grids

- A grid of cells indicate water and land. For each time iteration, the water
  expands to adjacent land cells. Find how long it takes for two swans located
  on the grid can meet each other, where they can only move through water cells.
  - Algorithm
    1. This can be solved using a union-find data structure to keep track of the
       connected components of water cells and then simulating the expansion of
       water over time until the two swans are in the same connected component.
  - Related Problems
    - [ ] BOJ 3197 (Platinum 5)

### Bipartite Graph Check

- Given an undirected graph, split the nodes into two sets such that there is no
  edge between two nodes in the same set.
  - Related Problems
    - [ ] CSES 1668 (??)

### Topological Sorting

- Given a directed acyclic graph, find a topological ordering of its vertices.
  - Related Problems
    - [ ] BOJ 2252

### Shortest Path Algorithms

- Given a weighted directed graph with non-negative edges and a starting node
  $x$, find the shortest path from node $x$ to all other nodes.
  - Related Problems
    - [ ] BOJ 1753 (Gold 4)
    - [ ] BOJ 11779 (Gold 3): Construct the path from $x$ to a destination node.

- Given a weighted directed graph with non-negative edges, find the maximum
  round-trip distance from a node $x$ to all other nodes and back to $x$.
  - Related Problems
    - [ ] BOJ 1238 (Gold 3)

- Given a weighted undirected graph with non-negative edges, find the shortest
  path from a starting node to an ending node that passes through two specific
  nodes.
  - Related Problems
    - [ ] BOJ 1504 (Gold 4)

- Given a $n\times m$ grid of numbers, find the path from the top-left corner to
  the bottom-right corner such that the sum of numbers along the path is
  minimized, and return the sum.
  - Related Problems
    - [ ] SWEA 1249 (D4)

### Spanning Tree Algorithms

- Given $n$ coordinates, find the minimum spanning tree of the complete graph
  formed by the Euclidean distances between the coordinates.
  - Related Problems
    - [ ] SWEA 1251 (D4)
    - [ ] BOJ 1774 (Gold 3): Some edges already exist, and we need to find the
          minimum additional length required to connect all points.

## Tree Algorithms

## Range Query Problems

- Given a static array of integers, count the number of subarrays that have a
  sum equal to a target value.
  - Related Problems
    - [ ] CSES 1661 (??)
    - [ ] CSES 1662 (??): Count the number of subarrays where
          $\sum{S}\mod n =0$.

- Given an array of integers, answer multiple queries of point updates and range
  queries.
  - Related Problems
    - [ ] SWEA 14726 (??): Range minimum queries and range maximum queries.
    - [ ] CSES 1649 (??): Range minimum queries.

## String Algorithms

### Suffix Array

- Given a string $s$, find the $k$-th lexicographically smallest suffix of $s$.
  - Algorithms
    1. This can be solved in $O(N^2\log N)$ by generating all suffixes of the
       input string and then sorting the array of suffixes.

  - Related Problems
    - [ ] SWEA 1256 (D5)
