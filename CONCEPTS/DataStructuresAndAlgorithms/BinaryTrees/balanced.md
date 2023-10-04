### Balanced Binary Trees

**Question 14**: Write a function to determine if a binary tree is balanced.

Here's a recursive strategy:

1. Ensure that the left subtree is balanced.
2. Ensure that the right subtree is balanced.
3. Ensure that the difference between heights of left subtree and right subtree is not more than 1.

```python
def is_balanced(node):
    if node is None:
        return True, 0
    balanced_l, height_l = is_balanced(node.left)
    balanced_r, height_r = is_balanced(node.right)
    balanced = balanced_l and balanced_r and abs(height_l - height_r) <= 1
    height = 1 + max(height_l, height_r)
    return balanced, height
```

### Balanced Binary Search Trees

**Question 15**: Write a function to create a balanced BST from a sorted list/array of key-value pairs.

We can use a recursive strategy here, turning the middle element of the list into the root root, and recursively creating left and right subtrees.

```python
def make_balanced_bst(data, lo=0, hi=None, parent=None):
    if hi is None:
        hi = len(data) - 1
    if lo > hi:
        return None
    
    mid  = (lo + hi) // 2
    key, value = data(mid)

    root = BSTNode(key,value)
    root.parent = parent
    root.left = make_balanced_bst(data, lo, mid-1, root)
    root.right = make_balanced_bst(data, mid+1, hi, root)

    return root
```

If you were to start from the edge, you would end up with a skewed-tree. Important to start from the middle just like in a binary search.

### Balancing an Unbalanced BST

**Question 16**: Write a function to balance an unbalanced binary search tree.

We perform an inorder traversal, then create a balanced BST using the function defined earlier.

```python
# list_all gives us a sorted array of key-value pairs
def balance_bst(node):
    return make_balanced_bst(list_all(node))
```

### Complexity in BST
- Insert - O(log N) + O(N) = O(N)
- Find - O(log N)
- Update - O(log N)
- List all - O(N)

This is the importance of data structures.

### Self-Balancing Binary Trees and AVL Trees
A *self-balancing binary tree* remains balanced after every insertion or deletion. Examples of approaches to creating these are e.g. B-trees, Red Black Trees and AVL (Adelson-Velsky Landis) trees.

Self-balancing in AVL trees is achieved by tracking the **balance factor** (difference between the height of the left subtree and the right subtree) for each node and **rotating** unbalanced subtrees along the path of insertion/ deletion to balance them.

Each rotation takes constant time, and at most `log N` rotations may be required, this operation is far more efficient than creating a balanced binary tree from scratch allowing insertion and deletion to be performed in `O(log N)` time.