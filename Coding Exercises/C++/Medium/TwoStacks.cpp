#include <bits/stdc++.h> 
#include <iostream>
#include <vector>

using namespace std;

//problem linked from hackerrank https://www.hackerrank.com/challenges/game-of-two-stacks/problem
//To summarize the goal is to remove integers from the stacks while not going above the value x

//vectors a and b although this easily can be worked into stacks
//x is the value one cannot go over
int twoStacks(int x, vector<int> a, vector<int> b) {
    
    int sum=0,count=0,temp=0,i=0,j=0;        
    
    //considering only the first stack/vector while calculating the count
    while(i<a.size()&&sum+a[i]<=x){
        sum+=a[i];
        i++;
    }
    count = i;
    
    //add one element from second stack/vector at a time and subtract the top element of the first stack/vector to calculate count 
    while(j<b.size()&&i>=0){
        sum+=b[j];
        j++;
        //if the sum is greater than x and we still have elements from stack one remove the sum of element i from stack 1 until sum is not greater than x
        while(sum>x&&i>0){
            i--;
            sum-=a[i];
        }
        //if the result of taking elements from stack 1 and adding them with stack 2 is less than x and greater than the current count take current count as new max count
        if(sum<=x&&i+j>count){
            count = i+j;
        }
    }
    return count;
}

int main() {
  
  //in this example the max number of ints that can be removed is 4
  //4(stack1),2(stack2),1(stack2),2(stack1)
  int x = 10;
  vector<int> a{4, 2, 4, 6, 1};
  vector<int> b{2, 1, 8, 5};

  int result = twoStacks(x, a, b);

  cout << result << "\n";
}