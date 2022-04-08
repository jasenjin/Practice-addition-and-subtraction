using namespace std;

#include<iostream>
#include<cstdlib>
#include <ctime>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
int main()
{	int index ;//��Ŀ����
	double seconds;//��¼��������
	int chengchu;//�Ƿ��г˳�����ָʾ��
	int op_num;//������������м���
	int j_min = 0;//������������ֵ���Сֵ
	int j_max = 0;//������������ֵ����ֵ
	int answer;//��¼�û�����Ĵ�
	int num1=0;//���ɵĵ�һ������
	int num2=0;//���ɵĵڶ�������
	int right_num=0;//��ȷ��Ŀ����
	int wrong_num = 0;//������Ŀ����
	int store=0;//�÷�
	clock_t startTime, endTime;//��ʱ�Ŀ�ʼ�ͽ�������
	cout << "��ӭʹ�ñ�������������" << endl;
	cout << "�����������ʮ����Ŀ��ÿ��ʮ�֣��ܷ�һ�ٷ�" << endl;
	cout << "��ϣ�������������������Ŀ��" << endl;
	cin >> index;
	cout << "��ϣ�����뱾�������������ʲô��Χ�ڣ�����������С��Χ�����������Χ" << endl;
	cin >> j_min;
	cin >> j_max;
	while (j_min >= j_max||j_min<0)
	{
		cout << "������ķ�Χ��������������!ע����Сֵ����С��0������������С��Χ�����������Χ" << endl;
		cin >> j_min;
		cin >> j_max;
	}
	cout << "��ϣ���漰�˳��������ϣ��������1�������ϣ��������2" << endl;
	cin >> chengchu;
	while (chengchu != 1 && chengchu != 2)
	{
		cout << "�����������������������Ƿ��漰�˳��������ϣ��������1�������ϣ��������2" << endl;
		cin >> chengchu;
	}
	srand((unsigned int)time(NULL));//������������
	vector<string>wrong_col(index);
	vector<int>wrong_answer(index);
	vector<double>cal_time(index);
	for (int i = 0; i < index; i++)
	{
		int num1 = (rand() % (j_max - j_min + 1)) + j_min;//���ɵ�һ�������
		int num2 = (rand() % (j_max - j_min + 1)) + j_min;//���ɵڶ��������
		if (chengchu == 1)
		{
			op_num = 4;
		}
		if (chengchu == 2)
		{
			op_num = 2;
		}
		int op = rand() % op_num;//���ɼӼ�����
		switch (op) 
		{
		case 0 ://�ӷ���Ŀ
		
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
		case 1://������Ŀ
			
				if (num1 < num2)
				{
					int tmp;
					tmp = num1;
					num1 = num2;
					num2 = tmp;
				}//��֤����С�ڱ�����
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
		case 2://�˷���Ŀ
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
		case 3://������Ŀ
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
	cout << "������������ȷ����Ŀ���У�" << right_num << "��" << endl;
	cout << "����������������Ŀ���У�" << wrong_num << "��" << endl;
	cout << "�����ε÷�Ϊ��" << store <<" �� " << endl;
	cout << "�����δ���ƽ����ʱ��" <<average_Time<< endl;
	cout << "�����δ���������ʱΪ��" <<min_cal_Time<< endl;
	cout << "�������������Ŀ������ȷ�����£�" << endl;
	for (int a = 0; a < index; a++)
	{
	
			cout << wrong_col[a] << " " << wrong_answer[a] << endl;

	}

	system("pause");
	return 0;
}
