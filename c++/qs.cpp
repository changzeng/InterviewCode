#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int partition(int* array,int left,int right){
    int flag = array[right];
    int i=left,j=right;

    while(i<j){
        while(i<j && array[i]>=flag)
            i++;
        if(i<j)
            array[j] = array[i];

        while(i<j && array[j]<=flag)
            j--;
        if(i<j)
            array[i] = array[j];
    }
    array[i] = flag;
    return i;
}

int main(){
    srand(unsigned(time(0)));

    int a[5] = {1,2,3,0,0};

    for(int i=0;i<5;i++){
        a[i] = rand()%10;
        cout<<a[i]<<endl;
    }


    int p = partition(a,0,4);
    cout<<p<<endl;
}
