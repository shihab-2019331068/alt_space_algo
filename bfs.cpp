void bfs(ll u)
{
   q.push(u);
   d.assign(n+1,inf);
   in.assign(n+1,0);
   for(d[u]=0; q.size(); q.pop()){
      u=q.front();
      for(ll v:g[u]){
         if(d[u]+1>=d[v])
            continue;
         d[v]=d[u]+1;
         if(!in[v]){
            q.push(v); in[v]++;
         }
      }
   }
}|
