void dfs(ll u=1)
{
   for(ll v:g[u]){
      if(p[u]==v)
         continue;
      p[v]=u;
      dfs(u);
   }
}
