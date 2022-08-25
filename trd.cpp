
/*------ Kosaraju -------*/
struct Ksrj {
    ve<vll> g, rg;
    vll vs, sk, p;
    ll n;
    Ksrj (ll _n, ve<vll>& _g, ve<vll>& _rg) {
        n = _n; g = _g; rg = _rg;
        p = vs = vll (n + 1, 0); sk = {};
    }
    void dfs (ll u, ll P, ve<vll>& g) {
        vs[u] = 1; p[u] = P;
        for (ll v : g[u])
            if (!vs[v])
                dfs (v, P, g);
        if (P == -1) sk.push_back (u);
    }
    vll go () {
        ll i, u;
        for (i = 1; i <= n; i++)
            if (!vs[i])
                dfs (i, -1, g);
        p = vs = vll (n + 1, 0);
        for (; sk.size (); sk.pop_back ()) {
            u = sk.back ();
            if (!vs[u])
                dfs (u, u, rg);
        }
        return p;
    }
};

/*------- Count Inversion --------*/

ll cntInvrsn (ll l, ll r, vll& v, vll& t) {
    if (l == r) return 0;
    ll m = l + r >> 1;
    ll ans = cntInvrsn (l, m, v, t) + cntInvrsn (m + 1, r, v, t);
    ll i, j, k;
    for (i = k = l, j = m + 1; i <= m and j <= r; ) {
        if (v[i] <= v[j]) t[k++] = v[i++];
        else t[k++] = v[j++], ans += m - i + 1;
    }
    for (; i <= m; i++) t[k++] = v[i];
    for (; j <= r; j++) t[k++] = v[j];
    for (i = l; i <= r; i++) v[i] = t[i];
    return ans;
}

ll cntInvrsn (vll& v) {
    ll n = v.size ();
    vll t (n);
    return cntInvrsn (0, n - 1, v, t);
}

/* --------------- debug ---------------- */

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=" << a << " ! ";
    err (++it, args...);
}

/* ---------- Integer to binary ------------- */

string bbb (ll x) {
    string s;
    bool ok = 0;
    for (ll i = 63; i >= 0; i--) {
        ok |= (x >> i) & 1;
        if (ok) s += ((x >> i) & 1) ? "1" : "0";
    }
    return s;
}

/* ------------ Dinic ------------------- */

