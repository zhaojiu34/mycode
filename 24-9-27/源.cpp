#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <string>

using namespace std;

   
int compare(string version1, string version2) {
    //����stringstream���������洢�汾��
    //sstmpΪ��ʱstringstream�����������շָ���string������ת��Ϊint
    stringstream ss1, ss2, sstmp;
    //string���͵���ʱ������������getline�ָ������string���͵��޶���
    string stmp;
    //����int�ͱ��������洢��ǰ���޶��Ų����бȽ�
    int v1, v2;
    //��string���͵������汾�����뵽ss������
    ss1 << version1;
    ss2 << version2;
    //eof()�����жϵ�ǰ��stringstream�Ƿ����뵽��ĩβ�����Ѵﵽĩβ�򷵻�true
    //����whileѭ������Ϊ�����汾������1����δ�Ƚϵ�ĩβ��������бȽ�
    while (!ss1.eof() || !ss2.eof()) {
        //�����е�һ���޶�������ʡ������������汾�ų��Ȳ�һ�����������һ�����ĩβ�����
        //��ôʡ�ԵĲ���ֱ�Ӳ�Ϊ0������һ���޶��Ž��бȽ�
        if (ss1.eof()) v1 = 0;
        else {
            getline(ss1, stmp, '.'); //��getline()�ԡ�.�����зָ���ָ������뵽stmp��
            sstmp << stmp;//��������Ϊstringstream�������ݵ�����ת��
            sstmp >> v1;//string���͵�stmpͨ��<<���뵽sstmp������>>ֱ��ת��Ϊint���͵�����
            //ע���ⲽת�����Զ�����ǰ����0��ת��Ϊ������int�������ݣ�0011���Զ�תΪ11
            sstmp.clear();//stringstream������Ҫclear}

            if (ss2.eof()) v2 = 0;
            else {
                getline(ss2, stmp, '.');
                sstmp << stmp;
                sstmp >> v2;
                sstmp.clear();
            }

            if (v1 > v2) return 1;//��v1��v2�򷵻�1
            if (v1 < v2) return -1;  //��v1<v2�򷵻�-1
        }

        return 0;//�������汾�ž���������ѭ����δ�ֳ���С�򷵻�0}
    };
