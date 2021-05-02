void scc(ll u=1,ll p=-1,ll D=0)
{
   d[u]=D;
   for(auto [i,v]:g[u]){
      if(v==p)
         continue;
      if(d[v]==-1)
         scc(v,u,D+1);
      if(d[v]>D){
         A.push_back({u,v});
         A.push_back({v,u});
      }
      else if(f[i]){
         f[i]=0;
         A.push_back({u,v});
      }
      d[u]=min(d[u],d[v]);|
   }
}
