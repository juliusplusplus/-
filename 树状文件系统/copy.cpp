#include"FileSystem.h"

MyFile *FileSystem::copy_file(MyFile *h)   //复制文件
{
    MyFile *f;
    f = new MyFile;
    f->size = h->size;
    strcpy_s(f->name, h->name);
    f->content = h->content;
	f->nextFile=0;   //初始化下一个指针的指向
    return f;
}

MyFile *FileSystem::copyFile() //复制文件前的逻辑判断
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
/*MyFile *FileSystem::copyFile2() //复制文件前的逻辑判断
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

MyDir *FileSystem::copy_dir(MyDir *d)    //复制目录
{
    MyFile *fh;   //被复制目录的临时文件指针
    MyDir *dh;    //被复制目录的临时目录指针
	MyDir  *dir;     //复制得到的目录
	//初始化
    dir = new MyDir;
    dir->dirPtr = NULL;
    dir->filePtr = NULL;
    dir->nextDir = NULL;
    dir->preDir = NULL;
    fh = d->filePtr;
    dh = d->dirPtr;
    //复制目录下的文件
    while (fh != NULL) 
	{
        MyFile *f;
        f = copy_file(fh);
        f->nextFile = dir->filePtr;
        dir->filePtr = f;
        fh = fh->nextFile;
    }
    //复制子目录
    while (dh != NULL) 
	{
        MyDir *d1, *d2;
        d1 = copy_dir(dh);
        d1->preDir = dir;
        dir->dirPtr = d1;
        d2 = dh->nextDir;  //d2指向被复制目录的子目录
        while (d2 != NULL)    //将子目录一个个复制到d1里然后作为dir的子目录     
		{
            d1->nextDir = copy_dir(d2);

            d2 = d2->nextDir;
            d1 = d1->nextDir;
            d1->preDir = dir;
        }

        dh = dh->dirPtr;     //循环将子目录的子目录进行复制
    }

    strcpy_s(dir->name, d->name);
    dir->size = d->size;
    return dir;
}

MyDir *FileSystem::copyDir()   //复制目录前的逻辑判断
{
    MyDir *h;
    char n[MAX_NAME];
    cin >> n;
    h = currentDir->dirPtr;
    while (h != NULL) 
	{
        if (!strcmp(h->name, n))         //被复制的目录存在判断
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

/*MyDir *FileSystem::copyDir2()   //复制目录前的逻辑判断
{
    MyDir *h;
    char n[MAX_NAME];
    cin >> n;
    h = currentDir->dirPtr;
    while (h != NULL) 
	{
        if (!strcmp(h->name, n))         //被复制的目录存在判断
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
