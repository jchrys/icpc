#DFS [:link:](https://codeforces.com/blog/entry/16221)
The most useful graph algorithms are search algorithms. DFS(Depth First Search) is one of them.

While running DFS, we assign colors to the vertices (initially white) Algorithm itself is really simple

```python
dfs(v):
    color [v] = gray
    for u in adj[v]:
        if color[u] == white:
            then dfs(u)
    color[v] = black
```

Black color here is not used, but you can use it sometimes.

Time complexity: $O(n + m)$
