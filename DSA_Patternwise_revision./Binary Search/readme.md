# 🔍 Binary Search

**Binary Search** is a divide-and-conquer algorithm used to efficiently search within a **sorted search space**. Instead of checking every element, it repeatedly halves the search space until the desired answer is found.

Although it is commonly used on sorted arrays, Binary Search can also be applied to **answer spaces**, **matrices**, and **optimization problems** where the search space exhibits a monotonic property.

---

## 🎯 When to Use

Use Binary Search when a problem involves:

* Searching in a sorted array
* Finding the first or last occurrence of an element
* Lower Bound / Upper Bound
* Searching in a sorted matrix
* Rotated sorted arrays
* Peak element problems
* Binary Search on Answer
* Optimization problems with a monotonic condition

---

## 💡 Core Idea

Maintain two pointers:

* **Low** → Start of the search space.
* **High** → End of the search space.

At each step:

1. Compute the middle index.
2. Compare the middle element with the target (or check the feasibility condition).
3. Eliminate one half of the search space.
4. Repeat until the answer is found or the search space becomes empty.

Since half of the search space is discarded in every iteration, Binary Search is extremely efficient.

---

## 🧩 Common Patterns

### 🔹 Classic Binary Search

Find the position of an element in a sorted array.

### 🔹 Lower Bound / Upper Bound

Find the first or last position satisfying a given condition.

### 🔹 Binary Search on Answer

Treat the answer space as sorted and search for the minimum or maximum feasible answer.

### 🔹 Search in 2D Matrix

Apply Binary Search on a flattened matrix or perform row-wise/column-wise search.

---

## 🚀 Advantages

* Reduces search space by half in every iteration.
* Converts many brute-force **O(n)** or **O(n²)** solutions into **O(log n)**.
* Forms the basis for many optimization problems.
* Frequently asked in coding interviews and competitive programming.

---

## 📌 Complexity

| Operation     |             Complexity |
| ------------- | ---------------------: |
| Binary Search |           **O(log n)** |
| Extra Space   | **O(1)** *(Iterative)* |

---

## 🛠️ Language

* C++

---

> **Don't search every element—eliminate half the search space at every step. That's the power of Binary Search. 🚀**
