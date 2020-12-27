#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>

char b_posi[9]={'1','2','3','4','5','6','7','8','9'};

char player1Sym,player2Sym,who,position;
void main();
void setSymbol(){
    printf("Enter a Symbol for player 1:");
    scanf("%c",&player1Sym);
    fflush(stdin);
    printf("\nEnter a Symbol for player 2:");
    scanf("%c",&player2Sym);
    fflush(stdin);
}
void printSymbol(int N)
{
    if(N== 1)
    {
        printf("\t\t\t    Player 1(%c) - Computer(%c)\n\n",player1Sym, player2Sym);
    }
    else if(N == 2)
    {
        printf("\t\t\t    Player 1(%c) - Player 2(%c)\n\n",player1Sym, player2Sym);
    }
}
void displayBoard(int N)
{
    printf("\t\t\t\t !!Tic Tac Toe!!\n\n");
    printSymbol(N);
    printf("\n");
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n",b_posi[0],b_posi[1],b_posi[2]);
    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n",b_posi[3],b_posi[4],b_posi[5]);
    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n",b_posi[6],b_posi[7],b_posi[8]);
    printf("\t\t\t\t     |     |     \n");
    printf("\n\n");
}
void whoFirst()
{
    printf("Enter who will play first? \nplayer 1 or 2: ");
    scanf("%c",&who);
    fflush(stdin);
    system("cls"); // to clear screen
    displayBoard(2);
}
void check(char position, char who)
{
    int i,check_posi=0;
    for(i=0;i<9;i++)
    {
        if(position == b_posi[i])
        {
            if(who == '1')
            {
                b_posi[i] = player1Sym;

            }
            else if(who =='2')
            {
                b_posi[i] = player2Sym;

            }
            check_posi = 1;
        }
    }
    if(check_posi == 0)
    {
        PlaySound("wrong.wav", NULL, SND_FILENAME|SND_ASYNC);
        if(position >= '1' && position<='9')
        {
            printf("\nposition already taken!\n\n");
            printf("Enter position for player %c : ",who);
            scanf("%c",&position);
            fflush(stdin);
            check(position,who);
        }
        else{
            printf("\nPlease enter a valid position!\n\n");
            printf("Enter position for player %c : ",who);
            scanf("%c",&position);
            fflush(stdin);
            check(position,who);
        }
    }

    PlaySound("move.wav", NULL, SND_FILENAME|SND_ASYNC);
}
void play()
{
    fflush(stdin);
    printf("Enter position for player %c : ",who);
    scanf("%c",&position);
    fflush(stdin); // character input problem
    check(position,who);
    if(who == '1')
        {
            who = '2';
        }
    else if(who == '2')
        {
            who = '1';
        }
    system("cls"); // to clear screen
    displayBoard(2);
}

