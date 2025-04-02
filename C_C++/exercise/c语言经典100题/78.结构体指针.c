#include <stdio.h>
#include <stdlib.h>

struct student{
	char name[20];
	int age;
} /*person = { "go", 13 };*/
person[3] = { "gogo", 14, "li", 45, "ms", 56 };

int main() {
	//struct student *student_ptr = &person;
	//printf("%s, %d\n", student_ptr->name, student_ptr->age);

	struct student* stu_ptr = person;
	for (int i = 0; i < 3; ++i) {
		printf("%s, %d\n", stu_ptr->name, stu_ptr->age);
		++stu_ptr;
	}

	char* name = (char*)malloc(sizeof(char) * 20);
	//gets(name);
	fgets(name, 20, stdin);
	printf("your name: %s", name);

	char string[20] = {0};
	char* string_name = string;
	fgets(string_name, 20, stdin);
	printf("your name: %s", string_name);

	return 0;
}