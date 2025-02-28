/* 
----------------------------------------------------------------------------------------------------------------------------
----------------------------- This problem has been solved by coderdhanraj (Dhanraj Chaurasia) ---------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define float long double
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define si set<int>
#define msi multiset<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ppb pop_back()
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bk back()
#define cr clear()
#define emp empty()
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define count_0(x) __builtin_ctzll(x)
#define count_1(x) __builtin_popcountll(x)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define sumof(x) accumulate(all(x), 0LL)
#define S_index(x, y) accumulate(all(x), 0LL)
#define index(x, y) find(all(x), y) - (x).begin()
#define exist(x, y) binary_search(all(x), y)
#define trans(x, y) transform(all(x), (x).begin(), ::y)
#define ceil(x, y) x / y + (x % y != 0)
#define debug(x) cout << #x << " = " << x << endl
#define debugs(x) cout << "{" << x.ff << ", " << x.ss << "}" << endl
#define cins(x)       \
    for (auto &i : x) \
    cin >> i
#define cins2(x)      \
    for (auto &i : x) \
    cin >> i.ff >> i.ss
#define cond(x) cout << &("NO\0YES"[3 * x]) << endl
#define google(x) cout << "Case #" << x << ": "
#define mem(x, y) memset(x, y, sizeof(x))
#define assign(x, y) (x).assign(size(x), y)
#define length(x) (int)(floor(log10(x) + 1))
#define endl "\n"
#define mod (int)1e9 + 7
#define mod2 998244353
#define eps 1e-6
#define inf (int)1e18
const int maxn = 2e5 + 10;

void IOS_ONLINE_JUDGE()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout.setf(ios::fixed);
}
/*
----------------------------------------------------------------------------------------------------------------------------
------------------------------------------------ Solution Starts From Here------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------
*/
vi adj[maxn], par(maxn);
bool vis[maxn];

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.emp)
    {
        int x = q.fr;
        q.pop();
        for (auto &a : adj[x])
        {
            if (!vis[a])
            {
                par[a] = x;
                vis[a] = true;
                q.push(a);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs();
    if (!par[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vi ans;
        while (par[n] != 1)
        {
            ans.pb(n);
            n = par[n];
        }
        ans.pb(n);
        ans.pb(1);
        reverse(all(ans));
        cout << size(ans) << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
}

int32_t main()
{
    IOS_ONLINE_JUDGE();
    int ttc = 1;
    while (ttc--)
    {
        auto start_time = chrono::high_resolution_clock::now();
        solve();
        cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms." << endl;
    }
    return 0;
}