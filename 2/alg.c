#include<stdio.h>
int main (void){
    int SC[2][2];
    //IDの値は詳しくわかってない
}

int play(int ID,int N,int SC[2] , int *H){
    int nexthand,bool,trust; // trust　しっぺ返し用
    (SC[0][1] > SC[1][0]) ? bool = 0 , bool = 1; //sc01 自分協調(p) sc10 自分裏切り(s)

    if(N<2)nexthand=bool;
    else{
            if(H[2*N] == bool)trust = 1;//裏切りをした時点でtrustが1になりelseの裏切りの選択しか選べなくする

            else if(trust == 0){
                (SC[1-bool][1-bool] > SC[bool][bool]) ? nexthand = 1 - bool , nexthand = bool;
            }//trust==0の時 |\ (相手から反対のの選択を受けていなくq>r高いとき)は相手の選択をコピー

            else{
                nexthand=bool;
            }
    }
    return nexthand;//0 協調 1 裏切り
}
