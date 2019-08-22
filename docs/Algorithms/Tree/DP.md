title: Tree Dynamic Programming
hero: Tree Dynamic Programming
description: Dynamic Programming on Tree
author: jchrys

# Tree Dynamic Programming
> Dynamic programming can be used to calculate some information during a tree traversal.

## Time Complexities
> Not yet added



### The number of nodes in its subtree
> The subtree contains the node itself and all nodes in the subtrees of its children. 
> so we can calculate the number of nodes recursively using the following code

> Time complexity: $\Omicron(n)$

```cpp
int count[#nodes];

void dfs(int s, int e) { //current node s, previous node e;
    count[s] = 1;
    for (auto u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        count[s] += count[u];
    }
}
```

## Diameter
> The Diameter of a tree is the maximum length of a path between two nodes.

### Algorithm 1 (based on DP)
> _A general way to approach many tree problems is to first root the tree arbitrarily_.
> After this, we can try to solve the problem separately for each subtree.
> Our first algorithm for calculating the diameter is based on this idea.


<del> An important observation is that every path in a rooted tree has a _highest point_: the highest node that belongs to the path. Thus we can calculate for each node the length of the longest path whose heighest point is the node. One of those path corresponds to the diameter of the tree.
</del>


> We calculate for each node $x$ two values:

<del> - toLeaf(x): the maximum length of a path from x to any leaf</del>  
<del> - maxLength(x): the maximum length of a path whose highest point is $x$</del>  

- $f(x)$: Longest path starts from node $x$ and goes into its subtree.

- $g(x)$: Longest path starts in subtree of $x$, passes through $x$ and ends in subtree of $x$

> If for all nodes $x$, we take maximum of $f(x), g(x)$, then we can get the diameter.

> Dynamic programming can be used to calculate the above values for all nodes in $\Omicron(n)$ time. 

#### Implementation

```cpp
//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int f[N], g[N], diameter;

// pV is parent of node V
void dfs(int V, int pV) {
    //this vector will store f for all children of V
    vector<int> fValues;

    //traverse over all children
    for (auto v: adj[V]) {
        if (v == pV) continue;
        dfs(v, V);
        fValues.push_back(f[v]);
    }

    //sort to get top two values
    // you can also get top two values without sorting in O(N)
    // current complexity is n lg n
    sort(fValues.begin(), fValues.end());
    
    f[V] = 1;
    if (! fValues.empty()) f[V] += fValues.back();

    if (fValues.size()>=2)
        g[V] = 2 + fValues.back() + fValues[fValues.size() -2];
    diameter = max(diameter, max(f[V], g[V]));
}
```
#### More General Implementation
> with weighted edges

```cpp
//adjacency list 
//adj[i] contains all neighbors of i, and weights to i -> its neighbor
vector<vector<pair<int, int>>> adj[N];
int diameter = 0;

void dfs(int V, int pV) {
    vector<int> fValues;

    for (auto v : adj[V]) {
        if (v.first == pV) continue;
        dfs(v.first, V);
        fValues.push_back(f[v.first] + v.second); // fvalue of child + weight of edge;
    }

    int a = -1, b = -1; // a is biggest, b is second to biggest
    for (auto x: fValues) {
        if (x > a) {
            b = a;
            a = x;
        } else if (x > b) {
            b = x;
        }
    }
    f[V] = 0;
    if (a > 0) f[V] = a;
    
    if (a > 0 && b > 0)
        g[V] = a + b;
    diameter = max(diameter, max(f[V], g[V]));
}
```

### Algorithm 2 (based on DFS)
> Another efficient way to calculate the diameter of a tree is based on two depth-first searches.
> First, we choose an arbitrary node $a$ in the tree and find the farthest node $b$ from $a$.
> Then, we find the farthest node $c$ from $b$. The diameter of the tree is the distance between $b$ and $c$.

#### How this works?
> Not yet added

#### implementation

```cpp
int firstFar;
int diameter = 0;
void dfs(int V, int pV, int dis) {
    if (diameter < dis) {
        diameter = dis;
        firstFar = V;
    }
    for (auto v : adj[V]) {
        if (v.first == pV) continue;
        dfs(v.first, V, dis + v.second); // v.first == neighbor node, v.second weight of edge
    }
}

dfs(0, 0, 0) //initial call
// diameter = 0; // not necessary;
dfs(firstFar, 0, 0);
// now diameter is diameter of tree
```



#### resources
https://codeforces.com/blog/entry/20935

