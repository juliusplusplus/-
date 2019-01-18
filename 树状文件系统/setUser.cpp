#include"FileSystem.h"
int FileSystem::setUser(char *n, char *c)   //设置用户名与密码
{
    MyDir *root = new MyDir;
    strcpy_s(root->name, n);
    strcpy_s(name, n);
    strcpy_s(password, c);

    this->root = root;
    currentDir = root;
    currentDir->preDir = NULL;
    currentDir->dirPtr = NULL;
    currentDir->filePtr = NULL;
    currentDir->nextDir = NULL;
    return 1;
}