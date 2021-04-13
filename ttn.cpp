vector<ll> ttn(vector<ll> &a)
{
   bitset<N> t=1;
   vector<ll> A;
   ll i;
   for(ll i:a)
      t|=(t<<i);
   for(i=0; i<N; i++)
      if(t[i])
         A.push_back(i);
   return A;
}
