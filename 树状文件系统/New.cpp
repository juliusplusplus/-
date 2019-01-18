#include"FileSystem.h"


string error[]={"{","}","/","\\", ":","<",">","|","*","&"} ;  //�����еķǷ��ַ�

int FileSystem::newFile()    //�����ļ�
{
	MyFile *p = NULL;
	p=new MyFile;
	
	cin>>p->name;
	/*������⣬�Ƿ��зǷ��ַ�*/
	string tempname(p->name);
	for(int i=0;i<8;i++)
	{
		if(tempname.find(error[i],0)!=string::npos) //���ַ������±�Ϊ0����ʼ����error[i],���û�ҵ�������һ���ر�ı�־c++����npos��ʾ
		{
			cout<<"THE NAME IS ILLEGAL     --FAILED"<<endl;
			return 0;
		}
	}
	 /*����ʱ���������
     * 1. Ŀ¼��û���ļ�
     * 2. Ŀ¼�����ļ������ļ�������ͻ
     * 3. Ŀ¼�����ļ������ļ���������ͻ
     * */


	/*�������ͬ������*/
	
	if(currentDir->filePtr==NULL) /*Ŀ¼��û���ļ�*/
	{
		p->nextFile=currentDir->filePtr;
		currentDir->filePtr=p;                                                                                                                                                                                                                                         
	}
	else   /*Ŀ¼�����ļ������ļ�������ͻ*/
	{
		MyFile *q=new MyFile;
		q=currentDir->filePtr;
		while(q!=NULL)
		{
			if(strcmp(p->name,q->name)==0)
			{
				cout<<"FILE HAS EXISTED     --FAILED"<<endl;
				return 0;
			}
			q=q->nextFile;
		}
		/*��������ṹ*/
		p->nextFile=currentDir->filePtr;
		currentDir->filePtr=p;
		MyDir *h=currentDir;
		/*�����ϼ�Ŀ¼�Ĵ�С*/
		while(h!=NULL)
		{
			h->size+=p->size;
			h=h->preDir;
		}
	}
	currentDir->filePtr->size=0;
	cout<<"CREATE FILE          --SUCCEED"<<endl;
	disk_empty=disk_empty-p->size;
	size+=p->size;
	return 1;
}


int FileSystem::newDir()   //����Ŀ¼
{
    MyDir *p, *h;
    p = new MyDir;
    cin >> p->name;

    /*�������*/
    string tempname(p->name) ;
    for(int i = 0 ;i< 8 ;++i)
    {
        if(tempname.find(error[i],0)!=string::npos)
        {
            cout<<"THE NAME IS ILLEGAL     --FAILED"<<endl;
            return 0 ;
        }
    }

    /*��ʼ��*/
    p->dirPtr = NULL;
    p->size = 0;
    p->filePtr = NULL;
    p->nextDir = NULL;
    if (currentDir->dirPtr == NULL)
        h = NULL;
    else
        h = currentDir->dirPtr;

    /*����ʱ���������
     * 1. Ŀ¼��û����Ŀ¼
     * 2. Ŀ¼������Ŀ¼��������ͻ
     * 3. Ŀ¼������Ŀ¼����������ͻ
     * */

    /*�������ͬ��Ŀ¼*/
     while (h != NULL) 
	{
        if (strcmp(h->name, p->name)==0) 
		{
            cout << "THE DIR HAS EXISTED      --FAILED" << endl;
            return 0;
        }
        h = h->nextDir;
    }

    /*��������ṹ*/
    p->preDir = currentDir;
    p->nextDir = currentDir->dirPtr;
    currentDir->dirPtr = p;

	cout<<"THE DIR CREATE           --SUCCEED"<<endl;
    return 1;
}