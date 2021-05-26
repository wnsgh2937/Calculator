#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXBIT 64
#define MAXSHIFT 20
#define lld long long int
#define bool lld

bool lessEqualThan(lld a, lld b);
bool lessThan(lld a, lld b);

struct divideValue {
	lld quotient;
	lld remainder;
	bool divide_by_zero;
}divideValue;

lld shift_arr[MAXBIT];
lld xor_arr[MAXBIT];

// ==
bool iEqual(lld a, lld b) {
	if (a == b) return true;
	else return false;
}

// ++
lld iPlusOne(lld a) {
	return ++a;
}

//���� �����.
lld getComplement(lld a) {
	return iPlusOne(~a);
}


// ���� �Ǻ�
bool isNegative(lld a) {
	return shift_arr[63] & a;
}


// ��� �Ǻ�
bool isPositive(lld a) {
	return iEqual(isNegative(a), false);
}


// !=
bool iNotEqual(lld a, lld b) {
	return iEqual(iEqual(a, b), false);
}

//����Ʈ ������ ���� shift_arr �ʱ�ȭ
void _init_() {
	xor_arr[0] = 0;
	shift_arr[0] = 1;
	lld i = 0;
	while (iNotEqual(i, MAXBIT)) {
		lld next_i = iPlusOne(i);
		xor_arr[next_i] = xor_arr[i] ^ shift_arr[i];
		shift_arr[next_i] = iPlusOne(xor_arr[next_i]);
		i = next_i;
	}
	shift_arr[0] = 1;
}


// �������� �ѹ� ����Ʈ ���� ( <<1 )
lld leftShift(lld a) {
	lld i = 0;
	lld rtn = 0;
	while (iNotEqual(i, MAXBIT)) {
		lld next_i = iPlusOne(i);
		if (shift_arr[i] & a) {
			rtn |= shift_arr[next_i];
		}
		i = next_i;
	}
	return rtn;
}

// �������� cnt�� ����Ʈ ���� ( <<cnt )
lld multiLeftShift(lld a, lld cnt) {
	lld i = 0;
	while (iNotEqual(i, cnt)) {
		a = leftShift(a);
		i = iPlusOne(i);
	}
	return a;
}


