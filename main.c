#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXBIT 32
#define MAXSHIFT 10

bool lessEqualThan(int a, int b);
bool lessThan(int a, int b);

struct num {
	union {
		struct {
			unsigned int p0 : 1;
			unsigned int p1 : 1;
			unsigned int p2 : 1;
			unsigned int p3 : 1;
			unsigned int p4 : 1;
			unsigned int p5 : 1;
			unsigned int p6 : 1;
			unsigned int p7 : 1;
			unsigned int p8 : 1;
			unsigned int p9 : 1;
			unsigned int p10 : 1;
			unsigned int p11 : 1;
			unsigned int p12 : 1;
			unsigned int p13 : 1;
			unsigned int p14 : 1;
			unsigned int p15 : 1;
			unsigned int p16 : 1;
			unsigned int p17 : 1;
			unsigned int p18 : 1;
			unsigned int p19 : 1;
			unsigned int p20 : 1;
			unsigned int p21 : 1;
			unsigned int p22 : 1;
			unsigned int p23 : 1;
			unsigned int p24 : 1;
			unsigned int p25 : 1;
			unsigned int p26 : 1;
			unsigned int p27 : 1;
			unsigned int p28 : 1;
			unsigned int p29 : 1;
			unsigned int p30 : 1;
			unsigned int p31 : 1;
		};
		int num;
	};
};

int shift_arr[MAXBIT];
int or_arr[MAXBIT];

bool iEqual(int a, int b) {
	if (a == b) return true;
	else return false;
}

int iPlusOne(int a) {
	return ++a;
}

// true true ����
bool iEqual11(int a, int b) {
	if (iEqual(a, 1)) {
		if (iEqual(b, 1)) {
			return true;
		}
	}
	return false;
}

// false false ����
bool iEqual00(int a, int b) {
	if (iEqual(a, 0)) {
		if (iEqual(b, 0)) {
			return true;
		}
	}
	return false;
}

// true false / false true ����
bool iEqual10(int a, int b) {
	if (iEqual00(a, b)) {
		return false;
	}
	return true;
}

//or���� (a|b)
int or (int a, int b) {
	struct num a_num;
	struct num b_num;
	struct num rtn_num;
	int tmp = 0;
	a_num.num = a;
	b_num.num = b;
	rtn_num.num = tmp;

	if (iEqual10(a_num.p0, b_num.p0)) rtn_num.p0 = 1;
	if (iEqual10(a_num.p1, b_num.p1)) rtn_num.p1 = 1;
	if (iEqual10(a_num.p2, b_num.p2)) rtn_num.p2 = 1;
	if (iEqual10(a_num.p3, b_num.p3)) rtn_num.p3 = 1;
	if (iEqual10(a_num.p4, b_num.p4)) rtn_num.p4 = 1;
	if (iEqual10(a_num.p5, b_num.p5)) rtn_num.p5 = 1;
	if (iEqual10(a_num.p6, b_num.p6)) rtn_num.p6 = 1;
	if (iEqual10(a_num.p7, b_num.p7)) rtn_num.p7 = 1;
	if (iEqual10(a_num.p8, b_num.p8)) rtn_num.p8 = 1;
	if (iEqual10(a_num.p9, b_num.p9)) rtn_num.p9 = 1;
	if (iEqual10(a_num.p10, b_num.p10)) rtn_num.p10 = 1;
	if (iEqual10(a_num.p11, b_num.p11)) rtn_num.p11 = 1;
	if (iEqual10(a_num.p12, b_num.p12)) rtn_num.p12 = 1;
	if (iEqual10(a_num.p13, b_num.p13)) rtn_num.p13 = 1;
	if (iEqual10(a_num.p14, b_num.p14)) rtn_num.p14 = 1;
	if (iEqual10(a_num.p15, b_num.p15)) rtn_num.p15 = 1;
	if (iEqual10(a_num.p16, b_num.p16)) rtn_num.p16 = 1;
	if (iEqual10(a_num.p17, b_num.p17)) rtn_num.p17 = 1;
	if (iEqual10(a_num.p18, b_num.p18)) rtn_num.p18 = 1;
	if (iEqual10(a_num.p19, b_num.p19)) rtn_num.p19 = 1;
	if (iEqual10(a_num.p20, b_num.p20)) rtn_num.p20 = 1;
	if (iEqual10(a_num.p21, b_num.p21)) rtn_num.p21 = 1;
	if (iEqual10(a_num.p22, b_num.p22)) rtn_num.p22 = 1;
	if (iEqual10(a_num.p23, b_num.p23)) rtn_num.p23 = 1;
	if (iEqual10(a_num.p24, b_num.p24)) rtn_num.p24 = 1;
	if (iEqual10(a_num.p25, b_num.p25)) rtn_num.p25 = 1;
	if (iEqual10(a_num.p26, b_num.p26)) rtn_num.p26 = 1;
	if (iEqual10(a_num.p27, b_num.p27)) rtn_num.p27 = 1;
	if (iEqual10(a_num.p28, b_num.p28)) rtn_num.p28 = 1;
	if (iEqual10(a_num.p29, b_num.p29)) rtn_num.p29 = 1;
	if (iEqual10(a_num.p30, b_num.p30)) rtn_num.p30 = 1;
	if (iEqual10(a_num.p31, b_num.p31)) rtn_num.p31 = 1;

	int rtn = rtn_num.num;
	return rtn;
}

