/* Ques: An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color 
as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.*/

class Solution {
public:

    void dfs(vector<vector<int>>& image, int i,int j, int initialColor,int newColor){
        int n= image.size();
        int m = image[0].size();
        if(i<0 || j<0) return;
        if(i>=n || j>=m) return;
        if(image[i][j] != initialColor) return;
        image[i][j]=newColor;

        dfs(image,i-1,j,initialColor,newColor);
        dfs(image,i+1,j,initialColor,newColor);
        dfs(image,i,j-1,initialColor,newColor);
        dfs(image,i,j+1,initialColor,newColor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor=image[sr][sc];
        if(initialColor!=newColor){
            dfs(image,sr,sc,initialColor,newColor);
        }
        return image;
    }
};
