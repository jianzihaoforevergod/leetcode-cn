

//////////////////////////////////////////////////////////////////////////
int lastRemaining(int n) 
{
	int time = 0;
	int factor = 1;
	int len = n;
	while (len != 1) 
	{
		time++;
		if (time % 2 == 0 || len % 2 == 1) 
		{
			n -= factor;
		}
		factor <<= 1;
		len >>= 1;
	}
	return n;
}

//////////////////////////////////////////////////////////////////////////
//int lastRemaining(int n)
//{
//	if (n == 0) return 0;
//
//	int first = 1;							//��һ����
//	int factor = 1;							//����
//	bool isLeft = true;						//����
//	bool isEven = ((n & 1) == 0);			//�����Ƿ�Ϊż��
//
//	while (n != 1)
//	{
//		if (isLeft || !isEven)				//���������һ��ߴ�������ʱΪ��������һ������Ϊԭ���ĵڶ���
//		{
//			first += factor;
//		}
//		isLeft = !isLeft;					//�ı䷽��
//		n >>= 1;							//���ȼ���
//		factor <<= 1;						//�����
//		isEven = ((n & 1) == 0);			//�ж���ż
//	}
//	return first;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return lastRemaining(n);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "tests.txt";
}
