#include <string>
#include <vector>
#include<functional>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int Size = numbers.size();
    function<void(int, int)> DFS;
    DFS = [&](int Index, int Sum){
        if(Index >= Size)
        {
            if(Sum == target)
                answer++;
            return;
        }
        DFS(Index + 1, Sum + numbers[Index]);
        DFS(Index + 1, Sum - numbers[Index]);
    };
    
    DFS(0,0);
    
    return answer;
}