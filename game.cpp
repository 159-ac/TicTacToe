#include<bits/stdc++.h>
using namespace std;


int win(char grid[9]){                           // check karta hai ki koi line same hua ki nahi.

    if(grid[0] == grid[1] && grid[1] == grid[2])
    {
        return 1;
    }
    else if(grid[3] == grid[4] && grid[4] == grid[5])
    {
        return 1;
    }
    else if(grid[6] == grid[7] && grid[7] == grid[8])
    {
        return 1;
    }
    else if(grid[0] == grid[3] && grid[3] == grid[6])
    {
        return 1;
    }
    else if(grid[1] == grid[4] && grid[4] == grid[7])
    {
        return 1;
    }
    else if(grid[2] == grid[5] && grid[5] == grid[8])
    {
        return 1;
    }
    else if(grid[0] == grid[4] && grid[4] == grid[8])
    {
        return 1;
    }
    else if(grid[2] == grid[4] && grid[4] == grid[6])
    {
        // cout<<"111";
        return 1;
    }
    else{
        return 0;
    }
}

void prNT(char grid[9]){                                  // Grid print karta hai.
    for (int i = 0; i < 7; i=i+3)
    {
        // for (int j = 0; j < 3; j++)
        // {
        //     cout<<grid[i][j]<<" ";
        // }
        // cout<<endl;
        cout<<" "<<grid[i]<<" | "<<grid[i+1]<<" | "<<grid[i+2]<<endl;
        if(i==6) break;
        cout<<"--- --- ---"<<endl;
    }
    cout<<endl;
    
}

int main()
{
    char grid[9]={'1','2','3','4','5','6','7','8','9'};
    prNT(grid);
    
    cout<<"Player 1 - X"<<endl<<"Player 2 - O"<<endl<<endl;

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

        while(1>place || place>9 || grid[place-1]=='X' || grid[place-1]=='O' )           // check palce valid or not.
        {
            cout<< "Enter a valid place from 1-9 which is empty: ";
            cin>>place;
        }
        cout<<endl;
        
        switch (place)                                      // Updatte X or O at given place
        {
        case 1:
            grid[0]=update;
            break;
        case 2:
            grid[1]=update;
            break;
        case 3:
            grid[2]=update;
            break;
        case 4:
            grid[3]=update;
            break;
        case 5:
            grid[4]=update;
            break;
        case 6:
            grid[5]=update;
            break;
        case 7:
            grid[6]=update;
            break;
        case 8:
            grid[7]=update;
            break;
        case 9:
            grid[8]=update;
            break;
        default:

            break;
        }

    //     // grid[2] = 'X';                          // random cheaks/test point.
    //     // grid[4] = 'X';
    //     // grid[6] = 'X';

        prNT(grid);

        if(turn==9) break;                           // 9 bar chal gaya matlab khatam
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

