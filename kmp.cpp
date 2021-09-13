void mlps(string &t,vector<ll> &p){
   ll i,j,tz=t.size();
   for(j=0,i=1; i<tz; i++){
      if(t[j]==t[i]) p[i]=++j;
      else if(j){
         j=p[j-1]; i--;
      }
      else p[i]=0;
   }
}

ll kmp(string &s,string &t){
   ll tz=t.size(), sz=s.size();
   if(!tz) return 0;
   vector<ll> p(tz,0);
   mlps(t,p);
   ll i,j;
   for(i=j=0; i<sz and j<tz; ){
      if(s[i]==t[j]){
         i++; j++;
      }
      if(j==tz) return i-j;
      if(i<sz and s[i]!=t[j]){
         j?j=p[j-1]:i++;
      }
   }
   return sz;|
}
