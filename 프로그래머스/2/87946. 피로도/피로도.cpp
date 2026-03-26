#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //완전탐색. 가장 많이 방문한 던전 수.
    //이미 방문한 곳은 방문하면 안됨.
    for(auto& Vector : dungeons)
        Vector.push_back(0);
    
    //0은 탐사 안한 거, 1은 탐사한 거
    int Num = 0;
    function<void(int,int)> DFS;
    DFS = [&](int Num, int k){
        //현재 피로도와 최소 피로도 비교 및 Vector[2]가 0인지 확인.
        answer = max(answer,Num);
        for(auto& Vector : dungeons)
        {
            if(Vector[2] == 1 || k < Vector[0])
                continue;
            
            Vector[2] = 1;
            DFS(Num + 1, k - Vector[1]);
            Vector[2] = 0;
        }
    };
    
    DFS(0, k);
    
    return answer;
}