struct FlowEdge {
    ll v, u, cap, flow = 0;
    FlowEdge (ll v, ll u, ll cap) : v (v), u (u), cap (cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vll> adj;
    ll n, m = 0, s, t;
    vll level, ptr;
    queue<ll> q;

    Dinic (ll n, ll s, ll t) : n (n), s (s), t (t) {
        adj = vector<vll> (n);
        level = ptr = vll (n);
    }

    void add_edge (ll v, ll u, ll cap) {
        edges.emplace_back (v, u, cap);
        edges.emplace_back (u, v, 0);
        adj[v].pb (m);
        adj[u].pb (m + 1);
        m += 2;
    }

    bool bfs () {
        while (!q.empty ()) {
            ll v = q.front ();
            q.pop ();
            for (ll id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1 or
                    level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push (edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs (ll v, ll pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (ll& cid = ptr[v]; cid < (ll)adj[v].size (); cid++) {
            ll id = adj[v][cid];
            ll u = edges[id].u;
            if (level[v] + 1 != level[u] or edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs (u, min (pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow () {
        ll f = 0;
        while (1) {
            level = vll (n, -1);
            level[s] = 0;
            q.push (s);
            if (!bfs ()) break;
            ptr = vll (n, 0);
            while (ll pushed = dfs (s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

/* ------------ Fenwick Tree ------------- */

void upd (vll& t, ll i, ll v) { for (; i < t.size (); i += i & -i) t[i] += v; }
ll ask (vll& t, ll i) { ll R = 0; for (; i > 0; i -= i & -i) R += t[i]; return R; }

/* ------------- Hash ----------------- */

struct Hash {
    ve<ve<ll>> pv;
    ve<ll> b = { 122,123 };

    ll rabinKarpHash (const string& s, ll bi) {
        ll n = s.size (), ans = 0, i;
        for (i = 0; i < n; i++) ans = add (ans, mul (s[i], pv[bi][n - i - 1]));
        return ans;
    }

    ll roll (char c1, char c2, ll bi, ll sh, ll tz) {
        sh = sub (sh, mul (c1, pv[bi][tz - 1]));
        sh = mul (sh, b[bi]);
        sh = add (sh, c2);
        return sh;
    }

    ll go (const string& s, const string& t) {
        ll sz = s.size (), i, j, tz = t.size ();
        if (tz > sz) return -1;

        pv = ve<ve<ll>> (2, ve<ll> (sz + 7));
        for (i = 0; i < 2; i++) for (j = 1, pv[i][0] = 1; j < sz + 7; j++) pv[i][j] = mul (pv[i][j - 1], b[i]);

        ll th1 = rabinKarpHash (t, 0), sh1 = rabinKarpHash (s.substr (0, tz), 0);
        ll th2 = rabinKarpHash (t, 1), sh2 = rabinKarpHash (s.substr (0, tz), 1);

        if (th1 == sh1 and th2 == sh2) return 0;
        for (i = 0; i + tz < sz; i++) {
            sh1 = roll (s[i], s[i + tz], 0, sh1, tz);
            sh2 = roll (s[i], s[i + tz], 1, sh2, tz);
            if (th1 == sh1 and th2 == sh2) return i + 1;
        }
        return -1;
    }
};

/* ---------- HLD ----------------- */

template<ll size, ll lg>
struct hld {
    ll n;
    vector<ll> edges[size];
    ll heavy[size];
    ll sz[size];
    ll depth[size];
    ll chain[size];
    ll label[size], label_time;
    ll par[size];

    ll seg_tree[size << 3];
    ll lazy_tree[size << 3];

    ll euler_id[size << 2], euler_time;
    ll euler_end[size];
    pll lca_table[size << 2][lg];

    void init (ll _n) {
        n = _n;
        for (ll i = 0; i < n; i++) {
            edges[i] = {};
            chain[i] = i;
        }
        for (ll i = 1; i <= (n << 3) + 3; i++) seg_tree[i] = lazy_tree[i] = 0;
    }
    void init2 () {
        dfs (0, -1, 0);
        label_time = 0;
        dfs_chain (0, -1);
        euler_time = 0;
        dfs_euler (0, -1);
        build_lca_table ();
    }

    void dfs (ll u, ll p, ll h) {
        depth[u] = h; par[u] = p; sz[u] = 1;
        ll vv = -1;
        for (ll v : edges[u]) if (v != p) {
            dfs (v, u, h + 1);
            sz[u] += sz[v];
            if (vv == -1 or sz[v] > sz[vv]) vv = v;
        }
        heavy[u] = vv;
    }
    void dfs_chain (ll u, ll p) {
        label[u] = ++label_time;
        if (heavy[u] != -1) {
            chain[heavy[u]] = chain[u];
            dfs_chain (heavy[u], u);
        }
        for (ll v : edges[u]) if (v != p and v != heavy[u]) dfs_chain (v, u);
    }

    /* ----- LCA ----- */
    void dfs_euler (ll u, ll p) {
        euler_id[++euler_time] = u;
        euler_end[u] = euler_time;
        for (ll v : edges[u]) if (v != p) {
            dfs_euler (v, u);
            euler_id[++euler_time] = u;
            euler_end[u] = euler_time;
        }
    }
    void build_lca_table () {
        for (ll i = euler_time; i > 0; i--) {
            ll u = euler_id[i];
            lca_table[i][0] = mp (depth[u], u);
            for (ll j = 1; j < lg; j++) {
                ll len = 1ll << j;
                if (euler_time - i + 1 < len) break;
                lca_table[i][j] = min (lca_table[i][j - 1], lca_table[i + (1ll << j - 1)][j - 1]);
            }
        }
    }
    ll lca (ll l, ll r) {
        if (l == r) return l;
        if (euler_end[l] > euler_end[r]) swap (l, r);
        ll l_end = euler_end[l], r_end = euler_end[r];
        ll len = r_end - l_end + 1;
        ll len_msb = msb (len), len_msb_len = 1ll << len_msb;
        return min (lca_table[l_end][len_msb], lca_table[r_end - len_msb_len + 1][len_msb]).sc;
    }

    /* ------------ SegTree ---------- */
    ll out_of_bound = 0;
    ll seg_merge (ll x, ll y) {
        return x + y;
    }
    ll seg_q (ll id, ll tl, ll tr, ll ql, ll qr) {
        if (tl > qr or ql > tr) return out_of_bound;
        if (ql <= tl and tr <= qr) return seg_tree[id];
        ll mid = tl + tr >> 1;
        return seg_merge (seg_q (id << 1, tl, mid, ql, qr), seg_q (id << 1 | 1, mid + 1, tr, ql, qr));
    }
    ll seg_u (ll id, ll tl, ll tr, ll qi, ll val) {
        if (tl > qi or qi > tr) return seg_tree[id];
        if (qi == tl and tr == qi) return seg_tree[id] = val;
        ll mid = tl + tr >> 1;
        return seg_tree[id] = seg_merge (seg_u (id << 1, tl, mid, qi, val), seg_u (id << 1 | 1, mid + 1, tr, qi, val));
    }

    /* -------------- HLD -----------*/
    ll query (ll l, ll r) {
        ll lc = lca (l, r);
        ll ans = seg_merge (goUp (l, lc), goUp (r, lc));
        ll lcv = seg_q (1, 1, n, label[lc], label[lc]);
        ans = seg_merge (ans, lcv);
        return ans;
    }
    void update (ll vertex, ll val) {
        seg_u (1, 1, n, label[vertex], val);
    }
    ll goUp (ll cur, ll lc) {
        ll ans = out_of_bound;
        while (depth[cur] > depth[lc]) {
            ll up = chain[cur];
            if (depth[up] <= depth[lc]) ans = seg_merge (ans, seg_q (1, 1, n, label[lc] + 1, label[cur]));
            else ans = seg_merge (ans, seg_q (1, 1, n, label[up], label[cur]));
            cur = par[up];
        }
        return ans;
    }
    void add_edge (ll u, ll v) {
        edges[u].push_back (v);
        edges[v].push_back (u);
    }
};

/* -------------- Lazy ---------------- */

struct Node {
    ll small, lazy;

    void merge (const Node& a, const Node& b) {
        small = min (a.small, b.small);
    }

    void add (ll x) {
        small += x;
        lazy += x;
    }
};

ll TYPE_ADD = 1, TYPE_MAX = 2;

ve < Node > tree;

void rec (ll id, ll l, ll r, ll q_l, ll q_r, ll type, ll& x) {
    if (r < q_l or q_r < l) return;

    if (q_l <= l and r <= q_r) {
        if (type == TYPE_ADD) {
            tree[id].add (x);
        }
        else {
            x = min (x, tree[id].small);
        }

        return;
    }

    for (ll jd : {id << 1, id << 1 | 1}) {
        tree[jd].add (tree[id].lazy);
    }

    tree[id].lazy = 0;

    rec (id << 1, l, l + r >> 1, q_l, q_r, type, x);
    rec (id << 1 | 1, l + r + 2 >> 1, r, q_l, q_r, type, x);

    tree[id].merge (tree[id << 1], tree[id << 1 | 1]);
}

/* ----------------- CHT -------------- */
struct Line {
    ll m, b;
    ll operator()(ll x) { return m * x + b; }
};
struct LCT {
    // val is the line that
    // has the minimum y for
    // x=m=l+r>>1
    Line val;
    LCT* ls = 0, * rs = 0;
    LCT (Line _val) : val (_val) {}
    void upd (ll l, ll r, Line val) {
        if (l + 1 == r) {
            if (val (l) < this->val (l)) this->val = val;
            return;
        }
        ll m = l + r >> 1;
        // slope of val is bigger
        // so that the crossing point is left of 'm'
        if (val.m < this->val.m) swap (val, this->val);
        if (val (m) < this->val (m)) {
            swap (val, this->val);
            if (rs) rs->upd (m, r, val);
            else rs = new LCT (val);
        }
        else {
            if (ls) ls->upd (l, m, val);
            else ls = new LCT (val);
        }
        return;
    }
    ll rnq (ll l, ll r, ll x) {
        if (l + 1 == r) return this->val (x);
        ll m = l + r >> 1;
        if (x < m and (ls)) return min (this->val (x), ls->rnq (l, m, x));
        if (rs) return min (this->val (x), rs->rnq (m, r, x));
        return this->val (x);
    }
};

/*-------------- vector set map debug ----------- */
template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.fr << ", " << p.sc << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]\n"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]\n"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{";for (auto it = s.begin ();it != s.end ();++it) { if (it != s.begin ())out << ", ";out << *it; }return out << "}\n"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{";for (auto it = m.begin ();it != m.end ();++it) { if (it != m.begin ())out << ", ";out << *it; }return out << "}\n"; }
