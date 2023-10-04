### Quicksort

1. If the list is empty or has just one element, return it. It's already sorted.
2. Pick a random element from the list. This element is called a *pivot*.
3. Reorder the list so that all elements with values less than or equal to the pivot come before the pivot, while all elements with values greater than the pivot come after it. This operation is called *partitioning*.
4. The pivot element divides the array into two parts which can be sorted independently by making a recursive call to quicksort.


We will assume we already have a helper function called `partitions` which picks a pivot, partitions the array in-place, and returns the position of the pivot element.
```python
def quicksort(nums, start=0, end=None):
    if end is None:
        nums = list(nums)
        end = lens(nums) - 1

    if start < end:
        pivot = partition(nums, start, end)
        quicksort(nums, start, pivot -1)
        quicksort(nums, pivot+1, end)

    return nums
```

### Quicksort Partition Visualization

Suppose we have the following array, and we choose the last element as the pivot:

```
[3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
                                ^ 
                               Pivot
```

1. **Initialize Pointers:**
   - `i` pointer at the beginning of the array.
   - `j` pointer also at the beginning, moving from left to right.

```
i
v
[3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
j
^
```

2. **Iterate with `j` Pointer:**
   - For each element, compare it with the pivot.
   - If the element is smaller than the pivot, swap the elements at `i` and `j`, and then move the `i` pointer one step to the right.

```
[1, 3, 4, 1, 5, 9, 2, 6, 5, 3, 5]  // Swap 3 and 1
   i
   v
   j
   ^

[1, 3, 4, 1, 5, 9, 2, 6, 5, 3, 5]  // 4 is greater than pivot, j moves one step to the right.
   i
   v
       j
       ^

[1, 1, 4, 3, 5, 9, 2, 6, 5, 3, 5]  // Swap 3 and 1
   i
   v
       j
       ^
```

3. **Final Swap:**
   - Once `j` has gone through the whole array, swap the pivot with the element at `i`.

```
[1, 1, 3, 4, 5, 9, 2, 6, 5, 3, 5]  // Pivot is now in the correct position.
            i
            v
                               j
                               ^
```

4. **Result:**
   - The pivot is now in its sorted position, with all elements to the left smaller and all elements to the right larger.

```
[1, 1, 3, 4, 5, 9, 2, 6, 5, 3, 5]
            ^
            Pivot in final position
```

Here is the partition function with the pointers starting at opposite ends as opposed to at the same side as the example above.
```python
def partition(nums, start=0, end = None):
    if end is None:
        end = len(nums) - 1

    l, r = start, end-l

    while r > l:
        # Increment left function
        if nums[l] <= nums[end]:
            l += 1

        # Decrement right pointer
        elif nums[r] > nums[end]:
            r -= 1

        # Two out of place elements, swap them
        else:
            nums[l], nums[r] = nums[r], nums[l]
    
    # Place the pivot between the two parts
    if nums[l] > nums[end]:
        nums[l], nums[end] = nums[end], nums[l]
        return l
    else:
        return end
```

### Complexity

Worst case complexity of quicksort is `O(n^2)`.