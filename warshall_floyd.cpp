ll V;
vector<vector<ll>> dist;
void warshall_floyd()
{
    loop(k, V) loop(i, V) loop(j, V) if (dist[i][k] != 1e18 && dist[k][j] != 1e18) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
//Main関数
ll E;
cin >> V >> E;
dist.resize(V);
loop(i, V)
{
    loop(j, V)
    {
        if (i == j)
            dist[i].push_back(0);
        else
            dist[i].push_back(1e18);
    }
}
loop(i, E)
{
    ll s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d; //配列外参照に注意
}
warshall_floyd();
//dist[i][i]<0なら負閉路あり
//dist[i][j]==1e18ならi->jは非連結
