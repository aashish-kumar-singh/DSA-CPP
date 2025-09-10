#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int k){
        if(k < 0){
            return 0;
        }
         int l = 0;
        int r = 0;
        int cnt = 0;
        map<int, int> mpp;
        while (r < nums.size()) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int ans=helper(nums,k)-helper(nums,k-1);
       return ans;
    }

int main(){
return 0;
}