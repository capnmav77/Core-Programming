#include <stdio.h>

// define a structure with bit fields
struct student {
    char name[20]; // 20 bytes
    unsigned int age : 5; // 5 bits, can store values from 0 to 31
    unsigned int gender : 1; // 1 bit, can store values 0 or 1
    unsigned int grade : 4; // 4 bits, can store values from 0 to 15
};

// define a function to print a student's information
void print_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %u\n", s.age);
    printf("Gender: %s\n", s.gender ? "Male" : "Female");
    printf("Grade: %u\n", s.grade);
}

// driver code
int main(void) {
    // create an array of students
    struct student students[3] = {
        {"Alice", 19, 0, 10},
        {"Bob", 20, 1, 11},
        {"Charlie", 21, 1, 12}
    };

    // print each student's information
    for (int i = 0; i < 3; i++) {
        print_student(students[i]);
        printf("\n");
    }

    return 0;
}
