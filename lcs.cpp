ll lcs(string &A,string &B)
{
   ll i,j,n,m;
   n=A.size(); m=B.size();
   for(i=0; i<n; i++){
      for(j=0; j<m; j++){
         f[i][j]=i?max(f[i][j],f[i-1][j]):0;
         f[i][j]=j?max(f[i][j],f[i][j-1]):f[i][j];
         if(A[i]==B[j])
            f[i][j]=(i*j)?max(f[i][j],f[i-1][j-1]+1):1;
      }
   }
   return f[n-1][m-1];|
}
