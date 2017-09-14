/*Patrick Beach

This program takes input from the user for a stack and queue to be compared.
The program checks to see if the stack and queue have the same elements
in the same position and if the sizes are equal. Then it checks the first stack
to see if (,{,[,<,>,],},) are all matching correctly.
This process continues until the user terminates the program.
*/

#include<iostream>
#include<string>
#include<limits>
#include<iomanip>
using namespace std;


template<class output>
output response(output match)
{
    bool isMatch;

    if(match != 0)
        return true;
    else
        return false;
}


class sentenceStack
{
public:
    sentenceStack(int);
    ~sentenceStack();
    void push(char);
    void pop(char &);
    bool isEmpty() const;
    bool isFull() const;

private:
    int *stackArray;
    int stackSize;
    int top;
};


class sentenceQueue
{
public:
    sentenceQueue(int);
    ~sentenceQueue();
    void enqueue(char);
    char dequeue(char &);
    bool isEmpty() const;
    bool isFull() const;

private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;
};


bool comparison(sentenceQueue, sentenceStack);

int closure(sentenceQueue, sentenceStack, int);

void input(string &, string &, int);

int getLength(sentenceQueue, sentenceStack);


int main()
{

    string sentence1, sentence2;
    int testnum = 0;
    char temp1, temp2;
    bool identical, closed, isSame = false;
    int choice;


    cout << "*** Welcome to My stack / Queue Program ***\n\n";
    cout << "The function of this program is to:\n";
    cout << "      1 -  Validate that a stack and a\n";
    cout << "           queue is identical.\n";
    cout << "           Stacks / queues are same if\n";
    cout << "           they have the same number of elements, symbols,\n";
    cout << "           and their elements are the same.\n";
    cout << "           corresponding positions are the same.\n\n";
    cout << "      2-   The program also outputs whether the elements\n";
    cout << "           do have the same matching group symbols\n\n\n";


    do
    {

        cout << "Select from the following menu" << endl;
        cout << "1.    Enter Stack / Queue Values." << endl;
        cout << "9.    Terminate the program      ";

        while(!(cin >> choice) || choice != 1 && choice != 9)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid option\n\n";

            cout << "Select from the following menu" << endl;
            cout << "1.    Enter Stack / Queue Values." << endl;
            cout << "9.    Terminate the program      ";

        }

        if(testnum == 0)
            cin.ignore(numeric_limits<streamsize>::max(), '\n' ) ;


        if(choice == 1)
        {
            int S3size = 0, Q2size = 0;

            input(sentence1, sentence2, testnum);

            sentenceStack S(sentence2.size());
            sentenceStack S3(sentence2.size());
            sentenceQueue Q(sentence1.size());
            sentenceQueue Q2(sentence1.size());


            for(int i = 0; i < sentence1.size(); i++)
            {

                Q.enqueue(sentence1[i]);

                switch(sentence1[i])
                {
                case '(':
                    S3.push(sentence1[i]);
                    S3size++;
                    break;
                case '{':
                    S3.push(sentence1[i]);
                    S3size++;
                    break;
                case '[':
                    S3.push(sentence1[i]);
                    S3size++;
                    break;
                case '<':
                    S3.push(sentence1[i]);
                    S3size++;
                    break;
                case ')':
                    Q2.enqueue(sentence2[i]);
                    Q2size++;
                    break;
                case '}':
                    Q2.enqueue(sentence2[i]);
                    Q2size++;
                    break;
                case ']':
                    Q2.enqueue(sentence2[i]);
                    Q2size++;
                    break;
                case '>':
                    Q2.enqueue(sentence2[i]);
                    Q2size++;
                    break;
                }
            }


        for(int i = sentence2.size();i > 0; i--)
            S.push(sentence2[i-1]);


        identical = comparison(Q, S);

        identical = response(identical);


        int same = 0;
        if(S3size != 0 && Q2size != 0)
            same = closure(Q2, S3, same);
        else if(S3size != Q2size)
            same++;


        isSame = response(same);


        if(!identical)
            cout << "\n\Stack and Queue are not identical" << endl;
        else
            cout << "\n\nStack and Queue are identical" << endl;


        if(isSame)
            cout << "\n\nFirst expression does not have matching group symbols" << endl;
        else
            cout << "\n\nFirst expression does have matching group symbols" << endl;



    cout << endl << endl;

    testnum++;
    }

    }
    while(choice == 1);

    cout << "\n\n*** Program is terminated.  Written by Patrick"
         << " and Damian Bocanegra ***";

    return 0;
}

bool comparison(sentenceQueue Q, sentenceStack S)
{
    bool identical = true;;
    char temp1, temp2;
    while(!S.isEmpty())
    {
        S.pop(temp1);

        Q.dequeue(temp2);

        if(temp1 != temp2)
            identical = false;
    }
    while(!Q.isEmpty())
    {
        S.pop(temp1);
        Q.dequeue(temp2);
    }

    return identical;
}

void input(string &sentence1, string &sentence2, int testnum)
{
    cout << "\nEnter stack values terminated by semicolon ';'      ";
    getline(cin,sentence1,';');
    cout << "Enter queue values terminated by semicolon ';'      ";

    if(testnum == 0)
        cin.ignore();

    getline(cin,sentence2,';');
}

int closure(sentenceQueue Q, sentenceStack S, int same)
{
    int total = same;
    char temp1, temp2;


    while(!S.isEmpty())
    {
        S.pop(temp1);

        Q.dequeue(temp2);

        if(temp1 == '(' && temp2 != ')')
            total++;
        else if(temp1 == '{' && temp2 != '}')
            total++;
        else if(temp1 == '[' && temp2 != ']')
            total++;
        else if(temp1 == '<' && temp2 != '>')
            total++;
    }

    return total;
}




//Stack functions begin
sentenceStack::sentenceStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

sentenceStack::~sentenceStack()
{
    if(!isEmpty())
        delete [] stackArray;
}

void sentenceStack::push(char num)
{
        top++;
        stackArray[top] = num;
}

void sentenceStack::pop(char &num)
{
    if(!isEmpty())
    {
        num = stackArray[top];
        top--;
    }
}

bool sentenceStack::isEmpty() const
{
    if(top == -1)
        return true;
    else
        return false;
}

bool sentenceStack::isFull() const
{
    if(top == stackSize - 1)
        return true;
    else
        return false;
}




//This is where the queue functions begin

sentenceQueue::sentenceQueue(int size)
{
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

sentenceQueue::~sentenceQueue()
{
    if(!isEmpty())
        delete [] queueArray;
}

void sentenceQueue::enqueue(char num)
{

    if(rear == queueSize - 1)
        rear = 0;
    else
        rear += 1;

    queueArray[rear] = num;

    numItems++;
}

char sentenceQueue::dequeue(char &num)
{
    if(!isEmpty())
    {
        front = (front + 1) % queueSize;
        num = queueArray[front];
        numItems--;
    }
}

bool sentenceQueue::isEmpty() const
{
    if(numItems != 0)
        return false;
    else
        return true;
}

bool sentenceQueue::isFull() const
{
    if(numItems < queueSize)
        return false;
    else
        return true;
}




