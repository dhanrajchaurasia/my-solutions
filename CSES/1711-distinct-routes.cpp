#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#ifdef coderdhanraj
#include "libs/debug.h"
#else
#define debug(...) 
#endif
#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define FIND(x, y) binary_search(all(x), y)
#define MEM(x, y) memset(x, y, sizeof(x))
#define CNT(x) __builtin_popcountll(x)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define bck(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define endl '\n' // remove for interactives
using i64 = int64_t; using u64 = uint64_t; using i128 = __int128_t; using u128 = __uint128_t;
using vi = vector<int>; using mii = map<int, int>; using pii = pair<int, int>; using vii = vector<pii>;
/* --------------------------------------------------------- TEMPLATES --------------------------------------------------- */
class custom_hash{public: static u64 splitmix64(u64 x){ x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(u64 x) const {static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
    template<typename P, typename Q>
    size_t operator()(const pair<P, Q> &Y) const{static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);}
};
template<typename P, typename Q> istream& operator>>(istream &in, pair<P, Q> &p){return (in >> p.first >> p.second);}
template<typename P, typename Q> ostream& operator<<(ostream &out, const pair<P, Q> &p){return (out << p.first << " " << p.second); }
template<typename T> istream& operator>>(istream &in, vector<T> &a){for(auto &e : a) cin >> e; return in;}
template<typename T> ostream& operator<<(ostream &out, const vector<T> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T, size_t N> istream& operator>>(istream &in, array<T, N> &a){for(auto &e : a) cin >> e; return in;}
template<typename T, size_t N> ostream& operator<<(ostream &out, array<T, N> &a){for (auto &e : a) cout << e << " "; return out;}
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vec = vector<vector<T>>;
template<typename P, size_t Q> using var = vector<array<P, Q>>;
template<typename P, typename Q> using indexed_map = tree<P, Q, less<P>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename P, typename Q> using gphash = gp_hash_table<P, Q, custom_hash>;
template<typename P, typename Q> using umap = unordered_map<P, Q, custom_hash>;
template<typename P, typename Q> void amax(P &x, Q y){if(x < y) x = y;}
template<typename P, typename Q> void amin(P &x, Q y){if(x > y) x = y;}
template<typename T> void unique(vector<T> &a){sort(all(a)); a.resize(unique(all(a)) - a.begin());}
template<typename T> T ceil(T x, T y){return (x >= 0 ? (x + y - 1) / y : x / y);}
template<typename T> T floor(T x, T y){return x / y - ((x ^ y) < 0 and x % y);}
template<typename T> T gcd(T x, T y){return (x ? gcd(y % x, x) : y);}
template<typename T> T lcm(T x, T y){return x / gcd(x, y) * y;}
template<typename T> T ncr(T n, T k){if (n < k){return 0;} k = min(k, n - k); T ans = 1; rep(i, 1, k + 1){ans *= (n - i + 1), ans /= i;} return ans;}
template<typename P, typename Q> P expo(P x, Q y, u64 m = LLONG_MAX){P res = 1; x = x % m; while (y > 0){if (y & 1) res = (u128)res * x % m; y = y >> 1, x = (u128)x * x % m;} return res;}
template<typename P, typename Q> P bpow(P x, Q y){P res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1, x *= x;} return res;}
template<typename P, typename Q> P inv(P n, Q m){return expo(n, m - 2, m);}
template<typename T> T sqr(T x){return x * x;}
/* --------------------------------------------------------- UNIVERSAL CONSTANTS --------------------------------------------------- */
const double eps = 1e-9;
const int mod = 1e9 + 7;  // 998244353LL; // 10000000069LL; // 3006703054056749LL;
const i64 inf = 1LL << 60;
const double pi = 3.14159265358979323846264338327950;
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
/* --------------------------------------------------------- USEFUL FUNCTIONS ---------------------------------------------------- */
int testcase;
bool isOverflow(int x, int y){return (x > LLONG_MAX / y or y > LLONG_MAX / x);}
bool ispow2(int x){return (x ? !(x & (x - 1)) : 0);}
bool Case(){return cout << "Case #" << ++testcase << ": ", true;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
i64 rand(i64 x, i64 y){return uniform_int_distribution<i64>(x, y)(rng);}
#define JAI_SHREE_RAAM ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout.precision(20), cout.setf(ios::fixed);
/* ------------------------------------------------------- SOLUTION TO THE PROBLEM ------------------------------------------------- */
class Dinic{
private: const i64 flow_inf = 1e18;
    struct edge{
        int u, v;
        i64 cap, flow = 0;
        edge(int u, int v, i64 cap) : u(u), v(v), cap(cap){}
    };
    vector<vector<int>> adj;
    vector<int> d, nxt;
    vector<edge> e;
    queue<int> q;
    int n, m = 0, mflow = 1, s, t;
    bool bfs(){
        fill(all(d), -1), d[s] = 0, q.push(s);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto &id : adj[u]) if (d[e[id].v] == -1 and e[id].cap - e[id].flow >= mflow){
                d[e[id].v] = d[u] + 1, q.push(e[id].v);
            }
        }
        return d[t] != -1;
    }
    i64 dfs(int u, i64 flow){
        if (!flow) return 0;
        if (u == t) return flow;
        for (; nxt[u] < size(adj[u]); nxt[u]++){
            int id = adj[u][nxt[u]], v = e[id].v;
            if (e[id].cap == e[id].flow or d[v] != d[u] + 1) continue;
            i64 pushed = dfs(v, min(flow, e[id].cap - e[id].flow));
            if (pushed) return e[id].flow += pushed, e[id ^ 1].flow -= pushed, pushed;
        }
        return 0;
    }
public: Dinic(int n, int s, int t) : n(n), s(s), t(t){adj.resize(n), d.resize(n), nxt.resize(n);}
    void add_edge(int u, int v, i64 cap){
        e.emplace_back(u, v, cap), e.emplace_back(v, u, 0);
        adj[u].push_back(m), adj[v].push_back(m + 1), m += 2;
    }
    i64 flow(){
        i64 f = 0;
        while (bfs()){
            fill(all(nxt), 0);
            while (i64 pushed = dfs(s, flow_inf)) f += pushed;
        }
        return f;
    }
    vector<pair<int, int>> minCut(){
        set<int> reach;
        vi vis(n); q.push(s); vis[s] = 1;
        while (!q.empty()){
            int u = q.front(); q.pop();
            reach.insert(u);
            for (auto &id : adj[u]) if (e[id].flow > 0 and !vis[e[id].v]) q.push(e[id].v), vis[e[id].v] = 1;
        }
        vector<pair<int, int>> cut;
        for (auto &u : reach) for (auto &id : adj[u]) if (e[id].flow > 0 and d[e[id].v] == -1 and !reach.count(e[id].v)) cut.emplace_back(u, e[id].v);
        return cut;
    }
    void dfs(int u, vi &ans){
        ans.pb(u + 1);
        for (; nxt[u] < size(adj[u]); nxt[u]++){
            int id = adj[u][nxt[u]], v = e[id].v;
            if (e[id].flow > 0){
                nxt[u]++, dfs(v, ans);
                break;
            }
        }
    }
    vec<int> paths(){
        nxt.assign(n, 0);
        vec<int> ans;
        for (; nxt[s] < size(adj[s]); nxt[s]++){
            int id = adj[s][nxt[s]], v = e[id].v;
            if (e[id].flow > 0){
                vi res(1, s + 1);
                dfs(v, res);
                ans.pb(res);
            }
        }
        return ans;
    }
};
void solve(){
    int n, m; cin >> n >> m;
    Dinic d(n, 0, n - 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v, --u, --v;
        d.add_edge(u, v, 1);
    }
    cout << d.flow() << endl;
    auto ans = d.paths();
    for (auto &e : ans){
        cout << size(e) << endl;
        cout << e << endl;
    }
}
int32_t main(){
#ifdef coderdhanraj
    auto start = high_resolution_clock::now();
    freopen("error.txt", "w", stderr);
#endif
    JAI_SHREE_RAAM
    int ttc = 1;
    // cin >> ttc;
    while (ttc--) solve();
#ifdef coderdhanraj
    auto time =  duration_cast<microseconds>(high_resolution_clock::now() - start).count() / 1000;
    cerr << "Time: " << time << " ms!" << endl;
#endif
    return 0;
}