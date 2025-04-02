#include <stdio.h>

typedef struct Student {
	char name[20];
	int age;
}Student;

//void Change(struct Student* stu) {
void Change(Student* stu) {
	strcpy(stu->name, "xiaoming");
	stu->age = 20;
}

int main() {
	Student stu1 = { .name = "haha", .age = 13 };
	Change(&stu1);
	printf("stu1: name: %s, age: %d", stu1.name, stu1.age);

	return 0;
}