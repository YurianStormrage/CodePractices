#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 200005
#define ll long long
int T[maxn*20],L[maxn*20],R[maxn*20],sum[maxn*20],tot;
ll b[maxn];
struct node{
    int pos,num;
    bool operator <(const node &w)const{
        if(num==w.num)return pos<w.pos;
        return num>w.num;
    }
}a[maxn];
inline int update(int pre,int l,int r,int x)
{
    int rt=++tot;
    L[rt]=L[pre];
    R[rt]=R[pre];
    sum[rt]=sum[pre]+1;
    if(l<r)
    {
        int mid=(l+r)>>1;
        if(x<=mid)L[rt]=update(L[pre],l,mid,x);
        else R[rt]=update(R[pre],mid+1,r,x);
    }
    return rt;
}
inline int query(int u,int v,int l,int r,int k)
{
    if(l>=r)return l;
    int x=sum[L[v]]-sum[L[u]],mid=(l+r)>>1;
    if(x>=k)return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-x);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].num);
        a[i].pos=i;
    }
    sort(a+1,a+1+n);
    int len=n;
    tot=0;
    for(int i=1;i<=n;i++)
    {
        b[a[i].pos]=a[i].num;
        T[i]=update(T[i-1],1,len,a[i].pos);
    }
    int k,p;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&k,&p);
        printf("%d\n",b[query(T[0],T[k],1,len,p)]);
    }
    return 0;
}