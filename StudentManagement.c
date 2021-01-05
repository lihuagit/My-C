#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Write();
void Read();

struct student      //����ѧ����Ϣ�ṹ��
{
    char id[15],name[15];
    int Math,English,Chinese;
} st[1000];     //1000�� ������ �����ټ�
int total;      //����ͳ��ѧ��������
FILE* pf;       //�ļ�ָ��

void Write_1()  //�״�д����Ϣ
{
    int i,n;
    printf("������Ҫ��ӵ�ѧ��������\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("������ѧ��ѧ�ţ�");
        scanf("%s",&st[i].id);
        printf("������ѧ��������");
        scanf("%s",&st[i].name);
        printf("������ѧ����ѧ�ɼ���");
        scanf("%d",&st[i].Math);
        printf("������ѧ��Ӣ��ɼ���");
        scanf("%d",&st[i].English);
        printf("������ѧ�����ĳɼ���");
        scanf("%d",&st[i].Chinese);
        printf("\n");
    }
    total=n;
    Write();
}

void Read()     //��ȡ�ı�(ѧ��)����
{
    int i=0;    //ͳ��ѧ������
    pf=fopen("E:\\test.txt","r");
	if (!pf)
	{
		printf("file cannot open!");
		exit(1);
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
	pf = fopen("E:\\test.txt", "w");
	if (!pf)
	{
		printf("file cannot open!");
		exit(1);
	}
    for(i=0;i<total;i++)
        fprintf(pf,"%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
    fclose(pf);
}

void Add()      //����ѧ����Ϣ
{
    int i,n;
    Read();
    printf("������Ҫ��ӵ�ѧ��������\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("������ѧ��ѧ�ţ�");
        scanf("%s",&st[total+i].id);
        printf("������ѧ��������");
        scanf("%s",&st[total+i].name);
        printf("������ѧ����ѧ�ɼ���");
        scanf("%d",&st[total+i].Math);
        printf("������ѧ��Ӣ��ɼ���");
        scanf("%d",&st[total+i].English);
        printf("������ѧ�����ĳɼ���");
        scanf("%d",&st[total+i].Chinese);
        printf("\n");
    }
    total+=n;
    Write();
}

void ModifyDo(int i)    //�޸�ѧ����Ϣ
{
    printf("�������޸�ѧ��ѧ�ţ�");
    scanf("%s",&st[i].id);
    printf("�������޸�ѧ��������");
    scanf("%s",&st[i].name);
    printf("�������޸�ѧ����ѧ�ɼ���");
    scanf("%d",&st[i].Math);
    printf("�������޸�ѧ��Ӣ��ɼ���");
    scanf("%d",&st[i].English);
    printf("�������޸�ѧ�����ĳɼ���");
    scanf("%d",&st[i].Chinese);
}

void Modify()           //����Ҫ�޸ĵ�ѧ��
{
    Read();
    int i,n,m=1;        //m==ѭ�����أ�n==�޸ĵ�ѡ��
    char buf[15];       //�������Ŀ��
    while(m){
        printf("��������Ҫ�޸ĵ�ѧ��ѧ��������1����������Ҫ�޸ĵ�ѧ������������2\n�����룺");
        scanf("%d",&n);
        switch (n){
            case 1:
                printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                        ModifyDo(i);
                        m=0;
                        printf("�޸ĳɹ�������\n");
                        break;
                    }
                if(m==1)
                    printf("����ѧ�Ŵ���򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                break;
            case 2:
                printf("������Ҫ�޸ĵ�ѧ��������\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                        ModifyDo(i);
                        printf("�޸ĳɹ�������\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("������������򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                break;
            default:
                printf("������󣡣���\n");
                break;
        }
            printf("��������޸�ѧ����Ϣ������1���˳�������0\n�����룺");
            scanf("%d",&m);
    }
    Write();
}

void Del()              //ɾ��ѧ����Ϣ
{
    Read();
    int i,n,m=1;        //m==ѭ�����أ�n==�޸ĵ�ѡ��
    char buf[15];       //�������Ŀ��
    while(m){
        printf("��������Ҫɾ����ѧ��ѧ��������1����������Ҫɾ����ѧ������������2\n�����룺");
        scanf("%d",&n);
        switch (n){   
            case 1:
                printf("������Ҫɾ����ѧ��ѧ�ţ�\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                        total-=1;
                        for(;i<total;i++)
                        st[i]=st[i+1];
                        printf("ɾ���ɹ�������\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("����ѧ�Ŵ���򲻴��ڸ�ѧ��������\n");
                break;
            case 2:
                printf("������Ҫɾ����ѧ��������\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                        total-=1;
                        for(;i<total;i++)
                        st[i]=st[i+1];
                        printf("ɾ���ɹ�������\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("������������򲻴��ڸ�ѧ��������\n");
                break;
            default:
                printf("������󣡣���\n");
                break;
        }
            printf("�������ɾ��ѧ����Ϣ������1���˳�������0\n�����룺");
            scanf("%d",&m);
    }
    Write();
}

void OrderPrint(int i)  //�����ӡ
{
    
    printf("\nѧ��\t\t����\t��ѧ�ɼ�\tӢ��ɼ�\t���ĳɼ�\n");
    switch (i)  //��������==1��˳������==0
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
            printf("������󣡣���\n");
            break;
    }
}

void OrderMath()    //����ѧ�ɼ����򲢴�ӡ
{
    Read();
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
    printf("�������������1��˳�����������0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("������󣡣���\n");
    
}

void OrderCh()      //�����ĳɼ����򲢴�ӡ
{
    Read();
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
    printf("˳�����������1���������������0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("������󣡣���\n");
}

void OrderEn()      //��Ӣ��ɼ����򲢴�ӡ
{
    Read();
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
    printf("˳�����������1���������������0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("������󣡣���\n");
}

void Order()        //ͳ������
{
    char buf[15];
    printf("������Ҫͳ�Ƶ�ѧ�ƣ�");
    scanf("%s",&buf);
    if(strcmp(buf,"��ѧ")==0)
        OrderMath();
    if(strcmp(buf,"Ӣ��")==0)
        OrderEn();
    if(strcmp(buf,"����")==0)
        OrderCh();
    if(strcmp(buf,"��ѧ")!=0 && strcmp(buf,"Ӣ��")!=0 && strcmp(buf,"����")!=0)
        printf("������󣡣���\n");
}

void Check()        //��ѯѧ����Ϣ
{
    Read();
    int i,n,m=1;
    char buf[15];
    while(m){
        printf("��������Ҫ��ѯ��ѧ��ѧ��������1����������Ҫ��ѯ��ѧ������������2\n�����룺");
        scanf("%d",&n);
        switch (n){   
            case 1:
                printf("������Ҫ��ѯ��ѧ����ѧ�ţ�\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                            printf("%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                            m=0;
                            break;
                        }
                    if(m==1){
                    printf("����ѧ�Ŵ���򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                    }
                break;
            case 2:
                printf("������Ҫ��ѯ��ѧ��������\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                            printf("%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                            m=0;
                            break;
                        }
                    if(m==1){
                    printf("������������򲻴��ڸ�ѧ�����ѧ����Ϣ���󣡣���\n");
                    }
                break;
            default:
                printf("������󣡣���\n");
                break;
        }
            printf("���������ѯѧ����Ϣ������1���˳�������0\n�����룺");
            scanf("%d",&m);
    }
    Write();
}

void ConditionMath()    //ͳ����ѧ��ָ���������������ӡ
{
    int i,j;
    int max,min;    //������
    Read();
    printf("������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("������Ҫͳ�Ƶķ������ֵ��");
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
    Read();
    printf("������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("������Ҫͳ�Ƶķ������ֵ��");
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
    Read();
    printf("������Ҫͳ�Ƶķ�����Сֵ��");
    scanf("%d",&min);
    printf("������Ҫͳ�Ƶķ������ֵ��");
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
    char buf[15];
    printf("������Ҫͳ�Ƶ�ѧ�ƣ�");
    scanf("%s",&buf);
    if(strcmp(buf,"��ѧ")==0)
        ConditionMath();
    if(strcmp(buf,"Ӣ��")==0)
        ConditionEn();
    if(strcmp(buf,"����")==0)
        ConditionCh();
    if(strcmp(buf,"��ѧ")!=0 && strcmp(buf,"Ӣ��")!=0 && strcmp(buf,"����")!=0)
        printf("������󣡣���\n");
}

int main()      //������
{
    int n;  //����ѡ��
    int m=1;    //��������
    printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
    while(m)
    {
        printf("\n\n\n\n\n\n");
        printf("0==�״�д��ѧ�����ݣ�1==����ѧ����Ϣ��2==ɾ��ѧ����Ϣ��3==�޸�ѧ����Ϣ\n4==��ѯѧ����Ϣ��5==�ɼ�ͳ��,6==����ͳ������\n");
        printf("�������������:");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                Write_1();
                break;
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
            default:
                printf("������󣡣���\n");
                break;
        }
        printf("�����������������1���˳�������0\n�����룺");
        scanf("%d",&m);
    }
    return 0;
}
