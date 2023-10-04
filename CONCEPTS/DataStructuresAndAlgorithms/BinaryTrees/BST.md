### Binary Trees Overview

- *Binary* indicates that each node can have at most 2 children.
- *Root* is the single node at the top. Typically where operations like search, insertion etc. begin.
- *Leaves* are nodes with no children.

The number of levels in a tree is called its height. At level k-1: `2^(k-1)` nodes. Thus to store `N` records, we require a balanced binary search tree (BST) of height no larger than `log(N) + 1`. The operations `insert`, `find` and `update` have time complexity `O(log N)` since they all involve traversing a single path down from the root of the tree.

#### Balanced vs Unbalanced:
- **Balanced BST**: Maintains balance to ensure \(O(\log n)\) height, e.g., AVL Tree, Red-Black Tree.
- **Unbalanced BST**: May degrade to a linked list in the worst case, resulting in \(O(n)\) height.

#### Time Complexity:
- **Search, Insertion, Deletion**: 
  - Average case: \(O(\log n)\) for balanced trees.
  - Worst case: \(O(n)\) for unbalanced trees.

#### Example Code (Python):
```python
class TreeNode:
    def __init__(self, key):
        self.left = self.right = None
        self.key = key

def insert(root, key):
    if root is None:
        return TreeNode(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    return root

def search(root, key):
    if root is None or root.key == key:
        return root
    if key < root.key:
        return search(root.left, key)
    return search(root.right, key)
```

#### Usage:
```python
root = None
root = insert(root, 5)
root = insert(root, 3)
root = insert(root, 7)

node = search(root, 3)  # Returns the TreeNode with key 3.

# Basic BST, 3 nodes
node0 = TreeNode(3)
node1 = TreeNode(4)
node2 = TreeNode(5)

node0.left = node1
node0.right = node2

tree.right == 5 # tree refers to root node
```

It's a bit inconvenient to create a tree by manually connecting all the nodes. Lets write a helper function which can convert a tuple with the structure `(left_subtree, key, right_subtree)` (where `left_subtree` and `right_subtree` are themselves tuples) into a binary tree.

Here's a tuple representing a tree
```python
tree_tuple = ((1,3,None), 2, ((None,3,4), 5, (6,7,8)))

# Recursive Function
def parse_tuple(data):
    if isinstance(data, tuple) and len(data) == 3:
        node = TreeNode(data[1])
        node.left = parse_tuple(data[0])
        node.right = parse_tuple(data[2])
    elif data is None:
        node = None
    else:
        node = TreeNode(data)
    return node

# Display all keys in a tree-like structure for easier vizualization.
def display_keys(node, space='\t', level=0):
    if node is None:
        print(space*level + 'Empty')
        return
    # Leaf
    if node.left is None and node.right is None:
        print(space*level + str(node.key))
        return
    
    # If node has children
    display_keys(node.right, space, level+1)
    print(space*level + str(node.key))
    display_keys(node.left, space, level+1)
```

### Binary Search Tree (BST)
A binary search tree or BST is a binary tree that satisifies the following conditions:

1. The left subtree of any node only contains nodes with keys less than the node's key.
2. The right subtree of any node only contains nodes with keys greater than the node's key.

It follows that every subtree of a BST must also be a binary search tree.

**Question 8**: Write a function to check if a binary tree is a BST
**Question 9**: Write a function to find the maximum key in a binary tree.
**Question 10**: Write a function to find the minimum key in a binary tree

```python
def remove_none(nums):
    return [x for x in nums if x is not None]

def is_bst(node):
    if node is None:
        return True, None, None
    is_bst_l, min_l, max_l = is_bst(node.left)
    is_bst_r, min_r, max_r = is_bst(node.right)

    is_bst_node = (is_bst_l and is_bst_r and 
                (max_l is None or node.key > max_l) and
                (min_r is None or node.key < min_r))
    min_key = min(remove_none([min_l, node.key, min_r]))
    max_key = max(remove_none([max_l, node.key, max_r]))

    return is_bst_node, min_key, max_key
```

### Storing Key-Value Pairs using BSTs
We can create a tree with usernames as keys, and user objects as values.
```python
class BSTNode():
    def __init__(self, key, value=None):
        self.key = key
        self.value = value
        self.left = self.right = self.parent = None

tree = BSTNode(jadhesh.username, jadhesh)
```