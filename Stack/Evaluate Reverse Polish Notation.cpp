class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        // Reverse Polish Notation basically Postfix ko hi kehte hain

        stack<int> st;

        for (string ch : tokens)
        {
            // Agar token operator nahi hai toh ye number hai
            // stoi() string ko integer mein convert karta hai
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
            {
                st.push(stoi(ch));
            }

            // Addition ke liye dono operands stack se nikal kar add karo
            else if (!st.empty() && ch == "+")
            {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = num2 + num1;
                st.push(result);
            }

            // Subtraction mein num2 se num1 subtract hota hai
            else if (!st.empty() && ch == "-")
            {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = num2 - num1;
                st.push(result);
            }

            // Multiplication ke liye dono operands multiply karo
            else if (!st.empty() && ch == "*")
            {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = num2 * num1;
                st.push(result);
            }

            // Division mein num2 ko num1 se divide karo
            else if (!st.empty() && ch == "/")
            {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = num2 / num1;
                st.push(result);
            }

            // Modulo mein num2 ko num1 se divide karne par remainder milega
            else if (!st.empty() && ch == "%")
            {
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                int result = num2 % num1;
                st.push(result);
            }
        }

        // Final stack element hi expression ka answer hoga
        return st.top();
    }
};
