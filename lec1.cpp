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
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <array>
#include <forward_list>
#include <utility>
#include <tuple>
#include <queue>
#include <map>

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
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
            return 0;
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

// Solving the book allocation problem

bool isValid(vector<int> &arr, int stu, int maxMinPages)
{
    // to arrange student in continoues in that way..every student pages doesnt cross the maxMinPages numeber..if gonning, then increase student count..in end check if student..count equal to given count of student in question then return true otherwise false..

    int st = 1, pages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxMinPages)
            return false;

        if (pages + arr[i] <= maxMinPages)
        {
            pages += arr[i];
        }
        else
        {
            st++;
            pages = arr[i];
        }
    }

    return st <= stu;
    // st from the greedy loop is the minimum number of groups needed to keep every pile ≤ maxMinPages. If st < stu, that doesn't mean the allocation is invalid — it means you can split the existing groups into more, smaller pieces to use up the remaining students, and this will never violate the maxMinPages limit.
}

int maxBookAllocation(vector<int> &arr, int stu)
{
    if (stu > (int)arr.size())
        return -1;
    int st = 0, end = 0, minValidPages = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        end += arr[i];
    }

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, stu, mid))
        {
            minValidPages = min(minValidPages, mid);
            end = mid - 1; // left side if true
        }
        else
        {
            st = mid + 1;
        }
    }
    return minValidPages;
}

// Painter's parition problem

bool isValid1(vector<int> &arr, int minTime, int actaulN)
{
    int n = 1, time = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > minTime)
            return false;
        if (arr[i] + time <= minTime)
        {
            time += arr[i];
        }
        else
        {
            n++;
            time = arr[i];
        }
    }
    return (n <= actaulN);
}

int painterParition(vector<int> &arr, int pntr)
{
    if (pntr > (int)arr.size())
        return -1;

    int st = 0, sum = 0, minTime = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    while (st <= sum)
    {
        int mid = st + (sum - st) / 2;
        if (isValid1(arr, mid, pntr))
        {
            minTime = min(minTime, mid);
            sum = mid - 1; // left
        }
        else
        {
            st = mid + 1; // right if invalid
        }
    }
    return minTime;
}

// Agressive cows problem
// Assign C cows to N stalls such that min distance between them is largest possible.return largest minimum distance..

bool isPalindromeString(string &s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

// WAF to check a valid palindrome

bool isValid(char c)
{
    if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9')
        return true;
    else
        return false;
}

bool isValidPalindrome(string s)
{
    // handling the edge case
    if (s.empty())
        return true;
    int st = 0, end = s.size() - 1;
    while (st < end)
    {
        if (!isValid(s[st]))
        {
            st++;
        }
        else if (!isValid(s[end]))
        {
            end--;
        }
        else
        {
            if (tolower(s[st]) != tolower(s[end]))
                return false;
            st++, end--;
        }
    }
    return true;
}

// Remove All Occurrences of a Substring

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

string removeOccurrences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s = s.erase(s.find(part), part.size());
    }
    return s;
}

// Permutation in string problem

bool checkInslusion(string s1, string s2)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++)
    {
        vector<int> freq1(26, 0);
        int windowIdx = 0, idx = i;

        while (windowIdx < windowSize && idx < s2.length())
        {
            freq1[s2[idx] - 'a']++;
            idx++, windowIdx++;
        }
        if (freq == freq1)
            return true;
    }
    return false;
}

// also with other method doing the same

bool checkInslusion1(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    for (int i = 0; i < s1.size(); i++)
    {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2)
        return true;

    for (int i = s1.size(); i < s2.size(); i++)
    {
        freq2[s2[i] - 'a']++;
        freq2[s2[i - s1.size()] - 'a']--;

        if (freq1 == freq2)
            return true;
    }
    return false;
}

// solving the problem in the basis of mergeSort..using the backtracking and recursion...this is using the O(nlogn)

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int j = mid + 1, i = st;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left side
        mergeSort(arr, mid + 1, end); // right side
        merge(arr, st, mid, end);     // sorted array and merge
    }
}

// Sorting 0s,1s,2s
void sortColor(vector<int> &arr)
{
    // brute force approach
    sort(arr.begin(), arr.end());
}

// this is optimized with the O(n) with passes the array twice..
void sortColor1(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int val : arr)
    {
        if (val == 0)
            count0++;
        else if (val == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (0 < count0)
        {
            arr[i] = 0;
            count0--;
        }
        else if (0 < count1)
        {
            arr[i] = 1;
            count1--;
        }
        else
        {
            arr[i] = 2;
        }
    }
}

// so the optimal approach is O(n) with single passes the array..
void sortColor2(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++, mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// count the prime number upto to N.

int countPrime(int n)
{
    vector<bool> isPrime(n, true);
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
            count++;
        }
    }
    return count;
}

// Is number a armstrong or not?
bool isArmstrong(int n)
{
    int n_copy = n, ans = 0;
    while (n != 0)
    {
        int digts = n % 10;
        ans += pow(digts, 3);
        n /= 10;
    }
    return n_copy == ans;
}
// calculate the GCD

// with the brute force approach
int gcdBF(int a, int b)
{
    int ans = 1;
    for (int i = 1; i < min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }
    return ans;
} // O(min(a,b))

int gcd(int n1, int n2)
{
    // using recursion we can solve this..
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    if (n1 == n2)
        return n1;

    if (n1 > n2)
    {
        return gcd(n1 % n2, n2);
    }
    else
    {
        return gcd(n1, n2 % n1);
    }
} // O(log(min(a, b))) time, O(log(min(a, b))) space.

// also using the while loop..
int gcdWithWhileLoop(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    if (a == 0)
        return b;
    else
        return a;
} // O(log(min(a, b))) time, O(1) space.

// finding the target using the linear search over 2D Array
bool linearSearch(int mat[][5], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == target)
                return true;
        }
    }
    return false;
}

pair<int, int> linearSearchPair(int mat[][5], int rows, int cols, int target)
{
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == target)
            {
                ans.first = i;
                ans.second = j;
                return ans;
            }
        }
    }
    return ans;
}

// WAF to calculate the Maximum rows sum
int MaximumRowSum(int arr[][5], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += arr[i][j];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}

// Same for Columns sum
int MaximumColSum(int arr[][5], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < cols; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < rows; j++)
        {
            rowSum += arr[j][i];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}

// for calculating the Diagonal sum= PD + SD

int calDiagonalSum(int mat_Dia[][4], int n)
{
    int ansDiaSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ansDiaSum += mat_Dia[i][j];
            }
            else if (j == n - 1 - i)
            {
                ansDiaSum += mat_Dia[i][j];
            }
            // also that ignore the doubled calculated the mid element that comes twice..
            // so ignore that in odd square matrix..
        }
    }
    return ansDiaSum;
} // it take O(m*n)

// all this calculation work for both even and odd matrix..

int calDiagonalSum_N(int mat_Dia[][3], int n)
{
    int ansSum = 0;
    for (int i = 0; i < n; i++)
    {
        ansSum += mat_Dia[i][i];
        if (i != n - 1 - i)
        {
            ansSum += mat_Dia[i][n - 1 - i];
        }
    }
    return ansSum;
}

// Calculate the Max Row sum for vector
int maxRowSumvector(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int currSum = 0;
        for (int j = 0; j < mat[j].size(); j++)
        {
            currSum += mat[i][j];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Search in 2D vector-using the O(log(m*n))

bool searchInCol(vector<vector<int>> &m, int srow, int target)
{
    int cst = 0, cend = m[0].size() - 1; // cause same size
    while (cst <= cend)
    {
        int cmid = cst + (cend - cst) / 2;
        if (m[srow][cmid] == target)
        {
            return true;
        }
        else if (m[srow][cmid] < target)
        {
            cst = cmid + 1;
        }
        else
        {
            cend = cmid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &m, int target)
{
    int rst = 0, rend = m.size() - 1;
    int cst = 0, cend = m[0].size() - 1; // cause same col size of all rows..

    while (rst <= rend)
    {
        int rmid = rst + (rend - rst) / 2;
        if (m[rmid][cst] <= target && target <= m[rmid][cend])
        {
            return searchInCol(m, rmid, target);
        }
        else if (m[rmid][cst] > target)
        {
            rend = rmid - 1;
        }
        else if (m[rmid][cend] < target)
        {
            rst = rmid + 1;
        }
    }
    return false;
}

// Search in 2D matric..question part 2
bool searchMatrix2(vector<vector<int>> &m, int target)
{

    int i = 0, j = m[0].size() - 1;
    while (i < m.size() && j >= 0)
    {
        if (m[i][j] == target)
        {
            return true;
        }
        else if (m[i][j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

// WAF to calculate the 2 Sum problem
vector<int> twoSumBF(vector<int> &arr, int target)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// using better approch solving the same..O(nlogn) TC

vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size() - 1;
    // first sort array, with indexes...
    vector<pair<int, int>> v_p;
    for (int i = 0; i <= n; i++)
    {
        v_p.emplace_back(nums[i], i);
    };

    sort(v_p.begin(), v_p.end());

    int st = 0, end = n;
    while (st < end) // cause not two element twice sumup..
    {
        if (v_p[st].first + v_p[end].first == target)
        {
            ans.push_back(v_p[st].second);
            ans.push_back(v_p[end].second);
            return ans;
        }
        else if (v_p[st].first + v_p[end].first < target)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return ans;
} // this is standered way to do this..

// using the hashing doing the same..
vector<int> twoSum3(vector<int> &arr, int target)
{
    vector<int> ans;
    int n = arr.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int first = arr[i];
        int second = target - first;
        if (m.find(second) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[arr[i]] = i;
    }
    return ans;
}

// Find the missing and repeated values in grid
vector<int> findRepeatingAndMissing(vector<vector<int>> &m)
{
    unordered_set<int> us;
    vector<int> ans;
    int n = m.size();
    int a, b, actualSum = 0;
    int expectedSum = (n * n) * (n * n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (us.find(m[i][j]) != us.end())
            {
                a = m[i][j];
                ans.push_back(a);
            }
            else
            {
                us.insert(m[i][j]);
            }
            actualSum += m[i][j];
        }
    }
    b = expectedSum - actualSum + a;
    ans.push_back(b);
    return ans;
}
// Find duplicate value in array of 1 to n+1..and range between [1,n]..
// using unordered_set..O(n) TC and O(n) SC
int findDuplicate(vector<int> &nums)
{
    unordered_set<int> us;
    for (int i = 0; i < nums.size(); i++)
    {
        if (us.find(nums[i]) != us.end())
        {
            return nums[i];
        }
        else
        {
            us.insert(nums[i]);
        }
    }
    return -1;
}

// using the concept of linked list..Solvig the problem with slow and fast method..

// In this we are goig to intitiated with starting pointer..both slow and fast pointer..ans slow take one step and fast takes two step..until both gonnp meet a point..using while(slow!=fast)..
// after that... we reassigne the slow to arr[0]..the now start take slow+1 and fast also +1...until gonna meet at point..when both met a point..thats points is the joint point..(means comes again in thed array..)

// it takes O(n)-TC and O(1)-SC..

int findDuplicate_LL(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];      //+1
        fast = arr[arr[fast]]; //+2
    } while (slow != fast);

    // then again start slow from arr[0]
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow]; //+1
        fast = arr[fast]; //+1
    }
    return slow;
}

// spiral Matrix
vector<int> spiralmatrix(vector<vector<int>> &m)
{
    int rst = 0, rend = m.size() - 1;
    int cst = 0, cend = m[0].size() - 1;
    vector<int> ans;

    while (rst <= rend && cst <= cend)
    {
        // top
        for (int j = cst; j <= cend; j++)
        {
            ans.push_back(m[rst][j]);
        }
        // right
        for (int i = rst + 1; i <= rend; i++)
        {
            ans.push_back(m[i][cend]);
        }
        // bottom
        for (int j = cend - 1; j >= cst; j--)
        {
            if (rst == rend)
                break;
            ans.push_back(m[rend][j]);
        }
        // left
        for (int i = rend - 1; i >= rst + 1; i--)
        {
            if (cst == cend)
                break;
            ans.push_back(m[i][cst]);
        }
        rst++, cst++, rend--, cend--;
    }
    return ans;
}

// Solve the 3SUM problem using the bruteForce approach
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> uniqueSolution; // why we dont use unoredered_set..? cause In this we dont want to create custome hash table..

    // BF approach first
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> ans = {nums[i], nums[j], nums[k]};
                    sort(ans.begin(), ans.end());
                    uniqueSolution.insert(ans);
                }
            }
        }
    }
    return vector<vector<int>>(uniqueSolution.begin(), uniqueSolution.end());
} // TC-O(n^3 * logn)..here logn is TC of insertion in set.. and space complexicity is O(unique solutions)

// optimal approach to doing the same..

vector<vector<int>> threeSum1(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueSolution;

    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (s.find(third) != s.end())
            {
                vector<int> ans = {nums[i], nums[j], third};
                sort(ans.begin(), ans.end());
                uniqueSolution.insert(ans);
            }
            s.insert(nums[j]);
        }
    }
    return vector<vector<int>>(uniqueSolution.begin(), uniqueSolution.end());
}

// solve the optimized approach ever..
vector<vector<int>> threeSum2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;

        int st = i + 1, end = n - 1;
        while (st < end)
        {
            int sum = nums[i] + nums[st] + nums[end];

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[st], nums[end]});
                st++;
                end--;
                // skip duplicates for st
                while (st < end && nums[st] == nums[st - 1])
                    st++;
                // skip duplicates for end
                while (st < end && nums[end] == nums[end + 1])
                    end--;
            }
            else if (sum < 0)
            {
                st++;
            }
            else
            {
                end--;
            }
        }
    }
    return ans;
} // TC O(n^2 + nlogn) and O(1)SC

// Solving the same logic for 4Sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;
            int p = j + 1, q = n - 1;
            while (p < q)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;
                    // here the two conditions
                    while (p < q && nums[p - 1] == nums[p])
                        p++;
                    while (p < q && nums[q + 1] == nums[q])
                        q--;
                }
                else if (sum < target)
                {
                    p++;
                }
                else
                {
                    q--;
                }
            }
        }
    }
    return ans;
}

// Time: O(n³)
// Space: O(1) extra (excluding output/sort)

// create a struct for hashpair

