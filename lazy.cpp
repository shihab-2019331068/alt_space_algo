void push(ll u,ll b,ll e){
   T[u]+=L[u];
   if(b^e) L[u<<1]+=L[u], L[u<<1|1]+=L[u];
   L[u]=0;
}

ll rnq(ll l,ll r,ll u=1,ll b=1,ll e=m-1){
   push(u,b,e);
   if(r<b or e<l) return inf;
   if(l<=b and e<=r) return T[u];
   ll m=b+e>>1;
   return min(rnq(l,r,u<<1,b,m),rnq(l,r,u<<1|1,m+1,e));
}

void upd(ll l,ll r,ll v,ll u=1,ll b=1,ll e=m-1){
   push(u,b,e);
   if(r<b or e<l) return;
   if(l<=b and e<=r){L[u]+=v; push(u,b,e); return;}
   ll m=b+e>>1;
   upd(l,r,v,u<<1,b,m); upd(l,r,v,u<<1|1,m+1,e);
   T[u]=min(T[u<<1],T[u<<1|1]);
}
