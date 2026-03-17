#include <iostream>
#include <queue>

using namespace std;

int PopQueue(queue<int>& Queue)
{
    int Temp = Queue.front();
    Queue.pop();
    return Temp;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    queue<int> Que;
    for(int i = 1; i <= n; ++i)
    {
        int A = i;
        if(A == a || A == b)
            A = -1;
        Que.push(A);
    }
    
    while(true)
    {
        queue<int> Temp;    
        bool IsFinish = false;
        int Size = Que.size();
        cout << Que.size();
        for(int i = 0; i < Size / 2; ++i)
        {
            int A = PopQueue(Que);
            int B = PopQueue(Que);
            
            if(A == B)
            {
                IsFinish = true;
                break;
            }
            
            if(A == -1 || B == -1)
                Temp.push(-1);
            else
                Temp.push(A);
        }
        
        Que = move(Temp);
        answer++;
        
        if(IsFinish)
            break;
        
    }
    
    return answer;
}