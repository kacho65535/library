struct edge
{
    ll to;
    ll cost;
};
typedef pair<ll, ll> P; //P.first:最短距離,P.second:頂点の番号
//頂点V個の負閉路なし重み付きグラフGにおける始点sからの最短距離を求める
ll V;
vector<vector<edge>> G;
void dijkstra(vec &dist, ll s)
{
    //greater<P>によってfirstが小さい順に取り出される
    priority_queue<P, vector<P>, greater<P>> que;
    loop(i, V) dist[i] = 1e18;
    dist[s] = 0;
    que.push(P(0, s));
    //queが空になるまで繰り返す
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (dist[v] < p.first)
            continue; //すでに最短距離ならスルー
        loop(i, G[v].size())
        {
            edge e = G[v][i];
            //更新作業
            if (dist[e.to] > dist[v] + e.cost)
            {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}
