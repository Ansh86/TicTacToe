#include <bits/stdc++.h>
using namespace std;

char board[3][3] ={{'1', '2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

void drawboard(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"----------\n";
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"----------\n";
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

bool placemarker(int slot){
    int row=slot/3;
     int col;
    if(slot%3==0){
        row=row-1;
         col=2;
    }
    else{
        row=slot/3;
        col=slot%3-1;
    }
    if(board[row][col]!='X' && board[row][col]!='O'){
     board[row][col]=current_marker; 
     return true;
    }

    else{
       return  false;
    }
    
}

int winner(){
    for(int i=0;i<3;i++){
        // ROW
        if(board[i][1]==board[i][0] && board[i][1]==board[i][2] ){
            return current_player;
        }
        // COLOUMN
        if(board[1][i]==board[0][i] && board[2][i]==board[1][i] ){
            return current_player;
        }
        
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return current_player;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return current_player;
    }
    return 0;

}
void swap_player_and_marker(){
    if(current_marker=='X' ){
        current_marker='O';
    }
    else{
        current_marker='X';
    }

    if(current_player==1){
        current_player=2;
    }

    else{
        current_player=1;
    }
}


void game(){
    cout<<" Player 1, Choose your marker: ";
    char marker_pl;
    cin>>marker_pl;
    current_player=1;
    current_marker=marker_pl;
    drawboard();

    int player_won;
    for(int i=0;i<9;i++){
            cout<<"It's Player "<<current_player<<"'s turn. enter Your slot: ";
            int slot;
            cin>>slot;
            if(slot<1 || slot>9){
                cout<<"That slot  ! Try another slot";
            i--;
            continue;
            }
           if(!placemarker(slot)){
            cout<<"That slot occupied ! Try again";
            i--;
            continue;
           }

            
        drawboard();
        player_won=winner();
            if(player_won==1){
                cout<<"Player 1 WON ! CONGRATULATIONS!";
                cout<<endl;
                cout<<endl;
                break;
            }

            if(player_won==2){
                cout<<"Player 2 WON!  CONGRATULATIONS!";
                cout<<endl;
                cout<<endl;
                break;
            }

            swap_player_and_marker();
            cout<<endl;
            cout<<endl;
            cout<<endl; 
            drawboard();
            cout<<endl;
            cout<<endl;
            cout<<endl;
    }

    if(player_won==0){
        cout<<"That is a Tie Game!";
        cout<<endl;
        cout<<endl;
    }
}


int main(){
   game();
}