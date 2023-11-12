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
const int maxn=10005;
int n;
int one,two,ans;

struct minHeap{
  int key[maxn],size;
  minHeap(){for(int i=1;i<=n;i++)key[i]=0;size=0;}
  
  void update_up(int s){
    int f=s>>1,x=key[s];
	while(f){
	  if(key[f]<=x) break;
	  key[s]=key[f];
	  s=f; f>>=1;
	}
	key[s]=x;
  }
  void push(int x){
    key[++size]=x;
	update_up(size);
  }
  
  void update_down(int f){
    int a=f<<1,x=key[f];
	while(a<=size){
	  if(size>a&&key[a]>key[a+1])a++;
	  if(x<=key[a])break;
	  key[f]=key[a];
	  f=a; a<<=1;
	}
	key[f]=x;
  }
  void makeheap(int *f,int len){
    for(int i=1;i<=len;i++) key[i]=f[i];
	size=len;
    for(int i=n>>1;i>=1;i--)
	  update_down(i);
  }
  void pop(){
    key[1]=key[size--];
	update_down(1);
  }
  
  inline int top(){return key[1];}
}H;

int main()
{
  n=re();
  if(n==1) {printf("0");return 0;}
  for(int i=1,x;i<=n;i++){
    x=re();
	H.push(x);
  }
  while(true){
    one=H.top(); H.pop();
	if(!H.size)break;
	two=H.top(); H.pop();
	ans+=one+two;
	H.push(one+two);
  }
  printf("%d",ans);
}
