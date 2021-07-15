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
    #if 0
        freopen("./in.txt", "r", stdin);
        freopen("./out.txt", "w", stdout);
    #endif

    for(int T = read(); T--;) {
    ll past = read();
    int year[2] = {365, 366}, month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d = 0, m = 0, y = 0;
    if(past == 0) printf("1 1 4713 BC\n");
    else if(past < 1721424) {
        d = 1; m = 1; y = 4713;
        y -= past / 1461 * 4;
        past %= 1461;
        while(past >= year[(y - 1) % 4 == 0])
            past -= year[--y % 4 == 0];
        month[2] += (y - 1) % 4 == 0;
        while(past >= month[m])
            past -= month[m++];
        month[2] -= (y - 1) % 4 == 0;
        d += past;
        printf("%d %d %d BC\n", d, m, y);
    }
    else if(past < 2299161) {
        past -= 1721424;
        d = 1; m = 1; y = 1;
        y += past / 1461 * 4;
        past %= 1461;
        if(past >= 1095) {
            y += 3;
            past -= 1095;
        }
        else {
            y += past / 365;
            past %= 365;
        }
        month[2] += y % 4 == 0;
        while(past >= month[m])
            past -= month[m++];
        month[2] -= y % 4 == 0;
        d += past;
        printf("%d %d %d\n", d, m, y);
    }
    // else if(past < 2299238){
    //     past -= 2299160;
    //     d = 15; m = 10; y = 1582;
    //     d += past;
    //     while(d > month[m]) {
    //         d -= month[m++];
    //     }
    //     printf("%d %d %d\n", d, m, y);
    // }
    // else {
    //     past -= 2299238;
    //     d = 1; m = 1; y = 1583;
    //     y += past / 146097;
    //     past /= 146097;

    // }
    else {
        past -= 1721424;
        //past += 12 + 10;
        past -= 2;
        d = 1; m = 1; y = 1;
        y += past / 146097 * 400;
        past %= 146097;
        if(past >= 109572) {
            y += 300;
            past -= 109572;
        }
        else {
            y += past / 36524 * 100;
            past %= 36524;
        }
        if(past >= 35064) {
            y += 96;
            past -= 35064;
        }
        else {
            y += past / 1461 * 4;
            past %= 1461;
        }
        if(past >= 1095) {
            y += 3;
            past -= 1095;
        }
        else {
            y += past / 365;
            past %= 365;
        }
        month[2] += (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        while(past >= month[m])
            past -= month[m++];
        month[2] -= (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        d += past;
        printf("%d %d %d\n", d, m, y);
    }
    }
    return 0;
}