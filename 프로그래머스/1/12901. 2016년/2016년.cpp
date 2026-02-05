#include <string>
#include <vector>
#include<iostream>

using namespace std;

int CalcDays(int Month)
{
    int Days = 0;
    
    for(int i = 1; i < Month; ++i)
    {
        switch(i)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                Days += 31;
                break;
            case 4: case 6: case 9: case 11:
                Days += 30;
                break;
            case 2:
                Days += 29;
                break;
            default:
                return -1;
        }
    }
    return Days;
}

string solution(int a, int b) {
    string answer = "";
    
    //월마다 마지막 날짜가 언제인지 알아야함.
    //1월 1일부터 12월 31일까지 7로 %연산 해서 남는 값으로 요일 판별하기.
    //0:일, 1:월 2:화 3:수 4:목 5:금 6:토
    
    //월마다 날짜 몇인지 계산. a월 b일을 a월까지 총 날짜가 얼마인지 계산 + b일 % 7하기.
    //accumulate쓰기.
  
    int Days = CalcDays(a) + b;
    cout << Days << " " << (Days + 5)%7<<endl;
    switch((Days + 4)%7)
    {
        case 0:
            answer="SUN";
            break;
            
        case 1:
            answer="MON";
            break;
            
        case 2:
            answer="TUE";
            break;
            
        case 3:
            answer="WED";
            break;
            
        case 4:
            answer="THU";
            break;
            
        case 5:
            answer="FRI";
            break;
            
        case 6:
            answer="SAT";
            break;
            
    }
    return answer;
}