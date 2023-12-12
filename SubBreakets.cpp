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
void Fstr(char*, int, int, int, int);
void printV(vector<string> RES) {
    for (int i = 0; i < RES.size(); i++) {
        cout << RES[i] << " ";

    }
    cout << endl;
}

vector<string> RES;

vector<string> generateParenthesis(int n) {
    
    string subres;
    char str[10];// = (char*)malloc(sizeof(char) * 6);
    for (int i = 0; i < n*2; i++) 
        str[i] = '!';
    cout << str << " size = " << sizeof(char) * 6 << endl;
    RES.clear();
    Fstr(str, 0, 0, 0, n);
    return RES;
}



void Fstr(char* str, int i, int l, int r, int size) {
    char strN[8];
    strN[size*2] = '\0';
       // Fstr(strN, i+1, count-1, size);
       
    memccpy(strN, str, size*2, size*2);
    cout << "NEW FSTR " << strN  << endl;
    if (i < size*2 ) {
        if (l < size && l>=r ) {
            strN[i] = '(';
            Fstr(strN, i+1, l+1, r,  size);
            
        }
        if (l>r) {
            strN[i] = ')';
            Fstr(strN, i + 1, l, r+1, size);
        }
        
    }
    cout << "back =" << strN << endl;
    if (r == size && l == size)
        RES.push_back(strN);
    
}

class Solution {
public:
    vector<string> RESC;
    vector<string> generateParenthesisC(int n) {
        char str[18];// = (char*)malloc(sizeof(char) * 6);
        RESC.clear();
        FstrC(str, 0, 0, 0, n);
        return RESC;
    }
    void FstrC(char* str, int i, int l, int r, int size) {
        char strN[18];
        strN[size * 2] = '\0';

        memccpy(strN, str, size * 2, size * 2);
        if (i < size * 2) {
            if (l < size && l >= r) {
                strN[i] = '(';
                FstrC(strN, i + 1, l + 1, r, size);

            }
            if (l > r) {
                strN[i] = ')';
                FstrC(strN, i + 1, l, r + 1, size);
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