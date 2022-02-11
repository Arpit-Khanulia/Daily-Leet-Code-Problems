#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> ans;

        for (int i = 0; i < size; i++)
        {
            if( nums[abs(nums[i]) - 1]   < 0)
                ans.push_back(abs(nums[i]));
            
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        return ans;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;
    Solution a;
    ans = a.findDuplicates(array);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}