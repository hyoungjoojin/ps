# Problems

## Simulation

- Simulate the state of a system over time based on the given rules and initial
  conditions.
  - Related Problems
    - [ ] BOJ 23290 (Gold 1)
    - [ ] BOJ 21608 (Gold 5)
    - [ ] BOJ 14503 (Gold 5)
    - [ ] BOJ 20056 (Gold 4)
    - [ ] BOJ 20057 (Gold 3)
    - [ ] BOJ 20058 (Gold 3)

- Find the optimal solution by simulating all possible configurations of a
  system.
  - Related Problems
    - [ ] BOJ 15683 (Gold 3)
    - [ ] BOJ 2931 (Gold 2)

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

- Given a graph, find if two nodes are in the same connected component of the
  graph where edges can be added dynamically to the graph.
  - Related Problems
    - [ ] CSES 1676 (??): Find the number of connected components and the size
          of the largest connected component after each edge addition.

- Given a graph, find if adding an edge creates a cycle in the graph.
  - Related Problems
    - [ ] BOJ 20040 (Gold 4): Given a sequence of edges added to an initially
          empty graph, find the index of the first edge that creates a cycle.

## Dynamic Programming

- Given an array of elements, we can group two adjacent groups of elements
  together and merge them into one group with a cost equal to the sum of the two
  groups. Find the minimum cost of merging all the elements into one group.
  - Related Problems
    - [ ] BOJ 11066 (Gold 3)

- Given two arrays $T$ and $P$, select a set of indices such that the sum of the
  values in $P$ at those indices is maximized, and for each selected index $i$,
  the next selected index must be greater than or equal to $i + T[i]$.
  - Related Problems
    - [ ] BOJ 14501 (Silver 3)

### Longest Increasing Subsequence

### 0-1 Knapsack Problem

- Solve the 0-1 knapsack problem.
  - Related Problems
    - [ ] BOJ 12865 (Gold 5)

## Binary Search

- Given an array of integers, find two integers in the array such that their sum
  is closest to zero.
  - Related Problems
    - [ ] BOJ 2470 (Gold 5)

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

### Cycle Detection

- Given a weighted directed graph, find the length of the shortest cycle in the
  graph.
  - Algorithm
    1. If the graph is dense and the number of vertices is small, we can use the
       Floyd-Warshall algorithm to find the shortest paths between all pairs of
       vertices and then check for cycles.
  - Related Problems
    - [ ] BOJ 1956 (Gold 4): The graph is dense and the number of vertices is
          small.

#### Graph Traversal On Grids

- Given a grid of walls and empty spaces, find the distance between the top-left
  corner to the bottom-right corner.
  - Related Problems
    - [ ] BOJ 14442 (Gold 3): At most $k$ walls can be destroyed.

- Within a grid, a grid can have two states: $s$ and $t$. For each time
  iteration, the state of a cell changes from $s$ to $t$ if at least one of its
  adjacent cells is in state $t$. Given the initial states of the grid, find the
  state of the grid after $k$ time iterations.
  - Related Problems
    - [ ] BOJ 2636 (Gold 4): Cells change state only if they are conected to the
          outer layer of the grid. Find the number of time iterations required
          until all cells change state and the number of cells that change state
          in the last iteration.

- A grid of cells indicate water and land. For each time iteration, the water
  expands to adjacent land cells. Find how long it takes for two swans located
  on the grid can meet each other, where they can only move through water cells.
  - Algorithm
    1. This can be solved using a union-find data structure to keep track of the
       connected components of water cells and then simulating the expansion of
       water over time until the two swans are in the same connected component.
  - Related Problems
    - [ ] BOJ 3197 (Platinum 5)

#### Graph Traversal On Numbers

- Let $f$ be a function that transforms one integer to another integer. Given
  two integers $x$ and $y$, find the minimum number of times we need to apply
  $f$ to $x$ to get $y$.

- Let $f$ be a function that transforms one integer to another integer. Given a
  starting point $x$, find the maximum integer that can be obtained by applying
  $f$ to $x$ at most $k$ times.
  - Related Problems
    - [ ] BOJ 1039 (Gold 2): The function $f$ swaps two digits of the input
          integer.

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

- Given a weighted directed graph, find the path from a starting node to a
  destination node such that the path does not include any edge that is part of
  any shortest path from the starting node to the destination node.
  - Algorithm
    1. This can be solved by removing all edges that are part of any shortest
       path from the starting node to the destination node and then finding the
       shortest path in the remaining graph. Removing the edges can be done by
       building a reverse graph from the initial graph in the process of
       Dijkstra's algorithm and doing a graph traversal on the reverse graph to
       visit and remove all edges that are part of any shortest path.
  - Related Problems
    - [ ] BOJ 5719 (Platinum 5)

- Given a $n\times m$ grid of numbers, find the path from the top-left corner to
  the bottom-right corner such that the sum of numbers along the path is
  minimized, and return the sum.
  - Related Problems
    - [ ] SWEA 1249 (D4)

#### APSP Algorithms

- Given a weighted directed graph, find the shortest path between all pairs of
  vertices.
  - Related Problems
    - [ ] BOJ 11404 (Gold 4)

### Spanning Tree Algorithms

- Given $n$ coordinates, find the minimum spanning tree of the complete graph
  formed by the Euclidean distances between the coordinates.
  - Related Problems
    - [ ] SWEA 1251 (D4)
    - [ ] BOJ 1774 (Gold 3): Some edges already exist, and we need to find the
          minimum additional length required to connect all points.

## Tree Algorithms

### Dynamic Programming On Trees

- Given a tree, find the minimum vertex cover of the tree. The vertex cover of a
  tree is a set of vertices such that every edge of the tree is incident to at
  least one vertex in the set.
  - Related Problems
    - [ ] BOJ 2533 (Gold 3): Find the size of the minimum vertex cover.
    - [ ] BOJ 2213 (Gold 1): Find the maximum weight of an independent set of
          the tree and print the vertices in the set. The independent set of a
          graph is a set of vertices such that no two vertices in the set are
          adjacent.

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
    - [ ] BOJ 2042 (Gold 1): Range sum queries.
    - [ ] BOJ 9345 (Platinum 3): Range queries on the presence of integers in a
          range.

- Given an array of integers, answer multiple queries of range updates and point
  queries.
  - Related Problems
    - [ ] BOJ 16975 (Platinum 4): Range increment updates and point queries.

- Given an array $a$, for every element $a_i$, find the number of indices $j$
  such that $j\lt i$ and $a_j\gt a_i$.
  - Algorithms
    1. This problem can be solved using a segment tree on the inversion count of
       the array.
  - Related Problems
    - [ ] BOJ 1517 (Platinum 5): Given an array, find the number of swaps
          required to sort the array using a bubble sort algorithm.

## String Algorithms

### Suffix Array

- Given a string $s$, find the $k$-th lexicographically smallest suffix of $s$.
  - Algorithms
    1. This can be solved in $O(N^2\log N)$ by generating all suffixes of the
       input string and then sorting the array of suffixes.
  - Related Problems
    - [ ] SWEA 1256 (D5)
    - [ ] BOJ 11656 (Silver 4)
