/*

Problem Statement!!!

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

//If First solutions or brute force solution comes in your mind then implement it after it shows TLE then check this solution.
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ct_s(26), ct_p(26), res;
        if (s.size() < p.size())
            return res;
        for (int i = 0; i < p.size(); ++i)
        {
            ct_s[s[i] - 'a']++;
            ct_p[p[i] - 'a']++;
        }
        if (ct_s == ct_p)
            res.push_back(0);

        for (int i = p.size(); i < s.size(); ++i)
        {
            ct_s[s[i] - 'a']++;
            ct_s[s[i - p.size()] - 'a']--;

            if (ct_s == ct_p)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};