/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K),
your task is to replace color of the given pixel and
all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:
{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };
 x=4, y=4, color=3

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.
*/
#include <iostream>
using namespace std;

void floodfill(int **arr, int m, int n, int x, int y, int k)
{
    int tmp = arr[x][y];
    arr[x][y] = k;
    // Top
    if( x-1 >= 0 && tmp == arr[x-1][y])
    {
        // cout<<"Top"<<endl;
        floodfill(arr, m, n, x-1, y, k);
    }
    // Right
    if( y+1 < n && tmp == arr[x][y+1])
    {
        // cout<<"Right"<<endl;
        floodfill(arr, m, n, x, y+1, k);
    }

    // Down
    
    if( x+1 <m && tmp == arr[x+1][y])
    {
        // cout<<"Down"<<endl;
        floodfill(arr, m, n, x+1, y, k);
    }

    // Left
    if( y-1 >= 0 && tmp == arr[x][y-1])
    {
        // cout<<"Left"<<endl;
        floodfill(arr, m, n, x, y-1, k);
    }
    arr[x][y] = k;
    return;
}

int main(void)
{
    int T, m, n, x, y, k;
    cin >> T;
    // For all the test cases
    for(int t=0; t<T; t++)
    {
        cin >> m >> n;
        int **arr;
        arr = new int* [m];
        for(int i=0; i<m; i++)
            arr[i] = new int[n];
        // Take the array input rrom the user
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin >> arr[i][j];
        cin >> x >> y >> k;

        floodfill(arr, m, n, x, y, k);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cout << arr[i][j] <<" ";
        cout<<endl;

    }
    return 0;
}