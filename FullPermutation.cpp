#include <cstdio>

const int maxn = 11;
//P为当前排列, hashTable记录整数x是否已经在P中. 
int n, P[maxn], hashTable[maxn] = {false};

//当前处理排列的第 index 位 
void generateP(int index){
	if(index == n+1){ //递归边界 
		for(int i = 1; i<= n; i++){
			printf("%d ", P[i]); //输出全排列 
		}	
		printf("\n");
		return; 
	}
	//枚举1~n, 试图将x填入P[index]. 
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){ //如果x不在P[0]~P[index-1]中 
			P[index] = x; //令P的第index位为x, 即把x加入当前排列 
			hashTable[x] = true;
			generateP(index+1); 
			hashTable[x] = false;
		} 
	}
}

int main(){
	n = 3;
	generateP(1);
		
	return 0;
} 
