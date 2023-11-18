#include <bits/stdc++.h>
using namespace std;

class Solution {
    array<int,100>M,m;
public:
    int maximumSum(vector<int>& nums) {
        //map<int,int>ma;
        int n=nums.size();
        m.fill(0);
        M.fill(0);
        for(int i=0;i<n;++i)
        {
            int tmp=nums[i];
            int sum=0;
            while(tmp)
            {
                sum+=tmp%10;
                tmp/=10;
            }
            if(M[sum]<nums[i])
            {
                m[sum]=M[sum];
                M[sum]=nums[i];
            }
            else if(m[sum]<nums[i])
                m[sum]=nums[i];
        }
        int ret=-1;
        for(int i=1;i<=81;++i)
        {
            if(m[i]!=0)
                ret=max(ret,M[i]+m[i]);
        }
        return ret;
    }
};