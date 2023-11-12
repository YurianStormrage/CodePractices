#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char day[10];
int d[2];
void getday(int k){
  if(day[0]=='m') d[k]=1;
  else if(day[0]=='t'){
    if(day[1]=='u') d[k]=2;
	else d[k]=4;
  }
  else if(day[0]=='w') d[k]=3;
  else if(day[0]=='f') d[k]=5;
  else if(day[1]=='a') d[k]=6;
  else d[k]=7;
}
inline bool check(int x,int y){
  if((x+3)%6==y||(x+2)%6==y||x==y) return 1;
  return 0;
}
int main()
{
  scanf("%s",day);
  getday(0); d[0]--;
  scanf("%s",day);
  getday(1); d[1]--;
  if(check(d[0],d[1]))printf("YES");
  else printf("NO");
  return 0;
}
