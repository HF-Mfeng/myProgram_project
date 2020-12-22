﻿#include <iostream>

#include <string>  
#include <io.h>  
#include <vector>  
#include <iostream>  

using namespace std;

/************************************************************************/
/*  获取文件夹下所有文件名
输入：
path    :   文件夹路径
exd     :   所要获取的文件名后缀，如jpg、png等；如果希望获取所有
文件名, exd = ""或"*"
输出：
files   :   获取的文件名列表

shao, 20140707
*/
/************************************************************************/
void getFiles(string path, string exd, vector<string>& files)
{
    long   hFile = 0;

    struct _finddata_t fileinfo;
    string pathName, exdName;

    if (0 != strcmp(exd.c_str(), ""))
    {
        exdName = "\\*." + exd;
    }
    else
    {
        exdName = "\\*";
    }

    if ((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(), &fileinfo)) != -1)
    {
        do
        {
            //cout << fileinfo.name << endl;   

            //如果是文件夹中仍有文件夹,迭代之  
            //如果不是,加入列表  
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(pathName.assign(path).append("\\").append(fileinfo.name), exd, files);
            }
            else
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    files.push_back(pathName.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

int main()
{
    cout << "start list" << endl;
    vector<string> files;
    string filePath = "D:\\yosuga";

    //获取该路径下的所有jpg文件  
    //getFiles(filePath, "jpg", files);  

    //获取该路径下的所有文件  
    getFiles(filePath, "*mp4", files);

    //列表文件输出路径  
    FILE* fp;
    fopen_s(&fp, "d:\\dir_list.txt", "w");
    string outputCMD;
    int size = files.size();
    for (int i = 0; i < size; i++)
    {

        outputCMD.append(
              string("rename ")
            + files[i].c_str()
            + string(" ")
            + std::to_string(i+1)
            + string(".mp4")
        );
        if(i != size-1)
            outputCMD.append(string(" && "));
    }
    cout << outputCMD << endl;
    fputs(outputCMD.c_str(),fp);
    fclose(fp);

    cout << "end list" << endl;
    getchar();
    return 0;
}
