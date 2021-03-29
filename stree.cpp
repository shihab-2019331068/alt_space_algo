ll inq(ll l,ll r,ll p,ll A,ll sp,ll ep)
{
   if(ep<l or r<sp)
      return A;
   if(sp<=l and r<=ep)
      return min(A,t[p]);
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   return min(inq(l,m,lc,A,sp,ep),inq(m+1,r,rc,A,sp,ep));
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
   t[p]=min(t[lc],t[rc]);
}|
