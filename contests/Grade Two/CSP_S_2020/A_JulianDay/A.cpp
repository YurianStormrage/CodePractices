#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}
int main()
{
    // freopen("julian3.in", "r", stdin);
    // freopen("julian3.out", "w", stdout);
    ll BCTime = 1721423, JulianEndTime = 2299160, timeStartOfDelete = 0;
    int dayOfYear = 365, dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int startOfJulian = 4713, startYear = 1;

    // for(; startOfJulian; -- startOfJulian) {
    //     BCTime += dayOfYear + ((startOfJulian - 1) % 4 == 0);        
    // }
    // BCTime -= 1;

    // JulianEndTime = BCTime;
    // for( ;startYear < 1582; ++ startYear) {
    //     JulianEndTime += dayOfYear + (startYear % 4 == 0);        
    // }
    // JulianEndTime += 31 * 9 - 3 - 3 + 4;

    // printf("%lld\n", BCTime);
    // printf("%lld\n", JulianEndTime);

    int round = 146097, round_2 = 36524;
    // for(int i = 1; i <= 400; ++i) {
    //     if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
    //         round ++;
    // }
    // round += 400 * dayOfYear;
    // printf("%d\n", round);
    // for(int i = 1; i < 100; ++i)
    //     if(i % 4 == 0)
    //         round_2 ++;
    // round_2 += 100 * dayOfYear;
    // printf("%d", round_2);

    for(int T = read(); T--;) {

    ll targetDay = read();

    int ans[3] = {0};

    if(targetDay <= BCTime) {
        ans[0] = 1;
        ans[1] = 1;
        ans[2] = 4713;

        int pastYear = targetDay / 1461 * 4;
        targetDay %= 1461;
        if(targetDay >= 366) {
            targetDay -= 366;
            pastYear ++;

            pastYear += targetDay / 365;
            targetDay %= 365;
            ans[2] -= pastYear;
        }
        
        ans[0] += targetDay;
        while(ans[0] > dayOfMonth[ans[1]]) {
            ans[0] -= dayOfMonth[ans[1] ++] + (ans[1] == 2 && (ans[2] - 1) % 4 == 0);
        }

        for(int i = 0; i < 3; ++i) printf("%d ", ans[i]);
        printf("BC\n");
    }
    else if(targetDay <= JulianEndTime) {
        targetDay -= BCTime + 1;
        ans[0] = 1;
        ans[1] = 1;
        ans[2] = 1;

        int pastYear = targetDay / 1461 * 4;
        targetDay %= 1461;

        if(targetDay / dayOfYear < 4) {
            pastYear += targetDay / dayOfYear;
            targetDay %= dayOfYear;
        }
        else {
            pastYear += 3;
            targetDay -= dayOfYear * 3;
        }

        ans[2] += pastYear;

        ans[0] += targetDay;
        while(ans[0] > dayOfMonth[ans[1]] + (ans[1] == 2 && ans[2] % 4 == 0)) {
            ans[0] -= dayOfMonth[ans[1]] + (ans[1] == 2 && ans[2] % 4 == 0);
            ++ ans[1];
        }

        for(int i = 0; i < 3; ++i) printf("%d ", ans[i]);
        puts("");
    }
    else {
        targetDay -= JulianEndTime + 1 - 365;
        ans[0] = 15;
        ans[1] = 10;
        ans[2] = 1581;

        int pastYear = targetDay / round * 400;
        targetDay %= round;
    
        if(targetDay / round_2 < 4) {
            pastYear += targetDay / round_2 * 100;
            targetDay %= round_2;
        }
        else {
            pastYear += 300;
            targetDay -= round_2 * 3;
        }

        if(targetDay / 1461 < 25) {
            pastYear += targetDay / 1461 * 4;
            targetDay %= 1461;
        }
        else {
            pastYear += 96;
            targetDay -= 1461 * 24;
        }

        ans[2] += pastYear;

        ans[0] += targetDay;
        while(ans[0] > dayOfMonth[ans[1]] + (ans[1] == 2 && ((ans[2] % 4 == 0 && ans[2] % 100 != 0) || ans[2] % 400 == 0))) {
            ans[0] -= dayOfMonth[ans[1]] + (ans[1] == 2 && ((ans[2] % 4 == 0 && ans[2] % 100 != 0) || ans[2] % 400 == 0));
            if(++ans[1] > 12) {
                ans[1] -= 12;
                ans[2] ++;
            }
        }

        for(int i = 0; i < 3; ++i) printf("%d ", ans[i]);
        puts("");
    }

    }
    return 0;
}