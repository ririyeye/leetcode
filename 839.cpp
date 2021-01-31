#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int k = 0;
class Solution {
    public:
	bool cmpstr(string &sta, string &stb)
	{
        if((sta == "coswmccgkc"))
		    k = 1;


		char error_chr[2][2];

		int error_cnt = 0;

		for (size_t i = 0; i < sta.size(); i++) {
			if (sta[i] != stb[i]) {
				if (error_cnt < 2) {
					error_chr[0][error_cnt] = sta[i];
					error_chr[1][error_cnt] = stb[i];
					error_cnt++;

					if (error_cnt == 2) {
						if ((error_chr[0][1] != error_chr[1][0]) || (error_chr[0][0] != error_chr[1][1]))
							return false;
					}
				} else {
					return false;
				}
			}
		}
		return true;
	}

	bool insert_str(vector<vector<string> > &tmp, string &instr)
	{
		for (vector<string> &grp : tmp) {
			for (string &str : grp) {
				if (true == cmpstr(str, instr)) {
					grp.push_back(instr);
					return true;
				}
			}
		}
		return false;
	}
	int test = 0;

	int numSimilarGroups(vector<string> &strs)
	{
		vector<vector<string> > tmp;

		for (string &tmpstr : strs) {

            if(tmpstr == "cosgmccwkc"){
		        test = 1;
            }

			if (false == insert_str(tmp, tmpstr)) {
				vector<string> vstmp;
				vstmp.emplace_back(tmpstr);
				tmp.emplace_back(vstmp);
			}
		}

		for (auto &vec : tmp) {
			for (auto &st : vec) {
				cout << st << ",";
			}
			cout << endl;
		}

		return tmp.size();
	}
};

int main(int argc, char **argv)
{
	vector<string> str({"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"});

	Solution s;
	auto ret = s.numSimilarGroups(str);

	//printf("%d\n", ret);
}


