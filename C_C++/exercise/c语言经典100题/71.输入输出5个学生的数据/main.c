#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



typedef struct Student {
	char name[20];
	char sex[5];
	int age;
}Student;

void Input1(Student student[], int num) {
	for (int i = 0; i < num; ++i) {
		scanf("%s%s%d", student[i].name, student[i].sex, &student[i].age);
	}
}

void Output1(Student student[], int num) {
	for (int i = 0; i < num; ++i) {
		printf("%s\t%s\t%d\n", student[i].name, student[i].sex, student[i].age);
	}
}

void Input2(Student *student, int num) {
	scanf("%s%s%d", student->name, student->sex, &student->age);
}

void Output2(Student *student, int num) {
	printf("%s\t%s\t%d\n", student->name, student->sex, student->age);
}

#define num 3



int main() {
	
	Student student[num];
	Input1(student, num);
	Output1(student, num);

	//Student* student[num - 2] = { 0 };
	//Input2(student[0], num);
	//Output2(student[0], num);
	//
	return 0;
}