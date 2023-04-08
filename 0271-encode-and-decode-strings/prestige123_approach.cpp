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
        int size = s.length();
        for (int i = 0, n = 0; i < size; i+=n, n = 0) {
            while(isdigit(s[i])) {
                n = 10*n + (s[i++] - '0');
            }
            dec.push_back(s.substr(++i, n));
        }

        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));