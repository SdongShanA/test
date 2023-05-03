#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct Students
{
 	char name[20];
 	int number;	//ѧ�ţ�ѧ�Ŷ���Ϊ���ͣ�8λ��
 	char sex[3]; //�Ա� 
	int age; //����  
	int score; //�ܷ� 
	struct Students *next; //ָ����һ���ڵ�
}Students;
 Students *head=NULL; //��head��Ϊȫ�ֱ��� 


void Menu()
{
	printf("_________________________________________\n");
	printf("|\t��ӭʹ��ѧ���ɼ�����ϵͳ\t|\n");
	printf("| ��������������������������������������|\n");
	printf("|   1��¼��ѧ����Ϣ\t\t\t|\n");
	printf("|   2����ʾѧ����Ϣ\t\t\t|\n");
	printf("|   3������ѧ����Ϣ\t\t\t|\n");
	printf("|   4��ѧ���ɼ�����\t\t\t|\n");
	printf("|   5������ѧ����Ϣ\t\t\t|\n");
	printf("|   6��ɾ��ѧ����Ϣ\t\t\t|\n");
	printf("|   7���˳�����ϵͳ\t\t\t|\n");
	printf("_________________________________________\n");
}


//����һ��������������ʱ���ڽ������ݣ����ٴ������� 
void Swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


//����һ�����������ڽ������ڵ�֮�����Ϣ 
void SwapStudent(Students *p)
{
	char TmpName[20],TmpSex[3];
	Swap(&p->age,&p->next->age);
	Swap(&p->score,&p->next->score);
	Swap(&p->number,&p->next->number);
	strcpy(TmpName,p->name);//�ַ������ƣ�ǰΪĿ���ַ�������Ϊԭ�ַ�����ԭ�ַ�������Ŀ���ַ���ʵ�ֽ��� 
	strcpy(p->name,p->next->name);
	strcpy(p->next->name,TmpName);
	strcpy(TmpSex,p->sex);
	strcpy(p->sex,p->next->sex);
	strcpy(p->next->sex,TmpSex);
}



//¼�빦�� 
void InputStudent()
{
	Students *NewStudent;	//��ʾһ����ͬѧ�Ľڵ� 
	Students *tail;	//�����β�ڵ� 
	tail=head;	 
	NewStudent=(Students*)malloc(sizeof(Students));	//Ϊ��ͬѧ�ڵ���� 
	NewStudent->next=NULL;	//��һ���ڵ���NULL 
	//����β�ڵ� 
	while(head!=NULL&&tail->next!=NULL)
		tail=tail->next;
	//���ͷ�ڵ�Ϊ�գ����ʾ��ǰ¼����ǵ�һ��ͬѧ 
	if(head==NULL)
		head=NewStudent;
	else
		tail->next=NewStudent; //��Ϊ������β�ڵ�ָ���ͬѧ 
	//¼�뿪ʼ 
	printf("***��ʼ¼����Ϣ����ȷ����Ϣ��ȷ***\n");
	printf("������������");
	scanf("%s",NewStudent->name);
	printf("������ѧ�ţ�");
	scanf("%d",&NewStudent->number);
	printf("�������Ա�");
	scanf("%s",NewStudent->sex);
	printf("���������䣺");
	scanf("%d",&NewStudent->age);
	printf("������ɼ���");
	scanf("%d",&NewStudent->score);
	printf("¼����ϣ�\n");
	system("pause");
	system("cls");
}


//��ʾ���ܣ���ȫ��ѧ���ɼ���ӡ���� 
void PrintStuInfo()
{
	system("cls");
	Students *StuInfo; 
	int people=0;
	StuInfo=head;
	//�൱��ͷ�ڵ�Ϊ��	 
	if(StuInfo==NULL)
	{
		printf("����ѧ����Ϣ,����������ԡ�\n");
		system("pause");
		system("cls");
		return;
	}
	//ͷ�ڵ㲻Ϊ�վʹ�ӡ��Ϣ 
	else{
		printf("*****************************************\n");
		printf("|����\t|ѧ��\t|�Ա�\t|����\t|�ɼ�\t|\n"); 
		while(StuInfo)
		{
			people++;
			printf("*****************************************\n");
			printf("|%s\t|%d\t|%s\t|%d\t|%d\t|\n",StuInfo->name,StuInfo->number,StuInfo->sex,StuInfo->age,StuInfo->score);
			StuInfo=StuInfo->next;
		}
	}
	printf("*****************************************\n");
	printf("����ʾȫ�����ϼ�%d��\n",people); //����ѧ������ 
	system("pause");
	system("cls");
}


