#include <cstdio>
int n;
int x,now,ans;
int main()
{
  freopen("block.in","r",stdin);
  freopen("block.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x>now) ans+=x-now;
	now=x;
  }
  printf("%d",ans);
  return 0;
}
//由题意可知本题求区间数量
//第i楼房高度x的解析过程如下：
//now表示延续到i的区间的数量
//所以第i栋楼需要额外搭(x-now)层（即新开x-now个新的区间）
//此时考虑区间延续问题
//①x>now 新开了可以延续的区间 => now=now+(x-now)=x;
//②x<now now中保存的区间有(now-x)个到无法延续了 => now=now-(now-x)=x;
//③x=now 可延续区间数不变 => now=now=x;
//综上所述，每次更新ans值后都把x赋值到now即可保证正确性
