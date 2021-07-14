void upd(ll i,ll x){for(;i<N;i+=i&(-i)) t[i]+=x;}
void ask(ll i){for(ll R=0; i; i-=i&(-i)) R+=t[i]; return R;}|
