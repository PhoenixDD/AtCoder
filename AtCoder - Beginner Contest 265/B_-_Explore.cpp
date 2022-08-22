#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,bmi,bmi2,lzcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <cstring>
#include <vector>
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
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
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
template <class T>
static void hash_combine(size_t& seed,const T& v) {
     seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
}
namespace std {
    // Hash pair.
    template<typename T,typename U>
    struct hash<pair<T,U>> {
        inline size_t operator()(const pair<T,U>& p) const {
            size_t hash = 0;
            hash_combine(hash,p.first);
            hash_combine(hash,p.second);
            return hash;
        }
    };
    // Hash vector.
    template<typename T>
    struct hash<vector<T>> {
        inline size_t operator()(const vector<T>& v) const {
            size_t hash = 0;
            for(const T &val:v)
                hash_combine(hash,val);
            return hash;
        }
    };
    // Hash array.
    template<typename T>
    struct hash<array<T,2>> {
        inline size_t operator()(const array<T,2>& v) const {
            size_t hash = 0;
            for(const T &val:v)
                hash_combine(hash,val);
            return hash;
        }
    };
}

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 998244353

typedef long long ll;
typedef pair<int,int> ii;


void solve() {
    ll n,m,t;
    cin>>n>>m>>t;
    vector<int> a(n);
    vector<ii> xy(m);
    for(int i=0;i<n-1;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>xy[i].first>>xy[i].second;
    int j=0,i=0;
    for(i=0;i<n-1;i++)
        if(t>a[i]) {
            t-=a[i];
            if(j<m&&xy[j].first-2==i)
                t+=xy[j++].second;
        } else
            break;
    cout<<(i==n-1?"Yes":"No");
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