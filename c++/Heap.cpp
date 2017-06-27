#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void _float(int* array,int pos){
    int value=array[pos];
    while(pos != 1){
        if(array[pos] > array[pos/2]){
            array[pos] = array[pos/2];
            pos /= 2;
        }else
            break;
    }

    array[pos] = value;
}

void insert(int* array,int &length,int value){
    length += 1;
    array[length] = value;
    _float(array,length);
}

void sink(int* array,int pos,int length){
    int value = array[pos];

    while(2*pos <= length){
        pos *= 2;
        if(pos+1 < length && array[pos+1]>array[pos])
            pos += 1;
        if(array[pos] > array[pos/2])
            array[pos/2] = array[pos];
        else
            break;
    }

    array[pos] = value;
}

int main(){
    srand(unsigned(time(0)));

    int array[6]={0,5,1,0,6,1},length=0;
    int heap[6];

    for(int i=1;i<=5;i++){
        insert(heap,length,array[i]);
        for(int i=1;i<=length;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }

    return 0;
}
