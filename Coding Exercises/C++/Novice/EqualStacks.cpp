#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

/*The idea of this algorithm is to reverse the vectors and create new vectors out of them 
each element in the new vector is the sum of all the previous elements
Then reverse again and take the smallest array for smallest traversal
Search elements in the other 2 arrays and if the element exists in the other 2 stop and return the number
*/
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
	//Setting up variables to get the size of the three vectors
    int n1, n2, n3;
    n1 = h1.size();
    n2 = h2.size();
    n3 = h3.size();
	//Reversal of original vector
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    
	//Cumulative sum vectors of the three vectors
    vector<int> h1Cumulative(n1 + 1);
    for (int i = 1; i < n1+1; i++) {
        h1Cumulative[i] += h1[i-1] + h1Cumulative[i-1];
    }

    vector<int> h2Cumulative(n2 + 1);
    for (int k = 1; k < n2 + 1; k++) {
        h2Cumulative[k] += h2[k - 1] + h2Cumulative[k - 1];
    }
    vector<int> h3Cumulative(n3 + 1);
    for (int j = 1; j < n3 + 1; j++) {
        h3Cumulative[j] += h3[j - 1] + h3Cumulative[j - 1];
    }

    reverse(h1Cumulative.begin(), h1Cumulative.end());
    reverse(h2Cumulative.begin(), h2Cumulative.end());
    reverse(h3Cumulative.begin(), h3Cumulative.end());

	//This is required to iterate through the list to get the equal sum instead of more loops
	//It also is required if the sizes of the vectors get too large, iterators definition below 
	//https://www.geeksforgeeks.org/iterators-c-stl/ 
    vector<int>::iterator it1 = h1Cumulative.begin();
    vector<int>::iterator it2 = h2Cumulative.begin();
    vector<int>::iterator it3 = h3Cumulative.begin();

	//Uses above iterators to go through the vectors and do the comparisons
    while(true){
		//Found an equal element in all 3 return it
        if(*it1 == *it2 && *it2 == *it3){
            return *it1;
        }
		//Iterate through the vectors if not equal depending on below conditionals
        if(*it1 >= *it2 && *it1 >= *it3){
            ++it1;
        }
        else if(*it2 >= *it1 && *it2 >= *it3){
            ++it2;
        }
        else if(*it3 >= *it1 && *it3 >= *it2){
            ++it3;
        }
    }
}

//https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/
//This is the stack implementation from geeksforgeeks, it can easily be converted to vectors
//Not my own work just take as reference compared to the above code
int maxSum(int stack1[], int stack2[], int stack3[]) 
{ 
	int sum1 = 0, sum2 = 0, sum3 = 0; 
   
	// Finding the initial sum of stack1. 
	for (int i=0; i < stack1.size(); i++) 
		sum1 += stack1[i]; 
  
	// Finding the initial sum of stack2. 
	for (int i=0; i < stack2.size(); i++) 
		sum2 += stack2[i]; 
  
	// Finding the initial sum of stack3. 
	for (int i=0; i < stack3.size(); i++) 
		sum3 += stack3[i]; 
  
	// As given in question, first element is top 
	// of stack.. 
	int top1 =0, top2 = 0, top3 = 0; 
	int ans = 0; 
	while (1) 
	{ 
		// If any stack is empty 
		if (top1 == stack1.size() || top2 == stack2.size() || top3 == stack3.size()) 
			return 0; 
  
		// If sum of all three stack are equal. 
		if (sum1 == sum2 && sum2 == sum3) 
			return sum1; 
      
		// Finding the stack with maximum sum and  
		// removing its top element. 
		if (sum1 >= sum2 && sum1 >= sum3) 
			sum1 -= stack1[top1++]; 
		else if (sum2 >= sum3 && sum2 >= sum3) 
			sum2 -= stack2[top2++]; 
		else if (sum3 >= sum2 && sum3 >= sum1) 
			sum3 -= stack3[top3++]; 
   } 
} 

int main(){
	//Algorithm driver code
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};
    
    cout << equalStacks(stack1, stack2, stack3) << endl;;

	//Stack implementation driver code
	int stack1[] = { 3, 2, 1, 1, 1 }; 
	int stack2[] = { 4, 3, 2 }; 
	int stack3[] = { 1, 1, 4, 1 }; 
  
	cout << maxSum(stack1, stack2, stack3) << endl; 
	return 0; 
}