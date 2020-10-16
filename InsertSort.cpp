#include <cstdio>
// #include <algorithm>
// using namespace std;

void InsertSort(int n, int A[]){
	for(int i = 1; i < n; i++){ //进行 n-1 趟
		int temp = A[i], j = i; //temp 临时存放 A[i], j 从 i 开始枚举
		while(j > 0 && temp < A[j-1]){ //只要 temp 小于前一个元素 A[j-1] 
			A[j] = A[j-1]; //把 A[j-1} 后移一位至 A[j} 
			j--;
		}
		A[j] = temp; //插入位置为j 
	}
}

int main(){
	int a[6] = {5, 2, 4, 6, 3, 1};
	InsertSort(6, a);
	//sort(a, a+6); //可以直接使用 c++ 自带的函数进行排序, 记得加上 #include <algorithm> 和  using namespace std;
	for(int i = 0; i < 6; i++){
		printf("%d\t", a[i]);
	}
	
	return 0;
}
