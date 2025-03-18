#include<stdio.h>

// Define the structure 'stud'
struct stud {
    int rno;
    float per;
};

int main() {
    struct stud s1, s2, s3;

    printf("Enter student details: \n");

    // Get student 1 details
    printf("Enter roll no and percentage for student1: ");
    scanf("%d%f", &s1.rno, &s1.per);

    // Get student 2 details
    printf("Enter roll no and percentage for student2: ");
    scanf("%d%f", &s2.rno, &s2.per);

    // Get student 3 details
    printf("Enter roll no and percentage for student3: ");
    scanf("%d%f", &s3.rno, &s3.per);

    // Compare percentages to find the highest one
    if(s1.per > s2.per) {
        if(s1.per > s3.per) {
            printf("Student with higher percentage is Roll No.: %d\n", s1.rno);
        } else {
            printf("Student with higher percentage is Roll No.: %d\n", s3.rno);
        }
    } else {
        if(s2.per > s3.per) {
            printf("Student with higher percentage is Roll No.: %d\n", s2.rno);
        } else {
            printf("Student with higher percentage is Roll No.: %d\n", s3.rno);
        }
    }

    return 0;
}