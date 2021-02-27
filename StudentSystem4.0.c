#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void Write();
void Read();

struct student      //����ѧ����Ϣ�ṹ��
{
    char id[15],name[15];
    int Math,English,Chinese;
} st[1000];     //1000�� ������ �����ټ�
int total;      //����ͳ��ѧ��������
FILE* pf;       //�ļ�ָ��

void RED() {//����̨����ǰ��ɫΪ��ɫ
	HANDLE kai_1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(kai_1, FOREGROUND_INTENSITY | FOREGROUND_RED); // Ϊ��ɫ
}

void GREEN() {//����̨����ǰ��ɫΪ��ɫ
	HANDLE kai_2 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(kai_2, FOREGROUND_INTENSITY | FOREGROUND_GREEN);// Ϊ��ɫ
}

void Input(int i)  //¼����Ϣ
{
    printf("\t\t������ѧ��ѧ�ţ�");
    scanf("%s",&st[i].id);
    printf("\t\t������ѧ��������");
    scanf("%s",&st[i].name);
    printf("\t\t������ѧ����ѧ�ɼ���");
    scanf("%d",&st[i].Math);
    printf("\t\t������ѧ��Ӣ��ɼ���");
    scanf("%d",&st[i].English);
    printf("\t\t������ѧ�����ĳɼ���");
    scanf("%d",&st[i].Chinese);
    printf("\n");
}

void Read()     //��ȡ�ı�(ѧ��)����
{
    int i=0;    //ͳ��ѧ������
    pf=fopen("D:\\StudentData.txt","r");
	if (!pf)
	{
    	pf=fopen("D:\\StudentData.txt","w+");
    	total=0;
    	return;
	}
    while(!feof(pf))
    {
        fscanf(pf,"%s\t%s\t%d\t%d\t%d\n",&st[i].id,&st[i].name,&st[i].Math,&st[i].English,&st[i].Chinese);
        i++;        //ͳ��ѧ������
    }
    fclose(pf);
    total=i;
}

void Write()    //д��ѧ����Ϣ
{
    int i;
	pf = fopen("D:\\StudentData.txt", "w");
	if (!pf)
	{
		printf("\t\tfile cannot open!");
		printf("\t\t��������˳�����:");
		getch();
		exit(1);
	}
    for(i=0;i<total;i++)
        fprintf(pf,"%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
    fclose(pf);
}

void Add()      //����ѧ����Ϣ
{
    int i,n;
    system("cls");
    GREEN();
    printf("\n-------------------����ѧ����Ϣ-------------------\n");
    printf("\n\t\t������Ҫ��ӵ�ѧ��������");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    	Input(total+i);
    total+=n;
    RED();
    printf("\n\t\t��ӳɹ�������\n");
    printf("\t\t���������ַ�����\n\n");
    getch();
}

void Modify()           //����Ҫ�޸ĵ�ѧ��
{
    int i,n,m=1;        //m==ѭ�����أ�n==�޸ĵ�ѡ��
    char buf[15];       //�������Ŀ��
    system("cls");
    GREEN();
    printf("--------��������Ҫ�޸ĵ�ѧ��ѧ��������1����������Ҫ�޸ĵ�ѧ������������2--------\n\n");
    printf("\t\t�����룺");
    scanf("%d",&n);
    switch (n){
        case 1:
	        printf("\t\t������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	        scanf("%s",&buf);
	        for(i=0;i<total;i++)
	            if(strcmp(st[i].id,buf)==0){
	                Input(i);
	                m=0;
	                RED();
	                printf("\n\t\t�����ɹ�������\n\n");
	                break;
	            }
	        if(m==1){
	            RED();
	            printf("\t����������ѧ�Ŵ���򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
	        }
	        break;
    	case 2:
        	printf("\t\t������Ҫ�޸ĵ�ѧ��������");
        	scanf("%s",&buf);
        	for(i=0;i<total;i++)
            	if(strcmp(st[i].name,buf)==0){
                	Input(i);
                	RED();
                	printf("\n\t\t�����ɹ�������\n\n");
                	m=0;
                	break;
            	}
            if(m==1){
                RED();
                printf("\t����������ѧ�Ŵ���򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
            }
            break;
    	default:
        	RED();
        	printf("\t\t������󣡣���\n");
        	break;
    }
    printf("\t\t���������ַ�����\n\n");
    getch();
}

void Del()              //ɾ��ѧ����Ϣ
{
    int i,n,m=1;        //m==ѭ�����أ�n==�޸ĵ�ѡ��
    char buf[15];       //�������Ŀ��
    system("cls");
    GREEN();
    printf("---------��������Ҫɾ����ѧ��ѧ��������1����������Ҫɾ����ѧ������������2--------\n\n");
    printf("\t\t�����룺");
    scanf("%d",&n);
    switch (n){   
        case 1:
            printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].id,buf)==0){
                    total-=1;
                    for(;i<total;i++)
                        st[i]=st[i+1];
                    RED();
                    printf("\t\tɾ���ɹ�������\n");
                    m=0;
                    break;
                }
            if(m==1){
                RED();
                printf("\t\t����ѧ�Ŵ���򲻴��ڸ�ѧ��������\n");
            }
            break;
        case 2:
            printf("\t\t������Ҫɾ����ѧ��������");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].name,buf)==0){
                    total-=1;
                    for(;i<total;i++)
                        st[i]=st[i+1];
                    RED();
                    printf("\t\tɾ���ɹ�������\n");
                	m=0;
                    break;
                }
            if(m==1){
                RED();
                printf("\t\t����ѧ�Ŵ���򲻴��ڸ�ѧ��������\n");
            }
            break;
        default:
            RED();
            printf("\t\t������󣡣���\n");
            break;
    }
    printf("\t\t���������ַ�����\n\n");
    getch();
}

