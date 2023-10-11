// Time complexity: O(n), Space complexity: O(1)
// But works in C++ as it has mutable strings, not work for Java that has immutable strings
class Solution {
public:
    string reverseWords(string s) {
        int idx = 0; // New index that helps in skipping spaces
        int size = s.size();
        int end = size - 1;

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int st = 0; st < size; st++) {
            if (s[st] != ' ') {
                // Add a space after the word has ended
                if (idx) {
                    s[idx++] = ' ';
                }

                end = st;
                while(end < size && s[end] != ' ') {
                    s[idx++] = s[end++];
                }

                // Reverse only the word to get back actual word
                reverse(s.begin() + idx - (end - st), s.begin() + idx);

                // Move to next word
                st = end;
            }

        }
        // Delete unnecessary characters
        s.erase(s.begin() + idx, s.end());

        return s;
    }
};