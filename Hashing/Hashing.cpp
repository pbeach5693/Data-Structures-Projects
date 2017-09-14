/*Patrick Beach

 This program displays a hashed array of size thirty, where half the numbers
 will be set at -1, which is equivalent to nothing, and the other half
 being random in the range of 100 and 500.  The array will then be displayed to
 the user along with a menu giving the user four options: 1. To display the
 generated array(again), 2. To search the hashed array for a number, 3. To
 insert a new number into the array via the hashing function, 4. To delete an
 existing number from the hashed array, or 5. To end the program, and at the
 same time, listing off some statistical data such as the number of times each
 position in the hashed array was probed, and the number of times a collision
 occurred, and it's respective location.  After this, the program will give
 the users signatures, and promptly terminate.
 */

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>

using namespace std;


class hashing{

public:
    hashing();
    bool isFull();
    void printArray();
    void hashFunct(int);
    int searchNum(int);
    int randNum();
    void deleteArr(int);
    void displayStats();

private:
    int SIZE;
    int arr[30];
    int hashCount[30];
    int colCount[30];

};



int main() {
    int c; //user selection in menu
    bool cont = true;
    int count = 0;


    srand(time(NULL));

    hashing hashArr;


    cout <<"**** Welcome to my hashing program ****" << endl;
    cout << endl << "This program will:" << endl;
    cout << "1. Allow the user to search for a number." << endl;
    cout << "2. Allow the user to add a number to the array." << endl;
    cout << "3. Delete a number from the array" << endl;

    cout << endl << "Cuurent Array:" << endl;

    hashArr.printArray();

    do{
        cout << endl << "Menu:" << endl;
        cout << "Enter 1 to display the generated array" << endl;
        cout << "Enter 2 to search for a number" << endl;
        cout << "Enter 3 to add a number" << endl;
        cout << "Enter 4 to delete a number" << endl;
        cout << "Enter 9 to end the program" << endl;
        cout << endl << "Enter a nunmber and press ENTER" << endl;


        while(!(cin >> c) || c!=1 && c!=2 && c!=3 && c!=4 && c!=9)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n***Invalid option***\n\n";

            cout << endl << "Menu:" << endl;
            cout << "Enter 1 to display the generated array" << endl;
            cout << "Enter 2 to search for a number" << endl;
            cout << "Enter 3 to add a number" << endl;
            cout << "Enter 4 to delete a number" << endl;
            cout << "Enter 9 to end the program" << endl;
            cout << endl << "Enter a nunmber and press ENTER" << endl;
        }


        switch (c){

                //search for number

            case 1:{
                hashArr.printArray();
            }
             break;
            case 2:{
                int num = 0; //number that will be searched for in array
                cout <<"Enter the number you would like to search for" << endl;
                cin >> num;

                int index = hashArr.searchNum(num);

                if (index >= 0){
                    cout<< "Number " <<num <<" was found in location "<< index;
                    cout << endl;
                }

                else
                    cout << num << " was not found" << endl;
                break;
            }

                //add number to array
            case 3:{
                int num = 0;
                if (!hashArr.isFull()){
                   while (num < 100 || num > 500)
                    {
                        cout << "Enter a number between 100 and 500" << endl;
                        cin >> num;
                        if(num < 100 || num > 500)
                        {
                            cin.clear();
                            cout << "***Invalid option****" << endl;
                        }
                    }
                    hashArr.hashFunct(num);
                }
                else
                    cout<< "Array is Full: unable to add another number\n";
                break;
            }

                // delete number from array
            case 4:{
                cout << "Enter a number to delete (between 100-500)" << endl;
                int num = 0;
                cin >> num;

                int index = hashArr.searchNum(num);

                if (index == -1)
                    cout << "ERROR: The number was not found" << endl;
                else{
                    hashArr.deleteArr(index);
                    cout << num << " was successfully deleted" << endl;
                }
                break;

            }
            case 9:{
                hashArr.displayStats();
                cont = false;
                break;
            }
            default:
                cout << "INCORRECT ENTERY"<<endl;
        }
    }while(cont);

    return 0;
}

/******************************************************************
//hashing()
// constructor for hashing class
******************************************************************/
hashing::hashing()
{
    SIZE = 30;


    for (int i = 0; i < SIZE; i++) //initialize the arrays
    {
        arr[i] = -1;
        hashCount[i] = 0;
        colCount[i] = 0;
    }

    for(int i = 0; i < 15; i++)
        hashFunct(randNum()) ;
}

/******************************************************************
//printArray()
//prints the array in the hashing class to the screen
******************************************************************/
void hashing::printArray (){
    for (int i = 0; i < SIZE; i++){
        if (i == 15)
            cout << endl;

        cout << arr[i] << " ";
    }
    cout << endl;
}

/******************************************************************
//randNum()
//generates a random int
//returns: the random int
******************************************************************/
int hashing::randNum() {
    int randNum = 0;
    randNum = (rand() % 400) + 100;
    return randNum;
}

/******************************************************************
//hashingFunct()
//param num: the int to be added to the array
// this function takes in an int, hashes the number and adds to
// the correct place in the array
******************************************************************/
void hashing::hashFunct(int num){

    bool found = false;
    int count = 1;
    int index = num % SIZE;
    do{

        hashCount[index]++;

        if (arr[index] == -1){
            arr[index] = num;
            found = true;
        }
        else
        {
            colCount[index]++;
            index = (num + count) % SIZE;
        }

        count++;

    }while(!found);

}

/******************************************************************
//searchNum(): searches an array to determind if the
//int is in the array
//param num: the int to be searched for
//returns: -1 if the number is not found, or the index of the array
//where the number is located if found
******************************************************************/
int hashing::searchNum(int num){
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == num)
            return i;

    return -1;
}

/******************************************************************
//isFull()
//returns true if the array is full, false otherwise
******************************************************************/
bool hashing::isFull(){
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == -1)
            return false;
    return true;
}

/******************************************************************
//deleteArr()
//param num: the index of the array location that is to be deleted
//deletes an int for the array
******************************************************************/
void hashing::deleteArr(int num){
    arr[num] = -1;
}

/******************************************************************
//displaysStats()
//displays the final stats when user ends program
******************************************************************/
void hashing::displayStats(){

    for(int i = 0; i < SIZE; i++)
    {
        cout << "Location " << i+1 << " has been probed " << hashCount[i]
        << " Times and has " << colCount[i] << " collisions\n";
    }

    cout<<"\n\n\nThis program was implemented by Patrick Beach,"<<
    "David Hunter, and Damian Bocanegra";
}
