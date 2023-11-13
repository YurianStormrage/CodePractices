#include<bits/stdc++.h>
#define rint register int
#define rep(i,a,n) for(rint i=(a);i<=(n);i++)
#define repv(i,n,a) for(rint i=(n);i>=(a);i--)
#define ll long long
#define inf 0x3f3f3f3f
#define abs(x) ((x)>0? (x):-(x))
#define maxn 1005
#define maxm 3000005
using namespace std;
inline ll read(){
    ll s=0,f=1; char c=getchar();
    while(c<'0'||c>'9') f*=c=='-'?-1:1,c=getchar();
    while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return s*f;
}
struct Dijkstra{
    struct node{
        int id; double dis;
        bool operator <(const node& a) const{
            return dis>a.dis;
        }
    };
    struct edge{
        int to,nxt; double val;
    } e[maxm];
    int head[maxn],tot;
    inline void addedge(int u,int v,double w){
        e[++tot]=(edge){v,head[u],w},head[u]=tot;
        e[++tot]=(edge){u,head[v],w},head[v]=tot;
    }
    inline void dijkstra(int s,double *dis){
        priority_queue<node> q;
        dis[s]=0;
        q.push((node){s,0});
        while(!q.empty()){
            node u=q.top();
            q.pop();
            if(dis[u.id]!=u.dis) continue;
            for(int i=head[u.id];i;i=e[i].nxt){
                int v=e[i].to;
                if(dis[v]>max(u.dis,e[i].val)){
                    dis[v]=max(u.dis,e[i].val);
                    q.push((node){v,dis[v]});
                }
            }
        }
    }
} G;

struct point{
    double x,y;
    inline void init(){
        x=read(),y=read();
    }
} p[maxn],pos;
inline double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int n;
double w,dist[maxn],disr[maxn],ans=1ll<<62;
int main(){
    freopen("froggy.in","r",stdin);
    freopen("froggy.out","w",stdout);
    w=read(),n=read();
    if(!n) return printf("%.10f 0",w/2),0;
    rep(i,1,n+2) dist[i]=disr[i]=ans;
    int S=n+1,T=n+2;
    rep(i,1,n) p[i].init();
    rep(i,1,n){
        G.addedge(S,i,p[i].x);
        G.addedge(i,T,w-p[i].x);
        rep(j,i+1,n) G.addedge(i,j,dis(p[i],p[j]));
    }
    G.dijkstra(S,dist),G.dijkstra(T,disr);
    rep(i,1,n) rep(j,i+1,n){
        double tmp=min(max(dist[i],disr[j]),max(dist[j],disr[i]));
        tmp=max(tmp,dis(p[i],p[j])/2);
        if(tmp<ans) ans=tmp,pos=(point){(p[i].x+p[j].x)/2,(p[i].y+p[j].y)/2};
    }
    rep(i,1,n){
        double tmp=max(dist[i],(w-p[i].x)/2);
        if(tmp<ans) ans=tmp,pos=(point){(w+p[i].x)/2,p[i].y};
        tmp=max(p[i].x/2,disr[i]);
        if(tmp<ans) ans=tmp,pos=(point){p[i].x/2,p[i].y};
    }
    printf("%.10f %.10f",pos.x,pos.y);
    return 0;
}
