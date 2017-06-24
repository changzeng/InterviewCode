#include<iostream>

using namespace std;

void merge(int* array,int* array_tmp,int left,int mid,int right){
	int i=left,j=mid+1,index=left;
	// cout<<left<<"  "<<right<<endl;
	while(i<=mid && j<=right){
        //cout<<index<<endl;
		if(array[i] > array[j])
			array_tmp[index++] = array[j++];
		else
			array_tmp[index++] = array[i++];
	}

	while(i <= mid)
		array_tmp[index++] = array[i++];

	while(j <= right)
		array_tmp[index++] = array[j++];

	for(i=left;i<=right;i++){
        array[i] = array_tmp[i];
        // cout<<array[i]<<endl;
	}
}

void mergeSort(int* a1,int* a2,int left,int right){
	if(left >= right)
		return ;

	int mid = (left+right)/2;
	mergeSort(a1,a2,left,mid);
	mergeSort(a1,a2,mid+1,right);

	merge(a1,a2,left,mid,right);
}

int main(){
	int a[5] = {5,4,3,2,1};
	int tmp[5];

    mergeSort(a,tmp,0,4);

	for(int i=0;i<5;i++)
		cout<<a[i]<<endl;

	return 0;
}
