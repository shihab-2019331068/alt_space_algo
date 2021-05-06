void fws()
{
   ll i,j,k;
   for(k=0; k<n; k++){
      for(i=0; i<n; i++){
         for(j=0; j<n; j++){
            if(max(d[i][k],d[k][j])==inf)
               continue;
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);|
         }
      }
   }
}
