# 📚 Stack in C++ STL

## 🔹 What is Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.

👉 Last element inserted → first element removed

---

## 🔹 Header File

```cpp
#include <stack>
```

---

## 🔹 Declaration

```cpp
stack<int> st;
```

---

## 🔹 Basic Operations

### ➤ Push (Insert element)

```cpp
st.push(10);
```

### ➤ Pop (Remove top element)

```cpp
st.pop();
```

### ➤ Top (Access top element)

```cpp
st.top();
```

### ➤ Check Empty

```cpp
st.empty();
```

### ➤ Size

```cpp
st.size();
```


---

## 🔹 Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| push      | O(1)       |
| pop       | O(1)       |
| top       | O(1)       |
| empty     | O(1)       |

---

## 🔹 Applications

* Expression evaluation (Infix → Postfix)
* Parentheses validation
* Undo/Redo operations
* Backtracking (DFS)
* Monotonic Stack problems

---

## 🔹 STL Implementation Detail

* Implemented using **deque (default)**
* Can also use:

```cpp
stack<int, vector<int>> st;
```

---

## 🔹 Important Notes ⚠️

* No direct iteration support
* Only access top element
* Follows strict LIFO order

---

## 🔹 Interview Tips 💡

* Always check `empty()` before `top()` or `pop()`
* Use stack for **reversal problems**
* Combine with recursion for advanced problems

---

## 🚀 Summary

Stack is a simple yet powerful data structure used in many real-world and interview problems due to its LIFO behavior.

