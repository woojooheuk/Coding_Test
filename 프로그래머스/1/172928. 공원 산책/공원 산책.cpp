#include <string>
#include <vector>
#include<sstream>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    string Direction;
    int Count;

    //W랑 E는 string의 Index에 영향.
    //N랑 S는 vector의 Index에 영향.
    int StringIndex = 0;
    int VectorIndex = 0;
    int Size = park.size();
    
    for(int i = 0; i < Size; ++i)
    {
        int Length = park[i].size();
        bool Find=false;
        for(int j = 0; j < Length; ++j)
        {
            if(park[i][j] == 'S')
            {
                StringIndex = j;
                VectorIndex = i;
                Find=true;
                break;
            }
        }
        if(Find)
            break;
    }
    Size = routes.size();
    
    for(int i = 0; i < Size; ++i)
    {
        string Temp  =routes[i];
        stringstream ss(Temp);
        
        ss >> Direction;
        ss >> Count;
        
        if(Direction == "E")
        {
            int Range = park[VectorIndex].length();

            bool IsMove = true;
            int Will = 0;
            for(int j = 1 ; j <= Count; ++j)
            {
                Will = StringIndex + j;
                if(Will >= Range || park[VectorIndex][Will] == 'X')
                {
                    IsMove = false;
                    break;
                }
            }
            
            if(IsMove)
            {
                StringIndex = Will;
            }
        }
        else if(Direction == "W")
        {
            int Range = park[VectorIndex].size();
 
            bool IsMove = true;
            int Will = 0;
            for(int j = 1 ; j <= Count; ++j)
            {
                Will = StringIndex - j;
                if(Will < 0 || park[VectorIndex][Will] == 'X')
                {
                    IsMove = false;
                    cout << "W" <<endl;
                    break;
                }
            }
            if(IsMove)
            {
                StringIndex = Will;
            }
        }
        else if(Direction == "N")
        {
            int Range = park.size();
            
            bool IsMove = true;
            int Will = 0;
            for(int j = 1 ; j <= Count; ++j)
            {
                Will = VectorIndex - j;
                if(Will < 0 || park[Will][StringIndex] == 'X')
                {
                    IsMove = false;
                    cout << "N" <<endl;
                    break;
                }
            }
            if(IsMove)
            {
                VectorIndex = Will;
            }
        }
        else if(Direction == "S")
        {
            int Range = park.size();
            
            bool IsMove = true;
            int Will = 0;
            for(int j = 1 ; j <= Count; ++j)
            {
                Will = VectorIndex + j;
                if(Will >= Range || park[Will][StringIndex] == 'X')
                {
                    IsMove = false;
                    cout << "S" <<endl;
                    break;
                }
            }
            if(IsMove)
            {
                VectorIndex = Will;
            }
        }
        cout << VectorIndex <<" " <<StringIndex << endl;
    }
    answer.push_back(VectorIndex);
    answer.push_back(StringIndex);
    return answer;
}