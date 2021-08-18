ll fat(ll p[],ll x)
{
   return p[x]=p[x]==x?x:fat(p,p[x]);|
}

void join(ll p[],ll h[],ll a,ll b)
{
   if(a==b) return;
   if(h[a]<h[b]) swap(a,b);
   p[b]=a; h[a]+=h[b]; h[b]=0;
}

void start_dsu(ll p[],ll h[],ll n)
{
   ll i;
   for(i=1; i<=n; i++){
      p[i]=i; h[i]=1;
   }
}
