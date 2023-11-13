#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = (int)2e5+2, M = (int)2e5+2;

int n, m;
pair<int,int> a[N];
struct three{int a, b, c; three(int _a=0,int _b=0,int _c=0):a(_a),b(_b),c(_c){}};
vector<three> q;
int ans[M];

struct Treap
{
    struct node
    {
        int v, id, k, s;
        node* ch[2];
        node(int _v = 0, int _i = 0) : v(_v),id(_i),k(rand()),s(1) {ch[0] = ch[1] = NULL;} 
    };

    typedef node* tree;
    tree null, root;
    Treap(){null = new node(0, 0); null->s = 0; null->ch[0] = null->ch[1] = null; root = null;}
    
    inline void pushup(tree& p) {p->s = p->ch[0]->s+p->ch[1]->s+1;}
    inline void pre(tree& p) {p->ch[0] = p->ch[1] = null;}
    inline void rot(tree& p, bool d)
    {
        tree tmp = p->ch[d];
        p->ch[d] = tmp->ch[d^1]; pushup(p);
        tmp->ch[d^1] = p; pushup(tmp);
        p = tmp;
    }

    void insert(int val, int id, tree& p)
    {
        if(p == null)
        {
            p = new node(val, id);
            pre(p);
        }
        else
        {
            p->s++;
            bool d = id>p->id;
            insert(val, id, p->ch[d]);
            if(p->k < p->ch[d]->k) rot(p, d);
        }
    }
    
    int Search(int rk, tree& p)
    {
        int S = p->ch[0]->s+1;
        if(S == rk) return p->v;
        else if(S > rk) return Search(rk, p->ch[0]);
        else return Search(rk-S, p->ch[1]);
    }
    
    inline void ins(int val, int id) {insert(val, id, root);}
    inline int search(int rk) {return Search(rk, root);}
}T;

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}

inline bool cmp(pair<int,int> a, pair<int,int> b) {return a.first==b.first? a.second<b.second:a.first>b.first;}
inline bool cmp2(three a, three b) {return a.a<b.a;}

int main()
{
    srand(time(NULL));
    n = read();
    for(int i = 1; i <= n; ++i) a[i].first = read(), a[i].second = i;
    sort(a+1,a+1+n,cmp);
    m = read();
    for(int i = 1; i <= m; ++i) q.push_back({(int)read(),(int)read(),i});
    sort(q.begin(),q.end(),cmp2);
    for(int i = 1; i <= n; ++i)
    {
        T.ins(a[i].first, a[i].second);
        while(!q.empty() && q.begin()->a == i)
        {
            ans[q.begin()->c] = T.search(q.begin()->b);
            q.erase(q.begin());
        }
        if(q.empty()) break;
    }
    for(int i = 1; i <= m; ++i) printf("%d\n",ans[i]);
    return 0;
}