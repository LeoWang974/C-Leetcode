#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int tag = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (tag > 0)
                    tag -= 1;
                else
                    tag = 0;
            }
            else {
                s[tag] = s[i];
                tag++;
            }
        }

        string st = "";
        for (int i = 0; i < tag; i++) {
            st += s[i];
        }

        return st;
    }
};


//法二，更快
class Solution2 {
public:
    string clearDigits(string s) {
        string ans;
        for (char c : s)
        {
            if (isdigit(c))
                ans.pop_back();
            else
                ans += c;
        }
        return ans;
    }
};


int main() {
    string s = "cb34";
    Solution sol;
    string res = sol.clearDigits(s);
    cout << res;

    return 0;
}