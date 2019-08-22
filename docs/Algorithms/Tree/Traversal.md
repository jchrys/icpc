title: Tree Traversal
hero: Tree Traversal
description: Tree Traversal algorithms
author: jchrys

# Tree Traversal
> General [Graph Traversal](/Algorithms/Graph/GraphTraversal/) algorithms can be used to traverse the nodes of a tree.

> However, the traversal of a tree is easier to implement than that of a general graph, because there are no cycles in the tree and it is not possible to reach a node from multiple directions.

## implementation
> The typical way to traverse a tree is to start a depth-first search at an _arbitrary node_. The following recursive function can be used

> assumes that we are maintaining [adjacency list](/Algorithms/Graph/GraphTraversal/)
```cpp
void dfs(int s, int e) { // current node s and previous node e
    //process node s
    for (auto u : adj[s]) {
        if (u != e) dfs(u, s);
    }
}

dfs(x, x) // initial call because there's no self loop
```
