#include <bits/stdc++.h>
#include <windows.h>
#include <ctype.h>
#include <fstream>
using namespace std;
string name[12] = {"\0", "ͼ�����ʷ", "ͼ����̸", "ͼ��;�", "ͼ����һ��", "ͼ��С�ٵ�", "ͼ�����", "ͼ����ս", "ˢˢ��֪ʶ", "ͼ����ʷ", "һ�ԣ��ҥȥ��ȣ�", "ͼ�麽��"};//һ�ԣ��ҥȥ��ȣ� 
string fileName[12] = {"\0", "ͼ�����ʷ.txt", "ͼ����̸.txt", "ͼ��;�.txt", "ͼ����һ��.txt", "ͼ��С�ٵ�.txt", "ͼ�����.txt", "ͼ����ս.txt", "ˢˢ��֪ʶ.txt", "ͼ����ʷ.txt", "һ�ԣ��ҥȥ��ȣ�.txt", "ͼ�麽��.txt"};
string head[12] = {"\0", "|**<p class=\"ui tiny red label\">ͼ�����ʷ</p>**|", "|**<p class=\"ui tiny orange label\">ͼ����̸</p>**|", "|**<p class=\"ui tiny yellow label\">ͼ��;�</p>**|", "|**<p class=\"ui tiny green label\">ͼ����һ��</p>**|", "|**<p class=\"ui tiny teal label\">ͼ��С�ٵ�</p>**|", "|**<p class=\"ui tiny olive label\">ͼ�����</p>**|", "|**<p class=\"ui tiny blue label\">ͼ����ս</p>**|", "|**<p class=\"ui tiny purple label\">ˢˢ��֪ʶ</p>**|", "|**<p class=\"ui tiny pink label\">ͼ����ʷ</p>**|", "|**<p class=\"ui tiny red label\">һ�ԣ��ҥȥ��ȣ�</p>**|", "|**<p class=\"ui tiny black label\">ͼ�麽��</p>**|"};
string back = "\0";
string ntos(int t)
{
	int n = t;
	string ans = "\0";
	while(n)
	{
		int a = n % 10;
		ans += (char) ('0' + a);
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//�ǿ���ʽ����,���ǿո�,�滻Ϊ"&nbsp;"(������˫����)
int main()
{
	cout << setlocale(LC_ALL, "chs_china.65001") << endl;
    //<��ͷ>
    ifstream ifs;
    ofstream ofs;
    double qishu;//����
    //��ȡ����
    ifs.open("��������.txt", ios::in);
    ifs >> qishu;
    ifs.close();
    ofs.open("�����ĵ�.txt", ios::out);
    ofs << "### ͼ��챨 ��" << fixed << setprecision(1) << qishu << "�� ";
    //ʱ��
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    char time[100] = {0};
    sprintf(time, "%4d��%02d��%02d�շ�", sys.wYear, sys.wMonth, sys.wDay);
    ofs << time << endl << endl;
    //ͼ��챨 ��Ȩ����
    ofs << "### [ͼ��챨](https://tm.turingicode.com/judge/article/1288) ��Ȩ����" << endl;
    //</��ͷ>
    //<����>
    for(int i = 1;i <= 11;i++)
    {
    	int sw = 0, ss = 0, s_ = 0, sl = 0; //����������������������� 
		string s;//������
        //��string��תΪchar[]�ͣ�����ifs.open�����޷���ȡ
        char fname[10] = {0};
        for(int j = 0;j <= fileName[i].length();j++)
        {
            fname[j] = fileName[i][j];
        }
        ifs.open(fname, ios::in);
        if(!ifs.good())
        {
        	cout << "�ļ��޷�����" << endl;
			system("pause"); 
			return 1;
		}
        //����
        ofs << "- - -" << endl;
        ofs << head[i] << endl;
        ofs << "|----------|" << endl;
        while(getline(ifs, s))
        {
        	ifs.clear();
        	ofs << "|";
            int len = s.length();
            for(int j = 0;j < len;j++)
            {
            	if(s[j] == ' ')
            	{
            		ofs << "&nbsp;";
				}
				else if(s[j] == '\t')
				{
					ofs << "&nbsp;&nbsp;&nbsp;&nbsp;";
				}
				else
				{
					ofs << s[j];
				}
				if(s[j] == '.' && s[j] == '��' && s[j] == '?' && s[j] == '!' && s[j - 1] == '��' && s[j] == '��' && s[j] == ';' && s[j] == '��')
				{
					s_++;
					if(s[j - 1] != '.' && s[j - 1] != '��' && s[j - 1] != '?' && s[j - 1] != '!' && s[j - 1] != '��' && s[j - 1] != '��' && s[j - 1] != ';' && s[j - 1] != '��')
					{
						ss++;
					}
				}
				else if(s[j] != ' ')
				{
					sw++;
				}
					
			}
			ofs << "|" << endl;
			sl++;
			if(sl != 0 || s[len - 2] != '.' && s[len - 2] != '��' && s[len - 2] != '?' && s[len - 2] != '!' && s[len - 2] != '��' && s[len - 2] != '��' && s[len - 2] != ';' && s[len - 2] != '��')
			{
				ss++;
			}
        }
        ifs.close();
		back += name[i] + ":\n";
		back += "����:" + ntos(sw) + "\n";
		back += "����:" + ntos(ss) + "\n";
		back += "�����:" + ntos(s_) + "\n";
		back += "����:" + ntos(sl) + "\n";
		back += "\n";
    }
    ofs << "- - -\n"; 
    //��β
    ifs.open("��β.txt", ios::in);
    ofs << "|**���ڿ챨�������**|\n";
    ofs << "|:-|\n"; 
    string s;
    while(getline(ifs, s))
    {
    	ofs << "|" << s << "|" << endl;
	}
	ofs.close();
	qishu += 0.1;
	ofs.open("��������.txt", ios::out);
	ofs << qishu;
	ofs.close();
	ofs.open("������Ϣ.txt", ios::out);
	ofs << back;
	ofs.close();
	system("pause"); 
    return 0;
}

