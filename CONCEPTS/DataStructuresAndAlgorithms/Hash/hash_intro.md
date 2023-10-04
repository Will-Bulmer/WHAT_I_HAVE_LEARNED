### Problem Statement - Python Dictionaries and Hash Tables

In this assignment, you will recreate Python dictionaries from scratch using data structure called *hash table*. Dictionaries in Python are used to store key-value pairs. Keys are used to store and retrieve values. For example, here's a dictionary for storing and retrieving phone numbers using people's names.

```python
phone_numbers = {
    'name1' : '99828'
    'name2' : '82839'
    'name3' : '92980'
}

# Add new value 
phone_numbers['name4'] = '89340'

# Loop through to display
for name in phone_numbers:
    print('Name:', name, ', Phone Number: ', phone_numbers[name])
```
Dictionaries in Python are implemented using a data structure called **hash table**. A hash table uses a list/array to store the key-value pairs, and uses a **hasing function** to determine the index for storing or retrieving the data associated with a given key.

Your objective in this assignment is to implement a `HashTable` class which supports the following operations:

- **Insert**: Insert a new key-value pair.
- **Find**: Find the value associated with a key.
- **Update**: Update the value associated with a key.
- **List**: List all the keys stored in the hash table.

```python
class HashTable:
    def insert(self, key, value):
        """Insert a new key-value pair"""
        pass
    
    def find(self, key):
        """Find the value associated with a key"""
        pass

    def update(self, key, value):
        """Change the value associated with a key"""
        pass

    def list_all(self):
        """List all the keys"""
        pass
```

### Hash Table Representation

A hash table is a data structure that stores key-value pairs. It uses a hash function to compute an index where the value should be stored. Here's a simplistic representation of a hash table:

| Index | Key-Value Pairs          |
|-------|--------------------------|
| 0     | [("apple", 3)]           |
| 1     | [("banana", 2), ("grape", 5)] |
| 2     | []                       |
| 3     | [("orange", 7)]          |
| 4     | [("cherry", 1)]          |

- **Index**: The computed hash value for the key, determining where the key-value pair is stored.
- **Key-Value Pairs**: A list of key-value pairs stored at the respective index. When there are multiple pairs at the same index (collision), they are chained together.

In this example, the keys are fruit names, and the values are their quantities. When multiple key-value pairs are hashed to the same index, they are stored in a list at that index (chaining).
