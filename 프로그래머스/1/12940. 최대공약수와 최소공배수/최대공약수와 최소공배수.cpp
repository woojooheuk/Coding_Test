#include <string>
#include <vector>
#include<iostream>
using namespace std;

int GCD(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
};

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int Num = GCD(n,m);
    answer.push_back(Num);
    answer.push_back(n * m / Num);
    
    cout << Num << endl;
    cout <<  n * m / Num << endl;
    cout << endl;
    return answer;
}