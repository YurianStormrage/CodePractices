#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = (int)1e9+5, M = (int)3e3+5;
int n, m, k;
int a, b, c;
ll t;
int stop[M];
int cnt, ans;
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f)
		return -x;
	return x;
}

struct Node {
	int pos, cnt, end;
	ll time;
	inline bool operator > (const &a, const &b)
		{return a.cnt<b.cnt;}
};

struct Heap {
	int size;
	Node key[N];
	Heap():size(0) {}
	inline void up(int p) {
		int fa = p>>1;
		while(key[fa]>key[p]) {
			swap(key[fa],key[p]);
			p = fa;
			fa = p>>1;
		}
	}
	inline void down(int p) {
		int ch[2] = {p<<1,(p<<1)+1};
		bool smb;
		while(ch[0]<=size) {
			if(ch[1]>size) {
				swap(key[p],key[ch[0]]);
				p = ch[0];
				break;
			}
			else {
				smb = key[ch[0]]>key[ch[1]];
				swap(key[p],key[ch[smb]]);
				p = ch[smb];
				ch[2] = {p<<1,(p<<1)+1};
			}
		}
	}
	inline void pop() {
		key[1] = key[size--];
		down(1);
	}
	inline void push(int x) {
		key[++size] = x;
		up(size);
	}
	inline bool empty() {return size==0;}
	inline Node top() {return key[1];}
}H;

inline void init() {
	n = re(); m = re(); k = re();
	a = re(); b = re(); c = re();
	scanf("%lld",&t);
	for(int i = 1; i <= m; ++i)
		stop[i] = re();
	cnt = k-m;
}

inline void addnode(int pos, int cnt, int end, ll time) {
	if(pos >= end) return;
	int to = pos+cnt-1; if(to >= end) to = end-1;
	H.push((Node){pos,to-pos+1,end,time});
}

inline void solve() {
	for(int i = 1; i < n; ++i) {
		int num = (t-(ll)(stop[i]-1)*b)/a+1;
		ans += num;
		addnode(num+stop[i],num,stop[i+1],t-(ll)(stop[i]-1)*b-(ll)num*c);
	}
	while(!H.empty() && cnt) {
		Node now = H.top();
		H.pop(); --cnt;
		ans += now.cnt;
		ll time = now.time-(ll)now.cnt*c;
		addnode(now.pos+now.cnt,time/a+1,now.end,time);
	}
	printf("%d\n",ans);
}

int main() {
	init();
	solve();
	return 0;
}