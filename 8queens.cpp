#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

void printBoard(vector<vector<int>> & board, int size) // prints current state of board
{
    for(int j = size-1; j >= 0; --j)
    {
        for(int i = 0; i < size; i++)
        {

            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkSafe(int x, int y, const vector<vector<int>> & board, int size) // places queen and changes board accordingly
{
    for(int i = 0; i < size; i++)
    {
        if(board[i][y] == 1 || board[x][i] == 1)
        {
            return false;
        }
    }
    int i = 1;
    while(x+i < size && y+i < size)
    {
        if(board[x+i][y+i] == 1)
        {
            return false;
        }
        ++i;
    }
    i = 1;
    while(x+i < size && y-i >= 0)
    {
        if(board[x+i][y-i] == 1)
        {
            return false;
        }
        ++i;
    }
    i = 1;
    while(x-i >=0 && y+i < size)
    {
        if(board[x-i][y+i] == 1)
        {
            return false;
        }
        ++i;       
    }
    i = 1;
    while(x-i >= 0 && y-i >= 0)
    {
        if(board[x-i][y-i] == 1)
        {
            return false;
        }
        ++i;        
    }
    return true;
}

int queen(int row, vector<vector<int>> &board, int size)
{
    vector<vector<int>> boardCopy = board;
    long long unsigned int count = 0;
    if(row == size)
    {
        //printBoard(board, size);
        return 1;
    }

    for(int x = 0; x < size; ++x)
    {
            if(checkSafe(x, row, board, size))
            {   
                board[x][row] = 1;
                count += queen(row + 1, board, size);
                board[x][row] = 0;
            }
    }

    return count;
    

}


int main()
{
    int size;
    cout << "enter size of board: ";
    cin >> size;
    vector<vector<int>> board(size, vector<int> (size));

    cout << queen(0,board, size) << endl;

    

    return 0;
}