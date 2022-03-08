#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution 
{
public:
    // 贪心算法：当前下标所指元素之前的和小于0，则丢弃当前下标之前的数。每次比较更新最大值
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = INT_MIN;  //让最大值的初始值为最小整数, 定义在limits.h头文件中
        int curSum = 0;     //当前和的初始值为0
        for(int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
            // 若当前和小于0则丢弃
            if(curSum < 0)
                curSum = 0;
        }

        return maxSum;
    }

    // 动态规划：若前一个元素大于0(前一个元素指的是加完之后的值，不是原数组中的值)，则将其加到当前元素上
    // 可利用原数组来做，但是改变了原数组的值。
    int maxSubArray_1(vector<int>& nums)
    {
        #if 1
        int maxSum = nums[0];   // 最大值初始为第一个元素
        int preNum = 0;         // 前一个元素初始值为0
        for(int i = 0; i < nums.size(); i++)
        {
            preNum = max(preNum + nums[i], nums[i]);
            maxSum = max(maxSum, preNum);
        }

        return maxSum;
        #endif

        #if 0
        int pre = 0; 
        int maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns; 
        #endif
    }
};

int main()
{
    vector<int> v = {-2, 1, -2, 4, -1, 2, 1, -5, 4, 7};
    // vector<int> v = {-2, -1, -2, -4, 0, -2, -1, -5, -4};
    // vector<int> v = {-2, -1, -5, -4, -7, -2, -3, -5, -4};
    Solution s;
    // int ret = s.maxSubArray(v);
    int ret = s.maxSubArray_1(v);

    cout << "ret: " << ret << endl;

    return 0;
}

