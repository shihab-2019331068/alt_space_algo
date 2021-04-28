void dijkstra(ll u,ll z)
{
   set<pair<ll,ll>> s;
   d.assign(z,inf); d[u]=0;
   for(s={{0,u}}; s.size(); ){
      auto [ul,u]=*s.begin();
      s.erase(s.begin());
      for(auto [w,v]:g[u]){
         if(d[v]>d[u]+w){
            d[v]=d[u]+w;
            s.insert({d[v],v});
         }
      }
   }
}
