#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct Students
{
 	char name[20];
 	int number;	//学号，学号定义为整型，8位数
 	char sex[3]; //性别 
	int age; //年龄  
	int score; //总分 
	struct Students *next; //指向下一个节点
}Students;
 Students *head=NULL; //把head作为全局变量 


void Menu()
{
	printf("_________________________________________\n");
	printf("|\t欢迎使用学生成绩管理系统\t|\n");
	printf("| ———————————————————|\n");
	printf("|   1、录入学生信息\t\t\t|\n");
	printf("|   2、显示学生信息\t\t\t|\n");
	printf("|   3、查找学生信息\t\t\t|\n");
	printf("|   4、学生成绩排序\t\t\t|\n");
	printf("|   5、插入学生信息\t\t\t|\n");
	printf("|   6、删除学生信息\t\t\t|\n");
	printf("|   7、退出管理系统\t\t\t|\n");
	printf("_________________________________________\n");
}


//定义一个函数，在排序时用于交换数据，减少代码冗余 
void Swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


//定义一个函数，用于交换两节点之间的信息 
void SwapStudent(Students *p)
{
	char TmpName[20],TmpSex[3];
	Swap(&p->age,&p->next->age);
	Swap(&p->score,&p->next->score);
	Swap(&p->number,&p->next->number);
	strcpy(TmpName,p->name);//字符串复制，前为目标字符串，后为原字符串，原字符串覆盖目标字符串实现交换 
	strcpy(p->name,p->next->name);
	strcpy(p->next->name,TmpName);
	strcpy(TmpSex,p->sex);
	strcpy(p->sex,p->next->sex);
	strcpy(p->next->sex,TmpSex);
}



//录入功能 
void InputStudent()
{
	Students *NewStudent;	//表示一个新同学的节点 
	Students *tail;	//链表的尾节点 
	tail=head;	 
	NewStudent=(Students*)malloc(sizeof(Students));	//为新同学节点分配 
	NewStudent->next=NULL;	//下一个节点置NULL 
	//查找尾节点 
	while(head!=NULL&&tail->next!=NULL)
		tail=tail->next;
	//如果头节点为空，则表示当前录入的是第一个同学 
	if(head==NULL)
		head=NewStudent;
	else
		tail->next=NewStudent; //不为空则令尾节点指向该同学 
	//录入开始 
	printf("***开始录入信息，请确保信息正确***\n");
	printf("请输入姓名：");
	scanf("%s",NewStudent->name);
	printf("请输入学号：");
	scanf("%d",&NewStudent->number);
	printf("请输入性别：");
	scanf("%s",NewStudent->sex);
	printf("请输入年龄：");
	scanf("%d",&NewStudent->age);
	printf("请输入成绩：");
	scanf("%d",&NewStudent->score);
	printf("录入完毕！\n");
	system("pause");
	system("cls");
}


//显示功能，将全部学生成绩打印出来 
void PrintStuInfo()
{
	system("cls");
	Students *StuInfo; 
	int people=0;
	StuInfo=head;
	//相当于头节点为空	 
	if(StuInfo==NULL)
	{
		printf("暂无学生信息,请输入后再试。\n");
		system("pause");
		system("cls");
		return;
	}
	//头节点不为空就打印信息 
	else{
		printf("*****************************************\n");
		printf("|姓名\t|学号\t|性别\t|年龄\t|成绩\t|\n"); 
		while(StuInfo)
		{
			people++;
			printf("*****************************************\n");
			printf("|%s\t|%d\t|%s\t|%d\t|%d\t|\n",StuInfo->name,StuInfo->number,StuInfo->sex,StuInfo->age,StuInfo->score);
			StuInfo=StuInfo->next;
		}
	}
	printf("*****************************************\n");
	printf("已显示全部，合计%d人\n",people); //报告学生人数 
	system("pause");
	system("cls");
}


