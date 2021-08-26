void dfs(ll u,ll P,aa &g,aa &vs,aa &p,aa &sk)
{
   vs[u]++; p[u]=P;
   for(ll v:g[u])
      if(!vs[v])
         dfs(v,P,g,vs,p,sk);
   if(P==-1) sk.push_back(u);
}

vll ksrj(ll n,aa &g,aa &rg)
{
   ll i,u;
   vector<ll> sk,vs(n+1,0),p(n+1,0);
   for(i=1; i<=n; i++)
      if(!vs[i])
         dfs(i,-1,g,vs,p,sk);
   p=vs=vll(n+1,0);
   for(; sk.size(); sk.pop_back()){
      u=sk.back();
      if(!vs[u])
         dfs(u,u,rg,vs,p,sk);
   }
   return p;|
}