void OrderPrint(int i)  //�����ӡ
{
    printf("\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
    switch (i)  //��������==1����������==0
    {
        case 0:
        {
            for(i=total-1;i>=0;i--){
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            }
            printf("\n");
            break;
        }
        case 1:
        {
            for(i=0;i<total;i++){
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            }
            printf("\n");
            break;
        }
        default:
        	RED();
            printf("\t\t������󣡣���\n");
            break;
    }
}

void OrderMath()    //����ѧ�ɼ����򲢴�ӡ
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].Math=0;   //���ڴ������ֵ������ʱ���м����
        for(j=0;j<total-i;j++)
        {
            if(st[j].Math>=st[total].Math){
                n=j;
                st[total].Math=st[j].Math;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t�������������1���������������0\n");
    printf("\t\t�����룺"); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t������󣡣���\n");
    }
}

void OrderCh()      //�����ĳɼ����򲢴�ӡ
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].Chinese=0;
        for(j=0;j<total-i;j++)
        {
            if(st[j].Chinese>=st[total].Chinese){
                n=j;
                st[total].Chinese=st[j].Chinese;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t�������������1���������������0\n");
    printf("\t\t�����룺"); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t������󣡣���\n");
    }
}

void OrderEn()      //��Ӣ��ɼ����򲢴�ӡ
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].English=0;
        for(j=0;j<total-i;j++)
        {
            if(st[j].English>=st[total].English){
                n=j;
                st[total].English=st[j].English;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t�������������1���������������0\n");
    printf("\t\t�����룺"); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t������󣡣���\n");
    }
}

void Order()        //ͳ������
{
	system("cls");
	GREEN();
    char buf[15];
    printf("--------ͳ������ ������γ̰�������������в���ӡ------\n\n");
    printf("\t\t�γ̣���ѧ ���� Ӣ��\n");
    printf("\t\t������Ҫͳ�Ƶ�ѧ�ƣ�");
    scanf("%s",&buf);
    if(strcmp(buf,"��ѧ")==0)
        OrderMath();
    if(strcmp(buf,"Ӣ��")==0)
        OrderEn();
    if(strcmp(buf,"����")==0)
        OrderCh();
    if(strcmp(buf,"��ѧ")!=0 && strcmp(buf,"Ӣ��")!=0 && strcmp(buf,"����")!=0){
    	RED();
        printf("\t\t������󣡣���\n");
    }
    printf("\t\t���������ַ�����\n\n");
    getch();
}

