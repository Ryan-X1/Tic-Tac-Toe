#include<iostream>
#include<stdlib.h>
#include<C:\Users\Ryan\Desktop\Game\Tic Tac Toe\Tic Tac Toe.h>
using namespace std;

void game::display()
{
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<play[i][j]<<"   ";
        cout<<endl<<endl;
    }
    cout<<endl<<endl<<endl;
}

void game::pc_play(char turn)
{
    if(check_3(turn))
    {
        display();
        cout<<"Computer wins..."<<endl<<endl<<endl;
        end_game=true;
        return ;
    }
    if(pl_check_3(turn))
    {
        display();
        return ;
    }
    while(1)
    {
        r=abs(rand()%3);
        c=abs(rand()%3);
        if(play[r][c] == '_')
            break;
    }
    play[r][c] = turn;
    display();

    // Check if this condition will ever hold
    if(win(turn))
        cout<<"Computer wins..."<<endl<<endl<<endl;
}



bool game::check_3(char turn)
{
    int i, j;
    for(i=0;i<3;i++)
    for(j=0;j<3 && i<3;j++)
    if(play[i][j]==turn)
    {
        if(j==0)
        {
            if(play[i][1]==turn && play[i][2]=='_')
            {
                play[i][2]=turn;
                return true;
            }
            else if(play[i][1]=='_' && play[i][2]==turn)
            {
                play[i][1]=turn;
                return true;
            }
        }
        else if(j==1)
        {
            if(play[i][0]=='_' && play[i][2]==turn)
            {
                play[i][0]=turn;
                return true;
            }
        }
        i++;
        j=-1;
    }

    for(j=0;j<3;j++)
    for(i=0;i<3 && j<3;i++)
    if(play[i][j]==turn)
    {
        if(i==0)
        {
            if(play[1][j]==turn && play[2][j]=='_')
            {
                play[2][j]=turn;
                return true;
            }
            else if(play[1][j]=='_' && play[2][j]==turn)
            {
                play[1][j]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][j]=='_' && play[2][j]==turn)
            {
                play[0][j]=turn;
                return true;
            }
        }
        j++;
        i=-1;
    }

    for(i=0;i<3;i++)
    if(play[i][i]==turn)
    {
        if(i==0)
        {
            if(play[1][1]==turn && play[2][2]=='_')
            {
                play[2][2]=turn;
                return true;
            }
            else if(play[1][1]=='_' && play[2][2]==turn)
            {
                play[1][1]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][0]=='_' && play[2][2]==turn)
            {
                play[0][0]=turn;
                return true;
            }
        }
        else
            return false;
    }

    for(i=0;i<3;i++)
    if(play[i][2-i]==turn)
    {
        if(i==0)
        {
            if(play[1][1]==turn && play[2][0]=='_')
            {
                play[2][0]=turn;
                return true;
            }
            else if(play[1][1]=='_' && play[2][0]==turn)
            {
                play[1][1]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][2]=='_' && play[2][0]==turn)
            {
                play[0][2]=turn;
                return true;
            }
        }
        else
            return false;
    }
    return false;
}

