#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

#define MAXSZIE 50
typedef char ElemType;

ElemType expression[50];              //存放输入表达式
ElemType suffix_expression[100];      //存放后缀表达式
int count = 0;
char sign;
int exp_array_length = 0;
int suf_array_length = 0;


typedef struct
{
	ElemType data[MAXSZIE];
	int top;
}SqStack;


void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

bool PushStack(SqStack*& s, ElemType e)
{
	if (s->top == MAXSZIE - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

ElemType PopStack(SqStack*& s)
{
	ElemType e;
	e = s->data[s->top];
	s->top--;
	return e;
}



//栈内置函数
///////////////////////////////////////////////////////////////////////////////////////
//自定义函数


void input_exp(SqStack* s)
{
	int count_this = 0;
	cout << "Please input an exp_string, do not enter space, and enter '.'(point) indicate the end :  ";
	ElemType exp;
	cin >> exp;

	while (exp != '.')
	{
		expression[count_this] = exp;
		count_this++;
		cin >> exp;
		exp_array_length++;
	}
}

void translate_exp(SqStack* s, ElemType exp_trans[])
{
	int flag = 0;
	int i = 0;    //给后缀表达式数组赋值的变量
	int j = 0;    //循环判断每一个数值
	//cout << sizeof(exp_trans) / sizeof(char) + 1 << endl;
	while (j < exp_array_length)       //循环操作每一个字符
	{
		//////////////////////////////
		cout << "第 " << j << " 次执行while循环" << endl;
		////////////////////////////////

		if (exp_trans[j] >= 48 && exp_trans[j] <= 57)   //判断ascii码值的范围，确定是数字
		{
			///////////////////////////
			cout << "j为数字   且j = " << j << " 次执行" << "suf_expression [" << i << "]" << " 个以储存数据 " << exp_trans[j];
			cout << " suf_expression[" << i + 1 << "]" << "已经储存数据" << "\"#\"" << endl;
			/////////////////////////////

			suffix_expression[i] = exp_trans[j];
			suffix_expression[i + 1] = '#';
			flag = 1;
			suf_array_length = suf_array_length + 2;     //后缀表达式的长度
		}
		if (exp_trans[j] == '+' || exp_trans[j] == '-' || exp_trans[j] == '*' || exp_trans[j] == '/')//判断运算符
		{
			if (exp_trans[j] == '+' || exp_trans[j] == '-')   //判断如果是 + -
			{
				if (s->data[s->top] == '+' || s->data[s->top] == '-')   //栈顶元素为 + -
				{
					///////////////////////////////
					cout << "取出栈顶元素,赋值给变量 sign" << "suffix_expression[" << i << "] 以赋值为 ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " 且exp_trans[" << j << "] 以压入栈中**************" << endl;

					suf_array_length++;
				}
				if (s->data[s->top] == '*' || s->data[s->top] == '/')   //栈顶元素为 * / 操作与栈顶为‘+-’完全一致
				{
					///////////////////////////////
					cout << "取出栈顶元素,赋值给变量 sign" << "suffix_expression[" << i << "] 以赋值为 ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " 且exp_trans[" << j << "] 以压入栈中**************" << endl;

					suf_array_length++;

				}
				if (s->top == -1)           //栈没有元素时执行的操作
				{
					PushStack(s, exp_trans[j]);
					flag = 2;
					///////////////////////////
					cout << "栈顶无元素，将 exp_trans[" << j << "] 压入栈中" << endl;
				}
			}

			//如果这个位置上的字符为 * or /
			if (exp_trans[j] == '*' || exp_trans[j] == '/')  
			{
				if (s->data[s->top] == '*' || s->data[s->top] == '/')     //如果栈顶元素的优先级相同
				{
					///////////////////////////////
					cout << "取出栈顶元素,赋值给变量 sign" << "suffix_expression[" << i << "] 以赋值为 ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " 且exp_trans[" << j << "] 以压入栈中**************" << endl;
					suf_array_length++;
				}

				if (s->data[s->top] == '+' || s->data[s->top] == '-')     //此时栈顶元素为 + or -
				{
					PushStack(s, exp_trans[j]);   //  * or / 压入栈中，替代 +- 成为栈顶
					flag = 2;   //flag == 2；意味着i不做任何变动
					///////////////////////////
					cout << "原栈顶元素优先级低，将 exp_trans[" << j << "] 压入栈中" << endl;
				}

				if (s->top == -1)           //栈没有元素时执行的操作
				{
					PushStack(s, exp_trans[j]);
					flag = 2;
					///////////////////////////
					cout << "栈顶无元素，将 exp_trans[" << j << "] 压入栈中" << endl;
				}

			}


		}
		


		if (flag == 1)
		{
			i = i + 2;
			//flag = 0;
		}
		if (flag == 2)
		{
			//flag = 0;
		}
		if (flag == 0)
		{
			i = i + 1;
		}
		flag = 0;
		j++;
	}
	 
	cout << "s->top = " << s->top << endl;

	while (true)    //元素判断完毕，如果栈上还存在运算符，全部拿出来
	{
		if (s->top != -1) 
		{
			cout << "循环结束，但栈中仍然保留了 运算符号 需要全部取出 ";
			cout << "已经将suffix_expression[" << i << "] 个位置储存数据 ";
			//cout << "s->top = " << s->top << endl;
			char end_this = PopStack(s);
			//////////////////////////
			cout << end_this << endl;
			//////////////////////////
			suffix_expression[i] = end_this;
			suf_array_length++;
			i++;
		}
		else
		{
			break;
		}
	}
}

ElemType compile_suf_exp(SqStack*&s,ElemType suf_exp[])
{
	int result = 0;
	int i = 0;      //读取后缀表达式的字符
	int j = 0;      //循环次数
	while (j < suf_array_length)
	{

		if (suf_exp[i] >= 48 && suf_exp[i] <= 57)     //判断为数字
		{
			PushStack(s, suf_exp[i]);
		}
		if (suf_exp[i] == '#' || s->top == -1)
		{
			PushStack(s, '#');
		}
		if (suf_exp[i] == '+' || suf_exp[i] == '-' || suf_exp[i] == '*' || suf_exp[i] == '/') //遇到运算符
		{
			char num[10];
			char num_array_one[10];
			char num_array_two[10];
			int num_one = 0;
			int num_two = 0;
			int k = 0;
			int num_langth = 0;
			//栈里全部储存的是数字，并且坑的以‘#’为分割，以‘#’为栈顶
			if (suf_exp[i] == '+')
			{
				for (int x = 0; x < 2; x++)
				{
					k = 0;     //初始化
					num_langth = 0;
					PopStack(s);   //剔除栈顶元素
					while (s->top != -1)  //拿出字符，以‘#’结束
					{
						if (s->data[s->top] != '#')
						{
							num[k] = PopStack(s);
							num_langth++;
							k++;
						}
						else
							break;

					}
					for (int n = 0; n < num_langth; n++)
					{
						PushStack(s, num[n]);
					}
					if (x == 0)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_one[m] = PopStack(s);
						}
					}
					if (x == 1)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_two[m] = PopStack(s);
						}
					}

				}

				num_one = atoi(num_array_one);      //将字符数组转换为整型
				num_two = atoi(num_array_two);
				char save_num[10];
				_itoa_s(num_one + num_two, save_num, 10);

				int y = 0;
				while (save_num[y] != '\0')
				{
					PushStack(s, save_num[y]);
					y++;
				}
				PushStack(s, '#');

			}
			////////////////////////////////////////////////
			if (suf_exp[i] == '-')
			{
				for (int x = 0; x < 2; x++)
				{
					k = 0;     //初始化
					num_langth = 0;
					PopStack(s);   //剔除栈顶元素
					while (s->top != -1)  //拿出字符，以‘#’结束
					{
						if (s->data[s->top] != '#')
						{
							num[k] = PopStack(s);
							num_langth++;
							k++;
						}
						else
							break;

					}
					for (int n = 0; n < num_langth; n++)
					{
						PushStack(s, num[n]);
					}
					if (x == 0)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_one[m] = PopStack(s);
						}
					}
					if (x == 1)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_two[m] = PopStack(s);
						}
					}

				}

				num_one = atoi(num_array_one);      //将字符数组转换为整型
				num_two = atoi(num_array_two);
				char save_num[10];
				_itoa_s(num_two - num_one, save_num, 10);

				int y = 0;
				while (save_num[y] != '\0')
				{
					PushStack(s, save_num[y]);
					y++;
				}
				PushStack(s, '#');

			}

			if (suf_exp[i] == '*')
			{
				////////////////////////////////////////////////////////
				for (int x = 0; x < 2; x++)
				{
					k = 0;     //初始化
					num_langth = 0;
					PopStack(s);   //剔除栈顶元素
					while (s->top != -1)  //拿出字符，以‘#’结束
					{
						if (s->data[s->top] != '#')
						{
							num[k] = PopStack(s);
							num_langth++;
							k++;
						}
						else
							break;

					}
					for (int n = 0; n < num_langth; n++)
					{
						PushStack(s, num[n]);
					}
					if (x == 0)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_one[m] = PopStack(s);
						}
					}
					if (x == 1)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_two[m] = PopStack(s);
						}
					}

				}

				num_one = atoi(num_array_one);      //将字符数组转换为整型
				num_two = atoi(num_array_two);
				char save_num[10];
				_itoa_s((num_two * num_one), save_num, 10);

				int y = 0;
				while (save_num[y] != '\0')
				{
					PushStack(s, save_num[y]);
					y++;
				}
				PushStack(s, '#');
				////////////////////////////////////////////////////////

			}
			if (suf_exp[i] == '/')
			{
				/////////////////////////////////////////////////////////////
				for (int x = 0; x < 2; x++)
				{
					k = 0;     //初始化
					num_langth = 0;
					PopStack(s);   //剔除栈顶元素
					while (s->top != -1)  //拿出字符，以‘#’结束
					{
						if (s->data[s->top] != '#')
						{
							num[k] = PopStack(s);
							num_langth++;
							k++;
						}
						else
							break;

					}
					for (int n = 0; n < num_langth; n++)
					{
						PushStack(s, num[n]);
					}
					if (x == 0)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_one[m] = PopStack(s);
						}
					}
					if (x == 1)
					{
						for (int m = 0; m < num_langth; m++)
						{
							num_array_two[m] = PopStack(s);
						}
					}

				}

				num_one = atoi(num_array_one);      //将字符数组转换为整型
				num_two = atoi(num_array_two);
				char save_num[10];
				_itoa_s((num_two / num_one), save_num, 10);

				int y = 0;
				while (save_num[y] != '\0')
				{
					PushStack(s, save_num[y]);
					y++;
				}
				PushStack(s, '#');
				////////////////////////////////////////////////////////////////
			}

		}

		i++;
		j++;

	}
	//////////////////////////////////////////
	char result_array[10];
	char num[10];
	int k = 0;
	int num_langth = 0;
	PopStack(s);
	while (s->top != -1)  //拿出字符，以 -1 结束   倒序
	{
		num[k] = PopStack(s);
		num_langth++;
		k++;
	}

	for (int n = 0; n < num_langth; n++)    //存入栈中
	{
		PushStack(s, num[n]);
	}

	for (int m = 0; m < num_langth; m++)
	{
		result_array[m] = PopStack(s);
	}

	result = atoi(result_array);
	return result;
}

int main()
{
	SqStack* s;
	InitStack(s);

	input_exp(s);

	cout << "begin = " << expression<<" ";
	cout << exp_array_length << endl;

	translate_exp(s, expression);

	cout << "exp_array_length = " << exp_array_length << endl;
	cout << "suf_array_length = " << suf_array_length << endl;
	//cout << (sizeof(suffix_expression) / sizeof(char)) << endl;

	cout << "translate to suffix_expression";
	for (int i = 0; i < suf_array_length; i++)
	{
		cout << suffix_expression[i];
	}
	cout << "End" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	int result = compile_suf_exp(s, suffix_expression);
	cout << "程序最终运行的结果为 : " << result << endl;

	return 0;
}