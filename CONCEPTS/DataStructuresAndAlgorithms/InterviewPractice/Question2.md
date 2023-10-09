### Minimum Edit Distance

The following question was asked during a coding interviewat Google:

    Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.) You have the following 3 operations permitted on a word:
    - Insert a character
    - Delete a character
    - Replace a character

### Solution: Step 1

**Input**:
str1 = "intention"
str2 = "execution"

**Output**
output = 5

```python
def min_steps(str1, str2):
    pass

"""
TEST CASES
1. General Case (listed above)
2. No change is required
3. All the characters need to be changed
4. Equal length
5. Unequal length
6. One of the strings is empty 
7. Only requires deletion, addition or swapping.
"""

"""
RECURSION
- If the first character is equal, then ignore from both
- If the first character is not equal
    - either it has to be deleted
        - 1 + recursively solve after ignoring first character of str1
    - or swapped
        - 1 + recursively solve after ignoring the first character of each
    - or character inserted before
        - 1 + recursively solve after ignoring the first character of str2
"""

def min_steps(str1, str2, il=0, i2=0):
    if i1 == len(str1):
        return len(str2) - i2
    elif i2 == len(str2):
        return len(str1) - i1
    elif str1[i1] == str2[i2]
        return min_steps(str1, str2, i1+1, i2+1)
    else:
        return 1 + min(min_steps(str1, str2, i1+1, i2), # Deleted
                        min_steps(str1, str2, i1+1, i2+1), # Swap
                        min_steps(str1, str2, i1, i2+1)) # Inserted

# To remove duplication from the above code, use MEMOIZATION
# 
def min_edit_distance_memo(str1, str2):
    memo = {}
    def recurse(i1, i2):
        key = i1, i2
        if key in memo:
            return memo[key]
        elif i1 == len(str1):
            memo[key] = len(str2) - i2
        elif i2 == len(str2):
            memo[key] = len(str1) - i1
        elif str1[i1] == str2[i2]:
            memo[key] = recurse(i1+1, i2+1)
        else:
            memo[key] = 1 + min(recurse(i1+1, i2),
                                recurse(i1+1, i2+1),
                                recurse(i1, i2+1))
        return memo[key]
    return recurse(0,0)
```

### Solution: Step 2

Whenever you are in doubt, think about recursion. Can you reduce the problem to a combination of one more subproblems. With recursive solutions, normally you start by looking at the first character or the last character.