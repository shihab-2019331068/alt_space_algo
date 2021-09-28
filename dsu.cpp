ll fat(ll p[],ll x){return p[x]=p[x]==x?x:fat(p,p[x]);}
ll join(ll p[],ll h[],ll a,ll b){
   a=fat(p,a); b=fat(p,b);|
   if(a==b) return 0;
   if(h[a]<h[b]) swap(a,b);
   h[a]+=h[b]; h[b]=0; p[b]=a;
   return 1;
}
void dsu(ll p[],ll h[],ll n){for(ll i=0; i<=n; i++){p[i]=i; h[i]=1;}}
