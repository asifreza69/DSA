# 🔎 Classic Binary Search

Classic Binary Search is the most fundamental Binary Search algorithm used to find the position of a target element in a **sorted array**.

Instead of checking every element one by one, it repeatedly divides the search space into two halves, making it much faster than linear search.

---

## 🎯 When to Use

Use Classic Binary Search when:

* The array is **sorted** (ascending or descending with slight modification).
* You need to find whether an element exists.
* You need the index of an element.
* The search space is already sorted.

---

## 💡 Core Idea

Maintain two pointers:

* **Low** → Starting index
* **High** → Ending index

Repeat until **Low ≤ High**:

1. Find the middle index.
2. If the middle element equals the target, return its index.
3. If the target is smaller, search in the left half.
4. Otherwise, search in the right half.

Each iteration removes half of the remaining search space.

---

## 📝 Algorithm

```text
low = 0
high = n - 1

while (low <= high)
    mid = low + (high - low) / 2

    if arr[mid] == target
        return mid

    else if arr[mid] < target
        low = mid + 1

    else
        high = mid - 1

return -1
```

---

## ⚡ Advantages

* Very fast for sorted data.
* Eliminates half of the search space in every iteration.
* Simple to implement.
* Foundation for advanced Binary Search problems.

---

## ❌ Limitations

* Works only on sorted data.
* Cannot be directly applied to unsorted arrays.
* If duplicate elements exist, it may return any valid occurrence.

---

## 📌 Complexity

| Operation        |             Complexity |
| ---------------- | ---------------------: |
| Time Complexity  |           **O(log n)** |
| Space Complexity | **O(1)** *(Iterative)* |

---

## 🛠️ Language

* C++

---

> **Every comparison cuts the search space in half—this is why Binary Search is one of the fastest searching algorithms. 🚀**
