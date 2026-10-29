class Solution { 
public: 
    int calculateScore(int a, int b) { 
        // __builtin_popcount counts only the '1' bits in the binary representation
        int s1 = __builtin_popcount(a); 
        int s2 = __builtin_popcount(b); 

        if (s1 >= s2) { 
            return s1 * s2; 
        } else { 
            return s2 / s1; // Fixed: Problem asks for s2 / s1 when s1 < s2
        } 
    } 
};
