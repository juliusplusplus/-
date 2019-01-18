#pragma warning(disable:4996) 
#include<iostream>
#include<string.h>
#include<string>
#include<iomanip>
#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
#define MAX_NAME 25


typedef  struct MyFile         //�ļ��ṹ��
{
    char name[MAX_NAME];      //�ļ��� 
    int size;                 //�ļ���С
    MyFile *nextFile;         //ָ���ļ��б�����һ���ļ�
    string content;           //�ļ�����
} MyFile;


typedef struct MyDir          //Ŀ¼�ṹ��
{
    char name[MAX_NAME];      //Ŀ¼����
    int size;                 //Ŀ¼��С
    MyDir *nextDir;           //���Ŀ¼
    MyDir *preDir;            //ǰ��Ŀ¼
    MyFile *filePtr;          //��Ŀ¼�µ��ļ�����ָ��
    MyDir *dirPtr;            //��Ŀ¼�µ�Ŀ¼����ָ��                                                              
} MyDir;


class FileSystem //�ļ�ϵͳ��
{

private:             //˽�м���

    MyDir *currentDir; //��ǰĿ¼
    MyFile *copytempfile; //���ڿ����ļ�ʱ����ʱ�ļ�
	//MyFile *copytempfile2;
    MyDir *copytempdir; //���ڿ���Ŀ¼ʱ����ʱĿ¼
	//MyFile *copytempdir2;
    MyDir *root; //��Ŀ¼

    char password[MAX_NAME];   //�û�����
    char name[MAX_NAME];   //�û�����
    int size; //�û���ʹ�ÿռ��С
	int disk_empty;  // ���̿��д�С

 public:
    FileSystem();  
    ~FileSystem();

    int newFile(); //�����ļ�
    int newDir(); //����Ŀ¼

    int dele_file(MyFile *file);//ɾ���ļ�
    int deleteFile(); //ɾ���ļ�ǰ���߼��ж�
	int deleteFile2(); //ɾ���ļ�ǰ���߼��ж�

    int dele_dir(MyDir *d); //ɾ��Ŀ¼
    int deleteDir(); //ɾ��Ŀ¼ǰ���߼��ж�
	int deleteDir2();
	//int ClrDir();//��ʽ��Ŀ¼

    int readDir(); //��Ŀ¼
    int readFile(); //���ļ�

    int renameDir(); //������Ŀ¼
    int renameFile(); //�������ļ�

    MyDir *copy_dir(MyDir *dir);//����Ŀ¼
    MyDir *copyDir(); //����Ŀ¼ǰ���߼��ж�
	//MyDir *copyDir2();

    MyFile *copy_file(MyFile *h); //�����ļ�
    MyFile *copyFile(); //�����ļ�ǰ���߼��ж�
    //MyFile *copyFile2();

    int pasteDir(); //ճ��Ŀ¼
    int pasteFile(); //ճ���ļ�
    int edit(); //�༭�ļ�

    int showCurrentDir(); //��ʾ��ǰĿ¼����

    int show_path(MyDir *dir); //��ʾ·���Ĳ���ʵ��
    int showPath(); //��ʾ·��

    int goback(); //������һ��Ŀ¼

    int setUser(char *, char *);//�����û���������

    int getSize();//����û�����Ŀ¼��С
    MyDir *getCurrentdir(); //��õ�ǰĿ¼
};

