#include <cstdio>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define repp(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define dis(a,b) abs(h[a]-h[b])
using namespace std;
typedef long long ll;
const int N = 100005, M = 100005, inf = (1<<31)-1;
int n, h[N], x0, m;
int s[M], x1[M];
ll a1, b1, ans2[N][2];
double ans1 = (double)inf;
int ans1i;
int chn[N][2];
struct node {int h,id;} nd[N];
inline bool cmpH(node a, node b) {return a.h<b.h;}
struct drive {int a,b,ax,bx;} drv[N];
struct Run {int x;ll ax,bx;} run[N][18];

inline int re(){
	int x=0,f=1;char ch;
	while((ch=getchar())>'9'||ch<'0')if(ch=='-')f=-1;
	x=ch-48;
	while((ch=getchar())>='0'&&ch<='9')x=x*10+ch-48;
	return x*f;
}

inline void operate(int x, int& a, int& b) {
	if(!chn[x][0] && !chn[x][1]) {a=0; b=0; return;}//
	bool p;
	if(!chn[x][0] || !chn[x][1]) {
		p = chn[x][0]==0;
		a = chn[x][p];
		b = chn[chn[x][p]][p];
		return;
	}
	p = dis(x,chn[x][0])>dis(x,chn[x][1]);
	a = chn[x][p];
	if(!chn[chn[x][p]][p]) b = chn[x][p^1];//
	else if(dis(x,chn[chn[x][p]][p])==dis(x,chn[x][p^1]))
		b = h[chn[chn[x][p]][p]]<h[chn[x][p^1]]? chn[chn[x][p]][p]:chn[x][p^1];
	else
		b = dis(x,chn[chn[x][p]][p])<dis(x,chn[x][p^1])? chn[chn[x][p]][p]:chn[x][p^1];
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	n = re();
	rep(i,1,n) {h[i]=re(); nd[i].h=h[i]; nd[i].id=i;}
	x0 = re(); m = re();
	rep(i,1,m) {s[i]=re(); x1[i]=re();}
	sort(nd+1,nd+1+n,cmpH);
	rep(i,2,n) {chn[nd[i].id][0]=nd[i-1].id; chn[nd[i-1].id][1]=nd[i].id;}
	
	int ai,bi;
	rep(i,1,n) {
		operate(i,bi,ai);
		drv[i].a = ai; drv[i].b = bi;
		drv[i].ax = dis(i,ai); drv[i].bx = dis(i,bi);
		if(chn[i][1]) chn[chn[i][1]][0] = chn[i][0];//The first node in list is from which we can reach any other nodes
		if(chn[i][0]) chn[chn[i][0]][1] = chn[i][1];//By deleting the first node, we can maintenance the nature
	}
	rep(i,1,n) {
		run[i][0].x = drv[drv[i].a].b;
		run[i][0].ax = drv[i].ax;
		run[i][0].bx = drv[drv[i].a].bx;//The first to go is a, the next is b
	}
	rep(i,1,17) {
		rep(j,1,n) {
			run[j][i].x = run[run[j][i-1].x][i-1].x;
			run[j][i].ax = run[run[j][i-1].x][i-1].ax+run[j][i-1].ax;
			run[j][i].bx = run[run[j][i-1].x][i-1].bx+run[j][i-1].bx;
		}
	}
	
	rep(i,1,n) {
		int p = i; ll tmp = 0;
		a1 = 0; b1 = 0;
		repp(j,17,0) {
			if(run[p][j].x) {
				if(tmp+run[p][j].ax+run[p][j].bx > x0) continue;
				tmp += run[p][j].ax+run[p][j].bx;
				a1 += run[p][j].ax;
				b1 += run[p][j].bx;
				p = run[p][j].x;
			}
		}
		if(drv[p].a && tmp+drv[p].ax <= x0) a1 += drv[p].ax;
		if(b1) 
		{
			double tmpp = (double)a1/b1;//The ratio is a float number.
			if(ans1>tmpp) {ans1=tmpp; ans1i=i;}
			else if(ans1==tmpp) {ans1i=h[i]>h[ans1i]?i:ans1i;}
		}
		else if(ans1==(double)inf) ans1i = h[i]>h[ans1i]?i:ans1i;
	}
	
	rep(i,1,m) {
		int p = s[i];
		ll tmp = 0;
		repp(j,17,0) {
			if(run[p][j].x) {
				if(tmp+run[p][j].ax+run[p][j].bx > x1[i]) continue;
				tmp += run[p][j].ax+run[p][j].bx;
				ans2[i][0] += run[p][j].ax;//*Try to use s[i] to replace i
				ans2[i][1] += run[p][j].bx;//Every query has two keys, si and xi. So it's wrong.
				p = run[p][j].x;
			}
		}
		if(drv[p].a && tmp+drv[p].ax<=x1[i]) ans2[i][0] += drv[p].ax;
	}
	
	printf("%d\n",ans1i);
	rep(i,1,m) printf("%lld %lld\n",ans2[i][0], ans2[i][1]);
	return 0;
}
