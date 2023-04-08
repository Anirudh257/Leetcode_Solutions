class Codec {
public:
    // Time complexity: O(N), Space complexity: O(N)
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc = "";
        for (string s : strs) {
            enc += to_string(s.length()) + "#" +  s;
        }
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;

        int i = 0;
        string sub = "";

        while(i < s.length()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            string lenStr = s.substr(i, j - i);
            // cout << lenStr << endl;
            int subLen = stoi(lenStr);
            sub = s.substr(j + 1, subLen);
            dec.push_back(sub);
            i = j + 1 + subLen;
        }


        // cout << s << endl;

        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));