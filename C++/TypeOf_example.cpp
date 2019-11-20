#include <iostream>
#include <typeof.h>
#include <vector>
using namespace std;

int main()
{

    TypeName _typename;

    vector<int>::iterator itr;

    cout<<_typename.gettypeof(itr)<<endl;
    
    char *str;

    int *inp;

    float *fp;

    double *dp;

    cout << _typename.gettypeof(str) << endl;

    cout << _typename.gettypeof(inp) << endl;

    cout << _typename.gettypeof(fp) << endl;

    cout << _typename.gettypeof(dp) << endl;

    map<int, string> mstr;

   set<string> sS;

   vector<string> vstr;

    cout << _typename.gettypeof(mstr) << endl;

   cout << _typename.gettypeof(sS) << endl; 

     cout << _typename.gettypeof(vstr) << endl;

     float f;

     int n;
     double d;

     char c;

     cout << _typename.gettypeof(n) << endl;

     cout << _typename.gettypeof(f) << endl;

     cout << _typename.gettypeof(d) << endl;

     cout << _typename.gettypeof(c) << endl;     
     return 0;
}
