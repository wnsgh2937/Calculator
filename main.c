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

// true true 검출
bool iEqual11(int a, int b) {
	if (iEqual(a, 1)) {
		if (iEqual(b, 1)) {
			return true;
		}
	}
	return false;
}

// false false 검출
bool iEqual00(int a, int b) {
	if (iEqual(a, 0)) {
		if (iEqual(b, 0)) {
			return true;
		}
	}
	return false;
}

// true false / false true 검출
bool iEqual10(int a, int b) {
	if (iEqual00(a, b)) {
		return false;
	}
	return true;
}

//or연산 (a|b)
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

//and 연산 (a&b)
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


//not 연산 ( ~a )
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

//보수 만들기.
int getComplement(int a) {
	return iPlusOne(not(a));
}

// 음수 판별
bool isNegative(int a) {
	return and (shift_arr[31], a);
}


// 양수 판별
bool isPositive(int a) {
	return iEqual(isNegative(a), false);
}


// !=
bool iNotEqual(int a, int b) {
	return iEqual(iEqual(a, b), false);
}

//쉬프트 연산을 위한 shift_arr 초기화
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


// 왼쪽으로 한번 쉬프트 연산 ( <<1 )
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

// 왼쪽으로 cnt번 쉬프트 연산 ( <<cnt )
int multiLeftShift(int a, int cnt) {
	int i = 0;
	while (iNotEqual(i, cnt)) {
		a = leftShift(a);
		i = iPlusOne(i);
	}
	return a;
}


//더하기 연산 ( a + b )
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


// 빼기 연산 ( a - b )
int subtractOperation(int a, int b) {
	return addOperation(a, getComplement(b));
}

// 곱하기 연산 ( a * b )
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

// ~보다 작다. ( < )
bool lessThan(int a, int b) {
	return isNegative(subtractOperation(a, b));
}

// ~보다 작거나 같다. ( <= )
bool lessEqualThan(int a, int b) {
	return isPositive(subtractOperation(b, a));
}

// 0으로 나누었을 때 오류
void divideByZero() {
	printf("DIVIDE BY ZERO ERROR OCCURS\n");
}

// (+,-,/) 계산값 출력 기능
void printResult(int a, int b, int result, char op, int real) {
	printf("\n계산:%20d %c %-20d = %-20d\n", a, op, b, result);
	printf("실제:%20d %c %-20d = %-20d\n", a, op, b, real);
}

// Interface 상에서 더하기 기능.
void add(int a, int b) {
	printResult(a, b, addOperation(a, b), '+', a + b);
}

// Interface 상에서 빼기 기능.
void subtract(int a, int b) {
	printResult(a, b, subtractOperation(a, b), '-', a - b);
}

// Interface 상에서 곱하기 기능.
void multiply(int a, int b) {
	printResult(a, b, multiplyOperation(a, b), '*', a * b);
}

// Interface 상에서 나누기 기능.
void divide(int a, int b) {
	int a_org = a;
	int b_org = b;
	bool is_a_negative = isNegative(a);
	bool is_b_negative = isNegative(b);

	if (iEqual(b, 0)) {
		divideByZero();
		return;
	}

	if (and (is_a_negative, is_b_negative)) {//나머지 보수
		a = getComplement(a);
		b = getComplement(b);
	}
	else if (is_a_negative) {//둘 다 보수
		a = getComplement(a);
	}
	else if (is_b_negative) {//몫 보수
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
	if (and (is_a_negative, is_b_negative)) {//나머지 보수
		remainder = getComplement(remainder);
	}
	else if (is_a_negative) {//둘 다 보수
		quotient = getComplement(quotient);
		remainder = getComplement(remainder);
	}
	else if (is_b_negative) {//몫 보수
		quotient = getComplement(quotient);
	}
	printf("\n계산:%20d / %-20d = 몫:%d 나머지:%d\n", a_org, b_org, quotient, remainder);
	printf("실제:%20d / %-20d = 몫:%d 나머지:%d\n", a_org, b_org, a_org / b_org, a_org % b_org);

	return;
}

// 입력 인터페이스 함수.
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


// 계산기 인터페이스 함수.
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

// 테스트 코드 돌리는 함수.
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
		//난수 생성 과정
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
	printf("\n위에 출력값들은 테스트 값들 입니다.\n");
	printf("빠르게 프로그램 보시라고 rand()함수를 이용해 계산 예시들을 만들어놓았습니다.\n");
	printf("계산값들은 제가 짠 로직으로 계산한 값, 실제값들은 기본 사칙 연산자를 이용해 계산한 값 입니다.\n");

	printf("\n\n프로그램 설명---\n\n");
	printf("해당 계산기 프로그램은 32비트까지 처리가능하며, 음수 연산 또한 처리 가능합니다..\n");
	printf("64비트도 만들 수 있었으나.. 너무 반복작업이 심하여 그냥 32비트까지 처리 가능하게 만들었습니다.\n\n");

	printf("and 비트 연산자 구현 : 공용체와 비트 필드 이용, 각 변수별로 if문으로 구현한 && 연산 시행. true->1 , false->0\n");
	printf("or  비트 연산자 구현 : 공용체와 비트 필드 이용, 각 변수별로 if문으로 구현한 || 연산 시행. true->1 , false->0\n");
	printf("not 비트 연산자 구현 : 공용체와 비트 필드 이용, 각 변수별로 0이면 1로 1이면 0으로 바꾸어 주는 작업 시행\n\n");

	printf("shift 비트 연산자 구현 : shift[32] 배열에 0001, 0010, 0100, 1000 과 같은 값을 채움으로서 구현\n");
	printf("                         만든 배열을 바탕으로, 한 비트씩 왼쪽으로 움직이는 함수 구현.\n");
	printf("                         한 비트씩 왼쪽으로 움직이는 함수로, 원하는 횟수만큼 왼쪽으로 옮기는 함수 구현\n\n");

	printf("+ 사칙 연산자 구현 : carry 변수를 선언하여 일반 수 더하듯이 구현\n");
	printf("- 사칙 연산자 구현 : 두번째 숫자를 보수로 만들어 + 연산자 적용\n");
	printf("* 사칙 연산자 구현 : 일반 수 곱하듯이 구현\n");
	printf("/ 사칙 연산자 구현 : 피연산자에 음수일때 계산오류가 났었음.\n");
	printf("                     아마 보수체계 때문에 일어난 오류라고 생각.\n");
	printf("                     각 피연산자가 음수인지 양수인지 판단하여 모두 양수로 바꾸어 주고\n");
	printf("                     결과값에 적절히 보수를 취해줌으로서 구현\n");
	printf("----------------------------------------------------------------------------------------------------------------\n\n");





}

// 계산기 초기화
void generateCalculator() {
	_init_();
	test();
}

int main() {
	generateCalculator();
	calculatorInterface();
}