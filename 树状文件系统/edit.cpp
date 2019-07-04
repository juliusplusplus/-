#include"FileSystem.h"
int FileSystem::edit()    //编辑文件
{
    char n[MAX_NAME];//文件名最大长度
    string s;
    cin >> n;
    MyFile *f = currentDir->filePtr;
    while (f != 0) 
	{
        if (!strcmp(f->name, n)) 
		{
            cin >> s;
            disk_empty -= s.length();		//存磁盘空间
			if (disk_empty < 0) {
				cout << "NO ENOUGH SPACE     --FAILED" << endl;
				return 1;
			}
			f->content = s;				//存内容
			f->size = s.length();		//存大小
            MyDir *d = currentDir;
            while (d != 0)//修改编辑文件后各级目录的大小
            {
                d->size += f->size;
                d = d->preDir;
            }
             cout << "THE FILE HAS BEEN EDITED       --SUCCEED" << endl;
            size += f->size;
            return 1;
        }
        f = f->nextFile;
    }

    cout << "NO SUCH FILE     --FAILED" << endl;
    return 0;
}
