#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){

    int m=1;
    for (int i=0; i<b; i++){

        m*=a;
    }
    return m;
}

int main()
{
    int inp;

    cin>>inp;

    cout<<power(inp,2);     //Here 2 means, power of the input.


    return 0;
}

