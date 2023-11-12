#include <cstdio>
#include <cstring>
char s[100],m[1000],ans[1000];
int lens,lenm;
int main()
{
  freopen("vigenere.in","r",stdin);
  freopen("vigenere.out","w",stdout);
  scanf("%s%s",s,m);
  lens=strlen(s); lenm=strlen(m);
  for(int i=0,j=0,ks,km;i<lenm;i++,j=(j+1)%lens){
    if(m[i]>='A'&&m[i]<='Z')km='A';
	else km='a';
    if(s[j]>='A'&&s[j]<='Z')ks='A';
	else ks='a';
	ans[i]=m[i]-s[j]+ks;
	if(ans[i]<km)ans[i]+=26;
  }
  printf("%s",ans);
  return 0;
}
