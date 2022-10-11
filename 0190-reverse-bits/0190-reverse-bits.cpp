class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binRep = compBinRep(n);
        
        cout << binRep << endl;
        
        uint32_t res = 0;
        
        int count = 31;
        
        
        for (int i = 0; i < binRep.size(); i++) {
            long long int val = binRep[i] - '0';
            long long int power = pow(2, count);
            // cout << power << endl;
            res += val*power;
            count--;
        }
        
        return res;
    }
private:
    string compBinRep(uint32_t n) {
        string res = "";
        
        while(n) {
            int rem = n % 2;
            res += to_string(rem);
            n = n/2;
        }
        
        // reverse(res.begin(), res.end());
        
        return res;
    }
};