//and ���� (a&b)
intand (int a, int b) {
	int tmp = 0;
	struct num k;
	struct num a_num;
	struct num b_num;
	struct num rtn_num;
	a_num.num = a;
	b_num.num = b;
	rtn_num.num = tmp;

	if (iEqual11(a_num.p0, b_num.p0)) rtn_num.p0 = 1;
	if (iEqual11(a_num.p1, b_num.p1)) rtn_num.p1 = 1;
	if (iEqual11(a_num.p2, b_num.p2)) rtn_num.p2 = 1;
	if (iEqual11(a_num.p3, b_num.p3)) rtn_num.p3 = 1;
	if (iEqual11(a_num.p4, b_num.p4)) rtn_num.p4 = 1;
	if (iEqual11(a_num.p5, b_num.p5)) rtn_num.p5 = 1;
	if (iEqual11(a_num.p6, b_num.p6)) rtn_num.p6 = 1;
	if (iEqual11(a_num.p7, b_num.p7)) rtn_num.p7 = 1;
	if (iEqual11(a_num.p8, b_num.p8)) rtn_num.p8 = 1;
	if (iEqual11(a_num.p9, b_num.p9)) rtn_num.p9 = 1;
	if (iEqual11(a_num.p10, b_num.p10)) rtn_num.p10 = 1;
	if (iEqual11(a_num.p11, b_num.p11)) rtn_num.p11 = 1;
	if (iEqual11(a_num.p12, b_num.p12)) rtn_num.p12 = 1;
	if (iEqual11(a_num.p13, b_num.p13)) rtn_num.p13 = 1;
	if (iEqual11(a_num.p14, b_num.p14)) rtn_num.p14 = 1;
	if (iEqual11(a_num.p15, b_num.p15)) rtn_num.p15 = 1;
	if (iEqual11(a_num.p16, b_num.p16)) rtn_num.p16 = 1;
	if (iEqual11(a_num.p17, b_num.p17)) rtn_num.p17 = 1;
	if (iEqual11(a_num.p18, b_num.p18)) rtn_num.p18 = 1;
	if (iEqual11(a_num.p19, b_num.p19)) rtn_num.p19 = 1;
	if (iEqual11(a_num.p20, b_num.p20)) rtn_num.p20 = 1;
	if (iEqual11(a_num.p21, b_num.p21)) rtn_num.p21 = 1;
	if (iEqual11(a_num.p22, b_num.p22)) rtn_num.p22 = 1;
	if (iEqual11(a_num.p23, b_num.p23)) rtn_num.p23 = 1;
	if (iEqual11(a_num.p24, b_num.p24)) rtn_num.p24 = 1;
	if (iEqual11(a_num.p25, b_num.p25)) rtn_num.p25 = 1;
	if (iEqual11(a_num.p26, b_num.p26)) rtn_num.p26 = 1;
	if (iEqual11(a_num.p27, b_num.p27)) rtn_num.p27 = 1;
	if (iEqual11(a_num.p28, b_num.p28)) rtn_num.p28 = 1;
	if (iEqual11(a_num.p29, b_num.p29)) rtn_num.p29 = 1;
	if (iEqual11(a_num.p30, b_num.p30)) rtn_num.p30 = 1;
	if (iEqual11(a_num.p31, b_num.p31)) rtn_num.p31 = 1;

	int rtn = rtn_num.num;
	return rtn;
}


