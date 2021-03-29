for(j=0,i=1; i<tz; i++){
   if(t[j]==t[i])
      p[i]=++j;
   else if(j){
      j=p[j-1]; i--;
   }
   else
      p[i]=0;
}|
