#include <string>
#include <vector>
#include<iostream>
#include<bitset>
using namespace std;

constexpr int SIZE = 16;

vector<bitset<SIZE>> BitSet(int Size, vector<int> Array)
{
    vector<bitset<SIZE>> Temp;
    
    for(int i = 0; i < Size; ++i)
    {
        bitset<SIZE> Bit(Array[i]);
        Temp.push_back(Bit);
    }
    
    return Temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<bitset<SIZE>> Temp1;
    vector<bitset<SIZE>> Temp2;
    
    Temp1 = BitSet(n, arr1);
    Temp2 = BitSet(n, arr2);
    
    for(int i = 0; i < n; ++i)
    {
        string Temp="";
        for(int j = n - 1; j >= 0; --j)
        {
            if(Temp1[i][j] | Temp2[i][j])
                Temp+="#";
            else
                Temp+=" ";
        }
        answer.push_back(Temp);

    }
    return answer;
}