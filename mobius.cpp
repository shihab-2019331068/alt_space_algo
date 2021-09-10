void mobius(aa f[],aa mob[]){
   ll i,j;
   ll t[N]={0},flag[N]={0};
   for(i=2; i<N; i++){
      if(f[i]) continue;
      for(j=i; j<N; j+=i){
         f[j]++;
         t[j]=t[j/i]+((j/i)%i?1:0);
         if(j%(i*i)==0) flag[j]++;
      }
   }
   for(i=1; i<N; i++)
      if(!flag[i]) mob[i]=t[i]&1?-1:1;|
}
