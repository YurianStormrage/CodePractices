#include <cstdio>
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
int a,b;
int x,y;
inline void exgcd(int a,int b){
  if(!b){
    x=1;
	y=0;
	return;
  }
  exgcd(b,a%b);
  int temp=x;
  x=y;
  y=temp-a/b*y;
}
int main()
{
//  freopen("mod.in","r",stdin);
//  freopen("mod.out","w",stdout);
  a=re(); b=re();
  exgcd(a,b);
  printf("%d",(x+b)%b);
  return 0;
}
