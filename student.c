#include<stdio.h>
#include<stdlib.h>
struct student{
	char *name;
	//name=(char *)malloc(sizeof(char)*40);
	int age;
	char *gender;
	//gender=(char *)malloc(sizeof(char)*40);
	int id;
};
#define SIZE 100
void add(struct student [],int *);
void search(struct student [], int );
void display(struct student [], int );
void modify(struct student [], int);
void minimum( struct student [],int );
int main()
{
	struct student var[SIZE];
	int choice,count=0;
	int stu_id;
	while(1)
	{
		printf("======================================================\n");
		printf("-----------------::Enter the choice::-----------------\n");
		printf("======================================================\n");
		printf("1----->To add the student\n");
		printf("2----->To search the student\n");
		printf("3----->To display the student\n");
		printf("4----->To modify the student\n");
		printf("5----->To find min the student\n");
		printf("6----->exit\n");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				add(var,&count);
				break;
			case 2:
				search(var,count);
				break;
			case 3:
				int stu_id;
				printf("Enter student id:\t");
				scanf("%d",&stu_id);
				display(var,stu_id);
				break;
			case 4:
				printf("Enter student id:\t");
				scanf("%d",&stu_id);
				modify(var,stu_id);
				break;
			case 5:
				minimum(var,count);
				break;
			case 6:
				exit(0);
			default:
				printf("=====You entered wrong choice=====\n");
				printf("\n");
		}
	}
	return 0;
}
void add(struct student var[],int *count)
{
	if(*count<SIZE)
	{
		struct student reg;
		reg.name=(char *)malloc(40*(sizeof(char)));
		reg.gender=(char *)malloc(40*(sizeof(char)));
		printf("Enter the student name:\t");
		scanf("%s",reg.name);
		printf("Enter the student age:\t");
		scanf("%d",&reg.age);
		printf("Enter the student gender:\t");
		scanf("%s",reg.gender);
		printf("Enter the student id:\t");
		scanf("%d",&reg.id);
		var[*count]=reg;
		(*count)++;
		printf("\n================Student registered succesfully===========\n");
		printf("\n");
	}
	else
	{
		printf("\n============Student registration is full===============\n");
	}
}
void search(struct student var[], int count)
{
	int i=0;
	int stu_id;
	printf("Enter the student id\t");
	scanf("%d",&stu_id);
	while(i<=count)
	{
		if(var[i].id==stu_id)
		{
			printf("\n=================Student is present===============\n");
			display(var,stu_id);
			break;
		}
		i++;
	}
}
void display(struct student var[], int stu_id)
{
	int i=0;
	while(i<SIZE)
	{
		if(var[i].id==stu_id)
		{
			printf("Student name=\t%s\n",var[i].name);
			printf("Student name=\t%d\n",var[i].age);
			printf("Student name=\t%s\n",var[i].gender);
			printf("Student name=\t%d\n",var[i].id);
		}
		i++;
	}
}
void modify(struct student var[], int stu_id)
{
	int i=0;
	while(i<SIZE)
	{
		if(var[i].id==stu_id)
		{
		var[i].name=(char *)malloc(40*(sizeof(char)));
		var[i].gender=(char *)malloc(40*(sizeof(char)));
	
		printf("Enter the student name:\t");
		scanf("%s",var[i].name);
		printf("Enter the student age:\t");
		scanf("%d",&var[i].age);
		printf("Enter the student gender:\t");
		scanf("%s",var[i].gender);
		printf("Enter the student id:\t");
		scanf("%d",&var[i].id);
		printf("\n=============student data succesfully modified===========\n");
		printf("\n");
		}
		i++;
	}
}
void minimum( struct student var[],int count)
{
	int i=0;
	int min;
	min=var[0].age;
	while(i<SIZE)
	{
		if(min>var[i].age)
		{
			min=var[i].age;
		}/*
		else
		{
			min=var[0].age;
		}*/
		i++;
	}
	printf("Miniumum age of student=%d\n",min);
}

