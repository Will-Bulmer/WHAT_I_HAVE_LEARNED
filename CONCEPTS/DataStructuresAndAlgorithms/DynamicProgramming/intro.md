### Problem Statement

**QUESTION 1**: Write a function to find the length of the **longest common subsequence** between two sequences. E.g. Given the strings "serendipitous" and "precipitation", the longest common subsequence is "reipito" and its length is 7.

A *sequences* is a group of items with a deterministic ordering. Lists, tuples and ranges are some common sequence types in Python.

A *subsequence* is a sequence obtaining by deleting zero or more elements from another sequence.

**Input**
1. **seq1**: A sequence e.g. 'serendipitous'
2. **seq2**: Another sequence e.g. 'precipitation'

**Output**
1. **len_lcs**: Length of the longest common subsequence, 7.

**Signature**

```python
def len_lcs(seq1, seq2):
    pass
```

### Recursive Solution
1. Create two counters `idx1` and `idx2` starting at 0. Our recursive function will compute the LCS of `seq1[idx1:]` and `seq2[idx2:]`
2. If `seq1[idx1]` and `seq[idx2]` are equal, then this character belong to the LCS of `seq1[idx1:]` and `seq2[idx2:]`. Further, the length this is LCS is one more than LCS of `seq1[idx1+1:]` and `seq2[idx2+1:]`
3. If not, then LCS of `seq1[idx1:]` and `seq2[idx2:]` is the longer one among the LCS of `seq1[idx1:], seq2[idx2:]` and the LCS of `seq1[idx1:]`, `seq2[idx2+1:]`
4. If either `seq1[idx1:]` or `seq2[idx2:]` is empty, then their LCS is empty.


```python
def lcs_recursive(seq1, seq2, idx1=0, idx2=0):
    if idx1 == len(seq1) or idx2 == len(seq2):
        return 0
    elif seq1[idx1] == seq2[idx2]:
        return 1 + lcs_recursive(seq1, seq2, idx1+1, idx2+1)
    else:
        option1 = lcs_recursive(seq1, seq2, idx1+1, idx2)
        option2 = lcs_recursive(seq1, seq2, idx, idx2+1)
        return max(option1, option2)
```

### Time Complexity
- `O(2^(m+n))`

```python
def lcs_memo(seq1, seq2):
    memo = {}
    def recurse(idx1=0, idx2=0):
        key = (idx1, idx2)
        if key in memo:
            return memo[key]
        elif idx1 == len(seq1) or idx2 == len(seq2):
            memo[key]
        elif seq1[idx1] == seq2[idx2]:
            memo[key] = 1 + recurse(idx1+1, idx2+1)
        else:
            memo[key] = max(recurse(idx1+1, idx2), recurse(idx1, idx2+1))
        return memo[key]
    return recurse(0,0)
```

### Dynamic Programming
Recursion can take up a lot of memory. The solution to replace recursion is to do *dynamic programming*

1. Create a table of size `(n1+1) * (n2+1)` initialized with 0s, where `n1` and `n2` are the lengths of the sequences. `table[i][j]` represents the longest common subsequence of `seq[:i]` and `seq[:j]`.
2. If `seq1[i]` and `seq2[j]` are equal, then `table[i+1][j+1] = 1 + table[i][j]`.
3. If `seq1[i]` and `seq2[j]` are equal, then `table[i+1][j+1] = max(table[i][j+1], table[i+1][j])`

This has complexity `O(N1 * N2)`

```python
def lcs_dp(seq1, seq2):
    n1, n2 = len(seq1), len(seq2)
    table = [[0 for x in range(n2)] for x in range(n1)] # Create matrix

    for idx1 in range(n1):
        for idx2 in range(n2):
            if seq1[idx1] == seq2[idx2]:
                table[i+1, j+1] = 1 + table[i][j]
            else:
                table[i+1][j+1] = max(table[i][j+1], table[i+1][j])
    return table[-1][-1]
```

