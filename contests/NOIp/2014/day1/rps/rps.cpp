#include <cstdio>
int list[10][10];
const int maxn=205;
int n,na,nb;
int s1[maxn],s2[maxn];
int ans1,ans2;
inline void makelist(){
  list[0][1]=list[2][0]=list[3][1]=list[3][0]=list[4][2]=list[0][4]=list[1][2]=list[1][4]=list[2][3]=list[4][3]=-1;
  list[1][0]=list[0][2]=list[1][3]=list[0][3]=list[2][4]=list[4][0]=list[2][1]=list[4][1]=list[3][2]=list[3][4]=1;
}
int main()
{
  freopen("rps.in","r",stdin);
  freopen("rps.out","w",stdout);
  scanf("%d%d%d",&n,&na,&nb);
  for(int i=0;i<na;i++)
    scanf("%d",&s1[i]);
  for(int i=0;i<nb;i++)
    scanf("%d",&s2[i]);
  makelist();
  for(int i=0,k;i<n;i++){
    k=list[s1[i%na]][s2[i%nb]];
	if(k==1)ans1++;
	else if(k==-1)ans2++;
  }
  printf("%d %d",ans1,ans2);
  return 0;
}
