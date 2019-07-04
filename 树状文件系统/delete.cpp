#include"FileSystem.h"
int FileSystem::dele_file(MyFile *f)   //删除文件
{
    delete f;
    f = NULL;
    return 1;
	
}
int FileSystem::deleteFile()    //删除文件前的逻辑判断
{
    char temp[MAX_NAME];
    cin >> temp;
    MyFile *f;           //指向找到的文件
    MyFile *above = NULL;
    f = currentDir->filePtr;

    /*
     * 判断该目录下有无需要删除的文件
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
    while (d != 0) //修改删除文件后各级目录的大小
    {
        d->size -= f->size;
        d = d->preDir;  //
    }

    /*
     * 删除时考虑
     * 1. 需要删除的文件恰好是目录文件链表中的头节点
     * 2. 需要删除的文件在链表中间
     * */
    if(copytempfile!=NULL)
	if (!strcmp(f->name, copytempfile->name))
		copytempfile = NULL;
    if (f == currentDir->filePtr)//删除文件结点，如果是头结点的话
        currentDir->filePtr = currentDir->filePtr->nextFile;
    else
        above->nextFile = f->nextFile;
        size -= f->size;
        delete f;
        f = NULL;
        cout << "THE FILE HAS BEEN DELETED               --SUCCEED" << endl;
        return 1;
}
int FileSystem::deleteFile2()    //删除文件前的逻辑判断
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
   
    MyFile *f;           //指向找到的文件
    MyFile *above = NULL;
    f = currentDir->filePtr;

    /*
     * 判断该目录下有无需要删除的文件
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
    while (d != 0) //修改删除文件后各级目录的大小
    {
        d->size -= f->size;
        d = d->preDir;  //
    }

    /*
     * 删除时考虑
     * 1. 需要删除的文件恰好是目录文件链表中的头节点
     * 2. 需要删除的文件在链表中间
     * */
    //if(copytempfile!=NULL)
	//if (!strcmp(f->name, copytempfile->name))
	//	copytempfile = NULL;
    if (f == currentDir->filePtr)//删除文件结点，如果是头结点的话
        currentDir->filePtr = currentDir->filePtr->nextFile;
    else
        above->nextFile = f->nextFile;
        size -= f->size;
        delete f;
        f = NULL;
        //cout << "THE FILE HAS BEEN DELETED               --SUCCEED" << endl;
        return 1;
}


//存在问题
int FileSystem::dele_dir(MyDir *p)    //删除目录
{
	//MyDir *d =NULL;
	//d = p->dirPtr;
	MyDir *d = p->dirPtr;
	//MyFile *f = NULL;
	//f = p->filePtr;
    MyFile *f = p->filePtr;
    if (f != 0) 
	{
        while (p->filePtr->nextFile != NULL)//删除此目录下的文件
        {
            f = p->filePtr;
            while (f->nextFile->nextFile != NULL) //寻找最后一个文件结点
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
        while (p->dirPtr->nextDir != NULL)//删除此目录下的目录
        {
            d = p->dirPtr;
            while (d->nextDir->nextDir != NULL)//寻找最后一个文件结点
                d = d->nextDir;
            this->dele_dir(d->nextDir);//循环调用此函数
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
int FileSystem::deleteDir2() //删除目录前的逻辑判断
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
    
    

    MyDir *p, *pre = NULL;
    
    p = currentDir->dirPtr;
    //cin >> n; //删除的目录名

    /*查找所需要删除的目录*/
    while (p != NULL) 
	{
        if (strcmp(p->name, h->name)==0)
        {	
				break;
		}
		pre = p;
        p = p->nextDir;
    }
	/*未找到*/
    if (p == NULL) 
	{
        cout << "NO SUCH DIR       --FAILED" << endl;
        return 0;
    }

    /*删除目录时需要考虑
     * 1. 该目录处于父目录的目录链表的位置
     * 2. 该目录下是否有子目录或者子文件
     * */
//if(copytempdir!=NULL)
//if (!strcmp(p->name, copytempdir->name))
//		copytempdir = NULL;
	/*增加磁盘大小*/
    disk_empty += p->size;
    if (p == currentDir->dirPtr)
        currentDir->dirPtr = currentDir->dirPtr->nextDir;
    else
        pre->nextDir = p->nextDir;

    pre = currentDir;
    while (pre != NULL) //修改删除目录后各级目录大小
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
int FileSystem::deleteDir() //删除目录前的逻辑判断
{
    char n[MAX_NAME];

    MyDir *p, *pre = NULL;
    
    p = currentDir->dirPtr;
    cin >> n; //删除的目录名

    /*查找所需要删除的目录*/
    while (p != NULL) 
	{
        if (strcmp(p->name, n)==0)
        {	
				break;
		}
		pre = p;
        p = p->nextDir;
    }
	/*未找到*/
    if (p == NULL) 
	{
        cout << "NO SUCH DIR       --FAILED" << endl;
        return 0;
    }

    /*删除目录时需要考虑
     * 1. 该目录处于父目录的目录链表的位置
     * 2. 该目录下是否有子目录或者子文件
     * */
if(copytempdir!=NULL)					
if (!strcmp(p->name, copytempdir->name))
		copytempdir = NULL;
	/*增加磁盘大小*/
    disk_empty += p->size;
    if (p == currentDir->dirPtr)
        currentDir->dirPtr = currentDir->dirPtr->nextDir;
    else
        pre->nextDir = p->nextDir;

    pre = currentDir;
    while (pre != NULL) //修改删除目录后各级目录大小
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



