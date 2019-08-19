title: Graph Traversal
hero: Graph Traversal
description: DFS, BFS and others
author: jchrys

# Graph Traversal
> We will cover two fundamental graph algorithms. depth-first search & breadth-first search.

!!!note "BFS vs DFS"
    Both algorithms are given starting node in the graph and they visit all nodes that can be reached from the starting node. The difference in algorithms is the order in which they visit the nodes.

## Depth-first search($\text{DFS}$)
> Depth-first search always follows a single path in the graph as long as it find new nodes. After this, it returns to previous nodes and begin to explore other parts of the graph.

> The algorithm keeps track of visited nodes, so that it processes each node only once

### Implementation
> Using adjacency lists in an array   
> maintain an array visited[N]
```cpp
vector<int> adj[N]; //adjacency lists
bool visited[N];

void dfs(int s) { //starting node s
    if (visited[s]) return;
    visited[s] = true;
    // process node
    for (auto u: adj[s]) {
        dfs(u);
    }
}
```

## Breadth-first search($\text{BFS}$)
> Breadth-first search visits the nodes in increasing order of their distance from the starting node.

> Thus, we can calculate the distance from the starting node to all other nodes using $BFS$.

### Implementation
> Typical implementation is based on a queue that contains nodes.

```cpp
queue<int> q;
bool visited[N];
int distance[N];

visited[s] = true; // starting node s
distance[s] = 0;
q.push(s);

while (!q.empty()) {
    int cur = q.front(); q.pop();
    // process node
    for (auto next : adj[cur]) {
        if (visited[next]) continue;
        visited[next] = true;
        distance[next] = distance[cur] + 1;
        q.push(next);
    }
}

```


## Applications
> You can use any of both to check properties of graph  
> but in practice,  depth-first search  is a better choice, because of ease of implementation


### 1. Connectivity check
> A graph is connected if there is a path between any two nodes of the graph
#### Implementation
- Connected Graph: If a search did not visit all the nodes, we can conclude that the graph is not connected
- Find all components of Graph: iterating through the nodes and always starting a new depth-first search if the current node does not belong to any component yet


### 2. Finding cycles

#### Implementation
- Way1: A graph contains a cycle if during a graph traversal, we find a node whose neighbor (other than the previous node in the current path) has already been visited

- Way2(math): if a component contains c nodes and no cycle, it must contain exactly c-1 edges. if there are c or more edges, the component surely contains a cycle

### 3. Bipartiteness check
> A graph is bipartite if its nodes can be colored using two colors so that there are no adjacent nodes with the same color

#### Implementation
> The idea is to color the starting node blue, all its neighbors red, all their neighbors blue, and so on. If at some point of the search we notice that two adjacent nodes have the same color, this means that the graph is not bipartite. Otherwise, the graph is bipartite.

!!!note "Why it works?"
    This algorithm always works, because when there are only two colors available, the color of the starting node in a component determines the colors of all other nodes in the component


!!!warning "NP-hard"
    Note that in the general case, it is difficult to find out if the nodes in a graph can be colored using $k$ colors so that no adjacent nodes have the same color. 
    Even when $k=3$, no efficient algorithm is known but the problem is NP-hard
