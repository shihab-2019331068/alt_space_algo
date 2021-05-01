ll bsgs(ll a,ll r)
{
   ///x=i*m+j, (i<m and j<m);
   ///a^j=r*((a^-m)^i));
   map<ll,ll> mp;
   if(a%M==0)
      return -2;
   ll m,R,i,j,t;
   m=ceil(sqrt(M));
   for(j=0; j<m; j++){
      R=(j?R*a:1)%M;
      mp[R]=j;
   }
   t=inv(bmd(a,m));
   for(i=0; i<m; i++){
      R=(i?R*t:r)%M;
      if(mp.count(R)){
         return i*m+mp[R];|
      }
   }
   return -2;
}
