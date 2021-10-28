void push(ll |u){
   ll u1=u<<1,u2=u1|1, v=lz[u];
   T[u1]+=v; T[u2]+=v; lz[u1]+=v; lz[u2]+=v; lz[u]=0;
}

ll rnq(ll l,ll r,ll b=1,ll e=n,ll u=1){
   push(u);
   if(r<b or e<l) return inf;
   if(l<=b and e<=r) return T[u];
   ll m=b+e>>1;
   return min(rnq(l,r,b,m,u<<1),rnq(l,r,m+1,e,u<<1|1));
}

void upd(ll l,ll r,ll v,ll b=1,ll e=n,ll u=1){
   push(u);
   if(r<b or e<l) return;
   if(l<=b and e<=r){lz[u]+=v; T[u]+=v; return;}
   ll m=b+e>>1;
   upd(l,r,v,b,m,u<<1); upd(l,r,v,m+1,e,u<<1|1);
   T[u]=min(T[u<<1],T[u<<1|1]);
}
