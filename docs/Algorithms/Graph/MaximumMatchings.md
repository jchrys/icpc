# Maximum matchings
> The maximum matching problem asks to find a maximum-size of set of node pairs in an undirected graph such that each pair is connected with an edge and each node belongs to at most one pair.

> There are polynomial algorithms for finding maximum matchings in general graphs, but such algorithms are complex and rarely seen in programming contest

> However, ==in bipartite graphs==, the maximum matching problem is much easier to solve, because ==we can reduce it to the maximum flow problem==.

## Finding maximum matchings
> The node of a bipartite graph can be always divided into two groups such that all edges of the graph go from the left group to the right group

> ==We can reduce the bipartite maximum matching problem to the maximum flow problem by adding two new nodes to the graph: a source and a sink.==

> We also add edges from the source to each left node and from each right node to the sink

> After this, ==the size of a maximum flow in the graph equals the size of a maximum matching in the original graph.==


## Hall's theorem
> Hall's theorem can be used to find out whether a bipartite graph has a matching that contains all left or right nodes.

> If the number of left and right nodes is the same, Hall's theorem tells us if it is possible to construct a ==perfect matching== that contains all nodes of the graph.

> Assume that we want to find a matching that contains all left nodes.

> Let $X$ be any set of left nodes and let $f(X)$ be the set of their neighbors.

> ==According to Hall's Theorem, a matching that contains all left nodes exists exactly when for _each_ $X$, the condition $|X| \leq |f(X)|$ holds.==

> If the condition of Hall's theorem does not hold, the set $X$ provides an explanation why we cannot form such a matching.

> Since $X$ contains more nodes than $f(X)$, there are no pairs for all nodes in $X$.
