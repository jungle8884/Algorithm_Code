#include <cstdio>

/*
A[] 为严格递增序列，left为二分下届；right为二分上届；x为欲查询的数。 
若A[]为严格递减序列，则将下面的代码“A[mid] > x”换位“A[mid] < x”即可。
*/
int binarySearch(int A[], int left, int right, int x){
	int mid; //mid为left和right的中点
	while(left <= right){ //如果left > right就没办法形成闭区间了  
		//mid = (left + right) / 2; //取中点
		mid = left + (right - left) / 2; //避免left+right可能会超过int而导致溢出
		if(A[mid] == x){
			return x;
		}else if (A[mid] > x) //中间数大于x
		{
			right = mid-1; //往左子区间[left, mid-1]查找
		}else //中间数小于x
		{
			left = mid+1; //往右子区间[mid+1, right]查找
		}
	} 

	return -1; //查找失败，发回-1
}

//A[]为递增序列，x为与查询的数，函数返回第一个大于等于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0, n]
int lower_bound(int A[], int left, int right, int x){
	int mid;
	while (left < right) //如果序列中不存在x，那么可以假设它存在，返回它的位置。
	{
		mid = (left + right) / 2;
		if(A[mid] >= x){ //中间的数大于等于x
			right = mid; //往左子区间[left, mid]查找
		}else{ //中间的数小于x
			left = mid + 1; //往右子区间[mid+1, right]查找
		}
	}

	return left; //由于当left == right时while循环停止，因此最后的返回值既可以时left，也可以时right
}

//A[]为递增序列，x为欲查询的数，函数返回第一个大于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0, n]
int upper_bound(int A[], int left, int right, int x){
	int mid;
	while (left < right) //如果序列中不存在x，那么可以假设它存在，返回它的位置。
	{
		mid = (left + right) / 2;
		if(A[mid] > x){ //中间的数大于x
			right = mid; //往左子区间[left, mid]查找
		}else{ //中间的数小于等于x
			left = mid + 1; //往右子区间[mid+1, right]查找
		}
	}

	return left; //返回夹出来的位置
}


int main(){
	const int n = 12;
	int A[n] = {1, 3, 4, 6, 6, 6, 7, 8, 10, 11, 12, 15};
	printf("%d\n", binarySearch(A, 0, n-1, 6));
	printf("%d\n", lower_bound(A, 0, n-1, 6));
	printf("%d\n", upper_bound(A, 0, n-1, 6));
	
	return 0;
} 
