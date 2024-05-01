#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findBiggestRectangle(int row, int col, int towers, vector<pair<int, int>> &locs)
{
    // For X axis
    vector<int> towersX;

    // Push 2 dummy towers at x = 0 & x = col + 1;
    towersX.push_back(0);
    towersX.push_back(col + 1);
    for (int i = 0; i < locs.size(); i++)
    {
        towersX.push_back(locs[i].first);
    }
    sort(towersX.begin(), towersX.end());

    // For Y axis
    vector<int> towersY;

    // Push 2 dummy towers at x = 0 & x = col + 1;
    towersY.push_back(0);
    towersY.push_back(row + 1);
    for (int i = 0; i < locs.size(); i++)
    {
        towersY.push_back(locs[i].second);
    }
    sort(towersY.begin(), towersY.end());

    // Find max empty space on X axis
    int xDiff = INT_MIN;
    for (int i = 1; i < towersX.size(); i++)
    {
        int diff = towersX[i] - towersX[i - 1] - 1;
        xDiff = max(xDiff, diff);
    }

    // Find max empty space on Y axis
    int yDiff = INT_MIN;
    for (int i = 1; i < towersY.size(); i++)
    {
        int diff = towersY[i] - towersY[i - 1] - 1;
        yDiff = max(yDiff, diff);
    }

    return xDiff * yDiff;
}

int main()
{
    int testcases = 0;
    cin >> testcases;

    for (int testcase = 0; testcase < testcases; testcase++)
    {
        int rows = 0;
        int cols = 0;
        int towers = 0;
        cin >> rows >> cols >> towers;

        vector<pair<int, int>> locs(towers);

        for (int i = 0; i < towers; i++)
        {
            int row, col = 0;
            cin >> col >> row;

            locs[i] = {row, col};
        }

        int ans = findBiggestRectangle(rows, cols, towers, locs);
        cout << ans << endl;
    }

    return 0;
}