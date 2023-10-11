// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();
        vector<int> vowInds;
        vector<char> vows;

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

        for (int i = 0; i < size; i++) {
            char ch = s[i];
            if (vowels.count(ch)) {
                vowInds.push_back(i);
                vows.push_back(ch);
            }
        }

        int reqInd = vows.size() - 1;
        for (int ind : vowInds) {
            s[ind] = vows[reqInd--];
        }



        return s;
    }
};