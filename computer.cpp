#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream> 

#define PRICE 0.00138      //���ǮһСʱ

using namespace std;
using std::string;

//ȫ�ֱ��� 
int Count_array;
int Count_stu;
int Count_cpt;
int position_array;
int flag;
int stu_add_flag;
int cpt_add_flag;

int times;
int id_time;
int tm;


//ѧ���� 
class student_data
{
public:
	student_data() = default;
private:
	string name;           //ѧ�������� 
	int id;                //ѧ����ѧ�� 
	int kouling;           //�û����� 

	int Time = 0;              //ѧ��ʹ�ü����ʱ�� 
	int time_begin;        //��ʼʱ��
	int time_end;          //����ʱ��
	float money;             //ѧ���ܹ���Ҫ֧������Ǯ 

public:
	void user_add(int);            //���ѧ����Ϣ 
	int user_del();             //ɾ��ѧ����Ϣ 
	void user_kouling();        //�ı��¼���� 

	void student_display(int ,int );       //��ʾѧ����Ϣ�ĺ��� 
	int student_modify();
	void student_count();
	void output_stu_file(int);
	int xuhao_look(int );

};

//student_data student[50];



//������� 
class computer_status
{
public:
	computer_status() = default;
private:
	int use_zt = 0;                //ʹ��״̬ 
	int computer_zt = 1;           //�����״̬ 
	int number;                    //�������� 


public:
	void computer_control();         //����������� 
	void computer_use();             //������Ƿ�ʹ�õ�״̬ 
	void computer_broken();          //������ٻ�ʱ�������� 
	void computer_display();          //�����״̬��ʾ�ĺ��� 
	void computer_count();
	void output_cpt_file();
	int cpt_zt();



};

//computer_status computer[50];





//�˵����� 
void menu()
{

	cout << endl;
	cout << "\t\t\t" << "*-------------------ѧ����Ϣ��ӣ�1��-------------------*" << endl;
	cout << "\t\t\t" << "|-------------------ѧ����Ϣɾ����2��-------------------|" << endl;
	cout << "\t\t\t" << "|-------------------�޸�ѧ�����3��-------------------|" << endl;
	cout << "\t\t\t" << "|----------------------�豸����4��--------------------|" << endl;
	cout << "\t\t\t" << "|----------------------��Ӽ�¼��5��--------------------|" << endl;
	cout << "\t\t\t" << "|--------------------��������ϣ�6��--------------------|" << endl;
	cout << "\t\t\t" << "|---------------------�Ʊ���ʾ��7��---------------------|" << endl;
	cout << "\t\t\t" << "|-------------------ѧ����Ϣ�޸ģ�8��-------------------|" << endl;
	cout << "\t\t\t" << "|------------------- �����ͳ�ƣ�9��--------------------|" << endl;
	cout << "\t\t\t" << "*-----------------------�˳���0��-----------------------*" << endl;
	cout << endl;
	cout << "\t\t\t\t" << "        ѡ����Ҫ���еĲ���(0 - 7)" << endl;


}

/////////////////////////////////////////////////////////////////////////////////////
//����û�
void student_data::user_add(int x)
{

	//////////////////////////////////////////////////
	//д�ļ� 
	///////////////////////////////////////////////////
	string name_add;        //��ʱ ��Ϊ��ӵ��н���� 
	int id_add;

	//int kouling_add;

	cout << endl;
	cout << x << endl;

	this->time_begin = x;
//	cout << this->time_begin << "sdfsdfsddsfdfdddsfdfdfdfd" << endl;


	cout << "����û����� :" << endl;
	cin >> name_add;
	cin >> id_add;


	
	
	//cin>>kouling_add;

	name = name_add;
	id = id_add;

	stu_add_flag = 1;
	//	Count_array++;


}



///////////////////////////////////////////////////////////////////////////////////////////
//ɾ���û�
	int fg = 0;
//1.�ڼ������ 2.һ���ж��� 3.Ҫɾ����ID 
int ijk = 0;
int student_data::user_del()
{	

	//����� position_array ���ҵ��˶�Ӧ��ѧ�ţ��򷵻ظ�λ�ñ��
	//position_array Ϊλ�ñ�ǣ���ʼ��Ϊ0��
	//cout << id << endl;
	//cout << ijk << endl;

	//����ҵ���
	if (id == id_time)
	{
		cout << "�ҵ�Ŀ�� ��" << endl;
		//return ijk;
		fg = 1;

	}
	//    	for(int a = x; a < Count_array; a++)
	if (fg)
	{
		//����ֵΪ λ�ã��� m �ӵ�
		return ijk;
	}
	ijk++;
	//return 0;

}



//////////////////////////////////////////////////////////////////////////////////////////////
//��¼����

void student_data::user_kouling()
{

}





/////////////////////////////////////////////////////////////////////////////////
//����Ա��������������ǿ���û����� 
void computer_status::computer_control()
{
//	cout << "������Ҫ���Ƶ� �û� id ���� �������� :" << endl;

	use_zt = 0;

}

