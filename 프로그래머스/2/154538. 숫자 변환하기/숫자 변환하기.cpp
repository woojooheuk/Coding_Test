#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

struct Info{
    int Num = 0;
    int Count = 0;
};

int solution(int x, int y, int n) {
    int answer = 0;
    //x에 n을 더하고 2를 곱하고 3을 곱하기만 할 수 있다.

    Info Temp;
    Temp.Num = x;
    queue<Info> Queue;
    Queue.push(Temp); 
    set<int> Re;
    Re.insert(Temp.Num);
    
    while(Queue.empty()== false)
    {
        Info CurNum = Queue.front();
        Queue.pop();

        if(CurNum.Num == y)
            return CurNum.Count;
        else if(CurNum.Num > y)
            continue;
        
        Temp.Count = CurNum.Count + 1;
        Temp.Num = CurNum.Num + n;
        
        if(Re.find(Temp.Num) == Re.end())
        {
            Queue.push(Temp);
            Re.insert(Temp.Num);
        }
        
        Temp.Num = CurNum.Num * 2;
        if(Re.find(Temp.Num) == Re.end())
        {
            Queue.push(Temp);
            Re.insert(Temp.Num);
        }
        Temp.Num = CurNum.Num * 3;
        if(Re.find(Temp.Num) == Re.end())
        {
            Queue.push(Temp);
            Re.insert(Temp.Num);
        }
    }
    answer = -1;
    return answer;
}