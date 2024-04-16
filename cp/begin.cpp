#include <bits/stdc++.h>
using namespace std; 

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long int
#define pb push_back
#define no cout << "NO" << "\n"
#define yes cout << "YES" << "\n"
#define lb cout<<"\n" 
#define vll vector<lli> 
#define pll pair<lli,lli>
#define vvll vector<vector<lli>>
#define vpll vector<pair<lli, lli>> 
#define ump unordered_map<lli,lli>
#define all(v)    v.begin() , v.end()
#define len(v)  (lli)v.size()
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define sumv(v) accumulate(all(v),0ll)
#define MOD 1000000007ll
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
#define minheap priority_queue <lli,vll, greater<lli> >
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.rbegin(), v.rend())
#define printv(v) for(auto it: v) cout<<it<<" ";
#define input(v,n) for(lli i=0; i<n; i++){lli q; cin>>q; v.push_back(q);} 

void solve()
{

}
int32_t main()
{
    fast;
    int tests = 1;
    cin >> tests;
    for (int tt = 1; tt <= tests; tt++){
        //cout<<"Case # "<<tt<<" : ";
        solve();
    }
    return 0;
}
//*Number Theory : lcm | gcd | countDivisors | GetDivisors | ArrayGcd | PrimeFactors 
//*isPallindrome : return y/n
//*Kadanes : maximum Subarray
//*DP: DigitDp
//*String : LPS | KMP
//*Graph : dsu | dfs | subtreeNodeCount
//*sumPairs : sum of absolute diff. in O(N)
//*slidingWindowVar : largest window with sum lte t
//* Range Queries: segtree | fenwick | fenwickmin

//*---------------Gyaan---------------------*//
//! pbds ka gyaan
//!  v.order_of_key(x) -> number of elements smaller than X
//! *v.find_by_order(x) -> element present at index X