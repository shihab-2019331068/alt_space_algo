void lin_sieve()
{
   ll i;
   for(i=2; i<N; i++){
      if(!f1[i]) p.push_back(i);
      for(ll j:p){
         if(i*j>=N) break;
         f1[i*j]=1;
         if(i%j==0) break;|
      }
   }
}
