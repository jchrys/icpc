 File              : TreeQueries.md
 Author            : JCHRYS <jchrys@me.com>
 Date              : 15.01.2020
 Last Modified Date: 15.01.2020
 Last Modified By  : JCHRYS <jchrys@me.com>
# Tree Queries
- What is the $k$th ancester of a node?
- What is the sum of values in the subtree of a node?
- what is the sum of values on a path between two nodes?
- what is the lowest common ancester of two nodes?

## Finding ancestors
> The $k$th ancestor of a node $x$ in a rooted tree is the node that we will reach if we move $k$ levels up from $x$.
> Let `ancestor(x, k)` denote the $k$th ancestor of node $x$.

> an easy way to calculate any value of `ancestor(x, k)` is to perform a sequence of $k$ moves in the tree.
> However, the time complexity of the method is $\Omicron(k)$, which may be slow, because tree of $n$ nodes may have chain of $n$ nodes.

> Fortunately, using a technique similar to that used in [here](/Algorithms/Graph/DirectedGraphs/#successor_paths), any value of `ancestor(x, k)` can be efficiently calculated in $\Omicron(lgk)$ time after pre processing.
> The idea is to precalculate all values `ancestor(x, k)` where $k\leq n$ is a power of two.

> The preprocessing takes $\Omicron(nlgn)$ time, because $\Omicron(lgn)$ values are calculated for each node.

> After this, any value of `ancestor(x, k)` can be calculated in $\Omicron(lgk)$ time by representing $k$ as a sum where each term is a power of two.

### Implementation

``` cpp
not yet added
```

## Subtree and paths
> A tree traveral array contains the nodes of a rooted tree in the order in which a depth-first search from the root node visit them. 

!!! warning "example will be added"
    we're working on it


## Subtree queries
> Each subtree of a tree corresponds to a subarray of the tree traversal array such that the first element of the subarray is the root node.

> Using this fact, we can efficiently process queries that are related to subtree of a tree.

> for example: update the value of a node, calculate the sum of values in the subtree of a node.

> The idea is to construct a tree traversal array that contains three values for each node: the identifier of the node, the size of the subtree, and the value of the node.

> Using this array we can calculate the sum of the values in any subtree by first finding out the size of the subtree and then the values of the corresponding nodes.

> To answer the queries efficiently, it suffices to store the values of the nodes in a *binary indexed or segment tree*.<< link will be added.

> After this, we can both update a value and calculate the sum of values in $\Omicron(lgn)$ time.

### Implementation

```cpp
not yet added
```

## path queries
> Using a tree traversal array, we can also efficiently calculate sums of values on paths from the root node to any node of the tree.

> Consider a problem where our task is to support the following queries:

- change the value of a node

- calculate the sum of values on a path from the root to node

> We can solve this problem like before, but now each value in the last row of the array is the sum of values on a path from the root to the node.

> When the value of a node increase by $x$, the sums of all nodes in its subtree increase by $x$.

> Thus, to support both the operation, we should be able to increase all values in a range and retrieve a single value. 
> This can be done in $\Omicron(lgn)$  using a binary indexed or segment tree.

### Implementation
```cpp
not yet added
```

## Lowest Common Ancestor
> The lowest common ancestor of two nodes of a rooted tree is lowest node whose subtree contains both the nodes.
> A typical problem is to efficiently process queries that ask to find the lowest common ancestor of two nodes.

### Problems
1. [LCA](https://www.acmicpc.net/problem/11437) :star::star:
2. [LCA 2](https://www.acmicpc.net/problem/11438):star::star::star:
3. [LCA와 쿼리](https://www.acmicpc.net/problem/15480):star::star::star:


### Method 1
> One way to solve the problem is to use the fact that we can efficiently find the $k$th ancestor of any node in the tree.
> Using this, we can divide the problem of finding the lowest common ancestor into two parts.

> We use two pointers that initially point to the two nodes whose lowest common ancestor we should find.
> First, we move one of the pointers upwards so that both pointers point to nodes at the same level.
> After this, we determine the minimum number of steps needed to move both pointers upwards so that they will point to the same node. The node to which the pointers point after this is the lowest common ancestor.

> Since both parts of the algorithm can be performed in $\Omicron(lgn)$ time using precomputed information, we can find the lowest common ancestor of any two nodes in $\Omicron(lgn)$ time.

#### Implementation
```cpp

/*
    n: number of nodes
    preprocess: O(nlgn)
    query: O(lgn)
*/

int log(int x) {
    return sizeof(int) * 8 - __builtin_clz(x);
}

int const MAXN = 2e5;
int MAXLOG = log(MAXN);
vector<vector<int>> par(MAXN, vector<int>(MAXN, -1)) // initially all -1 which represents that the node has no parent
vector<int> depth(MAXN, 0);


void dfs(int u, int p = -1) {
    /*
     preprocessing
     make sparse table
    */

    if (p != -1)
        depth[u] = depth[p] + 1;

    par[u][0] = p;

    for (int i = 0; i < MAXLOG - 1; i++)
        if (par[u][i] != -1)
            par[u][i + 1] = par[par[u][i]][i];

    for (auto v : adj[u])
        if(u != p)
            dfs(v, u);
}

int query(int u, int v) {
    /*
    query implementation
    */

    // make depth[u] is always larger than or equal to depth[u];
    if (depth[u] < depth[v])
       swap(u, v)

    // make depth[v] == depth[u]
    for (int i = MAXLOG - 1; i >= 0; --i)
        if (par[u][i] != -1 && depth[par[u][i]] >= h[v])
            u = par[u][i];

    // if one of given node is parent of the other or given the same nodes u, v;
    // return one of them.
    if (u == v)
        return u;

    // make par[u][0] and par[v][0] target the same node
    for (int i = MAXLOG - 1; i >= 0; --i)
        if (par[u][i] != par[v][i])
            v = par[v][i], u = par[u][i];
    
    // return parent node which is common ancester of givens.
    return par[u][0];
}

```

### Method 2
> Another way to solve the problem is based on a tree traversal array[^1]. 
> Once again, the idea is to traverse the nodes using depth-first search.
> However, we use a different tree traversal array: We add each node to th e array always the depth-first search walks through the node, and not only at the first visit.
> Hence, a node that has $k$ children appears $k+1$ times in the array and there are a total $2n-1$ nodes in the array.

> We store two values in the array: the identifier of the node and the depth of the node in the tree.

> Now we can find the lowest common ancestor of nodes $a$ and $b$ by finding the node with $\text{minimum}$ depth between nodes $a$ and $b$ in the array

> Thus to find the lowest common ancestor of two nodes it suffices to process [range minimum query].
> Since the array is static, we can process such queries in $\Omicron(1)$ time after an $\Omicron(nlgn)$ time preprocessing.

### Implementation
```cpp
will be added after RMQ is added
https://codeforces.com/blog/entry/16221
```




### Distance of nodes
> The distance between nodes $a$ and $b$ equals the length of the path from $a$ to $b$. 
> It turns out that the problem of calculating the distance between nodes reduces to finding their lowest common ancestor.

> First, we root the tree arbitrarily.
> After this, the distance of nodes $a$ and $b$ can be calculated using the formula

$$
depth(a) + depth(b) - 2 \sdot depth(c)
$$

> where $c$ is the lowest common ancestor of $a$ and $b$ and $depth(s)$ denotes the depth of node $s$

## Offline algorithms
> Offline algorithms.  those algorithms are given a set of queries which can be answered in any order.

> It is often easier to design an offline algorithm compared to an online algorithm

### Merging data structures
> One method to construct an offline algorithm is to perform depth-first tree traversal and maintain data structures in nodes.

> At each node $s$, we create a data structure `d[s]` that is based on the data structures of the children of $s$.
> Then using this data structure, all queries related to $s$ are processed.

> As an example, consider the following problem: We are given a tree where each node has some value.

> Our task is to process queries of the form "calculate the number of nodes with value $x$ in the subtree of node $s$".

> In this problem, we can use map structures to answer the queries.

> If we create such a data structure for each node, we can easily process all given queries, because we can handle all queries related to a node immediately after creating its data structure.

> However it would be too slow to create all data structure from scratch.

> Instead, at each node $s$, we create an initial data structure `d[s]` that only contains the values of $s$.

> After this, we go through the children of $s$ and `merge d[s]` and all data structures `d[u]` where $u$ is a child of $s$.


> The merging at node $s$ can be done as follows

> We go through the children of $s$ and at each child $u$ merge `d[s]` and `d[u]`. 

> We always copy the contents from `d[u]` to `d[s]`.
> However, before this, we `swap` the contents of `d[s]` and `d[u]` if `d[s]` is smaller than `d[u]`.
> By doing this, each value is copied only $\Omicron(lgn)$ times during the tree traversal, which ensures that the algorithm is efficient.

> To swap the contents of two data structres $a$ and $b$ efficiently, we can just use following code:

```cpp
swap(a, b);
```

>  It is guaranteed that the above code works in constant time when $a$ and $b$ are C++ standard library data structures.


### Lowest common ancestors
> There is also an offline algorithm for processing a set of lowest common ancestor queries.

> The algorithm is based on the [union-find data structure](), and the benefit of the algorithm is that it is easier to implement than the algorithm we discussed earlier.

> The algorithm is given as input a set of pairs of nodes, and it determines for each such pair the lowest common ancestor of the nodes.

> The algorithm performs a depth-first tree traversal and maintains disjoint sets of nodes.

> Initially, each node belongs to a separate set.
> For each set, we also store the highest node in the tree that belongs to the set.

> When the algorithm visits a node $x$, it goes through all nodes $y$ such that the lowest common ancestor of $x$ and $y$ has to be found.
> If $y$ has already been visited, the algorithm reports that the lowest common ancestor of $x$ and $y$ is the highest node in the set of $y$.

> Then, after processing node $x$, the algorithm joins the sets of $x$ and its parent.




[^1]: This technique is sometimes called the Euler tour technique.
