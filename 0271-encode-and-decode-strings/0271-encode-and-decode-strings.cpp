class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        int size = strs.size();
        for (int i = 0; i < size; i++) {
            indStr[i] = strs[i];
            res += strs[i] + to_string(i);
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        int size = s.size();
        int numWords = indStr.size();
        
        for (int i = 0; i < numWords; i++) {
            dec.push_back(indStr[i]);
        } 
        
        return dec;
    }
private:
    unordered_map<int, string> indStr;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));