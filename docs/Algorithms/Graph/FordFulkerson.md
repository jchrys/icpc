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

### Dinic Algorithm
> Time complex $\Omicron(EV^2)$

> Like Edmond-Karp algorithm, Dinic's algorithm uses following concepts

1. A flow is maximum if there is no $source$ to $sink$ path in residual graph.

2. $\text{BFS}$ is used in a loop. There is difference though in the way we use BFS in both algorithms.

> In Edmond's Karp algorithm, we use $\text{BFS}$ to find a augmenting path and send flow accress this path.

> In Dinic's algorithm we use $\text{BFS}$ to check if more flow is possible and to construct level graph. 

> In, level graph, we assign levels to all nodes, level of a node is shortest distance (in terms of number of edges) of the node from source. 

> Once level graph is constructed, we send multiple flows using this level graph.

> This is the reason it works better than Edmond-Karp.

> In Edmond-Karp, we send only flow that is send across the path found by BFS.

## Implementation (Dinic with Scaling)
```cpp
/********************************************************************************
    MaxFlow Dinic algorithm with scaling. 
    O(N * M * log(MC)), where MC is maximum edge capacity.
    
    Based on problem 2784 from informatics.mccme.ru 
    http://informatics.mccme.ru/mod/statements/view3.php?chapterid=2784#1
********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, f, c;
};

const int inf = 1000 * 1000 * 1000;
const int MAXN = 1050;

int n, m;
vector <edge> e;
int pt[MAXN]; // very important performance trick
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;
int d[MAXN];
int lim;
int s, t;

void add_edge(int a, int b, int c) {                                                                           
    edge ed;

    //keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge 

    ed.a = a; ed.b = b; ed.f = 0; ed.c = c;
    g[a].push_back(e.size());
    e.push_back(ed);

    ed.a = b; ed.b = a; ed.f = c; ed.c = c;
    g[b].push_back(e.size());
    e.push_back(ed);
}

bool bfs() {
    for (int i = s; i <= t; i++)
        d[i] = inf;
    d[s] = 0; 
    q.push(s);
    while (!q.empty() && d[t] == inf) {
        int cur = q.front(); q.pop();
        for (size_t i = 0; i < g[cur].size(); i++) {
            int id = g[cur][i];
            int to = e[id].b;

            //printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);

            if (d[to] == inf && e[id].c - e[id].f >= lim) {
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }
    while (!q.empty()) 
        q.pop();
    return d[t] != inf;
}

bool dfs(int v, int flow) {
    if (flow == 0) 
        return false;
    if (v == t) {
        //cout << v << endl;
        return true;
    }
    for (; pt[v] < g[v].size(); pt[v]++) {
        int id = g[v][pt[v]];
        int to = e[id].b;

        //printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

        if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
            int pushed = dfs(to, flow); 
            if (pushed) {
                e[id].f += flow;
                e[id ^ 1].f -= flow;
                return true;
            }               
        }
    }
    return false;
}

void dinic() {
    for (lim = (1 << 30); lim >= 1;) {
        if (!bfs()) {
            lim >>= 1;
            continue;
        }

        for (int i = s; i <= t; i++) 
            pt[i] = 0;

        int pushed;

        while (pushed = dfs(s, lim)) { 
            flow = flow + lim;
        }

        //cout << flow << endl;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d", &n, &m);
    
    s = 1; t = n;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
    }

    dinic();

    cout << flow << endl;

    return 0;
}

```

## Problems
1. [최대 유량](https://www.acmicpc.net/problem/6086):star::star::star:


## Related topics
- [Maximum flow](/Algorithms/Graph/MaximumFlow)
- [Minimum cut](/Algorithms/Graph/MinimumCut)


