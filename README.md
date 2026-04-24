# ps

## Problems

### Graph Algorithms

#### Graph Traversal

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

##### Flood Fill

- Given a grid of 0s and 1s, count the number of connected components of 1s.
  - Related Problems
    - [ ] CSES 1192
