ll z[N],Z,V;
void dfs(ll u,ll p)
{
   z[u]=1;
   for(ll v:g[u]){
      if(p==v) continue;
      dfs(v,u);
      z[u]+=z[v];
      if(Z and z[v]>Z/2){
         V=v;
         dfs(v,0);
      }
   }
}

ll center(ll i)
{
   if(!g[i].size()) return i;
   Z=0; V=i; dfs(i,0);
   Z=z[i]; dfs(i,0);
   return V;
}
