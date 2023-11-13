#include<bits/stdc++.h>
#define rint register int
#define rep(i,a,n) for(rint i=(a);i<=(n);i++)
#define repv(i,n,a) for(rint i=(n);i>=(a);i--)
#define ll long long
#define inf 0x3f3f3f3f
#define abs(x) ((x)>0? (x):-(x))
#define maxn 15
using namespace std;
inline ll read(){
    ll s=0,f=1; char c=getchar();
    while(c<'0'||c>'9') f*=c=='-'?-1:1,c=getchar();
    while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return s*f;
}
int n,k,len,sum,cnt;
vector<int> v[maxn];
int main(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    n=read(),k=read();
    rep(i,1,n){
        int t=read();
        rep(j,1,t) v[i].push_back(read());
        rep(j,t+1,20) v[i].push_back(50);
    }
    rep(i,0,19) rep(j,1,n){
        if(cnt>=k||v[j][i]==50) return cout<<sum+(k-cnt)*50,0;
        if(v[j][i]<sum) continue;
        sum+=v[j][i];
        cnt++;
    }
    return 0;
}
