// Majority Element Probelm of Leetcode

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int freq = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (freq == 0)
            {
                ans = nums[i];
            }

            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }

        return ans;
    }
};

/*
[2, 2, 1, 1, 1, 2, 2]

ans me at the end of the day amjority element khud hi ajay ga 

2 → ans=2, freq=1
2 → same     freq=2
1 → different freq=1
1 → different freq=0
1 → freq=0 → ans=1
1 → same     freq=1
2 → different freq=0

*/