void Check()        //��ѯѧ����Ϣ
{
    int i,n,m=1;
    char buf[15];
    system("cls");
    GREEN();
    printf("--------��������Ҫ��ѯ��ѧ��ѧ��������1����������Ҫ��ѯ��ѧ������������2-----\n\n");
    printf("\t\t�����룺");
    scanf("%d",&n);
    switch (n){
        case 1:
            printf("\t\t������Ҫ��ѯ��ѧ����ѧ�ţ�");
            scanf("%s",&buf);
        	for(i=0;i<total;i++)
				if(strcmp(st[i].id,buf)==0){
                    printf("\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
                    printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                    m=0;
                    printf("\n");
                    break;
                    }
                if(m==1){
                    RED();
                    printf("\t\t����ѧ�Ŵ���򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                }
            break;
		case 2:
            printf("\t\t������Ҫ��ѯ��ѧ��������");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].name,buf)==0){
                    printf("\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
                    printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                    m=0;
                    printf("\n");
                    break;
                    }
                if(m==1){
                    RED();
                    printf("\t\t������������򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                }
            break;
        default:
            RED();
            printf("\t\t������󣡣���\n");
            break;
    }
    printf("\t\t���������ַ�����\n\n");
    getch();
}

void ConditionMath()    //ͳ����ѧ��ָ���������������ӡ
{
    int i,j;
    int max,min;    //������
    printf("\t\t������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("\t\t������Ҫͳ�Ƶķ������ֵ��");
    scanf("%d",&max);
    printf("\n\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].Math>=min && st[i].Math<=max)
        {  
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\n��ѧ�ɼ���%d��%d������һ����%d��\n\n",min,max,j);
}

void ConditionEn()      //ͳ��Ӣ����ָ���������������ӡ
{
    int i,j;
    int max,min;
    printf("\t\t������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("\t\t������Ҫͳ�Ƶķ������ֵ��");
    scanf("%d",&max);
    printf("\n\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].English>=min && st[i].English<=max)
        {  
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\nӢ��ɼ���%d��%d������һ����%d��\n\n",min,max,j);
}

void ConditionCh()      //ͳ��������ָ���������������ӡ
{
    int i,j;
    int max,min;
    printf("\t\t������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("\t\t������Ҫͳ�Ƶķ������ֵ��");
    scanf("%d",&max);
    printf("\n\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].Chinese>=min && st[i].Chinese<=max)
        {
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\n���ĳɼ���%d��%d������һ����%d��\n\n",min,max,j);
}

void Condition()        //ͳ��
{
	system("cls");
	GREEN();
    char buf[15];
    printf("-------�ɼ�ͳ�� ͳ������ѧ������������ε����------\n\n");
    printf("\t\t�γ̣���ѧ ���� Ӣ��\n");
    printf("\t\t������Ҫͳ�Ƶ�ѧ�ƣ�");
    scanf("%s",&buf);
    if(strcmp(buf,"��ѧ")==0)
        ConditionMath();
    if(strcmp(buf,"Ӣ��")==0)
        ConditionEn();
    if(strcmp(buf,"����")==0)
        ConditionCh();
    if(strcmp(buf,"��ѧ")!=0 && strcmp(buf,"Ӣ��")!=0 && strcmp(buf,"����")!=0)
        printf("/t/t������󣡣���\n");
    printf("\t\t���������ַ�����\n\n");
    getch();
}

int main()      //������
{
    int n;  //����ѡ��
    GREEN();
    Read();
    while(1)
    {
	    printf("------------��ӭʹ��ѧ����Ϣ����ϵͳ-------------\n");
	    printf("\n\t�����ļ�·����D:\\StudentData.txt\n");
        printf("\n\n\n");
        printf("\t\t1==����ѧ����Ϣ\n\t\t2==ɾ��ѧ����Ϣ\n\t\t3==�޸�ѧ����Ϣ\n\t\t4==��ѯѧ����Ϣ\n\t\t5==�ɼ�ͳ��\n\t\t6==����ͳ������\n\t\t7==���沢�˳�\n\n");
        printf("\t\t�������Ӧ��������:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                Add();
                break;
            case 2:
                Del();
                break;
            case 3:
                Modify();
                break;
            case 4:
                Check();
                break;
            case 5:
                Condition();
                break;
            case 6:
                Order();
                break;
            case 7:
				Write();
				RED();
				printf("\t\t����ɹ�������\n\n");
				return; 
            default:
                printf("������󣡣���\n");
                break;
        }
        GREEN();
        system("cls");
    }
    return 0;
}