//�������Һ������е���
//��ѧ����������ѧ����Ϣ���ò��Ҳ��ų�ͬ��ͬ�յ���� 
void FindStuName()
{
	char StuName[10];
	Students *p;
	p=head; //ָ��ͷ�ڵ� 
	int flag=1; //flag���ڱ�� 
	int people=0;//����ͳ�� 
	if(head==NULL)
	{ //���ͷ�ڵ�Ϊ�գ���ʾ����ʧ�� 
		printf("����ʧ�ܣ�Ŀǰ�����κ���Ϣ�ɲ�\n");
		system("pause"); //system����������ͣ�� 
		system("cls");	//system�������������� 
		return; //�����ú��� 
	}
	//���ͷ�ڵ㲻Ϊ�� 
	printf("������������Ҫ���ҵ�������");
	scanf("%s",StuName); 
	printf("________________________________________________________\n");
	while(p!=NULL)
	{
		if(strcmp(StuName,p->name)==0)
		{
			printf("|������%s   |ѧ�ţ�%d   |�Ա�%s   |���䣺%d   |�ɼ���%d   |\n",p->name,p->number,p->sex,p->age,p->score);
			flag=0;
			people++; 
		}
		p=p->next;
	}
	//��flag����ʱ��ʾ��Ϣ����û�д��� 
	if(flag)
	{
		printf("����ʧ�ܣ�ѧ����Ϣ�������޴���\n");
		system("pause"); //��������� 
		system("cls");	//���� 
		return;	//�������� 
	}
	
	//�鵽��Ϣ�����ʾ���� 
	printf("������ϣ�����%d�����\n",people);
	system("pause");	//��������� 
	system("cls");		//���� 
}


//�������Һ�������
//��ѧ�ŵķ�ʽ��ѧ�����в��ң����ҽ��Ψһ����Ϊѧ��Ψһ 
void FindStuNum()
{
	Students *p;
	p=head;
	//���ͷ�ڵ�Ϊ�գ����ʾ����ʧ�� 
	if(head==NULL)
	{
		printf("����ʧ�ܣ�Ŀǰ�����κ���Ϣ�ɲ�\n");
		system("pause");
		system("cls");
		return;
	}
	int StuNum;
	printf("������������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d",&StuNum);
	printf("________________________________________________________\n");
	while(p!=NULL&&p->number!=StuNum)
		p=p->next;
	//pΪNULLʱ����ʾ��δ�鵽��ѧ�� 
	if(p==NULL)
	{
		printf("����ʧ�ܣ�ѧ����Ϣ���в�δ�鵽��ѧ��\n");
		system("pause");
		system("cls");
		return;
	}
	
	printf("|������%s   |ѧ�ţ�%d   |�Ա�%s   |���䣺%d   |�ɼ���%d   |\n",p->name,p->number,p->sex,p->age,p->score);
	printf("�������\n");
	system("pause");
	system("cls");
}



//����ѧ����Ϣ 
void FindStudent()
{
	
	//���ǵ��������ܲ�Ψһ����ѧ��һ��Ψһ����������������ֲ�ѯ��ʽ
	//����ѧ�Ų�ѯ�Լ���������ѯ 
	printf("*****************************************\n");
	printf("*\tѧ���ɼ���ѯ\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t��ѡ��������Ҫ�Ĳ��ҷ�ʽ:\t*\n");
	printf("*\t1����ѧ�Ų���\t\t\t*\n");
	printf("*\t2������������\t\t\t*\n");
	printf("*****************************************\n");
	int choose;
	printf("��ѡ��");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			FindStuNum();	//���ð�ѧ�Ų�ѯ���� 
			break;
		case 2:
			FindStuName();		//���ð�ѧ��������ѯ���� 
			break;
		default:	//��С�İ������˳��ù��� 
			printf("ѡ�������Ϊ�����ڴ���ѡ��!\n");
			system("pause");
			system("cls");
			break; 
	}
}



//ð�����򷨶�ѧ���ɼ���������
//len��ʾ��ǰ����ڵ������pΪ��ǰ������choose��ʾѡ�� 
void BubbleSort(int len,Students *p,int choose)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
	p=head;
		for(j=0;j<len-i-1;j++)
		{
			if(choose==1)
			{		//���ܳɼ��������� 
				if(p->score<p->next->score)
					SwapStudent(p);     //����ѧ����Ϣ�����������������ڵ�֮�����Ϣ
				p=p->next;
			}
			else if(choose==2)
			{		//���ܳɼ��������� 
				if(p->score>p->next->score)
					SwapStudent(p);
				p=p->next;
			}
		}
	}
}


