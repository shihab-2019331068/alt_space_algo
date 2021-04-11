ll bmd(ll n,ll k)
{
   if(!k)
      return 1;
   if(k%2)
      return (n*bmd(n,k-1))%M;
   ll R=bmd(n,k/2);
   return (R*R)%M;
}

ll m_inv(ll x)
{
   return bmd(x,M-2);
}

ll ncr(ll n,ll r)
{
   return F[n]*m_inv(F[r]*F[n-r]%M)%M;
}
