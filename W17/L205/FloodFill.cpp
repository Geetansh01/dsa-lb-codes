#include<bits/stdc++.h>
using namespace std;

//TC : O(m*n) {ATQ, An image is represented by an m x n integer grid "image"}
void dfsTrav(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited){
    int startingColor = image[sr][sc];
    image[sr][sc] = color;
    visited[sr][sc] = true;

    vector<int> dx{0, +1, 0, -1};
    vector<int> dy{-1, 0, +1, 0};
    for(int i = 0; i < 4; i++){
        int newX = sr + dx[i];
        int newY = sc + dy[i];

        if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size()){
            if(image[newX][newY] == startingColor && visited[newX][newY] == false){
                dfsTrav(image, newX, newY, color, visited);
            }
        }
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int row = image.size();
    int col = image[0].size();

    //I could've changed the input "image" itself but generally it's a good practice to not change what was given to you in input!
    vector<vector<int>> MyImage = image;

    vector<vector<int>> visited(row, vector<int>(col, 0));
    dfsTrav(MyImage, sr, sc, color, visited);

    return MyImage;
}

int main(){
   
return 0;
}