#include<iostream>
#define STU 1000 //存储学生总数
struct Student {
	char *name; //姓名
	int age; //年龄
	char *sex; //性别
	char *banji; //班级
};

Student stss[STU];

//存储学生函数
int saveSt(Student st) {
	for (int i = 0; i < STU; i++) {
		if (stss[i].age == 0) {
			stss[i] = st;
			return 1;
			break;
		}
		
	}
	return 0;
}

void addStudent();
void getList();

//主页面用来输入菜单选项信息的
void home() {
	system("cls");
	printf("********************************\n");
	printf("请根据下方提示选择您要进行的操作:\n");
	printf("1、添加学生信息\n");
	printf("2、查看学生信息\n");
	printf("3、退出程序\n");
	printf("********************************\n");
		int action;
		action = getchar();
		switch (action) {
		case '1':
			addStudent();
			break;
		case '2':
			getchar();
			getList();
			break;
		case '3':
			printf("退出程序");
			break;
		default:
			printf("输入的操作指令有误");
		}
}

//查看现有学生
void getList() {
	system("cls");
	printf("**************所有学生信息*********\n");
	printf("姓名\t年龄\t性别\t班级\n");
	for (int i = 0; i < STU; i++) {
		if (stss[i].age != 0) {
			printf("%s\t%d\t%s\t%s\n", stss[i].name,stss[i].age, stss[i].sex, stss[i].banji);
			continue;
		}
		break;
	}
	printf("***********************************\n");
	printf("*1、返回主界面\t2、添加学生\t*\n");
	int a;
	a = getchar();
	switch (a) {
	case '1':
		getchar();
		home();
		break;
	case '2':
		addStudent();
		break;
	}
}


//添加学生信息
void addStudent() {
	char name[20]; //姓名
	int age; //年龄
	char sex[20]; //性别
	char banji[20]; //班级

	system("cls");
	printf("**************添加学生信息*********\n");
	printf("姓名\t年龄\t性别\t班级\n");
	scanf("%s\t%d\t%s\t%s", &name, &age, &sex, &banji);

	Student stud;
	stud.name = name;
	stud.age = age;
	stud.sex = sex;
	stud.banji = banji;

	int res = saveSt(stud);
	if (res == 1) {
		printf("添加成功\n学生信息如下:\n");
		printf("姓名：%s\t年龄：%d\t性别：%s\t班级：%s\n", name, age, sex, banji);
	}
	else {
		printf("添加失败\n");
	}
	printf("***********************************\n");
	printf("*1、返回主界面\t2、继续添加\t3、查看现有学生*\n");
	getchar();
	char ac;
	ac = getchar();
	switch (ac) {
	case '1':
		getchar(); //把缓冲区的字符串读完
		home();
		break;
	case '2':
		addStudent();
		break;
	case '3':
		getchar(); //把缓冲区的字符串读完
		getList();
		break;
	}

}


int main() {
	home();
	return 0;
}
