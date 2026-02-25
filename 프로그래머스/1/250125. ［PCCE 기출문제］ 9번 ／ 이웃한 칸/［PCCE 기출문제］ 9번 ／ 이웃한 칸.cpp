#include <string>
#include <vector>

using namespace std;

int Check_Color(vector<vector<string>> board, int h, int w)
{
    string color= board[h][w];
    int Count = 0;
    int Size = board.size();
    //보드 길이가 1일때.
    if(Size == 1)
        return 0;
    
    //보드 길이가 2야. 그러면 사이즈는 2. 
    
    if(h > 0)
    {
        if(board[h-1][w] == color)
            ++Count;
    }
    if(h + 1 < Size)
    {
        if(board[h+1][w] == color)
            ++Count;
    }
    if(w > 0)
    {
        if(board[h][w-1] == color)
            ++Count;
    }
    if(w + 1 < Size)
    {
        if(board[h][w+1] == color)
            ++Count;
    }
    
    
    return Count;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    answer = Check_Color(board,h,w);
    return answer;
}