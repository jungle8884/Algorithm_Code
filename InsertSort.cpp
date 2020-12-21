#include <cstdio>

void InsertSort(int n, int A[]){
	for(int i = 1; i < n; i++){ 
		int temp = A[i], j = i;
		while(j > 0 && temp < A[j-1]){ 
			A[j] = A[j-1]; 
			j--;
		}
		A[j] = temp; 
	}
}

int main(){
	int a[6] = {5, 2, 4, 6, 3, 1};
	InsertSort(6, a);
	for(int i = 0; i < 6; i++){
		printf("%d\t", a[i]);
	}
	
	return 0;
}
