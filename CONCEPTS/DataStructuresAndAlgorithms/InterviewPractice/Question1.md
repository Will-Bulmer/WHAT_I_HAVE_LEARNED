### Subarray with Given Sum

The following question was asked during a coding interview for Amazon:

    You are given an array of numbers(non-negative). Find a continuous subarray of the list which adds up to a given sum.

### Solving: Step 1
**Input**: 
arr = [1, 7, 4, 2, 1, 3]
target = 10

**Output**:
output = 2, 6 : Returns array indices

```python
# Solve the problem here

# First note that in l = [1,7,4,2,1,3,11,5] that l[2:6] = [4,2,1,3]
def subarray_num(arr, target):
    pass

"""
TEST CASES
1. Generic array where the subarray is in the centre.
2. Subarray could be at the start.
3. Subarray could be at the end.
4. There is no subarray that adds up to 10.
5. You have a few zeros in the list.
6. Multiple sub arrays with the same sum.
7. Empty array.
8. The subarray is a single element.
"""
```

### Solving: Step 2
Come up with the simplest solution.

1. Try every single sub-array
Always helps to write comments your code can be hard to read due to not knowing coding best practices.
```python
def subarray_sum1(arr, target):
    n = len(arr)
    # i goes from 0 to n-1
    for i in range(0, n):
        # j goes from i to n
        for j in range(i, n+1):
            # Check if subarray sum equal target
            if sum(arr[i:j]) == target:
                # answer found
                return i,j
    return None, Nones
```

2. Maintain a running sum.
   
```python
def subarray_sums2(arr, target):
    n = len(arr)
    # i goes from 0 to n-1
    for i in range(0,n):
        s = 0 # running sum
        for j in range(i, n+1):
            if s == target:
                return i,j
            elif s > target:
                break
            if j < n:
                s += arr[j]
    
    return None, None
```

Can you do better? Analyse the complexity and try and identify inefficiency.
There are inefficiencies with i (left index). We don't always have to have an empty subarray each time.

```python
def subarray_sum3(arr, target):
    n = len(arr)
    i, j, s = 0, 0, 0
    while i < n and j < n+1:
        if s == target:
            return i,j
        elif s < target:
            if j < n:
                s += arr[j]
            j += 1
        elif s > target:
            s -= arr[i]
            i += 1
    
    return None, None


```
