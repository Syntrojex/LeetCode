class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        if (nums.size() < 2 || nums.size() >= 10000)
        {
            cout << "ERROR: Invalid List size" << endl;
            return {};
        }

        else if (target <= -1000000000 || target >= 1000000000)
        {
            cout << "ERROR: Invalid Target" << endl;
            return {};
        }

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

        return {};
    }
};

// Constraints:
// Humne nums.size() built-in function use kiya hai,
// jo vector ke elements ki total quantity return karta hai.

// Comparison Logic:
// Hum har element ko uske agle elements ke saath compare karte hain.
// Yani i ko fix karke j = i + 1 se aage check karte hain.
// Is tarah same element khud ke saath compare nahi hota,
// aur ek hi pair dobara check nahi hota.

// Return Type:
// Hamare function ki return type vector<int> hai.
// Isliye humein integer indexes ka vector return karna hai.

// return {};
// Agar koi pair na mile to empty vector return hota hai.

// return {i, j};
// Agar pair mil jaye to uske dono indexes return hote hain.
