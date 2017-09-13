/*Patrick Beach Roster#2, Damian Bocanegra Roster#4, David Hunter Roster#16
Due Date: 4/13/2017
Programming Assignment Number 6
Spring CS 3358
Instructor: Hussain Gholoom

This program displays a menu on the screen allowing the user to enter a
choice to enter the size of an array or to terminate the program
After the user enters an array size of greater than 4, then an array
of random numbers greater than 25, but less than 500, will be generated.
The array will then be passed through a few recursive functions to sort,
or determine various properties of said array.
*/


#include<iostream>
#include<limits>
#include<cstdlib>
#include<ctime>
using namespace std;


void generateArray(int numArray[], int);

void tableOfSquares(int);

int power(int, int);

int sumOfSquares(int);

void maxMember(int numArray[], int, int &, int &);

void bubbleSort(int numArray[], int);

bool isMember(int numArray[], int, int);

bool notMember(int numArray[], int, int);

bool isPrime(int, int);

int main ()
{
    int arraySize, numPow, sum, test;
    int min = 500, max = 0;
    char c;
    bool hasMember;

    cout << "Thinking Recursively\n\n"
         << "The function of this program is to\n"
         << "use the recursion to :-\n\n";

    cout << "   1. Display squares of integers in ascending\n"
         << "      order from 1 to the last element in the array\n"
         << "   2. Raise the first number to a power of 2\n"
         << "   3. Return the sums of squares of the numbers\n"
         << "      from 0 to a array of SIZE - 2 in the array\n"
         << "   4. Search the array for the array's min and max values\n"
         << "   5. Sort the array in ascending order\n"
         << "   6. Search the array for the fourth value in the array\n"
         << "   7. Search the array for the number 600\n"
         << "   8. Determine if a number is prime(processes all array values)";


    do{

        cout << "\n\nSelect from the following menu\n"
             << "A.   Enter Array Size that is > 4.\n"
             << "X.   Terminate The Program.     ";

        while(!(cin >> c) || c!='A' && c!='a' && c!='X' && c!='x')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n***Invalid option***\n\n";

            cout << "\nSelect from the following menu\n"
                 << "A.   Enter Array Size that is > 4.\n"
                 << "X.   Terminate The Program.     ";
        }


        if(c == 'a' || c == 'A')
        {
            cout << "Enter Array Size:    \n";

            while(!(cin>>arraySize)  || arraySize < 4)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n***Invalid option***\n\n";

                if(!arraySize)
                    cout << "Enter an integer not a char:  ";
                else
                    cout << "Enter Array Size That is > 4:  ";
            }


            int numArray[arraySize];

            generateArray(numArray, arraySize);


            cout << "Table of square values 1 - " << numArray[arraySize-1]
                 << "\n\n"
                 << "N      N Squared\n";
            tableOfSquares(numArray[arraySize-1]+1);

            numPow = power(numArray[0], 2);

            cout << "\n\nPower Function:\n"
                 << numArray[0] << " raised to the second power is: " << numPow
                 << "\n\n\n";

            sum = sumOfSquares(numArray[arraySize-2]);

            cout << "Sum of squares between 0 and " << numArray[arraySize-2]
                << " is: " << sum << "\n\n\n";

            maxMember(numArray, arraySize, max, min);

            cout << "Min number of ( ";
            for(int i = 0; i < arraySize; i++)
            {
                cout << numArray[i];
                if(i != arraySize - 1)
                    cout << " , ";
                else
                    cout << " )";
            }
            cout << "is: " << min << "\n\n";


            cout << "Max number of ( ";
            for(int i = 0; i < arraySize; i++)
            {
                cout << numArray[i];
                if(i != arraySize - 1)
                    cout << " , ";
                else
                    cout << " )";
            }
            cout << "is: " << max << "\n";


            bubbleSort(numArray, arraySize);


            cout << "\n\nSorted array\n";
            for(int i = 0; i < arraySize; i++)
                cout << numArray[i] << "  ";


            cout << "\n\n\nMember Functions:\n"
                << "Does the array: ";
            for(int i = 0; i < arraySize; i++)
                cout << numArray[i] << "  ";
            cout << "Have the number " << numArray[3] << "?";


            hasMember = isMember(numArray, arraySize, numArray[3]);


            switch(hasMember)
            {
            case true:
                cout << "   YES\n";
                break;
            case false:
                cout << "   NO\n";
                break;
            }


            hasMember = notMember(numArray, arraySize, 600);

            cout << "Does the array: ";
            for(int i = 0; i < arraySize; i++)
                cout << numArray[i] << "  ";

            cout << "Have the member 600?";

            switch(hasMember)
            {
            case true:
                cout << "   YES";
                break;
            case false:
                cout << "   NO";
                break;
            }


            cout << "\n\n\nIs it Prime?\n";
            for(int i = 0; i < arraySize; i++)
            {
                hasMember = isPrime(numArray[i], numArray[i]-1);
                if(hasMember == false)
                    cout << "The number " << numArray[i] << " is Prime\n";
                else
                    cout << "The number " << numArray[i] << " is not Prime\n";
            }
        }
    }while(c != 'x' && c != 'X');


    cout << "\n\n\nThis program was implemented by Patrick Beach, David Hunter"
         << ", and Damian Bocanegra";

    return 0;
}


