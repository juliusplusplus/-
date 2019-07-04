#include<iostream>
#include"FileSystem.h"
#include<time.h>
using namespace std;
void menu()
{
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           【文件操作】                                 ==" << endl;
    cout << "==  mk  <filename>                       添加文件                         ==" << endl;
    cout << "==  rm  <filename>                       删除文件                         ==" << endl;
    cout << "==  rename  <pName>  <nName>             重命名文件                       ==" << endl;
    cout << "==  cp  <filename>                       复制文件                         ==" << endl;
    cout << "==  paste                                粘贴文件                         ==" << endl;
    cout << "==  read   <filename>                    读取文件                         ==" << endl;
    cout << "==  vi  <filename>+content               编辑文件                         ==" << endl;
	cout << "==  cut  <filename>                      剪切文件                         ==" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           【目录操作】                                 ==" << endl;
    cout << "==  mkdir  <dirname>                     新建目录                         ==" << endl;
    cout << "==  rmdir  <dirname>                     删除目录                         ==" << endl;
    cout << "==  renamedir  <pName>  <nName>          重命名目录                       ==" << endl;
    cout << "==  cpdir  <dirname>                     复制目录                         ==" << endl;
	cout << "==  cutdir  <dirname>                    剪切目录                         ==" << endl;
    cout << "==  pastedir                             粘贴目录                         ==" << endl;
    cout << "==  ls                                   显示目录下所有内容               ==" << endl;
    cout << "==  cd  <dirname>                        进入一个目录                     ==" << endl;
    cout << "==  cd..                                 返回上一级目录                   ==" << endl;
	cout << "============================================================================" << endl;
	cout << "==                           【系统操作】                                 ==" << endl;
    cout << "==  clear                                 清屏                            ==" << endl;
    cout << "==  exit                                  注销                            ==" << endl;
    cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
    cout<<endl;


}

void help() 
{

		cout << "\t\t=========================================================\t" << endl;
		cout << "\t\t=========================================================\t" << endl;                        
		cout << "\t\t==                     【帮助】                        ==\t" << endl;
		cout << "\t\t==      输入“help”,显示所有命令的帮助文档；          ==\t" << endl;
		cout << "\t\t==      输入某个命令+“?”时显示该条命令的使用说明      ==\t" << endl;
		cout << "\t\t==      输入1表示返回                                  ==\t" << endl;
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
                cout << "\t\t创建新目录dirname ，格式为 mkdir [dirname]" << endl;
            else if (ch == "mk?")
                cout << "\t\t创建新文件filename，格式为 mk[filename]" << endl;
            else if (ch == "rmdir?")
                cout << "\t\t删除子目录dirname，格式为 rmdir [dirname]" << endl;
            else if (ch == "rm?")
                cout << "\t\t删除文件filename，输入格式为 rm [filename]" << endl;
            else if (ch == "renamedir?")
                cout << "\t\t目录重命名 " << endl;
            else if (ch == "rename?")
                cout << "\t\t文件重命名 " << endl;
            else if (ch == "cd?")
                cout << "\t\t打开子目录dirname，格式为 cd [dirname]" << endl;
            else if (ch == "read?")
                cout << "\t\t查看文件filename内容，格式为 read [filename]" << endl;
			else if (ch == "cut?")
                cout << "\t\t剪切文件filename，格式为 cut [filename]" << endl;
            else if (ch == "ls?")
                cout << "\t\t显示目录内容列表" << endl;
            else if (ch == "cpdir?")
                cout << "\t\t复制子目录dirname, 格式为 cpDir [dirname]" << endl;
            else if (ch == "cp?")
                cout << "\t\t复制文件filename,格式为 cp [filename]" << endl;
            else if (ch == "pastedir?")
                cout << "\t\t粘贴已复制的目录" << endl;
			else if (ch == "cutdir?")
				cout << "\t\t剪切目录dirname，格式为 cutdir [dirname]" << endl;
            else if (ch == "paste?")
                cout << "\t\t粘贴已复制的文件" << endl;
            else if (ch == "clear?")
                cout << "\t\t清屏" << endl;
            else if (ch == "vi?")
                cout << "\t\t编辑文档filename，输入格式为 vi[filename]" << endl;
            else if (ch == "cd..?")
                cout << "\t\t返回当前目录的上一级目录" << endl;
            else if (ch == "exit?")
                cout << "\t\t注销文件系统" << endl;
			else if (ch == "1")
				break;
            else
                cout << "\t\t命令无效！" << endl;
		}

}


/*用户注册写入文件函数*/
int regist(char username[30], char password[30]) 
{
	
    FILE *cfptr;//文件指针
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
/*用户名字密码检验，是否已经注册（与文件内数据比较）*/
int login(char username[30], char password[30]) 
{
    char user[30];
    char pass[30];
    FILE *cfptr;//文件指针

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
                cout << "用户: " << name << "正在注销...."<<endl;
				Sleep(500);
                
                return 0;
            } 
			else
				cout<<"命令无效，可查看帮助！"<<endl;
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
        cout << "\t\t**             文  件  系  统              **\t" << endl;
        cout << "\t\t**              1. 注册新用户              **\t" << endl;
        cout << "\t\t**              2. 登录                    **\t" << endl;
        cout << "\t\t**              3. 帮助                    **\t" << endl;
        cout << "\t\t**              4. 退出                    **\t" << endl;
		cout << "\t\t*********************************************\t" << endl;
		cout << "\t\t*********************************************\t" << endl;
        cout << "\t\t请选择: " ;
        cin >> choice;
        switch (choice) 
		{
            /*选择注册*/
            case 1: 
				{
                        cout << "请输入用户名:";
                        cin >> name;
                        cout << "请输入密码: ";
                        cin >> pass;
                        cout << "请确认密码: ";
                        cin >> pass1;
                        while (strcmp(pass, pass1) != 0) 
						{
                            cout << "          --两次密码不一致，请重试--" << endl;
                            cout << "请输入密码: ";
                            cin >> pass;
                            cout << "请确认密码: ";
                            cin >> pass1;
                        }
                        if (regist(name, pass) == 1)
						{
                            cout << "        --注册成功!^_^" << endl;
                             Sleep(200);
                        } 
                        else
						{
                            cout << "         --警告，异常错误！(>_<)" << endl;
                             Sleep(200);
                        }
                    }
                    break;

                    /*选择登录*/
            case 2: {
                        cout << "请输入用户名:";
                        cin >> name;
                        cout << "请输入密码:";
                        cin >> pass;
						if (login(name, pass) == -1)
						{
							cout << "          --磁盘打开失败，请检查磁盘文件 " << endl;
							Sleep(1000);
						}
                        else if (login(name, pass) == 1) 
						{
                            cout << "       --登录成功--" << endl;
							Sleep(1000);
                            fsOperate(name, pass);
                        } 
						else
						{
                            cout << "          --登录失败，请检查用户名和密码.." << endl;
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
                        cout << "        --正在退出文件系统.." << endl;
                        exit(0);
                    }
                    break;
                    /*其他选项*/
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