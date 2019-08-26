# Minimum cut
> In the minimum cut problem, our task is to remove a set of edges from the graph such that there will be no path from the source to the sink after the removal and the total weight of the removed edges is minimum.

> It turns out that a maximum flow and a minimum cut are always equally large, so the concepts are two sides of the same coin.

## [Ford-Fulkerson algorithm](/Algorithms/Graph/FordFulkerson)
> It turns out that Ford-Fulkerson algorithm has found a maximum flow, it has also determined a minimum cut.

> Let $A$ be the set of nodes that can be reached from the source using positive-weight edges.

> Now the minimum cut consists of the edges of the original graph that start at some node in $A$, end at some node outside $A$, and ==whose capacity is fully used in the  maximum flow.==

### Why this works?
> Why is the flow produced by the algorithm maximum and why is the cut minimum?

> The Reason is that a graph cannot contain a flow whose size is larger than the weight of any cut of the graph. 

> Hence, ==always when a flow and a cut are equally large, they are a maximum flow and a minimum cut.==


## Related topics
- [Maximum flow](/Algorithms/Graph/MaximumFlow)

- [Ford-Fulkerson algorithm](/Algorithms/Graph/FordFulkerson)
