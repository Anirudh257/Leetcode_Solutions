//  Chunking technique
const int HEADERLEN = 4;

// Time complexity: O(N), Space complexity: O(N)
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc = "";
        
        for (string s : strs) {
            string chunkLen = int2Chunk(s.size());
            enc += chunkLen + s;
        }
        
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        
        while(s.length()) {
            string chLen = s.substr(0, HEADERLEN);
            int sLen = stoi(chLen);
            s.erase(0, HEADERLEN);
            dec.push_back(s.substr(0, sLen));
            s.erase(0, sLen);
        }
        
        return dec;
    }
private:
    string int2Chunk(int num) {
        stringstream ss;
        ss << setw(HEADERLEN) << setfill('0') << num;
        return ss.str();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
