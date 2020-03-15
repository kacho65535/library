/*
全頂点対最短距離を求める
※必ずwatshall_floyd_init(V, dist);を記述した後入力を受け取らないとバグります...
dist[i][i]<0なら負閉路あり
dist[i][j]==1e18ならi->jの経路を持たない
計算量O(V^3)
*/
void watshall_floyd_init(long long V, vector<vector<long long>> &dist)
{
    //初期化
    for (long long i = 0; i < V; i++)
    {
        for (long long j = 0; j < V; j++)
        {
            if (i == j)
                dist[i].push_back(0);
            else
                dist[i].push_back(1e18);
        }
    }
}
void warshall_floyd(long long V, vector<vector<long long>> &dist)
{
    for (long long k = 0; k < V; k++)
    {
        for (long long i = 0; i < V; i++)
        {
            for (long long j = 0; j < V; j++)
            {
                if (dist[i][k] != 1e18 && dist[k][j] != 1e18)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
//以下Main関数内における例
int main()
{
    long long V, E; //V:頂点数,E:辺数
    cin >> V >> E;
    vector<vector<long long>> dist(V);
    //以下必須!
    watshall_floyd_init(V, dist);
    //入力受け取り
    for (long long i = 0; i < E; i++)
    {
        long long s, t, d; //例)頂点sから頂点tへのコストdの有向辺を張る
        cin >> s >> t >> d;
        dist[s][t] = d; //配列外参照,無向,有向に注意
    }
    warshall_floyd(V, dist);
    return 0;
}
