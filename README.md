# ps

## Problems

### Array

- Given an array of integers containing $n$ distinct numbers taken from the
  range $0$ to $n$, find the one that is missing from the array.
  - Related Problems
    - [ ] LC 268 (Easy)

- **Two Sum**: Given an array of integers and a target sum, find any two values
  in the array that sum up to the target sum.
  - Algorithms
    1. This can be solved by using a hash table data structure to store the
       values of the array and their indices. For each element in the array, we
       can check if the complement exists in the hash table.
  - Related Problems
    - [ ] CSES 1640
    - [ ] LC 1 (Easy)

### Stack

- **Valid Parentheses**: Given a string composed of parentheses characters,
  determine if the string is valid.
  - Related Problems
    - [ ] LC 20 (Easy): The string is composed of three types of parentheses
          characters.

### Priority Queue

- **Top K Elements**: Given an array and a value $k$, find the $k$ largest
  elements in the array.
  - Algorithms
    1. This can be solved by sorting the array and returning the first $k$
       elements.
    2. This can also be solved by using a min-heap data structure to maintain
       the $k$ largest elements seen so far while iterating through the array.
  - Related Problems
    - [ ] LC 973 (Medium): Given an array of points on a 2D plane, find the $k$
          closest points to the origin.

### Sorting

- **Merge Two Lists** : Given two sorted lists, merge them into a single sorted
  list.
  - Related Problems
    - [ ] LC 21 (Easy): Merge two sorted linked lists.

### Binary Search

- Given a sorted array and a target value, return the index of the target if it
  is found in the array.
  - Related Problems
    - [ ] LC 704 (Easy)
    - [ ] LC 658 (Medium): Given a sorted array, find the $k$ closest elements
          to a target value.

### Dynamic Programming

- **Maximum Subarray**: Given an array of integers, find the contiguous subarray
  with the largest sum and return its sum.
  - Related Problems
    - [ ] LC 53 (Medium)

### Graph Algorithms

#### Graph Traversal

- Given an undirected graph, find the shortest path from a given starting node
  to a given destination node.
  - Related Problems
    - [ ] CSES 1667: Print any valid shortest path.

- Given an unweighted undirected graph, find the minimum number of new edges
  required to make the graph connected.
  - Related Problems
    - [ ] CSES 1666: Return any valid set of edges that need to be added.

- **Shortest Path Between Numbers**: Given a set of rules for transforming an
  integer to another integer, find the minimum required steps to transform a
  given integer $a$ to another integer $b$.
  - Algorithms
    1. If the output of the transformations do not overlap, we can use a
       brute-force approach by starting from $b$ and applying the
       transformations in reverse until we reach $a$.
  - Related Problems
    - [ ] CF 727A: $x$ can be transformed to $2x$ or $10+1$.

##### Depth-First Search

- Given a directed acyclic graph, count the number of children each node has.
  - Related Problems
    - [ ] CSES 1674

- Given a tree, find the number of leaf nodes that can be reached from the root
  without visiting more than $m$ consecutive colored nodes.
  - Related Problems
    - [ ] CF 580C

##### Graph Traversal on Grids

- Given a grid of 0s and 1s, count the number of connected components of 1s.
  - Related Problems
    - [ ] CSES 1192
    - [ ] LC 542 (Medium): For each cell in the grid, find the distance to the
          nearest 0.

- Given a grid of 0s and 1s, find the shortest path from a given starting point
  to a given destination point.
  - Related Problems
    - [ ] CSES 1193: Print any valid path.

- Given a grid of 0s and 1s, there is one entity of type A and multiple entities
  of type B that can each move one step in every iteration. Find if the entity
  of type A can reach the destination without being caught by the entities of
  type B.
  - Algorithms
    1. We can use a multi-source BFS to find the minimum time required for type
       B entities to reach each cell in the grid. Then, we can traverse the grid
       starting from entity A's position and check if it can reach the
       destination before any type B entity can reach the same cell.
  - Related Problems
    - [ ] CSES 1194: The destination is any border cell of the grid and if the
          entity of type A can reach the destination, print any valid path.

#### Shortest Path Algorithms

- Given a weighted graph, find the length of the shortest path from a starting
  node to all other nodes.
  - Related Problems
    - [ ] CSES 1671

#### Topological Sort

- Given a directed graph, determine if the graph contains a cycle and print any
  valid topological ordering of its vertices if the graph is acyclic.
  - Algorithms
    1. If the problem asks just to determine if the graph contains a cycle, we
       can use a DFS approach with colored nodes to detect cycles.
  - Related Problems
    - [ ] LC 207: Only determine if the graph contains a cycle.
    - [ ] LC 210: Return any valid topological ordering of the vertices.

### Tree Algorithms

#### Binary Tree Traversal

- Given a binary tree, determine if it is a valid binary search tree.
  - Related Problems
    - [ ] LC 98 (Medium)

### Geometry

#### CCW

- Given three points, determine whether the points are collinear, or whether the
  third point is on the left or right side of the directed line from the first
  point to the second point.
  - Related Problems
    - [ ] CSES 2189

### Bit Manipulation

- Given an integer, find the number of 1s in its binary representation.
  - Related Problems
    - [ ] LC 191 (Easy)
