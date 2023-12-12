// leetcode.com MEDIUM
//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

//Example 1:
//Input: n = 3
//Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
//Example 2 :
//    Input : n = 1
//    Output : ["()"]
//    Constraints :
//    1 <= n <= 8

//my recursion solution

#include <iostream>
#include <vector>

using namespace std;

void printV (vector<string> str){
    for(int i=0; i<str.size();i++)
        cout << str[i] << " ";
}

class Solution {
public:
    vector<string> RESC;
    int size;
    int length;
    vector<string> generateParenthesisC(int n) {
        char str[18];// = (char*)malloc(sizeof(char) * 6);
        RESC.clear();
        size=n;
        length=size*2; 
        FstrC(str, 0, 0, 0);
        return RESC;
    }
    void FstrC(char* str, int i, int l, int r) {
        char strN[18];
        strN[length] = '\0';

        memccpy(strN, str, length, length);
        if (i < length) {
            if (l < size && l >= r) {
                strN[i] = '(';
                FstrC(strN, i + 1, l + 1, r);

            }
            if (l > r) {
                strN[i] = ')';
                FstrC(strN, i + 1, l, r + 1);
            }

        }
        if (r == size && l == size)
            RESC.push_back(strN);
    }

};



int main()
{
    
    vector<string> AllRES;
    //printV(V);
 //   AllRES = generateParenthesis(3);
  //  printV(AllRES);

    Solution S;
    int i=1;
    cout << "ENTER numbers of breakets: ";
    cin>>i;
    AllRES = S.generateParenthesisC(i);
    cout << "Result = ";
    printV(AllRES);

    cout << "Bye bye\n";
}