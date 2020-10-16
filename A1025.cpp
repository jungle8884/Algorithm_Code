#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

struct Student {
	char registration_number[15]; //准考证号
	int score; //分数
	int location_number; //考场号 
	int local_rank; //考场内排名 
	int final_rank; //总排名 
}stu[30010]; 

bool cmp(Student a, Student b){
	if (a.score != b.score)  
		return a.score > b.score; //先按分数从高到低进行排序
	else 
		return strcmp(a.registration_number, b.registration_number) < 0; //分数相同按准考证号从小到大排序 
}



int main(){
	
	int n, k, num = 0; //num为总考生人数, k代表该考场的考生人数 
	scanf("%d", &n); //n为考场数 
	
	//步骤一 
	for(int i = 1; i <= n; i++){
		scanf("%d", &k); //该考场人数
		for(int j = 0; j < k; j++){
			scanf("%s %d", stu[num].registration_number, &stu[num].score);
			stu[num].location_number = i; //该考生的考场号为i
			num++; 
		} 
		sort(stu+num-k, stu+num, cmp); //将该考场的考生排序
		stu[num-k].local_rank = 1; //该考场第一名的local_rank记为1 
		//printf("%s ", stu[0].registration_number);
		//printf("%d %d\n", stu[0].location_number, stu[0].local_rank);
		for(int j = num-k+1; j < num; j++){ //对该考场剩余的考生 
			if(stu[j].score == stu[j-1].score){ //如果与前一位考生同分
				//local_rank也相同
				stu[j].local_rank = stu[j-1].local_rank; 
			} else{ //如果与前一位考生不同分 
				//local_rank为该考生前的人数 
				stu[j].local_rank = j+1 - (num-k); //j+1是下标从0开始;  - (num-k)是为了抵消前面for循环赋值. 
			}
			//printf("%s ", stu[j].registration_number);
			//printf("%d %d\n", stu[j].location_number, stu[j].local_rank);
		} 
	} 
	printf("%d\n", num); //输出总考生人数
	//步骤二 
	sort(stu, stu+num, cmp); //将所有考生排名 
	//步骤三 
	int r = 1; //当前考生的排名
	for(int i = 0; i < num; i++){
		stu[i].final_rank = r; //当前考生的总排名 
		if(i > 0 && stu[i].score != stu[i-1].score){ //从stu[1], 第二个考生开始判断. 
			r = i+1; //当前考生与上一个考生分数不同时, 让r更新为人数+1. 
			stu[i].final_rank = r; //更新总排名 
		} 
		printf("%s ", stu[i].registration_number);
		printf("%d %d %d\n", stu[i].final_rank, stu[i].location_number, stu[i].local_rank); 
	} 
	
	return 0;
} 


