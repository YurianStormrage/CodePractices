#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
int n;
int one,two,ans;
priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
  n=re();
  for(int i=1,x;i<=n;i++){
    x=re();
	Q.push(x);
  }
  while(true){
    one=Q.top(); Q.pop();
	if(Q.empty())break;
	two=Q.top(); Q.pop();
	ans+=one+two;
	Q.push(one+two);
  }
  printf("%d",ans);
}
