#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char id[10];
    char name[MAX_NAME_LENGTH];
    int age;
    float grades[5];
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }
    Student s;
    printf("Enter student ID: ");
    scanf("%s", s.id);
    printf("Enter student name: ");

    scanf(" %[^\n]", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    printf("Enter grade of subjects: ");
    printf("Algorithms: ");
    scanf("%f", &s.grades);
    printf("Programming: ");
    scanf("%f", &s.grades);
    printf("Engineering Mathematics: ");
    scanf("%f", &s.grades);
    printf("Digital Literacy: ");
    scanf("%f", &s.grades);
    printf("Digital Electronics: ");
    scanf("%f", &s.grades);
    printf("student added successfully\n\n");
    /*int i;
    for (i = 0; i < 5; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", &s.grades[i]);
    */}
    //students[student_count++] = s;
//}

void display_students() {
	int i;
    for (i = 0; i < student_count; i++) {
        Student s = students[i];
        float average = (s.grades[0] + s.grades[1] + s.grades[2] + s.grades[3] + s.grades[4]) / 5;
        printf("ID: %s, Name: %s, Age: %d, Grades: %.2f, %.2f, %.2f, %.2f, %.2f, Average: %.2f\n",
               s.id, s.name, s.age, s.grades[0], s.grades[1], s.grades[2], s.grades[3], s.grades[4], average);
    }
}

void search_student() {
    char id[10];
    printf("Enter student ID to search: ");
    scanf("%s", id);
    int i;
    for (i = 0; i < student_count; i++) {

        if (strcmp(students[i].id, id) == 0) {
            display_students();
            return;
        }
    }
    printf("Student not found.\n");
}

int compare(const void *a, const void *b) {
    float avg_a = ((Student *)a)->grades[0] + ((Student *)a)->grades[1] + ((Student *)a)->grades[2] + ((Student *)a)->grades[3] + ((Student *)a)->grades[4];
    float avg_b = ((Student *)b)->grades[0] + ((Student *)b)->grades[1] + ((Student *)b)->grades[2] + ((Student *)b)->grades[3] + ((Student *)b)->grades[4];
    return (avg_b / 5) - (avg_a / 5);
}

void sort_students() {
    qsort(students, student_count, sizeof(Student), compare);
    printf("Students sorted by average grade.\n");
}

void top_performer() {

    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }
    Student top_student = students[0];
    int i;
    for (i = 1; i < student_count; i++) {
        if (compare(&students[i], &top_student) < 0) {
            top_student = students[i];
        }
    }
    float average = (top_student.grades[0] + top_student.grades[1] + top_student.grades[2] + top_student.grades[3] + top_student.grades[4]) / 5;
    printf("Top Performer: ID: %s, Name: %s, Average: %.2f\n", top_student.id, top_student.name, average);
}

void filter_students_by_grade() {
    float range;
    printf("Enter grade threshold: ");
    scanf("%f", &range);
    int i;
    for (i = 0; i < student_count; i++) {
        float average = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2] + students[i].grades[3] + students[i].grades[4]) / 5;
        if (average >= range) {

            display_students();
        }
    }
}

void update_student() {
    char id[10];
    printf("Enter student ID to update: ");
    scanf("%s", id);
    int i;
    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            int j;
            for (j = 0; j < 5; j++) {
                printf("Enter new grade for subject %d: ", j + 1);
                scanf("%f", &students[i].grades[j]);
            }
            printf("Student updated.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void delete_student() {
    char id[10];
    printf("Enter student ID to delete: ");
    scanf("%s", id);
    int i;
    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
        	int j;
            for (j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void analyze_by_grade() {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }
    float total = 0;
    int i;
    for (i = 0; i < student_count; i++) {
        total += (students[i].grades[0] + students[i].grades[1] + students[i].grades[2] + students[i].grades[3] + students[i].grades[4]) / 5;

    }
    printf("Average of all students: %.2f\n", total / student_count);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Sort Students\n");
        printf("5. Top Performer\n");
        printf("6. Filter Students by Grade\n");
        printf("7. Update Student\n");
        printf("8. Delete Student\n");
        printf("9. Analyze by Grade\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("student added successfully.\n");

        switch (choice) {
            case 1: add_student();
			 break;
            case 2: display_students();
			 break;
            case 3: search_student();
			 break;
            case 4: sort_students();
			 break;
            case 5: top_performer();
			 break;
            case 6: filter_students_by_grade();
			 break;
            case 7: update_student();
			 break;
            case 8: delete_student();
			 break;
            case 9: analyze_by_grade();
			 break;
            case 10: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

