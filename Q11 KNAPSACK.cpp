//Write a program to solve the 0-1 knapsack problem

#include <bits/stdc++.h>
using namespace std;

// function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// function to print the weights and values of the items included in the optimal solution
void find_path(int ar[][100], int x, int y, int wt[], int val[])
{
    // base case: if either the row or the column is 0, return
    if (x == 0 || y == 0)
    {
        return;
    }
    // if the value in the cell above is the same, recursively call find_path on the cell above
    else if (ar[x - 1][y] == ar[x][y])
    {
        find_path(ar, x - 1, y, wt, val);
    }
    // otherwise, recursively call find_path on the cell above and to the left, and print the weight and value of the item
    else
    {
        find_path(ar, x - 1, y - wt[x - 1], wt, val);
        cout << wt[x - 1] << "\t" << val[x - 1] << endl;
    }
}

// function to solve the knapsack problem
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    // create a 2D array to store the maximum value that can be obtained for all possible combinations of items and weights
    int K[n + 1][100];

    // fill in the array using dynamic programming
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            // base case: if either the number of items or the weight is 0, the maximum value is 0
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // if the weight of the current item is less than or equal to the remaining weight, choose whether to include the item or not
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            // if the weight of the current item is greater than the remaining weight, exclude the item
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // print the weights and values of the items included in the optimal solution
    cout << "\nWeights and values that are included in optimal solution:-\n\nWeight\tValue\n-------\t------\n";
    find_path(K, n, W, wt, val);

    // return the maximum value that can be obtained
    return K[n][W];
}

int main()
{

    // input the number of items, their weights, and their values
    cout << "\nEnter the numbers of inputs: ";
    int n, W;
    cin >> n;
    int *val = new int[n];
    int *wt = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight and value of " << i + 1 << " : ";
        cin >> wt[i] >> val[i];
    }

    // input the maximum weight that can be carried
    cout<<"\nEnter the maximum weight to be taken: ";
	cin>>W;
     
    cout<<"\nThe maximum value for given weights will be: "<< knapSack(W, wt, val, n);
     
    return 0;
}

