#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//Taken from the hackerRank question 
//https://www.hackerrank.com/challenges/simple-text-editor/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
//When converting to java or other languages note that the stack has different method calls that must be changed
//If converting into a method call multiple ways to approach
//A possibly unappealing way I would do would be to make a different method for appending, erasing, printing and undoing

int main() { 
    int n;
    stack<string> stk;
    string st;
    cin>>n;
    
    while(n--){
        cin>>n;
        //input or append
        if(n==1){
            string str;
            cin>>str;
            
            //push the previous string to the stack for use in undo
            stk.push(st);
            st+=str;
        }
        //erase the last k characters
        else if(n==2){
            int k;
            cin>>k;
            
            //push the previous string to the stack for use in undo
            stk.push(st);
            st.erase(st.size()-k);
        }
        //print out the k'th element in the string
        else if(n==3){
            int k;
            cin>>k;
            cout<<st[k-1]<<endl;
        }
        //undo
        //this is implemented using a stack so we can pop the most recent string mimicing an undo
        else{
            st = stk.top();
            stk.pop();
        }
    }
    return 0;
}