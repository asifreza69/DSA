# 📍 Lower Bound & Upper Bound

**Lower Bound** and **Upper Bound** are specialized applications of **Binary Search** used to locate insertion points and occurrence ranges in a sorted array.

They are extremely useful in problems involving duplicates, frequency counting, and range queries.

---

## 🎯 When to Use

Use Lower Bound and Upper Bound when you need to:

* Find the first occurrence of an element.
* Find the last occurrence of an element.
* Count the frequency of an element.
* Find the insertion position of an element.
* Search in arrays containing duplicate values.
* Solve Binary Search-based range queries.

---

## 💡 Core Idea

### 🔹 Lower Bound

Returns the **first position** where the element is **greater than or equal to** the target.

```text
arr[index] >= target
```

If the target exists, it returns its **first occurrence**.

Otherwise, it returns the position where the target should be inserted while maintaining sorted order.

---

### 🔹 Upper Bound

Returns the **first position** where the element is **strictly greater than** the target.

```text
arr[index] > target
```

If the target exists multiple times, Upper Bound points to the element immediately after its last occurrence.

---

## 📊 Example

```text
Array  : [1, 2, 2, 2, 4, 5]
Target : 2

Lower Bound Index = 1
Upper Bound Index = 4

First Occurrence = 1
Last Occurrence  = 3
Frequency         = 4 - 1 = 3
```

---

## 🧩 Common Applications

### 🔹 Search Insert Position

```cpp
lower_bound(arr.begin(), arr.end(), target)
```

Returns the index where the target should be inserted.

---

### 🔹 First Occurrence

```cpp
lower_bound(arr.begin(), arr.end(), target)
```

---

### 🔹 Last Occurrence

```cpp
upper_bound(arr.begin(), arr.end(), target) - 1
```

---

### 🔹 Count Frequency

```cpp
upper_bound(arr.begin(), arr.end(), target) -
lower_bound(arr.begin(), arr.end(), target)
```

---

### 🔹 Find Number of Elements

* Less than **k**

```cpp
lower_bound(arr.begin(), arr.end(), k)
```

* Less than or equal to **k**

```cpp
upper_bound(arr.begin(), arr.end(), k)
```

* Greater than **k**

```cpp
n - upper_bound(arr.begin(), arr.end(), k)
```

* Greater than or equal to **k**

```cpp
n - lower_bound(arr.begin(), arr.end(), k)
```

---

## 🚀 Advantages

* Finds insertion positions efficiently.
* Handles duplicate elements naturally.
* Helps solve range-based Binary Search problems.
* Frequently used in STL-based competitive programming.
* Eliminates the need for custom first/last occurrence logic in many cases.

---

## 📌 Complexity

| Operation   |   Complexity |
| ----------- | -----------: |
| Lower Bound | **O(log n)** |
| Upper Bound | **O(log n)** |
| Extra Space |     **O(1)** |

---

## 🛠️ Language

* C++

---

> **Lower Bound finds where a value begins, Upper Bound finds where it ends. Together, they unlock powerful Binary Search techniques. 🚀**
