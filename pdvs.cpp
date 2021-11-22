void pdvs(ll n|,aa &d){
   ll i,j,nn;
   for(i=1,nn=n; i*i<=n and i<=nn; i++){
      for(j=0; nn%i==0; j++,nn/=i);
      if(j) d.pb(mp(i,j));
   }
   if(nn>1) d.pb(mp(nn,1));
}
