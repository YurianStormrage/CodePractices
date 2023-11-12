#include <cstdio>
#include <algorithm>
using namespace std;
inline int re(){
  int x=0,f=1;char ch;
  while((ch=getchar())>'9'||ch<'0')if(ch=='-')f=-1;
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x*f;
}
int main()
{
  
  return 0;
}
