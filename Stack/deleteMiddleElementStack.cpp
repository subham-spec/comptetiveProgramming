#include <bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> &st, int N){
    stack<int> temp;                    
	int count = 0;

	while(count < N/2){         
		temp.push(st.top());
		st.pop();
		count = count + 1;
	}
	st.pop();                       

	while(!temp.empty()){              
		st.push(temp.top());
		temp.pop();
	}
} 
