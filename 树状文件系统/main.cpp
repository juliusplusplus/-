#include<iostream>
#include"FileSystem.h"
#include<time.h>
using namespace std;
void menu()
{
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           ���ļ�������                                 ==" << endl;
    cout << "==  mk  <filename>                       ����ļ�                         ==" << endl;
    cout << "==  rm  <filename>                       ɾ���ļ�                         ==" << endl;
    cout << "==  rename  <pName>  <nName>             �������ļ�                       ==" << endl;
    cout << "==  cp  <filename>                       �����ļ�                         ==" << endl;
    cout << "==  paste                                ճ���ļ�                         ==" << endl;
    cout << "==  read   <filename>                    ��ȡ�ļ�                         ==" << endl;
    cout << "==  vi  <filename>+content               �༭�ļ�                         ==" << endl;
	cout << "==  cut  <filename>                      �����ļ�                         ==" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           ��Ŀ¼������                                 ==" << endl;
    cout << "==  mkdir  <dirname>                     �½�Ŀ¼                         ==" << endl;
    cout << "==  rmdir  <dirname>                     ɾ��Ŀ¼                         ==" << endl;
    cout << "==  renamedir  <pName>  <nName>          ������Ŀ¼                       ==" << endl;
    cout << "==  cpdir  <dirname>                     ����Ŀ¼                         ==" << endl;
	cout << "==  cutdir  <dirname>                    ����Ŀ¼                         ==" << endl;
    cout << "==  pastedir                             ճ��Ŀ¼                         ==" << endl;
    cout << "==  ls                                   ��ʾĿ¼����������               ==" << endl;
    cout << "==  cd  <dirname>                        ����һ��Ŀ¼                     ==" << endl;
    cout << "==  cd..                                 ������һ��Ŀ¼                   ==" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           ��ϵͳ������                                 ==" << endl;
    cout << "==  clear                                 ����                            ==" << endl;
    cout << "==  exit                                  ע��                            ==" << endl;
    cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
    cout<<endl;


}

void help() 
{

		cout << "\t\t=========================================================\t" << endl;
		cout << "\t\t=========================================================\t" << endl;                        
		cout << "\t\t==                     ��������                        ==\t" << endl;
		cout << "\t\t==      ���롰help��,��ʾ��������İ����ĵ���          ==\t" << endl;
		cout << "\t\t==      ����ĳ������+��?��ʱ��ʾ���������ʹ��˵��      ==\t" << endl;
		cout << "\t\t==      ����1��ʾ����                                  ==\t" << endl;
	    cout << "\t\t=========================================================\t" << endl;
		cout << "\t\t=========================================================\t" << endl;   
		while(1){
	string ch;
	cin>>ch;
		 if (ch == "help")
			{
                menu();
            }
			else if (ch == "mkdir?")
                cout << "\t\t������Ŀ¼dirname ����ʽΪ mkdir [dirname]" << endl;
            else if (ch == "mk?")
                cout << "\t\t�������ļ�filename����ʽΪ mk[filename]" << endl;
            else if (ch == "rmdir?")
                cout << "\t\tɾ����Ŀ¼dirname����ʽΪ rmdir [dirname]" << endl;
            else if (ch == "rm?")
                cout << "\t\tɾ���ļ�filename�������ʽΪ rm [filename]" << endl;
            else if (ch == "renamedir?")
                cout << "\t\tĿ¼������ " << endl;
            else if (ch == "rename?")
                cout << "\t\t�ļ������� " << endl;
            else if (ch == "cd?")
                cout << "\t\t����Ŀ¼dirname����ʽΪ cd [dirname]" << endl;
            else if (ch == "read?")
                cout << "\t\t�鿴�ļ�filename���ݣ���ʽΪ read [filename]" << endl;
			else if (ch == "cut?")
                cout << "\t\t�����ļ�filename����ʽΪ cut [filename]" << endl;
            else if (ch == "ls?")
                cout << "\t\t��ʾĿ¼�����б�" << endl;
            else if (ch == "cpdir?")
                cout << "\t\t������Ŀ¼dirname, ��ʽΪ cpDir [dirname]" << endl;
            else if (ch == "cp?")
                cout << "\t\t�����ļ�filename,��ʽΪ cp [filename]" << endl;
            else if (ch == "pastedir?")
                cout << "\t\tճ���Ѹ��Ƶ�Ŀ¼" << endl;
			else if (ch == "cutdir?")
				cout << "\t\t����Ŀ¼dirname����ʽΪ cutdir [dirname]" << endl;
            else if (ch == "paste?")
                cout << "\t\tճ���Ѹ��Ƶ��ļ�" << endl;
            else if (ch == "clear?")
                cout << "\t\t����" << endl;
            else if (ch == "vi?")
                cout << "\t\t�༭�ĵ�filename�������ʽΪ vi[filename]" << endl;
            else if (ch == "cd..?")
                cout << "\t\t���ص�ǰĿ¼����һ��Ŀ¼" << endl;
            else if (ch == "exit?")
                cout << "\t\tע���ļ�ϵͳ" << endl;
			else if (ch == "1")
				break;
            else
                cout << "\t\t������Ч��" << endl;
		}

}