//not ���� ( ~a )
int not(int a) {
	struct num a_num;
	struct num rtn_num;
	int tmp = 0;
	a_num.num = a;
	rtn_num.num = tmp;

	rtn_num.p0 = iEqual(a_num.p0, 1) ? 0 : 1;
	rtn_num.p1 = iEqual(a_num.p1, 1) ? 0 : 1;
	rtn_num.p2 = iEqual(a_num.p2, 1) ? 0 : 1;
	rtn_num.p3 = iEqual(a_num.p3, 1) ? 0 : 1;
	rtn_num.p4 = iEqual(a_num.p4, 1) ? 0 : 1;
	rtn_num.p5 = iEqual(a_num.p5, 1) ? 0 : 1;
	rtn_num.p6 = iEqual(a_num.p6, 1) ? 0 : 1;
	rtn_num.p7 = iEqual(a_num.p7, 1) ? 0 : 1;
	rtn_num.p8 = iEqual(a_num.p8, 1) ? 0 : 1;
	rtn_num.p9 = iEqual(a_num.p9, 1) ? 0 : 1;
	rtn_num.p10 = iEqual(a_num.p10, 1) ? 0 : 1;
	rtn_num.p11 = iEqual(a_num.p11, 1) ? 0 : 1;
	rtn_num.p12 = iEqual(a_num.p12, 1) ? 0 : 1;
	rtn_num.p13 = iEqual(a_num.p13, 1) ? 0 : 1;
	rtn_num.p14 = iEqual(a_num.p14, 1) ? 0 : 1;
	rtn_num.p15 = iEqual(a_num.p15, 1) ? 0 : 1;
	rtn_num.p16 = iEqual(a_num.p16, 1) ? 0 : 1;
	rtn_num.p17 = iEqual(a_num.p17, 1) ? 0 : 1;
	rtn_num.p18 = iEqual(a_num.p18, 1) ? 0 : 1;
	rtn_num.p19 = iEqual(a_num.p19, 1) ? 0 : 1;
	rtn_num.p20 = iEqual(a_num.p20, 1) ? 0 : 1;
	rtn_num.p21 = iEqual(a_num.p21, 1) ? 0 : 1;
	rtn_num.p22 = iEqual(a_num.p22, 1) ? 0 : 1;
	rtn_num.p23 = iEqual(a_num.p23, 1) ? 0 : 1;
	rtn_num.p24 = iEqual(a_num.p24, 1) ? 0 : 1;
	rtn_num.p25 = iEqual(a_num.p25, 1) ? 0 : 1;
	rtn_num.p26 = iEqual(a_num.p26, 1) ? 0 : 1;
	rtn_num.p27 = iEqual(a_num.p27, 1) ? 0 : 1;
	rtn_num.p28 = iEqual(a_num.p28, 1) ? 0 : 1;
	rtn_num.p29 = iEqual(a_num.p29, 1) ? 0 : 1;
	rtn_num.p30 = iEqual(a_num.p30, 1) ? 0 : 1;
	rtn_num.p31 = iEqual(a_num.p31, 1) ? 0 : 1;

	int rtn = rtn_num.num;
	return rtn;
}

//���� �����.
int getComplement(int a) {
	return iPlusOne(not(a));
}

// ���� �Ǻ�
bool isNegative(int a) {
	return and (shift_arr[31], a);
}


// ��� �Ǻ�
bool isPositive(int a) {
	return iEqual(isNegative(a), false);
}


// !=
bool iNotEqual(int a, int b) {
	return iEqual(iEqual(a, b), false);
}

//����Ʈ ������ ���� shift_arr �ʱ�ȭ
void _init_() {
	or_arr[0] = 0;
	shift_arr[0] = 1;
	int i = 0;
	while (iNotEqual(i, MAXBIT)) {
		int next_i = iPlusOne(i);
		or_arr[next_i] = or (or_arr[i], shift_arr[i]);
		shift_arr[next_i] = iPlusOne(or_arr[next_i]);
		i = next_i;
	}
	shift_arr[0] = 1;
}


// �������� �ѹ� ����Ʈ ���� ( <<1 )
int leftShift(int a) {
	int i = 0;
	int rtn = 0;
	while (iNotEqual(i, MAXBIT)) {
		int next_i = iPlusOne(i);
		if (and (shift_arr[i], a)) {
			rtn = or (rtn, shift_arr[next_i]);
		}
		i = next_i;
	}
	return rtn;
}

// �������� cnt�� ����Ʈ ���� ( <<cnt )
int multiLeftShift(int a, int cnt) {
	int i = 0;
	while (iNotEqual(i, cnt)) {
		a = leftShift(a);
		i = iPlusOne(i);
	}
	return a;
}


