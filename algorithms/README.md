# Algorithms Reference

## BFS

- if we want to traverse through all the edges in the graph, we can use BFS but
  do the visited check like Prim's algorithm

## String Algorithms

### Suffix Array

The suffix array is an array constructed from a string $s$ such that the $i$-th
element of the suffix array is the starting index of the $i$-th
lexicographically smallest suffix of $s$.

The LCP (Longest Common Prefix) array is an array constructed from a string $s$
and its suffix array such that the $i$-th element of the LCP array is the length
of the longest common prefix of the suffixes starting at the indices given by
the $i$-th and $(i-1)$-th elements of the suffix array. The first element of the
LCP array is usually defined to be 0.

## Data Structures

### Priority Queue

- Double-Ended Priority Queue
  - `std::multiset`
    - both allow duplicate, can find highest priority in O(1), insert in O(log
      n)
    - multiset can search for other elements
    - multset returns pointer to the element, can use iterator
    - pq uses heap, multiset uses balanced binary search tree
  - Lazy Deletion

- Consider using maps instead of unordered maps if the keys are plain integers
  because they can be vulnerable to hash collisions.

Prim's algorithm and Kruskal's algorithms can be used to find the minimum
spanning tree of a graph. For very dense graphs like complete graphs, Prim's
algorithm can be optimized to run in $O(n^2)$.

## Trie

### Suffix Trie

- find if "bc" is a substring of "abac"
  - is this better than KMP algorithm? Yes, because we can build the suffix trie
    once and then query multiple times in O(m) time, where m is the length of
    the query string. KMP algorithm would require O(n + m) time for each query,
    where n is the length of the original string.
- find the longest common prefix
  - find the lowest common ancestor of the two suffixes in the suffix trie, and
    the depth of that ancestor will give us the length of the longest common
    prefix.
- find the k-th lexicographical suffix
  - the dfs traversal of the suffix trie will give us the suffixes in
    lexicographical order, so we can keep a count of how many suffixes we have
    seen and return the k-th one when we reach it.

suffix tree -> compressed suffix trie

- suffix array?
- exact string matching
- substring matching
- longest common substring

ukkonen's algorithm, farach's suffix tree

LCP array?

- find the lexicographically smallest suffix of a string
- find the length of the longest common prefix
- search for a pattern in a string

bellman-ford algorithm

- KMP
- Manacher: Find the longest palindromic substring in O(n) time
- Aho-Corasick: Find all occurrences of a set of patterns in a text in O(n + m +
  z) time, where n is the length of the text, m is the total length of the
  patterns, and z is the number of matches found.

- problems
  - string matching: find if string P is a substring of string S
  - longest common prefix: find the longest common prefix of two strings S and T
