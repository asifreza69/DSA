# 🧠 Dynamic Programming — Core Pattern Problems

This folder contains a carefully curated set of Dynamic Programming problems that cover all major DP patterns asked in coding interviews.

The goal of this folder is simple:

> Solve a small number of representative problems so that revising them once is enough to refresh the entire Dynamic Programming topic.

---

## 🎯 Objective

Dynamic Programming can feel difficult at first, but most problems are based on a limited number of recurring patterns.

This folder organizes those patterns and includes the most important problems for each one.

After completing these problems, you should be able to:

- Identify DP patterns quickly
- Write recurrence relations confidently
- Convert recursion → memoization → tabulation
- Optimize space when possible
- Solve most interview-level DP questions

---

# 📚 Dynamic Programming Patterns

---

## 1️⃣ 1D DP

State depends on a single index.

### Core Problems
- Fibonacci Number
- Climbing Stairs
- Min Cost Climbing Stairs
- House Robber
- Decode Ways

---

## 2️⃣ 2D DP

State depends on two variables.

### Core Problems
- Unique Paths
- Minimum Path Sum
- Longest Common Subsequence
- Edit Distance

---

## 3️⃣ 0/1 Knapsack Pattern

For every item, either take it or skip it.

### Core Problems
- 0/1 Knapsack
- Subset Sum
- Partition Equal Subset Sum
- Target Sum

---

## 4️⃣ Unbounded Knapsack Pattern

Items can be taken unlimited times.

### Core Problems
- Coin Change
- Coin Change II
- Rod Cutting

---

## 5️⃣ String DP

Dynamic Programming on one or two strings.

### Core Problems
- Longest Common Subsequence
- Longest Palindromic Subsequence
- Distinct Subsequences
- Wildcard Matching
- Edit Distance

---

## 6️⃣ LIS Pattern

Subsequence optimization problems.

### Core Problems
- Longest Increasing Subsequence
- Number of LIS
- Maximum Sum Increasing Subsequence
- Russian Doll Envelopes

---

## 7️⃣ Grid DP

Movement through a matrix.

### Core Problems
- Unique Paths
- Minimum Falling Path Sum
- Cherry Pickup

---

## 8️⃣ Interval DP

Solve over subarrays or substrings.

### Core Problems
- Matrix Chain Multiplication
- Burst Balloons
- Palindrome Partitioning II

---

## 9️⃣ Partition DP

Split array or string into multiple parts.

### Core Problems
- Partition Array for Maximum Sum
- Minimum Cost to Cut a Stick
- Palindrome Partitioning

---

## 🔟 Stock DP

Buy/sell stock with constraints.

### Core Problems
- Best Time to Buy and Sell Stock II
- Stock with Cooldown
- Stock with Transaction Fee
- Stock with K Transactions

---

## 1️⃣1️⃣ Game DP

Two players making optimal decisions.

### Core Problems
- Predict the Winner
- Stone Game
- Optimal Strategy for a Game

---

## 1️⃣2️⃣ Counting DP

Count number of valid ways.

### Core Problems
- Combination Sum IV
- Dice Throw
- Unique Binary Search Trees

---

## 1️⃣3️⃣ Bitmask DP

Use subsets represented by bitmasks.

### Core Problems
- Traveling Salesman Problem
- Can I Win

---

## 1️⃣4️⃣ Digit DP

DP over digits of a number.

### Core Problems
- Count numbers satisfying digit constraints

---

## 1️⃣5️⃣ Tree DP

DP on tree structures.

### Core Problems
- House Robber III
- Binary Tree Cameras

---

# 🛠️ DP Problem Solving Framework

For every DP problem:

1. Define the state.
2. Identify choices.
3. Write recurrence relation.
4. Set base cases.
5. Add memoization.
6. Convert to tabulation.
7. Optimize space if possible.

---

# 🧠 Questions to Ask Yourself

Whenever you see a DP problem:

- What variables define the state?
- What are my choices?
- Is it counting or optimization?
- Can overlapping subproblems be reused?
- Which known pattern does it match?

---

# 🚀 Recommended Solving Order

1. 1D DP
2. 2D DP
3. Knapsack
4. Unbounded Knapsack
5. String DP
6. LIS Pattern
7. Grid DP
8. Interval DP
9. Partition DP
10. Stock DP
11. Game DP
12. Counting DP
13. Tree DP
14. Bitmask DP
15. Digit DP

---

# ⏱️ Complexity Cheat Sheet

| Pattern | Typical Complexity |
|------|------|
| 1D DP | O(n) |
| 2D DP | O(n²) |
| Knapsack | O(n × target) |
| String DP | O(n × m) |
| LIS | O(n log n) |
| Interval DP | O(n³) |
| Bitmask DP | O(2ⁿ × n) |
| Digit DP | O(pos × tight × state) |

---

# 🏆 Final Goal

Once you complete the problems in this folder, Dynamic Programming will become pattern recognition rather than trial and error.

If you can derive the recurrence relation, the implementation becomes straightforward.

> Master the pattern, and the problem becomes manageable.
