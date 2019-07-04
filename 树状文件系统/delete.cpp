#include"FileSystem.h"
int FileSystem::dele_file(MyFile *f)   //ɾ���ļ�
{
    delete f;
    f = NULL;
    return 1;
	
}
int FileSystem::deleteFile()    //ɾ���ļ�ǰ���߼��ж�
{
    char temp[MAX_NAME];
    cin >> temp;
    MyFile *f;           //ָ���ҵ����ļ�
    MyFile *above = NULL;
    f = currentDir->filePtr;

    /*
     * �жϸ�Ŀ¼��������Ҫɾ�����ļ�
     * */

    while (f != NULL) 
	{
        if (!strcmp(f->name, temp))
            break;
        above = f;
        f = f->nextFile;
    }
    if (f == NULL) 
	{
        cout << "NO SUCH FILE        --FAILED!" << endl;
        return 0;
    }
    disk_empty += f->size;
    MyDir *d = currentDir;
    while (d != 0) //�޸�ɾ���ļ������Ŀ¼�Ĵ�С
    {
        d->size -= f->size;
        d = d->preDir;  //
    }

    /*
     * ɾ��ʱ����
     * 1. ��Ҫɾ�����ļ�ǡ����Ŀ¼�ļ������е�ͷ�ڵ�
     * 2. ��Ҫɾ�����ļ��������м�
     * */
    if(copytempfile!=NULL)
	if (!strcmp(f->name, copytempfile->name))
		copytempfile = NULL;
    if (f == currentDir->filePtr)//ɾ���ļ���㣬�����ͷ���Ļ�
        currentDir->filePtr = currentDir->filePtr->nextFile;
    else
        above->nextFile = f->nextFile;
        size -= f->size;
        delete f;
        f = NULL;
        cout << "THE FILE HAS BEEN DELETED               --SUCCEED" << endl;
        return 1;
}
int FileSystem::deleteFile2()    //ɾ���ļ�ǰ���߼��ж�
{
    //char temp[MAX_NAME];
    //cin >> temp;
	MyFile *h;
    char n[MAX_NAME];
    cin >> n;
    h = currentDir->filePtr;

    while (h != NULL) 
	{
        if (!strcmp(h->name, n))
            break;
        h = h->nextFile;
    }
    if (h == NULL) 
	{
        cout << "NO SUCH FILE            --FAILED" << endl;
        return NULL;
    }
    copytempfile = copy_file(h);
    cout <<"THE FILE HAS BEEN CUT          --SUCCEED   " << endl;
   
    MyFile *f;           //ָ���ҵ����ļ�
    MyFile *above = NULL;
    f = currentDir->filePtr;

    /*
     * �жϸ�Ŀ¼��������Ҫɾ�����ļ�
     * */

    while (f != NULL) 
	{
        if (!strcmp(f->name, h->name))
            break;
        above = f;
        f = f->nextFile;
    }
    if (f == NULL) 
	{
        cout << "NO SUCH FILE        --FAILED!" << endl;
        return 0;
    }
    disk_empty += f->size;
    MyDir *d = currentDir;
    while (d != 0) //�޸�ɾ���ļ������Ŀ¼�Ĵ�С
    {
        d->size -= f->size;
        d = d->preDir;  //
    }

    /*
     * ɾ��ʱ����
     * 1. ��Ҫɾ�����ļ�ǡ����Ŀ¼�ļ������е�ͷ�ڵ�
     * 2. ��Ҫɾ�����ļ��������м�
     * */
    //if(copytempfile!=NULL)
	//if (!strcmp(f->name, copytempfile->name))
	//	copytempfile = NULL;
    if (f == currentDir->filePtr)//ɾ���ļ���㣬�����ͷ���Ļ�
        currentDir->filePtr = currentDir->filePtr->nextFile;
    else
        above->nextFile = f->nextFile;
        size -= f->size;
        delete f;
        f = NULL;
        //cout << "THE FILE HAS BEEN DELETED               --SUCCEED" << endl;
        return 1;
}


