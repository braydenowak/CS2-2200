//
// Lab_2:
// Maximum Subsequence Sum Problem
// Given (possibly negative) integers A1, A2, . . . , AN, find the maximum value
// 
// The given algorithm uses 3 loops --> O(N^3)
// 
// 1 - Verify the program run in your machine
// 2 - Implement and verify 2 more algorithms:
//     1-Two loops O(N^2)
//     2-One loop O(N)
// 
//  Capture enough runs to verify the execution time is matching the O(n^3), O(n^2) and O(n) per each algorithm
//  Will need to tweak the existing code to capture the running time in an array or equivlent
// 
// 3 - Create a report capturing the follwong items:
// 4 - Consider different values for N, and create random arrays accordingly 
// 5 - Verify the run time of Cubic, Quadratic, and Linear
// 6 - Add snapshots graphs to verify your code execution by capturing the expected vs.actual algorithm output.
// 7 - Discuss Algorithm / function individual operations
// 8 - Uplaod your socurce and program report to CANVAS
// 


#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

/**
 * Cubic maximum subsequence sum algorithm. O(n)
 */
int maxSubSum_Cubic(const vector<int>& a)
{
    int maxSum = 0, thisSum = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i; j < a.size(); ++j)
        {
            thisSum = 0;
            for (int k = i; k <= j; ++k)
            {
                thisSum += a[k];
            }
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}


 /**
  * Quadratic maximum contiguous subsequence sum algorithm. O(n^2)
  */

int maxSubSum_Quadratic( const vector<int> & a )
{
    int maxSum = 0, thisSum = 0;

    for(int i = 0; i < a.size( ); ++i)
    {
        thisSum = 0;
        for(int j = i; j < a.size( ); ++j)
        {
            thisSum += a[j];

            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}

/**
 * Linear maximum subsequence sum algorithm. O(n)
 */

int maxSubSum_Linear(const vector<int>& a)
{
    int maxSum = a[0], thisSum = a[0];

    for (int j = 0; j < a.size(); ++j)
    {
        thisSum = max(a[j], thisSum + a[j]);
        maxSum = max(maxSum, thisSum);
    }

    return maxSum;
}



int main()
{
    vector<signed int> a{ -2, 11, -4, 13, -5, -2 };  //(a1 through a3): 11 + -4 + 13 = 20.

    vector<signed int> arandom{}; 


    int Max_random = 100;
    int maxSum = 0;
    int i;

    Max_random = (Max_random < 1000) ? Max_random : 1000;

    maxSum = maxSubSum_Cubic(a);
    cout << "Cubic maxSubSum: " << maxSum << endl;

    maxSum = maxSubSum_Quadratic(a);
    cout << "Qudaratic maxSubSum: " << maxSum << endl;

    maxSum = maxSubSum_Linear(a);
    cout << "Linear maxSubSum: " << maxSum << endl << endl;

    // seed the random # generator
    srand((unsigned)time(NULL));
    for(int N : {10,50,100,200,500,1000}){
        // fill the array vector with random numbers
        for (i = 0; i < N; i++)
            arandom.push_back(rand()%100-50);

        cout << "N = " << N << endl;
        
        // Cubic:
        auto start = chrono::high_resolution_clock::now();
        maxSum = maxSubSum_Cubic(arandom);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
            cout << "Cubic maxSubSum: " << maxSum << endl;
        cout << "Time: maxSubSum_Cubic: = " << diff.count() << endl << endl;

        // Quadratic:
        start = chrono::high_resolution_clock::now();
        maxSum = maxSubSum_Quadratic(arandom);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Qudaratic maxSubSum: " << maxSum << endl;
        cout << "Time: maxSubSum_Quadratic = " << diff.count() << endl << endl;

        // Linear:
        start = chrono::high_resolution_clock::now();
        maxSum = maxSubSum_Linear(arandom);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Linear maxSubSum: " << maxSum << endl;
        cout << "Time: maxSubSum_Linear = " << diff.count() << endl << endl;
    }
    return 0;
}




