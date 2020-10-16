#include <cstdio>
#include <cstdlib>

int index = 0; //p������x ��ʮ���������ʾ����λ��. 

// �� p������x ת��Ϊ ʮ������y. 
int P2DEC(int x, int p){ //x ���� p(1 <= p <= 10)������, ��ʮ���Ƶ���������ʾ. 
	int y = 0, product = 1;
	while(x != 0){
		y += (x % 10) * product; //X % 10 ��Ϊ��ÿ�λ�ȡx�ĸ�λ�� 
		x /= 10; //ȥ��x�ĸ�λ
		product *= p; 
	}
	
	return y;
}

// �� ʮ������y ת��Ϊ p(1 <= p <= 10)������x, x��ʮ���Ƶ���������ʾ.
void DEC2P(int y, int p, int* x){
	//����x ��� p������y ��ÿһλ, indexΪλ��.
	do{ //����ȡ�� 
		x[index++] = y % p;
		y /= p; 
	} while(y != 0);	
	
	return;
}

int main(){
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	
	int x_dec, x = 0;
	
	int sum = a + b; 
	int ans[31], num = 0; //ans���D���Ƶ�ÿһλ
	
	DEC2P(sum, d, ans); //����ת�� 
	
	for(int i = index - 1; i >= 0; i--){ //�Ӹ�λ����λ������� 
		printf("%d", ans[i]);
		
	/*
		//�����������ʽת��Ϊ������ʽ 
		x_dec = 1;
		for(int j = 0; j < i; j++){ //�Ȼ�ȡ��ǰλ����Ȩֵ 
			x_dec *= 10;
		}	
		x += ans[i] * x_dec;
	*/
	}
/*
	printf("\n%d", x); //x ��ʾ ans ��������ʽ 
	printf("\n%d", P2DEC(x, d)); //��x��d����ת��Ϊʮ���Ʋ���� 
*/
	
	return 0;
} 


