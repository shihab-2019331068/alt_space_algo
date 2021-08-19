ll fat(ll p[],ll x){return p[x]=p[x]==x?x:fat(p,p[x]);}
void dsu(ll p[],ll n){for(ll i=1; i<=n; i++) p[i]=i;|}
