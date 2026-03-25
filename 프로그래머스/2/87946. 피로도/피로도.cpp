#include <string>
#include <vector>

using namespace std;

int DFS(vector<vector<int>>& dungeons, vector<bool>& Visited, int Size, int k, int Num)
{
    //현재까지 방문한 숫자 저장.
    int Count = Num;
    
    for(int i = 0; i < Size; ++i)
    {
        //스킵 조건 확인.
        if(Visited[i] == true || k < dungeons[i][0])
            continue;
        
        Visited[i] = true;
        
        //다음 방 탐색. 이번 방을 통과했다는 조건으로 피로도 감소, 방뭇 횟수 증가.
        Count = max(DFS(dungeons, Visited, Size, k - dungeons[i][1], Num + 1),Count);
        //이번 방을 들어갔을 때 할 수 있는 모든 경우의 수 탐색 완료. 방문 취소.
        Visited[i] = false;
    }
    return Count;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //DFS. 자신이 방문했던 곳 표시.
    //방문했거나, 최소 피로도보다 내 피로도가 작으면 스킵.
    
    int Size = dungeons.size();
    vector<bool> Visited;
    Visited.resize(Size, false);
    
    answer = DFS(dungeons,Visited,Size,k,0);
    return answer;
}