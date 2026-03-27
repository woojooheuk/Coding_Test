#include <string>
#include <vector>
#include<stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int Temp = 0;
    
    
    //순서상 뒷 기능이 먼저 개발돼도 앞 기능이 배포가 안되면 배포 못함.
    //배포될 때마다 몇 개의 기능이 동시에 배포되는지 반환.
    //vector의 i가 100인지 확인 후 100이면 i++, 스택에 그거 추가. 이후도 같은지 확인.
    
    int Size = progresses.size();
    
    int Index = 0;
    
    while(true)
    {
        if(Temp != 0)
        {
            answer.push_back(Temp);
            Temp = 0;
            
            if(Index == Size)
                break;
        }
        
        int TempIndex = Index;
        for(int i = TempIndex; i < Size; ++i)
        {
            progresses[i] += speeds[i];
            if(progresses[Index] >= 100)
            {
                Index++;
                Temp++;
            }
        }
    }
    
    return answer;
}