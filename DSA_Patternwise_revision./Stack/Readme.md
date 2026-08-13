# 📚 Stack

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The element inserted last is the first one to be removed.

Think of a stack as a pile of plates:

- Place a new plate on the top.
- Remove a plate from the top.

Only one end of the stack is accessible.

---

## 🎯 When to Use

Use a stack when a problem involves:

- Previous elements
- Next elements
- Nested structures
- Reversing data
- Backtracking
- Maintaining order of operations

Common interview questions include:

- Valid Parentheses
- Next Greater Element
- Previous Smaller Element
- Largest Rectangle in Histogram
- Daily Temperatures
- Asteroid Collision
- Remove K Digits
- Min Stack

---

## 💡 Core Idea

A stack supports operations at only one end called the **top**.

```text
Push(10)

Top
 ↓
+----+
| 10 |
+----+
```

```text
Push(20)

Top
 ↓
+----+
| 20 |
+----+
| 10 |
+----+
```

```text
Pop()

Top
 ↓
+----+
| 10 |
+----+
```

---

## 📝 Basic Operations

| Operation | Description |
| ---------- | ------------ |
| push() | Insert an element |
| pop() | Remove the top element |
| top() | Access the top element |
| empty() | Check whether the stack is empty |
| size() | Return the number of elements |

---

## 🚀 Standard Template

```cpp
stack<int> st;

st.push(10);

st.push(20);

cout << st.top();

st.pop();

if (st.empty()) {
    cout << "Empty";
}
```

---

## 🔥 Common Stack Patterns

### 1. Monotonic Increasing Stack

Elements remain in increasing order.

```text
Stack: 1 3 5 7
```

Used in:

- Previous Smaller Element
- Next Smaller Element

---

### 2. Monotonic Decreasing Stack

Elements remain in decreasing order.

```text
Stack: 9 7 5 3
```

Used in:

- Next Greater Element
- Previous Greater Element
- Daily Temperatures

---

### 3. Balanced Parentheses

Store opening brackets in the stack.

```text
Expression:

({[]})

Push → ( { [

Pop → ] } )

Valid
```

---

### 4. Collision Problems

Use the stack to simulate interactions between elements.

```text
Example:

5 10 -5

Stack:

5

5 10

5 10 -5

Result:

5 10
```

Used in:

- Asteroid Collision

---

### 5. Histogram Problems

Maintain indices inside the stack.

Used in:

- Largest Rectangle in Histogram
- Maximal Rectangle

---

## ⚠️ Common Mistakes

- Calling `top()` on an empty stack.
- Forgetting to check `empty()` before `pop()`.
- Storing values instead of indices when indices are required.
- Using a normal stack instead of a monotonic stack.

---

## 📊 Complexity

| Operation | Time |
| ---------- | ----: |
| push() | **O(1)** |
| pop() | **O(1)** |
| top() | **O(1)** |
| empty() | **O(1)** |
| size() | **O(1)** |

Space Complexity: **O(n)**

---

## 🛠️ Language

- C++

---

> **Whenever a problem asks for the next, previous, nearest, or matching element, think about using a Stack. 🚀**
