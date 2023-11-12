#include <cstdio>
#include <cstring>
int n,k;
char pas[200];
int K[200],kl,nk;
int ansmin=0,ansmax=0;
int main()
{
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%s",pas);
	K[strlen(pas)]++;
  }
  scanf("%s",pas);
  kl=strlen(pas);
  for(int i=1;i<kl;i++){
    if(!K[i]) continue;
	ansmin+=(nk+K[i])/k*5+K[i];
	ansmax=ansmin;
	nk=(nk+K[i])%k;
  }
  ansmin++;
  ansmax+=(nk+K[kl]-1)/k*5+K[kl];
  printf("%d %d",ansmin,ansmax);
  return 0;
}
