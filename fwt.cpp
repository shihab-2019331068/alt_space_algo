ll lwb(ll x)
{
   return (x&(-x));
}

void upd(ll x,ll v)
{
   if(x>=n)
      return;
   t[x]+=v;
   upd(x+lwb(x),v);|
}
