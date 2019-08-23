Title: Spanning Tree
Summary: A brief description of Spanning trees and implementation
Authors: JChrys
Date: August 22, 2019

# Spanning Trees
> A spanning tree of a graph consists of all nodes of the graph and some of the edges of the graph so that there is a path between any two nodes.

> Like trees in general, spanning trees are connected and acyclic.

> Usually there are several ways to construct a spanning tree.

> Note that a graph may have several minimum and maximum spanning trees, so the trees ar not unique.

> It turns out that several greedy methods can be used to construct minimum and maximum spanning trees.
### terminologies
- Weight of spanning tree: sum of its edge weights.
- Minimum spanning tree: a spanning tree whose weight is as small as possible


## Kruskal's Algorithms
> The initial spanning tree only contains the nodes of the graph and does not contain any edges.
> Then the algorithm goes through edges ordered by their weights, and always adds an edge to the tree if it does not create a cycle.
> The algorithm maintains the components of the tree. Initially each node of the graph belongs to a separate component.
> Always when an edge is added to the tree, two components are joined.
> Finally, all nodes belong to the same component and a minimum spanning tree has been found


### Implementation
> It's convinient to use the [edge list representation](/Algorithms/Graph/Basics/#3_edge_list_representation)

```cpp
vector<pair<int u, int v>> edges; //edge list
sort(vector.begin(), vector.end());

for (auto edge : edges) { //using union find structure
    if (!same(a, b)) unite(a, b);
}

```

!!! note "efficiency"
    The problem is how to efficiently implement the function `same` and `unite`. One possibility is to implement function `same` as a graph traversal and check if we can get from node `a` to node `b`. However, the time complexity of such a function would be $\Omicron(n+m)$ and resulting algorithm would be slow, because the function `same` will be called for each edge in graph.

### Union find structure
> Using a *Union find structure* implements both $same$ and $unite$ functions in $\Omicron(lg(n))$ time. thus the time complexity of Kruskal's algorithm will be $\Omicron(mlg(n))$

#### Structure
> In a union-find structure, one element in each set is the representative of the set, and there is a chain from any other element of the set to the representative.

> The efficiency of the union-find structure depends on how the sets are joined. 

> It turns out that we can follow a simple strategy:*always connect the representative the smaller set to the representative of larger set*.
> Using this strategy, the length of any chain will be $\Omicron(lg(n))$ 

#### Implementation
> The union-find structure can be implemented using arrays.

> `link` contains for each element the next element in the chain or the element it self if it is representative.

> and the array `size` indicates for each representative the size of thecorresponding set.

```cpp
for (int i = 1; i <= n; i++) link[i] = i;
for (int i = 1; i <= n; i++) size[i] = 1;

int find(int x) { 
// returns the representative for an element x.
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) { 
// returns whether elements a and b belong to the same set
    return find(a) == find(b);
}

void unite(int a, int b) {
// joins the set that contains elements a and b
// it connects the smaller set to the larger set
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


```

## Prim's algorithm
> The algorithm first adds an arbitrary node to the tree.
> After this, the algorithm always choose a minimum-weight edge that adds a new node to the tree.
> Finally all nodes have been added to the tree and a minimum tree has been found

> Prim's algorithm resembles [Dijkstra's algorithm](/Algorithms/Graph/ShortestPaths/Dijkstra/). 
> But, Prim's algorithm simply selects the minimum weight edge that adds a new node to the tree.

### Implementation
> Like [Dijkstra's algorithm](/Algorithms/Graph/ShortestPaths/Dijkstra/), Prim's algorithm can be efficiently implemented using a priority queue.

> The priority queue should contain all nodes that can be conneted to the current component using a single edge, in increasing order of the weights of the corresponding edges.

> The time complexity of Prim's algorithm is $\Omicron(n+ mlg(m))$ that equals the time complexity of Dijkstra's algorithm.

> most competitive programmers use Kruskal's algorithm.

```cpp
int V; // #nodes(vertices)
int E; // #edges 
int const INF = 2e9;

vector<vector<pair<int, int>>> adj; //adjacency list
using node = pair<int, int>; // pair<key, node> representation.

void Prim() {
    priority_queue<node, vector<node>, greater<node>> pq;
    //mean-heap implementation using stl

    int starter = 0; // starting node or initial node.

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, starter});
    int MST_weight = 0;

    while (!pq.empty()) {
        int w = pq.top().first; 
        // minimum weight to add a new vertice to MST
        int u = pq.top().second;
        // new vertice
        pq.pop();
        if (inMST[u]) continue;
        // if u already in MST continue;
        inMST[u] = true;
        // else add u to MST;
        MST_weight += w;
        for (auto vw : adj[u]) {
            int v = vw.first;
            int w = vw.second;
            if (inMST[v] == false && key[v] > w) {
                // only when new key(weight) value of v is less than current value
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
}
```
