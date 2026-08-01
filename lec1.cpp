// first we are using the c++ in this folder..
// understand the command who execute the code in terminal...
// g++ -std=c++23 -Wall -Wextra -pedantic lec1.cpp -o lec1 && ./lec1

// -Wall for all warnings
//-Wextra for extra warnings
//-pedantic for strict standard compliance c++

#include <iostream>
#include <limits>
#include <bitset>
#include <algorithm> //for sorting we include
using namespace std;

inline int calculateMultiply(int a, int b)
{
    return a * b;
}

// WAF to find sum of 1 to N.
// WAF to calculate factorial N.
// WAF to find sum of digits.
// WAF to calculate nCr.
// WAF to check number is prime or not.
// WAF to print the prime number from 1 To N.
// Fibonacci series..
// another way to doing the same.

int sumOfN(int a)
{
    int sumN = 0;
    for (int i = 1; i <= a; i++)
    {
        sumN += i;
    }
    return sumN;
}

// without recursion

long long int factorialOfN(long long int a)
{
    long long int facAns = 1;
    if (a >= 0)
    {
        for (int i = 2; i <= a; i++)
        {
            facAns *= i;
        }
        return facAns;
    }
    else
    {
        cout << "bsdk sahi value dal..-ve kyu dal rha h?" << endl;
        return -1;
    }
}

// with recusrsion
long long int factorialOfNumber(long long int a)
{
    if (a <= 1)
    {
        return 1;
    }
    return a * factorialOfNumber(a - 1);
}

// sum of digits

int sumOfDigit(long long int a)
{
    a = abs(a); // also allowing -ve numbers..
    int sumD = 0;

    while (a != 0)
    {
        sumD += (a % 10);
        a /= 10;
    }

    return sumD;
}

// calculate the ncr..

long long int comnbination(int n, int r)
// work only whe 0<=r<=n

{
    if (r > n || r < 0)
        return -1;
    else
    {
        return factorialOfN(n) / (factorialOfN(r) * factorialOfN(n - r));
    }
}

// check Is prime or not?

bool IsPrime(int a)
{
    if (a <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

// print prime 1 to N

void printPrimes(int n)
{
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (IsPrime(i))
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout << "bhai thoda greater than 1 plss" << endl;
    }
}

// fibonacci series..sum of previous two term..and 0th index is 0 and 1st index is 1..so 2nd index sum of 0th and 1st term..

int fibonacciAtIndex(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciAtIndex(n - 1) + fibonacciAtIndex(n - 2);
}
// O(2^n)

// also we create O(N) complexity fibonacci series

void fibonacciOn(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        int c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

void fibonacciSeries(int n) // based on index..
{

    for (int i = 0; i < n; i++)
    {
        cout << fibonacciAtIndex(i) << " ";
    }
    cout << endl;
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

// convert binary to dec for unsigned only
int getDecimalNumber(long int n)
{
    int decN = 0, pwr2 = 1;
    while (n > 0)
    {
        int digit = n % 10;
        decN += pwr2 * digit;
        pwr2 *= 2;
        n /= 10;
    }
    return decN;
}
// also for signed number of 1byte size..

// convert dec into bianry

long int getBinaryNumber(int n)
{
    int ans = 0;
    int power10 = 1;
    while (n > 0)
    {
        int r = n % 2;
        ans += r * power10;
        power10 *= 10;
        n /= 2;
    }
    return ans;
}

// write a function to check IS number make of power of 2 or not with the help of loop..?

bool isPow2(int a)
{
    if (a <= 0)
    {
        return false;
    }

    int pow = 1;

    while (pow < a)
    {
        pow *= 2;
    }

    return pow == a;
} // for only check is power of 2 or not

// for calculate the power if power of 2,otherwise return -1

int getPow2(int a)
{
    if (a <= 0)
        return -1;

    int pow = 1;

    while (pow < a)
    {
        pow *= 2;
    }

    if (pow == a)
        return pow;

    return -1;
}

// TC(logn)

// also better version to not using pow..just use power variable//

// we are using the concept of mathematcal that.. any number power of 2..and with AND logical operator with less than 1..gives is 0

// (n &(n-1))==0 that mean 1->power of two and 0 not power of 2..

bool isPow2WL(int n)
{

    return n > 0 && (n & (n - 1)) == 0;
}

// also count the pow2 if power of 2,otherwise -1

// using bitwise operator

int getPow2B(int n)
{
    if (n <= 0 || (n & (n - 1)))
    {
        return -1;
    }

    int pow = 0;
    while (n > 1)
    {
        n >>= 1; // divide 2 and assign to n
        pow++;
    }

    return pow;
}

// using inbuit funtion in clang in mac..

//__builtin_popcount(n) count the 1 bit in the number..
//__builtin_ctz(n) count the tailing zeros in the binary form representation..
// and no of zeros of 100000..give us power of 2..only if first hheading bit is 1..

// if __builtin_popcount(n)==1 then it mean poerof 2..

int getpow2Ibuilt(int n)
{
    if (n <= 0 || __builtin_popcount(n) != 1)
        return -1;

    return __builtin_ctz(n);
}

// WAF to reverse integers N.

int reverseInt(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int d = n % 10; // get digit
        ans = ans * 10 + d;
        n /= 10;
    }
    return ans;
}

// linear search target el in Array
int targetElArr(int arr[], int size, int trgt)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == trgt)
        {
            return i;
        }
    }
    return -1;
} // O(n)TC

