#include <cstdio>

#define Min(a,b) ((a)<(b)? (a):(b))

const int inf = (int)1e9;

int n;
int cnt[15];
int ans;

inline int calc()
{
	int ret = 0;
	int tmp[5] = {0};
	for(int i=0;i<=12;++i) tmp[cnt[i]]++;
	
	while(tmp[4])
	{
		ret++; tmp[4]--;
		if(tmp[1]>=2) tmp[1]-=2;
		else if(tmp[2]>=2) tmp[2]-=2;
	}
	while(tmp[3])
	{
		ret++; tmp[3]--;
		if(tmp[2]) tmp[2]-=1;
		else if(tmp[1]) tmp[1]-=1;
	}
	while(tmp[2]) {ret++; tmp[2]--;}
	while(tmp[1]) {ret++; tmp[1]--;}
	
	return ret+(cnt[13]!=0);
}

inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void solve(int cost)
{
	if(cost > ans) return;
	int ret = cost+calc();
	ans = Min(ret, ans);
	for(int i=0,j,k;i<=10;++i)
	{
		for(j=i;j<=11;++j)
			if(cnt[j]<3) break;
		if(j-i>=1)
		{
			for(k=i;k<=i+1;++k) cnt[k]-=3; solve(cost+1);
			for(;k<=j;++k) {cnt[k]-=3; solve(cost+1);}
			for(k=i;k<=j;++k) cnt[k]+=3;
		}
	}
	for(int i=0,j,k;i<=9;++i)
	{
		for(j=i;j<=11;++j)
			if(cnt[j]<2) break;
		if(j-i>=2)
		{
			for(k=i;k<=i+2;++k) cnt[k]-=2; solve(cost+1);
			for(;k<=j;++k) {cnt[k]-=2; solve(cost+1);}
			for(k=i;k<=j;++k) cnt[k]+=2;
		}
	}
	for(int i=0,j,k;i<=7;++i)
	{
		for(j=i;j<=11;++j)
			if(cnt[j]<1) break;
		if(j-i>=4)
		{
			for(k=i;k<=i+4;++k) cnt[k]-=1; solve(cost+1);
			for(;k<=j;++k) {cnt[k]-=1; solve(cost+1);}
			for(k=i;k<=j;++k) cnt[k]+=1;
		}
	}
}

int main()
{
	freopen("landlords.in","r",stdin);
	freopen("landlords.out","w",stdout);
	int Case = re(); n = re();
	while(Case--)
	{
		for(int i=0;i<=13;++i) cnt[i] = 0;
		for(int i=1,a;i<=n;++i)
		{
			a = re();
			if(a) cnt[(a+10)%13]++;
			else cnt[13]++;
			re();
		}
		
		ans = inf;
		solve(0);
		
		printf("%d\n",ans);
	}
	return 0;
}
