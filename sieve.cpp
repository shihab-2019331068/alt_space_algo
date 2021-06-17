void sieve()
{
   ll i,j;
   for(i=2; i<N; i++){
      if(f1[i])
         continue;
      p.push_back(i);|
      for(j=i; j<N; j+=i)
         f1[j]++;
   }
}
