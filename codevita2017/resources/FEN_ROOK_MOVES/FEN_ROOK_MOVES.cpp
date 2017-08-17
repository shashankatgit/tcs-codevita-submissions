#include<iostream>

using namespace std;


#define WHITE 0
#define BLACK 1
#define SPACE '0'

#define ISVALIDSTEP(x,y) ((x>=0 && y>=0 && x<8 && y<8))

//Program for counting and listng the no of possible ROOK moves for a given FEN state


//returns total spaces in matrix
//0 represents empty square
int populate(char exp[],char m[][8])
{
    int i,j,k,t;
    i=0;
    j=0;
    k=0;
    int spaces = 0;

    while(exp[k]!='\0')
    {
        if(exp[k]=='/') {
            k++;
            i++;
            j=0;
            continue;
        }

        else if(isdigit(exp[k])){
            int x= exp[k] - '0';
            spaces+=x;
            for(t=0;t<x;t++)
                m[i][j++]=SPACE;

            k++;
        }

        else{
            m[i][j++] = exp[k++];
        }
    }

    return spaces;
}

//utility function to show the matrix in a tab format
void showMatrix(char m[][8]){
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}


//Utility function to show possible Rook Moves
void showRookMoves(bool matrix[][8])
{
    for(int i=0; i<8; ++i)
    {
        for(int j=0; j<8; ++j)
        {
            if(matrix[i][j]==true)
                cout<<"("<<i<<","<<j<<")\n";
        }
    }
}

// Function to count and list rook moves
void countRookMoves(char board[][8], int turn)
{
    char matchUnit;
    bool possibleMovesMatrix[8][8]={false};
    int countMoves = 0;

    if(turn == WHITE)
    {
        matchUnit = 'R';
    }
    else
    {
        matchUnit = 'r';
    }
    for(int i=0; i<8; ++i)
    {
        for(int j=0; j<8; ++j)
        {
            if(board[i][j]==matchUnit)
            {
                //The thing to note is that i is Y coordinate and j is X coordinate
                //Probing right side of the unit
                for(int probeX=j+1; ISVALIDSTEP(probeX,j); ++probeX)
                {
                    if(board[i][probeX]==SPACE)
                        {
                            possibleMovesMatrix[i][probeX] = true;
                            ++countMoves;
                        }
                    else
                        break;
                }

                //Probing left side of the unit
                for(int probeX=j-1; ISVALIDSTEP(probeX,j); --probeX)
                {
                    if(board[i][probeX]==SPACE)
                        {
                            possibleMovesMatrix[i][probeX] = true;
                            ++countMoves;
                        }
                    else
                        break;
                }

                //Probing up side of the unit
                for(int probeY=i-1; ISVALIDSTEP(i,probeY); --probeY)
                {
                    if(board[probeY][j]==SPACE)
                        {
                            possibleMovesMatrix[probeY][j] = true;
                            ++countMoves;
                        }
                    else
                        break;
                }

                //Probing down side of the unit
                for(int probeY=i+1; ISVALIDSTEP(i, probeY); ++probeY)
                {
                    if(board[probeY][j]==SPACE)
                        {
                            possibleMovesMatrix[probeY][j] = true;
                            ++countMoves;
                        }
                    else break;
                }

            }
        }
    }

    cout<<"Possible rook moves = "<<countMoves<<"\n";
    showRookMoves(possibleMovesMatrix);
}
int main()
{

    char exp[] = "rnbqkbnr/pppp1ppp/8/4p3/4P3/R7/PPPP1PP1/1NBQKBNR";
    char board[8][8];

    int spaces = populate(exp, board);

    int turn;

    cout<<"Enter turn ("<<WHITE<<" for WHITE, "<< BLACK << "for BLACK)";
    cin>>turn; cin.ignore();

    showMatrix(board);

    cout<<endl;

    countRookMoves(board, turn);


}
