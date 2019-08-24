# Directed graphs

- Acyclic graphs($\text{DAGs}$): There are no cycles in the graph, so there is no path from any node to itself.
- Successor graphs: The out degree of each node is 1, so each node has a unique successor.

## Topological sorting
> A Topological sort is an ordering of the nodes of a directed graph such that if there is a path from node $a$ to node $b$, then node $a$ appears before node $b$ in the ordering.

> An acyclic graph always has a topological sort.

!!! note 
    It turns out that depth-first search($\text{DFS}$) can be used to both check if a directed graph contains a cycle and, if it does not contain a cycle, to construct a topological sort.

### Implementation(Using DFS)
> The idea is to go through the nodes of the graph and always begin a depth-first search at the current node if it has not been processed yet. during the the searches the node have three possible states:

- state 0: the node has not been processed
- state 1: the node is under processing
- state 2: the node has been processed

> Initially, the state of each node is 0. When a search reaches a node for the first time, its state becomes1. Finally, after all successors of the node have been processed, its state becomes 2.

> If the graph contains a cycle, we will find this out during the search, because sooner or later we wil arrive at a node whose state is 1. In this case, it is not possible to construct a topological sort.

> If the graph does not contain a cycle, we can construct a topological sort by adding each node to a list when the state of the node becomes 2. This list in reverse order is topological sort.

```cpp
vector<int> adj[];  // adjancency list
int color[];        // array: color of nodes
vector<int> topsort 
bool cycle = false;

void dfs(int u) {
    if (color[u] == 2) return; //already processed
    if (color[u] == 1) {
        //cycle detected
        cycle = true;
        return;
    }
    color[u] = 1; // color as under processing

    for (auto v : adj[u]) 
        dfs(v);

    color[u] == 2
    topsort.push_back(u);
}

for (int i = 0; i < #edges; i++) {
    if (color[i] == 0) // if node is not processed yet
        dfs(i);
}

if (cycle) {
    cout << "cycle detected" << endl;
} else {
    for (auto it = topsort.rbegin(); it != topsort.rend(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}
```
### Related Problems
1. [작업순서](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18TrIqIwUCFAZN):star::star:

## Dynamic Programming
> If a directed graph is acyclic, dynamic programming can be applied to it.
> For example, we can efficiently solve the following problems concerning paths from a starting node to and ending node

### 1. Counting the number of paths
> Let `paths(x)` denote the number of paths from node $1$ to node $x$.
> As a basecase, `paths(1)` 1. Then to calculate other values of `paths(x)`, we may use recursion
```
paths(x) = paths(a1) + paths(a2) + ... + paths(ak)
```
> where a1, a2, ..., ak are the nodes from which there is an edge to x.

> Since the graph is acyclic the values of `paths(x)` can be calculated in the order of topological sort.

### 2. Extending Dijkstra's algorithm
> A by-product of Dijkstra's algorithm is a directed, acyclic graph that indicates for each node of the original graph the possible ways to reach the node using a shortest path from the starting node. Dynamic programming can be applied to that graph.

> thus we can find number of shortest paths from node $a$ to node $b$

### 3. Representing problems as graphs
> Actually, any dynamic programming problem can be represented as a directed acyclic graph. In such a graph, each node coressponds to a dynamic programming state and the edges indicate how the states depend on each other.


## Successor paths
> Successor graphs: the outdegree of each node is 1.

> A successor graph consists of one or more components, each of which contains one cycle and some paths that lead to it.

> Successor graphs are sometimes called functional graphs. The reason for that is that any successor graph corresponds to a function that defines the edges of the graph.

> The parameter of the function is a node of the graph, and the function gives the successor of that node.

### `succ(x, k)`
> Since each node of a successor graph has a unique successor, we can also define a function `succ(x, k)` that gives the node that we will reach if we begin at node `x` and `k` step forward.

> Using preprocessing, any value of `succ(x, k)` can be calculated only $\Omicron(lgk)$ time.

> The idea is to precalculate all values of `succ(x, k)` where `k` is a power of two and at most `u`, where u is the maximum number of steps we will ever walk.

> This can be efficiently done, because we can use the following recursion

```
int succ(x, k) {
    if (k == 1) {
        return succ(x);
    }
    succ(succ(x, k/2), k/2);
}
```

> Precalculating the values takes $\Omicron(nlgu)$ time because $\Omicron(lgu)$ values are calculated for each node.

> After precalculating, any value of `succ(x, k)` can be calculating presenting the number of steps k as a sum of pwoers of two.

$$
succ(x, 11) = succ(succ(succ(x, 8), 2), 1);
$$

> Such a representation always consists of $\Omicron(lgk)$ parts, so calculating a value of `succ(x, k)` takes $\Omicron(lgk)$ time.


## Cycle Detection
> Consider a successor graph that only contains a path that ends in a cycle.
> A simple way to detect the cycle is to walk in the graph and keep track of all nodes that have been visited.
> Once a node is visited for the second time we can conclude that the node is the first node in the cycle. This method works in $\Omicron(n)$ time and also uses $\Omciron(n)$ memory.

> There are better algorithms for cycle detection.
> The time complexity of such algorithm is still $\Omicron(n)$, but they only use $\Omicron(1)$ memory.
> This is an important improvement if $n$ is large.

### Floyd's algorithm
> Floyd's algorithm walks forward in the graph using two pointers $a$ and $b$.
> Both pointers begin at node $x$ that is the starting node of the graph.
> Then on each turn, the pointer $a$ walks one step forward and the pointer $b$ walks to steps forward. The process continues until the pointer meet each other.

```cpp
a = succ(x);
b = succ(succ(x));
while (a != b) {
    a = succ(a);
    b = succ(succ(b));
}
```
> At this point, the pointer $a$ has walked $k$ steps and the pointer $b$ has walked $2k$ steps, so the length of the cycle divides $k$. Thus, the first node that belongs to the cycle can be found by moving the pointer $a$ to node $x$ and advancing the pointers step by step until they meet again.

```cpp
a = x;
while (a != b) {
    a = succ(a);
    b = succ(b);
}
first = a;
```

> After this, the length of the cycle can be calculated as follows

```cpp
b = succ(a);
length = 1;
while (a != b) {
    b = succ(b);
    length++;
}
```
