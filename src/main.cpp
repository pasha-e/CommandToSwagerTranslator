#include <iostream>
#include <conio.h>

#include "RestApiHelper.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    
    std::cout << "app started" << std::endl;

    OpenApiHelper::RestApiHelper restApiHelper;

    std::string  accessToken = "";
    std::vector<std::string> filesList;
       
    if (restApiHelper.GetAuthToken(accessToken))
    {
        std::cout << "access_token: " << accessToken << std::endl;
    }
    else
    {
        std::cout << "Error 1: Ответ за запрос авторизации не получен" << std::endl;

        return -1;
    }

    
    if (restApiHelper.GetWorkspaceList(accessToken, filesList))
    {
        if (filesList.size() == 0)
        {
            std::cout << "Warning: Нет доступных для скачивания файлов" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Files list:" << std::endl;
            foreach(std::string value, filesList)
            {
                std::cout << value << std::endl;
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Error 2: Ответ за запрос списка проектов не получен" << std::endl;

        return -1;
    }

    std::cout << "Request file: " << filesList[0] << std::endl;

    OpenAPI::OAIHttpFileElement fileElementInfo;

    if (restApiHelper.GetFile(filesList[0], fileElementInfo))
    {
        std::cout << "File lenght: " << fileElementInfo.asByteArray().length() << std::endl;
        std::cout << "File name: " << fileElementInfo.request_filename.toStdString() << std::endl;
    }
    else
    {
        std::cout << "Error 3: Ответ за запрос списка проектов не получен" << std::endl;

        return -1;
    }

   
    return a.exec();
}