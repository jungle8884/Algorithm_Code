#include <cstdio>

const int maxn = 100;
char S[maxn][5], temp[5]; 
int hashTable[26* 526* 526+ 10]; 

/*
给出N个字符串(由恰好三位大写字母组成),
再给出M个查询字符串, 问每个查询字符串在N个字符串中出现的次数. 
*/
int hashFunc(char S[], int len){
	int id = 0;
	for(int i = 0; i < len; i++){
		if(S[i] >= 'A' && S[i] < 'Z'){
			id = id * 52 + (S[i] - 'A');
		} 	
	}
	
	return id;
} 


int main(){
	int n, m;
	printf("请输入N, M:");
	scanf("%d%d", &n, &m);
	printf("\n输入N个字符串:"); 
	for(int i = 0; i < n; i++){
		scanf("%s", S[i]);
		int id = hashFunc(S[i], 3); // 将字符串转换为整数 
		hashTable[id]++; // 该字符串的出现次数加1 
	}
	printf("\n输入M个字符串:"); 
	for(int i = 0; i < m; i++){
		printf("\n请输入第%d个字符串:", i+1);
		scanf("%s", temp);
		int id = hashFunc(temp, 3); // 将字符串temp转换为整数 
		printf("%d", hashTable[id]); // 输出该字符串的出现次数 
	}
	
	return 0;
} 
