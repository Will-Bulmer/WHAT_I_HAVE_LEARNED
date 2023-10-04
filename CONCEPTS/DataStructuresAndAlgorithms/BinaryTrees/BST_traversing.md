### Traversing a Binary Tree
Common Questions:

**Question 3**: Write a function to perform the *inorder* traversal of a binary tree
**Question 4**: Write a function to perfrom the *preorder* traversal of a binary tree
**Question 5**: Write a function to perform the *postorder* traversal of a binary tree

**Traversal** is the process of visiting each node (adding it's key to a list) at least once.

#### Inorder Traversal
1. Traverse the left subtree recursively inorder.
2. Traverse the current node.
3. Traverse the right subtree recursively inorder.

```python
def traverse_in_order(node):
    if node is None:
        return []
    return(traverse_in_order(node.left) + [node.key] + traverse_in_order(node.right))
```

#### Preorder Traversal
1. Traverse the current node.
2. Traverse the left subtree recursively preorder.
3. Traverse the right subtree recursively preorder.

#### Postorder Traversal
1. Traverse the left subtree recursively in post-order.
2. Traverse the right subtree recursively in post-order.
3. Traverse the current node.

##### Example
        4
       / \
      2   5
     / \
    1   3
- **In-order Traversal**: `1 2 3 4 5`
- **Pre-order Traversal**: `4 2 1 3 5`
- **Post-order Traversal**: `1 3 2 5 4`