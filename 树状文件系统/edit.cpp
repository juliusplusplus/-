#include"FileSystem.h"
int FileSystem::edit()    //�༭�ļ�
{
    char n[MAX_NAME];//�ļ�����󳤶�
    string s;
    cin >> n;
    MyFile *f = currentDir->filePtr;
    while (f != 0) 
	{
        if (!strcmp(f->name, n)) 
		{
            cin >> s;
            disk_empty -= s.length();		//����̿ռ�
			if (disk_empty < 0) {
				cout << "NO ENOUGH SPACE     --FAILED" << endl;
				return 1;
			}
			f->content = s;				//������
			f->size = s.length();		//���С
            MyDir *d = currentDir;
            while (d != 0)//�޸ı༭�ļ������Ŀ¼�Ĵ�С
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
