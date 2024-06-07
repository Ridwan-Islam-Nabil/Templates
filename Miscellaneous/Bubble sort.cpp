#include <iostream>
using namespace std;

template <typename tmp>

void Bubble_sort(tmp ar[],int len){


        int temp=0;
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len-i-1; j++)
            {
                if(ar[j]>ar[j+1])
                {
                temp=ar[j];
                ar[j]=ar[j+1];     //swapping values
                ar[j+1]=temp;
                }
            }
        }
        for(int i=0; i<len; i++)
        {
            cout<<ar[i]<<" " ;  //printing sorted array
        }
}

int main()
{
        int n,base[1000];

        cin>>n;

        for(int i=0;i<n;i++)
        {                       //taking input in array
            cin>>base[i];
        }
        Bubble_sort(base,n);

    return 0;
}

