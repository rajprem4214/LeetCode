class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
                vector<vector<int>> pascal;

	for (int i = 0; i < numRows; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			if (j == 0 or j == i) {
				row.push_back(1);
			}
			else {
				row.push_back(pascal[i - 1][j] + pascal[i - 1][j - 1]);
			}
		}
		pascal.push_back(row);
	}

	return pascal;

    }
};