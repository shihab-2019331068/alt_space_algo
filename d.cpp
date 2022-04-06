ld D(ld x1,ld y1,ld x2,ld y2)
{
   x1=abs(x1-x2);
   y1=abs(y1-y2);
   return sqrt(x1*x1+y1*y1);|
}
