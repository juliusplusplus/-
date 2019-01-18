#include"FileSystem.h"

MyFile *FileSystem::copy_file(MyFile *h)   //�����ļ�
{
    MyFile *f;
    f = new MyFile;
    f->size = h->size;
    strcpy_s(f->name, h->name);
    f->content = h->content;
	f->nextFile=0;   //��ʼ����һ��ָ���ָ��
    return f;
}

MyFile *FileSystem::copyFile() //�����ļ�ǰ���߼��ж�
{
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
    cout <<"THE FILE HAS BEEN COPIED          --SUCCEED   " << endl;
    return copytempfile;
}
/*MyFile *FileSystem::copyFile2() //�����ļ�ǰ���߼��ж�
{
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
    return copytempfile;
	
}*/

MyDir *FileSystem::copy_dir(MyDir *d)    //����Ŀ¼
{
    MyFile *fh;   //������Ŀ¼����ʱ�ļ�ָ��
    MyDir *dh;    //������Ŀ¼����ʱĿ¼ָ��
	MyDir  *dir;     //���Ƶõ���Ŀ¼
	//��ʼ��
    dir = new MyDir;
    dir->dirPtr = NULL;
    dir->filePtr = NULL;
    dir->nextDir = NULL;
    dir->preDir = NULL;
    fh = d->filePtr;
    dh = d->dirPtr;
    //����Ŀ¼�µ��ļ�
    while (fh != NULL) 
	{
        MyFile *f;
        f = copy_file(fh);
        f->nextFile = dir->filePtr;
        dir->filePtr = f;
        fh = fh->nextFile;
    }
    //������Ŀ¼
    while (dh != NULL) 
	{
        MyDir *d1, *d2;
        d1 = copy_dir(dh);
        d1->preDir = dir;
        dir->dirPtr = d1;
        d2 = dh->nextDir;  //d2ָ�򱻸���Ŀ¼����Ŀ¼
        while (d2 != NULL)    //����Ŀ¼һ�������Ƶ�d1��Ȼ����Ϊdir����Ŀ¼     
		{
            d1->nextDir = copy_dir(d2);

            d2 = d2->nextDir;
            d1 = d1->nextDir;
            d1->preDir = dir;
        }

        dh = dh->dirPtr;     //ѭ������Ŀ¼����Ŀ¼���и���
    }

    strcpy_s(dir->name, d->name);
    dir->size = d->size;
    return dir;
}

MyDir *FileSystem::copyDir()   //����Ŀ¼ǰ���߼��ж�
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
    cout << "THE DIR HAS BEEN CPOIED           --SUCCEED" << endl;
    return copytempdir;
}

/*MyDir *FileSystem::copyDir2()   //����Ŀ¼ǰ���߼��ж�
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
    return copytempdir;
}*/
