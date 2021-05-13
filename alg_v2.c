#include<stdio.h>

int main (void){
}

/*
SCT[0][1] = (p)自分協調、相手裏切り
SCT[1][0] = (s)自分裏切り、相手協調

p,sのうち、得点が高いほうの選択（協調 or 裏切り）をboolとする
bool = (SCT[0][1] > SCT[1][0]) ? 0 : 1; 
*/


//２連not bool
int play_0(int ID,int n,const int SCT[2][2] , int *H)
{
    int nexthand,bool;  
    // 相手のIDに変更
    ID ^= 1; 
    // p,sのうち、得点が高いほうの選択（協調 or 裏切り）をboolとする
    bool = (SCT[0][1] > SCT[1][0]) ? 0 : 1;

    // 対戦回数が２回目以下の時、boolを選択
    if(n<2)nexthand=bool; 

    // 対戦回数が３回目以上の時
    else{ 
        // 相手の直近２回の選択がどちらもnot boolの時
        if( *(H+2*(n-1)+ID) != bool && *(H+2*(n-2)+ID) != bool){
            //(互いにnotboolを選んだ場合 > 互いにboolの場合)  かつ　(互いにnotboolを選んだ場合 > p,sのうち得点が高い方) ならば、notboolを選択
            nexthand = ((SCT[1-bool][1-bool] > SCT[bool][bool]) && (SCT[1-bool][1-bool] > SCT[bool][1-bool])) ? 1 - bool : bool;
        }

        // 相手の直近２回の選択にboolが含まれている時、boolを選択
        else{
            nexthand = bool;
        }
    }
    // 0 協調 1 裏切り
    return nexthand;
}

// ２連not bool＋相手のbool一生許さない
int play_0(int ID,int n,const int SCT[2][2] , int *H)
{
    int nexthand,bool;
    // trust　しっぺ返し用
    static int trust;
    // 相手のIDに変更
    ID ^= 1; 
    // p,sのうち、得点が高いほうの選択（協調 or 裏切り）をboolとする
    bool = (SCT[0][1] > SCT[1][0]) ? 0 : 1; 

    // 対戦回数が２回目以下の時、boolを選択
    if(n<2)nexthand=bool;

    // 対戦回数が３回目以上の時
    else{
        // 相手の直近２回の選択がどちらもnot bool かつ　過去に一度もboolを選択したことがない時
        if((*(H+2*(n-1)+ID) != bool && *(H+2*(n-2)+ID) != bool) && trust != 1){
            //(互いにnotboolを選んだ場合 > 互いにboolの場合)  かつ　(互いにnotboolを選んだ場合 > p,sのうち得点が高い方) ならば、notboolを選択
            nexthand = ((SCT[1-bool][1-bool] > SCT[bool][bool]) && (SCT[1-bool][1-bool] > SCT[bool][1-bool])) ? 1 - bool : bool;
        }

        // 相手の過去の選択にboolが含まれている時、boolを選択
        else{
            nexthand = bool;
            // 相手がboolを選択したことを記録
            trust = 1;
        }
    }
    // 0 協調 1 裏切り
    return nexthand; 
}

