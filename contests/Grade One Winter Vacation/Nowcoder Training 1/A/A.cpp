#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2;
char a[N], b[N];
int main()
{
    while(scanf("%s%s", a, b) != EOF)
    {
        int f;
        char *p, *q;
        if(strlen(a) > strlen(b)) p = a, q = b, f = 1;
        else p = b, q = a, f = -1;
        int lenp = strlen(p), lenq = strlen(q);
        int flag = 0;
        int pt = 0;
        for(int t = 1; t <= 2; ++t)
        {
            for(int i = 0; i < lenp; ++i)
            {
                if(p[i] > q[pt])
                {
                    flag = 1;
                    break;
                }
                else if (p[i] < q[pt])
                {
                    flag = -1;
                    break;
                }
                else
                {
                    if(++pt == lenq) pt = 0;
                }
            }
            if(flag) break;
        }
        if(!flag) printf("=\n");
        else if(flag*f == 1) printf(">\n");
        else printf("<\n");
    }
    return 0;
}