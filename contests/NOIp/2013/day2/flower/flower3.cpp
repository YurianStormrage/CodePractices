#include <cstdio>
inline int re(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=x*10+ch-48;
  while((ch=getchar())<='9'&&ch>='0')
    x=x*10+ch-48;
  return x;
}
const int maxn=100005;
int n,h[maxn];
int lst[maxn],nxt[maxn];
int s,t,ans=2;
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  n=re();
  for(int i=1;i<=n;i++){
    h[i]=re();
	lst[i]=i-1;
	nxt[i-1]=i;
	if(h[i]==h[i-1]) lst[i]=lst[i-1];
	nxt[lst[i]]=i;
	//此处nxt[i]不是连到i后面第一个值不相等的点的，只是保证一段连续相等区间的最后一个位置nxt值正确
  }
  s=nxt[1]; t=lst[n];
  while(h[s]==h[s+1])s++;
  while(h[t]==h[t-1])t--;
  //去头去尾避免无lst[1]和nxt[n]而WA
  for(int i=s;i<=t;i++)
    if((h[lst[i]]>h[i]&&h[nxt[i]]>h[i])||(h[lst[i]]<h[i]&&h[nxt[i]]<h[i]))
	  ans++;
  printf("%d",ans);
  return 0;
}
//因为必须‘全部’满足条件A ‘或’ ‘全部’满足条件B
//所以保留下来的花一定是一上一下的波浪形
//又因为答案一定不会大于拐点数量且把拐点数量取出一定是一种答案
//所以直接算拐点的数量
//注意h相等的点要缩点(nxt和lst数组,poj1096办公楼也用过)
//辣鸡算法毁我青春
