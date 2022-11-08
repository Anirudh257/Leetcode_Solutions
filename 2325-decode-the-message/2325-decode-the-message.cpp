class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> alphaMap;
        
        char ch = 'a';
        
        for (char c : key) {
            if ((alphaMap.find(c) == alphaMap.end()) && c != ' ') {
                alphaMap[c] = ch;
                ch++;
            }
        }
        
        string dec = "";
        for (char m : message) {
            if (m != ' ') {
                dec += alphaMap[m];
            }
            else {
                dec += ' ';
            }
        }
        
        return dec;
    }
};