#include <iostream>
#include<time.h>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void create_board(int);
void show_board(int);
void create_snake_and_ladder(int);
void show_snake_and_ladder(int);
void create_snakes(int);
void create_ladders(int);
int master_create_snake_and_ladder(int);
int roll_dice_r();
int roll_dice_b();
void whereami(int);
void whatsthescore();
int whowon();
int play_game(int);
void delay(int);
int options();
int startplay(int,int,int);

int board[100][100],sal[100][100];

int ind1=0,ind2=0,red=0,blue=0,r=0,b=0;

int main()
{

    int n,choice;
    string login;
    cout<<"\nLet's Play y or n? "<<endl;
    cin>>login;
    if(login=="n")
    {
        cout<<"\nYou said you don't want to play :< "<<endl;
        return 0;
    }
    if(login=="y")
        options();
    else
    {
        cout<<"\nWrong choice mate\n"<<endl;
        main();
    }
    return 0;

}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void create_board(int n)
{
    int c=1,index2=0;
    for(int i=n-1; i>=0; i--)
    {
        if(i%2==0)
        {
            index2=0;
            for(int j=0; j<n; j++)
            {
                board[i][index2]=c;
                index2++;
                c++;
            }
        }
        else
        {
            index2=n-1;
            for(int j=0; j<n; j++)
            {
                board[i][index2]=c;
                index2--;
                c++;
            }
        }
    }
}

void show_board(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]>=1&&board[i][j]<=9)
                cout<<"0"<<board[i][j]<<" ";
            else
                cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void show_snake_and_ladder(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(sal[i][j]>=0&&sal[i][j]<=9)
                cout<<"0"<<sal[i][j]<<" ";
            else
                cout<<sal[i][j]<<" ";
        }
        cout<<endl;
    }
}

void create_snake_and_ladder(int n)
{

    int times1=n/2+1;
    int times2=times1*times1;

    for(int i=0; i<times2; i++)
    {

    }

    sal[0][2]=15;
    sal[1][2]=10;
    sal[2][1]=21;
    sal[2][3]=5;
    sal[3][1]=17;
    sal[3][3]=13;
}

void create_snakes(int n)
{
    int st,en;
    show_board(n);
    cout<<"\nenter head of snake\n"<<endl;
    cin>>st;
    cout<<"\nenter tail of snake\n"<<endl;
    cin>>en;

    int index1,index2,index3,index4;
    st=max(st,en);
    en=min(st,en);

    if(st==en)
    {
        cout<<"\nNot possible, Try again\n"<<endl;
        master_create_snake_and_ladder(n);
    }
    else if(st>(n*n)||en<1)
    {
        cout<<"\nDon't go out of limit of board, try to create snake again\n"<<endl;
        create_snakes(n);
    }
    else
    {
        whereami(st);
        index1=ind1;
        index2=ind2;

        whereami(en);
        index3=ind1;
        index4=ind2;

        sal[index1][index2]=board[index3][index4];
        cout<<"\nSnake Created Succesfully\n"<<endl;
        show_snake_and_ladder(n);
    }

}

void create_ladders(int n)
{
    int st,en;
    show_board(n);
    cout<<"\nenter bottom point of ladder\n"<<endl;
    cin>>st;
    cout<<"\nenter top point of ladder\n"<<endl;
    cin>>en;

    int index1,index2,index3,index4;
    st=min(st,en);
    en=max(st,en);

    if(st==en)
    {
        cout<<"\nNot possible, Try again\n"<<endl;
        master_create_snake_and_ladder(n);
    }
    else if(st<0||en>(n*n))
    {
        cout<<"\nDont go out of limit of board, try to create ladder again\n"<<endl;
        create_ladders(n);
    }
    else
    {
        whereami(st);
        index1=ind1;
        index2=ind2;

        whereami(en);
        index3=ind1;
        index4=ind2;

        sal[index1][index2]=board[index3][index4];
        cout<<"\nladder Created Succesfully\n"<<endl;
        show_snake_and_ladder(n);
    }
}

int master_create_snake_and_ladder(int n)
{
    while(1)
    {
        cout<<"\nDo you want to create snake or ladder | s (snake) or l (ladder) | if done creating press 'e' \n"<<endl;
        string c;
        cin>>c;
        if(c=="s"||c=="S")
            create_snakes(n);
        else if(c=="l"||c=="L")
            create_ladders(n);
        else if(c=="e"||c=="E")
        {
            return 0;
        }
        else
        {
            cout<<"\nInvalid Option, I Created Snakes and ladders Don't worry \n"<<endl;
            create_snake_and_ladder(n);
            show_snake_and_ladder(n);
            return 0;
        }
    }


}


int roll_dice_b()
{

    srand((unsigned) time(0));

    return rand()%6+1;

}

int roll_dice_r()
{

    srand((unsigned) time(0) + 1);

    return rand()%6+1;

}

void whereami(int val)
{

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(board[i][j]==val)
            {
                ind1=i;
                ind2=j;
            }
        }
    }

}

