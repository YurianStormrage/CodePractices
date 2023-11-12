#include <cstdio>
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
int now,key;
int main()
{
  for(int i=1,x;i<=12;i++){
    x=re();
	now+=300;
	if(now<x){printf("%d",-i);return 0;}
	now-=x;
	key+=now/100*100;
	now-=now/100*100;
  }
  printf("%d",now+key/10*12);
}
