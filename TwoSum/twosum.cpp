#include <iostream>
#include <vector>
using namespace std;

vector<int> twosum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
}
int main()
{
    vector<int> nums = {3, 2, 4};
    cout << twosum(nums, 6)[0];
    cout << " ";
    cout << twosum(nums, 6)[1];
}