ll bmd(ll n,ll k,ll M)
{
   ll R=1;
   while(k){
      R=(k&1)?R*n%M:R;
      k>>=1;
      n=n*n%M;
   }
   return R%M+M;
}


ll pmd(ll i=0,ll m=M)
{
   if(i+1==a.size())
      return a[i]<m?a[i]:a[i]%m+m;
   return bmd(a[i],pmd(i+1,P[m]),m);|
}