//���ϱ� ���� ( a + b )
lld addOperation(lld a, lld b) {
	lld i = 0;
	lld carry = 0;
	lld result = 0;
	while (iNotEqual(i, MAXBIT)) {
		lld next_i = iPlusOne(i);
		lld a_sub = a & shift_arr[i];
		lld b_sub = b & shift_arr[i];
		if (carry) {
			if (a_sub & b_sub) {
				carry = shift_arr[next_i];
				result |= shift_arr[i];
			}
			else if (a_sub | b_sub) {
				carry = shift_arr[next_i];
			}
			else {
				carry = 0;
				result |= shift_arr[i];
			}
		}
		else {
			if (a_sub & b_sub) {
				carry = shift_arr[next_i];
			}
			else if (a_sub | b_sub) {
				carry = 0;
				result |= shift_arr[i];
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
lld subtractOperation(lld a, lld b) {
	return addOperation(a, getComplement(b));
}


// ���ϱ� ���� ( a * b )
lld multiplyOperation(lld a, lld b) {
	lld i = 0;
	lld result = 0;
	while (iNotEqual(i, MAXBIT)) {
		if (b & shift_arr[i]) {
			lld sub = multiLeftShift(a, i);
			result = addOperation(result, sub);
		}
		i = iPlusOne(i);
	}
	return result;
}


// ��� ������ ���� ( a/b , a>0 && b>0 )
struct divideValue* positiveDivideOperation(lld a, lld b) {
	lld result = 0;
	while (lessEqualThan(b, a)) {
		lld sub = b;
		lld cnt = 0;
		while (true) {
			lld tmp = leftShift(sub);
			cnt = iPlusOne(cnt);
			if (isPositive(tmp) & lessEqualThan(tmp, a)) {
				sub = tmp;
			}
			else {
				break;
			}
		}
		result |= shift_arr[subtractOperation(cnt, 1)];
		a = subtractOperation(a, sub);
	}
	struct divideValue* rtn = malloc(sizeof(struct divideValue));
	rtn->quotient = result;
	rtn->remainder = a;
	return rtn;
}

//������ ���� ( a / b )
struct divideValue* divideOperation(lld a, lld b) {
	struct divideValue* rtn;
	if (iEqual(b, 0)) {
		rtn = malloc(sizeof(divideValue));
		rtn->divide_by_zero = true;
		return rtn;
	}
	if (isNegative(a) & isNegative(b)) {
		rtn = positiveDivideOperation(getComplement(a), getComplement(b));
		rtn->remainder = getComplement(rtn->remainder);
	}
	else if (isNegative(a)) {
		rtn = positiveDivideOperation(getComplement(a), b);
		rtn->remainder = getComplement(rtn->remainder);
		rtn->quotient = getComplement(rtn->quotient);
	}
	else if (isNegative(b)) {
		rtn = positiveDivideOperation(a, getComplement(b));
		rtn->quotient = getComplement(rtn->quotient);
	}
	else {
		rtn = positiveDivideOperation(a, b);
	}
	rtn->divide_by_zero = false;
	return rtn;
}

// ~���� �۴�. ( < )
bool lessThan(lld a, lld b) {
	return isNegative(subtractOperation(a, b));
}

// ~���� �۰ų� ����. ( <= )
bool lessEqualThan(lld a, lld b) {
	return isPositive(subtractOperation(b, a));
}

// 0���� �������� �� ����
void divideByZero() {
	printf("DIVIDE BY ZERO ERROR OCCURS\n");
}

// (+,-,/) ��갪 ��� ���
void printResult(lld a, lld b, lld result, char op, lld real) {
	printf("\n���:%20lld %c %-20lld = %-20lld\n", a, op, b, result);
	printf("����:%20lld %c %-20lld = %-20lld\n", a, op, b, real);
}

// Interface �󿡼� ���ϱ� ���.
void add(lld a, lld b) {
	printResult(a, b, addOperation(a, b), '+', a + b);
}

// Interface �󿡼� ���� ���.
void subtract(lld a, lld b) {
	printResult(a, b, subtractOperation(a, b), '-', a - b);
}

// Interface �󿡼� ���ϱ� ���.
void multiply(lld a, lld b) {
	printResult(a, b, multiplyOperation(a, b), '*', a * b);
}

// Interface �󿡼� ������ ���.
void divide(lld a, lld b) {
	struct divideValue* result = divideOperation(a, b);
	if (result->divide_by_zero) {
		divideByZero();
	}
	else {
		printf("\n���:%20lld / %-20lld = ��:%-lld ������:%lld\n", a, b, result->quotient, result->remainder);
		printf("����:%20lld / %-20lld = ��:%-lld ������:%lld\n", a, b, a / b, a % b);
	}
	free(result);
}

// �Է� �������̽� �Լ�.
void inputInterface(lld* first_num, lld* second_num, char* operator) {
	printf("\nENTER FIRST OPERAND : ");
	scanf_s("%lld", first_num);
	rewind(stdin);
	printf("ENTER OPERATOR : ");
	scanf_s("%c", operator,1);
	rewind(stdin);
	printf("ENTER SECOND OPERAND : ");
	scanf_s("%lld", second_num);
	rewind(stdin);
}


// ���� �������̽� �Լ�.
lld calculatorInterface() {
	lld first_num, second_num;
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

		lld n1 = (lld)a;
		if (s1 % 2 == 0) n1 = -n1;
		lld n2 = (lld)b;
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
	printf("�ش� ���� ���α׷��� 64��Ʈ���� ó�������ϸ�, ���� ���� ���� ó�� �����մϴ�..\n");
	printf("������ ���� �ð��� ���.. ���α׷� ������ ���α׷� ���� �����ϰ� �ϰڽ��ϴ�.\n\n");
	printf("������ �����Կ� �־ ���� ����� ������, ���� �ٽ��� �κ��� left shift�� �����ϴ� �κ��̾����ϴ�.\n");
	printf("�� left shift������ ���� ��� ��Ģ������ �����߱� �����Դϴ�.\n\n");

	printf("left shift�� �迭�� 0001, 0010, 0100, 1000 �� ������ ���������μ� �����߰�, �ٽ� ������ ������ �����ϴ�.\n");
	printf("1000 �� ����� ���ؼ�, 0111���� 1�� ���ϸ� �ȴٴ� ������ �߽��ϴ�.\n");
	printf("�� 0111�� ����� ���ؼ� 0100 + 0010 + 0001 �� �ϸ� �ȴٴ� ������ �߽��ϴ�.\n");
	printf("���� ������ ��Ģ���� ����, \nshift_arr���� 1000, 0100, 0010, 0001 �� ���� ���� �����ϰ�\n");
	printf("  xor_arr���� 0111, 0011, 0001, 0000 �� ���� ���� �����Ͽ� left shift�� �����߽��ϴ�.\n");
	printf("0000�� 0001�� xor �����ϸ� 0001�� ���ɴϴ�. 1�� ���ϸ� 0010 �� ���ɴϴ�.\n");
	printf("0010�� 0001�� xor �����ϸ� 0011�� ���ɴϴ�. 1�� ���ϸ� 0100 �� ���ɴϴ�.\n");
	printf("0100�� 0011�� xor �����ϸ� 0111�� ���ɴϴ�. 1�� ���ϸ� 1000 �� ���ɴϴ�.\n");
	printf("�̷� ������ ���� 64��Ʈ ������ shift�迭�� ����� left shift�� �����߽��ϴ�.\n");


	printf("\n----------���ϱ� ���� ����\n");
	printf("left shift�� �����ϴ�, ���ϱ� ������ �����ϱ� �������ϴ�. carry���� �����Ͽ� �Ϲ� ���� ���ϵ��� ���ϴ� �������� �����߽��ϴ�.\n");
	printf("\n----------���� ���� ����\n");
	printf("������ ���Ͽ� ���߽��ϴ�. ������ not ���꿡 +1�� �Ͽ� ���߽��ϴ�.\n");
	printf("\n----------���ϱ� ���� ����\n");
	printf("������ ���Ͽ� �����ұ� ������ ���� ������, Ư�� ���̽��� ���� �ð��� �ſ� ���� �ɸ� �� ���� �Ϲ����� ���� ������ �ڵ�� �����߽��ϴ�.\n");
	printf("\n----------������ ���� ����\n");
	printf("�� ��������ϴ�. �Ϲ����� ������ ��������, ������� �������� ���������� ������ ���� ���� ��𼱰� ���̴� ������ �߻��߽��ϴ�. \n");
	printf("�Ƹ� ����ü�谡 ���� �Ϲ����� ������δ� ó���� �Ұ����� �� �������ϴ�.\n");
	printf("�׷��� ��� �ǿ����ڸ� ����� �ٲپ� �ְ� ����� �� �Ŀ�, ������ �� Ȥ�� �������� ������ �ٲپ� �ִ� �������� �����߽��ϴ�.\n");
}

// ���� �ʱ�ȭ
void generateCalculator() {
	_init_();
	test();
}

// ���� �Լ�
int main() {
	generateCalculator();
	calculatorInterface();
}