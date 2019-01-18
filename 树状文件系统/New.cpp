#include"FileSystem.h"


string error[]={"{","}","/","\\", ":","<",">","|","*","&"} ;  //命名中的非法字符

int FileSystem::newFile()    //创建文件
{
	MyFile *p = NULL;
	p=new MyFile;
	
	cin>>p->name;
	/*命名检测，是否含有非法字符*/
	string tempname(p->name);
	for(int i=0;i<8;i++)
	{
		if(tempname.find(error[i],0)!=string::npos) //从字符串的下标为0处开始查找error[i],如果没找到，返回一个特别的标志c++中用npos表示
		{
			cout<<"THE NAME IS ILLEGAL     --FAILED"<<endl;
			return 0;
		}
	}
	 /*创建时候情况如下
     * 1. 目录下没有文件
     * 2. 目录下有文件，新文件命名冲突
     * 3. 目录下有文件，新文件无命名冲突
     * */


	/*检测有无同名函数*/
	
	if(currentDir->filePtr==NULL) /*目录下没有文件*/
	{
		p->nextFile=currentDir->filePtr;
		currentDir->filePtr=p;                                                                                                                                                                                                                                         
	}
	else   /*目录下有文件，新文件命名冲突*/
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
		/*重置链表结构*/
		p->nextFile=currentDir->filePtr;
		currentDir->filePtr=p;
		MyDir *h=currentDir;
		/*更改上级目录的大小*/
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


int FileSystem::newDir()   //创建目录
{
    MyDir *p, *h;
    p = new MyDir;
    cin >> p->name;

    /*命名检测*/
    string tempname(p->name) ;
    for(int i = 0 ;i< 8 ;++i)
    {
        if(tempname.find(error[i],0)!=string::npos)
        {
            cout<<"THE NAME IS ILLEGAL     --FAILED"<<endl;
            return 0 ;
        }
    }

    /*初始化*/
    p->dirPtr = NULL;
    p->size = 0;
    p->filePtr = NULL;
    p->nextDir = NULL;
    if (currentDir->dirPtr == NULL)
        h = NULL;
    else
        h = currentDir->dirPtr;

    /*创建时候情况如下
     * 1. 目录下没有子目录
     * 2. 目录下有子目录，命名冲突
     * 3. 目录下有子目录，无命名冲突
     * */

    /*检测有无同名目录*/
     while (h != NULL) 
	{
        if (strcmp(h->name, p->name)==0) 
		{
            cout << "THE DIR HAS EXISTED      --FAILED" << endl;
            return 0;
        }
        h = h->nextDir;
    }

    /*重置链表结构*/
    p->preDir = currentDir;
    p->nextDir = currentDir->dirPtr;
    currentDir->dirPtr = p;

	cout<<"THE DIR CREATE           --SUCCEED"<<endl;
    return 1;
}