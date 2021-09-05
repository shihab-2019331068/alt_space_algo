void srk(ll a[],ll n){
   map<ll,ll> m; set<ll> s; ll i;
   for(i=1; i<=n; i++) s.insert(a[i]);
   i=0; for(ll j:s) m[j]=++i;
   for(i=1; i<=n; i++) a[i]=m[a[i]];|
}
