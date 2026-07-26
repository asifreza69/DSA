# 🎯 Binary Search on Answers

**Binary Search on Answers** is an advanced application of Binary Search where the search is performed **not on the array itself, but on the range of possible answers**.

It is commonly used in optimization problems where we need to find the **minimum** or **maximum** value satisfying a given condition.

---

## 🎯 When to Use

Use Binary Search on Answers when:

* You need to minimize or maximize an answer.
* The answer lies within a known range.
* A brute-force solution checks every possible answer.
* The feasibility of an answer can be verified efficiently.
* The problem exhibits a **monotonic property**.

Typical questions include:

* Minimum eating speed
* Allocate minimum pages
* Aggressive cows
* Capacity to ship packages
* Koko Eating Bananas
* Painter's Partition
* Split Array Largest Sum
* Minimum days to make bouquets

---

## 💡 Core Idea

Instead of searching an array, search the **answer space**.

1. Define the minimum and maximum possible answer.
2. Pick the middle answer.
3. Check whether this answer is feasible.
4. If feasible, try to find a better (smaller or larger) answer.
5. Otherwise, discard that half of the search space.
6. Repeat until the optimal answer is found.

---

## 📈 Monotonic Property

Binary Search on Answers works only when the feasibility function is **monotonic**.

### Increasing Feasibility

```text id="0kr3fv"
Answer

✗ ✗ ✗ ✗ ✓ ✓ ✓ ✓ ✓
          ↑
     First Valid Answer
```

Example:

```text id="bs6vle"
Minimum eating speed
Minimum ship capacity
Minimum pages
Minimum days
```

---

### Decreasing Feasibility

```text id="c29cij"
Answer

✓ ✓ ✓ ✓ ✗ ✗ ✗ ✗
        ↑
    Last Valid Answer
```

Example:

```text id="qhl2r4"
Maximum minimum distance
Maximum feasible value
```

---

## 📝 Generic Algorithm

```text id="f91bpg"
low = minimum possible answer
high = maximum possible answer

while (low <= high)

    mid = low + (high - low) / 2

    if (isPossible(mid))
        answer = mid
        move left/right depending on optimization

    else
        move opposite direction

return answer
```

---

## 🧩 Steps to Solve

1. Identify the search space.
2. Determine the minimum and maximum possible answer.
3. Write a feasibility (`isPossible()`) function.
4. Ensure the feasibility is monotonic.
5. Apply Binary Search on the answer range.
6. Return the optimal feasible answer.

---

## 🚀 Advantages

* Converts many **O(n²)** or **O(n log n × Answer Range)** brute-force solutions into efficient solutions.
* Works for a wide variety of optimization problems.
* One reusable Binary Search template fits many interview questions.
* Frequently asked in coding interviews and competitive programming.

---

## ⚠️ Common Mistakes

* Applying Binary Search without a monotonic property.
* Choosing incorrect search boundaries.
* Writing an incorrect feasibility function.
* Integer overflow while computing `mid`.
* Updating the answer in the wrong direction.

---

## 📌 Complexity

Let:

* **N** = Size of the input.
* **R** = Size of the answer range.

| Operation                |       Complexity |
| ------------------------ | ---------------: |
| Feasibility Check        |         **O(N)** |
| Binary Search Iterations |     **O(log R)** |
| Overall Time Complexity  | **O(N × log R)** |
| Extra Space              |         **O(1)** |

---

## 🛠️ Language

* C++

---

> **Don't search the data—search the answer. If the answer space is monotonic, Binary Search can efficiently find the optimal solution. 🚀**
