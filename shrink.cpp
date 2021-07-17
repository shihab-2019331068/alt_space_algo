void shrink(vector<pll> &p)
{
   auto t=p; p={};
   map<ll,ll> X,Y;
   sort(all(t));
   for(auto [x,y]:t){
      if(!X.count(x))
         X[x]=X.size()+1;
      p.push_back({y,X[x]});
   }
   t=p; p={};
   sort(all(t));
   for(auto [y,x]:t){
      if(!Y.count(y))
         Y[y]=Y.size()+1;
      p.push_back({x,Y[y]});
   }
   sort(all(p));|
}
