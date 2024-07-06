#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct student{
    int rollno;
    char name[10];
    int marks;
}stu;

void insertion_sort(stu *s);
void display(stu *s);

int main(){
    stu *s = (stu*) malloc (sizeof(stu)*SIZE);

    s[0].marks= 10;
    strcpy(s[0].name,"parth");
    s[0].rollno = 11;

    s[1].marks = 99;
    s[1].rollno = 1;
    strcpy(s[1].name,"ajay");

    s[2].marks = 50;
    s[2].rollno = 4;
    strcpy(s[2].name,"parekh");

    s[3].marks = 77;
    s[3].rollno = 7;
    strcpy(s[3].name,"jay");

    s[4].marks = 80;
    s[4].rollno = 10;
    strcpy(s[4].name,"akash");

    s[5].marks = 67;
    s[5].rollno = 22;
    strcpy(s[5].name,"akashy");

    s[6].marks = 79;
    s[6].rollno = 15;
    strcpy(s[6].name,"ashay");

    s[7].marks = 60;
    s[7].rollno = 24;
    strcpy(s[7].name,"vimal");

    s[8].marks = 80;
    s[8].rollno = 2;
    strcpy(s[8].name,"chcha");

    s[9].marks = 81;
    s[9].rollno = 21;
    strcpy(s[9].name,"sam");

    insertion_sort(s);
    display(s);        
    free(s);
    return 0;
}

void insertion_sort(stu *s){
    int i,j;
    for(i=1; i<SIZE;i++){
        stu temp = s[i];
        for(j=i-1; j >= 0 && temp.marks < s[j].marks; j--){
            s[j+1] = s[j];
        }
        s[j+1] = temp;
    }
}

void display(stu *s){

    for (int i = 0; i < SIZE; i++)
    {
        printf("name:%s\t marks:%d\t rollno:%d\n",s[i].name,s[i].marks,s[i].rollno);
    }
    
}