//��������
int FileSystem::dele_dir(MyDir *p)    //ɾ��Ŀ¼
{
	//MyDir *d =NULL;
	//d = p->dirPtr;
	MyDir *d = p->dirPtr;
	//MyFile *f = NULL;
	//f = p->filePtr;
    MyFile *f = p->filePtr;
    if (f != 0) 
	{
        while (p->filePtr->nextFile != NULL)//ɾ����Ŀ¼�µ��ļ�
        {
            f = p->filePtr;
            while (f->nextFile->nextFile != NULL) //Ѱ�����һ���ļ����
                f = f->nextFile;
            this->dele_file(f->nextFile); 
            f->nextFile = NULL;
        }
        if (p->filePtr->nextFile == NULL) 
		{
            this->dele_file(p->filePtr);
            p->filePtr = NULL;
        }
    }
    if (d != NULL) 
	{
        while (p->dirPtr->nextDir != NULL)//ɾ����Ŀ¼�µ�Ŀ¼
        {
            d = p->dirPtr;
            while (d->nextDir->nextDir != NULL)//Ѱ�����һ���ļ����
                d = d->nextDir;
            this->dele_dir(d->nextDir);//ѭ�����ô˺���
            d->nextDir = NULL;
        }
        if (p->dirPtr->nextDir == NULL) 
		{
            this->dele_dir(p->dirPtr);
            p->dirPtr = NULL;
        }
    }
    delete p;
    p = NULL;
    return 1;
}
int FileSystem::deleteDir2() //ɾ��Ŀ¼ǰ���߼��ж�
{
	MyDir *h;
    char n[MAX_NAME];
    cin >> n;
    h = currentDir->dirPtr;
    while (h != NULL) 
	{
        if (!strcmp(h->name, n))         //�����Ƶ�Ŀ¼�����ж�
            break;
        h = h->nextDir;
    }
    if (h == NULL) 
	{
        cout << "NO SUCH DIR       --FAILED" << endl;
        return 0;
    }
    copytempdir = copy_dir(h);
    cout << "THE DIR HAS BEEN CUT           --SUCCEED" << endl;
    
    

    MyDir *p, *pre = NULL;
    
    p = currentDir->dirPtr;
    //cin >> n; //ɾ����Ŀ¼��

    /*��������Ҫɾ����Ŀ¼*/
    while (p != NULL) 
	{
        if (strcmp(p->name, h->name)==0)
        {	
				break;
		}
		pre = p;
        p = p->nextDir;
    }
	/*δ�ҵ�*/
    if (p == NULL) 
	{
        cout << "NO SUCH DIR       --FAILED" << endl;
        return 0;
    }

    /*ɾ��Ŀ¼ʱ��Ҫ����
     * 1. ��Ŀ¼���ڸ�Ŀ¼��Ŀ¼�����λ��
     * 2. ��Ŀ¼���Ƿ�����Ŀ¼�������ļ�
     * */
//if(copytempdir!=NULL)
//if (!strcmp(p->name, copytempdir->name))
//		copytempdir = NULL;
	/*���Ӵ��̴�С*/
    disk_empty += p->size;
    if (p == currentDir->dirPtr)
        currentDir->dirPtr = currentDir->dirPtr->nextDir;
    else
        pre->nextDir = p->nextDir;

    pre = currentDir;
    while (pre != NULL) //�޸�ɾ��Ŀ¼�����Ŀ¼��С
    {
        pre->size -= p->size;
        pre = pre->preDir;
    }
    size -= p->size;

    
    this->dele_dir(p);
	p = NULL;

    //cout << "THE DIR HAS BEEN DELETED       --SUCCEEDD" << endl;
    return 1;

}
int FileSystem::deleteDir() //ɾ��Ŀ¼ǰ���߼��ж�
{
    char n[MAX_NAME];

    MyDir *p, *pre = NULL;
    
    p = currentDir->dirPtr;
    cin >> n; //ɾ����Ŀ¼��

    /*��������Ҫɾ����Ŀ¼*/
    while (p != NULL) 
	{
        if (strcmp(p->name, n)==0)
        {	
				break;
		}
		pre = p;
        p = p->nextDir;
    }
	/*δ�ҵ�*/
    if (p == NULL) 
	{
        cout << "NO SUCH DIR       --FAILED" << endl;
        return 0;
    }

    /*ɾ��Ŀ¼ʱ��Ҫ����
     * 1. ��Ŀ¼���ڸ�Ŀ¼��Ŀ¼�����λ��
     * 2. ��Ŀ¼���Ƿ�����Ŀ¼�������ļ�
     * */
if(copytempdir!=NULL)					
if (!strcmp(p->name, copytempdir->name))
		copytempdir = NULL;
	/*���Ӵ��̴�С*/
    disk_empty += p->size;
    if (p == currentDir->dirPtr)
        currentDir->dirPtr = currentDir->dirPtr->nextDir;
    else
        pre->nextDir = p->nextDir;

    pre = currentDir;
    while (pre != NULL) //�޸�ɾ��Ŀ¼�����Ŀ¼��С
    {
        pre->size -= p->size;
        pre = pre->preDir;
    }
    size -= p->size;

    
    this->dele_dir(p);
	p = NULL;

    cout << "THE DIR HAS BEEN DELETED       --SUCCEEDD" << endl;
    return 1;

}



