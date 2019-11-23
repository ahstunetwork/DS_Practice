#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

#define MAXSZIE 50
typedef char ElemType;

ElemType expression[50];              //���������ʽ
ElemType suffix_expression[100];      //��ź�׺���ʽ
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



//ջ���ú���
///////////////////////////////////////////////////////////////////////////////////////
//�Զ��庯��


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
	int i = 0;    //����׺���ʽ���鸳ֵ�ı���
	int j = 0;    //ѭ���ж�ÿһ����ֵ
	//cout << sizeof(exp_trans) / sizeof(char) + 1 << endl;
	while (j < exp_array_length)       //ѭ������ÿһ���ַ�
	{
		//////////////////////////////
		cout << "�� " << j << " ��ִ��whileѭ��" << endl;
		////////////////////////////////

		if (exp_trans[j] >= 48 && exp_trans[j] <= 57)   //�ж�ascii��ֵ�ķ�Χ��ȷ��������
		{
			///////////////////////////
			cout << "jΪ����   ��j = " << j << " ��ִ��" << "suf_expression [" << i << "]" << " ���Դ������� " << exp_trans[j];
			cout << " suf_expression[" << i + 1 << "]" << "�Ѿ���������" << "\"#\"" << endl;
			/////////////////////////////

			suffix_expression[i] = exp_trans[j];
			suffix_expression[i + 1] = '#';
			flag = 1;
			suf_array_length = suf_array_length + 2;     //��׺���ʽ�ĳ���
		}
		if (exp_trans[j] == '+' || exp_trans[j] == '-' || exp_trans[j] == '*' || exp_trans[j] == '/')//�ж������
		{
			if (exp_trans[j] == '+' || exp_trans[j] == '-')   //�ж������ + -
			{
				if (s->data[s->top] == '+' || s->data[s->top] == '-')   //ջ��Ԫ��Ϊ + -
				{
					///////////////////////////////
					cout << "ȡ��ջ��Ԫ��,��ֵ������ sign" << "suffix_expression[" << i << "] �Ը�ֵΪ ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " ��exp_trans[" << j << "] ��ѹ��ջ��**************" << endl;

					suf_array_length++;
				}
				if (s->data[s->top] == '*' || s->data[s->top] == '/')   //ջ��Ԫ��Ϊ * / ������ջ��Ϊ��+-����ȫһ��
				{
					///////////////////////////////
					cout << "ȡ��ջ��Ԫ��,��ֵ������ sign" << "suffix_expression[" << i << "] �Ը�ֵΪ ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " ��exp_trans[" << j << "] ��ѹ��ջ��**************" << endl;

					suf_array_length++;

				}
				if (s->top == -1)           //ջû��Ԫ��ʱִ�еĲ���
				{
					PushStack(s, exp_trans[j]);
					flag = 2;
					///////////////////////////
					cout << "ջ����Ԫ�أ��� exp_trans[" << j << "] ѹ��ջ��" << endl;
				}
			}

			//������λ���ϵ��ַ�Ϊ * or /
			if (exp_trans[j] == '*' || exp_trans[j] == '/')  
			{
				if (s->data[s->top] == '*' || s->data[s->top] == '/')     //���ջ��Ԫ�ص����ȼ���ͬ
				{
					///////////////////////////////
					cout << "ȡ��ջ��Ԫ��,��ֵ������ sign" << "suffix_expression[" << i << "] �Ը�ֵΪ ";
					sign = PopStack(s);
					////////////////////////////////
					cout << "sign = " << sign;
					////////////////////////////////
					suffix_expression[i] = sign;
					PushStack(s, exp_trans[j]);
					////////////////////////////////
					cout << " ��exp_trans[" << j << "] ��ѹ��ջ��**************" << endl;
					suf_array_length++;
				}

				if (s->data[s->top] == '+' || s->data[s->top] == '-')     //��ʱջ��Ԫ��Ϊ + or -
				{
					PushStack(s, exp_trans[j]);   //  * or / ѹ��ջ�У���� +- ��Ϊջ��
					flag = 2;   //flag == 2����ζ��i�����κα䶯
					///////////////////////////
					cout << "ԭջ��Ԫ�����ȼ��ͣ��� exp_trans[" << j << "] ѹ��ջ��" << endl;
				}

				if (s->top == -1)           //ջû��Ԫ��ʱִ�еĲ���
				{
					PushStack(s, exp_trans[j]);
					flag = 2;
					///////////////////////////
					cout << "ջ����Ԫ�أ��� exp_trans[" << j << "] ѹ��ջ��" << endl;
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

	while (true)    //Ԫ���ж���ϣ����ջ�ϻ������������ȫ���ó���
	{
		if (s->top != -1) 
		{
			cout << "ѭ����������ջ����Ȼ������ ������� ��Ҫȫ��ȡ�� ";
			cout << "�Ѿ���suffix_expression[" << i << "] ��λ�ô������� ";
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
	int i = 0;      //��ȡ��׺���ʽ���ַ�
	int j = 0;      //ѭ������
	while (j < suf_array_length)
	{

		if (suf_exp[i] >= 48 && suf_exp[i] <= 57)     //�ж�Ϊ����
		{
			PushStack(s, suf_exp[i]);
		}
		if (suf_exp[i] == '#' || s->top == -1)
		{
			PushStack(s, '#');
		}
		if (suf_exp[i] == '+' || suf_exp[i] == '-' || suf_exp[i] == '*' || suf_exp[i] == '/') //���������
		{
			char num[10];
			char num_array_one[10];
			char num_array_two[10];
			int num_one = 0;
			int num_two = 0;
			int k = 0;
			int num_langth = 0;
			//ջ��ȫ������������֣����ҿӵ��ԡ�#��Ϊ�ָ�ԡ�#��Ϊջ��
			if (suf_exp[i] == '+')
			{
				for (int x = 0; x < 2; x++)
				{
					k = 0;     //��ʼ��
					num_langth = 0;
					PopStack(s);   //�޳�ջ��Ԫ��
					while (s->top != -1)  //�ó��ַ����ԡ�#������
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

				num_one = atoi(num_array_one);      //���ַ�����ת��Ϊ����
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
					k = 0;     //��ʼ��
					num_langth = 0;
					PopStack(s);   //�޳�ջ��Ԫ��
					while (s->top != -1)  //�ó��ַ����ԡ�#������
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

				num_one = atoi(num_array_one);      //���ַ�����ת��Ϊ����
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
					k = 0;     //��ʼ��
					num_langth = 0;
					PopStack(s);   //�޳�ջ��Ԫ��
					while (s->top != -1)  //�ó��ַ����ԡ�#������
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

				num_one = atoi(num_array_one);      //���ַ�����ת��Ϊ����
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
					k = 0;     //��ʼ��
					num_langth = 0;
					PopStack(s);   //�޳�ջ��Ԫ��
					while (s->top != -1)  //�ó��ַ����ԡ�#������
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

				num_one = atoi(num_array_one);      //���ַ�����ת��Ϊ����
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
	while (s->top != -1)  //�ó��ַ����� -1 ����   ����
	{
		num[k] = PopStack(s);
		num_langth++;
		k++;
	}

	for (int n = 0; n < num_langth; n++)    //����ջ��
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
	cout << "�����������еĽ��Ϊ : " << result << endl;

	return 0;
}