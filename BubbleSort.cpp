#include <cstdio> 

/*数组作为参数时, 第一维不需要填写长度;
实际调用时也只需要填写数组名;
数组作为参数时, 在函数中对数组元素的修改就等同于是对原数组元素的修改.*/
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


