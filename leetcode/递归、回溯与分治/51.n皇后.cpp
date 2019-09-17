/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 * 思路：递归+回溯
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;    // 存储最终结果的数组
        vector<vector<int>> mark;         // 标记棋盘是否可以放置皇后的二维数组
        vector<string> temp;              // 存储某个摆放结果
        // 初始化
        for (int i = 0; i < n; i++) {
            mark.push_back((vector<int>()));
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }
            temp.push_back("");
            temp[i].append(n, '.');
        }
        generate(0, n, temp, result, mark);
        return result;

    }
private:
    void put_down_the_queen(int x, int y, vector<vector<int>>& mark) {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 1; i < mark.size(); i++) {
            for (int j = 0; j < 8; j++) {
                int new_x = x + i*dx[j];
                int new_y = y + i*dy[j];
                if (new_x >= 0 && new_x < mark.size() &&
                    new_y >= 0 && new_y < mark.size()) {
                        mark[new_x][new_y] = 1;
                    }
            }
        }
    }

    void generate(int k, int n, vector<string>& temp, // k代表完成了几个皇后的放置（正在放置第k行皇后）
                  vector<vector<string>>& result,     // 最终结果存储在result
                  vector<vector<int>>& mark           // 表示棋盘的标记数组
                 ) {
        if (k == n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mark[k][i] == 0) {
                vector<vector<int>> temp_mark = mark;
                put_down_the_queen(k, i, mark);
                temp[k][i] = 'Q';
                generate(k+1, n, temp, result, mark);
                mark = temp_mark;
                temp[k][i] = '.';
            }
        }
    }
};


// 另一种实现
class Solution {
	bool isValid(vector<string> &v, int row, int col){
		bool valid=true;
		for(int i=0; valid && i<row; valid=v[i++][col]!='Q');
		for(int i=0; valid && i<col; valid=v[row][i++]!='Q');
		for(int i=row, j=col; valid && i-- && j--; valid=v[i][j]!='Q');
		for(int i=row, j=col; valid && i-- && ++j<v.size(); valid=v[i][j]!='Q');
		return valid;
	}
	void backtrack(vector<string> &v, int row, vector<vector<string> > &vs){
		if(row==v.size()){
			vs.push_back(v);
			return;
		}
		for(int col=0; col<v.size(); ++col){
			v[row][col]='Q';
			if(isValid(v,row,col)) backtrack(v,row+1,vs);
			v[row][col]='.';
		}
	}
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<string> v(n,string(n,'.'));
		vector<vector<string> > vs;
		backtrack(v,0,vs);
		return vs;
	}
};
