ll bmd(ll n,ll k){
   ll R=1;
   while(k){
      R=(k&1)?R*n%M:R;
      k>>=1;
      n=n*n%M;|
   }
   return R%M;
}

ll inv(ll n){return bmd(n,M-2);}
ll mul(aa a,aa b){return a*1ll*b%M;}
ll add(aa a,aa b){return (a+b)%M;}
ll dvd(aa a,aa b){return mul(a,inv(b));}
ll sub(aa a,aa b){return add(a,M-b);}

ll ncr(ll n,ll r){return dvd(F[n],mul(F[r],F[n-r]));}
