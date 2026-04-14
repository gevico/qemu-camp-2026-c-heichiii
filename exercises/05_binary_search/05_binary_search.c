#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LEN     50

// 学生结构体
typedef struct {
    char name[NAME_LEN];
    int score;
} Student;

Student students[MAX_STUDENTS];
int n;
void swap(a,b)
{
    Student tmp=students[a];
    students[a]=students[b];
    students[b]=tmp;
}
void quick_sort(int left,int right)
{
    if(left>=right)
    return;
    Student pivot=students[left];
    int i=left,j=right,index;
    while (i<j)
    {
        while (i<j && strcmp(students[i].name,pivot.name)<=0)
        {
            i++;
        }
        while (i<j && strcmp(students[j].name,pivot.name)>0)
        {
            j--;
        }

        if(i<j)
        swap(i,j);
        else
        {
            index=i;
            break;
        }
    }
    swap(left,index);

    quick_sort(left,index-1);
    quick_sort(index+1,right);
    
}
int bs(const char *target_name,int l,int r)
{
    int m=(l+r)/2;
    int res=strcmp(target_name,students[m].name);
    if(res==0)
    return m;
    if(res>0)
    return bs(target_name,m+1,r);
    if(res<0)
    return bs(target_name,l,m-1);
}
int binary_search(const char *target_name) {
    // TODO: 在这里添加你的代码
    quick_sort(0,MAX_STUDENTS-1);
    return bs(target_name,0,MAX_STUDENTS-1);

}

int main(void) {
    // 打开文件读取已排序的学生信息
    FILE *file = fopen("05_students.txt", "r");
    if (!file) {
        printf("错误：无法打开文件 05_students.txt\n");
        return 1;
    }

    // 读取学生人数
    fscanf(file, "%d", &n);
    if (n <= 0 || n > MAX_STUDENTS) {
        printf("学生人数无效：%d\n", n);
        fclose(file);
        return 1;
    }

    // 读取每个学生信息
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %d", students[i].name, &students[i].score);
    }
    fclose(file);

    char query_name[NAME_LEN] = "David";

    int index = binary_search(query_name);

    printf("\n折半查找出的排序后的学生信息：\n");
    if (index != -1) {
        printf("姓名：%s，成绩：%d\n", students[index].name, students[index].score);
    } else {
        printf("未找到该学生\n");
    }

    return 0;
}