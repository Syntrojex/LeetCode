class Solution
{
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> result;

        int current = 1;

        for (int num : target)
        {
            // Target number tak pohanchne ke liye
            // missing numbers ko Push karke Pop kar dete hain
            while (current < num)
            {
                result.push_back("Push");
                result.push_back("Pop");

                current++;
            }

            // Current number target mein hai
            // isliye sirf Push karna hai
            result.push_back("Push");
            current++;
        }

        return result;
    }
};
