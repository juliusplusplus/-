
#include"FileSystem.h"

int FileSystem::pasteFile() //粘贴文件
{
	MyFile *h = currentDir->filePtr;
	MyFile *pTemp = h;
	if (copytempfile == NULL)
	{
		cout << "NO FILE HAS BEEN COPIED          --FAILED" << endl;
		return 0;
	}
	/*如果当前目录没有文件*/
	if (disk_empty < copytempfile->size)
	{
		cout << "NO ENOUGH SPACE            --FAILED";
		return 0;
	}
	if (h == NULL)
	{

		currentDir->filePtr = copy_file(copytempfile);
		currentDir->size += copytempfile->size;
		cout << "THE FILE HAS BEEN PASTED          --SUCCEED" << endl;
	}
	else
	{
		while (h != NULL)
		{
			if (!strcmp(h->name, copytempfile->name))
			{
				cout << "FILE HAS EXISTED        --FAILED" << endl;
				return 0;
			}
			break;
			h = h->nextFile;
		}

		if (disk_empty < copytempfile->size)
		{
			cout << "NO ENOUGH SPACE            --FAILED";
			return 0;
		}
		currentDir->filePtr = copy_file(copytempfile);
		currentDir->filePtr->nextFile = pTemp;
		currentDir->filePtr->nextFile = h;
		currentDir->size += copytempfile->size;
		cout << "THE FILE HAS BEEN PASTED          --SUCCEED" << endl;
		return 1;
	}
	return 0;

}
int FileSystem::pasteDir()    //粘贴目录
{
	MyDir *h, *d1;
	h = currentDir->dirPtr;

	if (copytempdir == NULL)
	{
		cout << "NO SUCH DIR HAS BEEN COPIED        --FAILED" << endl;
		return 0;
	}
	if (disk_empty < copytempdir->size)
	{
		cout << "NO ENOUGH SPACE     --FAILED";
		return 0;
	}
	while (1)
	{

		if (h = copytempdir->dirPtr)
		{
			cout << "THIS IS FATHER DIR,CAN'T PASTE        --FAILED" << endl;
			return 0;
		}
		if (h = root->dirPtr)
			break;
		h = h->preDir;
	}
	if (h == NULL) //是否有子目录,若无
	{

		disk_empty -= copytempdir->size;    //减去大小
		d1 = copy_dir(copytempdir);        //加入链表
		currentDir->dirPtr = d1;
		d1->preDir = currentDir;
		MyDir *df = currentDir;
		//更新父母目录大小
		while (df != NULL)
		{
			df->size += copytempdir->size;
			df = df->preDir;
		}
		delete df;


	}
	else
	{
		while (h != NULL)
		{
			if (!strcmp(h->name, copytempdir->name))
			{
				cout << "THE DIR HAS EXSITED           --FAILED" << endl;
				return 0;
			}
			h = h->nextDir;
		}


		disk_empty -= copytempdir->size;    //减去大小
		d1 = copy_dir(copytempdir);           //递归拷贝
		d1->nextDir = currentDir->dirPtr;
		currentDir->dirPtr = d1;
		d1->preDir = currentDir;
		currentDir->size += copytempdir->size;

	}
	cout << "THE DIR HAS BEEN PASTED              --SUCCEED" << endl;
	return 1;
}
