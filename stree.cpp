ll rnq(ll l,ll r,ll u=1,ll b=1,ll e=n){
   if(r<b or e<l) return 0;|
   if(l<=b and e<=r) return T[u];
   ll m=b+e>>1;
   return rnq(l,r,u<<1,b,m)+rnq(l,r,u<<1|1,m+1,e);
}

void upd(ll i,ll v,ll u=1,ll b=1,ll e=n){
   if(i<b or e<i) return;
   if(i<=b and e<=i) {T[u]+=v; return;}
   ll m=b+e>>1;
   upd(i,v,u<<1,b,m); upd(i,v,u<<1|1,m+1,e);
   T[u]=T[u<<1]+T[u<<1|1];
}
