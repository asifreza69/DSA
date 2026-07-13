# ⚡ Kadane's Algorithm

**Kadane's Algorithm** is an efficient technique used to find the **maximum sum subarray** in a single traversal. Instead of checking every possible subarray, it decides whether to extend the current subarray or start a new one at each element.

It is one of the most frequently asked algorithms in coding interviews and serves as the foundation for many optimization problems involving contiguous subarrays.

---

## 🎯 When to Use

Use Kadane's Algorithm when a problem asks for:

* Maximum Subarray Sum
* Maximum Circular Subarray Sum
* Maximum Difference Problems
* Maximum Product Subarray *(modified version)*
* Dynamic Programming on Arrays
* Optimization over Contiguous Subarrays

---

## 💡 Core Idea

Maintain two variables while traversing the array:

* **Current Sum** → Maximum subarray sum ending at the current index.
* **Maximum Sum** → Best answer found so far.

For every element:

1. Decide whether to:

   * Extend the current subarray, or
   * Start a new subarray from the current element.
2. Update the global maximum if the current sum is larger.

---

## 🧩 Variants

### 🔹 Classic Kadane's Algorithm

Find the maximum sum of a contiguous subarray.

### 🔹 Maximum Circular Subarray Sum

Handle circular arrays by combining Kadane's Algorithm with total array sum.

### 🔹 Maximum Product Subarray

Track both maximum and minimum products because multiplying by a negative number can swap them.

---

## 🚀 Advantages

* Eliminates the need for nested loops.
* Converts brute-force **O(n²)** solutions into **O(n)**.
* Requires only constant extra space.
* Simple, efficient, and widely applicable.

---

## 📌 Complexity

| Operation       | Complexity |
| --------------- | ---------: |
| Array Traversal |   **O(n)** |
| Extra Space     |   **O(1)** |

---

## 🛠️ Language

* C++

---

> **At every step, choose whether to continue the current subarray or start a new one. That's the essence of Kadane's Algorithm. 🚀**
