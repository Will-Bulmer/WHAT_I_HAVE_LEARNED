### Divide and Conquer

1. Divide the inputs into two roughly equal parts.
2. Recusrively solve the problem individually for each of the two parts.
3. Combine the results to solve the problem for the original inputs.
4. Include terminating conditions for small of indivisible inputs.

### Merge Sort
This is what the divide and conquer algorithm is called.

1. If the input list is empty or contains just one element, it is already sorted. Return it.
2. If not, divide the list of numbers into two roughly equal parts.
3. Sort each part recursively using the merge sort algorithm. You'll get back two sorted lists.
4. Merge the two sorted lists to get a single sorted list.

**Question 3**: Write a function to merge two sorted arrays.

```python
def merge_sort(nums):
    # Terminating condition (list of 0 or 1 elements)
    if len(nums) <= 1:
        return nums
    
    # Get the midpoint
    mid = len(nums) // 2 # Double slash returns an integer

    # Split the list into two halves
    left = nums[:mid]
    right = nums[mid:]

    # Solve the problem for each half recursively
    left_sorted, right_sorted = merge_sort(left), merge_sort(right)

    # Combine the results of the two halves
    sorted_nums = merge(left_sorted, right_sorted)

    return sorted_nums
```

```python
def merge(nums1, nums2):
    # List to store the results
    merged = []

    # Indices for iteration
    i, j = 0, 0

    # Loops over the two lists
    while i < len(nums1) and j < len(nums2):

        # Include the smaller element in the result and move to next element
        if nums1[i] <= nums2[j]:
            merged.append(nums1[i])
            i+=1
        else:
            merged.append(num2[j])
            j+=1
        
        # Get the remaining parts
        nums1_tail = nums1[i:]
        nums2_tail = nums2[j:]

        # Retrun the final merged array
        return merged + nums1_tail + nums2_tails
```

### Complexity

Complexity of merge sort is `O(nlog n)` with the right choice of pivot (random), with worst case `O(n^2)` which is as bad as bubble sort (only worst case though).