#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool Is_Speak(string Word, int Pos = 0)
{
    string Temp = "aywm";
    
    cout << Word << endl; 
    for(auto& TT : Temp)
    {
        if(Word[Pos] - TT == 0)
            return true;
    }
    cout << "Word" << endl; 
    
    return false;
};

int solution(vector<string> babbling) {
    int answer = 0;
    
    //aya, ye, woo, ma와 이들을 조합.
    //같은 발음 연속되는 건 불가.
    //yeye같은 거 불가.
    
    vector<string> Bab = {"aya", "ye", "woo", "ma"};
    string Temp = "ayewom";
    
    int Size = babbling.size();
    int Size2 = Bab.size();
    
    for(int i = 0; i < Size; ++i)
    {
        //글자를 잘라서 읽을 수 있는지 확인. 못읽는 거면 다음으로 넘기고 
        //읽을 수 있으면 그 부분 삭제.
        int Prev = -1;
        for(int j = 0; j < Size2; ++j)
        {
            int Length = Bab[j].size();
            string Sub = babbling[i].substr(0,Length);
            if((Sub == Bab[j]) && (Prev != j))
            {
                 babbling[i].erase(0,Length);
                 
                 Prev = j;
                 j = -1;
            }
        }
        
        if(babbling[i].size() == 0)
            answer++;
        
    }
    return answer;
}
