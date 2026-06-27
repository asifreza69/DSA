# ➕ Prefix Sum

The **Prefix Sum** technique is one of the most powerful preprocessing methods used in Data Structures and Algorithms. It transforms an array into its cumulative sum representation, allowing range sum queries to be answered in constant time.

Instead of recalculating the sum of every subarray repeatedly, we compute the cumulative sum once and reuse it throughout the solution, significantly reducing the overall time complexity.

---

## 🎯 When to Use

Use Prefix Sum when a problem involves:

* Range Sum Queries
* Subarray Sum Problems
* Prefix/Suffix Calculations
* Equilibrium or Pivot Index
* Counting Valid Subarrays
* Prefix Sum + Hash Map
* Multiple Queries on the Same Array

---

## 💡 Core Idea

Construct a prefix sum array such that:

```text
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```

Once the prefix array is built, the sum of any subarray **[L...R]** can be computed in constant time.

* If `L == 0`

```text
Sum = prefix[R]
```

* Otherwise

```text
Sum = prefix[R] - prefix[L - 1]
```

Many interview problems optimize this further by maintaining a **running prefix sum**, eliminating the need for an extra array.

---

## 🧩 Common Patterns

### 🔹 Prefix Sum Array

Precompute cumulative sums to answer multiple range sum queries efficiently.

### 🔹 Running Prefix Sum

Maintain a running cumulative sum while traversing the array to reduce space complexity.

### 🔹 Prefix Sum + Hash Map

Store previously seen prefix sums in a hash map to solve problems like:

* Subarray Sum Equals K
* Longest Subarray with Given Sum
* Count of Subarrays with Target Sum

### 🔹 Prefix + Suffix

Maintain prefix and suffix information simultaneously to solve problems like:

* Equilibrium Index
* Pivot Index
* Product of Array Except Self

---

## 🚀 Advantages

* Eliminates repeated summation.
* Converts many brute-force O(n²) solutions into O(n).
* Easy to combine with Hash Maps, Sliding Window, and Dynamic Programming.
* Frequently asked in coding interviews.

---

## 📌 Complexity

| Operation               |                                   Complexity |
| ----------------------- | -------------------------------------------: |
| Prefix Sum Construction |                                     **O(n)** |
| Range Sum Query         |                                     **O(1)** |
| Extra Space             | **O(n)** *(or **O(1)** using a running sum)* |

---

## 🛠️ Language

* C++

---

> **Compute once, reuse everywhere. That's the power of Prefix Sum. 🚀**
