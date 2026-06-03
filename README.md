# ps

## Problems

### LeetCode

|          ID           |              Title              | Difficulty |
| :-------------------: | :-----------------------------: | :--------: |
|    [LC 1](./lc/1)     |             Two Sum             |    Easy    |
|   [LC 20](./lc/20)    |        Valid Parentheses        |    Easy    |
|   [LC 53](./lc/53)    |        Maximum Subarray         |   Medium   |
|  [LC 204](./lc/20/4)  |          Count Primes           |   Medium   |
|  [LC 300](./lc/30/0)  | Longest Increasing Subsequence  |   Medium   |
|  [LC 344](./lc/34/4)  |         Reverse String          |    Easy    |
|  [LC 347](./lc/34/7)  |     Top K Frequent Elements     |   Medium   |
|  [LC 463](./lc/46/3)  |        Island Perimeter         |    Easy    |
|  [LC 703](./lc/70/3)  | Kth Largest Element in a Stream |    Easy    |
|  [LC 704](./lc/70/4)  |          Binary Search          |    Easy    |
| [LC 1314](./lc/13/14) |        Matrix Block Sum         |   Medium   |
| [LC 1922](./lc/19/22) |       Count Good Numbers        |   Medium   |

### Codeforces

|           ID           |                Title                | Difficulty |
| :--------------------: | :---------------------------------: | :--------: |
|  [CF 27A](./cf/27/A)   |              Next Test              |    1200    |
|  [CF 61A](./cf/61/A)   |      Ultra-Fast Mathematician       |    800     |
| [CF 230B](./cf/23/0/B) |              T-primes               |    1300    |
| [CF 265B](./cf/26/5/B) | Roadside Trees (Simplified Edition) |    1000    |
| [CF 304A](./cf/30/4/A) |       Pythagorean Theorem II        |    1200    |
| [CF 315B](./cf/31/5/B) |          Sereja and Array           |    1200    |
| [CF 368B](./cf/36/8/B) |         Sereja and Suffixes         |    1100    |
| [CF 456A](./cf/45/6/A) |               Laptops               |    1100    |
| [CF 467B](./cf/46/7/B) |         Fedor and New Game          |    1100    |

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

- **Can Make Palindrome from Substring**: Given a string, answer queries about
  whether a substring of the string can be rearranged to form a palindrome after
  replacing at most $k$ characters.
  - Related Problems
    - [ ] LC 1177 (Medium)

### Linked List

- Given a linked list, find the $n$-th node in the linked list from the head of
  the linked list.
  - Related Problems
    - [ ] LC 876 (Easy): Find the middle node of the linked list.

### Stack

- Implement a stack data structure.
  - Related Problems
    - [ ] LC 225 (Easy): Implement a stack using queues.

- **Valid Parentheses**: Given a string composed of parentheses characters,
  determine if the string is valid.
  - Related Problems
    - [ ] LC 20 (Easy): The string is composed of three types of parentheses
          characters.

### Hash Table

- **Longest Consecutive Sequence**: Given an unsorted array, return the length
  of the longest sequence consisting of consecutive elements.
  - Related Problems
    - [ ] LC 128 (Medium)

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

- **K-th Largest Element in a Stream**: Given a stream of integers and a value
  $k$, find the $k$-th largest element at any point in time.
  - Related Problems
    - [ ] AC ABC-234D (503): Given a permutation of integers from 1 to $N$, for
          each $i$ from $K$ to $N$, find the $K$-th largest element among the
          first $i$ elements of the permutation.

- **Task Scheduling**: Given an array of tasks, schedule them in a way that
  minimizes the total time taken to complete all tasks.
  - Related Problems
    - [ ] LC 621 (Medium): Each task takes 1 time unit to complete and there is
          a cooldown period of $n$ time units between two executions of the same
          task.
    - [ ] CSES 1164: Given a list of customers with their arrival and departure
          times, find the minimum number of rooms required to accommodate all
          customers and assign a room number to each customer.

- Given a stream of integers, either select or skip each integer in the stream
  to maximize some objective function while maintaining a certain constraint on
  the selected integers at any point in time.
  - Related Problems
    - [ ] CF 1800C2 (1100): Given a deck of $n$ cards, each card has either 0 or
          a positive integer value. For each positive integer value, we can
          either put the card on top of the deck or discard it. For every card
          with value 0, we can take a card from the top of the deck if the deck
          is not empty. Find the maximum sum of the values of the cards that
          were selected from the 0-value cards.
    - [ ] CF 1526C2 (1600): Given a sequence of $n$ integers, we either select
          and add the integer to our score or skip it. Find the maximum number
          of selected integers such that the score is always non-negative.

