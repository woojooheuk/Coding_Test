#include <string>
#include <vector>
#include<sstream>

using namespace std;

int To_Sum(string Times)
{
    stringstream ss(Times);
    int Min;
    int Sec;
    
    ss>>Min;
    ss.get();
    ss>>Sec;
    
    return Min * 60 + Sec;
}

string To_Word(int Sum)
{
    string Word = "";
        int Min = Sum / 60;
    int Sec = Sum % 60;
    
    if(Min < 10)
        Word+="0";
    Word +=to_string(Min);
    Word +=":";
    
    if(Sec < 10)
        Word+="0";
    Word +=to_string(Sec);
    
    return Word;
}

int Time_Control(string Command, int VideoLen, int CurTime, int Op_Start, int Op_End)
{
    int PlusTime = 10;

    if(Command == "prev")
        PlusTime*=-1;
    
    CurTime+=PlusTime;
    
    if(CurTime <= 0)
        CurTime = 0;
    else if(CurTime >= VideoLen)
        CurTime = VideoLen;
    
    if(Op_Start <= CurTime && CurTime <= Op_End)
        CurTime = Op_End;
    

    
    return CurTime;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int OpS = To_Sum(op_start);
    int OpE = To_Sum(op_end);
    int Len = To_Sum(video_len);
    int Pos = To_Sum(pos);
    
    int Size = commands.size();
    
    if(OpS <= Pos && Pos <= OpE)
        Pos = OpE;
    
    for(int i = 0; i < Size; ++i)
    {
        Pos = Time_Control(commands[i], Len, Pos, OpS, OpE);
    }
    //3번. 0도, 영상 끝도 아님.
    answer = To_Word(Pos);
    answer = To_Word(Pos);

    return answer;
}