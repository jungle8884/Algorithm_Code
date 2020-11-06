#include <cstdio>

const int maxn = 11; 
int n;
int P[maxn]; // P Ϊ��ǰ���� 
bool hashTable[maxn] = {false}; //hashTable��¼����x�Ƿ��Ѿ���P�� 

int F(int n){
	if(n == 0) 
		return 1; //�ݹ�߽�
	else 
		return F(n-1) * n; //�ݹ�ʽ 
}

int Fibonacci(int n){
	if(n == 0 || n == 1) //�ݹ�߽�
		return 1;
	else 
		return Fibonacci(n-1) + Fibonacci(n-2); //�ݹ�ʽ
}

void generateP(int index){
	if(index == n+1){ //�ݹ�߽�, �Ѿ����������е�1~nλ 
		printf("	  ");
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]); //�����ǰȫ���� 
		}
		printf("\n");
		return; 
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false; //�Ѿ�������P[index]Ϊx��������, ��ԭ״̬ 
		} 
	}
} 

int main(){
	
	printf("������n: ");
	scanf("%d", &n); 
	printf("\n�׳�: %d! = %d\n", n, F(n));
	printf("\n쳲���������: Fibonacci(%d) = %d\n", n, Fibonacci(n));
	
	printf("\n%d��ȫ����:\n", n);
	generateP(1); 
	printf("\n");
	
	return 0;
} 
