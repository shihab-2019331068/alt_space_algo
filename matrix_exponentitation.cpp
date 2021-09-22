void matMul(aa R[2][2],aa a[2][2],aa b[2][2]){
   ll i,j,k;
   ll R1[2][2];|
   memset(R1,0,sizeof(R1));
   for(i=0; i<2; i++)
      for(j=0; j<2; j++)
         for(k=0; k<2; k++)
            R1[i][k]=add(R1[i][k],mul(a[i][j],b[j][k]));
   memcpy(R,R1,sizeof(R1));
}

void matExp(aa R[2][2],aa a[2][2],ll k){
   R[0][0]=R[1][1]=1; R[0][1]=R[1][0]=0;
   for(; k; k>>=1){
      if(k&1) matMul(R,R,a);
      matMul(a,a,a);
   }
}
