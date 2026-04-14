#include <string>
#include<iostream>
#include<functional>
#include<set>

using namespace std;

int Ways(string dirs,int Index, int Size, set<pair<array<int,2>,array<int,2>>>& Count, array<int,2> Pos)
{      
    if(Index >= Size)
    {
        return 0;
    }
   
    char CurDir = dirs[Index];

    array<int,2> CurPos = {0,0};
    switch(CurDir)
    {
        case 'U':
            CurPos[1]--;
            break;
        case 'R':
            CurPos[0]++;
            break;
        case 'D':
            CurPos[1]++;
            break;
        case 'L':
            CurPos[0]--;
            break;
    }
    array<int,2> Sum = {Pos[0] + CurPos[0], Pos[1] + CurPos[1]};
    
    if((Sum[0] <= 10 && Sum[0] >= 0) && (Sum[1] <= 10 && Sum[1] >= 0))
    {
        Count.insert({Pos, Sum});
        Count.insert({Sum, Pos});
        Pos = Sum;
    }
    
    return Ways(dirs, Index + 1, Size, Count, Pos);
}

int solution(string dirs) {
    int answer = 0;
    array<int,2> Pos = {5, 5};
    int Size = dirs.size();
    int Index = 0;
    set<pair<array<int,2>,array<int,2>>> Way;

    Ways(dirs, Index, Size, Way, Pos);

    answer+=static_cast<int>(Way.size()) / 2;
    return answer;
}