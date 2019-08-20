title: Floyd-Warshall Algorithm
hero: Floyd-Warshall Algorithm
description: Floyd-Warshall Algorithm implementation and analysis, shortest path in graph
arthur: jchrys

# Floyd-Warshall Algorithm
> Floyd-Warshall algorithm provides an alternative way to approach th problem of finding shortest paths.

> Floyd-Warhsall algorithm finds all shortests paths between the nodes in a single run.

> Floyd-Warhsall algorithm maintains a two-dimensional array that contains distances between the nodes.

> Floyd-warshall algorithm is easy to implement.

> Floyd-warhsall algorithm reduces distance by intermediate nodes in paths.

## Implementation
> Assume using [adjacency matrix](http://localhost:8000/Algorithms/Graph/Basics/#2_adjacency_matrix_representation)

```cpp
// first build distance (2-dimensional array)
int const INF = 2e9;
int adj[][];
int distance[][];

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == j) distance[i][j] = 0;
        else if (adj[i][j]) distance[i][j] = adj[i][j];
        else distance[i][j] = INF;
    }
}

```
```cpp
// process
for (int k = 1; k <= n; k++) { // k == intermediate node
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            distance[i][j] = min(distance[i][j], 
                                 distance[i][k] + distance[k][j])
        }
    }
}


```

## Time Complexity
> $\Omicron(n^3)$
