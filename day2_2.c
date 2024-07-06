#include<stdio.h>
#define SIZE 8
#define Swap(a,b) {int t=a; a=b; b=t;}

typedef struct info
{
    int passes;
    int comp;    
}info_t;

info_t selection_sort(int arr[]);
info_t bubble_sort(int arr[]);
info_t insertion_sort(int arr[]);

int main(void){
    info_t n1={.comp=0,.passes=0};

    int arr1[SIZE] = {64,29,90,16,76,22,46,80}; 
    int arr2[SIZE] = {64,29,90,16,76,22,46,80};
    int arr3[SIZE] = {64,29,90,16,76,22,46,80};

    n1 = selection_sort(arr1);
    printf("selection_sort passes: %d and comparisons: %d\n", n1.passes,n1.comp);

    n1 = bubble_sort(arr2);
    printf("bubble_sort passes: %d and comparisons: %d\n", n1.passes,n1.comp);

    n1 = insertion_sort(arr3);
    printf("insertion_sort passes: %d and comparisons: %d\n", n1.passes,n1.comp);

    return 0;
}

info_t selection_sort(int arr[]){
    int i,j;
    info_t n1={.comp=0, .passes=0};
    for(i=0;i<SIZE-1;i++){
        n1.passes++;
        for(j=i+1;j<SIZE;j++){
            n1.comp++;
            if(arr[i]> arr[j]){
                Swap(arr[i],arr[j]);
            }
        }
    }
    return n1;
}

info_t bubble_sort(int arr[]){
    int i, j,flag;
    info_t n1={.comp=0, .passes=0};
    for(i=0;i<SIZE-1;i++){
        n1.passes++;
        flag=1;
        for(j=0; j<SIZE-1-i;j++){
            n1.comp++;
            if(arr[j]>arr[j+1]){
                Swap(arr[j],arr[j+1]);
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
    return n1;
}

info_t insertion_sort(int arr[]){
    int i,j,temp;
    info_t n1={.comp=0, .passes=0};
    for(i=1;i<SIZE;i++){
        n1.passes++;
        temp = arr[i];
        for(j=i-1; j >= 0 && temp < arr[j]; j--){
            n1.comp++;
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    return n1;
}