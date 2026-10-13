// Leetcode Maximum Sub Array Sum

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i : nums)
        {
            currSum += i;

            maxSum = max(currSum, maxSum);

            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }
};

/*
Kadane's Algorithm ek Dynamic Programming approach hai.

Hum currSum mein current subarray ka sum maintain karte hain.

Agar currSum negative ho jaye, toh usay 0 kar dete hain,
kyunke negative sum ko aage carry karna kisi future subarray ke
sum ko faida nahi dega.

Har element ke baad currSum ko maxSum ke saath compare karte hain
taake ab tak ka maximum subarray sum save rahe.

Important:
maxSum ko INT_MIN se initialize karte hain, 0 se nahi,
kyunke agar array mein saare numbers negative hon toh bhi
humein sabse bara negative number return karna hota hai.

Example:
[-2, -3, -1]

Answer = -1

Time Complexity: O(n)
Space Complexity: O(1)
*/