/*�û�ע��д���ļ�����*/
int regist(char username[30], char password[30]) 
{
	
    FILE *cfptr;//�ļ�ָ��
    if ((cfptr = fopen("users.ini", "a+")) == NULL) 
	{
        
        fclose(cfptr);
        return 0;
    } 
	else 
	{
        fprintf(cfptr, "%s %s\n", username, password);
        fclose(cfptr);
        return 1;

    }
}
/*�û�����������飬�Ƿ��Ѿ�ע�ᣨ���ļ������ݱȽϣ�*/
int login(char username[30], char password[30]) 
{
    char user[30];
    char pass[30];
    FILE *cfptr;//�ļ�ָ��

    if ((cfptr = fopen("users.ini", "r")) == NULL) 
	{
        return -1;
    } 
	else 
	{
        while (!feof(cfptr)) 
		{
            fscanf(cfptr, "%s%s", user, pass);
            if ((strcmp(username, user) == 0) && (strcmp(password, pass) == 0)) 
			{
                fclose(cfptr);
                return 1;
            }
        }
    }
    fclose(cfptr);
    return 0;
}

int fsOperate(char name[30], char pass[30]) 
{
    FileSystem fs;
    fs.setUser(name, pass);
    while (1) 
	{
        system("CLS");
        menu();
        while (1) 
		{
            cout << endl;
            string choice;

            fs.showPath();
            cin >> choice;
            if (choice == "mkdir")
                fs.newDir();
            else if (choice == "mk")
                fs.newFile();
            else if (choice == "rmdir")
                fs.deleteDir();
            else if (choice == "rm")
                fs.deleteFile();
            else if (choice == "renamedir")
                fs.renameDir();
            else if (choice == "rename")
                fs.renameFile();
            else if (choice == "cd")
                fs.readDir();
            else if (choice == "read")
                fs.readFile();
            else if (choice == "ls")
                fs.showCurrentDir();
            else if (choice == "cpdir")
                fs.copyDir();
            else if (choice == "cp")
                fs.copyFile();
            else if (choice == "pastedir")
                fs.pasteDir();
			else if (choice == "cut")
			{
				//fs.copyFile2();
			    fs.deleteFile2();
			}
			else if (choice == "cutdir")
			{
				//fs.copyDir2();
			    fs.deleteDir2();
			}
           //else if (choice == "clrdir") 
		//	{
             // fs.ClrDir();
            //} 
            else if (choice == "paste") 
			{
                fs.pasteFile();
            } 
			else if (choice == "vi")
                fs.edit();
            else if (choice == "cd..")
                fs.goback();
            else if (choice == "clear") 
			{
                system("CLS");
            } 
			else if (choice == "exit") 
			{
                system("CLS");
                 Sleep(500);
                cout << "�û�: " << name << "����ע��...."<<endl;
				Sleep(500);
                
                return 0;
            } 
			else
				cout<<"������Ч���ɲ鿴������"<<endl;
        }
    }

}

void run()
{
    int choice = 0;
    char name[30], pass[30], pass1[30];
    while (true) 
	{
        system("CLS");
		time_t t = time(0);
		char tmp[64];
		strftime(tmp,sizeof(tmp),"\t                    %Y/%m/%d %X %a ",localtime(&t));
		puts(tmp);
		cout << "\t\t*********************************************\t" << endl;
		cout << "\t\t*********************************************\t" << endl; 
        cout << "\t\t**             ��  ��  ϵ  ͳ              **\t" << endl;
        cout << "\t\t**              1. ע�����û�              **\t" << endl;
        cout << "\t\t**              2. ��¼                    **\t" << endl;
        cout << "\t\t**              3. ����                    **\t" << endl;
        cout << "\t\t**              4. �˳�                    **\t" << endl;
		cout << "\t\t*********************************************\t" << endl;
		cout << "\t\t*********************************************\t" << endl;
        cout << "\t\t��ѡ��: " ;
        cin >> choice;
        switch (choice) 
		{
            /*ѡ��ע��*/
            case 1: 
				{
                        cout << "�������û���:";
                        cin >> name;
                        cout << "����������: ";
                        cin >> pass;
                        cout << "��ȷ������: ";
                        cin >> pass1;
                        while (strcmp(pass, pass1) != 0) 
						{
                            cout << "          --�������벻һ�£�������--" << endl;
                            cout << "����������: ";
                            cin >> pass;
                            cout << "��ȷ������: ";
                            cin >> pass1;
                        }
                        if (regist(name, pass) == 1)
						{
                            cout << "        --ע��ɹ�!^_^" << endl;
                             Sleep(200);
                        } 
                        else
						{
                            cout << "         --���棬�쳣����(>_<)" << endl;
                             Sleep(200);
                        }
                    }
                    break;

                    /*ѡ���¼*/
            case 2: {
                        cout << "�������û���:";
                        cin >> name;
                        cout << "����������:";
                        cin >> pass;
						if (login(name, pass) == -1)
						{
							cout << "          --���̴�ʧ�ܣ���������ļ� " << endl;
							Sleep(1000);
						}
                        else if (login(name, pass) == 1) 
						{
                            cout << "       --��¼�ɹ�--" << endl;
							Sleep(1000);
                            fsOperate(name, pass);
                        } 
						else
						{
                            cout << "          --��¼ʧ�ܣ������û���������.." << endl;
                             Sleep(1000);

                        }
					}
                        break;
            case 3:{
				        system("CLS");
            	        help();
						system("PAUSE");

            	     }
				        break;
           
            case 4: {
                        system("CLS");
                        Sleep(1000);
                        cout << "        --�����˳��ļ�ϵͳ.." << endl;
                        exit(0);
                    }
                    break;
                    /*����ѡ��*/
            default:
                    break;
        }
    }
}
int main()
{
	run();
	return 0;
}