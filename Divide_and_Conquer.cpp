#include <cstdio>

const int maxn = 11; 
int n;
int P[maxn]; // P 为当前排列 
bool hashTable[maxn] = {false}; //hashTable记录整数x是否已经在P中 

int F(int n){
	if(n == 0) 
		return 1; //递归边界
	else 
		return F(n-1) * n; //递归式 
}

int Fibonacci(int n){
	if(n == 0 || n == 1) //递归边界
		return 1;
	else 
		return Fibonacci(n-1) + Fibonacci(n-2); //递归式
}

void generateP(int index){
	if(index == n+1){ //递归边界, 已经处理完排列的1~n位 
		printf("	  ");
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]); //输出当前全排列 
		}
		printf("\n");
		return; 
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false; //已经处理完P[index]为x的子问题, 还原状态 
		} 
	}
} 

int main(){
	
	printf("请输入n: ");
	scanf("%d", &n); 
	printf("\n阶乘: %d! = %d\n", n, F(n));
	printf("\n斐波那契数列: Fibonacci(%d) = %d\n", n, Fibonacci(n));
	
	printf("\n%d的全排列:\n", n);
	generateP(1); 
	printf("\n");
	
	return 0;
} 
