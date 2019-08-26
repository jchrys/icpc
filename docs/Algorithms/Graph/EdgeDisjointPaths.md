# Edge-disjoint paths
> Problem of finding the maximum number of edge-disjoint paths from source to the sink.

> This means that we should construct a set of paths such that each edge appears in at most one path.

## Idea
> It turns out that the maximum number of of edge-disjoint paths equals the maximum flow of the graph, assuming that the capacity of each edge is one.

> After the maximum flow has been constructed, the edge-disjoint paths can be found greedily by following paths from the source to the sink
