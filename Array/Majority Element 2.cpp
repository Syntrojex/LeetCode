class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> result;

        int freq1 = 0;
        int ans1 = 0;

        int freq2 = 0;
        int ans2 = 0;

        // Pehla pass: 2 possible candidates find karna
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq1 == 0 && ans2 != nums[i])
            {
                ans1 = nums[i];
                freq1 = 1;
            }
            else if (freq2 == 0 && ans1 != nums[i])
            {
                ans2 = nums[i];
                freq2 = 1;
            }
            else if (ans1 == nums[i])
            {
                freq1++;
            }
            else if (ans2 == nums[i])
            {
                freq2++;
            }
            else
            {
                freq1--;
                freq2--;
            }
        }

        // Doosra pass: candidates ki actual frequency count karna
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ans1)
            {
                count1++;
            }

            else if (nums[i] == ans2)
            {
                count2++;
            }
        }

        // Jo candidate n/3 se zyada baar aya usko result mein add karo
        if (count1 > nums.size() / 3)
        {
            result.push_back(ans1);
        }

        if (count2 > nums.size() / 3)
        {
            result.push_back(ans2);
        }

        return result;
    }
};

/*
Approach:

1. Majority Element II mein maximum 2 elements ho sakte hain
   jo n/3 se zyada baar appear karte hain.

2. Isliye do candidates rakhe:
   ans1 aur ans2
   aur unki frequencies:
   freq1 aur freq2

3. Agar freq1 zero ho jaye aur current element ans2 nahi hai,
   to current element ko ans1 ka candidate bana dete hain.

4. Agar freq2 zero ho jaye aur current element ans1 nahi hai,
   to current element ko ans2 ka candidate bana dete hain.

5. Agar current element ans1 ke equal hai,
   freq1 increase hoti hai.

6. Agar current element ans2 ke equal hai,
   freq2 increase hoti hai.

7. Agar current element dono candidates se different hai,
   dono frequencies decrease kar dete hain.
   Isay cancellation kehte hain.

8. Pehle pass ke baad ans1 aur ans2 sirf possible candidates hain.
   Unki actual frequency abhi confirm nahi hui.

9. Isliye doosre loop mein dono candidates ki actual frequency
   dobara count karte hain.

10. Jo candidate n/3 se zyada baar appear kare,
    usko result vector mein add kar dete hain.

Time Complexity: O(n)
Space Complexity: O(1) extra space
*/ 
