//TIMESTAMPbfs
vector<bool> seen;
vec first;
vec last;
void dfs(const Graph &G, ll v, ll &time)
{
    if (!(seen[v]))
    {
        seen[v] = true;
        first[v] = time++;
        for (auto next_v : G[v])
        {
            if (seen[next_v])
                continue;
            dfs(G, next_v, time);
        }
        last[v] = time++;
    }
}
//main関数内で
seen.assign(n, false); // 全頂点を「未訪問」に初期化
first.resize(n);
last.resize(n);
///////////////////////////////////////////////////////////////////////////
field.assign(h, vector<ll>(w, 0));
vector<vector<ll>> field;
void dfs(ll x, ll y, ll h, ll w)
{
    field[x][y] = 0;
    loop(i, 8)
    {
        ll next_x = x + dx[i], next_y = y + dy[i];
        if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w)
            continue;
        if (field[next_x][next_y] == 0)
            continue;
        dfs(next_x, next_y, h, w);
    }
}
///////////////////////////////////////////////////////////////////////////
Graph g;
//始点sからS回以内の移動でたどりつける町を探索
void bfs(vec &dist, ll S, ll s)
{
    queue<ll> que;
    dist[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        ll v = que.front();
        que.pop();
        if (dist[v] == S)
            continue;
        for (auto next_v : g[v])
        {
            if (dist[next_v] != -1)
                continue;
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}
