#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include<stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> Temp;
    
    //뒷큰수가 있으면 값 바꾸고, 없으면 냅두기
    int Size = numbers.size();
    answer.resize(Size, -1);
    
    for(int i = Size - 1; i >= 0; --i)
    {
        while(Temp.empty() == false)
        {
            //Temp.top()은 이전 인덱스.
            //numbers[Temp.top()]이 이전 값.
            if(numbers[Temp.top()] > numbers[i])
            {
                //이전 값이 현재 값보다 크면
                answer[i] = numbers[Temp.top()];
                break;
            }
            else
                Temp.pop();
        }
        
        Temp.push(i);
    }
    
    
    return answer;
}