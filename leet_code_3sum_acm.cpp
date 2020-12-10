#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

  vector<vector<int>> ans;
  if (nums.size() < 3)
    return ans;
  sort(nums.begin(), nums.end());
  int len = nums.size();
  for (int i = 0; i < len - 2; i++)
  {
    if (i > 0 && nums[i - 1] == nums[i])
      continue;
    int s = -nums[i], l = i + 1, r = len - 1;
    while (l < r)
    {
      if (nums[l] + nums[r] == s)
      {
        vector<int> co;
        co.push_back(nums[i]), co.push_back(nums[l]), co.push_back(nums[r]);
        //ans.push_back({nums[i], nums[l], nums[r]});
        ans.push_back(co);
        while (nums[l] == nums[l + 1])
          l++;
        while (nums[r] == nums[r - 1])
          r--;
        l++, r--;
      }
      else if (nums[l] + nums[r] > s)
        r--;
      else
        l++;
    }
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  auto ans = threeSum(nums);
  for (auto p : ans)
  {
    for (auto k : p)
    {
      cout << k << " ";
    }
    cout << '\n';
  }

  return 0;
}
