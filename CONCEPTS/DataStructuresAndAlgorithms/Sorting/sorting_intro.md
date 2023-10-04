## Merge Sort, Quicksort and Divide-n-Conquer Algorithms in Python

### Problem
**Question 1**: You're working on a new feature on Jovian called "Top Notebooks of the Week". Write a function to sort a list of notebooks in decreasing order of likes. Keep in mind that up to millions of notebooks can be created every week, so your function needs to be as efficient as possible.

The problem of sorting a list of objects comes up over and over in computer science and software development, and it's important to understand common approaches for sorting, and the trade-offs they offer. Here is a simplified problem.

**Question 2**: Write a program to sort a list of numbers

**Sorting** refers to "sorting in ascending order", unless specified otherwise.

### The Method
**Input**: `nums` e.g. [4,2,6,3,4,6,2,1]
**Output**: `sorted_nums` e.g. [1,2,2,3,4,4,6,6]

```python
def sort(nums):
    pass
```

First we need to sort objects, not just numbers. Also, we want to sort them in the descending order of likes. To achieve this, all we need is a custom comparison function for two notebooks.

```python
class Notebook:
    def __init__(self, title, username, likes):
        self.title, self.username, self.likes = title, username, likes
    
    def __repr__(self):
        return 'Notebook <"{}/{}", {} likes>'.format(self.username, self.title, self.likes)
```

Next, we'll define a custom comparison function. For comparing notebooks, it will return the string 'lesser', 'equal' or 'greater' to establish order between the two objects.

```python
def compare_likes(nb1, nb2):
    if nb1.likes > nb2.likes:
        return 'lesser'
    elif nb1.likes == nb2.likes:
        return 'equal'
    elif nb1.likes < nb2.likes:
        return 'greater'
```

Here's an implementation of merge sort which accepts a custom comparison function.

```python
def default_compare(x, y):
    if x < y:
        return 'lesser'
    elif x == y:
        return 'equal'
    else:
        return 'greater'

def merge_sort(objs, compare=default_compare):
    if len(objs) < 2:
        return objs
    mid = len(objs) // 2
    return merge(merge_sort(objs[:mid], compare), merge_sort(objs[mid:], compare), compare)

def merge(left, right, compare):
    i,j, merged = 0, 0 ,[]
    while i < len(left) and j < len(right):
        result = compare(left[i], right[j])
        if result == 'lesser' or result == 'equal':
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
    return merged + left[i:] + right[j:]
```