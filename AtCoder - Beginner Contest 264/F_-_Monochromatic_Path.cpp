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
#include <limits>
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

static ll memo[2001][2001][2][2][2];
ll dp(vector<vector<int>> &a,vector<int> &rc,vector<int> &cc,int i,int j,int r,int c,int target) {
    if(i==a.size()-1&&j==a[0].size()-1)
        return 0;
    if(memo[i][j][r][c][target]!=-1)
        return memo[i][j][r][c][target];
    ll result=LLONG_MAX;
    if(i+1<a.size()) {
        if(a[i+1][j]^c==target)
            result=dp(a,rc,cc,i+1,j,0,c,target);
        else
            result=rc[i+1]+dp(a,rc,cc,i+1,j,1,c,target);
    }
    if(j+1<a[0].size()) {
        if(a[i][j+1]^r==target)
            result=min(result,dp(a,rc,cc,i,j+1,r,0,target));
        else
            result=min(result,cc[j+1]+dp(a,rc,cc,i,j+1,r,1,target));
    }
    return memo[i][j][r][c][target]=result;
}
void solve() {
    int h,w;
    cin>>h;
    cin>>w;
    vector<int> r(h),c(w);
    vector<vector<int>> a(h,vector<int>(w));
    for(int i=0;i<h;i++)
        cin>>r[i];
    for(int i=0;i<w;i++)
        cin>>c[i];
    string temp;
    for(int i=0;i<h;i++) {
        cin>>temp;
        for(int j=0;j<w;j++)
            a[i][j]=temp[j]-'0';
    }
    memset(memo,-1,sizeof memo);
    ll result=LLONG_MAX;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++) {
                int curr=0;
                if(i==1)
                    curr=r[0];
                if(j==1)
                    curr+=c[0];
                if(a[0][0]^i^j==k)
                    result=min(result,curr+dp(a,r,c,0,0,i,j,k));
            }
    cout<<result;

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