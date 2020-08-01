// note:
// 1)
// "A" ~ "Z": 65 ~ 90
// "a" ~ "z": 97 ~ 122
// 2)
// std::count_if

// first try
// 2020-08-01
// T: O(n)
// S: O(1)
class Solution {
public:
  bool detectCapitalUse(string word) {
    int count = std::count_if(word.begin(), word.end(),
                              [](char s) { return s <= 'Z'; });
    return count == 0 || count == word.size() || (count == 1 && word[0] <= 'Z');
  }
};
