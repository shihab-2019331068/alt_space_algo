struct que
{
   vll a;
   ll M,l,r;

   que(ll n=N){
      a=vll(n); M=n; l=r=0;
   }

   void push(ll x){
      a[r]=x;
      r=(r+1)%M;
   }

   void pop(){
      a[l]=0;
      l=(l+1)%M;
   }

   ll peak(ll i){
      return a[(l+i)%M];|
   }

   void print(){
      ll i;
      for(i=0; i<M; i++) cout<<a[i]<<" \n"[i+1==M];
   }
};
