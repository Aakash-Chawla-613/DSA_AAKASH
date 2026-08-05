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
// Bianry search code
int binarySearch(vector<int> &num, int target)
{

    int st = 0, end = num.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target < num[mid])
        {
            // 1st half
            end = mid - 1;
        }
        else if (target > num[mid])
        {
            // 2nd half
            st = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

// recusrion form of binary search

int binarySearchRecursion(vector<int> num, int target, int st, int lt)
{
    if (st <= lt)
    {
        int mid = st + (lt - st) / 2;
        if (num[mid] < target)
        {
            return binarySearchRecursion(num, target, st + 1, lt);
        }
        else if (num[mid] > target)
        {
            return binarySearchRecursion(num, target, st, mid - 1);
        }
        else
            return mid;
    }
    else
        return -1;
}

// creating a funtion, who calculate the product of whole array except itself..

vector<int> productArrEx(const vector<int> &arr)
{
    vector<int> ans(arr.size(), 1);
    vector<int> prefix(arr.size(), 1);
    vector<int> suffix(arr.size(), 1);

    // calculate the prefix aaray first
    for (int i = 1; i < arr.size(); i++)
    {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }
    // calculate the suffix array than
    for (int j = arr.size() - 2; j >= 0; j--)
    {
        suffix[j] = suffix[j + 1] * arr[j + 1];
    }
    // at the end multiply both and store value in ans array..
    for (int i = 0; i < arr.size(); i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

// also solving the same question with,woth constant space complexity..

vector<int> productArrEx1(const vector<int> &nums)
{
    vector<int> ans(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    int val = 1;
    for (int j = nums.size() - 2; j >= 0; j--)
    {
        val *= nums[j + 1];
        ans[j] *= val;
    }
    return ans;
}

// WAF to find index of target value, in rotated shorted array..

// O(logn) complexity

int rotatedIndex(const vector<int> &arr, int target)
{
    int st = 0, end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[st] <= arr[mid])
        {
            if (arr[st] <= target && target <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

// Peak index in mountain array..

int peakIndexInMountain(const vector<int> &arr)
{
    int st = 1, end = arr.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid - 1] < arr[mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// Single Element in sorted array
int singleNonDuplicate(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;
    if (arr.size() == 1)
    {
        return arr[0];
    } // this is for handling the single elememny array
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid == 0 && arr[mid] != arr[mid + 1])
            return arr[mid];
        if (mid == arr.size() - 1 && arr[mid] != arr[mid - 1])
            return arr[mid];

        if (arr[mid - 1] != arr[mid] && arr[mid + 1] != arr[mid])
            return arr[mid];

        if (mid % 2 == 0)
        {
            if (arr[mid - 1] == arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (arr[mid - 1] == arr[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

// Implementing the pow(x,n)
double pow_ak(double x, int n)
{
    // also handling some edge cases
    n = long(n);
    if (n == 0)
        return double(1);
    if (x == 1)
        return double(1);
    if (x == 0)
        return double(0);
    if (x == -1 && n % 2 == 0)
        return double(1);
    if (x == -1 && n % 2 != 0)
        return double(-1);

    if (n < 0)
    {
        x = 1 / x;
        n = -(n);
    }

    double ans = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;
}

// the best time to buy and sell the stock..

int maxProfitBuySell(vector<int> &arr)
{
    int bestBuy = arr[0], maxProfit = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > bestBuy)
        {
            maxProfit = max(maxProfit, arr[i] - bestBuy);
        }
        bestBuy = min(bestBuy, arr[i]);
    }
    return maxProfit;
}

// Max filled container
int maxContainer(vector<int> &arr)
{
    int maxAmount = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int wt = j - i;
            int ht = min(arr[i], arr[j]);
            int currFilled = wt * ht;
            maxAmount = max(maxAmount, currFilled);
        }
    }
    return maxAmount;
}

// Doing the same question with the help of O(n) TC

int maxArea(vector<int> &arr)
{
    int maxArea = 0, st = 0, end = arr.size() - 1;

    while (st < end)
    {
        int wt = end - st;
        int len = min(arr[st], arr[end]);
        maxArea = max(maxArea, wt * len);

        arr[st] < arr[end] ? st++ : end--;
    }
    return maxArea;
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

    // time and space complexity
    // what is time complexity,is not actual time taken by code..its depend on complier,server etc..It is amount of time taken as fucntion of input size(n)..

    // what is time taken..how we measure that..in terms of no of operations..

    // calculate when n high or n low..how much operation taken..its all behaviour is TC

    // plot on graph..and equaction of graph is called..

    // graph of no of n imput and  no of operations..like f(n)=n.. O(n)..Linear complexity..
    // why we calculate the TC..to keep mind in worst case senario..(to make optimized prog and compare the code..)

    // Big O notation, worst case compexity (upper bound)..

    // ignore the constant
    // take the biggest terms..

    // also lower bound..(omega)-best case..
    // also theta for avg case..
    // and Big O for worst case..

    // What is space complexity?
    // Amount of space taken by a algo or function of input size(n)..

    // theirs two type of space..first is input and other is auxiliary space(extra space)

    // let a function take..imput arr and return other square aaray..so those other square array is auxiliary space

    // input size of array (n) and create space of other array..so O(n) space complexity..

    // if calculate the sum of array el..so only O(1) only gonna to return the ans_sum

    // In the modern time, we more focous on time complexity, instead of space complexity(cheap and more in quantity)
    // where time CPU is more expensive..

    /*
        Order of Growth (Fastest → Slowest)

        O(1)
        ↓
        O(log n)-binary search
        ↓
        O(n)-linear search
        ↓
        O(n log n)->sorting
        ↓
        O(n^2)
        ↓
        O(n^3)
        ↓
        O(2^n)-recursion
        ↓
        O(n!)
    */

    // common time complexity-O(1)
    // O(n)-linear search,kadanes,moore,nth fibonnaci,Nth factorial..
    // O(n^2 or n^3)-bubble,selection,insertions sort,also patterns
    // O(logn(power of base 2,7 etc))-Binary search,BST..when seems that if full array->half array->one fourth->etc this is logn TC
    // O(nlogn)-optimized sorting algorithm, mergeSort,quicksort(avg),Greedy algorithm
    // O(2^n): expotenial TC-recusrsion bruet force code..
    // O(n!)..not so common- n queens, knights tour..all permutation

    // find TC of finding prime number?
    // O(rootn)<O(n)
    // also O(logn)<O(rootn)

    // mainly logn time complecities in binary search and binary search tree..

    // O(nlog n)->optimazation  sorting alogorithm..like mergeSort and averge case-Quick sort and also in greedy algos

    // O(2^n)-expotentional->In the recursion..in bruteForce..

    // O(n!)-> to get all permuatation in recursion form..also N Queens, Knights Tour..string all possible permuatations

    // How to recusrsion' Time complexity?
    // using recursion relation equaction..
    // TC=total no of rec calls*work done in each frame..\n making the recursion tree..

    // also the important recursion function..to calculate the space complexity..their is major big differences between the recursion space comp and normal function space complexity..
    // because when we call the recursion function..in memory created a call stack..call also counted in auxiliary space..

    // SC- height of call stack*memory in each call..

    // Three important things.to keep in mind..(recursive relation), (TC=total no of call* work done in each call.)

    // also for space complexity..(height of call stack* memory in each frame..)
    // also for (depth of rec tree*memory in each call)

    // In mergeSort, time complexity is O(n*logn) and O(n)-space compleixty

    // also some important usage of space and time complexity..like

    // Practical usage..on averge on any website complier, 1second ~ 10^8..if greater than that TLE(time limit exceeded)

    // if 10^6 than might be O(n*logn)-sorting

    // n<25 than might be recursion

    // n>10^8 than might be O(1) or O(logn).
    // or n<=12 than might be O(n!)

    // doing three type of sorting algorithms..of O(n^2)

    // bubble,selection and insertion sorting..

    // In bubble sort...adjecent comparing,if smaller put him first and bigger one in last..also..only n-1 outer loop..
    // Why n-1 loop? cause if organise the n-1 element then last one automatically on right place..
    // how we track each index using j=0 and ending with n-1-i..why this? cause we check i and i+1 el..so so loop (n-1) run
    // n-1 run...after every i=0,i=1 ..n-1 iteration..one element gonna last right place..so (n-i-1)

    vector<int> arr_sort = {4, 1, 5, 2, 3, 20, 3, 1, 34, 22, 1, -1, -445};

    int n_arr = arr_sort.size();

    for (int i = 0; i < n_arr - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n_arr - i - 1; j++)
        {
            if (arr_sort[j] > arr_sort[j + 1])
            {
                swap(arr_sort[j], arr_sort[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted == true)
        {
            break; // and return vector
        }
    }

    cout << "Using the bubble sorting: \n";
    for (int val : arr_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    // their's some optimazation..if already sorted array passed..then nothing happend to the array, not running the code..

    // What is selction sorting?
    // In which we are, pick smallest element from unordered part of array..(how we decided which part is sorted or not?)
    // we assume all array first unsorted..
    // pick 1 el of unoredere smallest and check with whole unordered array..using inner loop j=i+1 to n.. and track smallest(who first element of US ) with i=0 to n-1..cause of sorted 1 to n-1 then last one..on there right position..

    vector<int> vec1_sort = {4, 1, 5, 2, 3, 20, 3, 1, 34, 22, 1, -1, -445};
    int vec1_s = vec1_sort.size();
    for (int i = 0; i < vec1_s - 1; i++)
    {
        int smallestIdx = i; // taking first el of US as smallest..

        for (int j = i + 1; j < vec1_s; j++)
        {
            if (vec1_sort[smallestIdx] > vec1_sort[j])
            {
                smallestIdx = j;
            }
        }
        swap(vec1_sort[smallestIdx], vec1_sort[i]);
    }

    cout << "Using the selection sorting: \n";
    for (int val : vec1_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    // what is insertion sort?
    // In this, we are gonna insert a new value in sorted array..and single element is always a sorted..so we start our loop to 1 to n-1..of (n-1) loop..also this give us first index of unordered array...and we create a previous pointer(that make space for new insertion)..we assign prev=prev+1..and make space for insertion..only when curr<prev value..and (curr=prev+1)..-ve loop of prev-- until prev==0..

    // also curr not pointer, its actual value..we copied.cause after that replacement of places..

    vector<int> vec2_sort = {4, 1, 5, 2, 3, 20, 3, 1, 34, 22, 1, -1, -445};
    int vec2_s = vec2_sort.size();
    for (int i = 1; i < vec2_s; i++)
    {
        int curr = vec2_sort[i];
        int prev = i - 1;
        while (prev >= 0 && curr < vec2_sort[prev])
        {
            vec2_sort[prev + 1] = vec2_sort[prev];
            prev--;
        }
        vec2_sort[prev + 1] = curr;
    }

    cout << "Using the insertion sorting: \n";
    for (int val : vec2_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    // also doing same with decending order..
    // just change the sign of camparison..

    for (int i = 0; i < n_arr - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n_arr - i - 1; j++)
        {
            if (arr_sort[j] < arr_sort[j + 1])
            {
                swap(arr_sort[j], arr_sort[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted == true)
        {
            break; // and return vector
        }
    }

    cout << "Using the bubble sorting reverse the array: \n";
    for (int val : arr_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 0; i < vec1_s - 1; i++)
    {
        int smallestIdx = i; // taking first el of US as smallest..

        for (int j = i + 1; j < vec1_s; j++)
        {
            if (vec1_sort[smallestIdx] < vec1_sort[j])
            {
                smallestIdx = j;
            }
        }
        swap(vec1_sort[smallestIdx], vec1_sort[i]);
    }

    cout << "Using the selection sorting reverse the array: \n";
    for (int val : vec1_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 1; i < vec2_s; i++)
    {
        int curr = vec2_sort[i];
        int prev = i - 1;
        while (prev >= 0 && curr > vec2_sort[prev])
        {
            vec2_sort[prev + 1] = vec2_sort[prev];
            prev--;
        }
        vec2_sort[prev + 1] = curr;
    }

    cout << "Using the insertion sorting reverse the array: \n";
    for (int val : vec2_sort)
    {
        cout << val << " ";
    }
    cout << endl;

    // What is Binary search?
    // Binary search is optimization of linear search..it is only used in sorted array unlike unsorted array..
    // binary search is algorithm used to search for an element in a sorted array by repeateadly dividing the search into two halves..

    // intead of checking every elemrnt one by one (linear), it compares the target with middle element..

    // if target is smaller->search the second half
    // if target is bigger->search in first half..
    // if equal->element found..

    // only when st<=end? why equal sign?..cause both are st=end return a single element..

    // iteration approach and recursive approach..ONLY ON SORTED ARRAY..

    // smaller optimization=st+(end-st)/2

    cout << endl;

    for (int val : vec2_sort)
    {
        cout << val << " ";
    }
    cout << endl;
    // above we have vector of sorted

    vector<int> chk = {2, 5, 8, 10};

    cout << "using the binary search: " << binarySearch(chk, -14) << endl;

    // O(logn)-TC and O(1)-SC

    // also making the recursion form of binary search..

    cout << "using the binary search: " << binarySearchRecursion(chk, -13, 0, 4) << endl;

    // recursion based binary search, TC-O(logn) and SC-O(logn) also..recursion call store in call stack..height of call stack equal to logn..

    // What is pointer?
    // A pointer is variable that stores the momory address of another varibale,rather than storinng a value directly..

    // think of memory as hige street of numbered houses-a pointer is like piece of paper with an address written on it.and telling you where to go,rather than being the house itself..

    int val1 = 10;
    int *ptr = &val1; // ptr holds the address where x is placed in memory

    // to initialization of pointer..also give datatype of same value that you want to store address..

    // because A pointer 's types tells the complier how to interpret the memory location and how many bytes to read/write,and how much to move when you do pointer arthemetic..

    // int *ptr = &a;
    // double *ptr_d = &d1;

    // if we give some other value to other type of pointer..give us error..

    cout << &val1 << endl;
    cout << ptr << endl;
    // memory stores in form of hexadeximal  form..in which 0-9 and a-f..if in the last 0x...48-> +byte bytes adrdress not the 0x..5b cause, 0-9->than 1-f..

    cout << *(ptr + 1) << endl; // if no value store in any memory address..give us garbage value..

    // Pointer to Pointer (Double Pointer)
    //  A pointer to pointer is variable that stores the address of another pointer,instead of storing the address of a normal variable like int or char..

    // so instead of one level of indirection,you get two..

    // above we store pointer ptr->storing address of a..

    // now im storing address of pointer ptr..

    // what is type of ptr?
    // its int* , so storing its type with pointer..

    int **parPtr = &ptr;

    // Internally work as
    // Variable:   x        ptr      parPtr
    // Value:     10      0x1000     0x2000
    // Address:  0x1000   0x2000     0x3000

    // val is placed at address 0x1000, and holds the value 10
    // ptr is placed at address 0x2000, and holds the value 0x1000 (the address of x)
    // parPtr is placed at address 0x3000, and holds the value 0x2000 (the address of p)

    // also dereferncing..
    cout << *ptr << endl;     // 10
    cout << **parPtr << endl; // 10

    **parPtr = 50; // modifies x through double pointer
    cout << "x after modification = " << val1 << endl;

    /*
        void allocate(int** ptr) {
            *ptr = new int(100);
            // changes the actual pointer main()
        }

        int main() {
            int* p = nullptr;
            allocate(&p); // pass address of p
            cout << *p; // 100
            delete p;
        }

    */

    /*
        Quick Summary
        Expression	Meaning
        int x	    a value
        int* p = &x	  p holds address of x
        int** pp = &p	 pp holds address of p
        *pp	        gives you p (an address)
        **pp	    gives you x (the value)

    */

    // to showing nothind..useful in linked list..nullptr

    int *nullp = nullptr;
    // cout << *nullp << endl; // give us sagementation error 33320

    // Pointer Arithemetic?
    // Pointer arithemetic means performing maths operations(+,-,++,--) directly on pointer..but its does nt work like normal number arithemetic-its scaled by size of datatype the pointer points to.

    // The core rule
    // When you do ptr+1, the complier doent just add 1 bytes. it add 1*(sizeof(type)) bytes, moving the pointer to next element of that types in memory..

    // int* p;      p + 1   →  moves forward by sizeof(int)    (usually 4 bytes)
    // double* p;   p + 1   →  moves forward by sizeof(double)  (usually 8 bytes)
    // char* p;     p + 1   →  moves forward by sizeof(char)    (1 byte)

    // this basically use in array treversing..

    int pointerArr[6] = {1, 2, 3, 4, 5, 6};
    int *pArr = pointerArr; // p pointer to arr[0]

    // name of array points to 0 index address and continoues in memory..thats why we use ++ or decrement operator..

    cout << pArr << endl;     // 0x16db0e710
    cout << pArr + 1 << endl; // 0x16db0e714
    cout << pArr + 2 << endl; // 0x16db0e718

    // also defrencing
    cout << *pArr << endl;       // 0x16db0e710
    cout << *(pArr + 1) << endl; // 0x16db0e714
    cout << *(pArr + 2) << endl;

    // arr[i]  is literally identical to  *(arr + i)

    // Both compile to the same code. That's why 3[arr] also works in C++ (weird but true) — it's *(3 + arr).

    cout << 3 [pArr] << endl; // this gives 3 indexes -> value is 4

    cout << *(3 + pArr) << endl;

    // also array or vector pointers are constant pointer thats change or modify

    cout << pointerArr << endl; // array name
    cout << pArr << endl;       // pointer to pointerArr[0]

    // so if we wanna change the pointerArr address isnt possible..cause constant pointer..
    // and we wanna chnage the pArr, yes its possible..

    // pointerArr = &val1;//error: array type 'int[6]' is not assignable
    // cause,

    // we wanna change the value of pArr pointer..yes its possible

    pArr = &val1;
    cout << "modify the pointer to an array" << endl;
    cout << pointerArr << endl;
    cout << pArr << endl;

    pArr = pointerArr; // back to their pointerArr

    // Increment and decrement
    // int pointerArr[6] = {1, 2, 3, 4, 5, 6};
    // int *pArr = pointerArr; // p pointer to arr[0]

    cout << *pArr << endl; // 1
    pArr++;
    cout << *pArr << endl; // 2
    pArr++;
    cout << *pArr << endl; // 3
    pArr--;
    cout << *pArr << endl; // 2

    // p++ is very commonly used to walk through arrays..

    // Pointer subtraction-Distance between elements

    // Subtracting two pointer(of a same type), gives you the number of elements between them,not the bytes difference..

    int *garbagePtr;
    int *garbagePtr2 = (garbagePtr + 6);
    cout << "Diff between two pointers of same type not give bytes(differences), its actually given the how many elements: " << garbagePtr2 - garbagePtr << endl; // 6

    cout << garbagePtr - garbagePtr2 << endl; //-6(just sign change, work as normal subtraction with no of element noy bytes..)

    // Comparison Operators

    // also pointers pointing into the same array can be compared..

    double db = 988.289;
    double *db_p = &db;

    cout << db_p << endl;
    cout << garbagePtr << endl;

    // comparing of two diff datatypes is not compatiable..only same type of datatypes are comaprable..because its interpret the memory on the basis of datatype..

    // int* p1 = &arr[1];
    // int* p2 = &arr[3];

    // if (p1 < p2) cout << "p1 comes before p2 in memory";

    // What you cannot do..

    // Add two pointers together-this is meaningless and wont complile..

    // Arithemetic on void* : the complier doest know the size to scale by:

    // void* pt=&..;
    // pt++; // ERROR (or non-standard GCC extension treats it as 1 byte)

    // Go out of bounds- one past the last element(used in loop end-condition) but deferencing beyond that is undefined behaviour..

    int *pastOneLast = pointerArr + 7; // OK: one-past-the-end (valid pointer, don't dereference)
    cout << *pastOneLast << endl;      // UNDEFINED BEHAVIOR — reading garbage/invalid memory

    // this works as stopping condition in iteration loop with pointer..

    // Pitfall pointer arithemetic vs pointer different arrays..Arithmetic and comparison between pointers to different arrays/objects is undefined behavior, even if it compiles:

    // int a[5], b[5];
    // int* p1 = &a[0];
    // int* p2 = &b[0];

    // cout<<p1-p2<<endl;//gives error if both are diff arrays..

    // What is struct?
    // A struct group multiple varibles of diff types also..into a single unit..Each struct instance occupies a contigeous block of memory..

    struct points
    {
        int x;    // 4
        int y;    // 4
        double z; // 8 total= 16 bytes
    };

    points pts[3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "size of points: " << sizeof(points) << endl;

    // Array of stucts: An array of structs is simply struct instance placed contigeous, back to back in memory-just like an array of int s, except each slot in the size of whole struct..

    // Address:   0x1000        0x1010        0x1016
    //        [x=1][y=2][z=3]    [x=4][y=5][z=6]   [x=7][y=8][z=9]

    // Index:      pts[0]         pts[1]         pts[2]

    // access members
    cout << pts[0].x << " ";  // 1
    cout << pts[0].y << " ";  // 2
    cout << pts[0].z << endl; // 3

    // also modifiy the member directly..
    pts[0].z = 100;
    cout << pts[0].z << endl; // 100

    // pointer to structs
    // A pointer to a struct the address where a struct instanec is placed..

    points *Ppts = pts;        // Ppts hold address of points pts..array
    cout << (*Ppts).x << endl; // access the [1][1]
    cout << (*Ppts).y << endl; //[1][2]
    cout << (*Ppts).z << endl; //[1][3]

    // next value..
    Ppts++;
    cout << (*Ppts).x << endl;
    cout << (*Ppts).y << endl;
    cout << (*Ppts).z << endl;

    // access the value with the help of pointer,we have two ways to doing the same..

    // through deferencing first, then access the member -1
    //  cout<<(*Ppts).x

    // second, using the arrow operators,doing the same thing, cleaner synatax -10

    // cout<<Ppts->x;
    //-> is just shorthand for (*ptr). — it's used constantly in C++ because dereferencing structs/objects is so common.
    Ppts = pts;
    // treverse the whole array of struct..
    for (int i = 0; i < 3; i++)
    {
        cout << "x=" << Ppts->x << " y=" << Ppts->y << " z=" << Ppts->z << endl;
        Ppts++;
    }

    // Both forms compile down to the same underlying pointer math- pts[i] is leterally (*pts).x ..

    // Array of pointer structs(Different from above)
    // This is distinct concept-instead of array holding actual struct values contigeously,it holds pointer,each pointing to struct that may be placed anywhere in memory(often on the heap)

    //     Point* pts[3];          // array of 3 pointers to Point

    // pts[0] = new Point{1, 2};
    // pts[1] = new Point{3, 4};
    // pts[2] = new Point{5, 6};

    // cout << pts[0]->x;    // 1
    // cout << pts[1]->y;    // 4

    // // cleanup
    // for (int i = 0; i < 3; i++) delete pts[i];

    /*
        Array of Structs:          Array of Pointers to Structs:

        pts[0]: [x=1][y=2]         pts[0]: 0x3000 ─────► [x=1][y=2]  (heap, elsewhere)
        pts[1]: [x=3][y=4]         pts[1]: 0x5000 ─────► [x=3][y=4]  (heap, elsewhere)
        pts[2]: [x=5][y=6]         pts[2]: 0x7000 ─────► [x=5][y=6]  (heap, elsewhere)
        (all contiguous, 8B apart) (pointers contiguous, targets scattered)

                                   Array of Structs	        Array of Pointers to Structs
            Memory layout	      All structs contiguous	Only the pointers are contiguous; actual structs can be scattered

            Cache performance	  Better (sequential access)	Worse (pointer chasing, cache misses)

            Size per element	 sizeof(Point)	     sizeof(Point*) (4 or 8 bytes always)

            Use case	         Fixed-size, performance-critical data	           Polymorphism, large structs, or when  elements are created/destroyed independently


    */

    // if we struct char and int..then size not be 5 bytes..it will wb 8 bytes..cause of padding

    // A Note on Struct Padding (Why sizeof(Point) Might Not Be 8)

    // Compilers often add padding for alignment, so pointer arithmetic scales by the actual compiler-determined size, not just the sum of member sizes:

    /*
        struct Mixed {
        char c;    // 1 byte
        int x;     // 4 bytes
    };
    // sizeof(Mixed) is often 8, not 5, due to padding for alignment
    cpp
    Mixed arr[2];
    Mixed* p = arr;
    p++;   // moves forward by sizeof(Mixed) = 8 bytes (compiler-dependent), not
    */

    // all we done for one thing..
    // Pointer arithmetic with array of structs:The scalling rule matters even more with larger types:

    // p++ moves forward by sizeof(points)=8 not by 1..

    // Pass by value,References,Pointer

    // Pass by value: A copy of the argument is made and passed to the funtion..The function work on this copy-the original variable is completely untouched..
    /*
        void modify(int x)
        {
            x = 100; // modifies the local copy only
        }

        int main()
        {
            int a = 10;
            modify(a);
            cout << a; // 10 — unchanged!
        }

            main():  a = 10   (address 0x1000)
            modify(): x = 10   (address 0x2000, a NEW copy)
            x = 100  (only this copy changes)
            main():  a is still 10
    */

    // Safe (original data can't be accidentally changed)

    // But wasteful for large objects (structs, classes, containers) — the entire object gets copied every call

    // Pass by reference
    // Instead of copying, the function parameters becomes an alias for the original variable-no copy is made and change inside the function direclty affect the original..

    // function make alias int &s that store the address of that variable with changing name..so those modification occure in function gonna refelect in main function also..

    /*
        void modify(int& x) {
        x = 100;   // modifies the ORIGINAL variable
    }

    int main() {
        int a = 10;
        modify(a);
        cout << a;   // 100 — changed!
    }


    main():  a = 10  (address 0x1000)
    modify(): x is just another NAME for 0x1000 — no new memory allocated
            x = 100  → directly writes to 0x1000
    main():  a is now 100


    No copying — efficient, even for large objects
    Function can modify the caller's variable
    Syntax stays clean — used just like a normal variable (x, not *x)

    */

    // If you want to the effiecieny of no copy,but dont want the function to modify the original,use "const&"

    // void display(const bigData& data){
    //     //data[0]=4 ERROR cant modify ,protect by const
    //     cout<<data[0]<<endl;
    // }

    // What is const? means constant..it tells the complier "this value cannot be changed."

    // const a variable
    //  const int x=10;
    //  x++;//give us error

    // Why we use const?
    // Prevent accidental modification.
    // Make code easier to understand
    // help the complier optimize in some cases..

    // const with variable
    // const with fucntion parameters: void print(const vector<int>& nums)
    // this prevent from coping whole data and dont allow to modification..

    // const with binary search, beacuse its only read, not any modifications

    // const with pointer: const int *ptr = &x; ptr can move but *ptr cannot change the value..(no modification)

    // constain pointer, int* const ptr=&a; Pointer cannot move but change the value..

    // constant pointer to constant.. const int* const ptr=array; cant move and cant modifications..

    // Pass by pointer
    // You pass the address of the variable.The funtion receieve a poimter and must exiplicily deferenced it to access and modify the original value..

    /*
        void modify(int* x) {
            *x = 100;   // dereference to modify the original
        }

        int main() {
            int a = 10;
            modify(&a);   // must pass address explicitly
            cout << a;    // 100 — changed!
        }
            main():  a = 1(address 0x1000)
            modify(): x = 0x1000   (x is a NEW variable, but it STORES a's address)
            *x = 100     → goes to 0x1000 and writes 100 there
            main():  a is now 100
    */
    // Can modify the original like refernce
    // can be nullptr-allows an optional argument(refernces can never be null)
    // Needs expicitly & at call site and * inside the funtion-more verbose,more error-prone
    // supports pointer arithemactic

    // Product of Array except self..
    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]

    /*
        Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    */

    // You must write an algorithm that runs in O(n) time and without using the division operation.

    // with the division solving this with O(n)..but we gonna the optimalization approach of O(n)TC and O(1)SC

    // starting with bruteForce approach

    // O(n^2)TC and O(1)SC

    vector<int> productArray = {1, 2, 3, 4};
    vector<int> ans_product(productArray.size());
    for (int i = 0; i < productArray.size(); i++)
    {
        int val = 1;
        for (int j = 0; j < productArray.size(); j++)
        {
            if (j != i)
            {
                val *= productArray[j];
            }
            ans_product[i] = val;
        }
    }

    for (int val : ans_product)
    {
        cout << val << " ";
    }
    cout << endl;

    // now solving the same with O(n) TC and O(n)SC..we count space complexity without ans vector..cause we gonna return a vector..

    vector<int> ansPreSuf = productArrEx(productArray);
    for (int val : ansPreSuf)
    {
        cout << val << " ";
    }
    cout << endl;
    vector<int> ansPreSuf1 = productArrEx1(productArray);

    for (int val : ansPreSuf1)
    {
        cout << val << " ";
    }
    cout << endl;

    // Solving quuestion based on Binary serach..

    // 33. Search in rotated short Array..

    // This is an integers array nums sorted in ascending order(with distinct value)

    // Prior to being passed to your function,nums is possibily left roated at unknow index..k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

    // Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    // You must write an algorithm with O(log n) runtime complexity.

    // Input: nums=[4,5,6,7,0,1,2]
    // target = 0
    // Output: 4

    // In this, firstly we find which array part are sorted..those area sorted, where we apply the binary search condition..
    // In binary search, important thing to find searching space..and split into two..until both value are equal..

    vector<int> rotated_Array = {4, 5, 6, 7, 0, 1, 2};
    cout << "Target 0  found at: " << rotatedIndex(rotated_Array, 7) << endl;

    // Peak Index problem
    // firstly we know that, no solution on last and first index of array..because on anyone have answer,than no mountain arrau formed..

    // also one line is increasing and other is decreasind..also of mid found on inc line->search for greater then mid(peak always on greater of inc line)..and if on decreasing side..the always end=mid-1..because peak lies bac side of decreasing..peak lines..

    vector<int> mountainArray = {3, 5, 3, 2, 0};
    cout << "peak point in mountain array is: " << peakIndexInMountain(mountainArray) << endl; // 1

    // 540 single element in a sorted array..

    // you are given a sorted array consisting of only intergers where every element appears exactly twice, except for one element which appears exactly once..

    // return the single element that appears only once..

    // your solution must run in O(logn) time and O(1) spaces..

    // Input: nums = [1,1,2,3,3,4,4,8,8]
    // Output: 2

    // asking for O(logn) and sorted array..so using the binary search..

    // solving this problem, with the help of knowing how many size of array..Always odd size..(cause pair of el +1 single element)

    // if mid%2==0 then both side are evenly distributed both side..

    // and if (mid%2 !=0) then both side are odd numbered distributed..

    // check search space..If In evem both side..arr[mid-1]=arr[mid]..then single number found in left..cause all are in even form..if one matched to mid..then one is exactly single element..else if not match then right..

    // if both side are odd numebr..and arr[mid-1]=arr[mid] then found in right side..cause odd in number and one match..other left onlt pairs..so founded in right part..reverse of above point..

    // also handling the edges cases.if size of array only 1..or mid=0 or mid=last element..cause mid+1 and mid-1 dont work..size==0 handle above while loop..other are in while-loop..

    vector<int> singleElSrch = {1, 2, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single element in sorted array is: " << singleNonDuplicate(singleElSrch) << endl;

    // Also solving the pow(N,x)-power Exponential and buy and sell stock problem..

    // pow(N,x):-Implement pow(n,x) which calculate x raised to power n(i.e x^n)

    // -100.0 < x < 100.0
    // -231 <= n <= 231-1
    // n is an integer.
    // Either x is not zero or n > 0.
    // -104 <= xn <= 104

    cout << "Calculate the pow- Power exponential: " << pow_ak(-1.233, 3) << endl;
    // what is time complexity: its O(logn+1)..why logn+1..beacuse dec(n)= In binary form,Number of digits = (logn)+1..so our loop run upto logn complexity..and SC-O(1)

    // Best time to buy and sell stock..

    // You are given an array prices where prices[i] is the price of a given stock on the ith day.

    // You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    // Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    // Input: prices = [7,1,5,3,6,4]
    // Output: 5

    // doing this with O(n) TC, firstly we consider each day as selling and calculate the max profit..when we have min(smallest value) in previous days..also consider two two value..min(value) and updating with array..and maxprofit with array..

    vector<int> stocksPrice = {7, 6, 4, 3, 1};

    cout << "The best to buy and sell the stock: " << maxProfitBuySell(stocksPrice) << endl;

    // Container with most water

    // You are given an interger array height of length n..there are n vertical lines drawn such that the two endpoints of the ith line are (i,0) and (i,height[i])

    // find two lines that together with a axis from a container,such that the container contains the most water..

    // return the maximum amount of water a container con store..

    // notice that you may not slant the container.

    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49

    // doing this with brute force and optimal approach..
    // O(n^2)
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max filled water: " << maxContainer(height) << endl;

    cout << "Max filled water using O(n): " << maxArea(height) << endl;

    // Book Allocation problem

    // There are N books, each ith book has A[i] numbers of pages

    // You have to allocate books to M number of student so that the maximum number of pages allocated to student is minimum

    // Each book should be allocated to a student
    // Each student has to allocated at least one book
    // Allotment should be in contigoues order..

    // Calculate and return that mimimum possible number and return -1 if a valid assignment is not possible..

    return 0;
}