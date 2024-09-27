#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <string>

using namespace std;

   
int compare(string version1, string version2) {
    //创建stringstream对象用来存储版本号
    //sstmp为临时stringstream变量用来接收分割后的string并将其转换为int
    stringstream ss1, ss2, sstmp;
    //string类型的临时变量用来接收getline分割出来的string类型的修订号
    string stmp;
    //两个int型变量用来存储当前的修订号并进行比较
    int v1, v2;
    //将string类型的两个版本号输入到ss对象中
    ss1 << version1;
    ss2 << version2;
    //eof()用来判断当前的stringstream是否输入到了末尾，若已达到末尾则返回true
    //所以while循环条件为两个版本号任意1个尚未比较到末尾则继续进行比较
    while (!ss1.eof() || !ss2.eof()) {
        //若其中的一个修订号中有省略情况则两个版本号长度不一样会出现其中一个填到达末尾的情况
        //那么省略的部分直接补为0再与另一个修订号进行比较
        if (ss1.eof()) v1 = 0;
        else {
            getline(ss1, stmp, '.'); //用getline()对“.”进行分割并将分割结果输入到stmp中
            sstmp << stmp;//以下两行为stringstream类型数据的数据转换
            sstmp >> v1;//string类型的stmp通过<<输入到sstmp中再由>>直接转换为int类型的数据
            //注意这步转换会自动忽略前导的0而转换为正常的int类型数据，0011会自动转为11
            sstmp.clear();//stringstream复用需要clear}

            if (ss2.eof()) v2 = 0;
            else {
                getline(ss2, stmp, '.');
                sstmp << stmp;
                sstmp >> v2;
                sstmp.clear();
            }

            if (v1 > v2) return 1;//若v1＞v2则返回1
            if (v1 < v2) return -1;  //若v1<v2则返回-1
        }

        return 0;//若两个版本号经过了上述循环仍未分出大小则返回0}
    };
