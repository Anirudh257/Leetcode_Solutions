class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc = "";
        
        for (string s : strs) {
            enc += to_string(s.size()) + '@' + s;
        }
        
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        
        int i = 0;
        while(i < s.size()) {
            int atPos = s.find_first_of('@', i);
            int len = stoi(s.substr(i, atPos - i));
            i = atPos + 1;
            dec.push_back(s.substr(i, len));
            i += len;
        }
        
        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));