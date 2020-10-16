#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

struct Student {
	char registration_number[15]; //׼��֤��
	int score; //����
	int location_number; //������ 
	int local_rank; //���������� 
	int final_rank; //������ 
}stu[30010]; 

bool cmp(Student a, Student b){
	if (a.score != b.score)  
		return a.score > b.score; //�Ȱ������Ӹߵ��ͽ�������
	else 
		return strcmp(a.registration_number, b.registration_number) < 0; //������ͬ��׼��֤�Ŵ�С�������� 
}



int main(){
	
	int n, k, num = 0; //numΪ�ܿ�������, k����ÿ����Ŀ������� 
	scanf("%d", &n); //nΪ������ 
	
	//����һ 
	for(int i = 1; i <= n; i++){
		scanf("%d", &k); //�ÿ�������
		for(int j = 0; j < k; j++){
			scanf("%s %d", stu[num].registration_number, &stu[num].score);
			stu[num].location_number = i; //�ÿ����Ŀ�����Ϊi
			num++; 
		} 
		sort(stu+num-k, stu+num, cmp); //���ÿ����Ŀ�������
		stu[num-k].local_rank = 1; //�ÿ�����һ����local_rank��Ϊ1 
		//printf("%s ", stu[0].registration_number);
		//printf("%d %d\n", stu[0].location_number, stu[0].local_rank);
		for(int j = num-k+1; j < num; j++){ //�Ըÿ���ʣ��Ŀ��� 
			if(stu[j].score == stu[j-1].score){ //�����ǰһλ����ͬ��
				//local_rankҲ��ͬ
				stu[j].local_rank = stu[j-1].local_rank; 
			} else{ //�����ǰһλ������ͬ�� 
				//local_rankΪ�ÿ���ǰ������ 
				stu[j].local_rank = j+1 - (num-k); //j+1���±��0��ʼ;  - (num-k)��Ϊ�˵���ǰ��forѭ����ֵ. 
			}
			//printf("%s ", stu[j].registration_number);
			//printf("%d %d\n", stu[j].location_number, stu[j].local_rank);
		} 
	} 
	printf("%d\n", num); //����ܿ�������
	//����� 
	sort(stu, stu+num, cmp); //�����п������� 
	//������ 
	int r = 1; //��ǰ����������
	for(int i = 0; i < num; i++){
		stu[i].final_rank = r; //��ǰ������������ 
		if(i > 0 && stu[i].score != stu[i-1].score){ //��stu[1], �ڶ���������ʼ�ж�. 
			r = i+1; //��ǰ��������һ������������ͬʱ, ��r����Ϊ����+1. 
			stu[i].final_rank = r; //���������� 
		} 
		printf("%s ", stu[i].registration_number);
		printf("%d %d %d\n", stu[i].final_rank, stu[i].location_number, stu[i].local_rank); 
	} 
	
	return 0;
} 


