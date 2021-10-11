//https://leetcode.com/problems/minimum-path-sum/submissions/

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int left = 1000000, up = 1000000 ;
            if( i != 0 )
                up = grid[i-1][j];
            if( j != 0 )
                left = grid[i][j-1];
            if( i == j && i == 0 )
                continue;
            grid[i][j] += min( left, up );
        }
    }
    return grid[m-1][n-1];
}
