// Time complexity: O(N), Space complexity: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();

        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('A');
        vowels.insert('e');
        vowels.insert('E');
        vowels.insert('i');
        vowels.insert('I');
        vowels.insert('o');
        vowels.insert('O');
        vowels.insert('u');
        vowels.insert('U');

        int left = 0, right = size - 1;
        while(left < size && right >= 0 && left < right) {
            
            while(left != right && vowels.count(s[left]) != 1) {
                left++;
            }
            
            while(right >= 0 && vowels.count(s[right]) != 1) {
                right--;
            }

            if (left >= right) {
                break;
            }

            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};