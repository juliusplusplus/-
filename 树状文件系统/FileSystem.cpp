#include"FileSystem.h"
FileSystem::FileSystem()   //���캯��
{
	size=0;
	currentDir=NULL;
	copytempfile=NULL;
	copytempdir=NULL;
	disk_empty=10;
}

FileSystem::~FileSystem()   //��������
{
	//disk_empty+=size;     //�ͷ��û���ռ�ռ�
	//size=0;                //�û���ʹ�õĿռ��С��0

	//MyDir *d=root;
	//MyFile *f=currentDir->filePtr;
	//while(f!=0)
	//{
	//	if(f->nextFile==0)
	//	{
	//		this->dele_file(f);
	//		f=0;
	//		break;
	//	}
	//	while(f->nextFile->nextFile!=0)    //����߿�ʼɾ��
	//		f=f->nextFile;
	//	this->dele_file(f->nextFile);
	//	f->nextFile=0;
	//	f=currentDir->filePtr;
	//}
	//while(d!=0)
	//{
	//	if(d->nextDir==0)
	//	{
	//		this->dele_dir(d);
	//		d=0;
	//		break;
	//	}
	//	while(d->nextDir->nextDir!=0)
	//		d=d->nextDir;
	//	this->dele_dir(d->nextDir);
	//	d->nextDir=0;
	//	d=root;
	//}
}

