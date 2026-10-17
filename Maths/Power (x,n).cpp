class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;

        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                ans *= x;
            }

            x *= x;
            power /= 2;
        }

        return ans;
    }
};

/*
Approach:

1. double ans = 1.0;
   - ans mein final answer store hoga.
   - 1.0 se start kiya kyun ke multiplication mein 1 neutral value hai.
   - Misal: 1 * 2 * 2 = 4.

2. long long power = n;
   - n exponent hai, yani x ki power.
   - power ko long long banaya taake n = -2147483648 jaisi
     minimum int value ko safely positive banaya ja sake.

3. if (power < 0)
   - Agar exponent negative ho, to reciprocal ka rule use hota hai.
   - Mathematical rule: x^(-n) = (1/x)^n.
   - Misal: 2^(-3) = (1/2)^3 = 1/8.
   - Is liye x = 1/x kiya, taake negative exponent ko
     positive exponent mein calculate kar saken.
   - power = -power se exponent positive ho jata hai.
   - long long ki wajah se INT_MIN ko negate karna safe hai.

4. while (power > 0)
   - Jab tak exponent zero nahi hota, calculation chalti rahegi.

5. if (power % 2 == 1)
   - Agar power odd ho, to ans *= x karte hain.
   - Odd exponent mein ek x alag nikal kar ans mein multiply
     karna hota hai.
   - Misal: x^5 = x * (x^2)^2.
   - Agar power even ho, to is step mein ans ko multiply
     karne ki zaroorat nahi hoti.

6. x *= x;
   - x ko khud se multiply karke square karte hain.
   - Misal: x = 2 ho to x = 4, phir x = 16, phir x = 256.
   - Is tarah har step mein x ki power double hoti jati hai.

7. power /= 2;
   - Exponent ko aadha kar dete hain.
   - Is se har iteration mein remaining work kam hota hai.
   - Isi wajah se algorithm O(log |n|) time leta hai,
     O(n) nahi.

8. return ans;
   - Jab power zero ho jaye, final answer return kar dete hain.

Time Complexity: O(log |n|)
Space Complexity: O(1)
*/
