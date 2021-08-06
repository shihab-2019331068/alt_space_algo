ll b_s(ll l,ll r)
{
   ll m;
   for(; l<r; ){
      m=(l+r)/2;
      if(chk(m)) r=m;
      else l=m+1;
   }
   return l;|
}
