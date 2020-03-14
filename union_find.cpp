/*
union_find木で出来ること
1.要素xと要素yが同じグループに属するか判定
2.要素xが属する木と要素yが属するグループの併合
※グループの分割が出来ないことに注意！
計算量O(α(N))
*/
struct union_find
{
    vec par; //par[i]:iの親の番号　
    vec rank;
    //初期化子リストを用いた初期化
    union_find(ll N) : par(N), rank(N)
    {
        loop(i, N)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }
    //要素xが所属する木の根を再帰的に発見する
    ll root(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]); //経路圧縮
    }
    //要素xが属する木と要素yが属する木の併合
    void unite(ll x, ll y)
    {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry)
            return; //同じ木に属してたらそのまま
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry; //根がryの木に併合
        }
        else
        {
            par[ry] = rx; //根がrxの木に併合
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    //要素xが属する木と要素yが属する木が同じならtrueを返す
    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }
};
