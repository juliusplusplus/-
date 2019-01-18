#include"FileSystem.h"

int FileSystem::showCurrentDir()  //显示当前目录内容
{
    MyDir *d = currentDir->dirPtr;
    MyFile *f = currentDir->filePtr;
    if (d == NULL && f == NULL) 
	{
        cout << "EMPTY!" << endl;
        return 0;
    }
    cout << "\t*******当前目录下内容:*******" << endl;

    if (d != NULL) 
	{
        cout << "\t" << "Dir_name" << "\t" << "Dir_size" << endl;
        while (d != NULL) 
		{
            cout << "\t" << d->name << "\t\t"<< d->size << endl;
            d = d->nextDir;
        }
        cout << endl;
    }

    if (f != NULL) 
	{
        cout << "\t" << "File_name" << "\t" << "File_size" << "\t" << endl;
        while (f != NULL) 
		{
            cout << "\t" << f->name << "\t\t" << f->size << "\t" << endl;
            f = f->nextFile;
        }
    }
    return 1;
}

int FileSystem::showPath()//显示当前路径
{
    show_path(currentDir);
    return 1;
}

int FileSystem::show_path(MyDir *d)     //实现显示当前路径的函数
{
    if (d->preDir == NULL)
        cout << root->name;
    if (d->preDir != NULL) 
	{
        this->show_path(d->preDir);     //递归调用此函数
        cout << d->name;
    }
    cout << "/";
    return 1;
}

int FileSystem::goback() //返回上一级目录
{
    if (currentDir->preDir == NULL) 
	{
        cout << "IT IS  ALREADY ROOT" << endl;
        return 0;
    }
    currentDir = currentDir->preDir;
    return 1;
}


int FileSystem::getSize() //获得用户所在目录大小
{
    return size;
}

MyDir *FileSystem::getCurrentdir()   //获得当前目录
{
    return currentDir;
}
