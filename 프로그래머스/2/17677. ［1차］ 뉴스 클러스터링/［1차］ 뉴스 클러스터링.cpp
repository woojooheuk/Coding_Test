#include <string>
#include <cctype>
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void GetLine(string str, vector<string>& Samples)
{
    string Temp= "";
    int Num = 0;
    int Index = 0;
    int Size = str.size();
    while(Index < Size)
    {
        char TT = tolower(str[Index++]);
        
        if('a' <= TT && TT <= 'z')
        {
            Num++;
            Temp += TT;
        }
        else
        {
            Temp = "";
            Num = 0;
        }
        if(Num >= 2)
        {
            Samples.push_back(Temp);
            Temp = "";
            Num = 0;
            Index--;
        }

    }
    return;
}

bool IsSame(string str1, string str2)
{
    if(str1.size() != str2.size())
        return false;
    
    int Size = str1.size();
    for(int i = 0; i < Size; ++i)
    {
        if(tolower(str1[i]) != tolower(str2[i]))
            return false;
        
    }
    return true;
}


int solution(string str1, string str2) {
    int answer = 65536;
    //5번 13번
    if(IsSame(str1, str2))
        return answer;
    vector<string> One;
    vector<string> Two;
    vector<string> Temp;
    vector<string> Union;
    
    GetLine(str1, One);
    sort(One.begin(),One.end());
    
    GetLine(str2, Two);
    sort(Two.begin(),Two.end());
    
    set_union(One.begin(),One.end(),Two.begin(),Two.end(),back_inserter(Union));
    set_intersection(One.begin(),One.end(),Two.begin(),Two.end(),back_inserter(Temp));
    
    if(Union.empty() == false)
    {
        cout <<  static_cast<float>(Temp.size())/Union.size()<<endl;
        answer *= static_cast<float>(Temp.size())/Union.size();
        
    }
    return answer;
}