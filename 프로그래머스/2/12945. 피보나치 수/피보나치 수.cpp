#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Repeat_Fibo(int N, int Mod)
{
    if(N <=1)
        return N;
    
    int A = 0;
    int B = 1;
    
    for(int i = 1; i < N; ++i)
    {
        int C = (A + B) % Mod;
        A = B;
        B = C;
    }
    
    return B;
}

int solution(int n) {
    int answer = 0;
    int Mod = 1234567;
    answer = Repeat_Fibo(n, Mod);
    return answer;
}