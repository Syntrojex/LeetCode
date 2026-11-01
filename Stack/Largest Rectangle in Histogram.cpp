
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();

        // left[i] mein current bar ke nearest left smaller bar ka index store hoga
        // right[i] mein current bar ke nearest right smaller bar ka index store hoga
        //
        // Ye dono boundaries humein batayengi ke current bar ko minimum height
        // maan kar rectangle kitni width tak banaya ja sakta hai.

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // Stack mein bars ki heights ke bajaye unke indices store karenge.
        // Indices store karne ka faida ye hai ke hum baad mein unki heights
        // bhi access kar sakte hain aur rectangle ki width bhi calculate kar sakte hain.
        stack<int> st;

        // STEP 1: NEAREST RIGHT SMALLER ELEMENT

        // Array ko right se left traverse karenge.
        // Har index ke liye uske right side mein nearest smaller bar find karna hai.

        for (int i = n - 1; i >= 0; i--)
        {
            // Stack ke top par jo index hai uski height current bar se
            // bari ya equal hai toh woh current bar ke liye nearest smaller
            // element nahi ho sakta.
            //
            // Is liye usay pop karte jayenge jab tak:
            // 1. Stack empty na ho jaye.
            // 2. Ya stack ke top par current bar se choti height na mil jaye.
            //
            // Equal height ko bhi pop kar rahe hain taake duplicate heights
            // ki wajah se boundaries calculate karte waqt issue na aaye.

            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // Agar stack empty ho gaya toh current bar ke right mein
            // koi smaller bar available nahi hai.
            // Iska matlab rectangle array ke last index tak ja sakta hai.
            // Is liye right boundary n store karenge.

            if (st.empty())
            {
                right[i] = n;
            }

            // Agar stack empty nahi hai toh uske top par nearest
            // right smaller bar ka index available hai.

            else
            {
                right[i] = st.top();
            }

            // Current bar ka index stack mein push kar do
            // taake ye aage left side ke bars ke liye candidate ban sake.

            st.push(i);
        }

        // STEP 2: STACK EMPTY KARNA

        // Right smaller calculate karne ke baad stack mein purane indices
        // mojood hain. Left smaller calculate karne ke liye humein fresh
        // stack chahiye, is liye tamam elements pop kar denge.

        while (!st.empty())
        {
            st.pop();
        }

        // STEP 3: NEAREST LEFT SMALLER ELEMENT

        // Ab array ko left se right traverse karenge.
        // Har index ke liye uske left side mein nearest smaller bar find karna hai.

        for (int i = 0; i < n; i++)
        {
            // Agar stack ke top par mojood bar current bar se bari ya equal hai
            // toh woh nearest left smaller element nahi ho sakta.
            //
            // Is liye usay pop karte jayenge jab tak current bar se
            // choti height wala element nahi mil jata ya stack empty nahi hota.

            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // Agar stack empty ho gaya toh current bar ke left mein
            // koi smaller bar available nahi hai.
            // Iska matlab rectangle array ke starting index 0 tak ja sakta hai.
            // Is liye left boundary -1 store karenge.

            if (st.empty())
            {
                left[i] = -1;
            }

            // Agar stack empty nahi hai toh top par nearest
            // left smaller bar ka index available hai.

            else
            {
                left[i] = st.top();
            }

            // Current bar ka index stack mein push kar do
            // taake ye aage right side ke bars ke liye candidate ban sake.

            st.push(i);
        }

        // STEP 4: HAR BAR KA MAXIMUM RECTANGLE AREA

        int ans = 0;

        // Ab har bar ko ek baar minimum height maan kar check karenge
        // ke us height ke saath maximum kitni width ka rectangle ban sakta hai.

        for (int i = 0; i < n; i++)
        {
            // left[i] aur right[i] dono nearest smaller bars ke indices hain.
            //
            // Ye dono smaller bars rectangle mein include nahi ho sakte
            // kyun ke unki height current bar se kam hai.
            //
            // Is liye rectangle in dono boundaries ke darmiyan banega.
            //
            // Width = Right Boundary - Left Boundary - 1
            //
            // -1 is liye kar rahe hain kyun ke left aur right boundary
            // wale bars ko rectangle mein include nahi karna.

            int width = right[i] - left[i] - 1;


            // Current bar ko rectangle ki minimum height maan rahe hain.
            // Is height ke saath jitni width possible hai,
            // uska area calculate karenge.

            int currentArea = heights[i] * width;


            // Har bar ka maximum possible rectangle area calculate karne ke baad
            // usay ab tak ke maximum area ke saath compare karenge.

            ans = max(ans, currentArea);
        }


        // Tamam bars ko minimum height maan kar check kar chuke hain.
        // Ab ans mein largest possible rectangle ka area available hai.

        return ans;
    }
};


/*

PROBLEM:
Humein histogram mein maximum rectangle area find karna hai.

Har bar ki width 1 hai aur uski height heights[i] hai.

MAIN IDEA:
Hum har bar ko ek baar rectangle ki minimum height maanenge.
Phir find karenge ke us bar ki height ke saath maximum
kitni consecutive width ka rectangle ban sakta hai.

STEP 1: NEAREST RIGHT SMALLER
- Array ko right se left traverse karenge.
- Monotonic stack use karenge.
- Stack mein indices store karenge.
- Current height se bari ya equal heights ko pop karenge.
- Stack ka top nearest right smaller index dega.
- Agar stack empty ho toh right boundary n hogi.

STEP 2: STACK RESET
- Right smaller calculate hone ke baad stack empty karenge.
- Taake left smaller calculation fresh start ho.

STEP 3: NEAREST LEFT SMALLER
- Array ko left se right traverse karenge.
- Wohi monotonic stack logic use karenge.
- Current height se bari ya equal heights ko pop karenge.
- Stack ka top nearest left smaller index dega.
- Agar stack empty ho toh left boundary -1 hogi.

STEP 4: WIDTH CALCULATE
- Har bar ke liye uski left aur right boundaries mil chuki hain.
- Dono boundaries ke darmiyan jitne bars hain woh rectangle
  mein include ho sakte hain.
- Formula:
  width = right[i] - left[i] - 1

STEP 5: AREA CALCULATE
- Current bar ki height ko minimum height maanenge.
- Formula:
  area = height * width

STEP 6: MAXIMUM ANSWER
- Har bar ka possible maximum rectangle area calculate karenge.
- Sab areas mein se maximum answer return karenge.

WHY MONOTONIC STACK?
- Har element maximum ek baar push hota hai.
- Har element maximum ek baar pop hota hai.
- Is liye dono traversals O(n) mein complete ho jati hain.

TIME COMPLEXITY:
- Right Smaller: O(n)
- Left Smaller: O(n)
- Maximum Area: O(n)
- Overall: O(n)

SPACE COMPLEXITY:
- Left array: O(n)
- Right array: O(n)
- Stack: O(n)
- Overall: O(n)
*/
