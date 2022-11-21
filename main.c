#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x)        ((x-1)/2)
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환


int *origin;
int on;

void SelectionSort(int *base, int n);
void InsertionSort(int *base, int n);
void BubbleSort(int *base, int n);

void QuickSort(int *base, int n);
void ViewArr4(int *arr, int n);

void MergeSort5(int *base, int n);

void ViewArr5(int *arr, int n);

void HeapSort(int *base, int n);

void ViewArr6(int *arr, int n);
int main(void) {

    int j = 0;
    while (j == 0)
    {
        //랜덤 값 생성
        int select = 0, arr[25], dap[25];

        printf("\n\n랜덤 값 생성 : ");

        for (int i = 0; i < 25; i++) {
            arr[i] = rand() % 100;
            printf("%d ", arr[i]);
        }

        printf("\n1. 선택정렬 \n"
               "2. 삽입정렬 \n"
               "3. 버블정렬 \n"
               "4. 퀵정렬 \n"
               "5. 병합정렬 \n"
               "6. 힙정렬 \n"
               "7. 종료 \n"
               "원하는 정렬을 선택하세요 : ");
        if (!scanf("%d", &select)) { //입력값이 숫자가 아닐 경우
            printf("잘못 입력하셨습니다. \n"); //오류 메시지 출력
            exit(1); //프로그램 종료
        }

        switch (select) {
            case 1:
                printf("선택정렬을 선택하셨습니다. \n");
                SelectionSort(arr, 25); //선택정렬 함수 호출
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 2:
                printf("삽입정렬을 선택하셨습니다. \n");
                InsertionSort(arr, 25); //삽입정렬 함수 호출
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 3:
                printf("버블정렬을 선택하셨습니다. \n");
                BubbleSort(arr, 25); //버블정렬 함수 호출
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 4:
                printf("퀵정렬을 선택하셨습니다. \n");
                origin = arr;
                on = 25;
                ViewArr4(arr, 25); //퀵정렬 함수 호출
                QuickSort(arr, 25);
                ViewArr4(arr, 25);
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 5:
                printf("병합정렬을 선택하셨습니다. \n");
                origin = arr;
                on = 10;
                ViewArr5(origin, on);   //병합정렬 함수 호출
                MergeSort5(arr, 25);
                ViewArr5(origin, on);
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 6:
                printf("힙정렬을 선택하셨습니다. \n");
                ViewArr6(arr, 25);  //힙정렬 함수 호출
                HeapSort(arr, 25);
                ViewArr6(arr, 25);
                printf("\n정렬된 값 : ");
                for (int i = 0; i < 25; i++) {  //정렬된 배열 출력
                    printf("%d ", arr[i]);
                }
                break;
            case 7:
                //프로그램 종료
                printf("프로그램을 종료합니다. \n");
                exit(1);
            default:
                printf("잘못 입력하셨습니다. \n");   //오류 메시지 출력
        }
    }
    return 0;
}





//선택 정렬
void ViewArr(int *arr, int n);
void SelectionSort(int *base, int n)
{
    int i, j;
    int maxi;
    ViewArr(base, n);//현재 상태 출력
    for (i = n; i>1; i--)//정렬할 범위를 축소해 나갑니다.
    {
        maxi = 0;
        for (j = 1; j<i; j++)
        {
            if (base[maxi]<base[j])//더 큰 원소를 만나면
            {
                maxi = j;
            }
        }
        SWAP(base[maxi], base[i - 1]);//교환
        ViewArr(base, n);//상태 출력
    }
}
void ViewArr(int *arr, int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("%2d ", arr[i]);
//    }
//    printf("\n");
}





//삽입 정렬
void ViewArr2(int *arr, int n);
void InsertionSort(int *base, int n)
{
    int i, j;
    ViewArr2(base, n);//현재 상태 출력
    for (i = 1; i<n; i++)//정렬할 범위를 확대해 나갑니다.
    {
        for (j = i; j>0; j--)
        {
            if (base[j - 1]>base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[j - 1], base[j]);//교환
                ViewArr(base, n);//상태 출력
            }
            else
            {
                break;
            }
        }
    }
}
void ViewArr2(int *arr, int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}





//버블 정렬
void ViewArr3(int *arr, int n);
void BubbleSort(int *base, int n)
{
    int i, j;
    ViewArr3(base, n);//현재 상태 출력
    for (i = n; i>1; i--)//정렬할 범위를 축소해 나갑니다.
    {
        for (j = 1; j<i; j++)
        {
            if (base[j - 1]>base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[j - 1], base[j]);//교환
                ViewArr3(base, n);//상태 출력
            }
        }
    }
}
void ViewArr3(int *arr, int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("%2d ", arr[i]);
//    }
//    printf("\n");
}




