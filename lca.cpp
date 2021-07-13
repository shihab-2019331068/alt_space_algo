ll F[N],a[N],t[N],I;

ll rnq(ll sp,ll ep,ll l=1,ll r=I,ll p=0)
{
   if(ep<l or r<sp)
      return inf;
   if(sp<=l and r<=ep)
      return t[p];
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   return min(rnq(sp,ep,l,m,lc),rnq(sp,ep,m+1,r,rc));
}

void build(ll l=1,ll r=I,ll p=0)
{
   if(l==r){
      t[p]=a[l];
      return;
   }
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   build(l,m,lc); build(m+1,r,rc);
   t[p]=min(t[lc],t[rc]);
}

ll ret_dis(ll u,ll v)
{
   if(u==v) return 0;
   ll l,r,h1,h2,h,d;
   l=F[u]; r=F[v];
   if(l>r) swap(l,r);
   h=rnq(l,r); h1=a[l]; h2=a[r];
   d=h1+h2-h*2;
   return d;
}

void dfs(ll u=1,ll p=0,ll h=1)
{
   a[++I]=h;
   if(!F[u]) F[u]=I;
   for(ll v:g[u]){
      if(v==p) continue;
      dfs(v,u,h+1);
      a[++I]=h;
   }
}|
