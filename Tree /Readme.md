# 🌳 Trees

This repository contains implementations of common **Tree Data Structure problems** with optimized approaches and clear logic.

---

## 📌 What is a Tree?

A Tree is a hierarchical data structure consisting of nodes, where:

* The top node is called the **root**
* Each node can have **children**
* Nodes are connected via **edges**

---

## 🌿 Types of Trees

* Binary Tree
* Binary Search Tree (BST)
* Balanced Trees (AVL, Red-Black)
* Heap (Min Heap / Max Heap)
* Trie (Prefix Tree)
* N-ary Tree

---

## ⚡ Common Operations

* Insertion
* Deletion
* Traversal (DFS, BFS)
* Searching
* Height / Depth calculation

---

## 🔁 Tree Traversals

### Depth First Search (DFS)

* Preorder (Root → Left → Right)
* Inorder (Left → Root → Right)
* Postorder (Left → Right → Root)

### Breadth First Search (BFS)

* Level Order Traversal

---

## 🚀 Key Patterns Covered

* Recursive Traversal
* Iterative Traversal (using stack/queue)
* Level Order (Queue based)
* Height & Diameter
* Lowest Common Ancestor (LCA)
* Path-based problems
* Tree Construction
* BST properties

---

## 📂 Folder Structure

```bash
Tree/
│── inorder_traversal.cpp
│── preorder_traversal.cpp
│── postorder_traversal.cpp
│── level_order.cpp
│── height_of_tree.cpp
│── diameter_of_tree.cpp
│── lowest_common_ancestor.cpp
│── validate_bst.cpp
│── ...
```

---

## 🧩 Problem Solving Approach

1. Identify tree type (Binary / BST / General)
2. Decide traversal (DFS or BFS)
3. Use recursion for simplicity
4. Handle base cases (NULL node)
5. Optimize using properties (especially in BST)

---

## ⏱️ Complexity

* Time: O(n) for most traversals
* Space: O(h) recursion stack (h = height of tree)

---

## 🏆 Goal

Master Tree concepts to solve **interview-level problems efficiently**

---

## 💡 Tips

* Always draw the tree before coding
* Think in terms of recursion (subtrees)
* Use BFS when level-wise processing is needed

---
