#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int score;
} Student;

Student students[MAX_STUDENTS];
Student temp[MAX_STUDENTS];

void merge_sort(int left, int right) {
    // TODO: 在这里添加你的代码
    
    if((right-left)<=0)
    return;
    else if((right-left)==1)
    {
        if(students[left].score<students[right].score)
        {
            Student tmp=students[left];
            students[left]=students[right];
            students[right]=tmp;
        }
        return;
    }
    int mid=(left+right)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    Student * sorted = (Student*)malloc(sizeof(Student)*(right-left+1));
    int index1=left,index2=mid+1;
    for(int i=0;i<(right-left+1);i++)
    {
        if((index1<mid+1) && (index2< right+1))
        {
            if(students[index1].score>students[index2].score)
            {
                sorted[i]=students[index1];
                index1++;
            }
            else
            {
                sorted[i]=students[index2];
                index2++;
            }
        }
        else if(index1<mid+1)
        {
            sorted[i]=students[index1];
            index1++;
        }
        else
        {
            sorted[i]=students[index2];
            index2++;
        }
    }

    for(int i=left;i<=right;i++)
    {
        students[i]=sorted[i-left];
    }
    


    
}

int main(void) {
    FILE *file = fopen("02_students.txt", "r");
    if (!file) {
        printf("错误：无法打开文件 02_students.txt\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    if (n <= 0 || n > MAX_STUDENTS) {
        printf("学生人数无效：%d\n", n);
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %d", students[i].name, &students[i].score);
    }
    fclose(file);

    merge_sort(0, n - 1);

    printf("\n归并排序后按成绩从高到低排序的学生名单：\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}