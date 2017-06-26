#include<iostream>

using namespace std;

void quickSort(int*,int);
void quickSortRecursive(int*,int,int);

void quickSort(int* array,int length){
    quickSortRecursive(array,0,length-1);
}

void quickSortRecursive(int* array,int left,int right){
    if(left >= right)
        return ;

    int i=left,j=right,flag=array[left],tmp;
    while(i<j){
        while(i<j && array[j]>=flag)
            j--;
        if(i<j)
            array[i] = array[j];

        while(i<j && array[i]<=flag)
            i++;
        if(i<j)
            array[j] = array[i];
    }
    array[i] = flag;

    quickSortRecursive(array,left,i-1);
    quickSortRecursive(array,i+1,right);
}

int main(){
    int a[5] = {1,1,1,2,1};

    quickSort(a,5);

    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;

    return 0;
}
