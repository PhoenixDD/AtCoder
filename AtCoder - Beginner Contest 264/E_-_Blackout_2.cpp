#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,bmi,bmi2,lzcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include <complex>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <array>
#include <bitset>
#include <tuple>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// WARNING: functions as a set (doesn't allow duplicates); insert pairs (ele,idx) instead if duplicates are needed.
// Consider using splay_tree instead if constant factor is an issue (e.g., log^2 solutions), especially with duplicates.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // find_by_order, order_of_key

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 998244353

typedef long long ll;
typedef pair<int,int> ii;

class DSU {
    vector<int> Parent,Rank,ComponentSize;
    int maxComponentSize=1;
    public:
    DSU(int n) {
        Rank.resize(n,0);
        Parent.resize(n);
        ComponentSize.resize(n,1);
        for(int i=0;i<n;i++)
            Parent[i]=i;
    }
    int Find(int x) {
        return Parent[x]==x?x:Parent[x]=Find(Parent[x]);
    }
    bool Union(int x,int y) {
        int xset=Find(x),yset=Find(y);
        if(xset!=yset) {
            ComponentSize[xset]+=ComponentSize[yset];
            maxComponentSize=max(maxComponentSize,ComponentSize[yset]=ComponentSize[xset]);
            Rank[xset]<Rank[yset]?Parent[xset]=yset:Parent[yset]=xset;
            if(Rank[xset]==Rank[yset])
                Rank[xset]++;
            return true;
        }
        return false;
    }
    int getMaxComponentSize() {
        return maxComponentSize;
    }
    int getComponentSize(int n) {
        return ComponentSize[Find(n)];
    }
};
void solve() {
    int n,m,e;
    cin>>n>>m>>e;
    DSU dsu(n+m+1);
    vector<array<int,2>> edges(e);
    for(int i=0;i<e;i++) {
        cin>>edges[i][0]>>edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
    int q;
    cin>>q;
    vector<int> queries(q);
    for(int i=0;i<q;i++)
        cin>>queries[i],queries[i]--;
    unordered_set<int> qs(queries.begin(),queries.end());
    for(int i=n;i<n+m;i++)
        dsu.Union(i,n+m);
    for(int i=0;i<e;i++)
        if(!qs.count(i))
            dsu.Union(edges[i][0],edges[i][1]);
    vector<int> result;
    for(int i=q-1;i>=0;i--) {
        result.push_back(dsu.getComponentSize(n+m)-m-1);
        dsu.Union(edges[queries[i]][0],edges[queries[i]][1]);
    }
    for(auto it=result.rbegin();it!=result.rend();it++)
        cout<<*it<<endl;
}
int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("../inputf.in", "r", stdin);
    //     freopen("../outputf.out", "w", stdout);
    // #endif
    fast_cin();
    int testCaseCount=1;
    // cin>>testCaseCount;
    while(testCaseCount--)
        solve();
    return 0;
}