int end()
{
    //for player 1 checking 8 condition to win
    //Horizontal 3 condition
    if(b_posi[0] == player1Sym && b_posi[1] == player1Sym && b_posi[2] == player1Sym)
    {
        return 1;
    }
    else if(b_posi[3] == player1Sym && b_posi[4] == player1Sym && b_posi[5] == player1Sym)
    {
        return 1;
    }
    else if(b_posi[6] == player1Sym && b_posi[7] == player1Sym && b_posi[8] == player1Sym)
    {
        return 1;
    }

    //vertical 3 condition
    else if(b_posi[0] == player1Sym && b_posi[3] == player1Sym && b_posi[6] == player1Sym)
    {
        return 1;
    }
    else if(b_posi[1] == player1Sym && b_posi[4] == player1Sym && b_posi[7] == player1Sym)
    {
        return 1;
    }
    else if(b_posi[2] == player1Sym && b_posi[5] == player1Sym && b_posi[8] == player1Sym)
    {
        return 1;
    }

    //cross 2 condition
    else if(b_posi[0] == player1Sym && b_posi[4] == player1Sym && b_posi[8] == player1Sym)
    {
        return 1;
    }
    else if(b_posi[2] == player1Sym && b_posi[4] == player1Sym && b_posi[6] == player1Sym)
    {
        return 1;
    }


    //for player 2 checking 8 condition to win
    //Horizontal 3 condition
    if(b_posi[0] == player2Sym && b_posi[1] == player2Sym && b_posi[2] == player2Sym)
    {
        return 2;
    }
    else if(b_posi[3] == player2Sym && b_posi[4] == player2Sym && b_posi[5] == player2Sym)
    {
        return 2;
    }
    else if(b_posi[6] == player2Sym && b_posi[7] == player2Sym && b_posi[8] == player2Sym)
    {
        return 2;
    }

    //vertical 3 condition
    else if(b_posi[0] == player2Sym && b_posi[3] == player2Sym && b_posi[6] == player2Sym)
    {
        return 2;
    }
    else if(b_posi[1] == player2Sym && b_posi[4] == player2Sym && b_posi[7] == player2Sym)
    {
        return 2;
    }
    else if(b_posi[2] == player2Sym && b_posi[5] == player2Sym && b_posi[8] == player2Sym)
    {
        return 2;
    }

    //cross 2 condition
    else if(b_posi[0] == player2Sym && b_posi[4] == player2Sym && b_posi[8] == player2Sym)
    {
        return 2;
    }
    else if(b_posi[2] == player2Sym && b_posi[4] == player2Sym && b_posi[6] == player2Sym)
    {
        return 2;
    }
}
void multiplayer()
{
    displayBoard(2);
    setSymbol();
    whoFirst();
    int i=1,result,check_draw = 1;
    while(i<=9)
    {
        play();
        result = end();
        if(result == 1)
        {
            printf("Player 1 is win!\n");
            check_draw = 0;
            PlaySound("win.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        }
        else if(result == 2)
        {
            printf("Player 2 is win!\n");
            check_draw = 0;
            PlaySound("win.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        }
        i++;
    }
    if(check_draw == 1)
        {
            printf("Draw!\n");
            PlaySound("draw.wav", NULL, SND_FILENAME|SND_ASYNC);
        }
    char decision;
    printf("\nWant to play Again?y/n: ");
    scanf("%c",&decision);
    fflush(stdin); // character input taking issue
    if(decision == 'y' || decision == 'Y')
    {
        system("cls"); // to clear screen
        main();
    }
}
//for single player generating bot
void setBotSymbol()
{
    player1Sym = 'X';
    player2Sym = 'O'; // symbol for bot
}
int botMove()
{
    if(b_posi[4] != 'X' && b_posi[4] != 'O')
    {
        return 4;
    }
    //win move horizon row-1
    else if((b_posi[0] == 'O' && b_posi[1] == 'O') && b_posi[2] != 'X')
    {
        return 2;
    }
    else if((b_posi[1] == 'O' && b_posi[2] == 'O') && b_posi[0] != 'X')
    {
        return 0;
    }
    else if((b_posi[0] == 'O' && b_posi[2] == 'O') && b_posi[1] != 'X')
    {
        return 1;
    }
    //row-2
    else if((b_posi[3] == 'O' && b_posi[4] == 'O') && b_posi[5] != 'X')
    {
        return 5;
    }
    else if((b_posi[4] == 'O' && b_posi[5] == 'O') && b_posi[3] != 'X')
    {
        return 3;
    }
    else if((b_posi[3] == 'O' && b_posi[5] == 'O') && b_posi[4] != 'X')
    {
        return 4;
    }
    //row-3
    else if((b_posi[6] == 'O' && b_posi[7] == 'O') && b_posi[8] != 'X')
    {
        return 8;
    }
    else if((b_posi[7] == 'O' && b_posi[8] == 'O') && b_posi[6] != 'X')
    {
        return 6;
    }
    else if((b_posi[6] == 'O' && b_posi[8] == 'O') && b_posi[7] != 'X')
    {
        return 7;
    }

    //vertical col-1
    else if((b_posi[0] == 'O' && b_posi[3] == 'O') && b_posi[6] != 'X')
    {
        return 6;
    }
    else if((b_posi[0] == 'O' && b_posi[6] == 'O') && b_posi[3] != 'X')
    {
        return 3;
    }
    else if((b_posi[3] == 'O' && b_posi[6] == 'O') && b_posi[0] != 'X')
    {
        return 0;
    }
    //col-2
    else if((b_posi[1] == 'O' && b_posi[4] == 'O') && b_posi[7] != 'X')
    {
        return 7;
    }
    else if((b_posi[7] == 'O' && b_posi[4] == 'O') && b_posi[1] != 'X')
    {
        return 1;
    }
    else if((b_posi[1] == 'O' && b_posi[7] == 'O') && b_posi[4] != 'X')
    {
        return 4;
    }
    //col-3
    else if((b_posi[2] == 'O' && b_posi[5] == 'O') && b_posi[8] != 'X')
    {
        return 8;
    }
    else if((b_posi[2] == 'O' && b_posi[8] == 'O') && b_posi[5] != 'X')
    {
        return 5;
    }
    else if((b_posi[8] == 'O' && b_posi[5] == 'O') && b_posi[2] != 'X')
    {
        return 2;
    }

    //cross-1
    else if((b_posi[0] == 'O' && b_posi[8] == 'O') && b_posi[4] != 'X')
    {
        return 4;
    }
    else if((b_posi[0] == 'O' && b_posi[4] == 'O') && b_posi[8] != 'X')
    {
        return 8;
    }
    else if((b_posi[8] == 'O' && b_posi[4] == 'O') && b_posi[0] != 'X')
    {
        return 0;
    }
    //cross-2
    else if((b_posi[2] == 'O' && b_posi[4] == 'O') && b_posi[6] != 'X')
    {
        return 6;
    }
    else if((b_posi[4] == 'O' && b_posi[6] == 'O') && b_posi[2] != 'X')
    {
        return 2;
    }
    else if((b_posi[2] == 'O' && b_posi[6] == 'O') && b_posi[4] != 'X')
    {
        return 4;
    }
    // Defend move horizontal row-1
    else if((b_posi[0] == 'X' && b_posi[1] == 'X') && b_posi[2] != 'O')
    {
        return 2;
    }
    else if((b_posi[1] == 'X' && b_posi[2] == 'X') && b_posi[0] != 'O')
    {
        return 0;
    }
    else if((b_posi[0] == 'X' && b_posi[2] == 'X') && b_posi[1] != 'O')
    {
        return 1;
    }
    //row-2
    else if((b_posi[3] == 'X' && b_posi[4] == 'X') && b_posi[5] != 'O')
    {
        return 5;
    }
    else if((b_posi[4] == 'X' && b_posi[5] == 'X') && b_posi[3] != 'O')
    {
        return 3;
    }
    else if((b_posi[3] == 'X' && b_posi[5] == 'X') && b_posi[4] != 'O')
    {
        return 4;
    }
    //row-3
    else if((b_posi[6] == 'X' && b_posi[7] == 'X') && b_posi[8] != 'O')
    {
        return 8;
    }
    else if((b_posi[7] == 'X' && b_posi[8] == 'X') && b_posi[6] != 'O')
    {
        return 6;
    }
    else if((b_posi[6] == 'X' && b_posi[8] == 'X') && b_posi[7] != 'O')
    {
        return 7;
    }


    //vertical col-1
    else if((b_posi[0] == 'X' && b_posi[3] == 'X') && b_posi[6] != 'O')
    {
        return 6;
    }
    else if((b_posi[0] == 'X' && b_posi[6] == 'X') && b_posi[3] != 'O')
    {
        return 3;
    }
    else if((b_posi[3] == 'X' && b_posi[6] == 'X') && b_posi[0] != 'O')
    {
        return 0;
    }
    //col-2
    else if((b_posi[1] == 'X' && b_posi[4] == 'X') && b_posi[7] != 'O')
    {
        return 7;
    }
    else if((b_posi[7] == 'X' && b_posi[4] == 'X') && b_posi[1] != 'O')
    {
        return 1;
    }
    else if((b_posi[1] == 'X' && b_posi[7] == 'X') && b_posi[4] != 'O')
    {
        return 4;
    }
    //col-3
    else if((b_posi[2] == 'X' && b_posi[5] == 'X') && b_posi[8] != 'O')
    {
        return 8;
    }
    else if((b_posi[2] == 'X' && b_posi[8] == 'X') && b_posi[5] != 'O')
    {
        return 5;
    }
    else if((b_posi[8] == 'X' && b_posi[5] == 'X') && b_posi[2] != 'O')
    {
        return 2;
    }

    //cross-1
    else if((b_posi[0] == 'X' && b_posi[8] == 'X') && b_posi[4] != 'O')
    {
        return 4;
    }
    else if((b_posi[0] == 'X' && b_posi[4] == 'X') && b_posi[8] != 'O')
    {
        return 8;
    }
    else if((b_posi[8] == 'X' && b_posi[4] == 'X') && b_posi[0] != 'O')
    {
        return 0;
    }
    //cross-2
    else if((b_posi[2] == 'X' && b_posi[4] == 'X') && b_posi[6] != 'O')
    {
        return 6;
    }
    else if((b_posi[4] == 'X' && b_posi[6] == 'X') && b_posi[2] != 'O')
    {
        return 2;
    }
    else if((b_posi[2] == 'X' && b_posi[6] == 'X') && b_posi[4] != 'O')
    {
        return 4;
    }

    //random move
    else{
        int i;
        for( i = 0 ; i < 9 ; i++ )
            {
                if(b_posi[i]!= 'X' && b_posi[i] !='O')
                {
                    return i;
                    break;
                }
            }
    }
}
void botPlay()
{

    if(who == '1')
    {
        printf("Enter position for you: ");
        scanf("%c",&position);
        fflush(stdin);
        check(position,who);
        who = '2';
    }
    else if(who == '2')
    {
        position =botMove()+'1';
        check(position,who);
        who = '1';
    }

    system("cls"); // to clear screen
    displayBoard(1);
}
void single()
{
    setBotSymbol();
    displayBoard(1);
    who = '1';
    int i=1,result,check_draw = 1;
    while(i<=9)
    {
        botPlay();
        result = end();
        if(result == 1)
        {
            printf("You Win!\n");
            check_draw = 0;
            PlaySound("win.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        }
        else if(result == 2)
        {
            printf("You Lose!\n");
            check_draw = 0;
            PlaySound("lose.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        }
        i++;
    }
    if(check_draw == 1)
        {
            printf("Draw!\n");
            PlaySound("draw.wav", NULL, SND_FILENAME|SND_ASYNC);
        }
    char decision;
    printf("\nWant to play Again?y/n: ");
    scanf("%c",&decision);
    fflush(stdin); // character input taking issue
    system("cls"); // to clear screen
    if(decision == 'y' || decision == 'Y')
    {
        main();
    }
}


void main()
{
    char ch, b_posi_reassign[9]={'1','2','3','4','5','6','7','8','9'};
    player1Sym='\0';
    player2Sym='\0';
    printf("Multiplayer or Single? \nm for multiplayer / s for single:");
    scanf("%c",&ch);
    PlaySound("move.wav", NULL, SND_FILENAME|SND_ASYNC);
    fflush(stdin);
    system("cls");
    if(ch == 's' || ch == 'S')
    {
        strcpy(b_posi,b_posi_reassign);
        single();
    }
    else if(ch == 'm' || ch == 'M')
    {
        strcpy(b_posi,b_posi_reassign);
        multiplayer();
    }
}







