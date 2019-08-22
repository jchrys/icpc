title: Basics of Tree Algorithms
hero: Basics of Tree Algorithms
description: Basics of Tree Algorithms
author: jchrys

# Tree
> A tree is a connected, acyclic [graph](/Algorithms/Graph/Basics/#graph) that consist of $n$ nodes and $n-1$ edges.

> Removing any edges from a tree divides it into two [components](/Algorithms/Graph/Basics/#1_connectivity), and adding any edge to a tree creates a [cycle](http://localhost:8000/Algorithms/Graph/Basics/#graph).

> Moreover, there is always a unique path between any two nodes of a tree.

## Leaves
> leaves of a tree are the nodes with degree 1, i.e., with only one neighbor

## Rooted tree
> In a rooted tree, one of the nodes is appointed the root of the tree, and all other nodes are placed underneath the root.

### Children & Parent of a node
> In a rooted tree, the children of a node are its lower negibors, and the parent of a node is its upper neighbor.


### Recursive structure
> The structure of rooted tree is recursive

> each node of the tree ats as the root of subtree that contains the node itself and all nodes that are in the subtrees of its children
