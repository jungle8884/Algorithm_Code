#include <cstdio>

const int maxn = 100;
char S[maxn][5], temp[5]; 
int hashTable[26* 526* 526+ 10]; 

/*
����N���ַ���(��ǡ����λ��д��ĸ���),
�ٸ���M����ѯ�ַ���, ��ÿ����ѯ�ַ�����N���ַ����г��ֵĴ���. 
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
	printf("������N, M:");
	scanf("%d%d", &n, &m);
	printf("\n����N���ַ���:"); 
	for(int i = 0; i < n; i++){
		scanf("%s", S[i]);
		int id = hashFunc(S[i], 3); // ���ַ���ת��Ϊ���� 
		hashTable[id]++; // ���ַ����ĳ��ִ�����1 
	}
	printf("\n����M���ַ���:"); 
	for(int i = 0; i < m; i++){
		printf("\n�������%d���ַ���:", i+1);
		scanf("%s", temp);
		int id = hashFunc(temp, 3); // ���ַ���tempת��Ϊ���� 
		printf("%d", hashTable[id]); // ������ַ����ĳ��ִ��� 
	}
	
	return 0;
} 