int x_h_count = 0;
int student_data::xuhao_look(int x_h)
{
	if (id == x_h)
	{
		cout << "�ҵ���ѧ�� :" << endl;
		fg = 1;
		return x_h_count;
	//	x_h_count = 0;
	}

	x_h_count++;

}




///////////////////////////////////////////////////////////////////////////////////
//���ü������ʹ��״̬������û���ӳɹ�����Ϊ������һ̨����� 
//���û�����������
void computer_status::computer_use()
{
	use_zt = 1;

}


int zt;
int computer_status::cpt_zt()
{
	return use_zt;

}




////////////////////////////////////////////////////////////////////////////////////
//�𻵵ļ������¼
void computer_status::computer_broken()
{
	computer_zt = 0;

}


//////////////////////////////////////////////////////////////////
//�Ʊ���ʾ������Ĳ���Ϊʱ�䣬Ҳ�����ڵ��øú�����ʱ��
//����һ����ֹʱ�䣬��ʾ���� ͳ��ҳ�� �� ʵʱ�����ʱ�䣬�۸�
//��̬ˢ�£�������
void student_data::student_display(int y, int z_t)
{
//	cout << "������Ϣ����  ѧ��������" << endl;

	if (z_t == 1)
	{
		time_end = y;
		Time = time_end - time_begin;
		money = Time * PRICE;
	}




//	cout << endl;
//	cout << endl;

//	cout << time_begin<<"  dsffsdfsdfsdfsd";

//	cout << endl;
	cout << endl;
	cout << setw(17) << setiosflags(ios::left) << name << setw(17) << setiosflags(ios::left) << id;
	cout << setw(17) << setiosflags(ios::left) << Time << setw(17) << setiosflags(ios::left) << money;

}
///////////////////////////////////////////////////////////////////////
//ͬ�ϣ��������� ͬһ����֧ �� �������ã��� ѧ����Ϣ �� �������Ϣ ƴװ����
void computer_status::computer_display()
{
//	cout << "���м������Ϣ���� ��" << endl;

	cout << setw(17) << setiosflags(ios::left) << use_zt << setw(17) << setiosflags(ios::left) << computer_zt << endl;
	

}



//////////////////////////////////////////////////////////////////////////
//�޸�ѧ����Ϣ
int student_data::student_modify()
{
	if (id == id_time)
	{
		cout << "�ҵ�Ŀ�� ��" << endl;
		//return ijk;
		fg = 1;

	}
	//    	for(int a = x; a < Count_array; a++)
	if (fg)
	{
		cout << "��������Ҫ�޸�ѧ���� ���� ��id ��" << endl;
		cin >> name;
		cin >> id;
		//����ֵ�� m ����
		return ijk;
	}
	ijk++;
	//return 0;


}


int output_count;
void student_data::output_stu_file(int x)
{


	fstream output_file("generator_room.txt", ios::out | ios::app);

	if (output_count == 0)
	{
		fstream output_file("generator_room.txt", ios::out);
		output_file.close();
	}
	else
	{
		output_file << endl;
	}

	time_end = x;

	Time = time_end - time_begin;
	money = Time * PRICE;
	
	output_file << setw(17) << setiosflags(ios::left) << name;
	output_file << setw(17) << setiosflags(ios::left) << id;
	output_file << setw(17) << setiosflags(ios::left) << Time;
	output_file << setw(17) << setiosflags(ios::left) << money;

	output_file.close();


}

void computer_status::output_cpt_file()
{
	fstream output_file("generator_room.txt", ios::left | ios::app);

	output_file << setw(17) << setiosflags(ios::left) << computer_zt;

	output_file.close();

}



