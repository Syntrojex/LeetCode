class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> input;

        int length = 0;
        input.push(-1);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                input.push(i);
            }

            else if (s[i] == ')')
            {
                input.pop();

                if (input.empty())
                {
                    input.push(i);
                }

                else
                {
                    length = max(length, i - input.top());
                }
            }
        }

        return length;
    }
};

/*
Approach:

1. Stack mein characters nahi, balki parentheses ke INDEXES store karte hain.

2. Sabse pehle -1 stack mein push karte hain.
   -1 ek base index hai.
   - Iski wajah se agar valid parentheses string index 0 se start ho,
     toh length correctly calculate ho sake.

3. Agar '(' aaye:
   - Uska index stack mein push kar dete hain.
   - Kyunke '(' abhi close nahi hua, isliye uska index yaad rakhna zaroori hai.

4. Agar ')' aaye:
   - Sabse pehle stack se top element pop karte hain.
   - Agar stack mein '(' ka index tha, toh ye ')' us '(' ko match kar deta hai.

5. Pop karne ke baad agar stack EMPTY ho jaye:
   - Iska matlab current ')' kisi valid '(' ke saath match nahi hua.
   - Ye position valid parentheses ka break point hai.
   - Isliye current ')' ka index stack mein push kar dete hain.
   - Ye naya base index ban jata hai.

6. Agar pop karne ke baad stack empty NA ho:
   - Iska matlab current ')' valid pair ka part hai.
   - Ab current index aur stack ke top index ka difference
     valid parentheses ki length deta hai.

   Example:
   s = "()"
   indexes = 0 1

   Start:
   stack = [-1]

   '(' index 0:
   stack = [-1, 0]

   ')' index 1:
   0 pop ho gaya
   stack = [-1]

   length = 1 - (-1)
          = 2

7. max() isliye use karte hain kyunke humein sirf current valid length nahi,
   balki poori string mein SAB SE BARI valid length chahiye.

8. Ek aur example:
   s = ")()()"

   Pehla ')' index 0 par kisi '(' se match nahi hota.
   Stack empty ho jata hai, isliye 0 ko stack mein push kar dete hain.

   Ab 0 naya base ban gaya aur uske baad wali valid parentheses ki
   length isi base se calculate hogi.

9. Is tarah stack do cheezen yaad rakhta hai:
   - Unmatched '(' ke indexes
   - Last invalid ')' ka index, jo base ka kaam karta hai.

Time Complexity: O(n)
Space Complexity: O(n)
*/
