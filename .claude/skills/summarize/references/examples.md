# More distillation examples

Synthetic verbose statements paired with their distilled note, across common problem types. The pattern: drop story, I/O format, and bounds; keep objects, identity-defining conditions, and the objective; phrase the essence in the **simplest faithful terms** (plain English first, Markdown-math only when it earns its place); add the name if it is a known problem; add a one-line solution; then point at real variants to solve next, each framed by the gap it exposes.

## String

Verbose:
> You are given a message s of lowercase English letters. You may rearrange its characters however you like. Determine whether it can be rearranged into a palindrome. (1 ≤ |s| ≤ 10⁵.)

Output:
> **Essence:** Can the letters of a string be rearranged into a palindrome?
> **Also known as:** Palindrome Permutation (LeetCode).
> **Solution:** Character-frequency parity — at most one letter may have an odd count.
> **Solve next:**
> - Longest Palindrome you can build from the letters — same parity idea, now constructing a length; cements the counting.
> - Valid Palindrome after removing at most one character — shifts to two-pointer reasoning; a different tool for the same theme.
> - Count / find the longest palindromic substring — a real step up (Manacher, or a palindromic structure).

## Grid

Verbose:
> An n × m grid; each cell is land ('#') or water ('.'). Two land cells are the same island if adjacent horizontally or vertically. Count the islands. (1 ≤ n, m ≤ 10³.)

Output:
> **Essence:** In a grid of land and water cells, count the connected land regions (4-adjacency).
> **Also known as:** Number of Islands (LeetCode).
> **Solution:** Flood fill (BFS/DFS) from each unvisited land cell.
> **Solve next:**
> - Max Area of Island — same flood fill, track component sizes; cements the pattern.
> - Number of Islands II (land added over time) — forces union-find with incremental updates.
> - Surrounded Regions / capture-by-boundary — a twist on the boundary and adjacency rules.

## Counting

Verbose:
> Count the binary strings of length n with no two consecutive 1s. Answer modulo 10⁹ + 7. (1 ≤ n ≤ 10⁶.)

Output:
> **Essence:** Count length-$n$ binary strings with no two adjacent 1s.
> **Also known as:** Fibonacci-count (the no-two-adjacent structure behind House Robber and Zeckendorf).
> **Solution:** DP $f_n = f_{n-1} + f_{n-2}$.
> **Solve next:**
> - House Robber — the same no-two-adjacent rule, now maximizing a sum; cements the recurrence over values.
> - House Robber II (houses in a circle) — adds a wrap-around constraint; forces handling the cycle.
> - No k consecutive 1s — generalizes to a k-window DP; a clean step up.

## Number theory

Verbose:
> Given n positive integers, count the pairs (i, j), i < j, with gcd(aᵢ, aⱼ) = 1. (1 ≤ n ≤ 10⁵, 1 ≤ aᵢ ≤ 10⁶.)

Output:
> **Essence:** Count pairs $i < j$ with $\gcd(a_i, a_j) = 1$ among the given integers.
> **Also known as:** Coprime-pair counting.
> **Solution:** Count multiples per value + Möbius inversion (inclusion–exclusion over $\gcd$).
> **Solve next:**
> - Count pairs with $\gcd = g$ for each g — same divisor-counting, reported per value.
> - Sum of $\gcd$ over all pairs — steps up to gcd-summation via Euler's totient / divisor sums.
> - Count coprime triples — extends the inclusion–exclusion to three elements.

## Geometry (decision)

Verbose:
> Given n points in the plane and a value d, determine whether any two of them lie at Euclidean distance strictly less than d. (2 ≤ n ≤ 10⁵.)

Output:
> **Essence:** Do any two of the given planar points lie closer together than a distance d?
> **Also known as:** Closest-pair, decision form.
> **Solution:** Closest-pair by divide-and-conquer (or plane sweep); compare the minimum to d.
> **Solve next:**
> - Find the actual closest pair, not just yes/no — same algorithm, return the pair.
> - Count all pairs within distance d — a twist toward counting (sweep + balanced structure).
> - Closest pair in higher dimensions — a step up (k-d trees).

## Interval / greedy

Verbose:
> You are given n events, event i running from sᵢ to eᵢ. Attend as many as possible without two overlapping at once. What is the maximum? (1 ≤ n ≤ 10⁵.)

Output:
> **Essence:** From a set of intervals, choose the most that pairwise don't overlap.
> **Also known as:** Activity Selection / Interval Scheduling Maximization (LeetCode "Non-overlapping Intervals").
> **Solution:** Greedy — sort by right endpoint, repeatedly take the earliest-finishing compatible interval.
> **Solve next:**
> - Minimum rooms to host all intervals at once — a twist to a sweep or heap; different objective.
> - Weighted interval scheduling (each interval has a value, maximize total) — forces DP + binary search; a real step up.
> - The point covered by the most intervals — a twist to a difference-array / sweep.

Note how each essence stays as plain as the problem allows — reaching for symbols only where precision demands ($\gcd = 1$, the graph structure) — while every bound and every trace of the cover story is gone, the name gives a search handle, and the "solve next" lines point at real problems, each labelled by the gap it exposes.
