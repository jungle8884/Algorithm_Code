#include <cstdio>
#include <cstring>

const int maxn = 256;

//�ж��ַ���str�Ƿ��� "���Ĵ�".
bool judge(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len / 2; i++){ //i ö���ַ�����ǰһ�� 
		if(str[i] != str[len-1-i]){ //����Գ�λ�ò�ͬ 
			return false; 
		} 
	}
	
	return true;
} 

int main(){
	char str[maxn];
	/*
	gets()������STDIN(��׼����)��ȡ�ַ��������Ǽ��ص�str(�ַ���)��,	ֱ����������(\n)�򵽴�EOF. 
	�����ַ�����Ϊһ��null�жϷ�. 
	gets()�ķ���ֵ�Ƕ�����ַ���,������󷵻�NULL. 
	*/
	while(gets(str)){ //�����ַ��� 
		bool flag = judge(str); //�ж��ַ��� str �Ƿ��� "���Ĵ�".
		if(flag == true){ //"���Ĵ�"
			printf("YES\n");
		} else{ //���� "���Ĵ�" 
			printf("NO\n"); 
		} 
	}
	
	return 0;
}
