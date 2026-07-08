---
name: summarize
description: Distill a competitive-programming or coding-interview problem the user has solved into a compact Markdown note and connect it to their learning path. Reduce the statement to its essence in the simplest faithful terms — plain concise English by default, with Markdown-math (LaTeX) only when words get clumsy or imprecise. Then add the problem's canonical name if it is a well-known one (textbook, research, or platforms like LeetCode), one concise line naming the solving technique or key idea, and a short list of related problems to solve next — similar ones plus harder variants of the same idea — to expose and fill gaps in the user's knowledge. Use whenever the user pastes a problem statement (Codeforces, AtCoder, LeetCode, CSES, Programmers, Samsung-style, or similar) and asks to summarize, compress, distill, or note it. Web search is encouraged to confirm the name and to surface real, findable variants rather than inventing problems.
---

# Summarize — Problem Note & Learning-Path Builder

A good problem note is three things at once: a memory hook that reloads the solved problem into the user's head instantly, a label that tells them what it is called, and a signpost to what they should learn next. Keep it dense — the shortest faithful phrasing of the problem, its name if it has one, the one-line technique, and a few concrete next problems that stretch the same idea to expose where the user's knowledge thins out.

## Essence — the simplest faithful phrasing

Plain, concise natural language is the default. Introduce mathematical notation *only* when plain words would be clumsy, long, or ambiguous — a loose, readable definition is the goal, not formality.

- If one clear English sentence captures it, stop there. "For every element, find the nearest smaller element to its left." is already perfect — do not dress it up in symbols.
- Reach for notation only when English strains: nested quantifiers, precise set or graph structure, exact objective functions, modular or algebraic conditions. Then write Markdown-math (LaTeX) — `$...$` with `\le`, `\sum`, `\subseteq`, `\gcd`, and so on — never raw Unicode symbols.
- Test: if making the sentence precise would take three subordinate clauses, switch to notation; otherwise keep the words.

Whatever the form: strip story, flavor, input/output format, and size bounds; keep the identity-defining conditions and the exact objective; and stay faithful — never drop a detail that changes the answer.

## Also known as — if it has a name

If the problem is a recognized or classic one, name it — the name is itself a strong memory handle and a search key for more practice. Names come from textbooks and the literature ("Longest Increasing Subsequence", "maximum subarray / Kadane's"), a canonical named problem, or a platform identity ("LeetCode: Next Greater Element", a well-known Codeforces or AtCoder problem).

- **Use web search to confirm the exact name or number when you are not certain.** A verified handle beats a guess, and a wrong ID sends the user to the wrong problem.
- If it is not a known named problem, omit this line — never invent a name.

## Solution — one line

A single concise line naming the technique or key idea that cracks it: e.g. "monotonic stack", "binary search on the answer + greedy check", "segment tree with lazy propagation", "0/1 knapsack DP". Just the crux — no walkthrough, proof, or code. One line of math (a recurrence) is fine. A fuller worked solution is a separate, explicit request; the default stays one line.

## Solve next — variants that find and fill the gaps

This is the growth engine, and the real reason the note is worth making. Offer about three related problems that stretch the same core idea, ordered similar to harder, and for **each** say *what new idea it forces* — the point is to surface the user's missing links, not just to list problems.

Vary along different axes so the set probes real gaps:
- a **near-twin** that cements the pattern,
- a **structural twist** that changes the setting (array to tree, static to with-updates, one query to many, add a weight or constraint),
- a **genuine step up** — a harder constraint or a generalization that demands a stronger technique.

Ground every suggestion in reality:
- **Prefer real, findable problems** on the user's platforms (Codeforces, AtCoder, LeetCode, CSES, Programmers). **Web search is encouraged** to pull concrete problems with a name, number, or link — do not fabricate problems, since invented ones are uncalibrated and may not exist. If you cannot verify a specific problem, describe the variant generically ("the same but with point updates") rather than inventing a fake identifier.
- Frame each as a gap to close: "if you don't immediately see how to handle updates, that is the segment-tree gap — solve [problem]." One line each.

## Output shape

Assemble as compact, labelled Markdown. Omit any line that does not apply (no name → drop "Also known as"). Skeleton:

> **Essence:** [plain phrasing; math only if needed]
> **Also known as:** [name / platform handle]
> **Solution:** [one-line technique]
> **Solve next:**
> - [near-twin] — cements [idea].
> - [structural twist] — forces [new idea].
> - [step up] — needs [stronger technique].

Essence and solution stay tight; "Solve next" is the only place length grows, and even those lines stay one each.

## Faithful, dense, honest

Strip noise but never meaning. Do not pad. Do not invent names or problems — when you rely on web search, point to what you actually found. The note's whole value is that it is short, correct, and points somewhere real.

## Examples

**Example 1 — plain language needs no math**

Input (verbose):
> Given an array of n integers, for each position output the value of the nearest element to its left that is strictly smaller than it, or -1 if there is none. (1 ≤ n ≤ 10⁵.)

Output:
> **Essence:** For each element, find the nearest strictly-smaller element to its left (or none).
> **Also known as:** Previous Smaller Element — the classic monotonic-stack problem, mirror of LeetCode "Next Greater Element".
> **Solution:** Monotonic (increasing) stack, one left-to-right pass.
> **Solve next:**
> - Next Greater Element — the same idea mirrored right-to-left; cements the monotonic-stack pattern.
> - Largest Rectangle in a Histogram — uses previous- and next-smaller on both sides; forces you to fold two passes into an area computation.
> - Sum of Subarray Minimums — same span idea, but you sum contributions under a modulus; steps up to counting plus overflow care.

**Example 2 — math earns its place**

Input (verbose):
> There are n cities and m two-way roads; road j takes wⱼ minutes. Starting at city 1, find the least total time to reach city n, or -1 if impossible.

Output:
> **Essence:** Weighted undirected graph $G = (V, E)$, weights $\ge 0$; shortest-path distance from vertex $1$ to vertex $n$ (or $\infty$ if unreachable).
> **Also known as:** Single-source shortest path, non-negative weights.
> **Solution:** Dijkstra from vertex $1$.
> **Solve next:**
> - Same graph but some edges are negative — forces Bellman–Ford; Dijkstra breaks.
> - Shortest distance between every pair of cities — generalizes to Floyd–Warshall or repeated Dijkstra.
> - Allow up to k edges taken for free (a state per node) — steps up to shortest path on a layered / state graph.

For more transformations across problem types, read `references/examples.md`.
