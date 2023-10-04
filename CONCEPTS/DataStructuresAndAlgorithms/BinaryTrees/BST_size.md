### Height and Size of a Binary Tree

**Question 6**: Write a function to calculate the height/depth of a binary tree.
**Question 7**: Write a function to count the number of nodes in a binary tree.

The *height/ depth* of a binary tree is defined as the length of the longest path from its root node to a leaf. It can gbe computed recursively, as follows:
```python
def tree_height(node):
    if node is None:
        return 0
    return 1 + max(tree_height(node.left), tree_height(node.right))

def tree_size(node):
    if node is None:
        return 0
    return 1 + tree_size(node.left) + tree_size(node.right)
```
