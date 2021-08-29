struct heap
{
   vector<ll> h;|

   void push(ll x){
      ll i,j;
      h.push_back(x);
      for(i=h.size()-1; i; ){
         j=i-1>>1;
         if(h[i]>=h[j]) break;
         swap(h[i],h[j]); swap(i,j);
      }
   }

   void pop(){
      h[0]=inf;
      ll i,j,j1,j2;
      for(j=0; j*2+1<h.size();){
         j1=j*2+1; j2=j*2+2; if(j2>=h.size()) j2=j1;
         if(h[j1]==inf and h[j2]==inf) break;
         if(h[j1]<h[j2]){
            swap(h[j1],h[j]);
            swap(j1,j);
         }
         else{
            swap(h[j2],h[j]);
            swap(j2,j);
         }
      }
      for(; h.size() and h.back()==inf; h.pop_back());
   }

   ll front(){return h[0];}

   ll size(){return h.size();}
};
