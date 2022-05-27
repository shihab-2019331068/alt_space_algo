struct Line {
   ll m,b;
   ll operator()(ll x){return m*x+b;}
};
struct LCNode {
   Line val;
   LCNode *ls=0,*rs=0;
   LCNode(Line _val): val(_val){}

   void upd(ll l,ll r,Line val) {
      if(l+1==r) {
         if(val(l)<this->val(l)) this->val=val;
         return;
      }
      ll m=l+r>>1;
      if(val.m<this->val.m) swap(val,this->val);
      if(val(m)<this->val(m)) {
         swap(val,this->val);
         if(this->rs) this->rs->upd(m,r,val);
         else this->rs=new LCNode(val);
      } else {
         if(this->ls) this->ls->upd(l,m,val);
         else this->ls=new LCNode(val);
      }
      return;
   }
   ll rnq(ll l,ll r,ll x) {
      if(l+1==r) return this->val(x);
      ll m=l+r>>1;
      if(x<m and (this->ls)) return min(this->val(x),this->ls->rnq(l,m,x));
      if(this->rs) return min(this->val(x),this->rs->rnq(m,r,x));
      return this->val(x);
   }
};
