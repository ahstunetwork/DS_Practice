#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream> 

#define PRICE 0.00138      //五块钱一小时

using namespace std;
using std::string;

//全局变量 
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


//学生类 
class student_data
{
public:
	student_data() = default;
private:
	string name;           //学生的姓名 
	int id;                //学生的学号 
	int kouling;           //用户口令 

	int Time = 0;              //学生使用计算机时间 
	int time_begin;        //开始时间
	int time_end;          //结束时间
	float money;             //学生总共需要支付多少钱 

public:
	void user_add(int);            //添加学生信息 
	int user_del();             //删除学生信息 
	void user_kouling();        //改变登录密码 

	void student_display(int ,int );       //显示学生信息的函数 
	int student_modify();
	void student_count();
	void output_stu_file(int);
	int xuhao_look(int );

};

//student_data student[50];



//计算机类 
class computer_status
{
public:
	computer_status() = default;
private:
	int use_zt = 0;                //使用状态 
	int computer_zt = 1;           //计算机状态 
	int number;                    //计算机编号 


public:
	void computer_control();         //计算机管理函数 
	void computer_use();             //计算机是否被使用的状态 
	void computer_broken();          //计算机毁坏时，处理函数 
	void computer_display();          //计算机状态显示的函数 
	void computer_count();
	void output_cpt_file();
	int cpt_zt();



};

//computer_status computer[50];





//菜单函数 
void menu()
{

	cout << endl;
	cout << "\t\t\t" << "*-------------------学生信息添加（1）-------------------*" << endl;
	cout << "\t\t\t" << "|-------------------学生信息删除（2）-------------------|" << endl;
	cout << "\t\t\t" << "|-------------------修改学生口令（3）-------------------|" << endl;
	cout << "\t\t\t" << "|----------------------设备管理（4）--------------------|" << endl;
	cout << "\t\t\t" << "|----------------------添加记录（5）--------------------|" << endl;
	cout << "\t\t\t" << "|--------------------计算机报废（6）--------------------|" << endl;
	cout << "\t\t\t" << "|---------------------制表显示（7）---------------------|" << endl;
	cout << "\t\t\t" << "|-------------------学生信息修改（8）-------------------|" << endl;
	cout << "\t\t\t" << "|------------------- 计算机统计（9）--------------------|" << endl;
	cout << "\t\t\t" << "*-----------------------退出（0）-----------------------*" << endl;
	cout << endl;
	cout << "\t\t\t\t" << "        选择你要进行的操作(0 - 7)" << endl;


}

/////////////////////////////////////////////////////////////////////////////////////
//添加用户
void student_data::user_add(int x)
{

	//////////////////////////////////////////////////
	//写文件 
	///////////////////////////////////////////////////
	string name_add;        //临时 作为添加的中介变量 
	int id_add;

	//int kouling_add;

	cout << endl;
	cout << x << endl;

	this->time_begin = x;
//	cout << this->time_begin << "sdfsdfsddsfdfdddsfdfdfdfd" << endl;


	cout << "添加用户数据 :" << endl;
	cin >> name_add;
	cin >> id_add;


	
	
	//cin>>kouling_add;

	name = name_add;
	id = id_add;

	stu_add_flag = 1;
	//	Count_array++;


}



///////////////////////////////////////////////////////////////////////////////////////////
//删除用户
	int fg = 0;
//1.第几个序号 2.一共有多少 3.要删除的ID 
int ijk = 0;
int student_data::user_del()
{	

	//如果第 position_array 个找到了对应的学号，则返回该位置标记
	//position_array 为位置标记，初始化为0，
	//cout << id << endl;
	//cout << ijk << endl;

	//如果找到了
	if (id == id_time)
	{
		cout << "找到目标 ！" << endl;
		//return ijk;
		fg = 1;

	}
	//    	for(int a = x; a < Count_array; a++)
	if (fg)
	{
		//返回值为 位置，被 m 接到
		return ijk;
	}
	ijk++;
	//return 0;

}



