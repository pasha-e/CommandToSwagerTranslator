#include <QCoreApplication>
#include <iostream>
#include <conio.h>

#include <QtCore>

#include "RestApiHelper.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    
    std::cout << "app started" << std::endl;

    OpenApiHelper::RestApiHelper restApiHelher;

    restApiHelher.GetAuthToken();

    restApiHelher.GetWorkspaceList();

    restApiHelher.GetFile(restApiHelher.CurrentFilesList()[0].toStdString());

    /*
       if(_filesRefList.count() > 0)
    {
        std::cout << "testGetFilesFunction call" << std::endl;
        testGetFilesFunction(_filesRefList[0]);
    }             
    */
    return a.exec();
}