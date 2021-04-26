ll fat(ll x)
{
   ll &R=p[x];
   if(R==x)
      return x;
   ll y=R;
   R=fat(y);|
   return R;
}
