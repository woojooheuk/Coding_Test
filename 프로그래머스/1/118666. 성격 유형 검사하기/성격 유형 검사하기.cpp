#include <string>
#include <vector>
#include<map>
#include<iostream>

using namespace std;

char CharTest(char A, char B, map<const char,int>& Points)
{
    if(Points[A] > Points[B])
        return A;
    else if(Points[A] < Points[B])
        return B;
    else
    {
        return min(A,B);
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<const char, int> Points;
    
    Points['R']=0;
    Points['T']=0;
    
    Points['C']=0;
    Points['F']=0;
    
    Points['J']=0;
    Points['M']=0;
    
    Points['A']=0;
    Points['N']=0;

    int Size = survey.size();
    
    for(int i = 0; i < Size; ++i)
    {
        int Point = choices[i] - 4;

        if(Point > 0)
        {
            auto iter = Points.find(survey[i][1]);
            
            if(iter != Points.end())
                iter->second+=Point;
        }
        else
        {
            auto iter = Points.find(survey[i][0]);
            
            if(iter != Points.end())
                iter->second-=Point;
        }
            
        
    }

    answer+=CharTest('R','T',Points);
    answer+=CharTest('C','F',Points);
    answer+=CharTest('J','M',Points);
    answer+=CharTest('A','N',Points);
        
    
    
    return answer;
}