# Maximum matchings
> The maximum matching problem asks to find a maximum-size of set of node pairs in an undirected graph such that each pair is connected with an edge and each node belongs to at most one pair.

> There are polynomial algorithms for finding maximum matchings in general graphs, but such algorithms are complex and rarely seen in programming contest

> However, ==in bipartite graphs==, the maximum matching problem is much easier to solve, because ==we can reduce it to the maximum flow problem==.

## Finding maximum matchings
> The node of a bipartite graph can be always divided into two groups such that all edges of the graph go from the left group to the right group

> ==We can reduce the bipartite maximum matching problem to the maximum flow problem by adding two new nodes to the graph: a source and a sink.==

> We also add edges from the source to each left node and from each right node to the sink

> After this, ==the size of a maximum flow in the graph equals the size of a maximum matching in the original graph.==

### Implementation
```cpp
// A C++ program to find maximal 
// Bipartite matching. 
#include <iostream> 
#include <string.h> 
using namespace std; 
  
// M is number of applicants  
// and N is number of jobs 
#define M 6 
#define N 6 
  
// A DFS based recursive function  
// that returns true if a matching 
// for vertex u is possible 
bool bpm(bool bpGraph[M][N], int u, 
         bool seen[], int matchR[]) 
{ 
    // Try every job one by one 
    for (int v = 0; v < N; v++) 
    { 
        // If applicant u is interested in  
        // job v and v is not visited 
        if (bpGraph[u][v] && !seen[v]) 
        { 
            // Mark v as visited 
            seen[v] = true;  
  
            // If job 'v' is not assigned to an  
            // applicant OR previously assigned  
            // applicant for job v (which is matchR[v])  
            // has an alternate job available.  
            // Since v is marked as visited in  
            // the above line, matchR[v] in the following  
            // recursive call will not get job 'v' again 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// Returns maximum number 
// of matching from M to N 
int maxBPM(bool bpGraph[M][N]) 
{ 
    // An array to keep track of the  
    // applicants assigned to jobs.  
    // The value of matchR[i] is the  
    // applicant number assigned to job i, 
    // the value -1 indicates nobody is 
    // assigned. 
    int matchR[N]; 
  
    // Initially all jobs are available 
    memset(matchR, -1, sizeof(matchR)); 
  
    // Count of jobs assigned to applicants 
    int result = 0;  
    for (int u = 0; u < M; u++) 
    { 
        // Mark all jobs as not seen  
        // for next applicant. 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
  
        // Find if the applicant 'u' can get a job 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
} 
  
// Driver Code 
int main() 
{ 
    // Let us create a bpGraph  
    // shown in the above example 
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0}, 
                          {1, 0, 0, 1, 0, 0}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 0, 1, 1, 0, 0}, 
                          {0, 0, 0, 0, 0, 0}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph); 
  
    return 0; 
} 
```

## Hall's theorem
> Hall's theorem can be used to find out whether a bipartite graph has a matching that contains all left or right nodes.

> If the number of left and right nodes is the same, Hall's theorem tells us if it is possible to construct a ==perfect matching== that contains all nodes of the graph.

> Assume that we want to find a matching that contains all left nodes.

> Let $X$ be any set of left nodes and let $f(X)$ be the set of their neighbors.

> ==According to Hall's Theorem, a matching that contains all left nodes exists exactly when for _each_ $X$, the condition $|X| \leq |f(X)|$ holds.==

> If the condition of Hall's theorem does not hold, the set $X$ provides an explanation why we cannot form such a matching.

> Since $X$ contains more nodes than $f(X)$, there are no pairs for all nodes in $X$.

## Problems
1. [축사 배정](https://www.acmicpc.net/problem/2188) :star::star:
