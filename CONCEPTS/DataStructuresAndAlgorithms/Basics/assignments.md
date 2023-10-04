## 1. Binary Search

You are given list of numbers, obtained by rotating a sorted list an unknown number of times. Write a function to determine the minimum number of times the original sorted list was rotated to obtain the given list. Your function should have the worst-case complexity of `O(log N)`, where N is the length of the list. You can assume that all the numbers in the list are unique.

### Solution
The signature of our function will be,
```python
def count rotations(nums):
    pass
```

Create test cases:
```python
# A list  of size 8 rotated 5 times
test1 = {
    'input': {
        'nums': [4, 5, 6, 7, 8, 1, 2, 3]
    },
    'output':
    }
```

```python
# A list that wasn't rotated at all
test2 = {
    'input': {
        'nums': [1 ,2 ,3 , 4]
    },
    'output': 0
    }
```

Linear Solution: Check for each number in the list whether is is smaller than the number than comes before it.

Binary Solution: If the middle element of the list is smaller than the last element of the range, then the answer lies to the left of it. Otherwise, the answer lies to the right.

## 2. Binary Search Tree

We need to create a data structure which can store 100 million records and perform insertion, search, update and list operations efficiently.

### Solution
Key inputs to our data structure are user profiles, which contain the username, name and email of a user.

```python
class User:
    # Constructor
    def __init__(self, username, name, email):
        self.username = username
        self.name = name
        self.email = email
    
    # String representation
    def __repr__(self):
        return "User(username='{}', name='{}', email='{}')".format(self.username)

    def __str__(self):
        return self.__repr__()
```

Our output would be:
```python
class UserDatabase:
    def insert(self, user):
        i = 0
        while i < len(self.users):
            # Find the first username greater than the new user's username
            if self.users[i].username > user.username:
                break
            i += 1
        self.users.insert(i, user)

    def find(self, username):
        for user in self.users:
            if user.username == username:
                return user

    def update(self, user):
        target = self.find(user.username)
        target.name, target.email = user.name, user.email

    def list_all(self):
        return self.users
```

Analyzing complexity, the methods take up to `N` iterations, worst case. `O(N)`. List has complexity `O(1)`. It is apparent that a sorted list of users might not be the best data structure.