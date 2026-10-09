class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;

        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = size1 + size2;

        vector<int> nums3(size3);

        int i = 0;

        while (p1 < size1 && p2 < size2) {
            if (nums1[p1] < nums2[p2]) {
                nums3[i] = nums1[p1];
                p1++;
            }
            else {
                nums3[i] = nums2[p2];
                p2++;
            }
            i++;
        }

        while (p1 < size1) {
            nums3[i] = nums1[p1];
            p1++;
            i++;
        }

        while (p2 < size2) {
            nums3[i] = nums2[p2];
            p2++;
            i++;
        }

        if (size3 % 2 != 0) {
            return nums3[size3 / 2];
        }
        else {
            int left = size3 / 2 - 1;
            int right = size3 / 2;

            return (nums3[left] + nums3[right]) / 2.0;
        }
    }
};

/*
Approach:
1. p1 and p2 banay p1 array1 k indexes k liye ro p2 array 2 k liye
2. i array3 k index age le jane k liye 
3. dono arrays ko 0 se shuru kia yani p1 = p2 = 0
4. third array bana li array3 k name se wahan ka size rkha array1 + array2 k size k equal 
5. vector se declare kia vector<int> nums3(size3);
6. phele while loop tab tak chale ga jab tak dono arrays me elements hoo like agar array 1 me 3 the or array 2 me 5
   to phele 3 elements dono arrays k compare hoo ge or chote wala num3 me place ho ga
7. jis array ka element copy ho ga us k p1 ya p2 increment ho ga
8. When one array ends, copy all remaining elements from the other array
9. If the total size is odd, return the middle element
10. If the total size is even, return the average of the two middle elements
    left or right se dono middle elements ate hain

Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/
