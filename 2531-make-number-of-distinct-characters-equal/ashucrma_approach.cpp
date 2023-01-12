// Time complexity: O(26*26 + m + n), Space complexity: O(m + n)
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        unordered_map<char, int> freq1, freq2;

        for (char ch : word1) {
            freq1[ch]++;
        }

        for (char ch : word2) {
            freq2[ch]++;
        }

        for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {

                // Skip if characters not present in the map
                if (freq1.count(ch1) == 0 || freq2.count(ch2) == 0) {
                    continue;
                }

                // Insert ch2 in freq1 and remove ch1 from freq2
                // Insert ch1 in freq2 and remove ch2 from freq2
                // Check if freq1.size == freq2.size
                insertAndRemove(freq1, ch2, ch1);
                insertAndRemove(freq2, ch1, ch2);

                // If swapping lead to same size of distinct chars, return true
                if (freq1.size() == freq2.size()) {
                    return true;
                }

                // Else, reset maps
                insertAndRemove(freq1, ch1, ch2);
                insertAndRemove(freq2, ch2, ch1);

            }
        }

        return false;
    }
private:
    void insertAndRemove(unordered_map<char, int>& freq, char toAdd, char toRem) {
        freq[toAdd]++;
        freq[toRem]--;
        if (freq[toRem] == 0) {
            freq.erase(toRem);
        }
        return;
    }
};
