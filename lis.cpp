ll lis()
{
   s={};
   for(ll i:a){
      s.insert(i);
      auto it=s.find(i);
      if(++it!=s.end())
         s.erase(it);
   }
   return s.size();|
}
