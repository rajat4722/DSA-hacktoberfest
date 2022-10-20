#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;

/*
Matrix chain multiplication(Dynamic programming)
-------------------------------------------------
Time complexity:- O(n^3)
Space complexity:- O(n^2)
*/

int mcm(int* arr,int** dp,int l,int h)
{
    if(l==h)
        return 0;
    else
    {
        if(dp[l][h]!=-1)
            return dp[l][h];
        else
        {
            dp[l][h]=INT_MAX;
            for(int k=l;k<h;k++)
                dp[l][h]=min(dp[l][h],mcm(arr,dp,l,k)+mcm(arr,dp,k+1,h)+arr[l-1]*arr[k]*arr[h]);
        }
        return dp[l][h];
    }
}

int main()
{
    int x;
    cout<<"Enter number of matrices: ";
    cin>>x;
    int n=x+1;
    int* arr=new int[n];
    int** dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n];
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    cout<<"Enter dimentions of matrices: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Minimum number of operations needed for matrix chain multiplication: "<<mcm(arr,dp,1,n-1)<<endl;

    delete [] arr;
    for(int i=0;i<n;i++)
        delete [] dp[i];
    delete [] dp;

    return 0;
}
