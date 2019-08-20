title: Bellman-Ford Algorithm
hero: Bellman-Ford Algorithm
description: Bellman-Ford algorithm implementation and analysis
author: jchrys

# Bellman-Ford Algorithm
> The Bellman-Ford algorithm finds shortest paths from a starting node to all nodes of the graph.

> The algorithm reduces the distance by finding edges that shorten the paths until it is not possible to reduce any distances.

!!!note "Bellman-Ford can process all kinds of graphs"
    The algorithm can process all kinds of graphs, provided that the graph does not contain a cycle with negative length. *If the graph contains a negative cycle, the algorithm can detect this.*

## Implementation
> Assume that  the graph is stored as an [edge list](/Algorithms/Graph/Basics/#3_edge_list_representation)

> edge that consists of tuples of the form$(a, b, w)$, meaing that there is an edge from node $a$ to node $b$ with weight $w$.

> The algorithm consists of $n-1$ rounds, and on each round the round the algorithm goes through all edges of the graph and tries to reduce the distances.
> The algorithm constructs an array $\text{distance}$ that will contain the distance from x to all nodes of the graph. The constant INF denotes an infinite distance.


> $n = \text{number of vertices(nodes)}$, $m = \text{number of edges}$


```cpp
int const INF = 2e9;
tuple<int, int, int> edges[m]; //edge list

for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[s] = 0; // starting node s
for (int i = 1; i <= n-1; i++) {
    for (auto e: edges) {
        int a, b, w;
        tie(a, b, w) = e;
        distance[b] = min(distance[b], distance[a] + w);
    }
}
```

## Time Complexity
> $\Omicron(nm)$


## Negative Cycles
> The algorithm can also be used to check if the graph contains a cycle with negative length.

> A negative cycle can be detected using the Bellman-Ford algorithm by running the algorithm for $n$ rounds

> If the n-th round reduces any distance, the graph contains a negative cycle. 

!!!note "Negative cycle in the whole graph"
    Note that this algorithm can be used to search for a negative cycle in the whole graph regardless of the starting node 
