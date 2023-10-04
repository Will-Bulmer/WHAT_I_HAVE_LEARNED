### Depth-First Search

Start in one direction and keep going till you hit an end. It is how you would solve a maze.

**Question**: Implement depth first search from a given node in a graph using Python

We will write it without recursion by using a **stack** where we perform **last-in first-out**

```pseudocode
procedure DFS_iterative(G, v) is
    let S be a stack
    S.push(v)
    while S is not empty do
        v = S.pop()
        if v is not labelled as discovered then
            label v as discovered
            for all edges from v to w in G.adjacnetEdges(v) do
                S.push(w)
```

```python
def dfs(graph, root):
    stack = []
    discovered = [False] * len(graph.data)
    result = []

    stack.append(root)
    # Don't mark 3 as discovered yet.

    while len(stack) > 0:
        current = stack.pop()
        if not discovered[current]:
        discovered[current] = True
            result.append(current)
            for node in graph.data[current]:
                if not discovered[node]:
                stack.append(node)

    return result
```

If you want to track distance, you will want to use BFS instead!

**Question**: Write a function to detect a cycle in a graph.

