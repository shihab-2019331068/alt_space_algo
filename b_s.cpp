ll b_s(ll l,ll r)
{
   ll m;
   m=(l+r)/2;
   if(chk(m))
      return b_s(l,m);
   return b_s(m+1,r);
}
