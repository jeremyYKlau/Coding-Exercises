#include <bits/stdc++.h>
#include <stack>

using namespace std; //Just to shorten cout cut if namespace is viewed as bad practice

/*The idea behind this method is to use a stack which is a first in first out structure to ensure the order of
brackets is maintained properly. This can be done by just testing the top of the stack because we know the
order the brackets must appear in.*/

string isBalanced(string s) {
	//initialize stack
    stack <char> st; 
	//with this implenetation helps in the case of empty string or segmentationtation faults when testing
    st.push('@'); 
	//go through the entire string passed
    for(int i=0;i<s.length();i++)
    {
		//if any leading brackets push to the top of the stack
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        st.push(s[i]);
		//if closing brackets check to make sure the top of stack matches and isn't empty
        else if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]==']'&& st.top()=='[') ||(s[i]=='}' &&st.top()=='{')))
        {
			//if a match is found pop the top character which should be the leading bracket
            st.pop();
        }
        else{
			//else break the loop and return no
            return "NO";
        }
    }
	//if the stack contains only the initialize character return YES else return NO
    if(st.top()=='@'){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(){ //Driver program with 4 test cases
	string test1 = "({[]})";
	string test2 = "{[{})}";
	string test3 = "{[](})";
	string test4 = "({}[])";
	
	isBalanced(test1);
	isBalanced(test2);
	isBalanced(test3);
	isBalanced(test4);
}

