ll rnq(ll sp,ll ep,ll B,ll l=1,ll r=n,ll p=0)
{
   if(ep<l or r<sp) return B?0:inf;
   if(sp<=l and r<=ep) return t[p];
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   if(B) return max(rnq(sp,ep,B,l,m,lc),rnq(sp,ep,B,m+1,r,rc));
   return min(rnq(sp,ep,B,l,m,lc),rnq(sp,ep,B,m+1,r,rc));
}

void upd(ll i,ll v,ll l=1,ll r=n,ll p=0)
{
   if(i<l or r<i) return;
   if(l==r and r==i){
      t[0][p]=a[l]=v;
      t[1][p]=a[l]=v;
      return;
   }
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   upd(i,v,l,m,lc); upd(i,v,m+1,r,rc);
   t[0][p]=min(t[0][lc],t[0][rc]);
   t[1][p]=max(t[1][lc],t[1][rc]);
}

void build(ll l=1,ll r=n,ll p=0)
{
   if(l==r){
      t[0][p]=a[l];
      t[1][p]=a[l];
      return;
   }
   ll m,lc,rc;
   m=(l+r)/2;
   lc=p*2+1; rc=lc+1;
   build(l,m,lc); build(m+1,r,rc);
   t[0][p]=min(t[0],[lc],t[0][rc]);
   t[1][p]=max(t[1],[lc],t[1][rc]);|
}
