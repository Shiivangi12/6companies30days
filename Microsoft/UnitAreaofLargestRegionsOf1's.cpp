#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL)
           && (M[row][col] && !visited[row][col]);
}

void DFS(int M[][COL], int row, int col,
         bool visited[][COL], int& count)
{
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    visited[row][col] = true;
    for (int k = 0; k < 8; ++k)
    {
        if (isSafe(M, row + rowNbr[k],
                   col + colNbr[k],
                   visited))
        {

            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}

int largestRegion(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {

            if (M[i][j] && !visited[i][j])
            {
                DFS(M, i, j, visited, count);

                result = max(result, count);
            }
        }
    }
    return result;
}
int main()
{
    int M[][COL] = { { 0, 0, 1, 1, 0 },
                     { 1, 0, 1, 1, 0 },
                     { 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);

    return 0;
}
