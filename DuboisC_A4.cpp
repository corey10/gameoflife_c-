/*****************************************************
*  Assignment    : 4                                 *
*  Name          : Corey Dubois                      *
*  Student ID    : 002230197                         *
*  Date          : 11/13/2017                        *
*  Brief description: Game of life. If issues with   *
*  running, may need to comment out SetConsoleText   *
*  Attribute function. Runs only on Windows OS.      *
******************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;
// GLOBAL CONSTANTS

const int MAXGEN = 3;
const int n = 3;   // rows
const int m = 4;  // columns


void initialize(int grid[][m]){
    cout << "Enter 0 for dead, 1 for alive. Grid size is " << m << " columns across " << "and " << n<< " rows down." << endl;
    cout << "_____________________________________________________________________________" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int i = 0; i < n; i++){
       for (int j = 0; j < m; j++){

         cin >> grid[i][j];
        }

}
}
void initialize2(int grid[][m]){

  int randomNumber = 0;
  int density = 0;
  cout << setw(55) << "Enter the density in percentage: " << endl;
  cin >> density;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){

                randomNumber = rand() % 100 + 1;
                if (randomNumber <= density){
                grid[i][j] = 1;
                }
                if (randomNumber > density){
                grid[i][j] = 0;         //if random number <= density.. cell = 1, else cell = 0
                }

         }


}
}

int countNeighbours(int grid[][m],int x, int y){

      //grid[x][y] would represent current cell. Need to check all round that cell. Using modular for wrap.

    int counter = 0;

                                                  //(x+n)%n and (y+m)%m   to get wrap around


                                                                                                 //       y>
	if   (grid[((x+n)%n)][(((y-1)+m)%m)] == 1)      //one to left                                // 0    0 1 2
         counter++;                                                                             //  1 ^x 3 4 5
	if   (grid[(((x-1)+n)%n)][(((y-1)+m)%m)] == 1)    //up one to left                           // 2    6 7 8
         counter++;
    if   (grid[(((x-1)+n)%n)][((y+m)%m)] == 1)      // up one
         counter++;
	if   (grid[(((x-1)+n)%n)][(((y+1)+m)%m)]==1)    //up one to right
         counter++;
	if   (grid[((x+n)%n)][(((y+1)+m)%m)]==1)      // one to right
         counter++;
    if   (grid[(((x+1)+n)%n)][(((y+1)+m)%m)]==1)    // down one to right
         counter++;
	if   (grid[(((x+1)+n)%n)][((y+m)%m)]==1)      // down one
         counter++;
    if   (grid[(((x+1)+n)%n)][(((y-1)+m)%m)]==1)    // down one to left
         counter++;



	return counter;  // counter represents total number of Alive cells

}




bool allDead(int grid[][m]){
   bool allDead = true;


   int checkCells = 0;


      for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
           checkCells += grid[i][j];
        }

}

       if (checkCells == 0){

        return allDead;
       }

       else
        return !allDead;






}



void reproduce(int grid[][m], bool stableState){

stableState = true;
int newGrid[n][m];


        for(int i = 0; i<n; i++){
           for (int j=0; j<m; j++){              // copying all elements of grid to newGrid
                newGrid[i][j] = grid[i][j];     // this is so rules don't effect other rules. Everything happens at once.

           }
    }
                                 // while not all dead reproduce new generation

        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int myNeighbours = countNeighbours(grid,i,j);



            if (myNeighbours < 2 && grid[i][j] == 1)
                newGrid[i][j] = 0;
            if (myNeighbours > 3 && grid[i][j] == 1) // live with < 2 or > 3 neighbours dies
                newGrid[i][j] = 0;


            if (myNeighbours == 3 && grid[i][j] == 0)    //dead cell with 3 neighbours becomes alive
                newGrid[i][j] = 1;

            if (myNeighbours == 2 && grid[i][j] == 1)
                newGrid[i][j] = 1;
            if (myNeighbours == 3 && grid[i][j] == 1)   // live cell with 2 or 3 neighbours lives on
                newGrid[i][j] = 1;

      }

}




         for(int i = 0; i<n; i++){
                for (int j=0; j<m; j++){
                    if  (grid[i][j] != newGrid[i][j]){   // if any element of grid != newGrid, it cannot be stable.
                    stableState = false;
                    }
                    grid[i][j] = newGrid[i][j];      //copying contents of newGrid back to grid
                }
        }

                    if (stableState == true){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);  // if stable blue highlight
                    cout << endl << "We have reached a stable state. The next generations will be equal. " << endl << endl; // this would require not one single element be false
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white font bottom exit statement
                    exit(1);
                }

}

void print (int grid[][m]){



            cout << setw(35);

       for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){

             if  (grid[i][j] == 0)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // dead = green font 0's
             if  (grid[i][j] == 1)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // alive = red font 1's

                cout << grid[i][j];
            }
                cout << setw(35);
                cout << endl;

       }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);  // purple font
               cout << endl;
}



int main(){

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //yellow title
srand (time(NULL));    //pseudo random values
int grid[n][m];

char initializeValue;
cout << setw(49) << "G A M E  O F  L I F E" << endl << endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);  //grey intro
cout << setw(60) << "Choose how you want to generate populations" << endl << endl;
cout << setw(25) << "Keystroke" << setw(38) <<  "Population generation " << endl << endl;
cout << setw(21) << "1"  <<setw(35)  <<   "Manual "  << endl;
cout << setw(21) << "2"  <<setw(35)   <<  "Automatic" << endl;
cin >> initializeValue;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    if (initializeValue == '1'){
    initialize(grid);
    }
    if (initializeValue == '2'){
     initialize2(grid);
    }
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);  // purple font
cout << endl << setw(25) << "Initial population: \n";
print(grid);
int gen = 1;
bool stableState;

while (gen <= MAXGEN && !allDead(grid)){
    cout << setw(15) << "Generation " << gen << ": " << endl << endl;
    reproduce(grid,stableState); //will call the function countNeighbours for each cell
    print(grid);
    gen++;
 }
 if (allDead(grid)== true){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);     // highlights in red if all dead
    cout << "                 This population died before generation " << gen << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);     //goes back to grey font for bottom

}




}












