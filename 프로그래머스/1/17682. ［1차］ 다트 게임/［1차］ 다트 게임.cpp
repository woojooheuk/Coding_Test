#include <string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Times(char A)
{
    int Time = 0;
    switch(A)
    {
        case 'S':
            Time = 1;
            break;
        case 'D':
            Time = 2;
            break;
        case 'T':
            Time = 3;
            break;
    }
    
    return Time;
}

int Bonus(char A)
{
    int Bonus = 0;
    
    switch(A)
    {
        case '#':
            Bonus = -1;
            break;
        case '*':
            Bonus = 2;
            break;
    }
    
    return Bonus;
}

int solution(string dartResult) {
    int answer = 0;
    int Size = dartResult.size();
    int Point = 0;
    int Index = 0;
    
    vector<int> Points;
    while(Index < Size)
    {
        string TempPoint;
        while(true)
        {
            if(dartResult[Index] > 'A')
                break;
            TempPoint += dartResult[Index++];
        }
        int Point = stoi(TempPoint);
        int Square = Times(dartResult[Index++]);
        int Temp = 1;
        
        for(int j = 0; j < Square; ++j)
            Temp *= Point;
        
        Point = Temp;
        Points.push_back(Point);
        
        if(dartResult[Index] == '#')
        {
            Points.back() *= -1;
            Index++;
        }
        else if(dartResult[Index] == '*')
        {
            Index++;
            int Temp = Points.size();
            for(int j = 1; j <= 2; ++j)
            {
                int Pos = Temp - j;
                if(Pos < 0)
                    break;
                Points[Pos] *= 2;
            }
        }
    }
    
    for(auto& PP : Points)
        answer+=PP;
    
    return answer;
}