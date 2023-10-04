### Weighted Graphs

```python
num_nodes = 9
edges = [(0,1,3), (0,3,2), (0,8,4), (1,7,4), (2,7,2), (2,3,6), (2,5,1)
         (3,4,1), (4,8,8), (5,6,8)]
```
First two numbers in a tuple are the connected nodes, followed by the weight of the path.

### Directed Graphs

```python
num_nodes = 5
edges = [(0,1), (1,2), (2,3), (2,4), (4,2), (3,0)]
directed = True
```
Order of nodes in a tuple matters.

**Question**: Define a class to represent weighted and directed graph in Python.

```python
class Graph:
    def __init__(self, num_nodes, edges, directed=False):
        self.directed = directed
        self.weighted = len(edges) > 0 and len(edges[0]) == 3
        self.data = [[] for _ in range(num_nodes)]
        self.weight = [[] for _ in range(num_nodes)]

        for e in edges:
            self.data[e[0]].append(e[1])
            if self.weighted:
                self.weight[e[0]].append(e[2])
            if not directed:
                self.data[e[1]].append(e[2])
                if self.weighted:
                    self.weight[e[1]].append(e[2])

    
    def __repr__(self):
        result = ""
        if self.weighted:
            for i, (nodes, weights) in enumerate(zip(self.data, self.weight)):
                result += "{}: {}".format(i, list(zip(nodes, weights)))
        else:
            for i, nodes in enumerate(self.data):
                result += "{}: {}\n".format(i, nodes)
        return result
```