//���ϱ� ���� ( a + b )
int addOperation(int a, int b) {
	int i = 0;
	int carry = 0;
	int result = 0;
	while (iNotEqual(i, MAXBIT)) {
		int next_i = iPlusOne(i);
		int a_sub = and (a, shift_arr[i]);
		int b_sub = and (b, shift_arr[i]);
		if (carry) {
			if (and (a_sub, b_sub)) {
				carry = shift_arr[next_i];
				result = or (result, shift_arr[i]);
			}
			else if (or (a_sub, b_sub)) {
				carry = shift_arr[next_i];
			}
			else {
				carry = 0;
				result = or (result, shift_arr[i]);
			}
		}
		else {
			if (and (a_sub, b_sub)) {
				carry = shift_arr[next_i];
			}
			else if (or (a_sub, b_sub)) {
				carry = 0;
				result = or (result, shift_arr[i]);
			}
			else {
				carry = 0;
			}
		}
		i = next_i;
	}
	return result;
}


// ���� ���� ( a - b )
int subtractOperation(int a, int b) {
	return addOperation(a, getComplement(b));
}

// ���ϱ� ���� ( a * b )
int multiplyOperation(int a, int b) {
	int i = 0;
	int result = 0;
	while (iNotEqual(i, MAXBIT)) {
		if (and (b, shift_arr[i])) {
			int sub = multiLeftShift(a, i);
			result = addOperation(result, sub);
		}
		i = iPlusOne(i);
	}
	return result;
}

// ~���� �۴�. ( < )
bool lessThan(int a, int b) {
	return isNegative(subtractOperation(a, b));
}

// ~���� �۰ų� ����. ( <= )
bool lessEqualThan(int a, int b) {
	return isPositive(subtractOperation(b, a));
}

// 0���� �������� �� ����
void divideByZero() {
	printf("DIVIDE BY ZERO ERROR OCCURS\n");
}

// (+,-,/) ��갪 ��� ���
void printResult(int a, int b, int result, char op, int real) {
	printf("\n���:%20d %c %-20d = %-20d\n", a, op, b, result);
	printf("����:%20d %c %-20d = %-20d\n", a, op, b, real);
}

// Interface �󿡼� ���ϱ� ���.
void add(int a, int b) {
	printResult(a, b, addOperation(a, b), '+', a + b);
}

// Interface �󿡼� ���� ���.
void subtract(int a, int b) {
	printResult(a, b, subtractOperation(a, b), '-', a - b);
}

// Interface �󿡼� ���ϱ� ���.
void multiply(int a, int b) {
	printResult(a, b, multiplyOperation(a, b), '*', a * b);
}

// Interface �󿡼� ������ ���.
void divide(int a, int b) {
	int a_org = a;
	int b_org = b;
	bool is_a_negative = isNegative(a);
	bool is_b_negative = isNegative(b);

	if (iEqual(b, 0)) {
		divideByZero();
		return;
	}

	if (and (is_a_negative, is_b_negative)) {//������ ����
		a = getComplement(a);
		b = getComplement(b);
	}
	else if (is_a_negative) {//�� �� ����
		a = getComplement(a);
	}
	else if (is_b_negative) {//�� ����
		b = getComplement(b);
	}

	int result = 0;
	while (lessEqualThan(b, a)) {
		int sub = b;
		int cnt = 0;
		while (true) {
			int tmp = leftShift(sub);
			cnt = iPlusOne(cnt);
			if (and (isPositive(tmp), lessEqualThan(tmp, a))) {
				sub = tmp;
			}
			else {
				break;
			}
		}
		result = or (result, shift_arr[subtractOperation(cnt, 1)]);
		a = subtractOperation(a, sub);
	}
	int quotient = result;
	int remainder = a;
	if (and (is_a_negative, is_b_negative)) {//������ ����
		remainder = getComplement(remainder);
	}
	else if (is_a_negative) {//�� �� ����
		quotient = getComplement(quotient);
		remainder = getComplement(remainder);
	}
	else if (is_b_negative) {//�� ����
		quotient = getComplement(quotient);
	}
	printf("\n���:%20d / %-20d = ��:%d ������:%d\n", a_org, b_org, quotient, remainder);
	printf("����:%20d / %-20d = ��:%d ������:%d\n", a_org, b_org, a_org / b_org, a_org % b_org);

	return;
}

// �Է� �������̽� �Լ�.
void inputInterface(int* first_num, int* second_num, char* operator) {
	printf("\nENTER FIRST OPERAND : ");
	scanf_s("%int", first_num);
	rewind(stdin);
	printf("ENTER OPERATOR : ");
	scanf_s("%c", operator,1);
	rewind(stdin);
	printf("ENTER SECOND OPERAND : ");
	scanf_s("%int", second_num);
	rewind(stdin);
}


