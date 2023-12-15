#include<bits/stdc++.h>
using namespace std;


int win(char grid[][3]){                         // check karta hai ki koi line same hua ki nahi.

    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2])
    {
        return 1;
    }
    else if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2])
    {
        return 1;
    }
    else if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2])
    {
        return 1;
    }
    else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])
    {
        return 1;
    }
    else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1])
    {
        return 1;
    }
    else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2])
    {
        return 1;
    }
    else if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    {
        return 1;
    }
    else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        // cout<<"111";
        return 1;
    }
    else{
        return 0;
    }
}

void prNT(char grid[][3]){                                  // Grid print karta hai.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

int main()
{
    cout<<"Player 1 - X"<<endl<<"Player 2 - O"<<endl<<endl;
    
    char grid[3][3]={{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

    prNT(grid);

    int turn=0;
    
    while(!win(grid))                                       // jab tak grid ka koi line bhar nahi ho jata chalte raho.
    {
        turn++;
        char update; 
        int place;

        if( turn%2 == 1 )                                   // turn by turn
        {
            cout<<"Player - 1 [X] turn : ";
            cin>>place;
            update = 'X';
        }
        else
        {
            cout<<"Player - 2 [O] turn : ";
            cin>>place;
            update = 'O';
        }

        
        switch (place)                                      // Updatte X or O at given place
        {
        case 1:
            grid[0][0]=update;
            break;
        case 2:
            grid[0][1]=update;
            break;
        case 3:
            grid[0][2]=update;
            break;
        case 4:
            grid[1][0]=update;
            break;
        case 5:
            grid[1][1]=update;
            break;
        case 6:
            grid[1][2]=update;
            break;
        case 7:
            grid[2][0]=update;
            break;
        case 8:
            grid[2][1]=update;
            break;
        case 9:
            grid[2][2]=update;
            break;
        default:

            break;
        }

        // grid[0][2] = 'X';                 // random cheaks/test point.
        // grid[1][1] = 'X';
        // grid[2][0] = 'X';

        prNT(grid);

        if(turn==9) break;                    // 9 bar chal gaya matlab khatam
    }

    if(win(grid))                                    // if 9 inputs are filled and no lines simmilar, then draw.
    {
        turn--;
        cout<<"Player "<<(turn%2)+1<<" is the WINNER..";
    }
    else
    {
        cout<<"DRAW";
    }
    return 0;
}