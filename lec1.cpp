// first we are using the c++ in this folder..
// understand the command who execute the code in terminal...
// g++ -std=c++23 -Wall -Wextra -pedantic lec1.cpp -o lec1 && ./lec1

// -Wall for all warnings
//-Wextra for extra warnings
//-pedantic for strict standard compliance c++

#include <iostream>
#include <limits>
using namespace std;

long long int factorialOfNumber(long long int a)
{
    if (a <= 1)
    {
        return 1;
    }
    return a * factorialOfNumber(a - 1);
}

void printhollowdaimond(int n)
{

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }
        //*
        cout << "*";
        // inner space
        int innerSpaces = 2 * i - 1; // improves readability and recaluclulating the expression..
        for (int j = 0; j < innerSpaces; j++)
        {
            cout << " ";
        }
        // last *
        if (i > 0)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        // spaces
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }
        //*
        cout << "*";
        // inner space
        int innerSpaces = 2 * i - 1;
        for (int j = 0; j < innerSpaces; j++)
        {
            cout << " ";
        }
        // last *
        if (i > 0)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printButterFly(int n)
{
    for (int i = 0; i < n; i++)
    {
        //*
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }

        // spaces
        int innerspaces = 2 * (n - i - 1);
        for (int j = 0; j < innerspaces; j++)
        {
            cout << " ";
        }
        //*
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        //*
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }

        // spaces
        int innerspaces = 2 * (n - i - 1);
        for (int j = 0; j < innerspaces; j++)
        {
            cout << " ";
        }
        //*
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    cout << "This is my first c++ code in this folder\n";
    cout << "This is my fisrt c++ code in this folder" << "\n";
    cout << "Hey buddy,\n"
         << "Im Aakash Chawla, ownwer of this repo.\n";

    // What is cout?
    // cout stand for character Output

    // its is an object provided by the <iostream> library

    // it job to print output on terminal..

    // how does << work?
    // Actually, it is called think stream insertion operator

    // cout << "Hello" << "World\n"

    // work beacuse every inserstion return cout again

    // what is diff between endl vs \n
    // they both are not identical..endl is move cursor next line and flush all buffer..

    // where \n just move next line..(new line)

    // What is buffering?
    // instead of printing every character immediately..h e l l o

    // the computer first store output in memory and then prints evrything together..

    // which  one is better..\n cause
    // endl inserts a newline and flushes the output stream. \n only inserts a newline.

    // Comments
    // Complier ingnore comments

    // for multiline /*... */

    // Do comments increase executable size? No complier rmoves them before genrating machine code..

    // What is variable in c++?
    // A variable is a named location in memory that stores a value , and that value can change during the execution of a program..

    // Think of a varible as labelled box

    /*
    Variable

      age
   ┌─────────┐
   │   20    │
   └─────────┘
   */
    // age is variable name and 20 value stored in memory allpcated by the computuer represent as box..

    // Variable declaration,The gernal syntax is

    // datatype variable_name;

    // for eg, int age;

    // Variable naming rules
    // cant start with digit, no used reserved keyword, also no spaces..

    // camelCase

    // each variable has its own memory storage

    int age = 25;
    cout << "age = " << age << endl;
    cout << "age's address = " << &age << endl;

    // also assign other value,
    age = 30;
    cout << "age = " << age << endl;

    // also copy the same value to other variable
    int age1 = age;
    cout << "age1 = " << age1 << endl;

    // declarationa and intialization
    // int age;
    // cout<<age<<endl; this is return us any garbage value..

    // Always initialise variables before using them.

    // declaring the same varible twice in the same scope..

    // int age = 30; // already intialized, Give us Error

    // In this using = and == both operator,first one is use for assignment and other for comparing value..

    // Datatype

    // Why we use data type? cause data store only in bits..and the complier needs tfo know how much memory to reserve and how to interpret those bits..

    // 65 -> integers or character 'A'
    // Data type tells which interpretion to use..

    // Integer ->4 Bytes, -2^31 to 2^31 -1
    // Character -> 1 Byte, ASCII value(American standered code for information interchange)

    // A=65,B=66..

    // ASCII has 128 basic character.Unicode supports characters form many writing system and symbol worldwide..

    // Float: 4 Bytes, float pi=3.14f;, approx 6-7 digits precicion..
    // using f, beacuse withourt that it deafult treated as double literal..
    // adding f makes it a float literal..

    // Double:8 bytes, approx 15-16 digits precisions.

    // Bool: 1 bytes, just store 0 and 1 in form of true or false..
    // bool b=6, then any non zero integer beacomes true..while 0 become false..

    // void means no value..return nothing

    // function: sizeof(variable or datatype)

    // when is sizeof calucluated?..its calculated at the time of compline time..

    int a = 10;            // 4 bytes
    double b = 10.8888888; // 8 bytes
    float c = 10.678f;     // 4 bytes
    bool i = true;         // 1 bytes
    char n1 = 'A';         // 1 bytes

    cout << "Size of all datatype\n";
    cout << "Size of " << sizeof(a) << endl;
    cout << "Size of " << sizeof(b) << endl;
    cout << "Size of " << sizeof(c) << endl;
    cout << "Size of " << sizeof(i) << endl;
    cout << "Size of " << sizeof(n1) << endl;

    // type casting
    // changing one data type into another..

    // implicitly casting..
    // complier autumactically converts

    // 1
    int a1 = 'A';
    cout << a1 << endl; // 65

    // 2
    float f1 = 6873.29f;
    double d1 = f1;
    cout << typeid(d1).name() << endl;

    cout << typeid(a1).name() << endl; // i
    cout << typeid(b).name() << endl;  // d
    cout << typeid(c).name() << endl;  // f

    float f = 108.448;
    cout << typeid(f).name() << endl; // f

    // typeid(x).name() return the datatype of the variable

    // int-i,bool-b,char-c etc..but the output of implementation-defined and may be compiler specific..
    // it maybe vary from on diff complier..

    // why implicitly conversion? To avoid data lose where possible..

    // Explicitly casting
    // programmer force to convert to particular datatype

    // 1
    // above variable f..defined as float..

    cout << (int)f << endl; // 108.448->108only
    cout << static_cast<int>(f) << endl;

    // In modern c++, we are using
    // static_cast<int(var)

    // Why use static_cast instead of (int)?
    // Because it is safer, clearer, and fits C++'s type system better.

    // Input (cin)
    // int age_customer;
    // cout << "Could you pls tell me your age ";
    // cin >> age_customer;
    // cout << "Your age is " << age_customer << endl;

    // cin vs getline(cin,variable)
    /*
    | Feature          | `cin`                 | `getline()`           |
    | ---------------- | --------------------- | --------------------- |
    | Reads            | One word              | Entire line           |
    | Stops reading at | Space, Tab, Enter     | Only Enter (`\n`)     |
    | Can read spaces? | ❌ No                  | ✅ Yes                |
    | Used for         | Numbers, single words | Full names, sentences |
    */

    // How cin works internally?
    // keyboard buffer is "Hello world c++"
    // cin>> word onlt takes "hello" only cause cin stops at white space..and other remain in keyboard buffer "world c++"

    // and how getline work..those in kwyboard buffer..read evrything until(\n-> enter)

    // lets take a example

    // int number;
    // string line;

    // cout << " your number: ";
    // cin >> number;
    // cout << "your number: " << number << endl;

    // // here \n in buffer so, to clean it.

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // // also used cin.ignore() for one character \n..

    // cout << "your line: ";
    // getline(cin, line);
    // cout << "your line is: " << line << endl;

    /*
    output
    your number: 78
    your number: 78
    your line: your line is:
    */

    // cause-your number: 25\n(\n comes with enter)

    // keyboard buffer stores "25\n" then 25 take as number..and \n remaining in keyboard buffer and getline stops only at \n that stores in keyboard previously..so not input taken..only return nothing..It immediately sees the newline and thinks:
    //"The line is already finished."
    // So it returns an empty string.

    // the solution of this problem is..

    // cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // cin.ignore() removes just only one character default..and but this above removes all characters upto and including the newline,making it much safer when switching from cin to getline()...
    // start from leftover and empty whole buffer..

    // string ab;
    // int num1 = 88;

    // cout << "hey whats your name: ";
    // cin >> ab;
    // cout << "Hey!!, " << ab << endl;

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // cout << "your age: ";
    // cin >> num1;
    // cout << "ohh, your age is: " << num1 << endl;

    // Arthematic operations
    //+,-,*,/,%

    // Realrional operations
    //<,>,<=,>=,==,!=

    // Logical opertors
    //  ||,&&,!

    // Sum of two number given by users.
    // int num6, num7;
    // cout << "Enter first number: ";
    // cin >> num6; // automatic next line
    // cout << "Enter second number: ";
    // cin >> num7; // automatica next line
    // cout << "Sum of numbers is " << (num6 + num7) << endl;

    // In this, also not using cin.ignore() why?
    // auto line skip not \n in buffer used..its enter in terminal..

    // here cin >>, after one after one..because of that, its remove the leftside all buffer and new empty buffer..

    // What is conditional statement?

    // A conditional statemenet lets the prog makes decision

    // condition -> if yes? then do this..A if no? then do this..B

    // syntax
    /*
    if(condition){
        execute the code
    }
    */
    // if condition follow then execute the code..if not then skip..give nothing..

    // syntax
    // if-else
    /*
    if(condition){
        execute A
    }else{
        execute B
    }
    */

    // syntax

    /*
    if-else if-else

    if(condition1){
        execute A
    }else if(condition2){
        execute B
    }else{
        execute C
    }
        */

    // what is short circuit behaviour  evaluation..
    // The prevents division by zero..using &&..is called short circuit behaviour..

    // What is ternary operators..?

    // consdition? executeA(when condition is true): executeB(when false);

    cout << (age > 18 ? "you r adult" : "you r minor") << endl;

    // when to use?

    // int max=(a>b)?a:b;
    // its good way to do this..

    // loops: loops repeat block of code..without do it once and once..so many time

    // while,do while,for loops

    // while:
    /*
    while(condition){
        execution code..(repeat until condition return false..)or break in code..
    }

    if cond. true? ->run->again(check condition).
    */
    int j = 1;
    while (j < 6)
    {
        cout << j << endl;
        j++;
    }

    // can while loop run zero times?yes if first iteration is false..then inner code not execute..

    // for loop

    /*
    for(initialization;condition;updation){
       // code execution
    }
    */

    for (int i = 0; i < 5; i++)
    {
        cout << "hello world" << endl;
    }

    // flow something like..init->cond->body->upd.->cond->body..

    //++i vs i++ (pre and post increment)
    // i++, first use the value, then increment
    //++i,first incrementm,then use value

    // which is faster? for primitive datatype both are same..but for STL iterations..++i more efficient.

    // do-while loop:

    /*
    do{
        body..
    }while();

    */

    // run->condition->run->condition...it is not not run zero times..body at least once.

    // question 1 to n sum..

    int sum = 0;
    int tym = 500;
    for (int i = 1; i <= tym; i++)
    {
        sum += i;
    }
    cout << sum << endl;
    // O(n)

    // sum of odd numbers

    int oddSum = 0;
    int t = 100;
    for (int i = 1; i <= tym; i++)
    {
        if (i % 2 == 1)
        {
            oddSum += i;
        }
    }
    // other way also.. iteration skip 2 step i+=2
    // or by formula finding the sum of nth odd sum.. number of odd= (n+1)/2 and sum is ((n+1)/2)^2

    cout << "first n odd number sum is: " << oddSum << endl;

    // Check Is number is prime or not?

    bool isPrime = true;
    int p = 97; // must be greater than 1..

    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << (isPrime == true ? "yes its prime" : "sorry its not prime") << endl;

    // also write in the form of input the number..and check also n>1 or not?

    /*
    if (n > 1)
    {
        code above..
    }
    else
    {
        cout << "pls enter number grater then "
    }

    */

    // Which is better sqrt(n) or i*i<=n ?
    // second one because it is avoids repeatedly computing sqrt(n) and is the standard approach in interview and competitive programming..for large integers also doing this..

    // switch loop..used for multiple condition check in the same..question

    // syntax
    /*

    switch(expression){
        case value1:
            //code
            break;

        case value2:
            //code
            break;

        case value3:
            //code
            break;

        case value4:
            //code
            break;

        deafult:
            //code

    }

    */

    // int d;
    // cout << "Enter your number pls(1-7): ";
    // cin >> d;

    // What types are allowed in expressio of switch? only int,char,enum and also bool in new modern c++..

    // The expression is evaluated once.
    // case values must be constant expressions.
    // No duplicate case values.
    // default is optional.

    // can we use variable in case?
    // yes if its const int a=99; otherwise not..beacuse it compile time constants..

    // also we are not write condition inside case? like a>10;

    /*
    When should you choose switch instead of if-else?

    Use switch when:

    You're comparing one expression against many fixed constant values (e.g. menu options, days of the week, commands).

    Use if-else when:

    You need ranges (score >= 90),
    Multiple conditions (age >= 18 && citizen),
    Floating-point comparisons,
    Or string comparisons (in standard C++).
     */

    // switch (d)
    // {
    // case 1:
    //     cout << "Monday" << endl;
    //     break;
    // case 2:
    //     cout << "Tuesday" << endl;
    //     break;
    // case 3:
    //     cout << "Wednesday" << endl;
    //     break;
    // case 4:
    //     cout << "Thrusday" << endl;
    //     break;
    // case 5:
    //     cout << "Friday" << endl;
    //     break;
    // case 6:
    //     cout << "Saturday" << endl;
    //     break;
    // case 7:
    //     cout << "Sunday" << endl;
    //     break;
    // default:
    //     cout << "Invalid number" << endl;
    // }

    // // sum of all number from 1 to N which are divisible by 3
    // int div3 = 100;
    // for (int i = 0; i <= div3; i += 3)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // // for sum
    // int sum3 = 0;
    // for (int i = 3; i <= div3; i += 3)
    // {
    //     sum3 += i;
    // }

    // cout << "sum of all first N,  divisible by 3 digits is " << sum3 << endl;

    // // print factorial of a Number N.

    // int fac = 1;
    // long long int factorialN = 1;

    // for (int i = 2; i <= fac; i++)
    // {
    //     factorialN *= i;
    // }

    // // optimize to i>=1..beacuse multiply with 1..dont effect the answer..

    // cout << "factorial of " << fac << " is " << factorialN << endl;

    // // also with the recursion,

    // cout << factorialOfNumber(10) << endl;
    // cout << factorialOfNumber(0) << endl;

    // In the iterative version of factorial is better beacuse, its space complexity is O(1) and but recursion its O(n)..

    // now we gonna move on patterns

    // Square patterns
    cout << endl;

    /*
    1234567
    1234567
    1234567
    1234567
    1234567
    1234567
    1234567
    */

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    /*
     * * * * * * *
     * * * * * * *
     * * * * * * *
     * * * * * * *
     * * * * * * *
     * * * * * * *
     * * * * * * *
     */

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        A B C D
        A B C D
        A B C D
        A B C D
    */

    // same for alphabets ABCD
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (char j = 'A'; j < 'A' + n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        char ch_in = 'A';
        for (int j = 0; j < n; j++)
        {
            cout << ch_in;
            ch_in++;
        }
        cout << endl;
    }

    cout << endl;

    // 123
    // 456
    // 789

    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << k << " ";
            k += 1;
        }
        cout << endl;
    }

    cout << endl;
    // same for ASCII values
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch += 1;
        }
        cout << endl;
    }

    // loops always from 0 to less than n..and if increasing value defined outside the parent loop and re-assigning then define in parent loop..

    // same for character and define char ch='A' and for next..just add +1 in it..

    cout << endl;
    // Triangle patterns
    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    /*
        1
        22
        333
        4444
        55555
    */

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (i + 1);
        }
        cout << endl;
    }

    // same for triangle ASCII
    /*
        A
        BB
        CCC
        DDDD
        EEEEE

    */

    cout << endl;
    char ch1 = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch1;
        }
        ch1++;
        cout << endl;
    }

    cout << endl;

    /*
        1
        12
        123
        1234
        12345
    */

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;

    // always in triangle plays with scope variable..
    for (int i = 1; i <= n; i++)
    {

        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;
    // Floyd's Triangle pattern..
    int fl_num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << fl_num << " ";
            fl_num++;
        }
        cout << endl;
    }

    cout << endl;

    // same for ascii values

    char fl_num_c = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << fl_num_c << " ";
            fl_num_c++;
        }
        cout << endl;
    }

    cout << endl;

    // Reverse Triangle pattern

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    char Rfl_ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (char j = Rfl_ch; j >= 'A'; j--)
        {
            cout << j << " ";
        }
        cout << endl;
        Rfl_ch++;
    }

    cout << endl;

    // Inverted Triangle pattern

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        // num
        for (int j = 1; j <= n - i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }

    // same for ascii values...

    cout << endl;
    char Itp_ch = 'A';
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        // num
        for (int j = 1; j <= n - i; j++)
        {
            cout << Itp_ch;
        }
        Itp_ch++;
        cout << endl;
    }

    // Pyramid Triangle

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // num
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        // num
        for (int l = i - 1; l > 0; l--)
        {
            cout << l;
        }
        cout << endl;
    }

    // hallow daimond pattern
    printhollowdaimond(5);

    // butterfly pattern
    cout << endl;

    printButterFly(10);

    return 0;
}
