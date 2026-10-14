class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while (left <= right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax)
            {
                ans += min(leftMax, rightMax) - height[left];
                left++;
            }

            else
            {
                ans += min(leftMax, rightMax) - height[right];
                right--;
            }
        }

        return ans;
    }
};

/*
Approach:

1. Do pointers use kiye hain:
   - left array ke start par hai.
   - right array ke end par hai.

2. leftMax:
   Left side par ab tak jo sabse bari height mili hai,
   usko store karta hai.

3. rightMax:
   Right side par ab tak jo sabse bari height mili hai,
   usko store karta hai.

4. Har iteration mein:
   leftMax ko current left height ke saath update karte hain.
   rightMax ko current right height ke saath update karte hain.

5. Agar leftMax < rightMax ho:
   Matlab left side ki boundary choti hai.
   Isliye current left position par water ki limit leftMax hogi.

   Water:
   min(leftMax, rightMax) - height[left]

   Phir left ko ek step aage kar dete hain.

6. Agar leftMax >= rightMax ho:
   Right side ki boundary choti/equal hai.
   Isliye current right position par water calculate karte hain.

   Water:
   min(leftMax, rightMax) - height[right]

   Phir right ko ek step peeche kar dete hain.

7. Har position ka water 'ans' mein add hota rehta hai.

8. Jab left aur right pointers cross kar jaate hain,
   poori array process ho chuki hoti hai.

9. End par total trapped water 'ans' mein hota hai,
   isliye ans return kar dete hain.

Time Complexity: O(n)
Space Complexity: O(1)
*/
