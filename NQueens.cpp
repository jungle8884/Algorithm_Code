#include <cstdio>
#include <cstdlib>

int count = 0;
int step = 0; 
const int maxn = 11;
//P为当前排列, hashTable记录整数x是否已经在P中. 
int n, P[maxn], hashTable[maxn] = {false};

//当前处理排列的第 index 位 --> by 递归法 
void generatePbyRecursive(int index){
	if(index == n+1){ //递归边界 
		//输出当前排列---测试 
		//printf("step: %d: ", ++step);
		//for(int k = 1; k <= n; k++){
		//	printf("%d ", P[k]);  
		//}
		//printf("	count: %d\n", count);
		
		bool flag = true; //flag为true表示当前排列为一个合法方案 
		//遍历任意两个皇后, 求当前排列的合法方案数 
		for(int i = 1; i <= n; i++){  
			for(int j = i+1; j <= n; j++){
				if(abs(i - j) == abs(P[i] - P[j])){ //如果在一条对角线上 
					flag = false; //不合法 
				}
			} 
		} 
		if(flag) count++;
		return;
	}
	
	//假设当前已经填好了 P[1]~P[index-1], 正准备填 P[index] 
	for(int x = 1; x <= n; x++){ //显然需要枚举1~n, 试图将x填入P[index]		 
		if(hashTable[x] == false){ //如果x不在P[1]~P[index-1]中 
			P[index] = x; //令P的第index位为x, 即把x加入当前排列 
			hashTable[x] = true; //记x已在P中 
			generatePbyRecursive(index + 1); //处理排列的第index+1号位 
			hashTable[x] = false; //已处理完P[index]为x的子问题, 还原状态 
		} 
	}
}

// --> by 回溯法 
void generatePbyBack(int index){
	if(index == n+1){ //递归边界 
		count++; //能达到这里的一定是合法的. 
		return;
	} 
	for(int x = 1; x <= n; x++){ //第x行 
		if(hashTable[x] == false){ //第x行还没有皇后 
			bool flag = true; //flag为true表示当前皇后不会和之前的皇后冲突 
			for(int pre = 1; pre < index; pre++){
				//第index列皇后的行号为x, 第pre列皇后的行号为P[pre] 
				if(abs(index - pre) == abs(x - P[pre])){
					flag = false; //与之前的皇后在一条对角线上, 冲突 
					break; 
				} 
			} 
			if(flag){ //如果可以把皇后放在第x行 
				P[index] = x; //令第index列皇后的行号为x
				hashTable[x] = true; //第x行已被占用 
				generatePbyBack(index + 1); //递归处理第index+1行皇后 
				hashTable[x] = false; //递归完毕, 还原第x行为未被占用 
			} 
		} 
	} 
}

int main(){
	n = 8;
	//generatePbyRecursive(1);
	generatePbyBack(1); 
	printf("%d", count); 
	return 0;
}  
