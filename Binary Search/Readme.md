# 🔍 Binary Search

Binary Search is an efficient algorithm used to find an element in a **sorted array or search space**.
It works by repeatedly dividing the search range in half.

---

## ⚡ Why Binary Search?

* Reduces search space by half each step
* Much faster than linear search
* Core technique in many interview problems

---

## 🧠 Basic Idea

1. Start with `low = 0`, `high = n - 1`
2. Find middle:

   ```cpp
   mid = low + (high - low) / 2;
   ```
3. Compare:

   * If `target == nums[mid]` → return index
   * If `target < nums[mid]` → search left
   * If `target > nums[mid]` → search right

---

## 💻 Template

```cpp
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}
```

---

## ⏱️ Complexity

| Operation | Complexity |
| --------- | ---------- |
| Time      | O(log n)   |
| Space     | O(1)       |

---

## 🔥 Types of Binary Search Problems

### 1. Basic Binary Search

* Find element in sorted array

### 2. Lower Bound / Upper Bound

* First or last occurrence
* First ≥ target
* Last ≤ target

---

### 3. Search on Answer (Important 💀)

Binary search on range of answers instead of array.

Examples:

* Minimum speed to finish work
* Allocate books
* Koko eating bananas

---

### 4. Rotated Array

* Search in rotated sorted array
* Find minimum in rotated array

---

### 5. Binary Search on 2D

* Matrix problems
* Flattened or row-wise sorted

---

## 🧩 Common Patterns

* Sorted array → direct binary search
* Monotonic function → search on answer
* Peak / valley → modified binary search

---

## ⚠️ Important Tips

* Always use:

  ```cpp
  mid = low + (high - low) / 2;
  ```

  (avoids overflow)

* Loop condition:

  ```cpp
  while (low <= high)
  ```

* Think:
  👉 **"Can I eliminate half of the search space?"**



---

## 🧠 Interview One-Liner

“Binary Search works on sorted or monotonic spaces by eliminating half of the search range each step.”

---

## 🏆 Goal

Master:

* Template
* Variations
* Search on Answer

👉 Binary Search = **must-have for top companies**

---
