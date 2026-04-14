#include <string>
#include <vector>
#include<functional>
#include<iostream>

using namespace std;

int solution(string word) {
    int answer = 0;
    //기본 정렬 순서. DFS 방식인듯
    //A E I O U 순서로
    
    //현재 단어, 카운트
    function<bool(string)> DFS;
    
    int Num = 0;
    DFS = [&](string CurWord){
        if(CurWord == word)
        {
            answer = Num;
            return true;
        }
        if(CurWord.size() >= 5)
        {
            return false;
        }
        Num++;
        DFS(CurWord+"A");
        Num++;
        DFS(CurWord+"E");
        Num++;
        DFS(CurWord+"I");
        Num++;
        DFS(CurWord+"O");
        Num++;
        DFS(CurWord+"U");

        return true;
    };
    
    string Temp="";
    DFS(Temp);
    return answer;
}