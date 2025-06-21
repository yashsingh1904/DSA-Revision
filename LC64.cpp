//this is a recursive problem 

/****************************************************************************/

//solution 1 : Recusrion can give Time limit exceed 

class Solution {

    //lest write recursive functiojnt to count minpath from given row col to 0,0 
  
public:
    int minPath(int row,int col,vector<vector<int>>&grid){
        //base cases 
        if(row<0 || col<0){
            //not a possible path
            return 1e6;
        }

        if(row==0 && col==0){
            //reach at destination 
            return grid[0][0];
        }


        // //rest cases or major cases 
        // int left_path=INT_MAX;
        // int top_path=INT_MAX;

     int left=grid[row][col]+ minPath(row,col-1,grid);
        int right=grid[row][col]+minPath(row-1,col,grid);

        return min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        return minPath(row,col,grid);

        
        
    }
};


/****************************************************************************/

//solution 2 : Recusrion with memoization
class Solution {

    //lest write recursive functiojnt to count minpath from given row col to 0,0 
  
public:
    int minPath(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&DP){
        //base cases 
        if(row<0 || col<0){
            //not a possible path
            return 1e6;
        }

        if(row==0 && col==0){
            //reach at destination 
            return grid[0][0];
        }

        if(DP[row][col])return DP[row][col];

        // //rest cases or major cases 
        // int left_path=INT_MAX;
        // int top_path=INT_MAX;

      int left=grid[row][col]+ minPath(row,col-1,grid,DP);
        int up=grid[row][col]+minPath(row-1,col,grid,DP);

        return DP[row][col]= min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>DP(row,vector<int>(col,0));
             return minPath(row-1,col-1,grid,DP);

        
        
    }
};




