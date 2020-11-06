#include <cstdio>

const int maxn = 11;
//PΪ��ǰ����, hashTable��¼����x�Ƿ��Ѿ���P��. 
int n, P[maxn], hashTable[maxn] = {false};

//��ǰ�������еĵ� index λ 
void generateP(int index){
	if(index == n+1){ //�ݹ�߽� 
		for(int i = 1; i<= n; i++){
			printf("%d ", P[i]); //���ȫ���� 
		}	
		printf("\n");
		return; 
	}
	//ö��1~n, ��ͼ��x����P[index]. 
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){ //���x����P[0]~P[index-1]�� 
			P[index] = x; //��P�ĵ�indexλΪx, ����x���뵱ǰ���� 
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
