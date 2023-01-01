// 290. Word Pattern

// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//          unordered_map<char, string> mp;
//         unordered_map<string, char> mp2;
//         int i = 0;
//         int j = 0;
//         while (i < pattern.size() && j < s.size())
//         {
//             string temp = "";
//             while (j < s.size() && s[j] != ' ')
//             {
//                 temp += s[j];
//                 j++;
//             }
//             if (mp.find(pattern[i]) == mp.end())
//             {
//                 mp[pattern[i]] = temp;
//             }
//             else
//             {
//                 if (mp[pattern[i]] != temp)
//                 {
//                     return false;
//                 }
//             }
//             if (mp2.find(temp) == mp2.end())
//             {
//                 mp2[temp] = pattern[i];
//             }
//             else
//             {
//                 if (mp2[temp] != pattern[i])
//                 {
//                     return false;
//                 }
//             }
//             i++;
//             j++;
//         }
//         if (i != pattern.size() || j != s.size())
//         {
//             return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, size_t> dp;
        unordered_set<size_t> seenWords;
        istringstream ss(s);
        string word; 
        size_t h;
        int i = 0;
        while (ss >> word) {
            h = hash<string>()(word);
            if (dp[pattern[i]] != 0) {
                if (dp[pattern[i]] != h) return false;
            } else if (seenWords.find(h) != seenWords.end()) {
                return false;
            } else {
                seenWords.insert(h);
                dp[pattern[i]] = h;
            }
            i++;
        }
        if (pattern.size() > i)
            return false;
        return true;
    }
};
