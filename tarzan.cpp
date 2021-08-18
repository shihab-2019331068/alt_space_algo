void tarzan(ll u,ll p,vll &vs,vll &et,vll &lt,vll &ap)
{
   vs[u]=1; et[u]=lt[u]=++tim;
   for(ll v:g[u]){
      if(p==v) continue;
      if(!vs[v]) tarzan(v,u,vs,et,lt,ap);
      if(et[u]<=lt[v]) ap[u]=1;
   }
   for(ll v:g[u])
      if(p!=v) lt[u]=min(lt[u],lt[v]);|
}
