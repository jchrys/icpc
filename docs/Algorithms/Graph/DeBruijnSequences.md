# De Bruijn sequences
> A De Bruijn sequence is a string that contains every string of length $n$ exactly once as a substring, for fixed alphabet of $k$  characters.

> The length of such a string is $k^n + n - 1$ characters.

> It turns out that each De Bruijn sequence corresponds to an Eulerian path in a graph.
> The idea is to construct a graph where each node contains a string of $n-1$ characters and each edge adds one character to the string.

> An Eulerian path in this graph corresponds to a string that contains all strings of length $n$.
> The string contains the characters of the starting node and all characters of the edges.
> The starting node has $n-1$ characters and there are $k^n$ characters in the edges, so the length of the string is $k^n + n - 1$.
