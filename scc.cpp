void scc(ll u,ll p,ll D)
{
   d[u]=D;
   for(auto [i,v]:g[u]){
      if(v==p)
         continue;
      if(d[v]==-1)
         scc(v,u,D+1);
      d[u]=min(d[u],d[v]);|
   }
}
