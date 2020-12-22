#include <cstdio>

void SelectSort(int n, int A[]){
	for(int i = 0; i < n; i++){ 
		int k = i;
		for(int j = i; j < n; j++){ 
			if(A[j] < A[k]){
				k = j;
			}
		}
		
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
