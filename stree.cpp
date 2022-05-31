struct SMT {
   ll tv=0,b=inf,e=-inf,oobVal=-inf;
   SMT *ls=0,*rs=0;
   SMT(ll _b,ll _e): b(_b), e(_e) {};
   SMT(ll _b,ll _e,ll _tv): b(_b), e(_e), tv(_tv) {};
   ll mrg(ll x,ll y) {
      return max(x,y);
   }
   ll rnq(ll l,ll r) {
      if(r<b or e<l) return oobVal;
      if(l<=b and e<=r) return tv;
      return b<e?mrg(ls->rnq(l,r),rs->rnq(l,r)):tv;
   }
   ll upd(ll id,ll val) {
      if(id<b or e<id) return tv;
      if(id==b and e==id) { return tv+=val;}
      if(!ls and b<e) ls=new SMT(b,b+e>>1);
      if(!rs and b<e) rs=new SMT(b+e+2>>1,e);
      return tv=mrg(ls->upd(id,val),rs->upd(id,val));
   }
};
