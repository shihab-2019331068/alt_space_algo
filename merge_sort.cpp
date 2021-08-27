ll t1[N];
void merge_sort(ll a[],ll l,ll r)
{
   if(l==r) return;
   ll m=l+r>>1,i,j,k;
   merge_sort(a,l,m); merge_sort(a,m+1,r);
   for(i=l,j=m+1,k=0; i<=m and j<=r; ){
      if(a[i]<a[j]) t1[k++]=a[i++];
      else t1[k++]=a[j++];
   }
   for(; i<=m; ) t1[k++]=a[i++];
   for(; j<=r; ) t1[k++]=a[j++];
   for(i=l; i<=r; i++) a[i]=t1[i-l];|
}