//////////////////////////////////////////////////////////////////////////////////////////////
//登录口令

void student_data::user_kouling()
{

}





/////////////////////////////////////////////////////////////////////////////////
//管理员管理计算机，可以强制用户下线 
void computer_status::computer_control()
{
//	cout << "输入你要控制的 用户 id 或者 计算机编号 :" << endl;

	use_zt = 0;

}

int x_h_count = 0;
int student_data::xuhao_look(int x_h)
{
	if (id == x_h)
	{
		cout << "找到此学生 :" << endl;
		fg = 1;
		return x_h_count;
	//	x_h_count = 0;
	}

	x_h_count++;

}




///////////////////////////////////////////////////////////////////////////////////
//设置计算机的使用状态，如果用户添加成功，则为他分配一台计算机 
//和用户添加项相关联
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
//损坏的计算机记录
void computer_status::computer_broken()
{
	computer_zt = 0;

}


//////////////////////////////////////////////////////////////////
//制表显示，传入的参数为时间，也就是在调用该函数的时候
//设置一个截止时间，显示的是 统计页面 的 实时情况（时间，价格）
//动态刷新，待开发
void student_data::student_display(int y, int z_t)
{
//	cout << "所有信息如下  学生姓名：" << endl;

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
//同上，两者是在 同一个分支 中 连续调用，把 学生信息 和 计算机信息 拼装起来
void computer_status::computer_display()
{
//	cout << "所有计算机信息如下 ：" << endl;

	cout << setw(17) << setiosflags(ios::left) << use_zt << setw(17) << setiosflags(ios::left) << computer_zt << endl;
	

}



//////////////////////////////////////////////////////////////////////////
//修改学生信息
int student_data::student_modify()
{
	if (id == id_time)
	{
		cout << "找到目标 ！" << endl;
		//return ijk;
		fg = 1;

	}
	//    	for(int a = x; a < Count_array; a++)
	if (fg)
	{
		cout << "输入你想要修改学生的 姓名 ，id ：" << endl;
		cin >> name;
		cin >> id;
		//返回值被 m 接受
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



//主函数，由于使用的是类的设计方式，导致 参数传递 不是很自由，显得主函数很臃肿
//相同原因，使用了很多全局变量，后面有待代码优化
int main()
{
	//menu();
	//计算对象个数的全局变量
	Count_array = 0;

	//两个类对象数组
	student_data student[50];
	computer_status computer[50];

	//	Count_stu = sizeof(student)/sizeof(student[0]);
	//	cout<<Count_stu<<endl;


	////////////////////////////////////////////////////////////////////
	//文件读写区域，待开发
	int tm = time(0);
	cout << tm << endl;





	///////////////////////////////////////////////////////////////////

	//检验while循环的状态
	int cho;
	cho = 1;
	//检验第二层循环 switch 的状态
	int choo;
	while (cho)
	{
		//时间函数来给每个学生类对象的 相关时间点 赋值
		//本程序采用 开始时间 减去 结束时间 来统计时间，不加转换的使用 秒
		//收费情况为：5元/h 也就是 0.00168元/秒
		tm = time(0);
		menu();

		cin >> choo;

		system("cls");

		switch (choo)
		{
			//输入用户信息 
		case 1:
			//tm = time(0);
			cout << tm << endl;
			//调用 添加信息 的函数，判断返回的值，如果真，表示添加了学生
			//则进一步调用 计算机类 的相关函数,为学生分配一台计算机，进而设置计算机的状态
			student[Count_array].user_add(tm);

			if (stu_add_flag)
			{
				computer[Count_array].computer_use();

			}

			Count_array++;

			break;

			//删除用户信息	
		case 2:

			int m;

			cout << "输入你想删除的用户学号 ：" << endl;
			//临时变量，存放 id
			cin >> id_time;
			//调用循环，找到输入的学号对应的位置
			//参数来回传递特别麻烦，心态都传崩了，先是0-49的循环
			for (int k = 0; k < 50; k++)
			{
				//cout << k << endl;
				//对每一个类对象检索， m 接受返回值，返回值为: 在  第几个 位置 ，找到了对应的的学号
				m = student[k].user_del();
				if (fg)
				{
					//跳出 这一层 循环
					break;
				}

			}

			if (fg)
			{
				
				//cout << m <<" "<< Count_array << endl;
				//找到了该位置，m 携带着位置标记
				//对于第 m 个位置，及其后面的所有对象，直到 Count_array ,都往前移动一个位置

				for (int n = m; n < Count_array-1; n++)
				{
					cout << "hadhasjdsahjdhasd" << endl;
					student[n] = student[n + 1];
					computer[n] = computer[n + 1];
				}
				//删除过后，总Count_array 减去 1
				Count_array--;
				cout << " 删除成功 ！" << endl;
				fg = 0;
				ijk = 0;
			}
			else
			{
				cout << "没有找到此人 ！" << endl;
			}

			break;

			//更改用户口令 
		case 3:
			student[Count_array].user_kouling();

			break;



			//管理员管理 
		case 4:

			cout << "请输入你想管理的 学生 学号 ：" << endl;
			int xuhao;
			cin >> xuhao;
			int j;

			for (int x = 0; x < Count_array; x++)
			{
				j = student[x].xuhao_look(xuhao);
			}

			if (fg)
			{
				cout << "管理成功 ！" << endl;
				fg = 0;
				x_h_count = 0;
			}

			computer[j-1].computer_control();
			break;



			//添加记录到硬盘
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

			//计算机报修	
		case 6:

			cout << "添加损坏的计算机的编号 (0 - 50) :" << endl;
			int broken;
			cin >> broken;

			computer[broken].computer_broken();
			break;

			//制表显示 




		case 7:
			tm = time(0);
			cout << tm;
			//cout<<Count_stu<<endl;
			cout << "用户及计算机的信息如下，计算机状态 表示计算机是否正常，使用状态 表示是否正在使用"<< endl;
			cout << "计算机使用状态 1 (正在使用) 0 (空闲) ；计算机状态 1 (正常) 0 (损坏)" << endl;
			cout << endl;
			cout << "学生姓名         " << "学生学号         " << "使用时间(秒)    " << "费用（元）        ";
			cout << "计算机使用状态   " << "计算机状态" << endl;
			int h;
			for (int i = 0; i < Count_array; i++)
			{
				h = computer[i].cpt_zt();
				student[i].student_display(tm, h);
				computer[i].computer_display();
			}

			break;






			//////////修改
		case 8:
			cout << "输入你想要修改的学生的 id :" << endl;

			cin >> id_time;

			for (int k = 0; k < 50; k++)
			{
				//cout << k << endl;
				//对每一个类对象检索， m 接受返回值，返回值为: 在  第几个 位置 ，找到了对应的的学号
				m = student[k].student_modify();
				if (fg)
				{
					//跳出 这一层 循环
					break;
				}

			}

			if (fg)
			{
				cout << "修改成功 ！" << endl;;
				fg = 0;
				ijk = 0;

			}


			break;

		case 9:

			cout << setw(17) << setiosflags(ios::left) << "序号 " << setw(17) << setiosflags(ios::left) << "是否正在用";
			cout << setw(17) << setiosflags(ios::left) << "是否损坏" << endl;


			for (int i = 0; i < 50; i++)
			{
				//student[i].student_display(tm);
				cout << "第 " << setw(4) << setiosflags(ios::left) << i + 1 << " 台";
				cout << "         ";
				computer[i].computer_display();
			}
			break;

			//退出 
		case 0:
			cho = 0;
			break;

			//	Count_array++; 

		}



	}
	cout << "程序退出 !" << endl;

	return 0;
}

