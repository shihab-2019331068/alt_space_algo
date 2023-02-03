
#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define aa                auto
#define ll                long long
#define ull               unsigned long long
#define ld                long double
#define fr                first
#define sc                second
#define pll               pair<ll,ll>
#define tll               pair<pll,ll>
#define vll               vector<ll>
#define bp(x)             __builtin_popcountll(x)
#define msb(x)            (63-__builtin_clzll(x))
#define all(a)            a.begin(),a.end()
#define arr(a)            a.rbegin(),a.rend()
#define cb(a,i)           (a>>i&1)
#define mp(a,b)           make_pair(a,b)
#define mt(a,b,c)         mp(mp(a,b),c)
#define lb(a)             lower_bound(a)
#define ub(a)             upper_bound(a)
#define pb(a)             push_back(a)
#define ve                vector


#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=" << a << " ! ";
    err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.fr << ", " << p.sc << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]\n"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]\n"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{";for (auto it = s.begin ();it != s.end ();++it) { if (it != s.begin ())out << ", ";out << *it; }return out << "}\n"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{";for (auto it = m.begin ();it != m.end ();++it) { if (it != m.begin ())out << ", ";out << *it; }return out << "}\n"; }

const ll N = 5e5 + 7, inf = 2e18;
const ld eps = 1e-8;
const ll M = 1e9 + 7;
//const ll M = 998244353;


/******************** Aladeen Matha Faka ***********************/


ll a[N], b[N];
string s;
ll n, m, i, j, k, x, u, v;

void solve (ll tt) {
    while (getline (cin, s)) {
        string t;
        t += '\"';
        for (aa c : s) {
            if (c == '"') t += '\\';
            if (c == '\\') t += '\\';
            t += c;
        }
        t += "\",";
        cout << t << "\n";
    }
}

int32_t main () {
    fastio;
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) solve (i);
}
