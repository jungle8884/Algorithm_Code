#include <cstdio> 

void BubbleSort(int n, int arry[]){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i; j++){
			if(arry[j] > arry[j+1]){
				int temp = arry[j];
				arry[j] = arry[j+1];
				arry[j+1] = temp;
			}
		}
	}
}

int main(){
	int a[5] = {3, 1, 4, 5, 2};
	BubbleSort(5, a);
	for(int i = 0; i < 5; i++){
		printf("%d\t", a[i]);
	}
	
	return 0;
}


