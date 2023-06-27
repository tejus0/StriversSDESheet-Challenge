
void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int newcolor, int delRow[],int delCol[],int inicolor){
	
	
	//what to pass 
	//1.orig image 
	//2.copied image
	//3.newcolor &&initialcolor
	//4.delrow delcol for 4 directions 
	//5.sr and sc 
     ans[row][col]=newcolor;//first make the sr and sc only with newcolor 
     int n=image.size();
     int m=image[0].size();
     for(int i=0;i<4;i++)//go inoto 4 directions 
     {
         int nrow= row+delRow[i]; //get to that newrownewcol 
         int ncol= col+delCol[i];
         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor &&
           ans[nrow][ncol]!=newcolor)
		   //check if it is within boundary and initial grid color and current grid coor is same and in copied matricx that //grid is not filled with newcolor 
     //call dfs         
     dfs(nrow,ncol,ans,image,newcolor,delRow,delCol,inicolor);
     }
    }

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Write your code here.
    int inicolor= image[sr][sc];
        vector<vector<int>>& ans=image;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,newColor,delRow,delCol,inicolor);
        return ans;
}