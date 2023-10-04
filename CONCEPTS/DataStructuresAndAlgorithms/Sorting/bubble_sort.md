### Bubble Sort

1. Iterate over the list of numbers, starting from the left.
2. Compare each number with the number that follows it.
3. If the number is greater than the one that follows it, swap the two elements
4. Repeat 1-3 until sorted.

Needs to be repeated `n-1` times.

```python
def bubble_sort(nums):
    nums = list(nums)

    for _ in range(len(nums) - 1):
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                nums[i], nums[i+1] = nums[i+1], nums[i]

    return nums
```

### Complexity
Core operations are compare and swap. Total swaps will be less than or equal to the number of comparisons. We need to count the number of comparisons.
Two loops of length `n-1` so comparison is (n-1)*(n-1) which is `O(N^2)`

Inefficiency comes since we are shifting elements by at most one position at a time.