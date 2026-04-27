# ps

## Problems

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

### Shortest Path Algorithms

- Given a weighted graph, find the length of the shortest path from a starting
  node to all other nodes.
  - Related Problems
    - [ ] CSES 1671
