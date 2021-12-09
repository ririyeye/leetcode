#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
	int checkwin(vector<string> &board, char chk_char)
	{
		for (int i = 0; i < 3; i++) {
			if (board[i][0] == chk_char && board[i][1] == chk_char && board[i][2] == chk_char)
				return 1;

			if (board[0][i] == chk_char && board[1][i] == chk_char && board[2][i] == chk_char)
				return 1;
		}

		if (board[0][0] == chk_char && board[1][1] == chk_char && board[2][2] == chk_char)
			return 1;

		if (board[0][2] == chk_char && board[1][1] == chk_char && board[2][0] == chk_char)
			return 1;
		return 0;
	}

	bool validTicTacToe(vector<string> &board)
	{
		int xcnt = 0, ocnt = 0;

		for (string &str : board) {
			for (int i = 0; i < 3; i++) {
				if (str[i] == 'X') {
					xcnt++;
				}
				if (str[i] == 'O') {
					ocnt++;
				}
			}
		}

		if (ocnt != xcnt && ocnt != xcnt - 1) {
			return false;
		}
		if (checkwin(board, 'X') && ocnt != xcnt - 1) {
			return false;
		}
		if (checkwin(board, 'O') && ocnt != xcnt) {
			return false;
		}

		return true;
	}
};

int main(int argc, char **argv)
{
	vector<string> test = { "XOX", "O O", "XOX" };
	Solution s;
	auto ret = s.validTicTacToe(test);
	return 0;
}
