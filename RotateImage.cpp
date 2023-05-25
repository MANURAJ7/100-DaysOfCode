void rotate(vector<vector<int>> &matrix)
{

    int r = matrix.size();
    int c = matrix.size();

    vector<vector<int>> ans;
    vector<int> temp;

    for (int col = 0; col < c; col++)
    {
        for (int row = c - 1; row >= 0; row--)
        {
            temp.push_back(matrix[row][col]);
        }
        ans.push_back(temp);
        temp.clear();
    }

    matrix = ans;
};