//被主查找函数进行调用
//以学生姓名查找学生信息，该查找不排除同名同姓的情况 
void FindStuName()
{
	char StuName[10];
	Students *p;
	p=head; //指向头节点 
	int flag=1; //flag用于标记 
	int people=0;//用于统计 
	if(head==NULL)
	{ //如果头节点为空，表示查找失败 
		printf("查找失败：目前尚无任何信息可查\n");
		system("pause"); //system函数，用于停顿 
		system("cls");	//system函数，用于清屏 
		return; //结束该函数 
	}
	//如果头节点不为空 
	printf("请输入你所需要查找的姓名：");
	scanf("%s",StuName); 
	printf("________________________________________________________\n");
	while(p!=NULL)
	{
		if(strcmp(StuName,p->name)==0)
		{
			printf("|姓名：%s   |学号：%d   |性别：%s   |年龄：%d   |成绩：%d   |\n",p->name,p->number,p->sex,p->age,p->score);
			flag=0;
			people++; 
		}
		p=p->next;
	}
	//当flag置零时表示信息库中没有此人 
	if(flag)
	{
		printf("查找失败：学生信息库中暂无此人\n");
		system("pause"); //任意键继续 
		system("cls");	//清屏 
		return;	//结束函数 
	}
	
	//查到信息后会显示出来 
	printf("查找完毕，共有%d条结果\n",people);
	system("pause");	//任意键继续 
	system("cls");		//清屏 
}


//被主查找函数调用
//以学号的方式对学生进行查找，查找结果唯一，因为学号唯一 
void FindStuNum()
{
	Students *p;
	p=head;
	//如果头节点为空，则表示查找失败 
	if(head==NULL)
	{
		printf("查找失败：目前尚无任何信息可查\n");
		system("pause");
		system("cls");
		return;
	}
	int StuNum;
	printf("请输入你所需要查找的学号：");
	scanf("%d",&StuNum);
	printf("________________________________________________________\n");
	while(p!=NULL&&p->number!=StuNum)
		p=p->next;
	//p为NULL时，表示并未查到该学号 
	if(p==NULL)
	{
		printf("查找失败：学生信息库中并未查到该学号\n");
		system("pause");
		system("cls");
		return;
	}
	
	printf("|姓名：%s   |学号：%d   |性别：%s   |年龄：%d   |成绩：%d   |\n",p->name,p->number,p->sex,p->age,p->score);
	printf("查找完毕\n");
	system("pause");
	system("cls");
}



//查找学生信息 
void FindStudent()
{
	
	//考虑到姓名可能不唯一但是学号一定唯一的情况，定义了两种查询方式
	//即按学号查询以及按姓名查询 
	printf("*****************************************\n");
	printf("*\t学生成绩查询\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t请选择您所需要的查找方式:\t*\n");
	printf("*\t1、按学号查找\t\t\t*\n");
	printf("*\t2、按姓名查找\t\t\t*\n");
	printf("*****************************************\n");
	int choose;
	printf("请选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			FindStuNum();	//调用按学号查询函数 
			break;
		case 2:
			FindStuName();		//调用按学生姓名查询函数 
			break;
		default:	//不小心按错，则退出该功能 
			printf("选择错误！因为不存在此项选择!\n");
			system("pause");
			system("cls");
			break; 
	}
}



//冒泡排序法对学生成绩进行排序
//len表示当前链表节点个数，p为当前的链表，choose表示选择 
void BubbleSort(int len,Students *p,int choose)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
	p=head;
		for(j=0;j<len-i-1;j++)
		{
			if(choose==1)
			{		//按总成绩降序排序 
				if(p->score<p->next->score)
					SwapStudent(p);     //调用学生信息交换函数，交换两节点之间的信息
				p=p->next;
			}
			else if(choose==2)
			{		//按总成绩升序排序 
				if(p->score>p->next->score)
					SwapStudent(p);
				p=p->next;
			}
		}
	}
}


