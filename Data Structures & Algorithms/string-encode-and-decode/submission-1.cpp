class Solution {
    int calculateDigits(int l){
        if(l >= 0 && l <= 9) return 1;
        int numOfDigits = 0;
        while(l > 0){
            l /= 10;
            ++numOfDigits;
        }
        return numOfDigits;
    }

public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string encoded = "";

        for(const string s: strs){
            int len = s.length(), digits = calculateDigits(len);
            string init = '#' + to_string(digits) + to_string(len);
            encoded += init + s; 
        }

        return encoded;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};

        vector<string> decoded;
        int len = s.length();

        for(int i=0; i<len; ++i){
            if(s[i] == '#'){
                int digits = s[i+1] - '0';
                int len = stoi(s.substr(i+2, digits));

                string str = s.substr(i+digits+2, len);

                decoded.push_back(str);

                i += 1 + digits + len;
            }
        }

        return decoded;
    }
};
