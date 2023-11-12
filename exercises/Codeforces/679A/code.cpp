#include <cstdio>
#include <cstring>
int main()
{
	char s[3];
	int cnt = 0, prm[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
	for(int i=0;i<19;++i)
	{
		printf("%d",prm[i]);
		fflush(stdout);
		scanf("%s",s);
		if(!strcmp(s,"yes")) ++cnt;
	}
	if(cnt>=2) puts("composite");
	else puts("prime");
	fflush(stdout);
	return 0;
}