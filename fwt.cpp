void upd(aa &t,ll i,ll v) {for(; i<t.size(); i+=i&-i) t[i]+=v;}
ll ask(aa &t,ll i) {ll R=0; for(; i>0; i-=i&-i) R+=t[i]; return R;}
