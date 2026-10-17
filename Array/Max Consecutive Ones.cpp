class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(count, maxCount);
            }

            if (nums[i] == 0) {
                count = 0;
            }
        }

        return maxCount;
    }
};

/*
Approach:

- count current consecutive 1s ko count karta hai.
- maxCount ab tak milne wali maximum consecutive 1s ki count store karta hai.
- Agar nums[i] == 1 ho, to count ko increment kar do.
- Har 1 ke baad maxCount ko count aur maxCount mein se maximum value assign kar do.
- Agar nums[i] == 0 ho, to count ko 0 kar do kyun ke consecutive sequence break ho gayi.
- maxCount ko reset nahi karna, kyun ke is mein pehle se mila hua maximum محفوظ rehta hai.
- Loop ke end par maxCount return kar do.

Time Complexity: O(n)
Space Complexity: O(1)
*/
