#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Info{
    int Row = 0;
    int Col = 0;
    int Dist = 1;
    };

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    queue<Info> Q;
    
    int RowCount = maps.size();
    int ColCount = maps[0].size();

    vector<vector<bool>> Visited(RowCount,vector<bool>(ColCount,false));
    Info First;
    Q.push(First);
    //                 위  오 아  왼
    vector<int> Row = {-1, 0, 1, 0};
    vector<int> Col = {0, 1, 0, -1};
    Visited[0][0] = true;

    while(Q.empty() == false)
    {
        Info CurInfo = Q.front();
        Q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            Info info;
            info.Row = CurInfo.Row + Row[i];
            info.Col = CurInfo.Col + Col[i];
            info.Dist = CurInfo.Dist + 1;
            if(info.Row < 0 || info.Row >= RowCount)
                continue;
            if(info.Col < 0 || info.Col >= ColCount)
                continue;

            if(maps[info.Row][info.Col] == 0)
                continue;
            if(Visited[info.Row][info.Col] == true)
                continue;
            Visited[info.Row][info.Col] = true;
            
            if(info.Row == RowCount - 1 && info.Col == ColCount - 1)
                return info.Dist;
            Q.push(info);
        }
    }
    return answer;
}