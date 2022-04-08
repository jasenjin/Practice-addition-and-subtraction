using namespace std;

#include<iostream>
#include<cstdlib>
#include <ctime>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
int main()
{	int index ;//题目数量
	double seconds;//记录答题秒数
	int chengchu;//是否含有乘除法的指示符
	int op_num;//决定运算符号有几种
	int j_min = 0;//参与运算的数字的最小值
	int j_max = 0;//参与运算的数字的最大值
	int answer;//记录用户输入的答案
	int num1=0;//生成的第一个数字
	int num2=0;//生成的第二个数字
	int right_num=0;//正确题目数量
	int wrong_num = 0;//错误题目数量
	int store=0;//得分
	clock_t startTime, endTime;//计时的开始和结束变量
	cout << "欢迎使用本程序：四则运算" << endl;
	cout << "你会连续作答十个题目，每题十分，总分一百分" << endl;
	cout << "您希望本次连续作答多少题目？" << endl;
	cin >> index;
	cout << "您希望参与本次运算的数字在什么范围内，请先输入最小范围，再输入最大范围" << endl;
	cin >> j_min;
	cin >> j_max;
	while (j_min >= j_max||j_min<0)
	{
		cout << "您输入的范围有误，请重新输入!注意最小值不能小于0。请先输入最小范围，再输入最大范围" << endl;
		cin >> j_min;
		cin >> j_max;
	}
	cout << "您希望涉及乘除法吗？如果希望请输入1，如果不希望请输入2" << endl;
	cin >> chengchu;
	while (chengchu != 1 && chengchu != 2)
	{
		cout << "您的输入有误，请重新输入是否涉及乘除法，如果希望请输入1，如果不希望请输入2" << endl;
		cin >> chengchu;
	}
	srand((unsigned int)time(NULL));//添加随机数种子
	vector<string>wrong_col(index);
	vector<int>wrong_answer(index);
	vector<double>cal_time(index);
	for (int i = 0; i < index; i++)
	{
		int num1 = (rand() % (j_max - j_min + 1)) + j_min;//生成第一个随机数
		int num2 = (rand() % (j_max - j_min + 1)) + j_min;//生成第二个随机数
		if (chengchu == 1)
		{
			op_num = 4;
		}
		if (chengchu == 2)
		{
			op_num = 2;
		}
		int op = rand() % op_num;//生成加减符号
		switch (op) 
		{
		case 0 ://加法题目
		
				cout << num1 << " + " << num2 << " = ?" << endl;
				startTime = clock();
				cin >> answer;
				endTime = clock();
				seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
				cal_time[i] = seconds;

				if (answer == num1 + num2)
				{
					right_num++;
					store += 10;

				}
				else
				{
					wrong_num++;
					wrong_col[i] = to_string(num1) + "+" + to_string(num2) + "=";
					wrong_answer[i] = num1 + num2;

				}
				break;
		case 1://减法题目
			
				if (num1 < num2)
				{
					int tmp;
					tmp = num1;
					num1 = num2;
					num2 = tmp;
				}//保证减数小于被减数
				cout << num1 << " - " << num2 << " = ?" << endl;
				startTime = clock();
				cin >> answer;
				endTime = clock();
				seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
				cal_time[i] = seconds;
				if (answer == num1 - num2)
				{
					right_num++;
					store += 10;

				}
				else
				{
					wrong_num++;
					wrong_col[i] = to_string(num1) + "-" + to_string(num2) + "=";
					wrong_answer[i] = num1 - num2;

				}
				break;
		case 2://乘法题目
			if (chengchu == 2)
			{
				break;
			}

			cout << num1 << " * " << num2 << " = ?" << endl;
			startTime = clock();
			cin >> answer;
			endTime = clock();
			seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			cal_time[i] = seconds;

			if (answer == num1 * num2)
			{
				right_num++;
				store += 10;
			}
			else
			{
				wrong_num++;
				wrong_col[i] = to_string(num1) + "*" + to_string(num2) + "=";
				wrong_answer[i] = num1 * num2;

			}
			break;
		case 3://除法题目
			if (chengchu == 2)
			{
				break;
			}
			if(num2==0)
			{
				
				num2 = 1 + rand() * j_max / (j_max + 1);
			}
			cout << num1 << " / " << num2 << " = ?" << endl;
			startTime = clock();
			cin >> answer;
			endTime = clock();
			seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
			cal_time[i] = seconds;

			if (answer == num1 / num2)
			{
				right_num++;
				store += 10;
			}
			else
			{
				wrong_num++;
				wrong_col[i] = to_string(num1) + "/" + to_string(num2) + "=";
				wrong_answer[i] = num1 / 
					num2;

			}
			break;

		}
		
	}
	
	double sum_Time = accumulate(begin(cal_time), end(cal_time), 0.0);
	double average_Time = sum_Time / cal_time.size();
	double min_cal_Time = *min_element(cal_time.begin(), cal_time.end());
	cout << "您本次作答正确的题目共有：" << right_num << "道" << endl;
	cout << "您本次作答错误的题目共有：" << wrong_num << "道" << endl;
	cout << "您本次得分为：" << store <<" 分 " << endl;
	cout << "您本次答题平均用时：" <<average_Time<< endl;
	cout << "您本次答题最少用时为：" <<min_cal_Time<< endl;
	cout << "您本次做错的题目及其正确答案如下：" << endl;
	for (int a = 0; a < index; a++)
	{
	
			cout << wrong_col[a] << " " << wrong_answer[a] << endl;

	}

	system("pause");
	return 0;
}
