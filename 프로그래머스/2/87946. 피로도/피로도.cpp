#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

int DFS(vector<vector<int>>& Dungeons, vector<bool>& Visited, int Size, int k, int Num)
{
    //현재까지 회차에서 방문한 횟수
    int Count = Num;
    
    //다음 방을 방문했을 때의 결과를 이번 방에서 미리 반영하지 마라.
    for(int i = 0; i < Size; ++i)
    {       
        //현재 가려는 곳이 이번 회차에서 갔던 곳인지 확인 + 피로도가 허용하는지. 
        //안되면 다음으로 이동.
        if(Visited[i] || k < Dungeons[i][0])
            continue;
            
        //이번 회차에 여기 왔다 표시
        Visited[i]=true;
        //피로도 감소
        
        //방문 횟수 증가
        //다음 방문
        int NewCount = DFS(Dungeons, Visited, Size, k-Dungeons[i][1], Num + 1);
        Count = max(NewCount, Count);
        //갔다가 나왔으니 해당 구역 방문 취소.
        Visited[i] = false;
    }
    return Count;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    int Size = dungeons.size();
    vector<bool> Visited;
    Visited.resize(Size, false);
    answer = DFS(dungeons,Visited,Size,k,0);
    return answer;
}