//ѧ���ɼ������� 
void SortStudents()
{
	system("cls");
	Students *p,*q;
	int len;	//ͳ�ƽڵ��������ѧ������ 
	int choose;	//����ѡ������ʽ 
	len=0;
	q=head;
	
	//���ͷ�ڵ�Ϊ�� 
	if(head==NULL)
	{
		printf("����ʧ�ܣ�ѧ����Ϣ���������κ���Ϣ��\n");
		system("pause");
		system("cls");
		return;
	}
	//ͳ�ƽڵ� 
	while(q!=NULL)
	{
		q=q->next;
		len++;
	}
	printf("*****************************************\n");
	printf("*\tѧ���ɼ�����\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t��������2������ʽ��ѡ:\t*\n");
	printf("*\t1�����ܳɼ�����\t\t\t*\n");
	printf("*\t2�����ܳɼ�����\t\t\t*\n");
	printf("*****************************************\n");
	printf("��ѡ��");
	scanf("%d",&choose);
	
	//ͨ��ѡ��ͬ�ķ�ʽ�������򣬵���ð�������㷨���� 
	switch(choose)
	{
		case 1:
			BubbleSort(len,p,choose);
			break;
		case 2:
			BubbleSort(len,p,choose);
			break;
		default:	//��ֹ�������ѡ�� 
			printf("ѡ�������Ϊ�����ڴ���ѡ��!\n");
			system("pause");
			system("cls");
			break; 
	}
	printf("����ɹ������ڹ���2�в鿴��\n"); 	//����ɹ������ͨ����ʾ�����鿴������ 
	system("pause");
	system("cls");
}


//��ѧ�Ų���ѧ����Ϣ 
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
	printf("\t\t\t������Ҫ����ѧ������Ϣ:\n\n");
	printf("***��ʼ������Ϣ����ȷ����Ϣ��ȷ***\n");
	printf("������������");
	scanf("%s",NewStudent->name);
	printf("������ѧ�ţ�");
	scanf("%d",&NewStudent->number);
	printf("�������Ա�");
	scanf("%s",NewStudent->sex);
	printf("���������䣺");
	scanf("%d",&NewStudent->age);
	printf("������ɼ���");
	scanf("%d",&NewStudent->score);
	printf("�������\n");
	system("pause");
	system("cls");
}


 
//ɾ��ĳ��ѧ������Ϣ����ѧ�Ž��в��ң���Ϊ��������ͬ������� 
void DeleteStuInfo()
{
	Students *p,*BeforeNode;
	p=head;
	int StuNum;
	int choose;
	//���ͷ�ڵ�Ϊ�� 
	if(head==NULL)
	{
		printf("����ѧ����Ϣ,����������ԡ�\n");
		system("pause");
		system("cls");
		return;
	}
	printf("�������㽫ɾ����ѧ����ѧ�ţ�");
	scanf("%d",&StuNum);
	
	//����ѧ�� 
	while(p!=NULL&&p->number!=StuNum)
	{
		BeforeNode=p;
		p=p->next;
	}
	
	//����ʧ�ܣ�����������ѧ�Ŵ��������Ϣ����û�и�ѧ�� 
	if(p==NULL)
	{
		printf("ɾ��ʧ�ܣ�ѧ����Ϣ���в�δ�鵽��ѧ��\n");
		system("pause");
		system("cls");
		return;
	}
 
	printf("�㽫ɾ����ѧ���ǣ�%s��ѧ��Ϊ��%d\n",p->name,p->number);	//��ʾ��Ҫɾ����ѧ����ѧ�ź����� 
	printf("��ȷ��Ҫɾ����ͬѧ����Ϣ��(��ѡ��1����ѡ��2)\n");	//��ֹʧ��ѧ����Ϣɾ������� 
	printf("��ѡ��");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			if(p==head)	//���ɾ����ѧ������ͷ�ڵ� 
				head=p->next;
			else	//���ɾ����ѧ������β�ڵ�������м�ڵ� 
				BeforeNode->next=p->next;
			printf("ɾ���ɹ���\n");
			break;
		case 2:
			printf("ɾ��ʧ�ܣ��������ɾ��ָ�\n");
			break;
	}
	system("pause");
	system("cls");
}



//������ 
int main()
{
	int choise;
	while(1)
	{
		Menu();	//�ȵ��ò˵����� 
		printf("��ѡ��");
		scanf("%d",&choise);
		
		//�ߴ��� 
		switch(choise)
		{
			case 1:
				InputStudent();	//¼�빦�� 
				break;
			case 2:
				PrintStuInfo();	//��ʾ���� 
				break;
			case 3:
				FindStudent();	//���ҹ��� 
				break;
			case 4:
				SortStudents();	//������ 
				break;
			case 5:
				InsertStudent();//���빦�� 
				break;
			case 6:
				DeleteStuInfo();//ɾ������ 
				break;
			case 7:	//�˳����� 
				printf("�����˳�ѧ���ɼ�����ϵͳ����ӭ�´�ʹ�ã�");
				return 0;
				break;
			default:	//��ֹ������� 
				printf("ѡ�������Ϊ�����ڴ���ѡ��!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}

