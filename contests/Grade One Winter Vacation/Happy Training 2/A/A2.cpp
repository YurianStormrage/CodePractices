#include <cstdio>
#include <cstring>
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;
const int maxn = 40 + 5;
const int maxf = 100 + 5;
const int maxm = 400 + 5;

char dp[maxn][maxf][maxm];
char nm[maxn][maxm];
bool val[maxn][maxf];
int pre[maxn][maxf];
int n, m;

bool change(const char *a, const char *b, int lim, char *temp) {
    strcpy(temp, b);
    int left = lim;
    int p = 0;
    for(p=0;p<m&&left;p++) if(temp[p]!=a[p])
        temp[p] = a[p], left--;
    if(strcmp(temp, a)>=0) 
        return true;
    left = lim;
    for(--p;p>=0&&temp[p]=='9';) --p;
    if(p<0) return false;
    int pos;
    strcpy(temp, b);
    for(pos=0;pos<p;pos++) if(temp[pos]!=a[pos])
        temp[pos] = a[pos], left--;
    if(temp[p]-1 != a[p]) {
        temp[p] = a[p]+1; left --;
    }
    for(++p;p<m&&left;p++) {
        temp[p] = '0';
        if(temp[p]!=b[p]) left--;
    }
    return true;
}

void print_ans(int nn, int k) {
    if(!nn) return ;
    print_ans(nn-1, pre[nn][k]);
    printf("%s\n", dp[nn][k]);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%s", nm[i]);
    CLR(dp, 0);
    CLR(val, false);
    for(int i=0;i<m;i++)
        dp[0][0][i] = '0';
    dp[0][0][m] = '\0';
    val[0][0] = true;
    char temp[maxm];
    CLR(pre, 0);
    for(int i=0;i<n;i++) 
        for(int j=0;j<maxf;j++) if(val[i][j]) {
            for(int k=0;k<=m && k+j < maxf;k++) {
                if(change(dp[i][j], nm[i+1], k, temp) && 
                (!val[i+1][k+j] || strcmp(temp, dp[i+1][k+j]) < 0)) {
                    val[i+1][k+j] = true;
                    strcpy(dp[i+1][k+j], temp);
                    pre[i+1][k+j] = j;
                }
            }
        }
    int sign = 0;
    for(int i=0;i<maxf;i++)
        if(val[n][i]) { sign = i; break; }
    print_ans(n, sign);
}