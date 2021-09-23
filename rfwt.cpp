void upd(aa &t,ll i,ll| x){for(;i<t.size();i+=i&(-i)) t[i]+=x;}
ll ask(aa &t,ll i){ll R=0; for(; i; i-=i&(-i)) R+=t[i]; return R;}
void r_upd(aa &t1,aa &t2,ll l,ll r,ll x){
   upd(t1,l,x); upd(t1,r+1,-x);
   upd(t2,l,(l-1)*x); upd(t2,r+1,r*-x);
}
ll prefSum(aa &t1,aa &t2,ll i){return ask(t1,i)*i-ask(t2,i);}
ll r_sum(aa &t1,aa &t2,ll l,ll r){return prefSum(t1,t2,r)-prefSum(t1,t2,l-1);}
