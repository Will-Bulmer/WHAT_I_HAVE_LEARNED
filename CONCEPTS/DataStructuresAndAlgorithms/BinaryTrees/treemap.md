### A Python-Friendly Treemap

We are now ready to return to our original problem statement.

**Question 1**: As a senior backend engineer at Jovian, you are tasked  with developing a fast in-memory data structure to manage profile information (username, name and email) for 100 million users. It should allow the following operations to be performed efficiently:

1. **Insert** the profile information for a new user.
2. **Find** the profile information of a user, given their username.
3. **Update** the profile information of a user, given their username.
4. **List** all the user of the platform, sorted by username.

You can assume the usernames are unique.

### Solution

We can create a generic class `Treemap` which supports all the operations specified in the original problem statement in a python-friendly manner.

```python
class TreeMap():
    def __init__(self):
        self.root = None
    
    def __setitem__(self, key, value):
        node = find(self.root, key)
        if not node:
            self.root = insert(self.root, key, value)
            self.root = balance_bst(self.root)
        else:
            update(self.root, key, value)
    
    def __getitem__(self, key):
        node = find(self.root, key)
        return node.value if node else None
    
    # Allows class to be used in a for loop
    def __iter__(self):
        return (x for x in list_all(self.root))

    def __len__(self):
        return tree_size(self.root)

    def display(self):
        return display_keys(self.root)
```