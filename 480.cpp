#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> slideWindow;
        for(int i=0; i<nums.size(); i++){
            if(slideWindow.size() >= k){
                slideWindow.erase(slideWindow.find(nums[i - k]));
            }
            slideWindow.insert(nums[i]);
            if(slideWindow.size() == k){
                auto it = slideWindow.begin();
                std::advance(it, k/2);
                double val = ((double)*it + *std::prev(it, (1 - k%2))) / 2;
                res.push_back(val);
            }
        }
        return res;
    }
};