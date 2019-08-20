title: Dijkstra's Algorithm
hero: Dijkstra's Algorithm
description: Dijkstra's Algorithm implementation and analysis
author: jchrys

# Dijkstra's Algorithm
> The algorithm finds shortest paths from the starting node to all nodes of the graph, Like [Bellman-Ford algorithm](http://localhost:8000/Algorithms/Graph/Basics/#3_edge_list_representation).

> The Benefit of Dijkstra's algorithm is that it is more efficent and can be used for processing large graphs.

> Dijkstra's algorithm is efficient, because it only process each edge in the graph once, using the fact that there are no negative edges.

!!!warning "Negative edges"
    Dijkstra's algorithm requires that there are no negative weight edges in the graph


## Implementation
> Assume that the graph is stored as an [adjacency lists](http://localhost:8000/Algorithms/Graph/Basics/#1_adjacency_list_representation) so that $adj[a]$ contains a pair $(b, w)$ always when there is an edge from node $a$ to node $b$ with weight $w$

> Use priority queue that contains nodes the nodes ordered by their distances. Using priority queue, the next node to be processed can be retrieved in logarithmic time


```cpp
int distance[];
bool processed[];
priority_queue<int, int> q; // (-dis, node)

for (int i = 1; i <= n; i++) distance[i] = INF;

distance[s] = 0; // starting node s
q.push({0, x});
while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
        int b = u.first, w = u.second;
        if (distance[a] + w < distance[b]) {
            distance[b] = distance[a] + w;
            q.push(-distance[b], b);
        }
    }
}
```

## Time Complexity
> Not yet
