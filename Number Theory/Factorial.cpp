#include <bits/stdc++.h>
using namespace std;

void fact(int f){

        int carry=1;

        for(int i=1;i<=f;i++){

        carry=carry*i;
        }
        cout<<carry<<endl;

}

int main()
{
    int inp;

    cin>>inp;
    fact(inp);


    return 0;
}

