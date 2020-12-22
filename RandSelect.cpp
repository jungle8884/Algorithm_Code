#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int maxn = 100010;
int A[maxn], n; //A�����������, nΪ�����

//����[left, right]��Χ�ڵ������
int generateRandomNum_Range_fromLeft2Right(int left, int right){
    srand((unsigned)time(NULL)); //�������������
    
    return (int)(round(1.0 * rand()/RAND_MAX * (right-left) + left));
}

//����a��b��ֵ
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//���ָ����ԪA[p]
int randPartition(int A[], int left, int right){
    int p = generateRandomNum_Range_fromLeft2Right(left, right);
    swap(&A[p], &A[left]);
    
    int temp = A[left];
    while (left < right) //��left��right����ʱ�˳�
    {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }

    A[left] = temp; //��temp�ŵ�left��right�����ĵط�

    return left; //�����������±�
}

//���ѡ���㷨�������������---A[left, right]�з��ص�K�����
int randSelect(int A[], int left, int right, int K){
    //�ݹ�߽�
    if(left == right) return A[left]; //�߽�

    int p = randPartition(A, left, right); //��Ԫ��λ��Ϊp
    int M = p - left + 1; //A[p]��A[left, right]�е�M�����

    if(K == M) return A[p]; //�ҵ���K�����
    if (K < M)
    {
        return randSelect(A, left, p-1, K); //����Ԫ����ҵ�K�����
    }else
    {
        return randSelect(A, p+1, right, K-M); //����Ԫ�Ҳ��ҵ�K-M�����
    }  
}


int main(){
     
    //���ѡ���㷨�������������---A[left, right]�з��ص�K�������
    /*
    int A[100] = {6, 5, 12, 7, 2, 9, 3};
    int n = A[0]; //A[0]���ʵ�ʳ���
    int K = 3;

    int result = randSelect(A, 1, n, K);
    //�ʱ�临�Ӷ�ΪO(n*n); ���������������ʱ�临�Ӷ�ȴ��O(n).
    printf("%d\n", result); */

    //sum��sumL��¼��������֮�����зֺ�ǰn/2��Ԫ��֮��
    int sum = 0, sumL = 0;
    printf("��������������:");
    scanf("%d", &n); 
    /* ����һ����������ɵļ��ϣ������е�����������ͬ��
    ����Ҫ������Ϊ�����Ӽ��ϣ�ʹ���������Ӽ��ϵĲ�Ϊԭ���ϡ���Ϊ�ռ���
    ͬʱ�������Ӽ��ϵ�Ԫ�ظ��� n1��n2 ֮��ľ���ֵ|n1-n2|������С��ǰ���£�
    Ҫ�����Ǹ��Ե�Ԫ��֮�� S1��S2��ľ���ֵ|S1-S2|�����ܴ� 
    �����|S1-S2|���ڶ��� 
    ��Ч�ڣ���ԭ�����е�n/2�����
    */
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]); //��������
        sum += A[i]; //�ۼ���������֮��
    }
    randSelect(A, 0, n-1, n/2); //Ѱ�ҵ�n/2��������������з�
    for (int i = 0; i < n/2; i++)
    {
        sumL += A[i]; //�ۼƽ�С���Ӽ�����Ԫ��֮��
    }
    int sumR = (sum - sumL); //�ϴ���Ӽ�����Ԫ��֮��
    //printf("��С���Ӽ�����Ԫ��֮��: %d\n", sumL); 
    //printf("�ϴ���Ӽ�����Ԫ��֮��: %d\n", sumR); 

    printf("�����Ӽ��ϵ�Ԫ�غ�֮��: %d\n", sumR - sumL); //�������Ӽ��ϵ�Ԫ�غ�֮��

    return 0;
} 