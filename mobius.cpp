void mobius(aa f[],aa mob[]){
   ll i,j;
   for(i=2; i<N; i++){
      if(f[i])
         continue;
      for(j=i; j<N; j+=i){
         f[j]++;
         if(j>i and f[j]==1) continue;
         mob[j]=f[j]&1?-1:1;|
      }
   }
}
