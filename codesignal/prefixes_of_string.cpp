// Time complexity: O(N), Space complexity: O(N)

bool isPal(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev == s;
}

string solution(string s) {
    int size = s.size();
    int st = 0;
    string pal = "";
    
    for (int i = 0; i <= size; i++) {
        string temp = s.substr(0, i);
        if (isPal(temp) && pal.size() < temp.size()) {
            pal = temp;
            st = i; // Go to this character as start if palindrome exists.
            continue;
        }
    }
    if (pal.size() >= 2) {
        s = s.substr(st);
        return solution(s);
    }
    
    return s;
    
}
