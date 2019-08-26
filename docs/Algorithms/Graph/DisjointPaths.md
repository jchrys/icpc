# Disjoint paths
> our task is to find the maximum number of disjoint paths from the source to the sink

## Edge-disjoint paths
> We will first focus on the problem of finding the maximum number of edge-disjoint paths from the source to the sink.

> This means that ==we should construct a set of paths such that each edge appears in at most one path.==

> It turns out that the maximum number of edge-disjoint paths equals the maximum flow of the graph, assuming that the capacity of each edge is one.

> After the maximum flow has been constructed, the edge-disjoint paths can be found greedily by following paths from the source to sink.



## Node-disjoint paths
> Let us now consider another problem: finding the maximum number of node-disjoint paths from the source to the sink.

> In this problem, ==every node, except for the source and sink, may appear in at most one path.==

> The number of node disjoint paths may be smaller than the number of edge-disjoint paths.

> ==We can reduce also this problem to the maximum flow problem.==

> Since each node can appear in at most one path, we have to limit the flow that goes through the nodes.

> A standard method for this is to divide each node into two nodes such that the first node has the incoming edges of the original node, the second node has the outgoing edges of the original node, and there is a new edge from the first node to second node.
