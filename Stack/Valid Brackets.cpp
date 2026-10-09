class Solution {
public:
    bool isValid(string s) {
        stack<char> input;

        for (char ch : s) 
        {
            if (ch == '{' || ch == '[' || ch == '(')
             {
                input.push(ch);
            }

            else if(ch=='}')
            {
                if(!input.empty() && input.top() == '{') 
                {
                input.pop();
                continue;
                }
                else
                {
                    return false;
                }
            }

            else if(ch==']')
            {
                if(!input.empty() && input.top() == '[') 
                {
                input.pop();
                continue;
                }
                else
                {
                    return false;
                }
            }

            
            else if(ch==')')
            {
                if(!input.empty() && input.top() == '(') 
                {
                input.pop();
                continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return input.empty();
    }
};

/*
Approach:
1. Opening brackets ko stack mein push karo.
2. Closing bracket aaye to stack empty nahi hona chahiye aur top par matching opening bracket hona chahiye.
3. Match milne par top bracket ko pop karo.
4. Match na mile ya stack empty ho to false return karo.
5. End par stack empty ho to true, warna false return karo.
*/
