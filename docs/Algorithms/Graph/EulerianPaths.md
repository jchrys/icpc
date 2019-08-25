# Eulerian Path
> An Eulerian Path is a path that goes through each edge exactly one.

> It turns out that there is a simple rule that determines whether a graph contains an Eulerian path, and there is also an efficient algorithm to find a path if it exists.


## Existence
> The existence of Eulerian paths and circuits depends on the degrees of the nodes.

### In undireccted graph
> _an undirected graph_ has an Eulerian path exactly when "all the edges belong to the same connected component" and

- Case 1: the degree of each node is even
- Case 2: the degree of exactly two nodes is odd, and the degree of all other nodes is even

> In the Case 1, each Eulerian path is also Eulerian circuit.

> In the Case2, the odd-degree nodes are the starting and ending nodes of an eulerian path which is not an Eulerian circuit.

### Directed graph
> In a directed graph, we focus on indegrees and outdegrees of the nodes.

> A directed graph contains an Eulerian path exactly when "all the edges belong to the same connected component" and 

- Case 1: in each node, the indegree equals the outdegree
- Case 2: in one node, the indegree is one larger than the outdegree, in another node, the outdegree is one larger than the indegree, and in all other nodes, the indegree equals the out degree.

> In Case 1, each Eulerian path is also an Eulerian circuit.
> In case 2, the graph contains an Eulerian path that begins at the node whose out degree is larger and ends at the node whose indegree is larger.


## Hierholzer's Algorithm
> Hierholzer's algorithm is an efficient method for constructing an Eulerian circuit.
> The algorithm consists of several rounds, each of which adds new edges to the circuit.
> Of course, we assume that the graph contains an Eulerian circuit; otherwise Hierholzer's algorithm cannot find it

> First, the algorithm constructs a circuit that contains some of the edges of the graph.
> After this, the algorithm extends the circuit step by step by adding subcircuits to it.
> The process continues until all edges have been added to the circuit.

> The algorithm extends the circuit by always finding a node $x$ that belong to the circuit but has an outgoing edge that is not included in the circuit.
> The algorithm constructs a new path from node $x$ that only contains edges that are not yet in the circuit.
> Sooner or later, the path will return to node $x$, which creates a subcircuit

> If the graph only contains an Eulerian path, we can still use Hierholzer's algorithm to find it by adding an extra edge to the graph and removing the edge after the circuit has been constructed.

> For example, in an undirected graph, we add the extra edge between the two odd-degree nodes.

### Implementation
--- will be added---
