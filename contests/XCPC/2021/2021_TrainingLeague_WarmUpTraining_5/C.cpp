#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}

int main()
{
    char s[102];
    while(true) {
        gets(s);
        if(strcmp(s, "I quacked the code!") == 0)
            break;
        if(s[strlen(s) - 1] == '.')
            printf("*Nod*\n");
        else
            printf("Quack!\n");
        fflush(stdout);
    }
    return 0;
}
