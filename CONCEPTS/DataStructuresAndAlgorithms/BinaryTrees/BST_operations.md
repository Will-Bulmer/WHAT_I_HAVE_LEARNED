### INSERTION into BST
**Question 11**: Write a function to insert a new node into a BST.

We use the BST-property to perform insertion efficiently.

1. Starting from the root node, we compare the key to be inserted with the current node's key.
2. If the key is smaller, we recursively insert it in the left subtree (if it exists) or attach it as the left child if no left subtree exists.
3. If the key is larger, we recursively insert it in the right subtree (if it exists) or attach it as the right child if no right subtree exists.

Here is a recursive implementation of `insert`
```python
def insert(node, key, value):
    if node is None:
        node = BSTNode(key, value)
    elif key < node.key:
        node.left = insert(node.left, key, value)
        node.left.parent = node
    elif key > node.key:
        node.right = insert(node.right, key, value)
        node.right.parent = node
    return node
```

### FINDING a Node in BST

**Question 11**: Find the value associated with a given key in a BST

Use a *recursive function*:
```python
def find(node, key):
    if node is None:
        return None
    if key == node.key:
        return node
    if key < node.key:
        return find(node.left, key)
    if key > node.key:
        return find(node.right, key)
```

### UPDATING a value in a BST

**Question 12**: Write a function to update the value associated with a given key within BST.
**Question 13**: Write a function to retrieve all the key-values pairs stored in a BST in the sorted order of keys

We can use `find` to locate the node to be updated, and simply update its value.
The nodes can be listed in sorted order by performing an inorder traversal of the BST.

```python
def update(node, key, value):
    target = find(node, key)
    if target is not None:
        target.value = value

def list_all(node):
    if node is None:
        return []
    return list_all(node.left) + [(node.key, node.value)] + list_all(node.right)
```