void whatsthescore()
{

    cout<<" -----------SCORE-----------"<<endl;
    if(r<=9&&r>=0)
        cout<<"|       RED score  =  0"<<r<<"    |"<<endl;
    else
        cout<<"|       RED score  =  "<<r<<"    |"<<endl;

    if(b<=9&&b>=0)
        cout<<"|       BLUE score =  0"<<b<<"    |"<<endl;
    else
        cout<<"|       BLUE score =  "<<b<<"    |"<<endl;

    cout<<" -----------SCORE-----------"<<endl;

}

int whowon()
{
    if(r>b)
        cout<<"RED Won :> "<<endl;
    if(b>r)
        cout<<"BLUE Won :> "<<endl;
    if(b==r)
        cout<<"Its a draw :( "<<endl;

}

int options()
{

    char choice;
    cout<<"\n1 player or 2 players ? 1 or 2"<<endl;
    cin>>choice;

    if(choice=='2')
    {
        cout<<"\nTWO PLAYER GAME\n";
        play_game(choice);
    }
    else if(choice=='1')
    {
        cout<<"\nONE PLAYER GAME\n";
        cout<<"\nplayer A is RED (You) | player B is BLUE (Computer) \n"<<endl;
        play_game(choice);
    }
    else
    {
        cout<<"Invalid Choice Buddy"<<endl;
        options();
        return 0;
    }




}

int play_game(int choice)
{
    int n;
    cout<<"\nlet's Go! \n\nenter the size of the board, Minimum Board Size = 5, Maximum Board Size = 10 "<<endl;
    cin>>n;

    int storechoice=choice;

    if(n<5||n>10)
    {
        cout<<"\nMinimum board size is 5 and maximum Board size is 10, kindly enter within 5 and 10";
        play_game(storechoice);
    }

    create_board(n);
    cout<<"\nBoard"<<endl;
    show_board(n);

    cout<<endl<<endl;

    cout<<"\nJust Play or Create your own snakes and ladders? play (just play) or master (create) \n"<<endl;
    string op;
    cin>>op;
    if(op=="master")
    {
        cout<<"Let's create snakes and ladder master\n\n";
        master_create_snake_and_ladder(n);
    }
    else if(op=="play")
        create_snake_and_ladder(n);
    else
    {
        cout<<"Invalid choice mate"<<endl;
        return 0;
    }


    cout<<"Board with Snakes and Ladders"<<endl;
    show_snake_and_ladder(n);

    cout<<endl<<endl;

    cout<<"\nLet's Play Now\n";
    cout<<endl<<endl;

    startplay(1,n,choice);

}


int i=1;

int startplay(int i,int n,int choice)
{

    while(1)
    {
        char cho;
        int change;
        if(i%2!=0)
        {
            cout<<"RED's turn Roll your die? y or n ?"<<endl;
            cin>>cho;
            int dice=roll_dice_r();

            if(cho=='y')
            {

                cout<<"\n        RED you rolled "<<dice<<endl<<endl;
                r+=dice;
                if(r>(n*n))
                    r-=dice;
                red=1;
                blue=0;

                whereami(r);
                if(sal[ind1][ind2]!=0)
                {
                    change = sal[ind1][ind2];
                    if(change>board[ind1][ind2])
                        cout<<" YAY! RED You went up the ladder! :> "<<endl<<endl;
                    else if(change<board[ind1][ind2])
                        cout<<" RED You got bit by a snake :< "<<endl<<endl;
                    r = change;
                }
            }
            else if(cho=='n')
            {
                cout<<"BLUE WON :< because you didn't want to play :<  \n";
                return 0;
            }
            else
            {
                cout<<"wrong input, try again :) \n\n";
                startplay(i,n,choice);
                return 0;
            }

        }
        else if(i%2==0)
        {
            int dice=roll_dice_b();

            if(choice==2)
            {
                cout<<"BLUE's turn roll your die? y or n ?"<<endl;
                cin>>cho;
            }
            else if(choice==1)
            {
                cout<<"BLUE is playing........"<<endl;
                delay(1);
                cho='y';
            }

            if(cho=='y')
            {

                cout<<"\n          BLUE you rolled "<<dice<<endl<<endl;
                b+=dice;
                if(b>(n*n))
                    b-=dice;
                red=0;
                blue=1;

                whereami(b);
                if(sal[ind1][ind2]!=0)
                {
                    change = sal[ind1][ind2];
                    if(change>board[ind1][ind2])
                        cout<<" YAY! BLUE You went up the ladder! "<<endl<<endl;
                    else if(change<board[ind1][ind2])
                        cout<<" BLUE You got bit by a snake :< "<<endl<<endl;
                    b = change;
                }

            }
            else if(cho=='n')
            {
                cout<<"RED WON :< because you didn't want to play :<  \n";
                return 0;
            }
            else
            {
                cout<<"wrong input, try again :) \n\n";
                startplay(i,n,choice);
                return 0;
            }

        }

        whatsthescore();
        i++;

        cout<<endl;

        if(i%2!=0)
            cout<<"\n\n\n\n";

        int towin=n*n;
        if(r==towin||b==towin)
        {
            whowon();
            return 0;
        }

    }



}

