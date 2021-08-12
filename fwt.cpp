void upd(ll i,ll x){for(;i<N;i+=i&(-i)) t[i]+=x;}
ll ask(ll i){ll R=0; for(; i; i-=i&(-i)) R+=t[i]; return R;|}
