ll fat(ll p[],ll x){return p[x]=p[x]==x?x:fat(p,p[x]);}

void join(ll p[],ll h[],ll a,ll b)
{
   if(a==b) return;
   if(h[a]<h[b]) swap(a,b);
   h[a]+=h[b]; h[b]=0; p[b]=a;|
}

void dsu(ll p[],ll h[],ll n){for(ll i=0; i<=n; i++){p[i]=i; h[i]=1;}}