bool game::pl_check_3(char turn)
{
    char opp='T' + 'X' - turn;
    int i, j;
    for(i=0;i<3;i++)
    for(j=0;j<3 && i<3;j++)
    if(play[i][j]==opp)
    {
        if(j==0)
        {
            if(play[i][1]==opp && play[i][2]=='_')
            {
                play[i][2]=turn;
                return true;
            }
            else if(play[i][1]=='_' && play[i][2]==opp)
            {
                play[i][1]=turn;
                return true;
            }
        }
        else if(j==1)
        {
            if(play[i][0]=='_' && play[i][2]==opp)
            {
                play[i][0]=turn;
                return true;
            }
        }
        i++;
        j=-1;
    }

    for(j=0;j<3;j++)
    for(i=0;i<3 && j<3;i++)
    if(play[i][j]==opp)
    {
        if(i==0)
        {
            if(play[1][j]==opp && play[2][j]=='_')
            {
                play[2][j]=turn;
                return true;
            }
            else if(play[1][j]=='_' && play[2][j]==opp)
            {
                play[1][j]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][j]=='_' && play[2][j]==opp)
            {
                play[0][j]=turn;
                return true;
            }
        }
        j++;
        i=-1;
    }

    for(i=0;i<3;i++)
    if(play[i][i]==opp)
    {
        if(i==0)
        {
            if(play[1][1]==opp && play[2][2]=='_')
            {
                play[2][2]=turn;
                return true;
            }
            else if(play[1][1]=='_' && play[2][2]==opp)
            {
                play[1][1]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][0]=='_' && play[2][2]==opp)
            {
                play[0][0]=turn;
                return true;
            }
        }
    }

    for(i=0;i<3;i++)
    if(play[i][2-i]==opp)
    {
        if(i==0)
        {
            if(play[1][1]==opp && play[2][0]=='_')
            {
                play[2][0]=turn;
                return true;
            }
            else if(play[1][1]=='_' && play[2][0]==opp)
            {
                play[1][1]=turn;
                return true;
            }
        }
        else if(i==1)
        {
            if(play[0][2]=='_' && play[2][0]==opp)
            {
                play[0][2]=turn;
                return true;
            }
        }
    }
    return false;
}

void game::player_play(char turn)
{
    while(1)
    {
        char i1, i2;
        if(turn=='T')
            cout<<"Enter the position to place the tick mark : ";
        else
            cout<<"Enter the position to place the cross mark : ";
        cin>>i1>>i2;
        r=i1 - '0' - 1;
        c=i2 - '0' - 1;
        if(r<0 || r>2 || c<0 || c>2 || play[r][c] != '_')
        {
            cout<<endl<<"Entered position is invalid"<<endl;
            cout<<"Choose Again"<<endl<<endl;
        }
        else
            break;
    }
    play[r][c] = turn;
    display();

    if(win(turn))
        cout<<"You Win..."<<endl<<endl<<endl;
}

bool game::win( char turn)
{
    end_game=true;
    int i;
    // Checking Horizontally
    if( play[r][c%3] == turn && play[r][(c+1)%3] == turn && play[r][(c+2)%3] == turn )
        return true;
    // Checking Vertically
    if(  play[r%3][c] == turn && play[(r+1)%3][c] == turn && play[(r+2)%3][c] == turn )
        return true;
    // Down Diagonal
    if(r==c)
    {
        for(i=0;i<3;i++)
            if(play[i][i]!=turn)
            {
                end_game=false;
                break;
            }
        if(end_game)
            return true;
    }
    // Up Diagonal
    end_game = true;
    if(r+c==2)
    {
        for(i=0;i<3;i++)
            if(play[i][2-i]!=turn)
            {
                end_game=false;
                break;
            }
        return end_game;
    }
    end_game=false;
    return end_game;
}

void game::start()
{
    int i, j;
    end_game = false;
    cout<<endl<<"\t\t\t\t\t Tic - Tac - Toe"<<endl<<endl;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            play[i][j]='_';
    display();

    cout<<"\t\t\t\t\t Tossing...\n";
    if(rand()%2)
    {
        cout<<"Computer won the toss\n";
        for(i=0 ; i<9 && !end_game ; i++)
        {
            if(i%2==0)
            {
                cout<<"Thinking..."<<endl<<endl;
                pc_play('T');
            }
            else if(i%2==1 && !end_game && i<9 )
                player_play('X');
        }
    }
    else
    {
        cout<<"You won the toss\n";
        for(i=0 ; i<9 && !end_game ; i++)
        {
            if(i%2==0)
                player_play('T');
            else if(i%2==1 && !end_game && i<9)
            {
                cout<<"Thinking..."<<endl<<endl;
                pc_play('X');
            }
        }
    }
    if(!end_game)
        cout<<"Sadly, This was a draw..."<<endl<<endl;
    if(stop())
        exit(1);
    else
        start();
}

bool game::stop()
{
    while(1)
    {
        cout<<"Do you want to play more? (Y/N) : ";
        char again;
        cin>>again;
        if(again=='Y' || again=='y')
        {
            cout<<endl<<endl<<endl;
            return false;
        }
        else if(again == 'N' || again == 'n')
            return true;
        else
            cout<<"Entered input is invalid. Enter again."<<endl<<endl;
    }
}
