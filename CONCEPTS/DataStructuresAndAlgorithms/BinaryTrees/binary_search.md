### Binary Search Algorithm Overview

Binary Search is an efficient algorithm for finding a target value within a sorted array or list. It works by repeatedly dividing the search interval in half.

#### Algorithm Steps:
1. **Initialize**: Start with two pointers, `low` and `high`, where `low` is the index of the first element and `high` is the index of the last element.
2. **Middle Element**: While `low` <= `high`, calculate the middle index, `mid = low + (high - low) // 2`.
3. **Check Middle**: If the middle element, `array[mid]`, is the target, return `mid`.
4. **Adjust Bounds**: 
   - If `array[mid]` < target, set `low = mid + 1`.
   - Else, set `high = mid - 1`.
5. **Not Found**: If `low` > `high`, the target is not in the array, return `-1`.

#### Time Complexity:
- Worst-case: O(log n)
- Best-case: O(1)

#### Code Example in Python:
```python
def binary_search(array, target):
    low, high = 0, len(array) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

#### Usage:
```python
index = binary_search([1, 2, 3, 4, 5], 3)  # Returns 2, as array[2] is 3.
```

### Repeated Indices
We need to check if the number we select is the first occurance. Define a **helper function**.

```python
def test_location(cards, query, mid):
    mid_number = cards[mid]
    if mid_number == query:
        if mid-1 >=0 and cards[mid-1] == query:
            return 'left'
        else:
            return 'found'
    elif mid_number < query:
        return 'left'
    else:
        return 'right'
```

### Calculating Complexity from First Order

Initial length - `N`
Iteration 1 - `N/2`
Iteration 2 - `N/4` (i.e. `N/2^2`)
...
Iteration k - `N/2^k`

Since the final length of the array is 1, we can find the

`N/2^k = 1`
so 
`k = log N`

So we say that binary search runs in **logarithmic time**, **O(log N)** with space complexity is **O(1)**

