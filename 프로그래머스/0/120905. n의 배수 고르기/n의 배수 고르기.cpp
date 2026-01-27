#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> Find_if(int n, vector<int> numlist)
{
    int Size = numlist.size();
    //cout << Size << endl;
    vector<int> Temp;
    for(int i=0; i<Size; ++i)
    {
        if(numlist[i] % n == 0)
        {
            Temp.push_back(numlist[i]);            
        }
    }
    return Temp;
};


vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    
    
    return Find_if(n,numlist);
}