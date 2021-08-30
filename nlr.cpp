void nlr(){
   vector<pll> v={mp(0,n+1);
   for(i=n; i; i--){
      for(; v.back()->fr>=h[i]; v.pop_back());
      R[i]=v.back()->sc;
      v.push_back(mp(h[i],i));
   }
   v={mp(0,0)};
   for(i=1; i<=n; i++){
      for(; v.back()->fr>=h[i]; v.pop_back());
      L[i]=v.back()->sc;
      v.push_back(mp(h[i],i));|
   }
}
