### Insertion Sort
We keep the initial portion of the array sorted and insert the remaining elements one by one at the right position.

```python
def insertion_sort(nums):
    nums = list(nums)
    for i in range(len(nums)):
        cur = nums.pop(i)
        j = j-1
        while j >= 0 and nums[j] > cur:
            j -= 1
        nums.insert(j+1, cur)
    return nums
```