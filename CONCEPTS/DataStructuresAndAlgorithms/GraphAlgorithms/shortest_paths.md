### Shortest Paths

**Question**: Write a function to find the length of the shortest path between two nodes in a weighted directed graph.

If there are no weights involved, you can just use **breadth-first search**.

### Dijkstra's Algorithm
For an undirected graph:

1. Mark all nodes unvisited. Create a set of all the unvisisted nodes called the unvisited set.
2. Assign to every node a tentative distance value: set it to zero for our ititial node and to infinity for all other nodes. Set the initial node as current.
3. For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8, then change it to 8. Otherwise, the current value will be kept.
4. When we are done considering all of the unvisited neighbours of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm is finished.
6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

First, we will make the helper functions:

```python
def shortest_path(graph, source, target):
    visited = [False] * len(graph.data)
    parent = [False] * len(graph.data)
    distance = [float('inf')] * len(graph.data)
    queue = []

    distance[source] = 0
    queue.append(source)
    idx = 0

    while idx < len(queue) and not visited[target]:
        current = queue[idx]
        visited[current] = True
        idx += 1
        # update the distances of all the neighbors
        updatae_distances(graph, current, distance, parent)
        # find the first unvisited node with the smallest distance
        next_node = pick_next_node(distance, visited)
        if next_node:
            queue.append(next_node)
        visited[current] = True
    
    return distance[target], parent

def update_distances(graph, current, distance, parent=None):
    """Update the distances of the current noe's neighbors"""
    neighbors = graph.data[current]
    weights = graph.weight[current]
    for i, node in enumerate(neighbors):
        weight = weight[i]
        if distance[current] + weight < distance[node]:
            distance[node] = distance[current] + weight
            if parent:
                parent[node] = current

# Improvement on this is using a minHeap so you don't have to look through
# the entire list of nodes each time.
def pick_next_node(distance, visited):
    """Pick the next unvisited node at the smallest distance"""
    min_distance = float('inf')
    min_node = None
    for node in range(len(distance)):
        if not visited[node] and distance[node] < min_distance:
            min_node = node
            min_distance = distance[node]
    return min_node
```

### Binary Heap
A data structure to maintain the running minimum/maximum of a set of numbers, supporting efficient addition/removal.

Heap Operations:
- Insertion - `O(log N)`
- Min/ Max - `O(1)`, depending on the type of heap
- Deletion - `O(logN)`

Python has a built-in heap.

**Min Heap**: Left of node is less. Right of node is more.
**Max Heap**: Left of node is more. Right of node is less.

So for the Min Heap, getting the next node is as simple as selecting the minimum value.