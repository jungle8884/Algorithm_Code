#include <cstdio>
// #include <algorithm>
// using namespace std;

void InsertSort(int n, int A[]){
	for(int i = 1; i < n; i++){ //���� n-1 ��
		int temp = A[i], j = i; //temp ��ʱ��� A[i], j �� i ��ʼö��
		while(j > 0 && temp < A[j-1]){ //ֻҪ temp С��ǰһ��Ԫ�� A[j-1] 
			A[j] = A[j-1]; //�� A[j-1} ����һλ�� A[j} 
			j--;
		}
		A[j] = temp; //����λ��Ϊj 
	}
}

int main(){
	int a[6] = {5, 2, 4, 6, 3, 1};
	InsertSort(6, a);
	//sort(a, a+6); //����ֱ��ʹ�� c++ �Դ��ĺ�����������, �ǵü��� #include <algorithm> ��  using namespace std;
	for(int i = 0; i < 6; i++){
		printf("%d\t", a[i]);
	}
	
	return 0;
}
