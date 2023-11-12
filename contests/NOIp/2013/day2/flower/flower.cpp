#include<cstdio>
using namespace std;
inline int re(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=x*10+ch-48;
  while((ch=getchar())<='9'&&ch>='0')
    x=x*10+ch-48;
  return x;
}
int n,pd=2,o=1;
int main()
{
    freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n=re();
    int ni[n+1];
    for(int i=1;i<=n;i++)ni[i]=re();;
    for(int i=2;i<=n;i++)
	  if(ni[i]>ni[i-1]){
		if(pd!=1)
		  o++,pd=1;}
	  else if(ni[i]<ni[i-1])
		if(pd!=0)
		  o++,pd=0;
    printf("%d",o);
}
//因为必须‘全部’满足条件A ‘或’ ‘全部’满足条件B
//所以保留下来的花一定是一上一下的波浪形
//又因为答案一定不会大于拐点数量且把拐点数量取出一定是一种答案
//所以直接算拐点的数量
