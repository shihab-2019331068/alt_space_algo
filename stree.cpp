ll rnq(ll sp,ll ep,ll l=1,ll r=n,ll p=0)
{
   if(ep<l or r<sp)
      return 0;
   if(sp<=l and r<=ep)
      return t[p];
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   return rnq(sp,ep,l,m,lc)+rnq(sp,ep,m+1,r,rc);
}

void upd(ll i,ll v,ll l=1,ll r=n,ll p=0)
{
   if(i<l or r<i)
      return;
   if(l==r and r==i){
      t[p]=a[l]=v;
      return;
   }
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   upd(i,v,l,m,lc); upd(i,v,m+1,r,rc);
   t[p]=t[lc]+t[rc];
}

void build(ll l=1,ll r=n,ll p=0)
{
   if(l==r){
      t[p]=a[l];
      return;
   }
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   build(l,m,lc); build(m+1,r,rc);
   t[p]=t[lc]+t[rc];
}
|