// Two-Pointer Approach..

// Reverse the array,original once array

void reverseArr(int arr[], int s)
{
    int st = 0, end = s - 1;
    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

// WAF to calculate sum and product of all numbers in an array..

void sumProductArr(int arr[], int s)
{
    int sum = 0, product = 1;

    for (int i = 0; i < s; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }
    cout << "sum: " << sum << endl;
    cout << "product: " << product << endl;
}

// WAF to swap max and min of an array..

void swapMinMaxArr(int arr[], int s)
{
    int minel = INT_MAX;
    int maxel = INT_MIN;

    for (int i = 0; i < s; i++)
    {
        minel = min(minel, arr[i]);
        maxel = max(maxel, arr[i]);
    }
    swap(minel, maxel);
}

// WAF to print all unique values in an array..
// using nested loop,shorting,XOR,hash Map also..

void uniqueEl(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
            }
        }
    }
}

// using XOR
// only single unique el..

int uniqueEL(int arr[], int s)
{
    int ans = 0;
    for (int i = 0; i < s; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
// O(n) TC

// WAF to print intersection of 2 array

void intersectionArray(int arr[], int s, int arr1[], int s1)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s1; j++)
        {
            if (arr[i] == arr1[j])
            {
                cout << arr[i] << " ";
                arr1[j] = -1; // mark as unread..
                break;
            }
        }
    }
}
// pair sum-return pair in sorted array with target sum

