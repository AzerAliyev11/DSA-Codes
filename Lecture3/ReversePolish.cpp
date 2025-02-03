#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    if(s[s.size()-1] != ' ')
        s += " ";

    string sym = "";

    stack<int> st;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            sym += s[i];
        }
        else
        {
            if(sym == "+" || sym == "-" || sym == "*" || sym == "/")
            {
                int firstNum = st.top();
                st.pop();
                int secondNum = st.top();
                st.pop();

                if(sym == "+")
                {
                    st.push(secondNum + firstNum);
                }
                else if(sym == "-")
                {
                    st.push(secondNum - firstNum);
                }
                else if(sym == "*")
                {
                    st.push(secondNum * firstNum);
                }
                else
                {
                    st.push(secondNum / firstNum);
                }
            }
            else
            {
                int num = stoi(sym);
                st.push(num);
            }

            sym.clear();
        }
    }

    cout<<st.top()<<endl;
}