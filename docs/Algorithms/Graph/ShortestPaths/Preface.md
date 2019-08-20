title: Preface
hero: Shortest Paths
description: short description on algorithms on shortest paths, comparison
author: jchrys

# Shortest Paths
> Finding a shortest path between two nodes of a graph is an important problem that has many practical applications.

> In an uweighted graph, the length of a path equals the number of its edges, and we can simply use breath-first search to find a shortest path. However, in this chapter we focus on weighted graphs where more sophisticated algorithms are needed for shortest paths.



## Diff
> $n = \text{number of nodes}$, $m = \text{number of edges}$


|                |      TimeComplexity     |        DS        |                      -                     |
|:--------------:|:-----------------------:|:----------------:|:------------------------------------------:|
|  Bellman-Ford  |      $\Omicron(nm)$     |     edge list    |             neg-cycle detection            |
|      SPFA      |      $\Omicron(nm)$     |                  |                                            |
|    Dijkstra    | $\Omicron(n + m\lg(m))$ |  adjacency lists |                no neg edges                |
| Floyd-Warshall |     $\Omicron(n^3)$     | adjacency matrix | finds all shortest paths between the nodes |
