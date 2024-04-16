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

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define lli long long int
#define pb push_back
#define no cout << "NO" \
                << "\n"
#define yes cout << "YES" \
                 << "\n"
#define lb cout << "\n"
#define vll vector<lli>
#define pll pair<lli, lli>
#define vvll vector<vector<lli>>
#define vpll vector<pair<lli, lli>>
#define ump unordered_map<lli, lli>
#define all(v) v.begin(), v.end()
#define len(v) (lli) v.size()
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define sumv(v) accumulate(all(v), 0ll)
#define MOD 1000000007ll
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
#define minheap priority_queue<lli, vll, greater<lli>>
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.rbegin(), v.rend())
#define printv(v)     \
    for (auto it : v) \
        cout << it << " ";
#define input(v, n)             \
    for (lli i = 0; i < n; i++) \
    {                           \
        lli q;                  \
        cin >> q;               \
        v.push_back(q);         \
    }

void solve()
{
}
int32_t main()
{
    fast;
    int tests = 1;
    cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
    {
        // cout<<"Case # "<<tt<<" : ";
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

class SegmentTree
{
    vll seg;

public:
    SegmentTree(lli n)
    {
        seg.resize(4ll * n + 1);
    }
    void build(lli ind, lli low, lli high, vll &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        lli mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    //* seg.query(0,0,n-1,a,b);
    lli query(lli ind, lli low, lli high, lli l, lli r)
    {
        if (r < low || high < l)
            return INT_MAX;
        if (low >= l && high <= r)
            return seg[ind];
        lli mid = (low + high) / 2;
        lli left = query(2 * ind + 1, low, mid, l, r);
        lli right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    //* seg.update(0,0,n-1,a, b);
    void update(lli ind, lli low, lli high, lli i, lli val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        lli mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

class ST
{
    vector<int> seg, lazy;

public:
    ST(int n)
    {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }

public:
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    void update(int ind, int low, int high, int l, int r,
                int val)
    {
        // update the previous remaining updates
        // and propogate downwards
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap
        // we don't do anything and return
        // low high l r or l r low high
        if (high < l or r < low)
        {
            return;
        }

        // complete overlap
        // l low high r
        if (low >= l && high <= r)
        {
            seg[ind] += (high - low + 1) * val;
            // if a leaf node, it will have childrens
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        // last case has to be no overlap case
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    int query(int ind, int low, int high, int l, int r)
    {

        // update if any updates are remaining
        // as the node will stay fresh and updated
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap return 0;
        if (high < l or r < low)
        {
            return 0;
        }

        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class SegmentTree
{
    vll seg;

public:
    SegmentTree(lli n)
    {
        seg.resize(4ll * n + 1);
    }
    void build(lli ind, lli low, lli high, vll &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        lli mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    //* seg.query(0,0,n-1,a,b);
    lli query(lli ind, lli low, lli high, lli l, lli r)
    {
        if (r < low || high < l)
            return 0;
        if (low >= l && high <= r)
            return seg[ind];
        lli mid = (low + high) / 2;
        lli left = query(2 * ind + 1, low, mid, l, r);
        lli right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    //* seg.update(0,0,n-1,a, b);
    void update(lli ind, lli low, lli high, lli i, lli val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        lli mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
};

int sumPairs(vll &arr, int n)
{
    // sort if unsorted
    int sum = 0;
    for (lli i = n - 1; i >= 0; i--)
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    return sum;
}

void numberOfNodes(lli s, lli e, vll adj[], vll &count1)
{
    count1[s] = 1;
    for (auto u = adj[s].begin(); u != adj[s].end(); u++)
    {
        if (*u == e)
            continue;
        numberOfNodes(*u, s, adj, count1);
        count1[s] += count1[*u];
    }
}

void dfs(lli start, vll adj[], vll &vis, vll &v)
{
    vis[start] = 1;
    v.push_back(start);
    for (auto it : adj[start])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, v);
        }
    }
}

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v)
            return;
        if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

lli strStr(string s, string t)
{
    vll lps = lpsMaker(t);
    lli i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
        if (j == t.size())
        {
            return i - t.size();
        }
    }
    return -1;
}

vll lpsMaker(string &t)
{
    vll lps(t.size(), 0);
    lli prevLps = 0, i = 1;
    while (i < t.size())
    {
        if (t[i] == t[prevLps])
        {
            lps[i] = prevLps + 1;
            prevLps++;
            i++;
        }
        else
        {
            if (prevLps == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                prevLps = lps[prevLps - 1];
            }
        }
    }
    return lps;
}

lli dp[10][80][2];
lli G(string &str, lli pos = 0, lli tight = 1, lli sum = 0)
{
    if (pos == str.size())
    {
        return 1; // based on scenerio
    }
    if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];
    else if (tight == 1)
    {
        lli res = 0;
        for (int i = 0; i <= str[pos] - '0'; i++)
        {
            if (i == str[pos] - '0')
            {
                res += G(str, pos + 1, 1, sum + i);
            }
            else
            {
                res += G(str, pos + 1, 0, sum + i);
            }
        }
        return dp[pos][sum][tight] = res;
    }
    else
    {
        lli res = 0;
        for (int i = 0; i <= 9; i++)
        {
            res += G(str, pos + 1, 0, sum + i);
        }
        return dp[pos][sum][tight] = res;
    }
}
lli maxSubArraySum(vll &a, lli size)
{
    lli msf = LLONG_MIN, meh = 0;
    for (lli i = 0; i < size; i++)
    {
        meh = meh + a[i];
        if (msf < meh)
            msf = meh;

        if (meh < 0)
            meh = 0;
    }
    return msf;
}
vll primeFactors(lli n)
{
    vll facts;
    while (n % 2 == 0)
    {
        facts.pb(2);
        n = n / 2;
    }
    for (lli i = 3; i <= sqrtl(n); i = i + 2)
    {
        while (n % i == 0)
        {
            facts.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        facts.pb(n);
    return facts;
}
lli getGCD(lli a, lli b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        return b;
    }
    return a;
}
lli GcdOfArray(vll &arr)
{
    lli gcd = 0;
    for (lli i = 0; i < arr.size(); i++)
    {
        gcd = getGCD(gcd, arr[i]);
    }
    return gcd;
}
vll printDivisorsOptimal(int n)
{
    vll v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.pb(i);
            if (i != n / i)
                v.pb(n / i);
        }
    }
    return v;
}
vll divSum(n + 1, 0);
for (int i = 1; i <= n; i++)
{
    for (int j = i + i; j <= n; j += i)
    {
        divSum[j]++;
    }
}

lli gcd(lli int a, lli int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
lli lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}