title: Basics of Grpahs
hero: Basics of Graphs
description: Graphs
author: jchrys


# Graph
> A graph is consists of nodes and edges

## Terminologies

### 1. Connectivity
> A graph is connected if there is a path between any two nodes.    

- Components: Connected parts of its grpah.
- Tree: a tree is a connected graph that consists of $n$ nodes and $n-1$ edges.

### 2. Edge directions
> A graph is directed if the edges can be traversed in one direction only

### 3. Edge weights
> In a weighted graph, each edge is assigned a weight. often interpreted as edge length

### 4. Neighbors and degrees
> Two nodes are $neighbors$ or $adjacent$ if there is an edge between them

- Degree: The degrege of a node is number of its neighbors
    - Indegree: The indegree of a node is the number of edges that end at the node
    - Outdegree: The outdegree of a node is the number of edges that start at the node
- Regular graph: A graph is regular if the degree of every node is a constant d
- Complete graph: A graph is complete if the degree of every node is $n-1$

### Colorings
> In a coloring of a graph, each node is assigned a color so that no adjacent nodes have the same color

- Bipartite: A graph is bipartite if it is possible to color it using two colors
!!!note
    It turns out that a graph is bipartite exactly when it does not contain a cycle with an odd number of edges

### Simplicity
> A graph is simple if no edge starts and ends at the same node(loop), and there are no multiple edges between two nodes.

![loop&multiple edges](https://user-images.githubusercontent.com/45776091/63223944-0b786300-c1f8-11e9-94c2-3dbd0389202b.jpeg)


## Graph representation
> There are several ways to represent graphs in algorithms.
> The choice of a data structure depends on the size of graph and the way the algorithm processes it

### 1. Adjacency list representation
> In the adjacency list representation, each node x in the graph is assigned an *adjacency list* that consists of nodes to which there is an edge from x
- we can efficiently find the nodes to which we can move from a given node through an edge

### 2. Adjacency matrix representation
> An adjacency matrix is two dimensional array that indicates which edges the graph contains.

- we can efficiently check from an adjacency matrix if there is an edge between two nodes.

### 3. Edge list representation
> An edge list contains all edges of a graph in some order.

- This is convenient way to represent a graph if the algorithm proesses all edges of the graph and it is not needed to find edges that start at a given node.

