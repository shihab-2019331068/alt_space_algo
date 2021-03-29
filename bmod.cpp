ll bmod(ll n,ll k)
{
   if(!k)
      return 1;
   if(k%2)
      return (n*bmod(n,k-1))%M;
   ll R=bmod(n,k/2);
   return (R*R)%M;
}
