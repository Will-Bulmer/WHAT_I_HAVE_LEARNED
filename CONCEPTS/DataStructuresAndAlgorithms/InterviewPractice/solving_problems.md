## Tips on how to solve coding problems

1. State the problem clearly. Identify the input and output formats.
2. Come up with some example inputs and outputs. Try to cover all edge cases.
3. Come up with the correct solution for the problem. State it in plain English.
4. Implement the solution and test it using example inputs. Fix bugs, if any.
5. Analyze the algorithm's complexity and identify inefficiencies, if any.
6. Apply the right technique to overcome the inefficiency. Repeat steps 3 to 6.

### Example Problem - Binary Search

Alice has some cards with numbers written on them. She arranges the cards in decreasing order, and lays them out face down in a sequence on a table. She challegnes Bob to pick out the card containing a given number by turning over as few cards as possible. Write a function to help Bob locate the card.

### Solution

#### 1. State the problem clearly
Represent the cards as a list of numbers. Turning over a specific card is equivalent to accessing the value of the number at the corresponding position the list. So we can now state the problem as follows:

**Problem:**
    We need to write a program to find the position of a given number in a list of numbers arranged in decreasing order. We also need to minimize the number of times we access elements from the list

**Input:**
    1. `cards`: A list of numbers sorted in decreasing order. E.g. [13,11,7,4]
    2. `query`: A number, whose position in the array is to be determined. E.g. `7`

**Output:**
    3. `position`: The position of `query` in the list `cards`. E.g. `3` in the above case (counting from `0`)

Based on the above, we can now create the signature of our function:

```python
def locate_card(cards, query):
    pass
```

#### 2. Come up with example inputs & outputs
Develop *test cases*.
```python
cards = [13, 11, 10, 7, 4, 3, 1, 0]
query = 7
output = 3

result = locate_card(cards, query)
print(result)
assert result == output
```

We are testing over and over, and so we will represent our test cases as dictionaries. 
```python
test = {
    'input': {
        'cards': [13, 11, 10, 7, 4, 3, 1, 0],
        'query': 7
    },
    'output': 3
    }
locate_card(**test['input']) == test['output']
```

Here are some possible edge cases:
1. The number `query` occurs somewhere in the middle of the list `cards`
2. `query` is the first element in `cards`
3. `query` is the last element in `cards`
4. The list `cards` contains just one element, which is `query`
5. The list `cards` does not contain number `query`
6. The list `cards` is empty
7. The list `cards` contains repeating numbers
8. The number `query` occurs at more than one position in `cards`

We can add these tests:
```python
# cards does not contain query
tests.append({
    'input': {
        'cards': [9, 7, 5, 2, -9],
        'query': 4
    },
    'output': -1
    })
```

#### 3. Come up with a correct solution for the problem.
We should use first the simplest solution. *Brute force*. Bob can simply turn over cards in order one by one, till he finds a card with the given number on it. Here's how we may implement it:

1. Create a variable `position` with the value 0.
2. Check whether the number at index `position` in `card` equals `query`
3. If it does, `position` is the answer and can be returned from the function.
4. If not, increment the value of `position` by 1, and repeat steps 2 to 5 till we reach the last position.
5. If the number was not found, return `-1`.

**Linear Search Algorithm**: An algorithm is a list of statements that can be converted into code and executed by a computer. This particular one is called **Linear Search**.

#### 4. Implement the solution
```python
def locate_card(cards, query):
    # Create a variable position with the value 0
    position = 0

    # Set up a loop for repetition
    while True:

        # Check if element at the current position matches the query
        if cards[position] == query:

            # Anaswer found! Return and exit..
            return position
        # Increment the position
        position += 1

        # Check if we have reached the end of the array
        if position == len(cards):

            # Number not found, return -1
            return -1
```

Due to test case of an empty list, we must now change our function as follows:

```python
def locate_card(cards, query):
    position = 0
    while position < len(cards):
        if carrds[position] == query:
            return position
        position += 1
    return -1
```

#### 5. Analyze the algorithm's complexity and identify inefficiencies, if any
Recall: **turning over as few cards as possible**. The worst Bob can do out of N cards, is turn over N times.

The field of study concerned with finding the amount of time, space or other resrouces required to complete the execution of computer programs is called **the analysis of algorithms**. The process of finding out the best algorithm to solve a given problem is called **algorithm design and optimization**.

