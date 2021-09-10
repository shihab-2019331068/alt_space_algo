void sieve(aa f[],aa &p){
   ll i,j;
   for(i=2; i<N; i++){
      if(f[i])
         continue;
      p.push_back(i);
      for(j=i; j<N; j+=i)
         f[j]++;|
   }
}
