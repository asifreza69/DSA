# 📚 Monotonic Stack

A **Monotonic Stack** is a special type of stack in which elements are maintained in either **increasing** or **decreasing** order.

Instead of storing elements randomly, the stack preserves a specific order by removing unnecessary elements before inserting a new one.

---

## 🎯 When to Use

Use a Monotonic Stack when a problem asks for:

- Next Greater Element
- Previous Greater Element
- Next Smaller Element
- Previous Smaller Element
- Nearest Greater Element
- Nearest Smaller Element
- First Greater Element
- First Smaller Element

Common interview problems include:

- Next Greater Element
- Daily Temperatures
- Largest Rectangle in Histogram
- Trapping Rain Water
- Stock Span Problem
- Sum of Subarray Minimums
- Sum of Subarray Ranges

---

## 💡 Core Idea

Before inserting a new element, remove all elements that violate the required order.

There are two types of Monotonic Stacks:

- Monotonic Increasing Stack
- Monotonic Decreasing Stack

---

## 📈 Monotonic Increasing Stack

Elements remain in increasing order.

```text
Input:

4 2 5 1 6
```

```text
Push 4

4
```

```text
Push 2

Pop 4

2
```

```text
Push 5

5
2
```

```text
Push 1

Pop 5

Pop 2

1
```

Used in:

- Next Smaller Element
- Previous Smaller Element
- Sum of Subarray Minimums

---

## 📉 Monotonic Decreasing Stack

Elements remain in decreasing order.

```text
Input:

4 2 5 1 6
```

```text
Push 4

4
```

```text
Push 2

4
2
```

```text
Push 5

Pop 2

Pop 4

5
```

```text
Push 1

5
1
```

Used in:

- Next Greater Element
- Previous Greater Element
- Daily Temperatures
- Stock Span Problem

---

## 📝 Generic Templates

### Monotonic Increasing Stack

```cpp
stack<int> st;

for (int i = 0; i < arr.size(); i++) {

    while (!st.empty() && st.top() > arr[i]) {
        st.pop();
    }

    st.push(arr[i]);
}
```

---

### Monotonic Decreasing Stack

```cpp
stack<int> st;

for (int i = 0; i < arr.size(); i++) {

    while (!st.empty() && st.top() < arr[i]) {
        st.pop();
    }

    st.push(arr[i]);
}
```

---

## 🚀 How to Identify the Pattern

| Problem | Stack Type |
| --- | --- |
| Next Greater Element | Decreasing |
| Previous Greater Element | Decreasing |
| Next Smaller Element | Increasing |
| Previous Smaller Element | Increasing |
| Daily Temperatures | Decreasing |
| Stock Span | Decreasing |
| Largest Rectangle in Histogram | Increasing |
| Trapping Rain Water | Increasing |
| Sum of Subarray Minimums | Increasing |

---

## ⚠️ Common Mistakes

- Storing values when indices are required.
- Using an increasing stack instead of a decreasing stack.
- Forgetting to remove invalid elements before pushing.
- Accessing `top()` without checking `empty()`.

---

## 📊 Complexity

| Operation | Complexity |
| --- | ---: |
| Push | **O(1)** |
| Pop | **O(1)** |
| Overall | **O(n)** |

Although there are nested loops, every element is pushed and popped at most once.

---

## 🛠️ Language

- C++

---

> **If a problem asks for the nearest, next, or previous greater/smaller element, a Monotonic Stack should be your first thought. 🚀**
