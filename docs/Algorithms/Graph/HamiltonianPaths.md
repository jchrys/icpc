# Hamiltonian Paths
> A Hamiltonian path is a path that visits each node of the graph exactly once.

> If a Hamiltonian path begins and ends at the same node, it is called Hamiltonian circuit.

## Existence
> No efficient method is known for testing if a graph contains Hamiltonian path, and the problem is *NP-hard*
> Still, in some special cases, we can be certain that a graph contains a Hamiltonian path.

> A simple observation is that if the graph is complete. It also contains a Hamiltonian path.

- Dirac's theorem: If a degree of each node is at least $n/2$, the graph contains a Hamiltonian path

- Ore's theorem: If the sum of degrees of each non-adjacent pair of nodes is at least $n$, the graph contains a Hamiltonian path.

> A common property in these theorems and other results is that they guarantee the existence of a Hamiltonian path if the graph has a large number of edges.


## Construction
> Since there is no efficient way to check if a Hamiltonian path exists, it is clear that there is also no method to efficiently construct the path, because otherwise we could just try to construct the path and see whether it exists.

> A simple way to search for a Hamiltonian path is use _backtracking algorithm_ that goes through all possible ways to construct the path. The time complexity of such an algorithm is at least $\Omicron(n!)$, because there are $n!$ different ways to choose the order of $n$ nodes.

> A more efficient solution is based on dynamic programming.
> The idea is to calculate values of a function `possible(S, x)`, where $S$ is a subset of nodes and $x$ is one of the nodes. 
> The function indicates whether there is a hamiltonian path that visits the nodes of $S$ and ends at node $x$.
> It is possible to implement this solution in $\Omicron(2^nn^2)$ time.

## Implementation


## Related subjects
Kinght's tours
