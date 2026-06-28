class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            // Find the delimiter '#' starting from index i
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // Extract the length of the next string
            int len = stoi(s.substr(i, j - i));
            
            // Move pointer i to the start of the actual string
            i = j + 1;
            
            // Extract the string and add it to our result
            decoded.push_back(s.substr(i, len));
            
            // Move pointer i to the start of the next length prefix
            i += len;
        }
        
        return decoded;
    }
};