//学生成绩的排序 
void SortStudents()
{
	system("cls");
	Students *p,*q;
	int len;	//统计节点个数，即学生个数 
	int choose;	//用于选择排序方式 
	len=0;
	q=head;
	
	//如果头节点为空 
	if(head==NULL)
	{
		printf("排序失败：学生信息库中暂无任何信息！\n");
		system("pause");
		system("cls");
		return;
	}
	//统计节点 
	while(q!=NULL)
	{
		q=q->next;
		len++;
	}
	printf("*****************************************\n");
	printf("*\t学生成绩排序\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t你有以下2种排序方式可选:\t*\n");
	printf("*\t1、按总成绩降序\t\t\t*\n");
	printf("*\t2、按总成绩升序\t\t\t*\n");
	printf("*****************************************\n");
	printf("请选择：");
	scanf("%d",&choose);
	
	//通过选择不同的方式进行排序，调用冒泡排序算法函数 
	switch(choose)
	{
		case 1:
			BubbleSort(len,p,choose);
			break;
		case 2:
			BubbleSort(len,p,choose);
			break;
		default:	//防止输入错误选择 
			printf("选择错误！因为不存在此项选择!\n");
			system("pause");
			system("cls");
			break; 
	}
	printf("排序成功！请在功能2中查看！\n"); 	//排序成功后可以通过显示函数查看排序结果 
	system("pause");
	system("cls");
}


//按学号插入学生信息 
void InsertStudent()
{     
	Students *NewStudent,*tail;
	tail=head;
	int i;
	while(tail->next&&tail->next->number<i)
	tail=tail->next;
	NewStudent=(Students *)malloc(sizeof(Students));
	NewStudent->next=tail->next;
	tail->next=NewStudent;
	printf("\t\t\t请输入要插入学生的信息:\n\n");
	printf("***开始插入信息，请确保信息正确***\n");
	printf("请输入姓名：");
	scanf("%s",NewStudent->name);
	printf("请输入学号：");
	scanf("%d",&NewStudent->number);
	printf("请输入性别：");
	scanf("%s",NewStudent->sex);
	printf("请输入年龄：");
	scanf("%d",&NewStudent->age);
	printf("请输入成绩：");
	scanf("%d",&NewStudent->score);
	printf("插入完毕\n");
	system("pause");
	system("cls");
}


 
//删除某个学生的信息，以学号进行查找，因为姓名会有同名的情况 
void DeleteStuInfo()
{
	Students *p,*BeforeNode;
	p=head;
	int StuNum;
	int choose;
	//如果头节点为空 
	if(head==NULL)
	{
		printf("暂无学生信息,请输入后再试。\n");
		system("pause");
		system("cls");
		return;
	}
	printf("请输入你将删除的学生的学号：");
	scanf("%d",&StuNum);
	
	//查找学号 
	while(p!=NULL&&p->number!=StuNum)
	{
		BeforeNode=p;
		p=p->next;
	}
	
	//查找失败，可能是输入学号错误或者信息库中没有该学号 
	if(p==NULL)
	{
		printf("删除失败：学生信息库中并未查到该学号\n");
		system("pause");
		system("cls");
		return;
	}
 
	printf("你将删除的学生是：%s，学号为：%d\n",p->name,p->number);	//显示将要删除的学生的学号和姓名 
	printf("你确认要删除该同学的信息吗？(是选择1，否选择2)\n");	//防止失误将学生信息删除的情况 
	printf("请选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			if(p==head)	//如果删除的学生是在头节点 
				head=p->next;
			else	//如果删除的学生是在尾节点或者是中间节点 
				BeforeNode->next=p->next;
			printf("删除成功！\n");
			break;
		case 2:
			printf("删除失败：你否认了删除指令！\n");
			break;
	}
	system("pause");
	system("cls");
}



//主函数 
int main()
{
	int choise;
	while(1)
	{
		Menu();	//先调用菜单函数 
		printf("请选择：");
		scanf("%d",&choise);
		
		//七大功能 
		switch(choise)
		{
			case 1:
				InputStudent();	//录入功能 
				break;
			case 2:
				PrintStuInfo();	//显示功能 
				break;
			case 3:
				FindStudent();	//查找功能 
				break;
			case 4:
				SortStudents();	//排序功能 
				break;
			case 5:
				InsertStudent();//插入功能 
				break;
			case 6:
				DeleteStuInfo();//删除功能 
				break;
			case 7:	//退出程序 
				printf("你已退出学生成绩管理系统，欢迎下次使用！");
				return 0;
				break;
			default:	//防止输入错误 
				printf("选择错误！因为不存在此项选择!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}

