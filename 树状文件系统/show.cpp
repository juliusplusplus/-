#include"FileSystem.h"

int FileSystem::showCurrentDir()  //��ʾ��ǰĿ¼����
{
    MyDir *d = currentDir->dirPtr;
    MyFile *f = currentDir->filePtr;
    if (d == NULL && f == NULL) 
	{
        cout << "EMPTY!" << endl;
        return 0;
    }
    cout << "\t*******��ǰĿ¼������:*******" << endl;

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

int FileSystem::showPath()//��ʾ��ǰ·��
{
    show_path(currentDir);
    return 1;
}

int FileSystem::show_path(MyDir *d)     //ʵ����ʾ��ǰ·���ĺ���
{
    if (d->preDir == NULL)
        cout << root->name;
    if (d->preDir != NULL) 
	{
        this->show_path(d->preDir);     //�ݹ���ô˺���
        cout << d->name;
    }
    cout << "/";
    return 1;
}

int FileSystem::goback() //������һ��Ŀ¼
{
    if (currentDir->preDir == NULL) 
	{
        cout << "IT IS  ALREADY ROOT" << endl;
        return 0;
    }
    currentDir = currentDir->preDir;
    return 1;
}


int FileSystem::getSize() //����û�����Ŀ¼��С
{
    return size;
}

MyDir *FileSystem::getCurrentdir()   //��õ�ǰĿ¼
{
    return currentDir;
}
