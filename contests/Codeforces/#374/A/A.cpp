#include <cstdio>
const int maxn=105;
int n;
char c;
int ansn,ans[maxn];
int main()
{
  scanf("%d\n",&n);
  for(int i=1,flag=0;i<=n;i++){
    scanf("%c",&c);
	if(c=='B'){
	  if(!flag)ans[0]++,flag=1;
	  ans[ans[0]]++;
	}
	else flag=0;
  }
  printf("%d\n",ans[0]);
  for(int i=1;i<=ans[0];i++)
    printf("%d ",ans[i]);
}
