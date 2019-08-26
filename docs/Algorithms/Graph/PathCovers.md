# Path Covers
> A path cover is a set of paths in a graph such that each node of the graph belongs to at least one path.

> ==It turns out that in directed, acyclic graphs ($\text{DAGs}$), we can reduce the problem of finding a minimum path cover to the problem of finding a maximum flow in another graph.==

## Node-disjoint path cover
> In a node-disjoint path cover, each node belongs to exactly one path.

> It is possible that a path does not contains any edges. (can have single node)

> We can find a minimum node-disjoint path cover by constructing a [matching graph] ==where each node of the original graph is represented by two nodes==:

> A left node and a right node. 

> There is an edge from a left node to a right node if there is such an edge in the original graph.

> In addition, the matching graph contains a source and a sink, and there are edges from the source to all left nodes and from all right nodes to the sink.

> ==[A Maximum matching] in the resulting graph corresponds to a minimum node-disjoint path cover in the original graph.==


> Each edge in the maximum matching of the matching graph corresponds to an edge in the minimum node-disjoint path cover of the original graph.

> Thus, ==the size of the minimum node-disjoint cover is $n-c$==, where $n$ is the number of nodes in the original graph and $c$ is the size of the maximum matching.

## General path cover
> A general path cover is a path cover where a node can belong to more than one path.

> A minimum general path cover may be smaller than a minimum node-disjoint path cover, because a node can be used multiple times in paths.

> ==A minimum general path cover can be found almost like a minimum node disjoint path cover.==

> It suffices to add some new edges to the matching graph so that there is an edge $a \rarr b$ always when there is a path from $a$ to $b$ in the original graph(possibly through several edges).


### Dilworth's Theorem
> An antichain is a set of nodes of a graph such that there is no path from any node to another node using the edges of the graph.

> ==Dilworth's Theorem states that in a directed acyclic graph($\text{DAGs}$), the size of a minimum general path cover equals the size of maximum antichain.==
