#include"FileSystem.h"
int FileSystem::readDir()     //��Ŀ¼
{
    char name[MAX_NAME];
    MyDir *p;
    p = currentDir->dirPtr;

    cin >> name;
    while (p != NULL) 
	{
        if (strcmp(p->name, name) == 0) 
		{
            currentDir = p;
            return 1;
        }
        p = p->nextDir;
    }
    cout << "NO SUCH DIR      --FAILED" << endl;
    return 0;
}


int FileSystem::readFile()    //���ļ�
{
    char n[MAX_NAME];
    cin >> n;
    MyFile *f = currentDir->filePtr;
    while (f != 0) 
	{
        if (strcmp(f->name, n)==0) //������Ϊn���ļ�
		{
            cout << f->content << endl;  //�������
            return 1;
        }
        f = f->nextFile;
    }
    cout << "NO SUCH FILE          --FAILED" << endl;
    return 0;
}