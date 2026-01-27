#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    char Melon[] = "수박";
    
    int Num = n / 2;
    int Temp = n % 2;
    
    for(int i = 0; i < Num; ++i)
    {
        answer += Melon;
    }

    if(Temp != 0)
        answer += "수";
    
    return answer;
}