#DFS tree
DFS Tree is a rooted tree that is built like this

```python
let T be a new tree
dfs(v):
    color[v] = gray
    for u in adj[v]:
        if color[u] == white:
            then dfs(u) and par[u] = v (in T)
    color[v] = black
```

_Lemma_: There is no cross edges, it means if there is an edge between $V$ and $u$, then $v=par[u]$ or $u=par[v]$