//������������ʹ�õ��������Ʒ�ʽ������ �������� ���Ǻ����ɣ��Ե���������ӷ��
//��ͬԭ��ʹ���˺ܶ�ȫ�ֱ����������д������Ż�
int main()
{
	//menu();
	//������������ȫ�ֱ���
	Count_array = 0;

	//�������������
	student_data student[50];
	computer_status computer[50];

	//	Count_stu = sizeof(student)/sizeof(student[0]);
	//	cout<<Count_stu<<endl;


	////////////////////////////////////////////////////////////////////
	//�ļ���д���򣬴�����
	int tm = time(0);
	cout << tm << endl;





	///////////////////////////////////////////////////////////////////

	//����whileѭ����״̬
	int cho;
	cho = 1;
	//����ڶ���ѭ�� switch ��״̬
	int choo;
	while (cho)
	{
		//ʱ�亯������ÿ��ѧ�������� ���ʱ��� ��ֵ
		//��������� ��ʼʱ�� ��ȥ ����ʱ�� ��ͳ��ʱ�䣬����ת����ʹ�� ��
		//�շ����Ϊ��5Ԫ/h Ҳ���� 0.00168Ԫ/��
		tm = time(0);
		menu();

		cin >> choo;

		system("cls");

		switch (choo)
		{
			//�����û���Ϣ 
		case 1:
			//tm = time(0);
			cout << tm << endl;
			//���� �����Ϣ �ĺ������жϷ��ص�ֵ������棬��ʾ�����ѧ��
			//���һ������ ������� ����غ���,Ϊѧ������һ̨��������������ü������״̬
			student[Count_array].user_add(tm);

			if (stu_add_flag)
			{
				computer[Count_array].computer_use();

			}

			Count_array++;

			break;

			//ɾ���û���Ϣ	
		case 2:

			int m;

			cout << "��������ɾ�����û�ѧ�� ��" << endl;
			//��ʱ��������� id
			cin >> id_time;
			//����ѭ�����ҵ������ѧ�Ŷ�Ӧ��λ��
			//�������ش����ر��鷳����̬�������ˣ�����0-49��ѭ��
			for (int k = 0; k < 50; k++)
			{
				//cout << k << endl;
				//��ÿһ������������ m ���ܷ���ֵ������ֵΪ: ��  �ڼ��� λ�� ���ҵ��˶�Ӧ�ĵ�ѧ��
				m = student[k].user_del();
				if (fg)
				{
					//���� ��һ�� ѭ��
					break;
				}

			}

			if (fg)
			{
				
				//cout << m <<" "<< Count_array << endl;
				//�ҵ��˸�λ�ã�m Я����λ�ñ��
				//���ڵ� m ��λ�ã������������ж���ֱ�� Count_array ,����ǰ�ƶ�һ��λ��

				for (int n = m; n < Count_array-1; n++)
				{
					cout << "hadhasjdsahjdhasd" << endl;
					student[n] = student[n + 1];
					computer[n] = computer[n + 1];
				}
				//ɾ��������Count_array ��ȥ 1
				Count_array--;
				cout << " ɾ���ɹ� ��" << endl;
				fg = 0;
				ijk = 0;
			}
			else
			{
				cout << "û���ҵ����� ��" << endl;
			}

			break;

			//�����û����� 
		case 3:
			student[Count_array].user_kouling();

			break;



			//����Ա���� 
		case 4:

			cout << "�������������� ѧ�� ѧ�� ��" << endl;
			int xuhao;
			cin >> xuhao;
			int j;

			for (int x = 0; x < Count_array; x++)
			{
				j = student[x].xuhao_look(xuhao);
			}

			if (fg)
			{
				cout << "����ɹ� ��" << endl;
				fg = 0;
				x_h_count = 0;
			}

			computer[j-1].computer_control();
			break;



			//��Ӽ�¼��Ӳ��
		case 5:

			//computer[Count_array].computer_use();
			output_count = 0;

			tm = time(0);
			cout << tm;

			for (int i = 0; i < Count_array; i++)
			{
				student[i].output_stu_file(tm);
				computer[i].output_cpt_file();

				output_count++;

			}
			



			break;

			//���������	
		case 6:

			cout << "����𻵵ļ�����ı�� (0 - 50) :" << endl;
			int broken;
			cin >> broken;

			computer[broken].computer_broken();
			break;

			//�Ʊ���ʾ 




		case 7:
			tm = time(0);
			cout << tm;
			//cout<<Count_stu<<endl;
			cout << "�û������������Ϣ���£������״̬ ��ʾ������Ƿ�������ʹ��״̬ ��ʾ�Ƿ�����ʹ��"<< endl;
			cout << "�����ʹ��״̬ 1 (����ʹ��) 0 (����) �������״̬ 1 (����) 0 (��)" << endl;
			cout << endl;
			cout << "ѧ������         " << "ѧ��ѧ��         " << "ʹ��ʱ��(��)    " << "���ã�Ԫ��        ";
			cout << "�����ʹ��״̬   " << "�����״̬" << endl;
			int h;
			for (int i = 0; i < Count_array; i++)
			{
				h = computer[i].cpt_zt();
				student[i].student_display(tm, h);
				computer[i].computer_display();
			}

			break;






			//////////�޸�
		case 8:
			cout << "��������Ҫ�޸ĵ�ѧ���� id :" << endl;

			cin >> id_time;

			for (int k = 0; k < 50; k++)
			{
				//cout << k << endl;
				//��ÿһ������������ m ���ܷ���ֵ������ֵΪ: ��  �ڼ��� λ�� ���ҵ��˶�Ӧ�ĵ�ѧ��
				m = student[k].student_modify();
				if (fg)
				{
					//���� ��һ�� ѭ��
					break;
				}

			}

			if (fg)
			{
				cout << "�޸ĳɹ� ��" << endl;;
				fg = 0;
				ijk = 0;

			}


			break;

		case 9:

			cout << setw(17) << setiosflags(ios::left) << "��� " << setw(17) << setiosflags(ios::left) << "�Ƿ�������";
			cout << setw(17) << setiosflags(ios::left) << "�Ƿ���" << endl;


			for (int i = 0; i < 50; i++)
			{
				//student[i].student_display(tm);
				cout << "�� " << setw(4) << setiosflags(ios::left) << i + 1 << " ̨";
				cout << "         ";
				computer[i].computer_display();
			}
			break;

			//�˳� 
		case 0:
			cho = 0;
			break;

			//	Count_array++; 

		}



	}
	cout << "�����˳� !" << endl;

	return 0;
}

