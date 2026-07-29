# 🔍 Search in 2D Matrix

**Search in a 2D Matrix** is a common Binary Search topic where the searching technique depends on **how the matrix is sorted**. Identifying the matrix property is the key to choosing the optimal algorithm.

---

## 🎯 When to Use

Use the appropriate approach based on the matrix's sorting condition.

- Matrix behaves like a sorted 1D array → **Flattened Binary Search**
- Each row is sorted independently → **Binary Search on Every Row**
- Rows and columns are both sorted → **Staircase Search**

---

## 💡 Core Idea

Different matrix properties require different searching techniques.

### 1. Flattened Binary Search

Treat the matrix as a virtual sorted 1D array.

```text
row = mid / columns
col = mid % columns
```

Perform a normal Binary Search.

---

### 2. Binary Search on Every Row

For each row:

- Check if the target can exist in that row.
- Perform Binary Search only on that row.

---

### 3. Staircase Search

Start from the **top-right** corner.

- Current > Target → Move Left
- Current < Target → Move Down
- Current == Target → Found

Each move eliminates one complete row or column.

---

## 📝 Matrix Types

### Type 1: Fully Sorted Matrix

Properties:

- Every row is sorted.
- First element of each row is greater than the last element of the previous row.

Example

```text
1   3   5   7
10 11 16 20
23 30 34 60
```

Algorithm:

- Flattened Binary Search

Time Complexity: **O(log(m × n))**

---

### Type 2: Row-wise Sorted Matrix

Properties:

- Every row is sorted.
- No ordering between different rows.

Example

```text
1 4 7 10
2 5 8 12
3 6 9 15
```

Algorithm:

- Binary Search on Every Row

Time Complexity: **O(m × log n)**

---

### Type 3: Row & Column Sorted Matrix

Properties:

- Rows are sorted.
- Columns are sorted.

Example

```text
1   4   7   11
2   5   8   12
3   6   9   16
10 13 14 17
```

Algorithm:

- Staircase Search

Time Complexity: **O(m + n)**

---

## 🚀 Generic Algorithms

### Flattened Binary Search

```text
low = 0
high = rows × columns - 1

while (low <= high)

    mid = low + (high - low) / 2

    row = mid / columns
    col = mid % columns

    if matrix[row][col] == target
        return true

    else if matrix[row][col] < target
        low = mid + 1

    else
        high = mid - 1

return false
```

---

### Staircase Search

```text
row = 0
col = columns - 1

while (row < rows && col >= 0)

    if matrix[row][col] == target
        return true

    else if matrix[row][col] > target
        col--

    else
        row++

return false
```

---

## 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------:|------:|
| Flattened Binary Search | **O(log(m × n))** | **O(1)** |
| Binary Search on Every Row | **O(m × log n)** | **O(1)** |
| Staircase Search | **O(m + n)** | **O(1)** |

---

## ⚠️ Common Mistakes

- Using Flattened Binary Search on matrices that are not globally sorted.
- Forgetting:
  - `row = mid / columns`
  - `col = mid % columns`
- Applying Staircase Search on row-wise sorted matrices.
- Ignoring empty matrix edge cases.

---

## 🛠️ Language

- C++

---

> **First identify how the matrix is sorted. Once the property is known, choosing the correct search algorithm becomes straightforward. 🚀**
