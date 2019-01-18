#include"FileSystem.h"
int FileSystem::readDir()     //打开目录
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


int FileSystem::readFile()    //读文件
{
    char n[MAX_NAME];
    cin >> n;
    MyFile *f = currentDir->filePtr;
    while (f != 0) 
	{
        if (strcmp(f->name, n)==0) //查找名为n的文件
		{
            cout << f->content << endl;  //输出内容
            return 1;
        }
        f = f->nextFile;
    }
    cout << "NO SUCH FILE          --FAILED" << endl;
    return 0;
}