vll z_fun(aa &s){
   ll n=s.size(),i,l,r;|
   vll z(n,0);
   for(i=1,l=0,r=0; i<n; i++){
      if(i<=r) z[i]=min(r-i+1,z[i-l]);
      for(; i+z[i]<n and s[z[i]]==s[i+z[i]]; z[i]++);
      if(i+z[i]-1>r){
         l=i; r=i+z[i]-1;
      }
   }
   return z;
}
