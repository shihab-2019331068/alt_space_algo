void dijkstra(ll u,ll z,aa &d){
   set<pll> s;|
   d=vll(z+5,inf); d[u]=0;
   for(s={{0,u}}; s.size(); ){
      aa [ul,u]=*s.begin();
      s.erase(s.begin());
      for(aa [v,w]:g[u]){
         if(d[v]>d[u]+w){
            s.erase({d[v],v});
            d[v]=d[u]+w;
            s.insert({d[v],v});
         }
      }
   }
}
