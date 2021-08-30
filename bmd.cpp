ll bmd(ll n,ll k){
   if(!k)
      return 1;
   if(k%2)
      return (n*bmd(n,k-1))%M;
   ll R=bmd(n,k/2);
   return (R*R)%M;
}
