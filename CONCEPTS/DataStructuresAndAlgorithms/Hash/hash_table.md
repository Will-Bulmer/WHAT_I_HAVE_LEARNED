### Data List
First step is to create a Python list which will hold all the key-value pairs.

```python
MAX_HASH_TABLE_SIZE = 4096

data_list = [None] * MAX_HASH_TABLE_SIZE
```

### Hashing Function
A *hashing function* is used to convert strings and other non-numeric data types into numbers which can then be used as list indices. Simple algorithm for hashing strings to numeric is:

1. Iterate over the string, character by character
2. Convert each character to a number using Python's built-in `ord` function
3. Add the numbers for each character to obtain the has for the entire string
4. Take the remainder of the result with the size of the data list

**Question 2**: Complete the `get_index` function below which implements the hashing algorithm described above.

```python
def get_index(data_list, a_string):
    result = 0

    for a_character in a_string:
        a_number = ord(a_character)
        result += a_number

    # Can work with data_lists of different sizes now
    list_index = result % len(data_list) 
    return list_index
```

### Insert
To insert a key-value pair into a hash table, we can simply get the hash of the key, and store the pair at that index in the data list.

```python
idx = get_index(data_list, key)

data_list[idx] = (key, value)
```

### Find
To retrieve the value associated with a pair, we can get the has of the key and look up that index in the data list.

```python
idx = get_index(data_list, 'Name')

key, value = data_list[idx]
```

### List
To get the list of the keys, we use a simple **list comprehension** which works as follows:
```python
list1 = [1,2,3,6,7]
list2 = [x for x in list1] # [1,2,3,6,7]
list2 = [x*2 for x in list1] # [2,4,6,12,14]
list2 = [x for x in list1 if x > 3] # [6,7]
```

```python
pairs = [kv[0] for kv in data_list if kv is not None] # kv = key-value
```

### Basic Hash Table Implementation
We can now use the hashing function to implement a basic hash table in Python.

**Question 3**: Complete the hash table implementation below

```python
class BasicHashTable:
    def __init__(self, max_size = MAX_HAS_TABLE_SIZE):
        self.data_list = [None] * max_size

    def insert(self, key, value):
        idx = get_index(self.data_list, key)
        self.data_list[idx] = key, value

    def find(self, key):
        idx = get_index(self.data_list, key)
        kv = self.data_list[idx]

        if kv is None:
            return None
        else:
            key, value = kv
            return value

    def update(self, key, value):
        idx = get_index(self.data_list, key)
        self.data_list[idx] = key, value

    def list_all(self):
        return [kv[0] for kv in self.data_list if kv is not None]
```

### Handling Collisions with Linear Probing
Multiple keys can have the same hash referred to as a *collision*. Here is how **linear probing** works:

1. While **inserting** a new key-value pair, if the target index for a key is occupied by another key, then we try the next index, following by the next and so on till we're in the closest empty location.
2. While **finding** a key-value pair, we apply the same strategy, but instead of searching for an empty location, we look for a location which contains a key-value pair with the matching key.
3. While **updating** a key-value pair, we apply the same strategy, but instead of searching for an empty location, we look for a location which contains a key-value pair with the matching key, and update its value.

**Question 4**: Complete the function `get_valid_index` below.

Function `get_valid_index`, starts searching the data list from the index determined by the hashing function `get_index` and returns the first index which is either empty or contains a key-value pair matching the given key.

```python
def get_valid_index(data_list, key):
    # Start with the index returned by get_index
    idx = ???

    while True:
        # Get the key-value pair stored at idx
        kv = ???

        # If is it None, return the index
        if ???:
            return idx

        # If the stored key matches the given key, return the index
        k, v = kv
        if ???:
            return idx

        # Move to the next index
        idx += 1

        # Go back to the start if you have reached the end if the array
        if idx == len(data_list):
            idx = 0
```

### Hash Table with Linear Probing

**Question 5**: Complete the hash table (with linear probing) implementation below by following the instructions in the comments.

```python
class ProbingHashTable:
    def __init__(self, max_size = MAX_HASH_TABLE_SIZE):
        self.data_list = [None] * max_size

    def insert(self, key, value):
        idx = get_valid_index(self.data_list, key)
        self.data_list[idx] = key, value

    def find(self, key)
        idx = get_valid_index(self.data_list, key)
        kv = self.data_list[idx]

        return None if kv is None else kv[1]

    def update(self, key, value):
        idx = get_valid_index(self.data_list, key)
        self.data_list[idx] = key, value

    def list_all(self):
        return [kv[0] for kv in self.data_list if kv is not None]
```

**(Optional) Question**: Implement a python-friendly interface for the hash table.
You will be able to use this just like a Python dictionary.
```python
MAX_HASH_TABLE_SIZE = 4096

class HashTable:
    def __init__(self, max_size=MAX_HAS_TABLE_SIZE):
        self.data_list = [None] * max_size

    def get_valid_index(self, key):
        # Use Python's in-built 'hash' function and implement linear probing
        pass
    
    def __getitem__(self, key):
        # Implement the logic for "find" here
        pass
    
    def __setitem__(self, key, value):
        # Implement the logic for "insert/update" here
        pass
    
    def __iter__(self):
        return (x for x in self.data_list if x is not None)

    def __len_(self):
        return len([x for x in self])

    def __repr__(self):
        from textwrap import indent
        pairs = [indent("{} : {}".format(repr(kv[0]), repr(kv[1])), ' ') if ?]
        return "{\n" + "{}".format(',\n'.join(pairs)) + "\n}"

    def __str__(self):
        return repr(self)
```
### Hash Table Improvements
- **Track the size of the hash table**: Number of key-value pairs so that len(table) has complexity O(1)
- **Implement deletion with tombstones**
- **Implement dynamic resizing**: automatically grow/ shrink the data list
- **Implement separate chaining**: an alternate to linear probing for collision resolution.

Average time-complexity of all operations for hash tables is `O(1)` with worst-case at `O(n)` due to collisions.
    