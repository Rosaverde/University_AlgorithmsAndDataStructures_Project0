#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct board
{
    int c;
    char l;
};

int main()
{
    const int n= 20;
    const int A = 1;
    const int B = 8;
    const int G = 97;
    const int H = 104;

    int up =0;
    int bottom;
    int temp, fU, fB; //// f finds empty spaces in the array
    board step[n];

    srand(time(0));
    for(int i=0; i<n; i++ )
        {
            temp=A+rand()%(B+1-A);
            step[i].c=temp;
            step[i].l=G+rand()%(H+1-G);

            if(temp>4) up++;
        }
    cout << "Board A" << endl;
    for(int i=0; i<n; i++)
        {
            cout << step[i].c << step[i].l << " ";
        }
    bottom = n-up;

    board *upperPart = new board[up];
    board *bottomPart = new board[bottom];

    fU=0;
    fB=0;
    for(int i=0; i<n; i++)
        {
            if(step[i].c>4)
              {
                  upperPart[fU]=step[i];
                  fU++;
              }
            else
              {
                  bottomPart[fB]=step[i];
                  fB++;
              }
        }

    cout<< endl << endl << "Board B (lower half <4)" <<endl;
    for(int i=0; i<fB; i++)
        {
            cout << bottomPart[i].c << bottomPart[i].l << " ";
        }

    cout<< endl << endl << "Board C (upper half >4)" << endl;
    for(int i=0; i<fU; i++)
        {
            cout << upperPart[i].c << upperPart[i].l << " ";
        }
    cout << endl;

    delete [] upperPart;
    delete [] bottomPart;
    return 0;
}


// 1-8
// a-h
