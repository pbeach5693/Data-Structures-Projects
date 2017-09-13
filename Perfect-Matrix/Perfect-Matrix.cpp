// Patrick Beach
// This program allow the user to enter the size of a mxn matrix where m = n
// And performs a number of operations on said matrix such as:
// calculating the sums of the rows, columns, and diagonals. Finding the
// perfect number, and determining if the matrix is perfect or not.

#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<limits>
#include<iomanip>
using namespace std;


void generateMatrix(int, vector<vector<int> >&);

void printOutput(int, vector<vector<int> >&);

int numberGenerator(int, vector<vector<int> >&);

void getMonth();

int main()
{
    int n;//n with be the size of the matrix entered by the user.
    char choice; //the choice as whether to repeat or quit the program.

    cout << "Welocme to my perfect matrix program. The function of the program"
         << "\nis to: \n \n" << "   1. Allow the user to enter the size of"
         << " the perfect matrix,such as N. N>=2." << endl
         << "   2. Create a 2 D vector array of size N x N." << endl
         << "   3. Populate the 2D vector array with distinct random numbers."
         << endl
         << "   4. Display the sum for each row, column, and diagonals then "
         << endl
         << "      determine whether the numbers in N x N "
         << "vector array are perfect"
         << endl << "      matrix numbers." << endl << endl;

    //do while loop the main program is contained within
    do
    {
        cout << "Enter the size of the matrix:   ";

        //verifies the user entered an acceptable size matrix
        while(!(cin >> n) || n < 1 || n > 50)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter an integer greater than 0 but less than 50:    ";
        }

        //create the two dimensional vector that will store the matrix
        vector<vector<int> >matrix(n, vector<int>(n));

        //function to populate the matrix
        generateMatrix(n, matrix);

        //function to output matrix calculations
        printOutput(n, matrix);

        do{
        cout << "Would you like to find another matrix - enter y or Y for yes "
             << "or n or N for no:  ";
        cin >> choice;

        if(choice != 'y'&& choice != 'Y'&& choice != 'n'&& choice != 'N')
            cout << "\nError *** Invalid choice - Must enter y|Y or n|N\n\n";

        //Makes sure user entered a valid input
        }while(choice != 'y'&& choice != 'Y'&& choice != 'n'&& choice != 'N');

        //Delete the vectors to prevent memory leaks
        matrix.clear();
    //Loop that checks whether the user inputed N or n
    }while(choice != 'n'&& choice != 'N');

    cout << endl << endl;

    cout << "This perfect algorithm is implemented by Patrick Beach" << endl;

    //Function that outputs the date
    getMonth();


    return 0;

}

void generateMatrix(int n, vector<vector<int> >& matrix)
{

    cout << endl << endl;

    cout << "The perfect matrix that is created for size " << n << ":   \n\n\n";

    for(int i = 0; i < n; i++)
    {
        for(int a = 0; a < n; a++)
        {
            //populated the matrix with unique numbers created in the generator function
            matrix[i][a] = numberGenerator(n, matrix);

            //outputs the matrix to the user
            cout << setw(6) <<left << matrix[i][a];
        }
        cout << endl << endl << endl;
    }

    cout << endl;
}


void printOutput(int n, vector<vector<int> >& matrix)
{

    int totalSum = 0; // total sum of all numbers in the matrix
    int leftDiagonal = 0; // sum of the left diagonal numbers
    int rightDiagonal = 0; // sum of the right diagonal numbers
    //used for locating the numbers in the right diagonal
    int rightDiagonalCount = n-1;
    //used for locating the numbers in the left diagonal
    int leftDiagonalCount = 0;
    // stores the value of the sum used for calculating perfect matrix
    int sumCounter;
    // counts number of equivalent sums for perfect matrix
    int perfectMatrix = 1;


        for(int i = 0; i < n; i++)
        {
            for(int a = 0; a < n; a++)
            {
                totalSum += matrix[i][a];
            }
        }

    //outputs the perfect matrix to the user
    cout << "The perfect number:    " << totalSum/3 << endl << endl << endl;


    for(int i = 0; i < n; i++)
    {

        int rowSum = 0;

        for(int a = 0; a < n; a++)
        {
            rowSum += matrix[i][a];
        }

        //sums the left diagonal, and moves he place over for the next number
        leftDiagonal += matrix[i][leftDiagonalCount];
        leftDiagonalCount++;

        //sums the right diagonal and moves the place over for the next number
        rightDiagonal += matrix[i][rightDiagonalCount];
        rightDiagonalCount--;

        //sets the first sum used for comparing following sums
        //this is used for determining whether the matrix is perfect
        if(i == 0)
            sumCounter = rowSum;

        //adds to the perfect matrix integer if the sum is
        // equivalent to the first sum
        if(sumCounter == rowSum && i != 0)
            perfectMatrix++;

        // outputs the sum for each row
        cout << "Sum numbers in Row        # " << i+1
             << "   =  " << rowSum << endl;
    }


    cout << endl;


    for(int i = 0; i < n; i++)
    {
        int columnSum = 0; //variable used for calculating sum of each column

        for(int a = 0; a < n; a++)
        {
            columnSum += matrix[a][i];
        }

        // adds one to the counter if column equals original
        // row sum from the beginning
        if(sumCounter == columnSum)
            perfectMatrix++;

        //outputs the sum of each column
        cout << "Sum of numbers in Column  # " << i + 1
             << "   =  " << columnSum << endl;
    }

    //if the sum of each diagonal is equal to the original
    // row sum, 1 is added to perfect matrix
    if(sumCounter == rightDiagonal)
        perfectMatrix++;

    if(sumCounter == leftDiagonal)
        perfectMatrix++;

    //outputs the sum of the diagonals to the user
    cout << "\nThe sum of the first diagonal   =  " << rightDiagonal << endl;
    cout << "The sum of the second diagonal  =  " << leftDiagonal << endl;


    if(perfectMatrix == (n * 2) + 2)
        cout << "\nThis is a perfect matrix\n\n\n\n";
    else
        cout << "\nThis is not a perfect matrix\n\n\n\n";

}


int numberGenerator(int n, vector<vector<int> >& matrix)
{

    int randomNum; //variable that stores the new random number
    bool unique=false; // whether the number is unique or not

    do
    {
        unique = true;

        randomNum = rand();

        randomNum = randomNum %(n*n + 4);

        //loop that makes sure the number hasn't been used before
        for(int i = 0; i < n; i++)
        {
            for(int a = 0; a < n; a++)
            {
                if(randomNum == matrix[i][a])
                    unique = false;
            }
        }

    }while(unique == false);


    return randomNum;
}


void getMonth()
{
    int intMonth;   // variable for converting int month to string month
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    intMonth = (now->tm_mon + 1);


    switch(intMonth)
    {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
            break;
    }


    cout << " - "
         << now->tm_mday << " - "
         << (now->tm_year + 1900);
}




