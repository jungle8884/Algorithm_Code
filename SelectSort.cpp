#include <cstdio>

void SelectSort(int n, int A[]){
	for(int i = 0; i < n; i++){ //进行 n 趟操作 
		int k = i;
		for(int j = i; j < n; j++){ //每趟操作找出待排序部分[i, n]中最小的元素. 
			if(A[j] < A[k]){
				k = j;
			}
		}
		//k 是本趟操作中最小元素的 下标, A[k]与 第一个元素A[i]交换. 
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp; 
	}
}

int main(){
	int a[5] = {3, 1, 4, 5, 2};
	SelectSort(5, a);
	for(int i = 0; i < 5; i++){
		printf("%d\t", a[i]);
	}
	
	return 0;
} 
