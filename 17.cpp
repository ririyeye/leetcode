#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    void func(vector<string> &res, char * str, string &digits, const char *map[], int k, int len)
    {
        if (k == len)
        {
            res.push_back(str);
            return;
        }
        const char *dat = map[digits[k] - '0'];
        int datlen = strlen(dat);
        for (int i = 0; i < datlen; i++)
        {
            str[k] = dat[i];
            func(res, str, digits, map, k + 1, len);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        const char *MAP[] = {
            " ",
            0,
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

        vector<string> res;
        if (digits == "")
            return res;

        char *str = (char *)calloc(digits.size() + 1,1);
        func(res, str, digits, MAP, 0, digits.size());
        free(str);
        return res;
    }
};



int main(int argc,char ** argv)
{
    Solution s;
    auto ret = s.letterCombinations("23");

    cout << "num:" << ret.size() << endl;
    for (auto &dat : ret)
    {
        cout << dat << endl;
    }
}



