### Conveying Graph Structure
To create a graph, you need the nodes and connections
```python
num_nodes = 5
edges = [(0, 1), (0, 4), (1, 2), (1, 3), (1, 4), (2, 3), (3, 4)]
```

### Adjacency Lists

**Question 1**: Create a class to represent a graph as an adjacency list in Python.

0 -> 1,4
1 -> 0,2,3,4
2 -> 1,3
3 -> 1,2,4
4 -> 0,1,3

```python
class Graph:
    def __init__(self, num_nodes, edges):
        self.num_nodes = num_nodes
        self.data = [[] for _ in range(num_nodes)]
        for n1, n2 in edges:
            self.data[n1].append(n2)
            self.data[n2].append(n1)

    def __repr__(self):
        # Gives index as well as values as tuples
        return "\n".join(["{}: {}".format(n, neighbors) for n, neighbors in enumerate(self.data)])

    def __str__(self):
        return self.__repr__()
```

**Question**: Write a function to add an edge to a graph represented as an adjancency list.
**Question**: Write a function to remove an edge from a graph represented as an adjacency list.
**Question**: Represent a graph as an adjacency matrix.