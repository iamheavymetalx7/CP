void searchIsland(std::vector<std::vector<int>>& grid, int i, int j, int& score)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            return;
        }
        

        score++;
        grid[i][j] = 0;
        searchIsland(grid, i + 1, j, score);
        searchIsland(grid, i - 1, j, score);
        searchIsland(grid, i, j + 1, score);
        searchIsland(grid, i, j - 1, score);

    }
    
    

int maxAreaOfIsland(vector<vector<int>>& grid) {

int ret=0;
for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            int score = 0;
            searchIsland(grid, i, j, score);
            ret = max(score, ret);
        }
    }
    
  return ret;
    
 }