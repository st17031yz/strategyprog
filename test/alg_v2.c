#include<stdio.h>


int bool,trust;
const int SCT[2][2]={{5,0},{10,2}}; //onefilematch用


int main (void){
}


int play_0(int ID,int n,int SC[2] , int *H)
{
    int nexthand; // trust　しっぺ返し用
    bool = (SCT[0][1] > SCT[1][0]) ? 0 : 1; //sc01 自分協調(p) sc10 自分裏切り(s)

    if(N<2)nexthand=bool;
    else{
            if(H[2*N] == bool)trust = 1;//裏切りをした時点でtrustが1になりelseの裏切りの選択しか選べなくする

            else if(trust == 0){
                nexthand = (SCT[1-bool][1-bool] > SCT[bool][bool]) ? 1 - bool : bool;
            }//trust==0の時 |\ (相手から反対のの選択を受けていなくq>r高いとき)は相手の選択をコピー

            else{
                nexthand=bool;
            }
    }
    return nexthand;//0 協調 1 裏切り
}
