# Strong Connectivity(DAGs)
> A graph is *strongly connected* if there is a path from any node to all other nodes in the graph

> The *strongly connected components* of a graph divide the graph into strongly connected parts that are as large as possible.

> The strongly connected components form an acyclic *component graph* that represents deep structure of original graph.

> A *component graph* is a cyclic, directed graph, so it is easior to process than the original graph.
> Since the graph does not contain cycles, we can always construct a topological sort and use dynamic programming techniques.

## Kosaraju's algorithm
> *Kosaraju's algorithm* is an efficient method for finding the strongly connected components of a directed graph.

> The algorithm performs two depth-first search

> the first search constructs a list of nodes according to the structure of the graph
> the second search forms the strongly connected components.

### 1. Search 1
> The first phase of Kosaraju's algorithm constructs a list of nodes in the order in which a depth-first search processes them.
> The algorithm goes through the nodes, and begins a depth-first search at each unprocessed node.
> Each node will be added to the list after it has been processed.



### 2. Search 2
> The second phase of the algorithm forms the strongly connected components of the graph.
> First, the algorithm reverses every edge in the graph.
> This guarantees that during second search, we will always find strongly connected components that do not have extra nodes.

> After this, the algorithm goes through the list of nodes created by the first search, in _reverse_ order.
> if a node does not belong to a component, the algorithm creates a new component and starts a depth-first search that adds all new nodes found durin g the search to the new component

!!!note "leak"
    Note that since all edges are reversed, the component does not leak "leak" to other pars in the graph.



### Implementation
```cpp
vector<int> adj[V]; //adjancecy lists
vector<int> radj[V]; // reversed adjacency list (directions are opposite to original)
vector<int> order;
vector<vector<int>> result;
bool processed[V];


void search1(int u) {
    if (processed[u]) return;
    processed[u] = true;
    for (auto v: adj[u])
        search1(v);
    order.push_back(u);
}

void search2(int u) {
    if (processed[u]) return;
    processed[u] = true;
    for (auto v: radj[u])
        search2(v);
    result[result.size() -1].push_back(u); //add current node to the last component
}


int main() {
    for (int i = 0; i < V; i++) { // V = number of nodes
        if(!processed[i])
            search1(i);
    } 
    reverse(order.begin(), order.end()) // reverse the order that created by the first search
    
    for (int i = 0; i < V; i++) // initialized processed array
        processed[i] = false;
    for (auto u: order)
        if (!processed[u]) 
            result.push_back(vector<int>()); // add new component
            search2(i);
}
```

### Time complexity
> $\Omicron(n+m)$ because the algorithm performs two depth-first searches.


## 2SAT problem
> Strong connectivity is also linked with the *2SAT problem*.
> In this problem, we are given a logical formula
> for example

$$
L_1 = (x_2 \lor \neg x_1) \land (\neg x_1 \lor \neg x_2) \land (x_1 \lor x_3) \land (\neg x_2 \lor \neg x_3) \land (x_1 \lor x_4) 
$$

> is true when the variables are assigned as follows

$$
\begin{aligned}
x_1 & = false \\\\
x_2 & = false \\\\
x_3 & = true \\\\
x_4 & = true \\\\
\end{aligned}
$$


> The 2SAT problem can be represented as a graph whose nodes correspond to variable $x_i$ and negations $\neg x_i$, and edges determine the connections between the variables.

> Each pair $(a_i \lor b_i)$ generates two edges: $\neg a_i \rarr b_i$ and  $\neg b_i \rarr a_i$.
> This means that if $a_i$ does not hold, $b_i$ must hold, and vice versa.

> The structure of the graph tells us whether it is possible to assign the values of the variables so that the formula is true.

> It turns out that this can be done exactly when there are no nodes $x_i$ and $\neg x_i$ such that both nodes belong to the same strongly connected component.

> If there are such nodes, the graph contains a path from $x_i$ to $\neg x_i$ and also a path from $\neg x_i$ to $x_i$, so both $x_i$ and $\neg x_i$ should be true which is not possible.

> In the graph of the formula $L_1$ there are no nodes $x_i$ and $\neg x_i$ such that both nodes belong to the same strongly connected component, so solution exists.

> If a solution exists, the values for the variables can be found by going through the nodes of the component graph in a reverse topological sort order.

> at each step, we process a component that does not contain edges that lead to an unprocessed component.
> If the variables in the component have not been assigned values, their values will be determined accoring to the values in the component, and if they already have values, they remain unchanged.
> The process continues until each variable has been assigned a value.


!!! note "this method works"
    because the graph has a special structure:
    if there are paths from node $x_i$ to node $x_j$ and from node $x_j$ to
    node $\neg x_j$, then node $x_i$ never becomes true. The reason for this is that there is also a path from node $\neg x_j$ to node $\neg x_j$, and both $x_i$ and $x_j$ become false.


!!! info 3SAT problem
    A more difficult problem is *3SAT problem*, where each part of the formula is form $(a_i \lor b_i \lor c_i)$. This problem is NP-hard, so no efficient algorithm for solving the problem is known. 


### Implementation
```cpp
int const MAXN; // maximum number of variables
int N; // number of variables
int M; // number of conditions
vector<vector<int>> adj; // adjancecy list
vector<vector<int>> radj; //inver adjancency list
vector<bool> processed(2*MAXN);
vector<bool> rprocessed(2*MAXN);
vector<int> sccnum(2*MAXN, -1); // initialize -1
vector<vector<int>> scc;
vector<int> order; // maintain order created by search 1
vector<int> answer(2*MAXN);

void search1(int u) {
    if (processed[u]) return;
    processed[u] = true;
    for (auto v: adj[u])
        search1(v);
    order.push_back(u);
}

void search2(int u) {
    if (rprocessed[u]) return;
    rprocessed[u] = true;
    for (auto v: radj[u])
        search2(v);
    scc[scc.size()-1].push_back(u); 
    sccnum[u] = scc.size()-1; // write which SCC node 'u' is in
}

int neg(int i) { // negate of i
    return (i + N) % (2*N);
}

int main() {
    for (int i = 0; i < 2*N; i++) { // to 2 * N because we have to consider neg.
        if(!processed[i])
            search1(i);
    } 
    
    reverse(order.begin(), order.end());
    for (auto u : order) {
        if (!rprocessed[u]) {
            scc.push_back(vector<int>());
            search2(u);
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (sccnum[i] == sccnum[neg(i)]) {
            cout << "WE FOUND CONTRADICTION!!!";
            return 0;
        } 
    }
    
    reverse(scc.begin(), scc.end()); // reverse order of topological order of SCC
    for (auto component: scc) {
        for (auto x: component) {
            if (answer[x] == -1) { // if not assigned yet
                answer[x] = true;
                answer[neg(x)] = false;
            }
        }
    }
    for (int i = N; i < 2 * N; i++) {
        cout << i << ": " << answer[i] << endl;
    }
}
```

### Related Problems
1. [2-SAT 1](https://www.acmicpc.net/problem/11277) :star::star:
2. [2-SAT 2](https://www.acmicpc.net/problem/11278) :star::star:
3. [2-SAT 3](https://www.acmicpc.net/problem/11280) :star::star:
4. [2-SAT 4](https://www.acmicpc.net/problem/11281) :star::star::star:
