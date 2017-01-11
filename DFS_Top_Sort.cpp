void dfs(int x) {
    vis[x] = true;
    for(int u = 0; u < n; u++) {
        if(!vis[u] && graph[x][u] == 1) {
            dfs(u);
        }
    }
    order.push_back(x);
}
