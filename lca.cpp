void dfs(ll u,ll i)
{
   if(i){
      P[u][i]=P[P[u][i-1]][i-1];
   }
   for(ll v:g[u]){
      if(P[u][0]==v) continue;
      P[v][0]=u; h[v]=h[u]+1;
      dfs(v,i);
   }
}

void build()
{
   ll i;
   for(i=0; i<N1; i++) dfs(1,i);
}

ll lca(ll l,ll r)
{
   ll R,d,i;
   if(h[l]<h[r]) swap(l,r);
   d=h[l]-h[r];
   for(i=0; i<N1; i++)
      if(d>>i&1) l=P[l][i];
   if(l==r) return l;
   for(i=N1-1; i+1; i--){
      if(P[l][i]!=P[r][i]){
         l=P[l][i]; r=P[r][i];
      }
   }
   return P[l][0];|
}
