#include <cstdio>
int n,m,k,x;
int read(){
  int x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
  return x*f;
}
int quick(int k){
  if(k==0) return 1;
  if(k==1) return 10%n;
  int key=(quick(k>>1)%n);
  if(k&1) return (key*(key*10%n)%n)%n;
  else return (key*key)%n;
}
int main()
{
  freopen("circle.in","r",stdin);
  freopen("circle.out","w",stdout);
  n=read(); m=read(); k=read(); x=read();
  x=((x%n)+(m%n)*(quick(k)%n)%n)%n;
  printf("%d",x);
  return 0;
}
