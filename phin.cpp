void phin()
{
   ll i,j;
   for(i=1; i<N; i++)
      P[i]=i;
   for(i=2; i<N; i++){
      if(P[i]!=i)
         continue;
      for(j=i; j<N; j+=i)
         P[j]-=P[j]/i;|
   }
}
