# Ford-Fulkerson algorithm
> The Ford-Fulkerson algorithm finds the maximum flow in a graph.

> The algorithm begins with an empty flow, and at each step finds a path from the source to the sink that generates more flow.

> Finally, when the algorithm cannot increase the flow anymore, the maximum flow has been found.


> ==The algorithm uses a special representation of the graph where each original edge has a reverse edge in another direction.==

> The weight of each edge indicates how much more flow we could route through it.

> At the beginning of the algorithm, the weight of each original edge equals the capacity of the edge and the weight of each reverse edge is zero.


## Algorithm description
> The Ford-Fulkerson algorithm consists of several rounds.

> On each round, the algorithm finds a path from the source to the sink such that each edge on the path has a positive weight.

> If there is more than one possible path available, we can choose any of them.

> After choosing the path, the flow increases by $x$ units, where $x$ is the smallest edge weight on the path.

> In addition, the weight of each edge on the path decreases by $x$ and the weight of each reverse edge increases by $x$.

> ==The idea is that increasing the flow decreases the amount of flow that can go through the edges in the future.==

> On the other hand, it is possible to cancel flow later using the reverse edges of the graph if it turns out that it would be beneficial to route the flow in another way.

> The algorithm increases the flow as long as there is a path from the source to the sink through positive-weight edges. 

> If It is not possible to increase the flow anymore, because there is no path from the source to the sink with positive edge weights, the algorithm terminates and has found the maximum flow.

## Implementation
```cpp

```



## Finding paths
> The Ford-Fulkerson algorithm does not specify how we should choose the paths that increase the flow.

> In any case, the algorithm will terminate sooner or later and correctly find the maximum flow. 

> ==However, the efficiency of the algorithm depends on the way the paths are chosen.==

## Path finding techniques
> In practive, ==the scaling algorithm is easier to implement==, because depth-first search can be used for finding paths.

> Both Algorithms are efficient enough for problems that typically appear in programming contests.
### Edmond-Karp algorithm
> ==The algorithm chooses each path so that the number of edges on the path is as small as possible.==

> This can be done by using $\text{breadth-first search}$ instead of depth-first search for finding paths.

> It can be proven that this guarantees that the flow increases quickly, and the ==time complexity of the algorithm is $\Omicron(m^2n)$.==

### Scaling algorithm
> ==The algorithm uses depth-first search to find paths where each weight is at least a threshold value.==

> Initially, the threshold value is some large number, for example the sum of all edge weights of the graph.

> Always when a path cannot be found, the threshold value is divided by 2.

> ==The time complexity of the algorithm is $\Omicron(m^2lgc)$==, where $c$ is the initial threshold value.

## Problems
1. [최대 유량](https://www.acmicpc.net/problem/6086):star::star::star:


## Related topics
- [Maximum flow](/Algorithms/Graph/MaximumFlow)

- [Minimum cut](/Algorithms/Graph/MinimumCut)


