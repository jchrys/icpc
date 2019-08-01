#Starting time, finishing time
Starting time of a vertex is the time we enter it (the order we enter it) and its finishing time is the time we leave it. Calculating these are easy

```python
TIME = 0
dfs(v):
    st[v] = TIME++
    color[v] = gray
    for u in adj[v]:
        if color[u] == white:
            then dfs(u)
    color[v] = black
    ft[v] = TIME # or we can use TIME ++
```

It is useable in specially data structure problems (convert the tree into an array).

_Lemma_: if we run $dfs(root)$ in a rooted tree, then v is an ancestor of $u$ if and only if $st_v\leq st_u\leq ft_u\leq ft_v$.

So, given arrays $st$ and $ft$ we can rebuild the tree.
