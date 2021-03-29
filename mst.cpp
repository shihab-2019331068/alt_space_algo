void join(ll a,ll b)
{
   if(a==b)
      return;
   if(g[a].size()<g[b].size())
      swap(a,b);
   for(ll i:g[b]){
      p[i]=a;
      g[a].push_back(i);
   }
   g[b]={};
}|
