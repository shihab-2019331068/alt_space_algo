void scc(ll u,ll p)
{
   d[u]=++D;
   for(auto [i,v]:g[u]){
      if(v==p) continue;
      if(d[v]==-1) scc(v,u);
      d[u]=min(d[u],d[v]);
   }
}