//퀵 정렬
void PrintSpace(int n);
void QuickSort(int *base, int n)
{
    int pivot = 0; // 피벗의 위치 기억하는 변수
    int left = 0, right = 0; // 피벗보다 큰 값과 작은 값의 위치를 찾기위한 변수
    if (n <= 1)
    {
        return;
    }
    left = 0;
    right = n;
    while (1)
    {
        //앞쪽에 피벗(인덱스 0에 있는 원소)보다 큰 값을 만날 때까지 left를 이동합니다.
        for (left++; (left<n) && (base[0] >= base[left]); left++);
        //뒤쪽에 피벗(인덱스 0에 있는 원소)보다 작은 값을 만날 때까지 right를 이동합니다.
        for (right--; (right>0) && (base[0]<base[right]); right--);
        //만약 left가 right보다 작다면 피벗과 비교했을 때 작은 값이 큰 값보다 뒤에 있으니 교환합니다.
        if (left<right)
        {
            SWAP(base[left], base[right]);
            PrintSpace(base - origin);
            ViewArr4(base, n);
        }
            //그렇지 않다면 피벗을 중심으로 작은 값들과 큰 값들이 분리 작업이 끝난 것입니다.
        else
        {
            break;
        }
    }
    //이제 피벗을 작은 값들과 큰 값들 사이로 보냅니다.
    SWAP(base[0], base[right]);
    PrintSpace(base - origin);
    ViewArr4(base, n);
    //피벗보다 작은 값들이 있는 앞쪽을 재귀 호출로 정렬합니다.
    QuickSort(base, right);
    //피벗보다 큰 값들이 있는 뒤쪽을 재귀 호출로 정렬합니다.
    QuickSort(base + left, n - left);
}
void PrintSpace(int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("   ");
//    }
}
void ViewArr4(int *arr, int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("%2d ", arr[i]);
//    }
//    printf("\n");
}



//합병정렬
void PrintSpace5(int n);
void MergeSort5(int *base, int n)
{
    int ahalf = n / 2; //배열의 앞쪽 개수
    int bhalf = n - ahalf; //배열의 뒤쪽 개수
    int ai = 0, bi = ahalf;
    int i = 0;
    int *tbase = 0;
    if (n <= 1)//배열의 크기가 1보다 작거나 같을 때
    {
        return;
    }
    MergeSort5(base, ahalf);//앞쪽 배열 재귀호출로 정렬
    PrintSpace5(base - origin);
    ViewArr(base, ahalf);
    MergeSort5(base + ahalf, bhalf);//뒤쪽 배열 재귀호출로 정렬
    PrintSpace5(base + ahalf - origin);
    ViewArr(base + ahalf, bhalf);
    tbase = (int *)malloc(sizeof(int)*n);//배열 크기의 임시 공간을 할당
    memcpy(tbase, base, sizeof(int)*n);//임시 공간에 배열 메모리 복사
    while ((ai<ahalf) && (bi<n))
    {
        if (tbase[ai] <= tbase[bi])//뒤쪽이 크거나 같을 때
        {
            base[i] = tbase[ai];//앞쪽 배열의 원소를 대입
            ai++;
        }
        else
        {
            base[i] = tbase[bi];//뒤쪽 배열의 원소를 대입
            bi++;
        }
        i++;
    }
    while (ai<ahalf)//앞쪽 배열의 남은 것들을 대입
    {
        base[i] = tbase[ai];
        i++;
        ai++;
    }
    while (bi<n)//뒤쪽 배열의 남은 것들을 대입
    {
        base[i] = tbase[bi];
        i++;
        bi++;
    }
    free(tbase);//임시 버퍼에 할당한 메모리 해제
}
void PrintSpace5(int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("   ");
//    }
}
void ViewArr5(int *arr, int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("%2d ", arr[i]);
//    }
//    printf("\n");
}



//힙정렬
void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);
void HeapSort(int *base, int n)
{
    int on = n;
    printf("초기 힙 생성 과정\n");
    InitHeap(base, n);
    n--;
    SWAP(base[0], base[n]);
    printf("정렬 과정\n");
    while (n>1)
    {
        MakeHeap(base, n);
        ViewArr6(base, n + 1);
        n--;
        SWAP(base[0], base[n]);
    }
    ViewArr6(base, n + 1);
}
void InitHeap(int *base, int n)
{
    int pa = 0;
    int now;
    int i;
    for (i = 1; i<n; i++)//순차적으로 힙에 구성
    {
        now = i;
        while (now>0)//now의 인덱스가 0이 아니면(힙의 루트가 아니면)
        {
            pa = PARENT(now);//부모 인덱스 구함
            if (base[now]>base[pa])//부모보다 더 크면
            {
                SWAP(base[now], base[pa]);//부모와 교환
                now = pa;//인덱스를 부모로 설정
            }
            else//아니면 자리를 찾은 것임
            {
                break;
            }
        }
        ViewArr6(base, i + 1);
    }
}
int FindMaxIndex(int *base, int n, int now);
void MakeHeap(int *base, int n)
{
    int now = 0;
    int mp = 0;
    //루트에 있는 요소를 힙 트리에 맞게 자리를 찾는 과정
    while (LEFT_CHILD(now) < n)//왼쪽 자식이 있다면
    {
        int mp = FindMaxIndex(base, n, now);//now와 왼쪽, 오른쪽 자식 중에 큰 값의 위치 찾음
        if (mp == now)//mp와 now가 같으면
        {
            break;//자리를 찾은 것임
        }
        if(base[mp] > base[now])
        {
            SWAP(base[mp], base[now]);//now와 큰 값의 자리 교환
        }
        now = mp;//큰 값의 위치를 now로 설정
    }
}
int FindMaxIndex(int *base, int n, int now)
{
    int lc = LEFT_CHILD(now);//왼쪽 자식
    int rc = RIGHT_CHILD(now);//오른쪽 자식
    if (rc >= n)//오른쪽 자식이 없을 때
    {
        if (base[now]<base[lc])
        {
            return lc;
        }
        return now;
    }
    if (base[lc]<base[rc])
    {
        return rc;
    }
    return lc;
}
void ViewArr6(int *arr, int n)
{
//    int i = 0;
//    for (i = 0; i<n; i++)
//    {
//        printf("%2d ", arr[i]);
//    }
//    printf("\n");
}