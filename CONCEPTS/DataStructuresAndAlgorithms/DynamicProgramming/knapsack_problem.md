### 0-1 Knapsack Problem

**Problem Statement**: You're in charge of selecting a football (soccer) team from a large pool of players. Each player has a cost, and a rating. You have a limited budget. What is highest total rating of a team that fits within your budget. Assume that there's no minimum or maximum team size

### Solution
In plain english,

Given n elements, each of which has a weight and a profit, determine the maximum profit that can be obtained by selecting a subset of the elements weighing no more than w.

**Input**
1. `weights`: A list of numbers containing weights.
2. `profits`: A list of numbers containing profits (same length as weights).
3. `capacity`: The maximum weight allowed.

**Output**

1. `max_profit`: Maximum profit that can be obtained by selecting elements of total weight no more than `capacity`

**Function Signature**

```python
def max_profit(weights, profits, capacity):
```

### Recursive Solution
Time complexity `O(2^N)`

1. We'll write a recrusive function that computes `max_profit(weights[idx:], profits[idx:], capacity)`, with `idx` starting from 0.
2. If `weights[idx] > capacity`, the current element cannot be selected, so the maximum profit is the same as `max_profit(weights[idx1:], profits[idx+1:], capacity)`.
3. Otherwise, there are two possibilities: we either pick `weights[idx]` or don't. We can recursively compute the maximum.
    A. If we don't pick `weights[idx]`, once again the maximum profit for this case is `max_profit(weights[idx+1:], profits[idx+1], capacity)`
    B. If we pick `weights[idx]`, the maximum profit for this case is `profits[idx] + max_profits(weights[idx+1:], profits[idx+1:], capacity - weights[idx])`

```python
def max_profit_recursive(weights, profits, capacity, idx=0):
    if idx == len(weights):
        return 0
    elif weights[idx] > capacity:
        # Element ignored as it can't fit in the bag
        return max_profit_recursive(weights, profits, capacity, idx+1)
    
    else:
        option1 = max_profit_recursive(weights, profits, capacity, idx+1)
        # Fill the bag
        option2 = profits[idx] + max_profit_recursive(weights, profits, capacity-weights[idx], idx+1)
```

### Dynamic Programming Solution
Time complexity of `O(N * W)`

1. Create a table of size (n+1) * (capacity+1) consisting of all 0s, where `n` is the number of elements. `table[i][c]` represents the maximum profit that can be obtained using the first `i` elements if the maximum capacity is `c`. 
2. We'll fill the table row by row and column by column. `table[i][c]` can be filled using some values in the row above it.
3. If `weights[i] > c` i.e. if the current element is larger than capacity then `table[i+1][c]` is simply equal to `table[i][c]` (since there's no way we can pick this element).
4. If `weights[i] <= c` then we have two choices: to either pick the current element of not to get the value of `table[i+1][c]`. We can compare the maximum profit for both these options and pick the better one as the value of `table[i][c]`.
    A. If we don't pick the element with weight `weights[i]`, then once again the maximum profit is `table[i][c]`
    B. If we pick the element with weight `weights[i]`, then the maximum profit is `profits[i] + table[i][c-weights[i]]`, since we have used up some capacity.

```python
def max_profit_dp(weights, profits, capacity):
    n = len(weights)
    table = [[0 for _ in len(capacity+1)] for _ in len(n+1)]

    for i in range(n):
        for c in range(1, capacity):
            if weights[i] > c:
                table[i+1][c] = table[i][c]
            else:
                table[i+1][c] = max(table[i][c], profits[i] + table[i][c-weights[i]])
    
    return table[-1][-1]

```