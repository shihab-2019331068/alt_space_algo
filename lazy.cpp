ll rnq(ll l,ll r,ll b=1,ll e=n,ll u=1){
   if(r<b or e<l) return inf;|
   if(l<=b and e<=r) return T[u];
   ll m=b+e>>1;
   return min(rnq(l,r,b,m,u<<1),rnq(l,r,m+1,e,u<<1|1))+lz[u];
}

void upd(ll l,ll r,ll v,ll b=1,ll e=n,ll u=1){
   if(r<b or e<l) return;
   if(l<=b and e<=r){lz[u]+=v; T[u]+=v; return;}
   ll m=b+e>>1;
   upd(l,r,v,b,m,u<<1); upd(l,r,v,m+1,e,u<<1|1);
   T[u]=min(T[u<<1],T[u<<1|1])+lz[u];
}
