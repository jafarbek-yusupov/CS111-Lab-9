# Tree Data Structure

## Introduction
#### A tree is a *`non-linear data structure`* consisting of *`nodes`* connected by *`edges`* that represent *`hierarchical relationships`*.

---

## Node Relationships
- **Parent** — Node directly above it.
- **Children** — Nodes directly below it.
- **Siblings** — Nodes sharing the same parent.
- **Root** — Topmost node (has no parent).
- **Leaf** — Node with no children.
- **Internal node** — Node with at least one child.

---

## Basic Properties
> [!NOTE]
> #### A tree with **`N nodes`** has exactly **`N-1 edges`**.

- **Depth(p)**: Number of ancestors of node p (distance from root).
- **Height(p)**: Number of **edges** on the longest path from p to a leaf.
- **Height(T)**: Height of the root node.
- **Recursive Nature**: Every subtree is itself a tree.

---

## Binary Trees

### Definitions
- **Binary tree**: Each node has at most two children.
- **Full (proper)**: Every internal node has exactly two children.
- **Complete**: All levels are full except possibly the last; nodes on the last level are as far left as possible.
- **Perfect**: All levels are completely full.

### Array Representation
For index `i` (1-based):
- Left child at `2i`
- Right child at `2i+1`
- Parent at `⌊i/2⌋`

---

## Tree Traversal Types

| Traversal Type | Description | Order |
|---------------|-------------|--------|
| **Preorder** | Visit the node first, then recursively visit its subtrees | Root → Left → Right |
| **Inorder** | Visit the left subtree, then the node, then the right subtree (binary trees only) | Left → Root → Right |
| **Postorder** | Visit all subtrees first, then the node itself | Left → Right → Root |
| **Level-order (BFS)** | Visit nodes level by level from top to bottom using a queue | Using Queue |

---

## General Properties of Binary Trees

| Property | Formula / Explanation |
|----------|----------------------|
| Number of edges in a tree with `n` nodes | `n - 1` |
| Maximum number of nodes on level `i` | `2^i` |
| Total possible nodes for height `h` | `2^(h+1) - 1` |
| Relationship between height and number of nodes | `h ≈ log₂(n + 1) - 1` |
| Depth of the root node | `0` |
| Height of a leaf node | `0` |
| Depth of a node `p` | Number of edges from the root to `p` |
| Height of a node `p` | Number of edges on the longest path from `p` to a leaf |

---

> [!IMPORTANT]
> #### Height is measured in *`edges`*, not *`nodes`*. *A single-node tree has height 0.*