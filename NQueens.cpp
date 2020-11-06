#include <cstdio>
#include <cstdlib>

int count = 0;
int step = 0; 
const int maxn = 11;
//PΪ��ǰ����, hashTable��¼����x�Ƿ��Ѿ���P��. 
int n, P[maxn], hashTable[maxn] = {false};

//��ǰ�������еĵ� index λ --> by �ݹ鷨 
void generatePbyRecursive(int index){
	if(index == n+1){ //�ݹ�߽� 
		//�����ǰ����---���� 
		//printf("step: %d: ", ++step);
		//for(int k = 1; k <= n; k++){
		//	printf("%d ", P[k]);  
		//}
		//printf("	count: %d\n", count);
		
		bool flag = true; //flagΪtrue��ʾ��ǰ����Ϊһ���Ϸ����� 
		//�������������ʺ�, ��ǰ���еĺϷ������� 
		for(int i = 1; i <= n; i++){  
			for(int j = i+1; j <= n; j++){
				if(abs(i - j) == abs(P[i] - P[j])){ //�����һ���Խ����� 
					flag = false; //���Ϸ� 
				}
			} 
		} 
		if(flag) count++;
		return;
	}
	
	//���赱ǰ�Ѿ������ P[1]~P[index-1], ��׼���� P[index] 
	for(int x = 1; x <= n; x++){ //��Ȼ��Ҫö��1~n, ��ͼ��x����P[index]		 
		if(hashTable[x] == false){ //���x����P[1]~P[index-1]�� 
			P[index] = x; //��P�ĵ�indexλΪx, ����x���뵱ǰ���� 
			hashTable[x] = true; //��x����P�� 
			generatePbyRecursive(index + 1); //�������еĵ�index+1��λ 
			hashTable[x] = false; //�Ѵ�����P[index]Ϊx��������, ��ԭ״̬ 
		} 
	}
}

// --> by ���ݷ� 
void generatePbyBack(int index){
	if(index == n+1){ //�ݹ�߽� 
		count++; //�ܴﵽ�����һ���ǺϷ���. 
		return;
	} 
	for(int x = 1; x <= n; x++){ //��x�� 
		if(hashTable[x] == false){ //��x�л�û�лʺ� 
			bool flag = true; //flagΪtrue��ʾ��ǰ�ʺ󲻻��֮ǰ�Ļʺ��ͻ 
			for(int pre = 1; pre < index; pre++){
				//��index�лʺ���к�Ϊx, ��pre�лʺ���к�ΪP[pre] 
				if(abs(index - pre) == abs(x - P[pre])){
					flag = false; //��֮ǰ�Ļʺ���һ���Խ�����, ��ͻ 
					break; 
				} 
			} 
			if(flag){ //������԰ѻʺ���ڵ�x�� 
				P[index] = x; //���index�лʺ���к�Ϊx
				hashTable[x] = true; //��x���ѱ�ռ�� 
				generatePbyBack(index + 1); //�ݹ鴦���index+1�лʺ� 
				hashTable[x] = false; //�ݹ����, ��ԭ��x��Ϊδ��ռ�� 
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