// ���� �������̽� �Լ�.
int calculatorInterface() {
	int first_num, second_num;
	char operator;
	while (true) {
		inputInterface(&first_num, &second_num, &operator);
		switch (operator)
		{
		case '+':
			add(first_num, second_num);
			break;
		case '-':
			subtract(first_num, second_num);
			break;
		case '*':
			multiply(first_num, second_num);
			break;
		case '/':
			divide(first_num, second_num);
			break;
		default:
			printf("INPUT ERROR OCCURS\n");
		}
	}
}

// �׽�Ʈ �ڵ� ������ �Լ�.
void test() {
	srand((unsigned int)time(NULL));
	char arr[4] = { '+','-','*','/' };
	for (int i = 0; i < 100; i++) {
		int a = rand();
		int b = rand();
		int s1 = rand();
		int s2 = rand();
		char op = arr[rand() % 4];

		int n1 = (int)a;
		if (s1 % 2 == 0) n1 = -n1;
		int n2 = (int)b;
		if (s2 % 2 == 0) n2 = -n2;

		n1 = n1 << s1 % MAXSHIFT;
		n2 = n2 << s2 % MAXSHIFT;
		//���� ���� ����
		switch (op)
		{
		case '+':
			add(n1, n2);
			break;
		case '-':
			subtract(n1, n2);
			break;
		case '*':
			multiply(n1, n2);
			break;
		case '/':
			divide(n1, n2);
			break;
		}

	}
	printf("\n���� ��°����� �׽�Ʈ ���� �Դϴ�.\n");
	printf("������ ���α׷� ���ö�� rand()�Լ��� �̿��� ��� ���õ��� �������ҽ��ϴ�.\n");
	printf("��갪���� ���� § �������� ����� ��, ���������� �⺻ ��Ģ �����ڸ� �̿��� ����� �� �Դϴ�.\n");

	printf("\n\n���α׷� ����---\n\n");
	printf("�ش� ���� ���α׷��� 32��Ʈ���� ó�������ϸ�, ���� ���� ���� ó�� �����մϴ�..\n");
	printf("64��Ʈ�� ���� �� �־�����.. �ʹ� �ݺ��۾��� ���Ͽ� �׳� 32��Ʈ���� ó�� �����ϰ� ��������ϴ�.\n\n");

	printf("and ��Ʈ ������ ���� : ����ü�� ��Ʈ �ʵ� �̿�, �� �������� if������ ������ && ���� ����. true->1 , false->0\n");
	printf("or  ��Ʈ ������ ���� : ����ü�� ��Ʈ �ʵ� �̿�, �� �������� if������ ������ || ���� ����. true->1 , false->0\n");
	printf("not ��Ʈ ������ ���� : ����ü�� ��Ʈ �ʵ� �̿�, �� �������� 0�̸� 1�� 1�̸� 0���� �ٲپ� �ִ� �۾� ����\n\n");

	printf("shift ��Ʈ ������ ���� : shift[32] �迭�� 0001, 0010, 0100, 1000 �� ���� ���� ä�����μ� ����\n");
	printf("                         ���� �迭�� ��������, �� ��Ʈ�� �������� �����̴� �Լ� ����.\n");
	printf("                         �� ��Ʈ�� �������� �����̴� �Լ���, ���ϴ� Ƚ����ŭ �������� �ű�� �Լ� ����\n\n");

	printf("+ ��Ģ ������ ���� : carry ������ �����Ͽ� �Ϲ� �� ���ϵ��� ����\n");
	printf("- ��Ģ ������ ���� : �ι�° ���ڸ� ������ ����� + ������ ����\n");
	printf("* ��Ģ ������ ���� : �Ϲ� �� ���ϵ��� ����\n");
	printf("/ ��Ģ ������ ���� : �ǿ����ڿ� �����϶� �������� ������.\n");
	printf("                     �Ƹ� ����ü�� ������ �Ͼ ������� ����.\n");
	printf("                     �� �ǿ����ڰ� �������� ������� �Ǵ��Ͽ� ��� ����� �ٲپ� �ְ�\n");
	printf("                     ������� ������ ������ ���������μ� ����\n");
	printf("----------------------------------------------------------------------------------------------------------------\n\n");





}

// ���� �ʱ�ȭ
void generateCalculator() {
	_init_();
	test();
}

int main() {
	generateCalculator();
	calculatorInterface();
}