// using brute force
vector<int> targetSumPair(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    for (int i = 0; i < nums.size(); i++)
    {
        int currSum = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

// using two pointer approach..

vector<int> targetSumPair1(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    int st = 0, lt = nums.size() - 1;
    while (st < lt)
    {
        if (nums[st] + nums[lt] < target)
            st++;
        else if (nums[st] + nums[lt] > target)
            lt--;
        else
        {
            ans[0] = st;
            ans[1] = lt;
            return ans;
        }
    }
    return ans;
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

    // What is function?
    // A function is a named block of reusable code that performs a specific task...

    // instead of writing the same code repeatedly, you write it once in function and call it whenever needed..

    // function always define in before int main() function..

    // gernal syntax:
    /*
        returnType name_of_function(parameters){
            //body
            return value;

        }
    */

    // int sum(int a, int b){
    //     return a+b;
    // }

    // int sum(int a,int b) tells complier that fumction declareation (prototype)

    // call the function
    // sum(10,29)

    // flow
    // main->sum function->return somthing->main contionous

    // types of imp. functions
    // No parameter,No return
    // parameter,No return
    // no parameter,return
    // parameter,return also

    // void function

    // void message(){
    //     cout<<"Hi babayy!!"<<endl;
    // }

    // local variable..those exist only inside the function..

    /*
        void num(){
            int num=0;
        }
        here num is local variable of num function..
    */

    // Global variable: those variable define above the all functiona, outside the int main() also..

    // int x=100;
    // void fun()..
    // int main()..{

    // }

    // Global variables can be accessed by all functions in the file(unless hidden by a local variable of the same name).

    /*
        int x = 100;
        void fun()
        {
            cout << x;
        }
    */

    // argument and parameter
    // int function(int a, int b), here a and b are parameters
    // function(a,b),here a and b are arguments

    // what is call by value and call by reference and type of this call by pointer..?

    // call by value..
    /*
        void change(int x)
        {
            x = 100;
        }

        int main()
        {
            int a = 10;

            change(a);

            cout << a;
        }

        output is 10..
        cause a copy is passed..
    */

    // call by reference

    /*
        void change(int &x){
            x=100;
        }
            make variable and store the same address of given int value..

        int main(){
            int a=10,
            change(a);
            cout<<a;
        }
            output is 100 now..
            No copy is made. The original variable changes.
    */

    // call by pointer
    /*
        void change(*int x){
            *x=100;
        }
            //pointer store the address..

        int main(){
            int a=10;
            change(&a);//give the address
            cout<<a;
        }
            output is 100 now, here we create a new pointer x and give it address of a..

    */

    // recursion also possible with the help of function
    //     int factorial(int n)
    // {
    //     if (n <= 1)
    //         return 1;

    //     return n * factorial(n - 1);
    //}

    // deafult argument and inline function

    /*
        void greet(string n="Guest"){
            cout<<n;
        }
        int main()
            {
                greet(); Guest
                greet("Aakash");Aakash
            }
        //initialize variable in parameter..then consider as deafult argument.
    */

    // Q1) If a variable is globally defined and a function declares a local variable with the same name, can other functions still access the global variable?

    // Answer: Yes.

    // The local variable hides (shadows) the global variable only inside that function.

    // Other functions can still access the global variable normally.

    // it hides the shadow of global variable but not the global variable itself..

    // if global variable define of variable name "a", then in function the same name..variable define and use..in function

    /*
            int x = 100;     // Global variable

            void fun1()
            {
                int x = 10;  // Local variable

                cout << "fun1 x = " << x << endl;
            }

            void fun2()
            {
                cout << "fun2 x = " << x << endl;
            }

            int main()
            {
                fun1();
                fun2();
            }
            Output
            fun1 x = 10
            fun2 x = 100
    */

    // what is function overloading?
    // Function overloading means:

    // Multiple functions can have the same name, provided their parameter lists are different.

    // The compiler chooses the correct function based on the number, type, and order of arguments.

    /*
        #include <iostream>
        using namespace std;

        void print(int x)
        {
            cout << "Integer: " << x << endl;
        }

        void print(double x)
        {
            cout << "Double: " << x << endl;
        }

        void print(string s)
        {
            cout << "String: " << s << endl;
        }

        int main()
        {
            print(5);
            print(5.5);
            print("Hello");

            Integer: 5
            Double: 5.5
            String: Hello

            Invalid Overloading
            int sum(int, int);

            double sum(int, int);

            ❌ Compiler Error

            Why?

            Because return type is not part of a function's signature. The compiler cannot distinguish these functions when you write sum(10, 20);.
        }
    */

    // What is inline function..

    // inline int calculateMultiply(int a, int b)
    // {
    //     return a * b;
    // }

    // cause inline function also define in out of int main(), its use only for run at compiled time..instead of making stack in memory and run at execution time..

    // if we define the same out side, then its just pass value to compiler 5 and 10 and simply return 5*10..as we doing in compile time cout<<5*10...
    cout << endl;

    cout << "Inline function calling and value is: " << calculateMultiply(5, 10) << endl;

    // why we dont use this?

    // Now your executable becomes huge.

    // if inline void printArray()
    {
        // 500 lines of code
    }

    // then this code run 100 times cout<<500 lines..

    // Large programs run slower, because the CPU cache becomes less effective.

    // So inline can actually reduce performance if overused.

    // inline is request, not a command..its depend on complier makes the final decision.

    // just use for small code..

    // An inline function is a function for which the compiler is requested to replace the function call with the function body at the call site to reduce function call overhead. The compiler may accept or ignore this request depending on its optimization decisions.

    // In modern compilers, may still be inlined by the compiler even without the inline keyword, if optimization is enabled

    // WAF to find sum of 1 to N.
    // WAF to calculate factorial N.
    // WAF to find sum of digits.
    // WAF to calculate nCr.
    // WAF to check number is prime or not.
    // WAF to print the prime number from 1 To N.
    ////Fibonacci series..
    // another way to doing the same.

    cout << "Sum of N number" << sumOfN(10) << endl;

    cout << "Factorial of given number wit loop menthod: " << factorialOfN(10) << endl;

    cout << "Factorial if given number with recursion method: " << factorialOfN(10) << endl;

    cout << "Sum of digits " << sumOfDigit(147397) << endl;

    cout << "Calculate ncr with n and r: " << comnbination(10, 5) << endl;

    cout << "Is number prime or not?: " << IsPrime(73) << endl;

    cout << "Print primes number first N number:" << endl;
    printPrimes(100);

    cout << endl;

    cout << "Fibonacci Series:" << endl;
    fibonacciSeries(4); // number of value..

    cout << "here fibonnaci series with O(n): " << endl;
    fibonacciOn(10);

    // Also how fuction in memory??

    /*
                Higher Memory
            +---------------------------+
            |         Stack             | ← Function calls, local variables
            +---------------------------+
            |           Heap            | ← Dynamic memory (new, malloc)
            +---------------------------+
            |   Global / Static Area    | ← Global & static variables
            +---------------------------+
            |    Code (Text Segment)    | ← Functions & instructions
            +---------------------------+
            Lower Memory

    */

    // mainly call stack use..when we call the function..
    // store in text sagment otherwise..

    // Whats is binary number?
    // A binary number uses only two number..0 and 1..Unlike decimal number,which uses 10 number 0-9 and hexadecimal number..usinh 16 number..abcdef and 0-9.

    // binary is base 2,while decimal base 10

    // example decimal:25,binary 11001
    // Position value are power of 2
    // Bit:      1   1   0   0   1
    // Power:   16   8   4   2   1

    // binary to decimal
    // 11001

    // =1×16
    // +1×8
    // +0×4
    // +0×2
    // +1×1

    // =25

    // Decimal to binary:Method repeatedly divide by 2..and those remainder store lower value to higher value of divident..

    // 13/2=6 r=1
    // 6/2=3 r=0
    // 3/2=1 r=1
    // 1/2=0 r=1

    // so binary number 1101
    // 13₁₀ = 1101₂

    // lets create code for convert dec to binary..
    // also create code for convert binary to dec..

    cout << getDecimalNumber(11001) << endl;

    //     On your Ma
    // Since you're using macOS with Clang, the sizes are typically:
    // Type	Size
    // char	1 byte (8 bits)
    // short	2 bytes (16 bits)
    // int	4 bytes (32 bits)
    // long	8 bytes (64 bits)
    // long long	8 bytes (64 bits)

    cout << getBinaryNumber(25) << endl;

    // What is bitwise operator?
    // A bitwise operator works directly on the binary(bits) of an integers.

    // unlike arthematic operators,bitwise operators compare or manipulate each individual bit..

    cout << bitset<8>(5) << endl;
    // thats is inbuilt function for getbinaryNumebr of any integers..

    // how float number store in binary form??

    // Every operation happens on these 0s and 1s..

    // Why we need bitwise operators?
    // fast calculations
    // Memory optimization
    // compeitive programming
    // operating system..etc

    // Types of binary operators
    // There are 6 bitwise operator
    //&,|,^(XOR),~(Compliment),<<(left shift),>>(right shift)..

    // Bitwise AND(&)
    /*
        1 & 1 = 1
        1 & 0 = 0
        0 & 1 = 0
        0 & 0 = 0
    */

    int check1 = 10;
    int check2 = 12;

    // Bitwise OR(|)

    /*
        1 | 1 =1
        1 | 0 =1
        0 | 1 =1
        0 | 0 =0
    */

    // Bitwisw XOR(^)-exclusive OR
    /*
        1^1=0
        0^0=0
        1^0=1
        0^1=1
    */
    // only different bits become 1.

    // Why XOR famous for?
    // because A^A=0,A^0=A..
    // this is very useful in finding unique number..in set of pairs

    // 2 3 5 4 5 3 2 int ans = 0;
    // 2^3^5^4^5^3^2
    // Pairs cancel.
    // Result
    // 4
    // for (int el : arr)
    // {
    //     ans ^= el
    // } O(n)TC and O(1)SC

    // Bitwise Not(~)..not !(Logical operators)

    cout << "Not of 5 dec..0101 binary: " << ~5 << endl; //-6 if you add+1 then its two's compliment..

    // to get -ve of same number..~n+5, ~n=-(n+1)

    // Left shift(<<)
    // moves bits to left..

    // example: 5 in dec
    // in binary 00000101

    // cout<<(5<<1)..means 5 shift 1 bit left..

    // in binary it becomes, 00001010
    // and in dec, 10..

    // if shifted 2 bits..then
    // cout<<(5<<2)<<endl..its becomes 20..

    // SO FORMULA : x<<n, = x*2^n

    // every bit multiply by 2..

    // BITWISE right shift(>>)

    // reverse of above..
    // 20 = 00010100
    // 20>>1
    // 00001010=10

    // every bit divided by 2..
    // SO FORMULA, x>>n, x=x/2^n

    cout << "AND : " << (check1 & check2) << endl;
    cout << "OR  : " << (check1 | check2) << endl;
    cout << "XOR : " << (check1 ^ check2) << endl;
    cout << "NOT : " << (~check1) << endl;
    cout << "LEFT SHIFT : " << (check1 << 1) << endl;
    cout << "RIGHT SHIFT: " << (check1 >> 1) << endl;

    // operators precendence..
    // imp and do this in detail..

    // Operators tells the complier which operator should be evaluated first when an expression contains multiply operators

    // for example int x=2+3*4;

    /*
        | Precedence  | Operators                                                        | Associativity |
        | ----------- | ---------------------------------------------------------------- | ------------- |
        | 1 (Highest) | `()`, `[]`, `->`, `.`, `func()`                                  | Left → Right  |
        | 2           | `++`, `--` (postfix)                                             | Left → Right  |
        | 3           | `++`, `--`, `+`, `-`, `!`, `~`, `*` (dereference), `&` (address) | Right → Left  |
        | 4           | `*`, `/`, `%`                                                    | Left → Right  |
        | 5           | `+`, `-`                                                         | Left → Right  |
        | 6           | `<<`, `>>`                                                       | Left → Right  |
        | 7           | `<`, `<=`, `>`, `>=`                                             | Left → Right  |
        | 8           | `==`, `!=`                                                       | Left → Right  |
        | 9           | `&` (Bitwise AND)                                                | Left → Right  |
        | 10          | `^` (Bitwise XOR)                                                | Left → Right  |
        | 11          | `\|` (Bitwise OR)                                                | Left → Right  |
        | 12          | `&&`                                                             | Left → Right  |
        | 13          | `\|\|`                                                           | Left → Right  |
        | 14          | `?:`                                                             | Right → Left  |
        | 15          | `=`, `+=`, `-=`, `*=`, `/=`, etc.                                | Right → Left  |
        | 16 (Lowest) | `,`                                                              | Left → Right  |

    */

    /*

        ()
        ↓
        Unary (++ -- ! ~)
        ↓
        * / %
        ↓
        + -
        ↓
        << >> This is left and right bitwise(Higest precendance in bitwise)
        ↓
        < <= > >=(Comparison)
        ↓
        == !=(comparison)
        ↓
        &(Bitwise) cause C->B
        ↓
        ^
        ↓
        |
        ↓
        &&
        ↓
        ||
        ↓
        ?:(Ternary)
        ↓
        = Assignments
        ↓
        ,

    */

    // int a = 5;
    // int b = 10;
    // int x = (a++, b++);

    // Execution:

    //     a++ → a becomes 6 b++ → b becomes 11 The value of the whole expression is the value of b++ before increment, which is 10.

    //     What does the comma operator do?

    // It evaluates the left expression first, discards its result, then evaluates and returns the right expression.

    // int x = (2 + 3, 10 + 20);
    // cout << x;

    // output 30

    // Q3. Is every comma in C++ a comma operator?

    // Answer: No.

    // Most commas you write are separators (in declarations, function arguments, initializer lists, etc.). The comma operator is a specific operator used in expressions, and it evaluates its left operand, then its right operand, returning the value of the right operand.

    //     func(a, b, c);        // Function arguments
    // int arr[] = {1, 2, 3}; // Initializer list

    // int x = (1, 2, 3); x=3

    // Bracket->uniary->BODMAS->l/r bitwise->Comparsion->Bitwise->logical->ternary->Assignment->,

    // What is scope?
    // A variable's scope in the region of the program where it exists and can be used..

    // think of it like this
    // scope of varible = visibility of varible

    // there are four type of scope in c++
    // Local,Global,block,function parameter scope

    // Local scope: A variable declared inside a function is called local variable..

    /*
        void fun(){
            int a=89;
            cout<<a

        }
        int main(){
        fun()
        cout<<a //error
        }

        output:89 but cout<<a gives error. x lives only inside fun()..

        after fun() ends, 'a' destroyed..

        //same for variable define in int main(), not accessable outside the int main()..

    */

    // local: declare inside the function only..

    // Global varible: Variable declared outside every function..

    /*
        int x=50;

        void fun(){..}
        int main(){....}

        also accessable inside every function..
    */

    // Local vs global variable

    /*
        int x = 100;
        int main()
        {
            int x = 20;

            cout << x;
        }

        here local x variable hides global variable inside the fun() in which that local x define..


        for access the global variable in main()

        {
            int x = 20;

            cout << x;

            cout<<::x//this is scope resolution operator..
        }

        output: 20,100
    */

    // Block varible: Also a kind of local varibale..Any pair of braces {} create a block..

    /*
        int main()
        {
            {
                int a = 5;
                cout << a << endl;
            }

            // cout << a; ❌ Error
        }
            a is only accessable inside the first braces..

        for(int i = 0; i < 5; i++)
        {
            cout << i << endl;
        }

        cout << i; // ❌ Compilation error
        beacuse after for loop, i dies

    */

    // Fucntion parameters scope:
    /*
        void sum(int a,int b){
            cout<<a+b;
        }
            here a and b exist only inside sum only
    */

    // Lifetime:How many time it stay in memory?
    // scope: where can we use it?

    // shadowing: when global varibale hides under shadow of  local varibale is called shadowing..

    // static variable: store in static memory..not inside local memory of function..

    /*
        void fun()
        {
            static int x = 0;

            x++;

            cout << x << endl;
        }

        int main()
        {
            fun();
            fun();
            fun();
        }
        output: 1 2 3

        Unlike normal local variables, static local variables keep their value between function calls, even though their scope is still limited to the function.
    */

    // What is data modifier?
    // A data modifier changes the size,range or sign (-ve and +ve capability) of a basic datatype

    // modifier=modifies an existing data type..

    // short
    //  short int x=2;
    // ot short x=2;
    //  then using only 2 bytes(16 bits)
    //-32768 to 32767

    // long:increase the size or range(platform dependent)

    // long int x=78;
    // or long x=88; increse the size to 8bytes
    // 8 bytes on most 64-bit systems (e.g., Linux/macOS), 4 bytes on many Windows compilers

    // like storing the population

    // sometime long isnt enough,then we using the long long..(for window)

    //-9 × 10^18 - +9 × 10^18
    // this is heavily used in competitive prog..

    // signed mean: can store both positive and negetive number..

    // signed int x=-89;
    // or int x=-98;

    // int default signed..

    // Unsigned removes the ability of store -ve number..

    // unsigned int x=100
    // 0 to 2^32-1 (4294967295)

    // also we used this combination also..

    // unsigned short int a;
    // signed short int b;

    /*

        | Data Type                              | Size    | Bits | Range (Power of 2)  | Decimal Range                   |
        | -------------------------------------- | ------- | ---- | ------------------- | ------------------------------- |
        | `short`                                | 2 bytes | 16   | **-2¹⁵ to 2¹⁵ − 1** | -32,768 to 32,767               |
        | `unsigned short`                       | 2 bytes | 16   | **0 to 2¹⁶ − 1**    | 0 to 65,535                     |
        | `int`                                  | 4 bytes | 32   | **-2³¹ to 2³¹ − 1** | -2,147,483,648 to 2,147,483,647 |
        | `unsigned int`                         | 4 bytes | 32   | **0 to 2³² − 1**    | 0 to 4,294,967,295              |
        | `long` *(macOS/Linux 64-bit)*          | 8 bytes | 64   | **-2⁶³ to 2⁶³ − 1** | About ±9.22 × 10¹⁸              |
        | `unsigned long` *(macOS/Linux 64-bit)* | 8 bytes | 64   | **0 to 2⁶⁴ − 1**    | 0 to 18,446,744,073,709,551,615 |
        | `long long`                            | 8 bytes | 64   | **-2⁶³ to 2⁶³ − 1** | About ±9.22 × 10¹⁸              |
        | `unsigned long long`                   | 8 bytes | 64   | **0 to 2⁶⁴ − 1**    | 0 to 18,446,744,073,709,551,615 |


    */

    cout << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of long long : " << sizeof(long long) << endl;
    cout << "Size of short: " << sizeof(short) << endl;

    // How to find if a number is power of 2  with loop and  without loop..both
    // total 6 questions..defined above..

    // WAE to reverse an Intergers n

    cout << "reverse the digits: " << reverseInt(123456) << endl;

    // What is Array?
    // Array is the one of type of data structure..Data structure is used to store data..and data is fuel of programming..
    // theirs type of data structure..some are linear and some are hireachial..

    // In the linear..Array is one of the important topis..for building knowledge of vector,stack,queues,heaps hash table  etc..

    // And we performe effiecient operations on data structure or data..is called algorithm.

    // for storing data of student in school

    // we create student1="feg",student2="rehi"...1000

    // to many variabled,hard to process in loop,difficult to sort or search..

    // thats why we using, an array

    // syntax
    // datatype array_name[size]={...}

    // An array is collection of elements of the same data type stored in contigous(continoues) memory location..

    // An array is similiar
    // Memory

    // 1000
    // 1004
    // 1008
    // 1012
    // 1016

    // each element store after other..

    // Why do we need an array?
    // Storing 1000 os students marks..

    // for that making 1000ths of variable to store the marks..

    // using array make a single variable track all data

    // int marks[1000]={78,3,23,24,22,..};

    // An array is fixed size collection of the same type stored in contiguous memory and accessed using index..

    // declaration of array..

    // int array[4]; create a array of 4 size stored in memory..

    // also initialization
    // int marks[5] = {90, 89, 78, 99, 99};
    // or
    // int marks[] = {73, 28, 88, 89, 22, 22, 45, 55, 42}; // create array of initialized size..

    // how we access the element of array..?
    // using the index of array..we access the element of array..

    // cout<<arr[0]<<endl;//first elem of array
    // cout<<arr[1]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<arr[3]<<endl;
    // cout<<arr[4]<<endl;//5th element of array

    // index 0 to size-1

    // int size =sizeof(arr)/sizeof(arr[0]);

    // we access the outside the array size..give us warning.."index past the end of array.."

    // arr[-1].. before the beginning of the array..

    // address[i]=base address+i*sizeof(datatype)

    // arr[3]=1000+3*4=1012

    // every element invidual work as variable..so we modifiy the array element

    int marks[] = {100, 34, 9, -93, 4392, 990, 0};

    cout << "0th index of array: " << marks[0] << endl;
    cout << "1th index of array: " << marks[1] << endl;
    cout << "2th index of array: " << marks[2] << endl;
    cout << "3th index of array: " << marks[3] << endl;
    cout << "4th index of array: " << marks[4] << endl;

    // cout << "4th index of array: " << marks[5] << endl;

    // gives warning..and return -1

    // calculating the size of array

    int sizemarks = sizeof(marks) / sizeof(marks[0]);

    cout << "size of marks is: " << sizemarks << endl;

    // types of array and loop over array..

    for (int i = 0; i < sizemarks; i++)
    {
        cout << marks[i] << endl;
    }

    // also we input the elem of array..only fiexed number..
    int sizeprice = 3;

    // int price[sizeprice];
    // for (int i = 0; i < sizeprice; i++)
    // {
    //     cin >> price[i];
    // }

    // for (int i = 0; i < sizeprice; i++)
    // {
    //     cout << price[i] << " ";
    // }
    // cout << endl;

    // find the smallest and largest in array
    int maxmarks = INT_MIN;
    for (int i = 0; i < sizemarks; i++)
    {
        maxmarks = max(maxmarks, marks[i]);
    }
    cout << "higest marks in array: " << maxmarks << endl;

    // same for smallest
    int minmarks = INT_MAX;
    for (int i = 0; i < sizemarks; i++)
    {
        minmarks = min(minmarks, marks[i]);
    }
    cout << "smallest marks in array: " << minmarks << endl;

    // also when we wenna index where the higest no. store..
    int indx = 0;
    int maxmarks1 = INT_MIN;
    for (int i = 0; i < sizemarks; i++)
    {
        if (marks[i] > maxmarks1)
        {
            maxmarks1 = marks[i];
            indx = i;
        }
    }
    cout << "max marks: " << maxmarks1 << " on index: " << indx << endl;

    int indx1 = 0;
    int minmarks1 = INT_MAX;
    for (int i = 0; i < sizemarks; i++)
    {
        if (marks[i] < minmarks1)
        {
            minmarks1 = marks[i];
            indx1 = i;
        }
    }
    cout << "mix marks: " << minmarks1 << " on index: " << indx1 << endl;

    // In array, function argument passed by reference..not pass by value..
    // In almost all non-primitive passed as pass by refernces..

    //"arr_name" exiplicitly considered as pointer of address..
    // we change something in function..seems in main function..because of pass by refernce..not making the copy of that array..

    //&arr->base pointer arr[0] and if we add+4bytes then give us next value of arr..

    cout << *(marks) << endl; // gives us 0index value..

    cout << *(marks + 1) << endl; // return us the (1 index) second value..because we add 1 int=4bytes..

    // void changes(int arr[],int size){
    //     cout<<"In function\n";
    //     for(int i=0;i<size;i++){
    //         arr[i]*=2;
    //     }cout<<endl;
    // }

    // void chnage(arr,5)

    // output
    // In function
    // In main
    // 20,40,60,80,100 in actual value of array..in main() memory

    // Linear search, search a target element in array,if you found then return the index of that el..and not then return -1

    int arr1[] = {4, 2, 7, 8, 1, 5};
    int sz = 6;
    int trgt = 999;

    // calling the function

    cout << "return the index:" << targetElArr(arr1, sz, trgt) << endl;
    ;

    // Reverse the array..
    reverseArr(arr1, sz);
    cout << "reverse array: ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // WAF to calculate sum and product of all number in an array..
    // WAF to swap the max and min number of an array
    // WAF to print all the unique values in an array
    // WAF to print intersection of 2 array...

    // What is vector?
    // A vector is a dynamic array provided by c++ standered templates library..(STL)

    // including header file #include <vector>

    // sagmentation error..if we trying to use some loaction thats not exist in memory..

    // define vector<datatype> vector_name;
    // also initialization vector<int> v={12,34,53,45}
    // no need to define the size before..

    // also vector<int> vec(5);//gives us 5 zeros in vector 0 0 0 0 0
    // also vector<int> vec(5,10); 10 10 10 10 10

    // unlike an array, int arr[5]; whose size is fixed forever, a vector can grow and shrink automatically during runtime..

    // suppose we want to add 6th element in array of 5 order..its not possible..but in vector thats possible.

    // you must create another large array and copy everything manually.A vector does this automatically..

    // Internal working of vector..
    // lets craete a vector vector<int> vec;
    // in starting size and capacity of vector both are zero..

    // Size = 0
    // Capacity = 0

    // vec.push_back(10);

    // Size = 1
    // Capacity = 1

    // vec.push_back(20);

    // Size = 2
    // Capacity = 2

    // vec.push_back(30);

    // Size = 3
    // Capacity = 4

    // vec.push_back(40);

    // Size = 4
    // Capacity = 4

    // vec.push_back(50);

    // Size = 5
    // Capacity = 8

    // we add something..check if this have space to fit in..otherwise..double the size..and store all value(including previous values also..)

    // vec.size() actual element stored.
    // vec.capacity() memory allocated.

    // why we double capacity? not insert +1?
    // insertion capacity 1..it taked O(n^2)
    // and double the capacity, amortized    O(1)

    // so this makes push_back() amortized O(1)..

    // Important operations
    // if you define the size..but not value then it would take 0..means define size with values only..

    vector<int> v = {4, 2, 5, 2, 5, 7, 3, 9, 0, 1}; // same above
    // 10-size,10-capacity
    vector<int> v1(5); // 0 0 0 0 0
    // 5 and 5
    vector<int> v2(5, 10); // 10 10 10 10 10
    // 5 and 5
    vector<int> v3; // empty 0 and 0

    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);

    cout << v3.size() << endl;     // 3
    cout << v3.capacity() << endl; // 4

    cout << v3[3] << endl; // 0

    // v.push_back(val)..add at end amortized O(1)..
    // v.pop_back()..remove from last O(1)

    // access, v[3-index], v.at(3)
    // v.front() gives the first element
    // v.back() gives the last element

    // Treverse the vector
    // using index,range-based loop,iterator

    /*
        for(int i=0;i<size;i++){
            cout<<vec(i)<<" ";
        }

        for(auto el:vec){
            cout<<el<<" ";
        }

        for(auto it=v.begin();it!=v.end();it++){
            cout<<*it<<" ";
        }
    */

    // useful function..

    // v.empty() check is vector empty or not?
    // v.clear() to empty the whole vector
    // v.size() how many el stored in vector
    // v.capacity memory allocated
    // v.resize(20)//increase or decrease the size of vector
    // v.reserve(100)//increse the capacity of vector.
    // v.shrink_to_fit()

    // v.erase(v.begin()+2) remove third el,take argument memory address
    // element after that shifted left..

    // v.insert(v.begin()+1,1000) -O(n)TC
    // This all are workout beacuse of contigeous of memory..exactly like an array..

    // also storing the 2D vector
    // vector<vector<int>> mstrix={{},{},{}..};
    // matrix[2][1].. means 3rd row,2nd column

    // vector use heap memory..because vector change size in runtime..heap memory allows dynamic allocation unlike the satck,where gernally fixed size local varibale..

    // imp: All the STL container passed by value..but for pass by reference used &..
    // solving the question SINGLE NUMBER...

    // solving question with single number using bit(exlusive OR ^)

    // Maximum subarray sum..using kadane's Algo

    // What is subarray means?
    // subarray is continoues part of array..
    // theirs some starting point and some ending point

    // 0 012345
    // 1 12345
    // 2 2345
    // 3 345
    // 4 45
    // 5 5

    // no of possibility: n*(n+1)/2
    // brute force approach is calculate all sum and which max return

    // O(n^3) after optimazation n^2
    // what optimazation..not need to recalculate the all sum..just add in it..

    vector<int> subArr = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = INT_MIN;
    for (int i = 0; i < subArr.size(); i++)
    {
        int curSum = 0;
        for (int j = i; j < subArr.size(); j++)
        {
            curSum += subArr[j];
            maxSum = max(maxSum, curSum);
        }
    }
    cout << "max sum is: " << maxSum << endl;

    // Kadane's Algorithm
    // Large +ve add with small +ve = +ve number
    // large +ve add with small -ve =+ve number
    // Small +ve add with large -ve=-ve number..this will deduct the result

    // thats why if any sum<0,assign that sum=0.. so no deduction..
    maxSum = INT_MIN;
    int curSum = 0;
    for (int el : subArr)
    {
        curSum += el;
        maxSum = max(maxSum, curSum);
        if (curSum < 0)
        {
            curSum = 0;
        } // why we using here not above..beacuse all number might be -ves
    }

    cout << "max sum using kadane's : " << maxSum << endl;

    // Pair Sum: return pair in sorted array with target sum..only unique pair exist..

    vector<int> pairS = {2, 7, 11, 15};
    // brute force: check all the sum of pair..if any them equal to that..return pair
    int target = 44;

    for (int val : targetSumPair(pairS, target))
    {
        cout << val << " ";
    }
    cout << endl;

    for (int val : targetSumPair1(pairS, target))
    {
        cout << val << " ";
    }
    cout << endl;

    // O(n^2)

    // this is sorted array..using two pointer approach

    for (int val : targetSumPair1(pairS, target))
    {
        cout << val << " ";
    }
    cout << endl;
    cout << endl;
    // O(n)

    // Majority Elemenent:
    // Given an array nums of size n, return the majority element.

    // The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    // bruteForce, optimazation and moore's voting algorithm..

    // O(n^2)TC
    vector<int> mjArr = {1, 1, 1, 2, 4, 2, 2, 1, 1};

    int mjN = mjArr.size();

    for (int i = 0; i < mjN; i++)
    {
        int freq = 0;
        for (int j = 0; j < mjN; j++)
        {
            if (mjArr[i] == mjArr[j])
            {
                freq++;
            }
        }
        if (freq > mjN / 2)
        {
            cout << "Majority element is: " << mjArr[i] << endl;
            break;
        }
    } // O(n^2)

    // also some optimazation..using sorting the array..

    // O(nlogn- for sorting + n for treverse the array)

    sort(mjArr.begin(), mjArr.end());
    cout << endl;
    int freq = 1;
    int ans = mjArr[0];
    for (int i = 1; i < mjN; i++)
    {
        if (mjArr[i - 1] == mjArr[i])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = mjArr[i];
        }

        if (freq > mjN / 2)
        {
            cout << "Majority elemenet is: " << ans << endl;
        }
    }

    // now using Boyer moore's algotithms
    // if you are majority elem, the at the end you are dominating the whole array
    // also match the value then ++ and not --..and if freq=0 then put something

    /*
        class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                int n=nums.size();
                int frq=0, ans=0;
                for(int i=0;i<n;i++){
                    if(frq==0){
                        ans=nums[i];
                    }
                    if(ans==nums[i]){
                        frq++;
                    }else{
                        frq--;
                    }
                }
                return ans;

            }
        };

    */

    return 0;
}