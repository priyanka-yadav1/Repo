#include <iostream>
using namespace std;

char  s[100001];
int top;


void push(char var) 
{
    if(top == 100000)
    {
        //cout<<"OVerflow\n";
        return;
    }
    top++;
    s[top] = var;
    return;
}

char pop() 
{
    return s[top];
}

bool isempty()
{
    if(top == -1)
    return true;
    return false;
}

void print()
{
	cout<<"Stack is: \n";
	for(int i =0;i<=top;i++)
	{
	 cout<<s[i]	<<" ";
	}
	cout<<endl;
}
bool fun_balanced( char *str)
{
    for(int i= 0; str[i]!='\0'; i++)
    {
    		
    	if(str[i] == '[' || str[i] == '{' || str[i]=='(')
    	{
    		push(str[i]);
    		print();
		}
    	
    	else
    	{
    		if(str[i] == ']' && pop()=='[')
			{
				top--;
			}
			else if(str[i] == '}' && pop()=='{')
			{
				top--;
			}		
			else if(str[i] == ')' && pop()=='(')
			{
				top--;
			}	
			else
			return false;
			print();
		}
	
	}
    if(isempty() == false)
    return false;
    else
	return true;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
	    top= -1;
	    char str[100001];
	    str[0]='\0';
	    cin>>str;
	    cout<<"sting is: "<<str<<endl;
	    if(fun_balanced(str)== true)
	    cout<<"balanced\n";
	    else
	    cout<<"not balanced\n";
	    t--;
	}
	return 0;
}
