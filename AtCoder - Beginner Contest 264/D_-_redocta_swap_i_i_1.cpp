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


void solve() {
    string s,fin="atcoder";
    cin>>s;
    int result=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]!=fin[i]) {
            int j=i+1;
            for(j=i+1;j<s.length();j++)
                if(s[j]==fin[i])
                    break;
            while(j!=i) {
                swap(s[j-1],s[j]);
                j--;
                result++;
            }
        }
    }
    cout<<result<<endl;
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