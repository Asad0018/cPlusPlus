#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Inputs an integer:
int GetInt()
{
    cout << "Enter an integer number: ";
    int n; cin >> n; return n;
}

// Inputs an array of doubles:
vector<double> GetDoubles() 
{
    double size;
    cout << "How many numbers do you wanna enter? ";
    cin >> size;
    vector<double> arr(size);

    cout << "Enter " << size << " numbers:\n";
    for (double i = 0; i < size; ++i)
        cin >> arr[i];
    return arr;
}

// Inputs a string:
string GetString()
{
    cout << "Enter a string: ";
    string s;
    cin.ignore(); getline(cin, s); 
    return s;
}

// Average:
double Average( vector<double> nums = GetDoubles())
{
    double sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum = sum + nums[i];
    return sum / nums.size();
}

// Outputs a list of prime numbers until n:
void PrimeList(int n = GetInt())
{
    for (int i = 2; i <= n; i++)
    {
        int j = i;
        do
        {
            if (j == 2)
                cout << i << ",";
            j--;
        } while (i % j != 0 && j > 1);
    }
}

// Minimum number:
double Min( vector<double> nums = GetDoubles()) 
{
    double min = INFINITY;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] < min)
            min = nums[i];
    return min;
}

// Maximum number:
double Max(vector<double> nums = GetDoubles())
{
    double max = -INFINITY;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] > max)
            max = nums[i];
    return max;
}

// Factorial:
int Factorial(int n = GetInt())
{
    double f = 1;
    for (n; n > 0; n--)
        f *= n;
    return f;
}

// Fibonacci:
int Fibonacci()
{
    cout << "enter a number\n";
    int f1 = 0, f2 = 1, n; cin >> n;
    cout << f1 << "," << f2;
    for (int i = 2; i < n; i++)
    {
        int f3 = f1 + f2; f1 = f2; f2 = f3;
        cout << "," << f3;
    }
    return 0;
}

// Checks if the number is prime or not (true/false):
bool CheckPrime(int n = GetInt())
{
    bool result = false;
    for (int i = 2; i < n; i++)
        if (n == i)
        {
            result = true;
            break;
        }
    return result;
}

// ب.م.م:
int BMM(int n1 = GetInt(), int n2 = GetInt())
{
    int BMM;
    for (int i = n2; true; i--)
        if (n1 % i == 0 && n2 % i == 0)
        {
            BMM = i;
            break;
        }
    return BMM;
}

// Multiplication table:
void MultiplicationTable(int n = GetInt())
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
            cout << i * j << ",";
        cout << "\n";
    }
}

//12. ++ + ...
void Plus(int n = GetInt())
{
    for (int j = 1; j <= n; j++)
    {
        cout << "\n";
        for (int i = 1; i <= j; i++)
            cout << "+";
        cout << "\n";
    }
}

// Sorts an array of doubles:
vector<double> Sort(vector<double> nums)
{
    double iMin = 0;
    vector<double> arranged(nums.size());
    for (int j = 0; j < nums.size(); j++)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < nums[iMin])
                iMin = i;
        arranged[j] = nums[iMin];
        nums[iMin] = INFINITY;
    }
    return arranged;
}

// If the number is even, *2 . otherwise /2 :
double CheckEO(int n = GetInt())
{
    double result = (n % 2 == 0) ? n * 2 : static_cast<double>(n) / 2;
    return result;
}

// Reverse the string:
string ReverseStr(string s = GetString())
{
    string r;
    for (int i = s.size() - 1; i >= 0; i--)
        r += s[i];
    return r;
}

int main()
{
    cout << "I can do these things for you. Choose the number of your option:\n\n";
    cout << "1. Find the minimum number\n";
    cout << "2. Find the maximum number\n";
    cout << "3. Sort numbers\n";
    cout << "4. Calculate the average\n";
    cout << "5. Calculate the factorial\n";
    cout << "6. Check if the number is prime or not\n";
    cout << "7. Calculate the B.M.M of two numbers\n";
    cout << "8. Show the multiplication table with the n length and width\n";
    cout << "9. n terms of the fibonacci sequence \n";
    cout << "10. Reverse a string\n";
    cout << "11. Show a list of prime numbers until n\n";
    cout << "12. If the number is even, *2 . otherwise /2\n";
    cout << "\nYour option: ";
    int option; 
    while (true)
    {
        cin >> option;
        
        switch (option)
        {
            case 1:
                cout << "The minimum number: " << Min();
                break;
            case 2:
                cout << "The maximum number: " << Max();
                break;
            case 3:
            {
                vector<double> nums = GetDoubles();
                vector<double> sorted(Sort(nums));
                cout << "Sorted numbers: ";
                for (int i = 0; i < sorted.size(); i++)
                    cout << sorted[i] << ",";
                break;
            }
            case 4:
                cout << "Average: " << Average();
                break;
            case 5:
                cout << "Factorial: " << Factorial();
                break;
            case 6:
                if (CheckPrime())
                    cout << "It's Prime";
                else
                    cout << "Not Prime";
                break;
            case 7:
                cout << "B.M.M : " << BMM();
                break;
            case 8:
                MultiplicationTable();
                break;
            case 9:
                Fibonacci();
                break;
            case 10:
            {
                cout << "Reversed string: " << ReverseStr();
                break;
            }
            case 11:
                PrimeList();
                break;
            case 12:
                cout << "Result: " << CheckEO();
                break;
            default: 
                cout << "invalid input!! Choose a numer between 1 and 12.\n";
                break;
        }
        if (option <= 12 && option >= 1)
            break;
    }
    return 0;
}
