#include <cstdio>

const int maxn = 100010; //n, m ������ 10��5�η� 
int hashTable[maxn] = {0};

int main(){
	// ��M��������N�������Ƿ���ֲ�������� 
	int n, m, x;
	printf("������n, m:");
	scanf("%d%d", &n, &m);
	// ͳ�Ƴ��ֵĴ��� 
	printf("\n������n����:"); 
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		hashTable[x]++; // �Կռ任ʱ�� --> ֱ�Ӷ�ַ�� 
	}
	printf("\n������m����:");
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		if(hashTable[x] > 0){
			printf("%d���ֹ�	", x);
			printf("���ִ�����:%d\n", hashTable[x]);
		}else{
			printf("%dδ���ֹ�", x);
		}
	}
	
	return 0; 
}
