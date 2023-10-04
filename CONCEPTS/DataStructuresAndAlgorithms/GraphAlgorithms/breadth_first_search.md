### Breadth-First Search

**Question**: Implement Breadth-First Search given a source node in a graph using Python.

BFS pseudocode (Wikipedia):
```pseudocode
procedure BFS(G, root) is
    let Q be a queue
    label root as discovered
    Q.enqueue(root)
    while Q is not empty do
        v := Q.dequeue()
        for all edges from v to w in G.adjacentEdges(v) do
            if w is not labelled as discovered then
                label w as discovered
                Q.enqueue(w)
```

This executes the **first-in first-out** queue policy.

```python
def bfs(graph, root):
    queue = []
    discovered = [False] * len(graph.data)
    distance = [None] * len(graph.data)
    parent = [None] * len(graph.data)

    discovered[root] = True
    queue.append(root)
    distance[root] = 0
    idx = 0 # Tracks first available element in the queue 

    while idx < len(queue):
        # dequeue
        current = queue[idx]
        idx += 1 

        # Check all the edges of current
        for node in self.data[current]:
            if not discovered[node]:
                distance[node] = 1 + distance[current]
                parent[node] = current
                discovered[node] = True
                queue.append(node)
    return queue, distance, parent
```

**Question**: Write a prgram to check if all the nodes in a graph are connected.