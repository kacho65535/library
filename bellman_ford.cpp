//頂点fromから頂点toへと結ぶコストcostの有向辺
struct edge
{
  ll from;
  ll cost;
  ll to;
};
ll V, E;
vector<edge> side;
vec dist;
vector<bool> find_negative_loop;
/*
始点vから各頂点への最短距離を求め(経路が存在しなければ1e18)、
また各頂点につくまでに負閉路が存在するかどうかも調べる
*/
void bellman_ford(ll v)
{
  loop(i, V) dist[i] = 1e18;
  dist[v] = 0;
  ll count = 0;
  while ("neko")
  {
    count++;
    bool update = false;
    //通常の最短経路探索
    if (count <= V - 1)
    {
      loop(i, E)
      {
        edge e = side[i];
        /*
      現在いる頂点の最短距離がinfでなく、
      かつ行先の最短距離が(現在いる頂点の最短距離+有向辺のコスト)よりも大きいとき更新
      */
        if (dist[e.from] != 1e18 && dist[e.to] > dist[e.from] + e.cost)
        {
          dist[e.to] = dist[e.from] + e.cost;
          update = true; //探索継続
        }
      }
    }
    //各頂点までに負閉路が存在するかチェック
    if (count >= V)
    {
      loop(i, E)
      {
        edge e = side[i];
        /*
      現在いる頂点の最短距離がinfでなく、
      かつ行先の最短距離が(現在いる頂点の最短距離+有向辺のコスト)よりも大きいとき更新
      +負閉路発見
      */
        if (dist[e.from] != 1e18 && dist[e.to] > dist[e.from] + e.cost)
        {
          dist[e.to] = dist[e.from] + e.cost;
          find_negative_loop[e.to] = true;
          update = true; //探索継続
        }
        //前(from)がtrueなら次(to)もtrue
        if (find_negative_loop[e.from])
          find_negative_loop[e.to] = true;
      }
    }
    if ((!update) || count == 2 * V - 1)
      break; //更新がなくなるか2*V-1回のwhileループが終了すれば終了
  }
}

//main関数
side.resize(E);
dist.resize(V);
find_negative_loop.assign(V, false);
