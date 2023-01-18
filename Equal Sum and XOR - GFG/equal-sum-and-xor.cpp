//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;
 

int countValues (int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		cout<<countValues(n)<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method */
int countValues (int n)
{
   //Your code here
   int unset = 0;
   
   while(n){
       if(!(n&1))
          unset++;
          
        n=n>>1;
   }
   
   return 1<<unset;
}
 