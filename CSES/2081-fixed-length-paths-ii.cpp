#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // yay python!

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define EACH(a, x) for (auto &a : x)

const int MOD = 1e9 + 7;  // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18;  // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int bits(int x) {  // assert(x >= 0); // make C++11 compatible until
                             // USACO updates ...
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

tcTU > T fstTrue(T lo, T hi, U f) {
    hi++;
    assert(lo <= hi);  // assuming f is increasing
    while (lo < hi) {  // find first index such that f is true
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    lo--;
    assert(lo <= hi);  // assuming f is decreasing
    while (lo < hi) {  // find first index such that f is true
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}
tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
    sort(all(v));
    v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T &t, const U &u) {  // don't erase
    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
}  // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class... U
tcT > void re(complex<T> &c);
tcTU > void re(pair<T, U> &p);
tcT > void re(V<T> &v);
tcT, size_t SZ > void re(AR<T, SZ> &a);

tcT > void re(T &x) { cin >> x; }
void re(double &d) {
    str t;
    re(t);
    d = stod(t);
}
void re(long double &d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
}

tcT > void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > void re(V<T> &x) { EACH(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ> &x) { EACH(a, x) re(a); }
tcT > void rv(int n, V<T> &x) {
    x.rsz(n);
    re(x);
}

// TO_STRING
#define ts to_string
str ts(char c) { return str(1, c); }
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
    // #ifdef LOCAL
    //  return b ? "true" : "false";
    // #else
    return ts((int)b);
    // #endif
}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(V<bool> v) {
    str res = "{";
    F0R(i, sz(v)) res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ> str ts(bitset<SZ> b) {
    str res = "";
    F0R(i, SZ) res += char('0' + b[i]);
    return res;
}
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) {  // containers with begin(), end()
#ifdef LOCAL
    bool fst = 1;
    str res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res = "";
    for (const auto &x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;

#endif
}
tcTU > str ts(pair<T, U> p) {
#ifdef LOCAL
    return "(" + ts(p.f) + ", " + ts(p.s) + ")";
#else
    return ts(p.f) + " " + ts(p.s);
#endif
}

// OUTPUT
tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T &t, const U &...u) {
    pr(t);
    pr(u...);
}
void ps() { pr("\n"); }  // print w/ spaces
tcTUU > void ps(const T &t, const U &...u) {
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T &t, const U &...u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
#ifdef LOCAL  // compile with -DLOCAL, chk -> fake assert
#define dbg(...)                                                               \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [",         \
        DBG(__VA_ARGS__)
#define chk(...)                                                               \
    if (!(__VA_ARGS__))                                                        \
        cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__        \
             << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")"                    \
             << "\n",                                                          \
            exit(0);
#else
#define dbg(...) 0
#define chk(...) 0
#endif

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
// FILE I/O
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
    unsyncIO();
    setPrec();
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for USACO
}

int max_len;
ll mul = 1;
ll ans;
int N, K1, K2;
vi adj[MX];

int get_prefix(const deque<int> &a, int mx) {
    if (mx < 0) return 0;
    if (mx + 1 >= sz(a)) return a[0];
    return a[0] - a[mx + 1];
}

void comb(deque<int> &a, deque<int> &b) {
    if (sz(a) < sz(b)) swap(a, b);
    F0R(i, sz(b) - 1) b[i] -= b[i + 1];
    F0R(i, sz(b))
    ans += (ll)b[i] * (get_prefix(a, K2 - i) - get_prefix(a, K1 - 1 - i));
    R0F(i, sz(b) - 1) b[i] += b[i + 1];
    F0R(i, sz(b)) a[i] += b[i];
}

deque<int> dfs(int x, int p) {  // each deque stores prefix sums
    deque<int> res{1};
    EACH(y, adj[x]) if (y != p) {
        deque<int> a = dfs(y, x);
        a.push_front(a.ft);
        comb(res, a);
    }
    return res;
}

int main() {
    setIO();
    re(N, K1, K2);
    F0R(i, N - 1) {
        int a, b;
        re(a, b);
        adj[a].pb(b), adj[b].pb(a);
    }
    max_len = K1 - 1, mul = -1;
    dfs(1, 0);
    ps(ans);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */