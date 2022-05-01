Problems: (LUV YT)
    https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
    https://www.hackerearth.com/problem/algorithm/city-and-flood-1/
    https://codeforces.com/problemset/problem/277/A
    https://codeforces.com/problemset/problem/1559/D1
    https://codeforces.com/problemset/problem/445/B
    https://codeforces.com/problemset/problem/1167/C

1.  Time Complexity : O(a(n))
    -> Path Compression
    -> Size Compression


ll parent[200005];
ll SZ[200005];

void make(ll v) {
        parent[v] = v;
        SZ[v] = 1;
        return;
}
ll find(ll v) {
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
}
void Union(ll a , ll b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(SZ[b]>SZ[a]) swap(a,b);
            parent[b] = a;
            SZ[a] += SZ[b];
        }
        return;
}

ll solve()
{
        ll n = vin() , k = vin();
        for(int i=1; i<=n; i++) {
            make(i);
        }
        for(int i=0; i<k; i++) {
            ll u = vin();
            ll v = vin();
            Union(u,v);
        }
        //  Connected Components
        ll cnt = 0;
        for(int i=1; i<=n; i++) {
            if(find(i) == i) cnt++;
        }
        return  cnt;
}
