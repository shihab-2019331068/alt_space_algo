void dfs1(ll u)
{
   vs[u]++;
   for(ll v:g[u])
      if(!vs[v])
         dfs1(v);
   sk.push_back(u);
}

void dfs2(ll u,ll D)
{
   vs[u]++;
   d[u]=D;
   for(ll v:rg[u])
      if(!vs[v])
         dfs2(v,D);
}

void ksrj()
{
   ll i,u;
   sk={};
   vs.assign(n+1,0);
   for(i=1; i<=n; i++)
      if(!vs[i])
         dfs1(i);
   vs.assign(n+1,0); d=vs;
   for(; sk.size(); sk.pop_back()){
      u=sk.back();
      if(!vs[u])
         dfs2(u,u);|
   }
}
