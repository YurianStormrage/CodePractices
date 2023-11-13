#include<bits/stdc++.h>
#define rint register int
#define rep(i,a,n) for(rint i=(a);i<=(n);i++)
#define repv(i,n,a) for(rint i=(n);i>=(a);i--)
#define ll long long
#define inf 0x3f3f3f3f
#define abs(x) ((x)>0? (x):-(x))
#define maxn 1005
using namespace std;
inline int read(){
    cout<<endl,fflush(stdout);
    int res; cin>>res;
    return res;
}
int n;
bool a[maxn];
vector<int> v;
int main(){
    cin>>n;
    srand(time(0));
    do rep(i,1,n) cout<<(a[i]=rand()&1);
    while(!read());
    a[1]^=1;
    rep(i,2,n){
        a[i]^=1;
        rep(j,1,n) cout<<a[j];
        if(read()) v.push_back(i);
        a[i]^=1;
    }
    a[1]^=1;
    for(auto &x:v) a[x]^=1;
    rep(i,1,n) cout<<a[i];
    if(read()) return 0;
    rep(i,1,n) cout<<!a[i];
    if(read()) return 0;
    return 0;
}
