# 🪟 Sliding Window

The Sliding Window technique is used to efficiently process contiguous subarrays or substrings by maintaining a window of elements and adjusting its boundaries as needed.

Instead of recomputing results for every possible range, the window is expanded or contracted to satisfy the given conditions, leading to optimal solutions.

## 🎯 When to Use

* Fixed-size subarray problems
* Variable-size window problems
* Longest/shortest subarray or substring
* Frequency counting
* Maximum or minimum sum problems
* Problems involving distinct elements or character constraints

## 💡 Key Idea

Maintain a window using two pointers:

* Expand the window to include new elements.
* Shrink the window when the required condition is violated.
* Continuously update the answer based on the current window.

## 🧩 Types of Sliding Window

### 🔹 Fixed Size Window

The window size remains constant throughout the traversal.

### 🔹 Variable Size Window

The window expands and contracts dynamically according to the problem constraints.

## ⏱️ Complexity

* **Time Complexity:** Usually `O(n)`
* **Space Complexity:** `O(1)` to `O(k)` depending on the problem.

## 🛠️ Language

* C++

---

> **Don't recompute, slide the window.** 🚀
