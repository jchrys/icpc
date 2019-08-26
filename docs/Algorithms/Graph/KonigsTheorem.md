# Konig's theorem
## Minimum node cover
> _A minimum node cover_ of a graph is a minimum set of nodes such that each edge of the graph has at least one end point in the set.

> In general graph, finding a minimum node cover is a *NP-hard* problem.

> However, ==if the graph is bipartite, Konig's theorem tells us that the size of minimum node cover and the size of a maximum matching are always equal.==

> Thus, we can calculate the size of a minimum node cover using a maximum flow algorithm.


## Maximum independent set
> The nodes that do _not_ belong to a minimum node cover form a maximum independent set[^1].

> Finding a maximum independent set in a general graph is _NP-hard_ problem, but in a bipartite graph we can use Konig's theorem to solve the problem efficiently.

[^1]: The largest possible set of nodes such that no two nodes in the set are connected with an edge.
