#include <string>
#include <vector>
#include<iostream>

using namespace std;

int Exchange(int Divide, int NewBottle, int Bottle, int WholeBottle)
{
    WholeBottle += (Bottle / Divide) * NewBottle;
    if(Bottle < Divide)
    {
        return WholeBottle;
    }   
    
    
    cout << "A : " << Divide << " B : " << NewBottle <<
        " C : " << Bottle<< " D: "<< WholeBottle << endl;
    
    return Exchange(Divide, NewBottle, 
                    (Bottle / Divide) * NewBottle + (Bottle % Divide),WholeBottle);
}

int solution(int a, int b, int n) {
    int answer = 0;

    answer = Exchange(a,b,n,0);
    
    cout<<answer<<endl;
    return answer;
}