void generateArray(int numArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        int randomNum = rand();
        randomNum = (randomNum % 475) + 25;
        numArray[i] = randomNum;
    }

    cout << "\n\nThe generated array is:   ";
    for(int i = 0; i < arraySize; i++)
        cout << numArray[i] << "   ";

    cout << "\n\n";

}

void tableOfSquares(int highest)
{
    int square;
    highest--;
    square = highest * highest;
    if(highest >= 2)
        tableOfSquares(highest);
    cout << highest << "      " << square << endl;
}


int power(int num, int pow)
{
    if(pow > 1)
    {
        num *= power(num, pow-1);
    }
    return num;
}


int sumOfSquares(int sumSquare)
{
    int sum;
    sum = sumSquare * sumSquare;

    if(sumSquare > 0)
    {
        sumSquare--;
        sum += sumOfSquares(sumSquare);
    }
    return sum;
}


void maxMember(int numArray[], int size, int &max, int &min){
    if (numArray[size-1] > max)
        max = numArray[size-1];
    if (numArray[size-1] < min)
        min = numArray[size-1];
    if (size > 1)
        maxMember(numArray, size-1, max, min);
}


void bubbleSort(int numArray[], int size){
    bool change = false;
    int temp = 0;

    for (int i = 0; i < size - 1; i++){
        if (numArray[i] < numArray[i+1]){
            temp = numArray[i];
            numArray[i] = numArray[i+1];
            numArray[i+1] = temp;
            change = true;
        }
    }

    if (change)
        bubbleSort(numArray, size);

}


bool isMember(int numArray[], int size, int num){

    if (size == 0)
        return false;
    else if (numArray[size-1] == num)
        return true;
    else
        return isMember(numArray, size-1, num);

}


bool notMember(int numArray[], int size, int num){
    int first = 0;
    int last = size-1;
    int middle = size/2;
    int newSize=0;

    if (numArray[middle] == num)
        return true;
    else if(last == first)
        return false;
    else if (numArray[middle] > num){
         int newArr[middle];
        for (int i = 0; i < middle; i ++){
            newSize++;
            newArr[i] = numArray[i];
        }
        return notMember(newArr, newSize, num);
    }

    else{
        int newArr[last-middle];
        int i = 0;
        for (;middle < size; middle++){
            newSize++;
            newArr[i] = numArray[middle];
            i++;

        }
        return notMember(newArr, newSize, num);
    }
}


bool isPrime(int x, int y){
    if (y == 1)
        return false;
    else if (x>y && x%y==0)
        return true;
    else
        return (isPrime(x, y-1));
}



