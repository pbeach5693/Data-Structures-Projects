// Patrick Beach
//
// takes in a number by the user and shows the number as a:
// dollar amount and broken into quarters, dimes, nickles and pennies
// an age with the amount of years, months, days, hours, minutes and seconds
// broken down into its digits and shows the digits in english
// if the number is an armstrong number
// the numbers factorial value
// wether or not the number is prime and all the primes in between that number
// and 1
// and the hailstone sequence for that number.
#include<iostream>
#include<cmath>
#include<iomanip>
#include<limits>
using namespace std;

void calculateMoney(int);

void calculateAge(int);

void numToWord(int);

void armstrongNumber(int);

void factorial(int);

void isPrime(int);

void hailstoneSeq(int);

int main()
{
    //The user's choice as to whether they would like to
    //execute another iteration of the program.
    char choice;
    //The integer that the user will enter
    int num;

    do
    {
        cout << "Enter an integer greater than 0 but less than 200:    ";

        //Do while loop that allows the user to enter the integer
        //Also, this loop verifies that the input is acceptable.
            while(!(cin >> num) || num < 1 || num > 200)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter an integer greater than 0 but less than 200:    ";
            }


        cout << "\n\n\n";

        //Call the functions that will carry out the tasks require of the assignment
        calculateMoney(num);

        calculateAge(num);

        numToWord(num);

        armstrongNumber(num);

        factorial(num);

        isPrime(num);

        hailstoneSeq(num);

        cout << "Enter Y to submit another integer, or N to quit:    ";
        cin >> choice;

    //Do while loop will continue if the user chooses any other character
    //than "n" or "N".
    }while(choice != 'n' && choice != 'N');

    //function will now terminate.
    return 0;
}

void calculateMoney(int num)
{
    cout << "The following integer converted to dollar amount is as follows:\n";
    cout << num << " Dollars" << endl;
    cout << num * 4 << " Quarters" << endl;
    cout << num * 10 << " Dimes" << endl;
    cout << num * 25 << " Nickels" << endl;
    cout << num * 100 << " Pennies\n\n\n" << endl;
}

void calculateAge(int num)
{
    double age = num;

    cout << "The following integer converted to age is as follows:  " << endl;
    cout << age << fixed << setprecision(0)
         << " Year/s" << endl;
    cout << age * 12 << fixed << setprecision(0)
         << " Month/s" << endl;
    cout << age * 365 << fixed << setprecision(0)
         << " Day/s" << endl;
    cout << age * 365 * 24 << fixed << setprecision(0)
         << " Hour/s" << endl;
    cout << age * 365 * 24 * 60 << fixed << setprecision(0)
         << " Minute/s" << endl;
    cout << age * 365 * 24 * 60 * 60 << fixed << setprecision(0)
         << " Second/s\n\n\n" << endl;


}

void numToWord(int num)
{
    int change; // for reading nums digits

    int i; // index for first loop and set by "if" statments

    cout << "Separating digits for the number   " << num << endl;

    if (num < 10)
        i = 2;
    else if (num < 100)
        i = 1;
    else
        i = 0;
    for (i; i < 3; i++)
    {
    switch(i)
    {
     case 0:
        change = (num % 1000) / 100;
        break;
     case 1:
        change = (num % 100) / 10;
        break;
     case 2:
        change = num % 10;
        break;
    }

    switch(change)
    {
    case 1:
        cout << "1   ";
        break;
    case 2:
        cout << "2   ";
        break;
    case 3:
        cout << "3   ";
        break;
    case 4:
        cout << "4   ";
        break;
    case 5:
        cout << "5   ";
        break;
    case 6:
        cout << "6   ";
        break;
    case 7:
        cout << "7   ";
        break;
    case 8:
        cout << "8   ";
        break;
    case 9:
        cout << "9   ";
        break;
    case 0:
        cout << "0   ";
        break;
    }
    }
    cout << endl;

    int k; // index for next loop

    if (num < 10)
        k = 2;
    else if (num < 100)
        k = 1;
    else
        k = 0;

    for (k; k < 3; k++)
    {

    switch(k)
    {
     case 0:
        change = (num % 1000 / 100);
        break;
     case 1:
        change = (num % 100) / 10;
        break;
     case 2:
        change = num % 10;
        break;
    }

    switch(change)
    {
    case 1:
        cout << "One ";
        break;
    case 2:
        cout << "Two ";
        break;
    case 3:
        cout << "Three ";
        break;
    case 4:
        cout << "Four ";
        break;
    case 5:
        cout << "Five ";
        break;
    case 6:
        cout << "Six ";
        break;
    case 7:
        cout << "Seven ";
        break;
    case 8:
        cout << "Eight ";
        break;
    case 9:
        cout << "Nine  ";
        break;
    case 0:
        cout << "Zero ";
        break;
    }


    }

    cout << endl;

}
void armstrongNumber(int num)
{
    int placeOne, placeTwo, placeThree, armstrong;

    placeThree = num % 10;
    placeTwo = (num % 100) / 10;
    placeOne = (num % 1000) / 100;

    armstrong = pow(placeThree, 3) + pow(placeTwo, 3) + pow(placeOne, 3);

    cout << "\n\n\n";

    if(num == armstrong)
        cout << num << " is an Armstrong number\n";
    else
        cout << num << " is not an Armstrong number\n";

}

void factorial(int num)
{
    long double factorial = 1;
    int count = num;

    for(int i = 0; i < num; i++)
        {
            factorial = factorial * count;
            count--;
        }

    cout << "\n\n\n The factorial is: " << fixed << setprecision(0)
         << factorial << "\n\n\n" << endl;

}


void isPrime(int num)
{
   bool prime = true; // flag for prime number

   for (int i = 2; i <= num/2; ++i)
   {
       if (num % i == 0)
       {
           prime = false;
           i = (num/2) + 2;
       }
   }

   if (prime)
   {
       cout << num << " is a prime\n" << endl;
   }
   else
       cout << num << " is not prime\n" << endl;


    cout << "All prime numbers between 1 and " << num << endl;




   for (int k = 1; k < num; k++)
   {
       prime = true;
       for (int x = 2; x < k/2; ++x)
       {
           if (k % x == 0 || k % 2 == 0 || k % 3 == 0)
           {
               prime = false;
               x = (k/2) + 1;
           }

           if (k % 2 == 0)
           {
               prime = false;
               x = (k/2) + 3;
           }
       }
       if (prime)
         cout << k << " number is prime" << endl;
   }
   cout << endl << endl << endl;
}

void hailstoneSeq(int num)
{
    cout << "The hailstone sequence for " << num << " is:" << endl;

    while (num != 1)
    {
        if (num % 2 == 0)
        {
          num = num/2;
          cout << num << " ";
        }

        else
        {
          num = (3 * num) + 1;
          cout << num << "  ";
        }
    }

  cout  << endl << endl << endl << endl;
}