struct hashPair
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

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

    // and how getline work..those in keyboard buffer..read evrything until(\n-> enter)

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

    vector<int> maxMinPages = {5, 17, 100, 11};
    int student = 4;

    cout << "Minimum of max pages allowed to a student: " << maxBookAllocation(maxMinPages, student) << endl;

    // Painter's parition problem
    // Given are N boards of length of each given in the form of array..and M painter,such that each panter takes 1 unit of time to 1 unit of the board..
    // The task is to find the minimum time to paint all the boards under the constranits that array will only paint continoues of board..

    vector<int> maxMinPaint = {5, 17, 100, 11};
    ;
    int pntr = 4;

    cout << "Minimum of max time takeby a painters: " << painterParition(maxMinPaint, pntr) << endl;

    // Agressive cows problem
    // Assign C cows to N stalls such that min distance between them is largest possible.return largest minimum distance

    // What is string?

    // String is a class in c++ standered library(<string> header file) that manages a dynamically-sized sequence of character..Unlike c- style string(char arr[]),it handles memory management automatically..

    // for that including the #include<string> header file..

    // declare and initialization..
    // string s1 = "hello";
    // string s2("world");
    // string s3(5, 'x'); //"xxxxx"-5 copies of 'x'
    // string s4 = s1 + " " + s2;

    // Core operations

    // Access
    string s1 = "Hey buddy!!, Akash this side..";
    cout << s1[0] << endl;      // give us 'H'
    cout << s1.at(0) << endl;   // gives us 'b'
    cout << s1.size() << endl;  // gives us length od string
    cout << s1.front() << endl; // first element of string
    cout << s1.back() << endl;  // gives us index el of string
    cout << s1.empty() << endl; // check is empty or not string?

    // Modifications
    s1.push_back('!');          // at the end add '!' and only single char..
    s1.pop_back();              // remove single el from back..only single char
    s1.append(" ,How're you?"); // add string at the end..
    s1 += "?";                  // doing same append with concatenation method

    // s1.insert(idx," all good?")//insert something after that index..

    // s1.erase(startingIdx, no_of_terms) // if you wanna erase the word or el from string..

    // s1.replace(starting, noofstring, "check") // replace from index to count..with some specific word..

    // s1.clear();//empty whole strng

    // Substring and searching

    // s1.substr(6) // from index 6 to end
    // s1.sunstr(0,5)//from 0 to 5 index..

    // s1.find("world")//index where we found
    // s1.find("xyz")//string::npos if not found
    // s1.rfind("o")//finding from last occurrence
    // s1.find_first_of("aeiou")//index of first vowel//

    // critical gotcha:  string::npos is special type of constant(usally -1 or huge unsigned number)

    // what is C-string vs string?

    // Character Arrays(also know as cstring)
    //  char str[]={'a','b','c','\0'}..also \0 is null character also same 1bytes to store in memory, also \n-next line also take 1bytes to store in memory..

    char str[] = {'a', 'a', 'k', 'a', 's', 'h', '\0'};
    cout << "cString: " << str << endl;

    // always using null character in the cstring..

    // also assign

    char str1[] = "hello babyy";
    cout << str1 << endl;

    // Character Arrays as input and output..
    // character array is type of array and string is type of vector..dynamic in nature and cstring is static in nature...

    // getline in cstring
    // char nameString[15];
    // cout << "could you pls tell me your name: ";
    // cin.getline(nameString, 15);
    // cout << "Ohh hey!!, " << nameString << endl;

    // how many element in nameString.
    // cout << "count char in cstring: " << strlen(nameString) << endl;

    // strlen(nameofstring): its count only the char in string except \0 in the last

    // also with loop check the same..
    // int lenStr = 0;
    // for (int i = 0; nameString[i] != '\0'; i++)
    // {
    //     lenStr++;
    //} // calculate the len of cstring using loop..until \0..
    // cout << "len of nameString with loop: " << lenStr << endl;

    // cin.getline(str_name,len)--this assign length to string for char(except \0) is len-1..

    // treverse the whole loop:for each and iterations

    // for (int i = 0; nameString[i] != '\0'; i++)
    // {
    //     cout << nameString[i] << " ";
    // } // using iterations
    // cout << endl;

    // for each loop
    // char nameString1[15] = "Aakash Chawla";
    // for (char ch : nameString1)
    // {
    //     cout << ch << " ";
    //} // treverse whole array..15 string()

    // cout << endl;

    // cout << nameString1[12] << endl;

    // char nameString2[100] = "3ihiu3g";
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << nameString2[i] << " ";
    //}

    // empty index store white space only..to fillup whole array..until null char..

    // What is stored in those remaining bytes?
    // It depends on how the array was created.

    // we we just declare the cstring then put something in this..or strcpy(str,"helloworld")-then other remaning byte have garbage values..

    // if we initialized with string literals..then all remaining becomes '\0'

    // if initialization with zero values..
    // char str[10]={};
    // or char str[10]={0}; both every. byte is zero..

    // why is \0 important?
    //  C string dont store their length instead strlen(str)..it keeps reading until it finds..'\0'

    // example: H e l l o \0 X Y Z
    // then return only 5, it ignore everything after the first '\0'

    // if we declaration only cstring and then getline some word..than getline overwrite the el..and remaining the garbage values..

    // char strCheck[50];
    // cout << "enter anythings: ";
    // cin.getline(strCheck, 50);
    // for (char val : strCheck)
    // {
    //     cout << val << " ";
    // }
    // cout << endl; // they have garbage char..

    // string is dynamical in nature..just like vector..nd cstring and array  both are static in nature..

    // cstring is constant varible..

    // nameString1="hello world!"//erroe variable must be modificated lvalue..

    // its increase size or decrese fix..cause word done in compile time..string is advanced version of cstring..a type of class we included from <string> header file...

    // also contigeous in nature..also using the comparison operators...

    string firststr = "hello dear!!";
    cout << firststr << endl;

    // also access through index value..

    // access the element
    cout << firststr[0] << endl;       // 0th index value
    cout << firststr.at(1) << endl;    // 1st index value
    cout << firststr.front() << endl;  // first value of string(0th index value)
    cout << firststr.back() << endl;   // last value of string
    cout << firststr.empty() << endl;  // check is string empty or not?
    cout << firststr.size() << endl;   // give us size of string
    cout << firststr.length() << endl; // same give size of string

    // size and length both are equal, in cstring strlen used for calculate the length of string..
    // evry function in string work until hit \0 in string..eg "hello\0 what'sup?" size and length both are 5 hello only..same for back..every funtion

    // modifications

    firststr.push_back('!'); // only single char in the last
    cout << firststr << endl;
    firststr.pop_back(); // remove single char from last
    cout << firststr << endl;
    firststr.append(", sup?"); // add string in the end..add+end
    cout << firststr << endl;
    firststr.insert(5, " aakash"); // insert some string with specifies index..
    cout << firststr << endl;
    firststr.replace(0, 5, "Helloo"); // replace some 0 to nth index value to something else..if some extra value we assign then all shifted one step right..
    cout << firststr << endl;
    firststr.erase(0, 1); // remove from 0th index to 1 element ahead..means remoce 'H'
    cout << firststr << endl;
    firststr += " chale??"; // add something in string with the help of concatenation..
    cout << firststr << endl;
    // firststr.clear(); // clear whole string
    // cout << firststr << endl;

    // substring and searching??
    cout << firststr.substr(6) << endl;    // from 6th index to end of string
    cout << firststr.substr(0, 5) << endl; // give substring from index 0 + 5 count
    cout << firststr.find("xyz") << endl;  // if not found just give us garbage value..
    cout << firststr.find("e") << endl;    // 0    // give the first occurence index..
    cout << firststr.rfind("e") << endl;   // 30  // give us the last occurence index..
    cout << endl;
    cout << firststr.find_first_of("aeiou") << endl;     // 0 return the vowels from begining
    cout << firststr.find_first_not_of("aeiou") << endl; // 1 find not vowels from begining
    cout << firststr.find_last_of("aeiou") << endl;      // 30 return first vowels or any char from last..
    cout << firststr.find_last_not_of("aeiou") << endl;  // 32

    // also very important topic, thats string::npos is spceial type of constant(usally -1 cast to size_t ie huge unsigned number)..Always compare with string::npos, never assume -1;

    // if(s.find("xyx")!=string::npos){
    // found the answer.
    //}

    // comparison also allowed in string

    string s2 = "abcd";
    string s3 = "kash";

    cout << "Is s2 lexicographic comes first? compare to s3: " << (s2 < s3) << endl;

    cout << "Is both equal: " << (s2 == s3) << endl;

    cout << "Is both not equal: " << (s2 != s3) << endl;

    cout << "Is s3 lexicographic comes first? compare to s2: " << s3.compare(s2) << endl; // 10 mean +ve number..any +ve number...

    // s1.compare to s2 means..tells that if both are equal tell 0, if s1<s2 gives us -ve no..or if s1>s2 gives any -ve umber

    // string to number conversion and vice-versa also..

    // string to number
    int strInt = stoi("123");
    long strLong = stol("7942370940943");
    double strDouble = stod("3.14");

    // number to string
    string numSt = to_string(2345);
    string num1St = to_string(3.12343);

    // Interview gotcha: stoi throw invalid_argument or out_of_range expection on bad input-always wrap in try catch if input isnt guranteed clean,or validate manually first..

    // for exceptions handling..used try and catch manually first..
    try
    {
        int numStr = stoi("abcde");
    }
    catch (const invalid_argument &e)
    {
        cout << "their error: " << e.what() << endl;
    }
    // try-catch method use to preverse our code to crash, and in this const and & is used to not modifies e and just reference not coping error..as e in memory

    // iteraing over string

    string fullname = "Aakash-chawla";

    // index-based
    for (int i = 0; i < fullname.size(); i++)
        cout << fullname[i];
    cout << endl;

    // range based(read only or modify by reference)

    for (char c : fullname)
        cout << c;
    cout << endl;

    for (char &c : fullname)
        c = toupper(c); // modifies original once..
    cout << endl;
    // iterators
    for (auto it = fullname.begin(); it != fullname.end(); it++)
    {
        cout << *it;
    }

    // reverse iteration
    cout << endl;
    for (auto it = fullname.rbegin(); it != fullname.rend(); it++)
    {
        cout << *it;
    }

    // do a question to reverse a string
    // we doing this by
    cout << endl;
    for (auto it = fullname.rbegin(); it != fullname.rend(); it++)
        cout << *it;
    cout << endl; // just for output...not actual

    // also by STL-reverse funtion
    reverse(fullname.begin(), fullname.end());
    cout << fullname << endl;
    // actual in memory reverse the whole string...

    // write a function that is a string a palindrome or not?

    string testPalindrome = "racara";
    cout << "Is palindrome or not: " << isPalindromeString(testPalindrome) << endl;

    // WAF to find valid palindrome string..

    // A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    // Given a string s, return true if it is a palindrome, or false otherwise.

    cout << "Is this a valid palindrome: " << isValidPalindrome("A man, a plan, a canal: Panama") << endl;

    cout << "Is this a valid palindrome: " << isValidPalindrome("race a car") << endl;

    cout << "Is this a valid palindrome: " << isValidPalindrome(" ") << endl;

    cout << "Is this a valid palindrome: " << isValidPalindrome("") << endl;

    cout << "Is this a valid palindrome: " << isValidPalindrome("0P") << endl;

    cout << "Is this a valid palindrome: " << isValidPalindrome("ab_a") << endl;

    // doing the same with isalnum and unsigned char..

    // remove all occurance of a substring

    cout << "after removal of all occurance: " << removeOccurrences("daabcbaabcbc", "abc") << endl;

    // solving the permuatation problem of string

    // Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    // In other words, return true if one of s1's permutations is the substring of s2.

    string perStr = "ab", perStr1 = "eidbaooo";

    cout << "first string any permutation in second string: "
         << checkInslusion(perStr, perStr1) << endl;

    // also with the optimization approach of doing this..
    cout << "first string any permutation in second string using optimizated way: "
         << checkInslusion1(perStr, perStr1) << endl;

    // time complexity of this is O(s2.size()) and space complexity is O(1) just array of 26 letters..

    vector<int> forSort = {2, 13, 2, 122, 67, 23, 99, 3, 0};
    mergeSort(forSort, 0, 8);
    for (int val : forSort)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> forSort1 = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(forSort1, 0, forSort.size() - 1);
    for (int val : forSort1)
        cout << val << " ";
    cout << endl;

    /*
    Merge sort is the recursiona and backtracking based algorithm using for sorting the data..with the optimal TC is O(nlogn)..

    This is based on divide and conquer concept..

    continously dividing the array until the array el represent itself as single..means when st=end=i...thats why we while loop of st<end..when its equal break the loop...

    ..with the recursion we calling the calculating the mid and call for two parts left(mergeSort(arr,int,mid)) and right(mergeSort(arr,mid+1,end))

    and at the end..in backtracking..we call right side and after that we call merge function that..merge two array in sorted order..and pass to arr to previous call..

    how merge part to create a sorted array..

    we pass arr, with st,mid and end index..

    //our loop fucntion..arrange the value in sorted way and store in tempory array..and At the end we store value in &arr with the help of relation arr[idx+st]=temp[idx]..

    so their are total three loop
    1) where we compare the value of first and second array..with we created new temp array and store the sorted value..and also temp element i=st and j=mid+1.., condition of loop is st<=mid and j<=end

    2) and 3) above loop sorted and store one loop..completely and other one sorted but not store in temp..so while(i<=mid)..store all value and same for other..while(j<=end)..store all value in temp..

    4) At the end..store temp values in original reference array..with the relation arr[st+idx]=temp[idx]..idx strat from 0 to size of temol array..


    //here's the code of the merge sort

    //In end paramerter..store the actual last index-arr.size()-1
    void merge(vector<int> & arr, int st, int mid, int end)
    {
        vector<int> temp;
        int i = st, j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= end)
        {
            temp.push_back(arr[j]);
            j++;
        }

        for (int idx = 0; idx < temp.size(); idx++)
        {
            arr[idx + st] = temp[idx];
        }
    }

    void mergeSort(vector<int> & arr, int st, int end)
    {
        if (st < end)
        {
            int mid = st + (end - st) / 2;
            mergeSort(arr, st, mid)          // left side
                mergeSort(arr, mid + 1, end) // right side
                merge(arr, st, mid, end)     // for sorting and merge the array
        }
    }
    */

    // sorting the 0s 1s 2s..doing this with bruteForce, optimized and optimal approach..

    // leetcode:75
    // Given an array nums with n objects colored red, white, or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    // We will use the integers 0,1, and 2 to represent the color red, white, and blue, respectively.

    // Example 1:

    // Input: nums = [2,0,2,1,1,0]
    // Output: [0,0,1,1,2,2]

    vector<int> colorArr = {2, 1, 1, 0, 0, 0};
    sortColor2(colorArr);

    for (int val : colorArr)
        cout << val << " ";

    cout << endl;

    // doing this with all three way: bruteforce, optimized and optimal approach..

    // only things to remember that..we have made three pointer while using dutch national flag aggregation..
    // 0s- 0 to low-1
    // 1s-low to mid-1
    // 2s high-size()-1

    // DNF sort does it in a single pass, O(n) time, O(1) space — which is the optimal approach and exactly what interviewers are looking for on this problem.

    // The Three-Pointer Technique

    // The core idea: maintain three pointers that partition the array into four conceptual regions as you scan:

    // [ 0s ... | 1s ... | unprocessed ... | 2s ... ]
    //         low      mid            high
    // low — boundary; everything before low is confirmed 0
    // high — boundary; everything after high is confirmed 2
    // mid — current element being examined; everything between low and mid is confirmed 1
    // Elements between mid and high are still unprocessed

    // Math in DSA..

    // find the count of prime upto N..
    // Given an integer n, return the number of prime numbers that are strictly less than n.

    // Example 1:

    // Input: n = 10
    // Output: 4
    // Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    // using the Sieve of Eratosthenes..finding the count of prime

    cout << "count the number of prime upto n, using sieve of eratosthenes: " << countPrime(100) << endl;

    // solve Is a number a armstrog number or not?

    cout << "Checking Is a number a armstrong or not: " << isArmstrong(113) << endl;

    // how to calculate the GCD(greatest commong divisor)of two number..

    cout << "calculating..the gcd of 20 and 28 is: " << gcdWithWhileLoop(20, 28) << endl;

    cout << "calculating..the gcd of 20 and 28 is: " << gcdBF(20, 28) << endl;

    // how we find the LCM of any two number..
    // we now that LCM=(a*b)/gcd(a,b)

    cout << "calculating..the LCM of 20 and 28 is:" << 20 * 28 / gcdWithWhileLoop(20, 28) << endl;

    // reverse the int value
    cout << "reverse the order of the digits: " << reverseInt(123456) << endl;

    // palindrome Number
    // modulo arithematic..if the ans value overflow the long or int..then sometime we are using this..to telly our anser..In constraints mention that..ans%(10^7+9)..so our answer convert into 0 to 10^7+8...

    //(x+y)%a = x%a +y%b;
    //(x-y)%a = x%a - y%b;
    //(x*y)%a = x%a * y%b;

    //(((x%m)%m)%m)%m..n always equal to x%m cause never more then m..always m-1..so next all %m are wasted..

    // starting the STL(standered template library)..

    // What is STL?
    // STL is a collection of template-based classes and function in c++ that provide ready to use,highly optimized implementation of common data structure and algorithm.Its built around of four core compenents..

    // container,algorithms,iterators,functors/fucntion object..

    // we are using the stl, to include the STL file..

    // #include<bits/stdc++.h> standered C++ file..

    // Container: sequence container like: vector,array,deque,list,forward_list

    // sequence container are those container who stored element in linear order, and position matters..

    // vector: the most commonly used container.Contigous memory. dynamic resizing(smiliar to std::string's growth model=doubling capacity when it runs out of space..)

    /*
        vector<int> vec;
        vector<int> vec(cout,val);
        vector<int> vec(v2);
        vecor<int> vec={...};

        also various function..
        v.push_back(4);//add to end..O(1)Amortized
        v.pop_back();//remove from end...O(1)
        v[0]..direct access no bound check
        v.at(0)..bound checked access..also O(1)

        v.insert(v.begin(),9); O(n) insert at arbitiary position,shifting elements

        v.erase(v.begin()); O(n) remove from arbitiary position,shifting elements

        v.size()// O(1)
        v.capacity()//O(1)
        v.reserve(100); allocate capacity to avoid repeated reallocation..


        v.clear()//to empty whole vector
        v.empty() Check Is vector empty or not?

        //v.emplace_back()//push element in end..like push_back but it also "In place object creation"..soon in pair..

        //v.front() gives us first val of vector..
        //v.back gives us last val of vector..

        In the insert and erase..it takes O(n) Tc..and also searching in array also take O(n) cause of unsorted vector..

        random access-takes O(1)

        push/pop at end-O(1) amortized

        size vs capacity..?already done in previous notes..

        //also creating a loop using the iterators

    vector<int> v = {10, 20, 30};

    v.push_back(40);      // O(1) amortized
    v.pop_back();           // O(1) — removes last element
    v.front();               // O(1) — first element
    v.back();                 // O(1) — last element
    v[1];                      // O(1) — no bounds check
    v.at(1);                   // O(1) — bounds-checked, throws std::out_of_range
    v.size();                   // O(1)
    v.empty();                   // O(1)
    v.clear();                    // O(n) — destroys all elements, size becomes 0 (capacity often unchanged!)
    v.resize(10);                  // O(n) — grows/shrinks, new elements default-initialized
    v.reserve(100);                  // O(n) if reallocation needed — pre-allocates capacity
    v.shrink_to_fit();                 // O(n) — requests capacity reduction to match size (non-binding request)

    v.insert(v.begin() + 1, 99);        // O(n) — shifts all elements after position
    v.erase(v.begin() + 1);               // O(n) — shifts all elements after position
    v.erase(v.begin(), v.begin() + 2);      // O(n) — erase a range



    */

    vector<int> vecLoop = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vecLoop.insert(vecLoop.begin(), 0);
    vector<int>::iterator itt; // making iterator or also make reverse_iterator
    // reverse_iterator rit;

    for (itt = vecLoop.begin(); itt != vecLoop.end(); itt++)
        cout << *itt << " ";
    cout << endl;
    vecLoop.erase(vecLoop.begin(), vecLoop.begin() + 2); // remove starting two elem from vecLoop
    for (auto it = vecLoop.begin(); it != vecLoop.end(); it++)
        cout << *it << " ";
    cout << endl;

    // vecLoop.end() doesnt deference the last value of array..it point to after last element of array..n+1;

    // resize and shrink_to_fit()

    cout << "capacity of vecLoop: " << vecLoop.capacity() << endl;
    cout << "size of vecLoop: " << vecLoop.size() << endl;

    // now resize the vector
    vecLoop.resize(10); // increase the size
    cout << "size of vecLoop: " << vecLoop.size() << endl;
    for (int val : vecLoop)
        cout << val << " ";
    cout << endl;

    // decrease the size of vecLoop
    vecLoop.resize(5);
    for (int val : vecLoop)
        cout << val << " ";
    cout << endl;

    // also capacity the same
    cout << vecLoop.capacity() << endl; // 18

    // now, capacity is 18 and size is 5..so extra memory are unused..to release them we are using shrink_to_fit()

    vecLoop.shrink_to_fit();
    cout << vecLoop.capacity() << endl; // 5

    //     Q: Does shrink_to_fit() guarantee that capacity becomes equal to size?

    // Answer: No. It is a non-binding request to reduce capacity. The implementation may choose not to reduce it.

    // Also remember:
    // size()      → elements currently stored
    // capacity()  → allocated storage available
    // shrink_to_fit() → request to reduce unused capacity

    // also commoin gotch: clear() doesnt free capacity

    // lets if we create a vector of 1000 capacity then after that we clear the clear whole array..using vecLoop.clear()

    // then only size becomes zero but not the capacity becomes zero..its still same..

    // so to release memory..first way to used vecLoop.shrink_to_fit() and other is swap with temp vector..

    vecLoop.clear(); // clear all the element of array..and now size of array becomes 0..but capacity still same..

    cout << vecLoop.capacity() << endl;

    vector<int>().swap(vecLoop); // swap with empty vector..and now the size becomes 0..
    cout << vecLoop.capacity() << endl;

    // also second way to doing the same is: using vecLoop.shrink_to_fit()..request(non-binding)-most implementation honor it..

    // also an Important topic: Iterator Invalidation-A frequent bug source..

    // Any operator that reallocate (growig past capacity) invalidates all exitsing iterators/pointer/reference into the vector.Even operations that dont reallocate(like erase/insert in the middle invalidate iterators from that point onward..)

    // example:

    vecLoop = {1, 2, 3, 4, 5};
    // size is five and also capacity also 5..
    cout << endl;
    // create a iterator

    auto it_vecLoop = vecLoop.begin();
    cout << *it_vecLoop << endl; // 1
    vecLoop.push_back(6);

    cout << *it_vecLoop << endl; // 3

    // this is because of undefined behaviour if reallcation happend..

    // also if insertion and erase element ..then same happend..

    // key fanda is:
    // Reallocation happens → ALL iterators/pointers/references become invalid.

    // No reallocation → often only iterators at/after the modified position become invalid.

    /*
        // Erasing while iterating — classic mistake
        for (auto it = v.begin(); it != v.end(); it++) {
            if (*it == 3) v.erase(it);   // ⚠️ invalidates 'it' — next it++ is undefined behavior
        }

        // Correct way:
        for (auto it = v.begin(); it != v.end(); ) {
            if (*it == 3) it = v.erase(it);   // erase() returns the next valid iterator
            else it++;
        }
    */

    // When to Use vector
    // Default choice for almost every problem unless you have a specific reason to use something else
    // Best cache locality of any container (contiguous memory → fast iteration due to CPU cache prefetching)
    // Fast random access, fast insertion/removal at the back

    // Array we do it later

    // Deque-Double Ended Queue
    // Internal structure-not fully contigous!

    // This is most common misunderstood container internals wise..

    // A deque is typically as collection of fixed - size fixed memory "chunks" (sometimes called blocks or buffers) with a map/index array of pointers to chunks

    /*
        Map (array of pointers):  [ ptr0 | ptr1 | ptr2 | ptr3 ]
            Chunk 0: [ _ | _ | 1 | 2 ]
            Chunk 1: [ 3 | 4 | 5 | 6 ]
            Chunk 2: [ 7 | 8 | _ | _ ]
    */

    // this is structure is what is enables O(1) push/pop at both ends-pushing to front just needs to write into unused space in the first chunks(or allocate a new if needed), without shifting existing elements unlike vector where front insertion requires shifting everything..

    /*
        |                 | `arr[i]`                  | `arr.at(i)`           |
        | --------------- | ------------------------- | --------------------- |
        | Bounds checking | ❌ No                      | ✅ Yes                |
        | Invalid index   | Undefined behavior        | Throws `out_of_range` |
        | Speed           | Slightly faster           | Slightly slower       |
        | Common use      | Normal competitive coding | Safer/debugging code  |

    */

    // Trade-off: Because the chunks aren't contiguous with each other, deque has worse cache locality than vector for pure iteration — the CPU can't prefetch as efficiently across chunk boundaries.

    // for that #include<deque>
    // deque<int> dq = {1, 2, 4, 5, 6, 3, 5, 6};

    // for (int val : dq)
    //     cout << val << " ";
    // cout << endl;

    // dq.push_back(10); // add in the end
    // dq.push_front(0); // add in the beginning
    // dq.pop_back();    // remove from end
    // dq.pop_front();   // remove from beginning
    // dq.emplace_back();
    // dq.emplace_front()
    // dq.front();
    // dq.back();
    // dq[3];
    // dq.at(3);
    // dq.insert();
    // dq.erase();
    // dq.size();
    // // dq.clear()
    // dq.empty();

    // Core function and TC

    /*
        deque<int> dq = {2, 3, 4};

        dq.push_front(1);   // O(1) — vector CANNOT do this in O(1)
        dq.push_back(5);      // O(1)
        dq.pop_front();        // O(1)
        dq.pop_back();          // O(1)

        dq[0];                    // O(1) — random access supported, unlike list
        dq.at(0);                  // O(1), bounds-checked
        dq.front();                  // O(1)
        dq.back();                    // O(1)

        dq.insert(dq.begin()+1, 99);    // O(n) — middle insertion still shifts
        dq.erase(dq.begin()+1);           // O(n)


    */

    // Deque is also providing the random access support with the O(1) and also push or pop at front and back..same as insertion and deletion takes o(n)TC

    // DEQUE VS VECTOR

    // Push/pop back takes O(1) amortized in vector but deque takes just O(1)

    // push/pop at front takes O(n) shifting eveything but deque takes just O(1)

    // random access in the vector-O(1) with better cache locality but O(1), worse cache locality

    // memory layout: vector is fully contigeous in memory but in deque's chunked,not contigoues..

    // When to Use deque
    //  Need O(1) insertion/removal at both ends (sliding window problems, BFS-like processing where you sometimes need front access)
    //  queue and stack actually use deque as their default underlying container (you rarely instantiate a deque directly outside of these specific use cases, but it's good to know it's there under the hood)

    // also we used the size,clear,begin,end,rbegin,rend,empty,front and back in the deque..as other function..

    // so lets do some example somethings

    /*
        int main() {
            deque<int> d1;                     // empty deque
            deque<int> d2(5);                  // 5 elements, value-initialized (0)
            deque<int> d3(5, 100);             // 5 elements, each = 100
            deque<int> d4 = {1, 2, 3, 4, 5};   // initializer list
            deque<int> d5(d4);                 // copy constructor
            deque<int> d6(d4.begin(), d4.end()); // range constructor
        }
    */

    cout << endl;

    deque<int> deq = {1, 2, 3, 4, 5, 6};

    cout << "size of deque is: " << deq.size() << endl;
    cout << "Is deque is empty or not: " << deq.empty() << endl;
    cout << "what value on its front: " << deq.front() << endl;

    cout << "whats value on its back: " << deq.back() << endl;
    ;
    cout << "whats value at 1 index: " << deq[1] << endl;
    cout << "whats value at 1 index: " << deq.at(1) << endl;

    // insert/erasea at arbitary positions

    // multiple value insertion and range of deletions
    // deq.insert(deq.begin() + 1, {0, 0, 0, 0});

    // erase in range

    // deq.erase(deq.begin(),deq.begin()+3);//remove starting three element..

    // Complexity: Insert/erase in the middle is O(n) — same as vector, because elements must shift. Only front/back operations are O(1).

    // size and resize

    // dq.size();      // number of elements
    // dq.empty();     // true/false
    // dq.resize(10);         // resize, new elements = 0
    // dq.resize(10, 7);      // new elements = 7
    // dq.clear();     // remove all elements

    // IMP: deque has no .capacity() or .reserve() cause it grows by allocating new blocks not by reallocating one big buffer..

    for (auto it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "after pushing val at front\n";
    deq.push_front(0);

    for (auto it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "after pop from back\n";
    deq.pop_back();

    for (auto it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "insert value at 2 index\n";

    deq.insert(deq.begin() + 2, 3);

    for (auto it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Complexity: push_back, push_front, pop_back, pop_front — all O(1) amortized.

    // IMP: Elements are not stored in contigeous manner like vector.instead ,a deque is internally implemented as fixed sized array..(chuncks,blocks) managed through a map/index of pointer to those blocks..

    // no reallocation of the entire container when it grows(unlike vector)

    // Memory layout (conceptual):

    // vector: [1][2][3][4][5]              (one contiguous block)

    // deque:  [1][2] -> [3][4] -> [5][6]   (multiple blocks linked via a map)

    // iterators and traversal:deque supports random access iteration,so you can use +,- sorting etc..

    // using the iterators

    // for(auto it: deq.begin();it!=deq.end();it++){
    //     cout<<*it<<" ";
    // }

    // range-based iterations

    // for(int val:deq){
    //     cout<<val<<" ";
    // }cout<<endl;

    // using the access numerical access also..

    // for (int i = 0; i < deq.size(); i++)
    // {
    //     cout << deq[i] << " ";
    // }
    // cout << endl;

    // also reverse the loop with the reversal iterations
    // for (auto it = dq.rbegin(); it != dq.rend(); ++it)
    // cout << *it << " ";

    // What is diff among reference,pointer and iterators..?

    // all let you work with existing data without necessarilyy making copy, but they serve diff purposes..

    // 1) reference(&) : A reference is another name(alias) for existing variable..

    int anyVar = 10;
    int &ref_var = anyVar;

    ref_var = 100;
    cout << ref_var << endl; // 100

    // so ref and x pointing to the same variable..

    // must be initialized when declared
    // cannot normally be made to refer to another variable later
    // you use it directly-no * required
    // very commonly use in function parameters

    // pointer: A pointer is a varible that store the memory address of another varible..

    int anyVar1 = 20;

    int *ptr_var = &anyVar1;

    *(ptr_var) = 200;
    cout << anyVar1 << endl; // 200

    // ptr contain the address,while *ptr access the value at that address..

    // pointer can change what it point to..
    // first, ptr_var->anyVar1

    ptr_var = &anyVar;

    // now the ptr_var is now pointing to anyVar..previously pointing to anyVar1..

    // it can also store thr nullptr..
    //  int *ptr=nullptr;

    // 3) Iterators : An iterators is an object used to move through elements of a container,such as vector,set,map etc..

    // ˜vector<int>::iterator it;
    //  using the loop we treverse the whole container

    // think of it like a position/handle pointing to an element inside a container

    // why do we need iterators?
    // cause diff conatiners have diff internal structures..
    // so iterators provide a common way to treverse them..

    /*
        | Feature            | Reference                     | Pointer                                     | Iterator                               |
        | ------------------ | ----------------------------- | ------------------------------------------- | -------------------------------------- |
        | What is it?        | Alias/name                    | Address-holding variable                    | Container traversal object             |
        | Symbol             | `&`                           | `*`                                         | Usually `iterator` / `auto`            |
        | Stores address?    | Conceptually refers to object | Yes                                         | Internally may hold position/state     |
        | Can be `nullptr`?  | ❌                             | ✅                                           | Depends; `end()` represents no element|
        | Can change target? | ❌                             | ✅                                           | ✅ can move                            |
        | Used mainly for    | Aliasing/function parameters  | Dynamic memory, optional objects, addresses | Traversing containers                  |
        | Access value       | `ref`                         | `*ptr`                                      | `*it`                                  |


    */

    // very important: pointer vs iterators?
    // this is where interview question often come from

    // consider a example

    vector<int> pt_and_it = {10, 20, 30};
    int *ptr11 = &pt_and_it[0];
    auto it = pt_and_it.begin();

    cout << *ptr11 << endl; // 10
    cout << *it << endl;    // 10

    // both can access 10, but they are not same thing

    // if we move pointer ptr++,
    // it moves to next memory location...
    // what if container are not contigeous uin memory..if linked list..or deque etc..

    // but iterators
    // it++, moves the iterators to the next container element acc to that container's iterations rules..

    // for vector it behave like similarly because vector elements are contigoes

    /*
        REFERENCE
        "Give this variable another name."

                x
                ↑
            ref


        POINTER
        "Give me the address of this variable."

                x
                ↑
                │
            ptr


        ITERATOR
        "Give me a position in this container."

        vector:  10   20   30
                ↑
                it


    */

    // Is an iterators a pointer? Not necessarily..
    // A pointer can act as an iterator for container like vector in many context, but an iterators is more gernal abstraction for example, set<int> :: iterator is not raw pointer..

    // both use the dereferencing,but the underlying objects are diff ptr is a pointer,while it is an iterators.. *ptr and *it..

    // Iterators invalidation rules for deque in detail

    // this is one of the important trickiest part of deque cause its validation rules are diff from vector and diff from what we people assume.lets go operations by operation..

    // The core rule(memorize this): for deque: push_back() and push_front() invalidates all iteratiors, but do not invalidate references/pointers to existing elemenents(unless the deque was empty)..

    // All other insertion/erasures(anywhere except possible the very ends) invalidate everything-iteratiors,pointers,And refernces..

    // 1) push_back and push_front()

    // iterators-Invalidated(all of them-begin,end,evrything)
    // references and pointer to existing elements still valid(survive)

    deque<int> iit = {1, 2, 3, 4, 5, 6, 7};

    // lets create a iterators,pointers,references...

    auto it_iit = iit.begin() + 2; // A iterators
    int *ptr_iit = &iit[2];        // A pointer
    int &ref_iit = iit[2];         // A refernces

    cout << *it_iit << " ";  // 3
    cout << *ptr_iit << " "; // 3
    cout << ref_iit << " ";  // 3

    // now push_something in back and front of the deque and check what the behaviour of iterators,pointers,refernces..

    cout << endl;
    iit.push_back(8);
    iit.push_front(0);

    cout << *it_iit << " ";  // invalid-iterators -3
    cout << *ptr_iit << " "; // 3
    cout << ref_iit << " ";  // 3

    // why does *it_iit still print 3?
    // cause "invalidated" does not mean "immediately stops working"..it mean c++ standered no longer gurantees that using that iterators is valid..

    // still print 3, but that is not something you cam rely on..

    // or some other value,or behave unpredicatably..using an invalidated iiterators is undefined behaviour..

    // why this works..deque grows by allocating a new block and linking it in..existing elements never move in memory.but the internal "maps of blocks" structure that iterators depend on cam get reorganized, so iterators break even through the actual data doest move..
    cout << endl;
    // 2) pop_back()/pop_front()

    // Invalidates only the iterators/references/pointer to the removed element..

    // All other iterators/refernces remain valid..

    int *ptr_first = &iit[0];
    int &ref_ptr_first = iit[0];
    auto it_first = iit.begin();

    // after pop from front..same for back also..

    cout << *ptr_first << " ";    // 0
    cout << ref_ptr_first << " "; // 0
    cout << *it_first << endl;    // 0

    // after pop from front
    iit.pop_front();
    cout << *ptr_first << " ";
    cout << ref_ptr_first << " ";
    cout << *it_first << endl;

    // all given, value 0 0 0..but value should be 1 1 1

    // cout << iit[0] << endl;//1

    // 3) insertion() at an arbitary position(middle)

    // deque<int> dq = {1, 2, 3, 4, 5};

    // auto it = dq.begin() + 3;   // points to '4'
    // int* p = &dq[3];

    // dq.insert(dq.begin() + 1, 99);  // insert in the middle

    // // it and p are now BOTH invalid — even though '4' still exists!
    // // cout << *it;  // UB
    // cout << *p;   // UB

    // This is a common bug source: people assume "I inserted far away from my iterator, so it should be fine" — wrong for deque. Any middle insert can trigger reshuffling of internal blocks, so treat it as "everything is invalidated."

    // 4) erase() at an arbitrary position(middle)

    // same as insert:invalidall iterators,pointers,and refernces to every element..(not just the erased one)

    // same as above

    /*
        deque<int> dq = {1, 2, 3, 4, 5};

        auto it_last = dq.end() - 1;  // points to '5'

        dq.erase(dq.begin() + 2);      // erase '3'

        // it_last is now invalid, even though '5' wasn't touched directly
    */

    // 5) clear(): invalidtes evrything-all iterators,pointers,references..deque becomes empty

    // 6) resize(): if shrink like popping-iterators/pointers to removed elements are invalidated

    // if it grows:behave like a sequence of push_back() -all iterators invalidated,but existing references/pointer remain valid..

    /*
            Summary Table
        Operation	                Iterators	                References/Pointers
        push_back() / push_front()	Invalidated (all)	        Valid (unless deque was empty)
        pop_back() / pop_front()	Only to removed element	    Only to removed element
        insert() (middle)	        Invalidated (all)	        Invalidated (all)
        erase() (middle)	        Invalidated (all)	         Invalidated (all)
        clear()	                    Invalidated (all)	        Invalidated (all)
        resize() (grow)	            Invalidated (all)	         Valid
        resize() (shrink)	        Only to removed elements	 Only to removed elements

    */

    // Invalidate all itearators,pointers, and references- no exception,regardless of where you insert(even near an end,if its not literally beign(),end())..

    // Using deque as underlying container for adapters: deque is the default underlying container for stack and queue..

    // both stack and queue internally used deque by default..

    cout << endl;

    // Now we gonna start..
    // LIST-DLL(Doubly linked list):

    // Internal structure:evry element lives in its own heap-allocated node,containing the value plus two pointer-to previous and next node..

    // nullptr ← [prev|1|next] ⇄ [prev|2|next] ⇄ [prev|3|next] → nullptr

    // this is direct,literal implementation of doubly linked list concept -connecting back to your earlier pointer discussions,this is essentially a chain of structs,each holding a T value,plus two pointer(Node* prev,Node* next), all managed automatically by the container..

    // for that include the #include<list>

    // WHAT IT IS?

    // std::list<T> is STL's implementation of a doubly linked list- a sequence container where every element lives in its own independently heap-allocated node, and each node holds pointers to both the previous and next neighbors..its declared in <list>

    list<int> l = {1, 2, 3, 4, 5, 6};

    // Internal Node structure(conceptual)
    // Every element you insert gets warapped in a node that looks conceptually like this..

    // struct Node {
    //     T data;
    //     Node* prev;
    //     Node* next;
    // };

    // the list objects just holds pointer to the head and tail node(implementation vary,but conceptually this is the idea), plus a size counter..
    // HEAD,TAIL and SIZE COUNTER

    // This is exactly the structure you'd hand build yourself if asked to "implement a doubly linked list" in an interview..

    // Why NO contiguous memory(and what that cost you)

    // Unlike vector or deque,each node is a seprate heap allocation,scattered wherevern the allocator happen to place it..this has two major..

    // 1) NO RANDOM ACCESS- to reach the 5th element you must walk node by node from the head(or tail),since there 's no way to compute address of 5th element via simple arithemetic like you can with contiguous memory..

    // 2) Worse cache locality: CPUs are fast at reading contiguous memory because of prefetching and cache lines:jumping between scattered heap address(pointer chasing) cause many more cache misses,making iteration significantly solwer in practice than a vector..even though both are techinacally "O(n)" for fully traversal..

    // construction

    /*list<int> l1; // empty
    list<int> l2(5);// 5 elements, default-initialized (0 for int)
    list<int> l3(5, 100);// 5 elements, all set to 100
    list<int> l4 = {1, 2, 3};// initializer list
    list<int> l5(l4);// copy constructor
    list<int> l6(l4.begin(), l4.end()); // range constructor*/

    // Access

    l.front(); // O(1) first element HEAD
    l.back();  // O(1) last element TAIL

    // Random access not possible
    // l[2]; or l.at(2) ERROR

    // There's genuinely no ways to get "3rd element" without  manually walking there..

    // create a iterator and walking throw that position..O(N)

    auto it11 = l.begin();
    advance(it11, 2); // O(n)-moves iterator forward 2 steps
    cout << *it11;    // return the third element now..

    // Insertion

    l.push_back(6);     // O(1)
    l.push_front(0);    // O(1)
    l.emplace_back(6);  // O(1)
    l.emplace_front(0); // O(1)-constructs in place,avoid move/copy???

    auto it1 = l.begin();
    advance(it1, 2);
    l.insert(it1, 99);  // O(1)-insert itself,GIVEN THE ITERATOR
    l.emplace(it1, 99); // O(1) same, connstructs in place..

    // DELETION
    l.pop_front(); // O(1)
    l.pop_front(); // O(1)

    auto it2 = l.begin();
    l.erase(it2); // O(1)-given the iterator

    l.remove(3); // O(n)-romoves all value equal to 3//value==3

    l.clear(); // O(n) -removes evrything,deallocates all nodes..

    l.remove_if([](int x)
                { return x % 2 == 0; }); // O(n) — removes all matching a predicate???

    // List-specific algorithms(members,not free functions!)

    // this is crucial points:cause list doest support random-access iterators,many standered algo(like sort, for instance) cannot operate on it..directly -sort require random -access iterator for its O(nlogn) gurantee,so list provide its own member version of these operations,specifically implementation to work efficiently with only sequential/birdirectiona access..

    l.sort(); // sort the list..O(nlogn)..list's OWN sort(merge sort internally, works via pointer relinking)

    l.sort(greater<int>()); // custome comaprator support..for desc..

    l.reverse(); // O(n)-reverses the list in place(just filp the prev/next pointer throughout)

    l.unique(); // O(n) -remove consecutive duplicate(must be sorted first for full dedup)

    // l.merge(otherlist);//O(n)-merges two ALREADY SORTED list into a single sorted list..aftermath otherlist becomes empty list..!

    // Gotch with merge():it doent just "combine" the lists-it moves all nodes from argument list into the calling list, leaving the argument list empty.This is O(n) not the O(Nlogn) cause its simple merge step not the mergeSORT not fully resort-but it require both list to already be sorted beforhand..

    /*
    list<int> a = {1, 3, 5};
    list<int> b = {2, 4, 6};
    a.merge(b);
    // a = {1, 2, 3, 4, 5, 6}
    // b = {}  (now empty!)*/

    // SPLICE()-The real superpower of list

    // this is the single most important thing that makes list genuinely special comapred to very squence conatiner:splice() moves nodes between list(or within the same list) in O(1) per element, by simply relinking pointer-no copying, no moving of actual data, no reallocation

    // syntax: pushing_list.splice(pushlist_position,otherlist_name,otherlist_it);

    /*
        list<int> a = {1, 2, 3};
        list<int> b = {10, 20, 30};

        auto it = b.begin();
        advance(it, 1);              // points to 20

        a.splice(a.begin(), b, it);    // move the node at 'it' from b to the front of a — O(1)!
        // a = {20, 1, 2, 3}
        // b = {10, 30}
    */

    // Three overload of splice

    // Move an ENTIRE list to another,at given position
    // a.splice(pos,otherlist)..this is move all otherlist into callinglist

    // Move a single element(guven an iterator) from another list

    // a.splice(pos,otherlist,it);

    // Move a Range of element [first,last) from another list

    // a.splice(pos, otherList, first, last);

    // why this matter:With a vector,moving an element from middle of one collection to another requires shifting in both-O(n).With list, since element are just pointer -linked nodes, splice can literally unhook a node from one list and rehook it into another wothout touching the node's content at all-This is where list O(1) insert/erase-given an iterator claim becomes genuinely powerful in composite operations like reordering..

    // The LRU(least recent used) cache-list's sognature use case..

    // requirements: get(key) and put(key,value) both in O(1) and the chache must evict the least recently used item when full..(DO IT LATER)

    // Iterator Stability-Another reason LIST Is special..

    // This connects back to the iterators invalidation discussion from vector.With list insertion or erasing a node never invalidates
    // Iterator/pointers/references to other,unrelated nodes-only the iterator to specific erased node becomes invalid.This is fundamental diff from vector,where insertion can trigger a full reallocation,invalidating every existing iterator..

    /*
        Complexity Summary
        Operation	                    Complexity
        push_front / push_back	        O(1)
        pop_front / pop_back	        O(1)
        front() / back()	            O(1)
        Insert/erase at a known iterator	O(1)
        Finding an element by value	        O(n)
        Random access (l[i])	        ❌ Not supported
        sort()	                        O(n log n)
        reverse()	                    O(n)
        merge() (two sorted lists)	    O(n)
        splice()	                    O(1) per element moved
        Iterator/reference stability	Preserved across insert/erase of other elements
    */

    // reverse takes O(n) cause, swap prev and next node of each node..

    // merge()(of two sorted list) O(n) cause O(n)..cause splice apply on all nodes of another list

    // splice() is O(1)..just relinking..

    // sort-O(nlogn) cause mergeSort apply on it.

    // ARRAY

    // std::array is a fixed-size contiguous container whose elements are stored directly inside the array object, while std::vector is a dynamically sized contiguous container whose elements are typically stored in a separately allocated buffer.

    // std:array<T,N> (instroducing in c++11, in <array>) is a thin, zero overhead wrapper around raw C-style T[N]. The size N is template parameter-backed into the type itself at compile time-so it can never grow or shrink at runtime..

    // WHAT IS T[N]? T is type here and N is number of element.. so int arr[5]..or double arr[5]

    // what does wrapper means here?Something that puts an existing thing inside a nicer interface and gives you additional functions...

    // like int arr[5]; does not have function like front(),back(),size() etc.. but std::<array> give us this function..

    // C-style array
    //     ↓
    // int arr[5]
    //     ↓
    // std::array gives it a nicer STL interface
    //     ↓
    // std::array<int,5>

    // zero-overhead mean? The wrapper doesn't add significant runtime memory or performance cost compared with using the raw array directly.

    // conceptually <array> is std::array<int,5> arr; is struct{int arr[5]}

    // so data is still in array object, The integers are inside the std::array object itself.

    // std::array = a fixed-size C-style array with a convenient STL interface, without adding a separate dynamic-memory layer.

    // think of simple version of how std::array can be imagined internally

    /*
        template<typename T, size_t N>
        struct array {
            T elems[N];
        };
    */

    // This means an array<int, 5> declared as a local variable is stored entirely on the stack, contiguous, with zero overhead compared to a raw int arr[5] — the STL wrapper adds convenience methods but compiles down to the same machine code.

    // Stack memory:  [ 1 | 2 | 3 | 4 | 5 ]   ← all 5 ints, inline, no indirection

    // std::array stores its elements directly inside the object, so there is no pointer indirection to reach the elements. std::vector stores its elements in dynamically allocated memory and the vector object holds a pointer to that memory, so accessing the elements involves one level of indirection.

    // why we called vector store on heap memory?"The vector object can be on the stack, while its dynamically allocated element storage is usually on the heap."

    /*
        |                     | `std::array`  | `std::vector` |
        | ------------------- | ------------- | ------------- |
        | Object              | Usually stack | Usually stack |
        | Actual elements     | Inside object | Usually heap  |
        | Pointer to elements | ❌             | ✅             |
        | Can grow?           | ❌             | ✅             |

    */

    // vector itself can be on the stack, but its data is usually on the heap.

    // So there are TWO things:

    // 1. Vector object v → usually stack

    // It contains things like:

    // pointer
    // size
    // capacity

    // 2. Actual elements → dynamically allocated memory, usually called the heap

    // [10][20][30][40][50]

    // why array matters:No dyanmic allocation overhead..cause there's no heap allocation

    // construction is essential free(no malloc or new call no bookeeping)

    // destruction is essentially free also(no delete/free call)

    // best possible cache locality-if the array fits in cache line or two accessing it is about fast as memory access gets..

    // this makes array, the ideal choice for small fixed size data used in hot loops..

    // Constructions

    /*
        array<int, 5> a1;                      // uninitialized (garbage values) if not explicitly initialized!
        array<int, 5> a2 = {1, 2, 3, 4, 5};      // aggregate initialization
        array<int, 5> a3 = {1, 2};                // remaining elements zero-initialized: {1,2,0,0,0}
        array<int, 5> a4{};                         // all zero-initialized (value-initialization)
    */

    // Gotcha: array<int, 5> a1; without an initializer leaves the elements with indeterminate values for built-in types (int, double, etc.) — same behavior as a raw C array. Always initialize explicitly if you need defined starting values.

    // Access

    /*
        array<int, 5> arr = {10, 20, 30, 40, 50};

        arr[2];             // O(1) — no bounds check, UB if out of range
        arr.at(2);            // O(1) — bounds-checked, throws std::out_of_range
        arr.front();            // O(1) — first element
        arr.back();               // O(1) — last element
        arr.data();                 // O(1) — returns raw T* pointer to the underlying array (useful for C-API interop)

    */
    cout << endl;
    array<int, 5> elems = {1, 2, 3, 4, 5};
    cout << "given data of array is: " << elems.data() << endl; // given the address of the elems array..As equal to int arr[5]..if we directly used..cout<<arr<<endl; same...

    // size-related(All compile time constants O(1))
    /*
        arr.size();       // always returns N — known at compile time, effectively free
        arr.empty();        // true only if N == 0 (a valid, if unusual, instantiation: array<int,0>)
        arr.max_size();       // same as size() for array — since it can never resize
    */

    // Modification(value only-no size)

    /*
        arr.fill(0);              // O(n) — sets every element to 0
        arr.swap(otherArr);          // O(n) — swaps contents element-by-element (both must be SAME type AND size!)

        // NO push_back, pop_back, insert, erase, resize — literally impossible, size is part of the TYPE

    */

    // Iterations

    /*
        for (int x : arr) cout << x << " ";                    // range-based
        for (auto it = arr.begin(); it != arr.end(); it++) ...    // iterator-based
        for (auto it = arr.rbegin(); it != arr.rend(); it++) ...    // reverse iteration
    */

    // since array provide full access of random-access iteration(unlike list/forward_list).it works seamlessly with every standered algor..

    /*
        sort(arr.begin(), arr.end());                    // ✅ works — array has random access iterators
        auto it = lower_bound(arr.begin(), arr.end(), 25);   // ✅ works
    */

    // Why array doesnt decay like a raw C Array..
    // array have two big advantage of std array..over c-style array..

    // 1) array doesnt turn into a pointer when passed to a function..
    // 2) array can be copied normally like other c++ objects..

    // raw array decay to a pointer..when we passed array name..to function its treated as first element pointer to that array..

    // printRaw(arr); means the array automatically convert into a pointer to its first element..

    // SO, this automatic conversion is called array to pointer decey..

    // why this is problem?
    /*
        void printRaw(int arr[5]){
            cout<<sizeof(arr); its return us 8bytes
            the size of pointer..not the array object..5 int * 4bytes =20 bytes..
        }

        //so this is size of pointer, so function knows only i have an address of an integers..but dont know how many integers are there..?
    */

    // but not happens with std::array..we have method like arr.size()l; return size of elements in arr..

    // if we sizeof(arr); also works return 20bytes of 5int..

    // and now the second part: COPYING
    // this is another very important difference, if we have two <array> then if create copy of first array into second
    // arr<int,3> a={1,2,3};
    //  arr<int ,3> b=a;
    // this make the completely the separeted copy of all the elements..so if we b[0]=100, its show changes in b only..not the a array..

    // but this not possible with the raw array..cause theirs no concept of copying the whole array...just doing this manually..with the help of loop..so Raw c array dont have normal copy/value semactics..

    // What does "value semantics" mean?
    // value semantics means the objects behaves like a value..so <array> have value semantics,but raw c array dont..

    /*
        | Feature                  | Raw array | `std::array` |
        | ------------------------ | --------- | ------------ |
        | `int a[5]`               | ✅         | —            |
        | Fixed size               | ✅         | ✅            |
        | `.size()`                | ❌         | ✅            |
        | `.at()`                  | ❌         | ✅            |
        | Array-to-pointer decay   | ✅         | ❌            |
        | Easy whole-array copying | ❌         | ✅            |
        | STL algorithms           | Limited   | Excellent    |
        | Value semantics          | ❌         | ✅            |

    */

    /*
        Operation	            Complexity
        Access arr[i] / .at(i)	    O(1)
        .size()	                    O(1) — literally a compile-time constant
        .fill()	                       O(n)
        Copy (constructor/assignment)	O(n) — copies all N elements
        .swap()	                        O(n) — element-wise swap (not O(1) like vector::swap, since there's no heap pointer to just swap!)
    */

    // When to Use array — Concrete Scenarios
    // Fixed small collections known at compile time : RGB color array<uint8_t, 3>, chess board row, day - of - week lookup table Returning a small, fixed - size collection from a function without heap allocation :

    // array<int, 3> getRGB() { return {255, 0, 0}; }  no heap allocation, efficient return

    // Performance-critical code where avoiding heap allocation entirely matters (embedded systems, real-time systems, tight loops)

    // As a safer drop-in replacement anywhere you'd otherwise reach for a raw C-style array

    // Important nuance: vector::swap is O(1) because it just swaps the internal pointer/size/capacity — no element copying needed. array::swap is O(n) because there's no pointer to swap — the data lives directly in the object, so swapping means actually swapping every element's value.

    //  How do we work with 2D Arrays?
    //  As we know thet metrix play important role in maths..

    cout << "from here,start the 2D array topic\n";
    // how we define 2D array in c++?
    int mat[3][5] = {{1, 2, 3, 4, 8}, {5, 6, 7, 8, 7}, {9, 10, 11, 12, 16}};

    // access
    cout << mat[0][0] << endl; // return the first element of 2D array..

    // also we modify the array's elements
    mat[0][0] = 1000;
    cout << mat[0][0] << endl; // return the first element of 2D array..

    // how to calculate the size of rows amd columns
    // this is based on old array method..so calculate the size of array..always passes with int row and int col..

    // but if we wanna to calculate the size of 2D array..

    int mat_rows = sizeof(mat) / sizeof(mat[0]);
    int mat_cols = sizeof(mat[0]) / sizeof(mat[0][0]);

    cout << "size of rows and col is: " << mat_rows << " " << mat_cols << endl;

    // loops over the 2D arrays(both input and output)
    // int mat1[3][5];
    // int mat1_rows = sizeof(mat1) / sizeof(mat1[0]);
    // int mat1_cols = sizeof(mat1[0]) / sizeof(mat1[0][0]); // we just calculate..but we exipilcitly mention that..

    // cout << "Please enter your matrix: ";
    // for (int i = 0; i < mat1_rows; i++)
    // {
    //     for (int j = 0; j < mat1_cols; j++)
    //     {
    //         cin >> mat1[i][j];
    //     }
    // }

    // // also for output
    // for (int i = 0; i < mat1_rows; i++)
    // {
    //     for (int j = 0; j < mat1_cols; j++)
    //     {
    //         cout << mat1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // In memory, how 2D array store..we know that 1D array we store in linear Contiguous manner..as same we store the 2D array..but we automatically complier automatically store 1) Row major and 2) Column major

    // In row major: we store the rows wise value in contiguoes manner..like in above   {{1, 2, 3, 4, 8}, {5, 6, 7, 8, 7}, {9, 10, 11, 12, 6}}; so In memory same as 12345678910111216..
    // In Column major: store value in contigeous manner, take all 0th col value, the 1th col ..upto to n-1..

    // Linear Search in 2D Array..

    // already we have, mat, rows-3 and cols-5 and target is 16..

    cout << "Check that Is target exists or not? " << linearSearch(mat, 3, 5, 16) << endl;
    pair<int, int> ansPair = linearSearchPair(mat, 3, 5, 16);
    cout << "return the target index: " << ansPair.first + 1 << " " << ansPair.second + 1 << endl;

    // now, return the maximum row sum...

    cout << "Maximum row sum is: " << MaximumRowSum(mat, 3, 5) << endl; // 1000+2+3+4+8=1017

    // treverse on the basis of rows
    for (int i = 0; i < mat_rows; i++)
    {
        for (int j = 0; j < mat_cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // first treverse the 2D array on the basis of cols

    cout << endl;
    for (int i = 0; i < mat_cols; i++)
    {
        for (int j = 0; j < mat_rows; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // now doing the same for Max columns sum
    cout << "Maximum row sum is: " << MaximumColSum(mat, 3, 5) << endl; // 1000+5+9

    // Calculate the Diagonal sum of 2D array(sqaure) both even and odd..

    // calculate the primary diagonal and secondary diagonal sum both..

    int mat_Dia[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int mat_Dia1[3][3] = {{1, 20, 3}, {4, 50, 6}, {70, 8, 9}};

    // for even
    cout << "Sum of diagonal of mat_Dia(Even square) matrix: " << calDiagonalSum(mat_Dia, 4) << endl;

    // for odd..
    cout << "Sum of diagonal of mat_Dia(odd square) matrix: " << calDiagonalSum_N(mat_Dia1, 3) << endl;

    // what is 2D vector?
    // this 2D vector also same as vector characteristic in 1D wrt array..its dyanmical size and compile at run time..

    // this is not necessary to be same size of row cols may vary..
    // so size of vector(rows) may changes or vector.el[0] also vary(cols)..

    vector<vector<int>> matrix = {{1, 2, 3}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // same for this calculate the MaxSum of rows

    cout << "Calculate the max sum of the vector matrix: " << maxRowSumvector(matrix) << endl;

    // Search element in 2D vector..brute force approach is nested loop..O(m*n)

    // You are given an m x n integer matrix matrix with the following two properties:

    // Each row is sorted in non-decreasing order.
    // The first integer of each row is greater than the last integer of the previous row.
    // Given an integer target, return true if target is in matrix or false otherwise.

    // You must write a solution in O(log(m * n)) time complexity.
    /*
        bool searchMatrix(vector<vector<int>>& m, int target) {
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==target){
                    return true;
                }
            }
        }return false;

    }
    */

    // now optimal approach in functions
    vector<vector<int>> test2D = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    cout << "Is target exists or not in 2D vector,using the O(log(m*n)): " << searchMatrix(test2D, 7) << endl;

    // Search in 2D matric(type-2 problem)
    vector<vector<int>> matrix22 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    //  Write an efficient algorithm that searches for a value target in an m cross  n integer matrix matrix. This matrix has the following properties:

    // Integers in each row are sorted in ascending from left to right.
    // Integers in each column are sorted in ascending from top to bottom.

    // O(m+n) TC

    cout << "Is target founded in matrix 2D array(2nd type): " << searchMatrix2(matrix22, 24) << endl;

    // also we using the second approach in first varitions,but O(log(n*m)) > O(n+m)...

    // Spiral matrix: Given an m x n matrix, return all elements of the matrix in spiral order.

    // like matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,3,6,9,8,7,4,5]

    vector<vector<int>> gonnaSpiral = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ansSpiaralMatrix = spiralmatrix(gonnaSpiral);

    cout << "solution of matrix in spiral form: ";
    for (int val : ansSpiaralMatrix)
    {
        cout << val << " ";
    }
    cout << endl;

    // 2 SUM problem:
    /*

        You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.

        Example 1:

        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]

    */

    // firstly with brute force approach..
    // Takes O(n^2) TC
    vector<int> for2Sum = {2, 7, 11, 15};
    auto ans2Sum1 = twoSumBF(for2Sum, 9);
    cout << "Answer indexes are: " << ans2Sum1[0] << " " << ans2Sum1[1] << endl;

    // now using the better approach of O(nlogn)-using the sort and 2 two pointer approach..
    auto ans2Sum2 = twoSum2(for2Sum, 9);
    cout << "Answer indexes using better approach are:  " << ans2Sum2[0] << " " << ans2Sum2[1] << endl;

    // now the optimal approach to doing this..O(n) using the hashing map..
    auto ans2Sum3 = twoSum3(for2Sum, 9);
    cout << "Answer indexes using better approach are:  " << ans2Sum3[0] << " " << ans2Sum3[1] << endl;

    // doing the missing and repeated number..

    /*2965. Find Missing and Repeated Values

        You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

        Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
    */
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    auto ansMisRE = findRepeatingAndMissing(grid1);
    cout << "find the repeated and missing no. resp is: " << ansMisRE[0] << " " << ansMisRE[1] << endl;

    // 287. Find the Duplicate Number

    // Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    // There is only one repeated number in nums, return this repeated number.

    // You must solve the problem without modifying the array nums and using only constant extra space.

    // Example 1:

    // Input: nums = [1,3,4,2,2]
    // Output: 2

    vector<int> forLL = {1, 3, 4, 2, 2};
    cout << "Finding duplicate value using unordered set: " << findDuplicate(forLL) << endl;
    // it takes  O(n)TC and O(n)SC

    cout << "Finding duplicate value using linked-list: " << findDuplicate_LL(forLL) << endl;
    // it takes only O(n)TC and O(1)SC

    // So, gonna RECURSION in detail..

    // what is Recursion?
    // Recursion is when a function calls itself to solve a smaller instance of the same problem,until it reaches a case simple enough to solve directly(the base case)

    // Every recursion function needs two things:

    // BASE CASE: the condition that stops recursion case(prevent infinte calls)

    // Recursive case: where the funtion calls itself with smaller/simplex input,moving towards the base case.

    // Example:
    /*
        void abc()
        {

            abc();
        }
    */

    // example to calculate the factorial using the factorial

    // int factorialN(int n){
    //     if(n<=1)return 1;

    //     return n*factorialN(n-1);
    // }

    // this is same as in mathematics we do..with help of composite function..like fog gof fof..etc

    // firstg call is always main->function..-> function return something in "main"..->main return 0;

    // but in recursion
    // main->function->fucntion->function->...until hit the base case..return base case..

    // we solve some part and pass rather to sa,e function..if we do our work right then..function we call..also doing the right work..

    // How it actually works-The call stack?
    // this is the part interviewer love to probe..each funtion call gets it own stack frame..containing local variable,parameters and return address..these frame are pushed onto the call stack..

    //     factorial(4)
    //         └─ factorial(3)
    //             └─ factorial(2)
    //                 └─ factorial(1) → returns 1
    //             └─ returns 2*1 = 2
    //         └─ returns 3*2 = 6
    //    returns 4*6 = 24

    // calls "windups"(push frame) until the base case,then "unwind"(pop frame,computing results) back down..this is why deep recursion can cause overflow-each frame consume stack and the stack has a limited size(1-8 MB)..

    // types of recursion
    // 1
    // direct vs indirect: when function call itself is called direct...and but if function call something else funtion and those function calls it own..A->B->A(Indirect) and Direct(A->A)..

    // Direct: A calls A
    // void A(int n) { if (n > 0) A(n - 1); }

    // // Indirect: A calls B, B calls A
    // void B(int n);
    // void A(int n) { if (n > 0) B(n - 1); }
    // void B(int n) { if (n > 0) A(n - 1); }

    // 2) Tail recursion :the resursion call is the last operation, nothing pending after it..(no backtracking)..

    //     int factTail(int n, int acc = 1) {
    //     if (n <= 1) return acc;
    //     return factTail(n - 1, n * acc); // nothing left to do after this call
    // }

    // Important interview point: Unlike some functional language, c++ doesnt guarantee tail call optimization(TCO)..complier may optimizated it witj -02/-03,but you cant rely on it..so tail recursion in c++ can still overflow the stack,know this its gotcha question..

    // 3
    // Head Recursion: work happen after the recursive call return(as in the factorial example above..)

    // like return n*fac(n-1);

    // 4

    // Tree recursion: a funtion calls itself more than once..

    // int fib(int n) {
    // if (n <= 1) return n;
    // return fib(n - 1) + fib(n - 2); // two recursive calls → branches like a tree
    // }

    // 5
    // Nested recursion-a recursion call as an argument to another

    // int f(int n) {
    // if (n > 100) return n - 10;
    // return f(f(n + 11));
    // }

    // In the fibonacci..Time C- O(2^n) and space C is O(N)..we doing it more optimized with DP..

    // Any recursiev function can convert into to iterative using the explicit stack(since that's literally what recursion uses under the hood)-interviewer sometime ask you to do this conversion manually..

    // Iterative factorial using explicit stack (mimics recursion)
    // int factorialIterative(int n) {
    //     int result = 1;
    //     for (int i = 2; i <= n; ++i) result *= i;
    //     return result;
    // }

    // How recursion is performed in c++?

    // The base Mechanism:
    // to performe recursion in c++, you write a function that calls itself inside its own body,with condition that eventually stops it..

    /*
        returnType functionName(parameters){
            if(baseCondition){
                return baseValue;
            }
        //do some work,then. calls itself with a smaller/simple input

            return functionName(smallerInput);
        }

    */

    // That's the entire syntax: nothing spcial is needed in c++.Any normal fucntion becomes recursive the comment it calls itself..

    // steps keep it mind..
    // identify the base case
    // identify the recursive case
    // make sure input shrink towards the base case

    // int sum(int n){
    //  if(n==0)return 0;
    //      return n+sun(n-1);
    //  }

    // sum(4) = 4 + sum(3)
    // sum(3) = 3 + sum(2)
    // sum(2) = 2 + sum(1)
    // sum(1) = 1 + sum(0)
    // sum(0) = 0   ← base case hit, starts returning back up

    // Then it unwinds: 0 → 1 → 3 → 6 → 10.

    // Also multiple recursive calls(Branching)
    // A function can call itself more than once-this is common for trees and combinatorics:
    // example of fibonacci..return fin(n-1)+fib(n-2);

    // What is backtracking ?
    // Backtarcking is a refined form of recursion used to solve problem by building a solution incrementally and abandoing("backtarcking") a path as soon its clear it cannot lead to a valid solution.

    // think of it as DFS on decision tree,where at each nodes you..

    // choose-pick an option
    // explore-recurse deep with that choice
    // un-choose-undo the choice before trying the nextg option(this is the "backtracking" steps)

    // It's used when a problem requires exploring all possible combinations/configurations to find ones that satisfy some constraint (or find all of them).

    // using the call stack in memory, a frame ends only when..it return or it no work after that..tail recursion..

    // void printNumber(int n)
    // {
    //     if (n == 1)
    //     {
    //         cout << n << " ";
    //         return;
    //     }
    //     cout << n << " ";
    //     printNumebr(n - 1);
    // }
    // so, O(N)TC and O(N)SC

    // also important to make recursion tree..helps us to calculate the TC and SC..
    // calculate the time complexicity using two method 1) reccursion relation and 2) TC= total no of call in recursion tree * work done in each call..

    // also same for Space Complexicity, SC= depth of recursion tree * memory in each frame...and SC=height of call stackv* work done in each frame..

    // WAF to calculate the foctorial of N number using the recursion and make recursion tree and calculate the TC and SC..

    // int factorialN(int n)
    // {
    //     if (n == 0 || n == 1)
    //         return n;
    //     return n * factorialN(n - 1);
    // }
    // O(N)TC and O(N)SC

    // Sum of N natural number..

    // int sumN(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     return n + sumN(n - 1);
    // }
    // O(N)TC and O(N)SC

    // using recursion..make fiboacchi series..
    // int fib(int n)
    // {
    //     if (n == 0 || n == 1)
    //     {
    //         return n;
    //     }
    //     return fib(n - 1) + fib(n - 2);
    // }
    // TC: O(2^n) and SC: O(N);

    // Check is array sorted or not?

    // bool isSorted(vector<int> & arr, int last_idx)
    // {
    //     if (last_idx == 0)
    //         retunr true;
    //     return arr[last_idx - 1] <= arr[last_idx] && isSorted(arr, last_idx - 1);
    // }

    // TC-O(N) ans SC-O(N)..

    // binary Search using the recursion..
    // int binarySearchUsingRecursion(vector<int> & nums, int target, int st, int end)
    // {
    //     if (st <= end)
    //     {
    //         int mid = st + (end - st) / 2;
    //         if (nums[mid] == target)
    //         {
    //             return mid;
    //         }
    //         if (nums[mid] < target)
    //         {
    //             return helperfunction(nums, target, mid + 1, end);
    //         }
    //         else
    //         {
    //             return helperfunction(nums, target, st, mid - 1);
    //         }
    //     }
    //     return -1;
    // } // TC: O(logn) and SC: O(logn) also..

    // Using the backtracking..solve the "print all subset of given array..."

    // Given an integer array nums of unique elements, return all possible subsets (the power set).

    // The solution set must not contain duplicate subsets. Return the solution in any order.

    // void helperfunction(vector<int> & nums, vector<int> & ans, int idx, vector<vector<int>> &powerSet)
    // {
    //     int n = nums.size();
    //     if (idx == n)
    //     {
    //         // also return here
    //         powerSet.push_back(ans);
    //         return;
    //     }
    //     // base case

    //     // body, simple problem solve..that is is idx include or not..first

    //     // include the idx's value in ans..
    //     ans.push_back(nums[idx]);
    //     helperfunction(nums, ans, idx + 1, powerSet);

    //     ans.pop_back(); // remove the current el..

    //     // exclude the idx's value
    //     helperfunction(nums, ans, idx + 1, powerSet);
    // }

    // varition of the same in the leetcode problem 90..

    // Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    // The solution set must not contain duplicate subsets. Return the solution in any order.

    // Example 1:

    // Input: nums = [1,2,2]
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    // void helperfunction(vector<int> & nums, vector<int> & ans, int idx, vector<vector<int>> &powerSet)
    // {
    //     int n = nums.size();
    //     // also sort the nums first
    //     if (idx == n)
    //     {
    //         powerSet.push_back(ans);
    //         return;
    //     }

    //     // include
    //     ans.push_back(nums[idx]);
    //     helperfunction(nums, ans, idx + 1, powerSet);

    //     // remove the current el
    //     ans.pop_back(); // backtarcking

    //     // exclude the value
    //     while (idx + 1 < n && nums[idx] == nums[idx + 1])
    //     {
    //         idx++;
    //     }
    //     helperfunction(nums, ans, idx + 1, powerSet);
    // }

    // What is forward_list? In detail..
    // for that include the forward_list STL file

    // std::forward_list<T>(c++11, in <forward_list>) is STL's singly linked list-each node only a next pointer,no prev.It was deliberately deigned to be the absolute minimal overhead linked list STL offers,explicitly optimized for memory footprint over features-completeness..

    // internal sturcture
    // struct Node{
    //     T data;
    //     Node* next;//no prev pointers
    // }

    //[1|next] → [2|next] → [3|next] → nullptr

    // compared to list's node(T data;Node* next,Node* prev),each forward list node saves exactly pne pointer's worth of memory(8 bytes on a 64 bit system).For a list of million elements, that;s roughly 8MB saved..genuinely meaningful in memory-constranined contexts..(embedded systems, very large datasets where you're optimizing every byte).

    // why the interface Is deliberately restricted?
    // this is most conceptual point about forward_lisr:every operation that would require O(n) hidden cost to support is simply not provided..forcing you to be explicitly aware of complexity rather than accidentally writing slow code that "looks" fast..

    // simply tells us that we are not provding the function that cost hidden O(n) or more..this is only for minimal overheads..

    // like size()
    // forward_list<int> f1={1,2,3,4};

    // f1.size(); NOT PROVIDED cause it takes internally O(n)..list internally maintain a running count..Forward_list deliberately does not maintain this counter-doing so would add a member variable to very forward_list objecrs..working against "minimal overhead"

    // so for calculating the size of forwaed_list simply calculate through

    forward_list<int> f11 = {1, 2, 3, 4, 5};
    int count = distance(f11.begin(), f11.end());
    cout << "size of forward_list is: " << count << endl;

    // their's not function to calculate the direct size of forward_list..

    // havent no push_back();

    // f11.push_back(6); NOT PROVIDED

    // without a prev pointer a maintained tail pointer,reaching the last node require walking the entire list from the fornt-O(n)..cause push_ back is omitted specifically so you cant accidentally write a loop that calls it repeated,silently turning an intended O(n) build into O(n^2);
    //// If push_back existed and you did this in a loop:

    // for (int i = 0; i < n; i++) fl.push_back(i);   // would be O(n²) — EACH push_back is O(n) to find the tail!..like this takes O(n^2)..

    // cause forward_list is singly linked lisr,and it only stores a link to next node..

    // there is no prev pointer ans importantly,forward_list doesnt maintain a tail pointer..

    // what happen if we want push_back(6);
    // we need to find the last node..startig from first..only after walking through all nodes can we attach 7 in last..if there are n nodes,wa may have have to visit all n nodes..

    // therefore are push_back() takes O(n)TC

    // but why we dont just maintain a tail pointer?..we know that forward_list is specifically designed to be minimal and lightweight..

    // it only need essesntially front->first node..but maintaining the last node..means maintaining extra info and updating it durung operations..

    // so how we add value at the end?
    auto prev = f11.before_begin();
    for (auto it = f11.begin(); it != f11.end(); it++)
    {
        prev = it;
    }
    f11.insert_after(prev, 6);

    for (int val : f11)
    {
        cout << val << " ";
    }
    cout << endl;

    // but this explicitly O(n)//thats exactly the philosphy of forward_list; it does not pretend that reaching the end is cheap..

    // forward_list:

    // push_front() → O(1) ✅
    // push_back()  → ❌ not provided

    // compare:push_front() is provided, since the front is always immediately accessible-O(1), no hidden cost..

    f11.push_front(0); // add element at the front of flist.. // ✅ O(1) — always available

    // insert_after/erase_after, NOT insert/erase
    // In the forward_list there is no no erase or insert in list..infact in that place erase_after and insert_after..

    auto f1_it = f11.begin();
    f11.insert_after(f1_it, 2); // insert at 1 Index of list
    // f1_it = f1_it++;

    // f11.erase_after(f1_it); // erase the 3index of the flist..

    auto nf1_it = f11.begin();
    nf1_it++;
    cout << (nf1_it == f1_it) << endl;

    f11.erase_after(nf1_it);

    for (int val : f11)
    {
        cout << val << " ";
    }
    cout << endl;

    // why? TO insert or erase at given iterator position in a singly linked structure,you'd need access to the previous node(to rewrite its next pointer past the new/removed node)..since there'no prev pointer..finding the previous node require walking from the head..-O(n) so the interface is redesigned aroung "insert/erase after this node"..so only next pointer require it-1 pointer ...and make insert_after and erase_after...

    // also before_begin()- A special iterator for editing the front..since you cant insert "before" a using normal iterator(there'no way to reach the previous node), forward list provide a special sentinel itertor before_begin() that conceptuallu point to a phantom position before the first element enabling insert_after and erase_after to work even at the front of list.

    /*
        forward_list<int> fl = {2, 3, 4};

        fl.insert_after(fl.before_begin(), 1);   // effectively "insert at front" via insert_after
        // fl = {1, 2, 3, 4}
    */

    // full operations references..

    // we already have forward list
    // 0 2 2 3 4 5 6

    f11.push_front(0); // O(1)
    f11.pop_front();   // O(1)

    cout << "front elem of the array: " << f11.front() << endl; // it should be 0 //O(1)

    auto it_f112 = ++f11.begin();

    f11.insert_after(it_f112, 99); // add on 3rd elem
    for (int val : f11)
        cout << val << " ";
    cout << endl;
    // O(1)
    //  0 2 99 2 3 4 5 6

    f11.erase_after(f11.before_begin()); // erase first index
    // 2 99 2 3 4 5 6
    for (int val : f11)
        cout << val << " ";
    cout << endl; // O(1)

    f11.remove(6); // remove all the elem whose value equal to 6..
    for (int val : f11)
        cout << val << " ";
    cout << endl;
    // 2 99 2 3 4 5
    // O(n)

    f11.remove_if([](int x)
                  { return x < 3; }); // remove elem with some condition on it..if elem less than 0 then remove those elems
    // it
    for (int val : f11)
        cout << val << " ";
    cout << endl;
    // 99 3 4 5
    // O(n)

    f11.sort();
    for (int val : f11)
        cout << val << " ";
    cout << endl;
    // 3 4 5 99
    // O(nlogn)

    f11.reverse(); // reverse the all elems of list
    for (int val : f11)
        cout << val << " ";
    cout << endl;
    // 99 5 4 3
    // O(n)

    // f11.unique();-already done above, O(n) remove the consecutive duplicates
    // f11.merge(otherlist);merge two SORTED forward_lists
    // f11.splice_after(it,otherlist); depending on overload O(1) or O(n)..

    // Notice splice_after, not splice — same naming convention shift as insert_after/erase_after, for the identical structural reason.

    /*
        Comparison: list vs forward_list
        Aspect	list	forward_list
        Pointers per node	2 (prev, next)	1 (next only)
        Memory per node	Higher	Lower (~1 pointer less)
        Backward traversal	✅ Supported	❌ Not supported
        size()	O(1)	❌ Not provided (would be O(n))
        push_back()	O(1)	❌ Not provided (would be O(n))
        back()	O(1)	❌ Not provided
        Insert/erase style	insert/erase (at position)	insert_after/erase_after
        splice()	✅	splice_after
        Reverse iterators (rbegin/rend)	✅	❌ Not provided (needs backward traversal)

    */

    /*
        When to Actually Use forward_list

        Honestly — rarely, in an interview context. The realistic scenarios are:

        Extreme memory constraints — embedded systems or massive datasets where every byte per node matters and you genuinely only ever need forward traversal

        Implementing algorithms that are naturally singly-linked — e.g., certain hash table bucket implementations internally use singly-linked chains

        Signaling intent — using forward_list instead of list communicates to future readers "this will only ever be traversed forward," which can be a meaningful design statement in a larger codebase

    */

    // what is Pair?
    // std::pair <T1,T2> is a simple template class in <utility> that bundless exactly two values-possibly of different types-into a single object..Its the simplest possible "compound" data structure the STL offeres..

    // for that #include <utility> ..technically where the pair lives..<bits/stdc++.h> or many headers pull it in transitively..

    pair<int, int> pair1 = {3, 5};

    // internal structure -genuinely just a struct
    // conceptually, std::pair is implemented almost exactly like this...
    /*
        template<typename T1, typename T2>
        struct pair {
            T1 first;
            T2 second;
        };
    */

    // their no hidden complexity-no heap alloacation,no dynamic resizing,nothing beyond two named member variable..this connects directly back to our earlier struct discussion:pair is struct(in spirit) and behaves with all the same memory charachtersitics-contiguous storage of its two members,stack-allocated when declared as local variable no indeirection..

    // pair<int, int> pair1 = {3, 5};
    // Memory: [ first=3 | second=5 ]   ← contiguous, inline, like any struct

    // Creating a pair
    // pair<int, int> p1 = {3, 5};          // aggregate/brace initialization
    // pair<int, int> p2(3, 5);             // constructor call
    // pair<int, int> p3 = make_pair(3, 5); // make_pair — type deduced automatically

    // auto p4 = make_pair(3, 5); // also works, and is very common in practice

    // pair<int, string> p5 = {1, "hello"}; // different types — this is the whole POINT of pair

    // pair<int, string> p6 = make_pair(1, string("hello")); // make_pair is convenient cause it deduces the type automatically-ypu dont need to spell out pair<int,string> expicitly;

    // auto p = make_pair(5, "text"); // but "text consider as const pointer to char"..so define the string
    //  expilicitly the string("hello")

    // Access Members-.first and .second

    cout << "first value of pair: " << pair1.first << endl;
    cout << "first value of pair: " << pair1.second << endl;

    // also fully mutable,just like any struct member
    pair1.first = 30;
    pair1.second = 50;
    cout << "after appying the modification: " << pair1.first << " " << pair1.second << endl;

    // theirs no .at() or bound checking needed here..since there are only exactly two members and they re accessed by name(first/second) not by index..there no way to go "out of bounds"

    // Why pair Exists — The Core Use Case

    // The single most common reason pair shows up constantly in C++ (especially competitive programming and interviews) is that many STL functions and algorithms need to return or store two related values together, and pair is the lightest-weight way to do that without defining a custom struct every single time.

    // example1 : returning the multiple values from afunction

    /*
        pair<int, int> findMinMax(vector<int>& arr) {
            int mn = *min_element(arr.begin(), arr.end());
            int mx = *max_element(arr.begin(), arr.end());
            return {mn, mx};
        }

        auto result = findMinMax(arr);
        cout << result.first << " " << result.second;   // min, max
    */

    // example2 :storing coordinates pairs..
    /*
        vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 6}};

        for (auto& [x, y] : points) {   // structured bindings (C++17) — very clean
            cout << "(" << x << ", " << y << ")" << endl;
        }
    */

    /*
        Example 3: map and unordered_map Are Literally Built on pair

        This is a genuinely important internals fact: when you iterate over a map<K, V>, each element you get is a pair<const K, V>.

        cpp
        map<string, int> m = {{"apple", 5}, {"banana", 3}};

        for (auto& entry : m) {
            // entry is actually of type pair<const string, int>
            cout << entry.first << ": " << entry.second << endl;
        }

        // which is exactly why structured bindings work seamlessly:
        for (auto& [key, val] : m) {
            cout << key << ": " << val << endl;
        }

        The const on the key type (pair<const K, V>) exists because modifying a key in place would corrupt the map's internal sorted/hashed structure — the STL prevents this by making the key portion immutable through the iterator.

    */

    // comparsion operators-lexicographic by default

    // This is one of the most useful built-in behaviors of pair, and it's exactly analogous to how strings compare (dictionary order): compare .first values first; if they're equal, compare .second values as a tiebreaker.

    // This works for ==, !=, <, <=, >, >= — all automatically defined, as long as both T1 and T2 themselves support the corresponding comparison.

    // pair1 30 and 50
    auto pair2 = make_pair(1, 1);
    auto pair3 = make_pair(5, 1);

    cout << "Is pair1<pair2: " << (pair1 < pair2) << endl;
    cout << "Is pair2<=pair3: " << (pair2 <= pair3) << endl;
    cout << "Is pair1!=pair3: " << (pair1 != pair3) << endl;

    // comparison the first elem, and tie broken by second-automatocally,no comparator needed..!

    // also sort algo apply on vector<pair<int,int>> v={....}

    // also support the sort(v.begin(),v.end())..
    // sort(v.begin(), v.end());
    // Result: {1,2}, {1,5}, {2,0}, {3,1}

    vector<pair<int, int>> vec_pair = {{2, 5}, {3, 3}, {0, 1}, {1, 1}, {2, 8}, {1, 4}};

    sort(vec_pair.begin(), vec_pair.end());
    // for (auto &[x, y] : vec_pair)
    //     cout << '(' << x << ',' << y << ')' << " ";
    // cout << endl;

    // for custome sorting argument..default ascending..

    // sort by second value..
    sort(vec_pair.begin(), vec_pair.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    // for (auto &[x, y] : vec_pair)
    //     cout << '(' << x << ',' << y << ')' << " ";
    // cout << endl;

    // auto &[x,y] is declaration in c++17, we prefer auto val..then using val.first or val.second

    // entry is actually of type pair<const string, int>

    sort(vec_pair.begin(), vec_pair.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first!=b.first)return a.first<b.first;
        return a.second > b.second; });

    // for (auto &[x, y] : vec_pair)
    //     cout << '(' << x << ',' << y << ')' << " ";
    // cout << endl;

    // the const on the key type(pair<const K,V>) exists because modifying a key in place would corrupt the map'internal sorted/hashed strructure-The STL prevents this by making the key porition immutable through the iterators

    // also using in set and map..

    // Because pair has built-in comparison operators, it can be used directly as a key in ordered associative containers without writing any custom comparator:

    /*
        set<pair<int,int>> visited;   // e.g., tracking visited grid cells in a graph problem

        visited.insert({2, 3});
        visited.count({2, 3});           // O(log n) — works because pair<int,int> is comparable

        map<pair<int,int>, int> distMap;  // e.g., mapping (row,col) -> distance
        distMap[{0,0}] = 0;
    */

    // concept of custome hash in set and pair...

    // mested pair- pair<pair<int,int>,int> ans similar..
    // yes you can bundle three or more value through this get unwiedly fast..

    // In practice, if you need 3+ values,std::tuple is cleaner:
    tuple<int, string, double> tup = {10, "Aakash", 85.5};

    cout << get<0>(tup) << endl; // 10
    cout << get<1>(tup) << endl; // Aakash
    cout << get<2>(tup) << endl; // 85.5
                                 // for thatg first include the <tuple>

    // or for anything beyond a quick throwaway use, a named struct is often more readable than either

    // struct Point3D { int x, y, z; };   // clearer field names than .first/.second/get<N>

    // brace vs make_pair
    // In modern c++11 and later) brace-initialization{a,b} is gernerally sufficent ans is what most competitive prog default to for brevity-make_pair is mostky a holdover from pre-c++11 code,through its stilll occasionally clearer when types need expicit deduction help..

    // moving and swaping pairs
    /*
        pair<int,int> a = {1, 2}, b = {3, 4};
        swap(a, b);       // O(1) if both T1, T2 are cheap to swap (like int) — swaps member-wise
        a.swap(b);          // same thing, member function version
    */

    // this gonna be imp topic of c++STL escpecially for set,map,unordered_set and more unordered_map

    // the main diff is
    // Ordered containers use comparison(<) to organize elements..where unordered containers used hasing to find elements..

    // so what is hashing?
    // Think of hashing as a fast way to decide where an element  should be stored, so that we cam find it quickly later..

    // the problem is to finding an element..suppose we have 10 25 37 42 89.. as we aks? where is 42?

    // if we search one by one ..it takes O(n)..but hashing idea..is simple instead of searching evry element ,we calculate a hash.. imagine we have 10 buckets 0-9..we can use simple hash fucntion hash(x)=x%10..so storing 10->0,25->5,37->7,42->2, 89->9.

    // we store them like..bucket 0 have 10 value, same for other..Now supposed to find the value of 42..firstly 42->hash fucntion ->find bucket->then find value in it...

    // we immediately knows where to look..thats the basic idea of hashing...

    // In c++,this is basically what an unordered_set does conceptually;

    /*
            unordered_set<int> s;

            s.insert(42);
            s.insert(25);
            s.insert(37);

            s.find(42);


            42
            ↓
            hash<int>(42)
            ↓
            bucket number
            ↓
            look in that bucket
            ↓
            42 found

    */

    // That's why unordered_set can have average O(1) lookup.

    // why is it called "hash"?
    // A hash function takes some input and produce a number..

    // hash<int>{}(42)..produce a size_t value..
    // 42
    // ↓
    // hash function
    // ↓
    // 123456789

    // the container then uses that hash to determine the appropiate bucket..the finding the proper value...All same for string..

    // why do we need == also?
    // two difference value can produce the same bucket/hash..this is called a collision..that why searching for that exact value must..

    // hashing finds the bucket; equality finds exact element

    // thats why unordered map or set is so fast..finding anything in O(1) amortized..

    // Hashing is the process of converting a key into a hash value that helps an unordered container quickly determine which bucket to search.

    // pair related to hashing(set/map or unordered_map/unordered_set)..

    // set<pair<int,int>> works directly because pair already has a built in lexicogrpagical comaprison...first elem comparison then second comparison..if first equal,than it compares second..so work directly..
    // because std::pair already provides the comparison needed by set..
    // same for map<pair<int,int>>..the keys automatocally ordered..map used camparison ans pair already knows how to compare..

    // what about unordered_set?
    // you might expect it to work just like set<pair<int,int>> but traditionally this doesnt work out of box..why? cause unordered_set doesnt sort...it use HASH FUNCTION..

    // An unordered container needs to answer.."which bucket should {x,y} go into?"

    // {10, 20}
    // ↓ hash function
    // ↓ 839472
    // ↓ bucket 7

    // this is problem is that c++ does not traditionally provide a standard: std::hash<pair<int,int>> implementation

    // IT HAS HASHES FOR MANY BASIC TYPES:
    // hash<int>
    // hash<string>
    // hash<double>

    // but not standard built in hash for every combination such as:
    // pair<int,int>
    // tuple<int,string,double>
    // vector<int>

    // for unordered_set<pair<int,int>> s; needs you tell c++,here's hoe you shoul hash a pair..

    // creating our own hash.. do this later
    /*
        #include <iostream>
        #include <unordered_set>
        using namespace std;

        struct PairHash {

            size_t operator()(const pair<int,int>& p) const {

                return hash<int>{}(p.first) ^
                    (hash<int>{}(p.second) << 1);
            }
        };

        int main() {

            unordered_set<pair<int,int>, PairHash> s;

            s.insert({2,5});
            s.insert({1,10});
            s.insert({2,3});

            for(auto p : s) {
                cout << p.first << " " << p.second << endl;
            }
        }
    */

    // now we gonna to create a custome hash function for unordered_map and unordered_set..for pair<int,int>

    // unordered_set<pair<int, int>> sp;//Error of no hash fucntions

    unordered_set<pair<int, int>, hashPair> sp;

    sp.insert({2, 3});
    sp.insert({1, 2});
    sp.insert({9, 0});

    for (auto s : sp)
    {
        cout << s.first << " " << s.second << endl;
    }
    // also same for the unordered_map:
    unordered_map<pair<int, int>, string, hashPair> up;
    up[{1, 2}] = "akc";
    up[{2, 3}] = "bkc";
    up[{4, 4}] = "iio";

    cout << up[{1, 2}] << endl;

    // std::pair already provides comparison operators, so ordered containers such as set can compare and order pairs directly. An unordered_set requires a hash function for its key type, and the standard library does not traditionally provide std::hash<pair<...>>, so we provide a custom hash.

    // Ordered → compare → tree → sorted
    // Unordered → hash + equality → buckets → no ordering.

    // what is STACK?
    // A stack is a linear data structure that follows the LIFO(last In,first out) principle-the last element added is the first one removed..think of a physical stack of books..you can only add a book to the top and you can only remove the topmost book-you cant pull one from the middle or bottom without dustrubuting everthing above it...

    // core operations(conceptual):- all core operations are O(1)-this is the entire point of a stack:fast,restricted access at just one end..

    // push(x),pop,top()/peek(),isEmpty(),size() -O(1)

    // lessgpoo..
    // for this include<stack> in header file

    stack<int> fs;

    fs.push(10);
    fs.push(20);
    fs.push(30);

    // now stack look like 10 20 30(top)
    cout << "top of fs is: " << fs.top() << endl;

    fs.pop();
    // now stack look like 10 20(top)
    cout << "top of fs is: " << fs.top() << endl;

    // topmost elment of stack is:
    cout << "topmost elment of stack is: " << fs.top() << endl; // 20

    // calculate the size of stack
    cout << "size of fs is: " << fs.size() << endl; // 2

    // check is stack empty or not?
    cout << "Is stack empty or not: " << fs.empty() << endl; // 0

    // also push with the emplace()-construction in place
    // emplace avoids creating a temporary object and then copying/moving it — for simple types like int there's no real difference, but for larger objects (structs, pairs, strings) it can save a copy.

    // warning:calling top() on emoty stack is undefind behavior-always check emoty() first if you re unsure

    // for iteration
    while (!fs.empty())
    {
        cout << fs.top() << " ";
        fs.pop();
    }
    cout << endl;

    // also a sap funtion..
    stack<int> fss;
    fss.push(1);
    fss.push(2);
    fss.push(3);
    fss.push(4);

    fs.swap(fss);

    while (!fs.empty())
    {
        cout << fs.top() << " ";
        fs.pop();
    }
    cout << endl; // 4 3 2 1

    // where fss is swap with empty stack..cause we pop up all values..

    // implementation a stack do it later...

    // std::queue - Complete guide form a memory placement point of view

    // What is Queue?
    // A queue is linear data stucture following tge FIFO(first in,first out) principle-the first element added is the first one removed..think of real-world line at checkout counter..people join at the back,and served from the front..

    /*
        Enqueue 1, 2, 3:

        front → [1][2][3] ← back

        Dequeue → removes 1 first (whoever's been waiting longest)
    */

    // this is key placement fact to start with: queue owns no memory of its own..Its purely an interface wrapper around sequence container(default: deque),resticting access to strickly"insert at back,remove from front"

    /*
        template<typename T, typename Container = deque<T>>
        class queue {
            Container c;   // the ENTIRE state of a queue is just this one underlying container
        public:
            void push(const T& val) { c.push_back(val); }
            void pop() { c.pop_front(); }
            T& front() { return c.front(); }
            T& back() { return c.back(); }
        };
    */

    // so when you declare queue<int> q;,whats actually place in memory is single member-an instance of deque<int> and every queue opertin just forward to that underlying conatiner...

    // Why the deafult underlying conatiner MUST BE deque(Not vector)

    // This is crucial placement-level distinction from stack..recall stack opertes only on the back of its underlying container, so vector works fine as backing store(push_back/pop_back) are both O(1)..

    // queue needs O(1) opertions at both ends-push_back()(enqueue) and pop_fornt()(dequeue).This is exactly why queue cannot default tp vector..thats why deque's chunked memory structure(as we discussed earlier) allow both front and back opertion at O(1),since removing from thhe front of first chunks just adjusts an internal offset-no data actually needs to move..

    /*
        Deque's chunked layout:

        Chunk 0: [_|_|1|2]   Chunk 1: [3|4|5|6]
                    ↑ front              ↑ back

        pop_front(): just moves the "front" marker to the next slot — O(1), NO shifting
        push_back(): adds to the last chunk (or allocates a new one) — O(1)
    */

    //     queue<int, deque<int>> q1;    // ✅ default, works
    // queue<int, list<int>> q2;      // ✅ works — list supports O(1) both ends
    // // queue<int, vector<int>> q3;  ❌ COMPILE ERROR — vector has no pop_front()

    queue<int> q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    // also with the emplace

    cout << "whats on front in queue: " << q1.front() << endl; // 10
    cout << "whats on back in queue: " << q1.back() << endl;   // 40
    cout << "whats size of queue: " << q1.size() << endl;      // 4

    // Ins single elem..both front and back are same point to 10..

    q1.pop();
    // after poping from queue
    cout << "whats on front in queue after pop: " << q1.front() << endl; // 20

    // to check is queue empty or not?
    cout << "Is our queue empty or not: " << q1.empty() << endl;

    // pop() Gotcha-same as stack..read the value first,then remove it-pop() cause return nothing

    // No iterations
    // queue<int, deque<int>> q1;    // DEFAULT — chunked memory
    // queue<int, list<int>> q2;      // scattered, node-based memory

    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);

    // after swaping the whole queue..
    q1.swap(q2);

    cout << q1.front() << " " << q1.back() << endl; // 1 3

    // The core takeaway, mirroring what we found with stack: queue has no memory identity of its own. Its placement story is entirely inherited from deque (or occasionally list), and the specific requirement of O(1) operations at both ends is precisely why vector — otherwise the default go-to container — is structurally incompatible as a backing store here.

    // implemtation of queue later..

    // What is std:: priority_queue ?
    // A priority queue is a data structure where elements are retrieved not by insertion order(like queue) or LIFO order(like stack), but by priority-the largest-priority(deafult the largest value) is always at the front regardless of when it was inserted

    /*
        Insert: 3, 1, 4, 1, 5

        Underlying storage isn't sorted — but top() ALWAYS gives the max:
        top() → 5
    */

    // priority_queue..Is also a container adapter-but with a twist..

    // Like stack and queue,priority_queue wraps an underlying conatiner.But unlike them..iits doesnt just forward operations directly-it maintains a heap invariant on top of that contaiuner using standalone heap algorithm(push_heap,pop_heap,make_heap) from <algorithm>

    /*
    template<typename T, typename Container = vector<T>, typename Compare = less<T>>
    class priority_queue {
        Container c;      // the actual data placement
        Compare comp;       // comparison function determining "priority"
    public:
        void push(const T& val) {
            c.push_back(val);                              // 1. place at the back
            push_heap(c.begin(), c.end(), comp);      // 2. re-establish heap order
        }
        void pop() {
            pop_heap(c.begin(), c.end(), comp);        // 1. move max to the back
            c.pop_back();                                       // 2. remove it
        }
        const T& top() { return c.front(); }              // max is ALWAYS at index 0
    };
    */

    // why the dafult underlying container is vector,not deque..

    // A binary heap doesn't need O(1) front operations at all — it needs fast random access (to jump between a node and its parent/children by index arithmetic) and fast back insertion/removal (to grow/shrink the array during heapify operations). vector provides exactly this: O(1) random access plus O(1) amortized push/pop at the back — and its contiguous memory gives the best possible cache locality for the heap's array-based tree traversal.

    // priority_queue<int, vector<int>> pq1;    // default, works great
    // priority_queue<int, deque<int>> pq2;       // also technically works (deque supports random access too)
    //  priority_queue<int, list<int>> pq3;   ❌ COMPILE ERROR — heap algorithms need RANDOM ACCESS iterators, list doesn't have them

    // Priority_queue is based on the CBT(complete binary tree Model

    // also working in #include <queue> header file..

    // visualizing the placement

    priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(9);

    // internally,the vector might look like [9,5,8,1,3]

    // As a tree(purely conceptual-no actual pointer exist, this is hust how flat array is interpreted)

    /*
        Index:        0   1   2   3   4
        Array:      [ 9 | 5 | 8 | 1 | 3 ]

        Tree view:
                        9(0)
                       /      \
                    5(1)      8(2)
                   /    \
                1(3)   3(4)

    */

    // why this placement is powerful:Every parent is guranteed >= both its children(max-heap property)-but siblings and deeper level arent sorted to each other.This partial ordering is exactly enough to guranteed the maximum is always at index,,achievable and mainatinable in O(logn)..while avoiding the O(n logn ) cost of keeping the entire array fully sorted..

    // trace through push()-Placement +reordering
    /*
        push(5): vector=[5]                      (single element, trivially a valid heap)

        push(3): vector=[5,3]  → push_heap → check: is 3 ≤ its parent(5)? yes → no swap needed vector=[5,3]

        push(8): vector=[5,3,8]  → push_heap → placed at index 2, compare to parent(0): 8 > 5 → SWAP

        vector=[8,3,5]

    */
    // at max swap until the height of tree..O(logn)

    // Mechanically, push_heap works by "bubbling up": the new element is placed at the very end (the next open array slot — an O(1) placement), then repeatedly swapped with its parent as long as it's larger than that parent, until the heap property is restored. Each swap is a genuine placement change — physically relocating values within the contiguous array — costing at most O(log n) swaps, since that's the height of the tree.

    // trace thrrough pop()-Placement+reordering..
    // pq.pop()//removing the max

    /*
        Before: vector=[8,3,5]

        pop_heap:
        1. swap root(index 0) with the LAST element → vector=[5,3,8]
        2. shrink logical heap size by 1 (the old max, 8, is now isolated at the end)
        3. "bubble down" the new root(5): compare with children, swap with larger child if needed
            - 5's children: index1=3, index2=(out of shrunk range)
            - 5 > 3, no swap needed
        vector after pop_heap: [5,3,8]

        c.pop_back(): removes the last element (8) from the vector entirely
        Final vector: [5,3]
    */

    // the push_back() in vector take O(1)..but shifting the last value at right position take logn position...

    // full opertions reference

    // alrady have pq={9,8,5,3,1}..max-heap default.

    pq.push(10);                                                        // O(logn)-placed at back,then bubbled up at correct position
    pq.emplace(6);                                                      // construct in place, then bubbled up
    cout << "top of priority_queue: " << pq.top() << endl;              // 10   // O(1)-always return the 0 index of underlying container..
    pq.pop();                                                           // O(logn)-swap root/last shrink bubble down
    cout << "Check is p.queue is emoty or not: " << pq.empty() << endl; // O(1)
    cout << "return the size of p queue " << pq.size() << endl;         // O(1)

    // not changing the comparator,Not the placement startegy

    // for min heap..just make new priority queue for min at top..

    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(8);
    minpq.push(0);
    minpq.push(3);
    cout << "topmost value in minpq: " << minpq.top() << endl; // 0

    // Important placement point: switching to a min-heap doesn't change how elements are placed (still an array-based implicit binary tree, still bubble-up/bubble-down) — it only flips the comparison direction used during those placement operations. The underlying algorithm and memory layout strategy is identical; only the ordering criterion changes.

    // also custome comparator for pair...do it later

    // No iterators-same restruction philosophy as stack/queue

    // Why O(log n), specifically: The height of a complete binary tree with n nodes is ⌈log₂(n+1)⌉ — since the tree is always kept perfectly balanced (a direct consequence of always filling the array left-to-right, level-by-level), both bubble-up and bubble-down touch at most O(log n) elements.

    // what is st::map?

    // std::map<K,V> stores key-value pairs automatically kept in sorted order ny key..unlike stack/queue/priority_queue(whuch is container)..map is genuine standalone container-it owns it own memory structure directly: a self balancing binary search tree,almost universally implemented as red-black tree..

    // standalone containers are container is a complete data structure that manages its own collection of elements, rather than being dependent on another container.

    // those adapter..only refer to memory that someone else owns..

    // A container that independently manages a collection of elements and their storage/lifetime, rather than merely providing a view into someone else's memory.

    // for that #include<map>

    // map<string, int> m;
    // m["apple"] = 5;
    // m["banana"] = 3;

    // Placement point of view-Node based not contigous..

    // This is the fundamental placement diff from evrything..we've covered sp far(vector,deque's chunks,or the heap's flat array):map places every key-value pair in itws own separatelu heap allocated node,scattered wherever the allcator puts them -connected entirely through pointers,exactly like list,but with three pointer per node instead of two...

    // internaly working like
    /*

        struct Node {
        pair<const K, V> data;   // the actual key-value pair
        Node* left;
        Node* right;
        Node* parent;              // needed for efficient in-order traversal and rebalancing
        Color color;                  // red or black — used for self-balancing (Red-Black Tree specific)
    };

    */

    // visualizing the placement
    // map<int, string> m;
    // m[5] = "five"; m[3] = "three"; m[8] = "eight"; m[1] = "one"; m[4] = "four";

    // physically,these nodes are scattered across the heap-but the pointer structure they form looks like this:

    /*
        [5,"five"]  (root, likely BLACK)
               /            \
        [3,"three"]        [8,"eight"]
        /        \
   [1,"one"]   [4,"four"]
    */

    // Each node's placement in raw memory could be anywhere — 0x7f001000, 0x7f003a20, 0x7f00ff10, wherever new happened to find space — but the logical structure (sorted, navigable, balanced) is entirely maintained through left/right/parent pointers, not physical adjacency.

    // In this we are used Balanced BST,specificaly RED-BLACK tree? do it later..

    // Insertion-Placement Trace through

    // lets create a new map

    // map<int, string> m;
    // m[5] = "five";

    // new allocats a fresh node somewhere on the heap-plcacement determined entirely by the allcator,unrelated to value 5..

    // since the tree is empty.this node becomes the root,colored balck..

    // m[3] = "three";

    // new node allocated at some(different,likely non-adjacent) heap address...
    // Tree traversal: 3<5->go left child of root is empty->place the new node there, linking root->left=newNode and newNode->parent=root.

    // color the new node red(standered red-black insertion rule),then check if any rebalancing rules are voiled-if so perform roatations..

    // do this later..

    // FUll operation references
    // Insertion

    map<string, int> m;

    m["apple"] = 5;                 // O(logn)-insertion or update via operator
    m.insert({"banana", 3});        // O(logn)-insertion(does nothing if key exists!!)
    m.emplace("cherry", 7);         // O(logn) construct node in place,avoids a temporary pair...
    m.insert(make_pair("date", 2)); // same insert,explicit make pair..

    // critical gotcha with []

    // m["nonexistent"]; // This not for finding the elem..It INSERT "nonexistent" with default value (0) as a SIDE effect of just reading!!

    // this means merely checking a key with[] silently create a new node-a genuine,physical placement of new element youd didnt intend to add.Always use find() or count() for existence checks,never[]

    // Access
    m["apple"]; // O(logn)-access or insert with default

    m.at("apple"); // O(logn) access, throws:out_of_range if missing(no accidental insertion)

    auto it_m = m.find("apple"); // O(logn)-return iterator, or m.end() if not found

    if (it_m != m.end())
    {
        cout << it_m->second << endl;
    }

    m.count("apple"); // O(logn)-1 if present,0 if not present(map has unique keys,so never more than 1)

    // deletion

    m.erase("apple"); // O(logn)- reomves by key;deallocates that node,rewire surrounding pointers
    // m.erase(it_m);    // O(logn) amortized-remove  by iterator(slightly faster,skips the search)

    // m.erase(it1,it2);//O(range size)-erasea a range

    // m.clear() //O(n)-destroys every node..

    // Range Queries-Where Tree placement really shines

    map<int, int> m2 = {{1, 10}, {3, 30}, {5, 50}, {7, 70}};
    m2.lower_bound(4); // O(logn)-return iterator to first key >=4->pointing to {5,50}

    m2.upper_bound(4); // O(logn)-iterator to first key >4 ->points to {5,50};

    m2.equal_range(5); // O(logn)-pair of iterators bounding all entries ==5(at most 1,since map has unique keys)

    // Why O(log n), specifically: These operations perform essentially the same tree-descent as a search — at each node, decide "go left" or "go right" based on comparing the target to the current node's key, tracking the best candidate seen so far. Since tree height is O(log n), so is this walk.

    // Iteration - Always sorted,via In Order Traversal

    // for (auto &[a, b] : m)
    // {
    //     cout << a << " " << b << endl;
    // }

    // Placement mechanics of iteration: Incrementing a map iterator (it++) doesn't move through contiguous memory (there is none) — it performs a specific in-order successor pointer-walk: if there's a right child, go right once then left as far as possible; otherwise, walk up via pareg++ -g -fsanitize=address,undefined -fno-omit-frame-pointer lec1.cpp -o lec1nt pointers until you move up from a left-child link. This guarantees visiting nodes in sorted key order despite their scattered physical placement — a beautiful example of logical order being entirely decoupled from physical memory order.

    // auto it = m.begin();   // leftmost node — smallest key
    //  auto it2 = m.rbegin();  // rightmost node — largest key

    /*
    Why Cache Locality Is Worse Than vector (Even Though Both Are O(log n) Territory Doesn't Apply to Vector Search)

    This connects directly to earlier discussions: since every node is a separate heap allocation, consecutive logical elements (in sorted order) are very likely scattered across unrelated memory addresses. Iterating a map in full is O(n) — same big-O as iterating a vector — but with a much larger constant factor in practice, because each it++ likely causes a cache miss (jumping to a new, unpredictable memory location), whereas vector iteration reads through predictable, contiguous, prefetchable memory.

    vector<pair<int,int>> — iteration: cache-friendly
    [e1][e2][e3][e4][e5]   ← sequential memory addresses, CPU prefetches ahead

    map<int,int> — iteration: cache-unfriendly
    [e3]......[e1]....[e5].[e2].......[e4]   ← scattered, pointer-chase required, hard to prefetch
    */

    // what is multi-map and unordered_map?

    // Multi-map?
    // std::multimao<V,K> is almost identical to map..with exactly one difference:duplicate keys are allowed.Multiple key value pairs can share the same keys and they re all kept,sorted together by key..

    /*
        multimap<string,int> mm;
        mm.insert({"apple",5});
        mm.insert({"apple",10});//both entries coexist!

    */

    // What is STL algorithms-complete guide(sort,min,max and More)

    // What are algorithms?
    // STL algorithms are genric,templated function in <algoritms>(and <numeric> for numeric ones) that operates on container through iteratiors,not through the container type container itself.This is the core design philosophy of STL:an algorithms like sort doesnt know or care whether its sorting vectorm,an array or raw c string array-it only need iterators that support the operation it require(random accecc,bidirectional etc)..

    // for that #include <algorithm>
    // for #include<numeric>

    // The Sorting Algorithms

    // sort()-The workhorse

    vector<int> vs = {5, 3, 2, 1, 9, 8};
    // sort the linear sequence

    sort(vs.begin(), vs.end()); // for ascending:

    for (int val : vs)
        cout << val << " ";
    cout << endl;
    sort(vs.begin(), vs.end(), greater<int>()); // for deascending
    for (int val : vs)
        cout << val << " ";
    cout << endl;

    // greater<int>() is compartor for deascending the order...

    // also custome comparator
    sort(vs.begin(), vs.end(), [](int a, int b)
         { return a < b; });
    for (int val : vs)
        cout << val << " ";
    cout << endl;

    // require random-access iterators-this is why sort() works vector,deque,array but not on list(must use list::sort) instead, as we coverd earlier..

    // TC: is typical introsort-a hybrid of quickSort,heapsort and insertion sort...

    // Time: O(n log n) worst case (guaranteed, unlike plain Quicksort)

    // Space: O(log n) — recursion stack..

    // also sorting a vector of pairs(connects to earlier pair discussion)

    vector<pair<int, int>> vp = {{3, 1}, {1, 5}, {1, 2}};
    sort(v.begin(), v.end());

    for (auto val : vp)
    {
        cout << '{' << val.first << ',' << val.second << "} ";
    }
    cout << endl;

    // sorting by lexicographical by first,then second.if tie..

    // stable_sort()-Preserve relative order of equal elements..
    // If two elements have the same sorting key, their original relative order is preserved after sorting...

    // Unlike sort(), stable_sort() guarantees elements that compare equal retain their original relative order. This matters when sorting by one field while wanting ties broken by "whoever came first originally" — connects directly to our earlier merge sort stability discussion.

    vector<pair<string, int>> vps = {{"Aakash", 80}, {"Rahul", 90}, {"Rohan", 80}, {"Amit", 90}};

    // stable_sort(vps.begin(), vps.end(), [](auto &a, auto &b)
    //             { return a.second < b.second; });

    // we know that..In custome comparator we using the two value from array [](auto &a,auto &b){return camparison}..

    // for (auto &[a, b] : vps)
    // {
    //     cout << '{' << a << ',' << b << "} ";
    // }
    // cout << endl;

    /*
        |                                   | `sort()`         | `stable_sort()`      |
        | --------------------------------- | ---------------- | -------------------- |
        | Sorts elements                    | ✅                | ✅                   |
        | Preserves order of equal elements | ❌ Not guaranteed | ✅ Guaranteed        |
        | Typical complexity                | `O(n log n)`     | `O(n log n)`         |
        | Extra memory                      | Usually less     | Can use extra memory |

    */

    // TC: O(nlogn) always -internally used merge sort(need O(n) extra space) rather than introsort spceificallu cause merge sory is naturallyh stable...

    // partial_sort() --only sort the first K elements..

    // complexity: O(nlogk)-much faster than fully sorting when only need the top/bottom k element,eg "find the 3 smallest value" without caring about the rest'order..

    // find the top 3 bottom value..and also top 3 value..

    partial_sort(vs.begin(), vs.begin() + 3, v.end());
    for (int val : vs)
        cout << val << " ";
    cout << endl;

    // nth element()-parition around the kth element(Quickselect)..
    // Is a algorrithm used when you want to find the element that would be at particular position if the range were sorted,but you dont need the entire range sorted..

    // Very important: nth means index, not "nth value"

    vector<int> vs1 = {7, 2, 9, 4, 1, 5, 8};
    // wana sorted array's 4 elem(3 index)
    nth_element(vs1.begin(), vs1.begin() + 3, vs1.end());
    cout << vs1[3] << endl; // it would be return 5..why 5? it we completely sorted array..1 2 4 5 7 8 9..so the element that belong at index 3 is 5..

    // nth_element makes sure that v[3] is 5..

    // but there is important part that...nth_element..the vector is not necessarily completely sorted...you might be get something like: 2 1 4 5(3 index) 7 9 8

    // Every element on LEFT  <= 5
    // Every element on RIGHT >= 5

    // but the left and right sides themselves dont need to be sorted..

    // why this is useful?
    // when you want the 3rd smallest element..instead od storing the whole array..

    // nth_element() has avg O(n) complexity..that's much faster than sorting the entire array when you only need one position..

    // find the kth smallest in sorted array..efficiently..A good answer is:

    // Kth largest, using nth_element (average O(n), beats priority_queue's O(n log k))
    // int findKthLargest(vector<int>& nums, int k) {
    //     nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    //     return nums[k - 1];
    // }

    // is_sorted()-check if already sorted
    // is_sorted(v.begin(),v.end()); //true-O(n)

    // for busError or trap error...scaning the whole code with Ascanmemory..
    // using the AddressSanitizer..

    return 0;
}