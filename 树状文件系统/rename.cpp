#include"FileSystem.h"


int FileSystem::renameFile()     //�������ļ�
{
    MyFile *h;
    char n1[MAX_NAME], n2[MAX_NAME];
    cin >> n1;
    cin >> n2;
    h = currentDir->filePtr;
    while (h != NULL) 
	{
        if (!strcmp(h->name, n2))     //�Ѿ�����
		{
            cout << "THE NAME HAS BEEN EXISTED          --FAILED" << endl;
            return 0;
        }
        h = h->nextFile;
    }
    h = currentDir->filePtr;
    while (h != NULL)      //Ҫ�����Ķ����Ƿ����
	{
        if (!strcmp(h->name, n1))
            break;
        h = h->nextFile;
    }
 
    if (h == NULL)         
	{
        cout << "NO SUCH FILE            --FAILED" << endl;
        return 0;
    }
    strcpy_s(h->name, n2);
    cout << "RENAME IT              --SUCCEED!" << endl;
    return 1;
}

int FileSystem::renameDir()    //������Ŀ¼
{
    MyDir *h;
    char n1[MAX_NAME], n2[MAX_NAME];
    cin >> n1;
    cin >> n2;
    h = currentDir->dirPtr;
    while (h != NULL)    
	{
        if (strcmp(h->name, n2)==0)      //�Ѿ�����
		{
            cout << "THE NAME HAS BEEN EXISTED          --FAILED" << endl;
            return 0;
        }
        h = h->nextDir;
    }
    h = currentDir->dirPtr;
    while (h != NULL)               //Ҫ�����Ķ����Ƿ����
	{
        if (strcmp(h->name, n1)==0)
            break;
        h = h->nextDir;
    }
    if (h == NULL) 
	{
        cout << "NO SUCH DIR          --FAILED" << endl;
        return 0;
    }
    strcpy_s(h->name, n2);          
   cout << "RENAME IT              --SUCCEED!" << endl;
    return 1;
}