### Sorting

- **Merge Two Lists** : Given two sorted lists, merge them into a single sorted
  list.
  - Related Problems
    - [ ] LC 21 (Easy): Merge two sorted linked lists.
    - [ ] LC 23 (Hard): Merge $k$ sorted linked lists.

### Binary Search

- Given a sorted array and a target value, return the index of the target if it
  is found in the array.
  - Related Problems
    - [ ] LC 704 (Easy)
    - [ ] LC 658 (Medium): Given a sorted array, find the $k$ closest elements
          to a target value.

#### Parametric Search

- **Find the Smallest Divisor Given a Threshold**: Given an array of integers
  and a threshold value, find the smallest integer such that the sum of each
  number in the array divided by the integer is less than or equal to the
  threshold.
  - Related Problems
    - [ ] LC 1283 (Medium)

### Greedy Algorithms

- **Monotone Increasing Digits**: Given an integer $n$, find the largest number
  that is less than or equal to $n$ with monotone increasing digits.
  - Related Problems
    - [ ] LC 738 (Medium)

### Dynamic Programming

- **Maximum Subarray**: Given an array of integers, find the contiguous subarray
  with the largest sum and return its sum.
  - Related Problems
    - [ ] LC 53 (Medium)

- **Climbing Stairs**: Given an array of integers, for each step we can jump to
  the next index or the index after the next index from the current index.
  Starting from the first element of the array, find the number of ways to reach
  the end of the array.
  - Related Problems
    - [ ] AC DP-A: Find the minimum cost to reach the end of the array where the
          cost of stepping from index $i$ to index $j$ is
          $\lvert A[i] - A[j] \rvert$.

- **Coin Change I**: Given an array of integers $A$, find the number of distinct
  ways to write a target value $N$ as a sum of the elements in $A$ where the
  order of elements matters.
  - Related Problems
    - [ ] CSES 1633: $A=\lbrace 1, 2, 3, 4, 5, 6\rbrace$.
    - [ ] CSES 1635
    - [ ] CSES 1634: Find the minimum number of elements in $A$ required to
          write $N$ as a sum of the elements in $A$.

- **Maximal Square**: Given a grid of 0s and 1s, find the largest square
  containing only 1s and return its area.
  - Related Problems
    - [ ] LC 221 (Medium)

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

- Given a n-ary tree, find the maximum depth of the tree.
  - Related Problems
    - [ ] LC 559 (Easy)

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

- Given a weighted graph, find any valid shortest path from a starting node to a
  destination node.
  - Related Problems
    - [ ] CF 20C (1900): Find the shortest path from vertex 1 to vertex $N$.

- Find the shortest path from a starting state to a destination state given a
  set of rules for transforming one state to another state and the cost of each
  transformation.
  - Related Problems
    - [ ] CF 1846G (1900): The states are bit strings and the transformations
          are defined by pairs of bit strings.

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

- Given a binary tree, use recursion to find some property of the binary tree.
  - Related Problems
    - [ ] LC 226 (Easy): Given a binary tree, invert the binary tree by swapping
          left and right nodes for every single node of the tree.
    - [ ] LC 104 (Easy): Given a binary tree, return its maximum depth.

#### Binary Tree Traversal

- Given a binary tree, determine if it is a valid binary search tree.
  - Related Problems
    - [ ] LC 98 (Medium)

### String Algorithms

- Given an array of strings, find the longest common prefix string.
  - Related Problems
    - [ ] LC 14 (Easy)

### Mathematics

- Add two numbers.
  - Related Problems
    - [ ] LC 415 (Easy): The numbers are represented as strings.

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

### SQL

- [ ] LC 1341 (Medium): `GROUP BY`, `UNION ALL`
- [ ] LC 1978 (Easy): Subqueries
- [ ] LC 176 (Medium): Get second highest value in a table.
- [ ] LC 177 (Medium): Get $n$-th highest value in a table.
- [ ] LC 178 (Medium): Get the rank of each score in a table.
- [ ] LC 602 (Medium): `GROUP BY`, `ORDER BY`, `LIMIT`
- [ ] LC 1045 (Medium): `GROUP BY`, `HAVING`
- [ ] LC 1321 (Medium): Compute the moving average of weekly sales.
- [ ] LC 185 (Hard): Find the top three entities for each group in a table.
