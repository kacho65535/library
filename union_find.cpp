/*
このunion_find木で出来ること
例)union_find tree(N);などで宣言(N:頂点数)
tree.same(x,y):要素xと要素yが同じグループに属するか判定
tree.unite(x,y):要素xが属する木と要素yが属するグループの併合
tree.size(x,y):要素xが属する木の頂点数を返す
※グループの分割が出来ないことに注意！
計算量O(α(N))(ほぼO(1))
*/
struct union_find
{
    vector<long long> par;  //親の番号　
    vector<long long> rank; //木の深さ(根のランクは0)
    vector<long long> siz;  //要素xが根なら木の頂点数を格納する
    //初期化子リストを用いた初期化
    union_find(long long N) : par(N), rank(N), siz(N)
    {
        for (long long i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    //要素xが所属する木の根を再帰的に発見する
    long long root(long long x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]); //経路圧縮
    }
    //要素xが属する木と要素yが属する木の併合
    void unite(long long x, long long y)
    {
        long long rx = root(x);
        long long ry = root(y);
        if (rx == ry)
            return; //同じ木に属してたらそのまま
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry; //根がryの木に併合
            siz[ry] = siz[rx] + siz[ry];
        }
        else
        {
            par[ry] = rx; //根がrxの木に併合
            siz[rx] = siz[rx] + siz[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    //要素xが属する木と要素yが属する木が同じならtrueを返す
    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }
    //要素xが属する木の頂点数を返す
    long long size(long long x)
    {
        return siz[root(x)];
    }
};
