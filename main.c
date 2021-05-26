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

//보수 만들기.
lld getComplement(lld a) {
	return iPlusOne(~a);
}


// 음수 판별
bool isNegative(lld a) {
	return shift_arr[63] & a;
}


// 양수 판별
bool isPositive(lld a) {
	return iEqual(isNegative(a), false);
}


// !=
bool iNotEqual(lld a, lld b) {
	return iEqual(iEqual(a, b), false);
}

//쉬프트 연산을 위한 shift_arr 초기화
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


// 왼쪽으로 한번 쉬프트 연산 ( <<1 )
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

// 왼쪽으로 cnt번 쉬프트 연산 ( <<cnt )
lld multiLeftShift(lld a, lld cnt) {
	lld i = 0;
	while (iNotEqual(i, cnt)) {
		a = leftShift(a);
		i = iPlusOne(i);
	}
	return a;
}


//더하기 연산 ( a + b )
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


// 빼기 연산 ( a - b )
lld subtractOperation(lld a, lld b) {
	return addOperation(a, getComplement(b));
}


// 곱하기 연산 ( a * b )
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


// 양수 나누기 연산 ( a/b , a>0 && b>0 )
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

//나누기 연산 ( a / b )
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

// ~보다 작다. ( < )
bool lessThan(lld a, lld b) {
	return isNegative(subtractOperation(a, b));
}

// ~보다 작거나 같다. ( <= )
bool lessEqualThan(lld a, lld b) {
	return isPositive(subtractOperation(b, a));
}

// 0으로 나누었을 때 오류
void divideByZero() {
	printf("DIVIDE BY ZERO ERROR OCCURS\n");
}

// (+,-,/) 계산값 출력 기능
void printResult(lld a, lld b, lld result, char op, lld real) {
	printf("\n계산:%20lld %c %-20lld = %-20lld\n", a, op, b, result);
	printf("실제:%20lld %c %-20lld = %-20lld\n", a, op, b, real);
}

// Interface 상에서 더하기 기능.
void add(lld a, lld b) {
	printResult(a, b, addOperation(a, b), '+', a + b);
}

// Interface 상에서 빼기 기능.
void subtract(lld a, lld b) {
	printResult(a, b, subtractOperation(a, b), '-', a - b);
}

// Interface 상에서 곱하기 기능.
void multiply(lld a, lld b) {
	printResult(a, b, multiplyOperation(a, b), '*', a * b);
}

// Interface 상에서 나누기 기능.
void divide(lld a, lld b) {
	struct divideValue* result = divideOperation(a, b);
	if (result->divide_by_zero) {
		divideByZero();
	}
	else {
		printf("\n계산:%20lld / %-20lld = 몫:%-lld 나머지:%lld\n", a, b, result->quotient, result->remainder);
		printf("실제:%20lld / %-20lld = 몫:%-lld 나머지:%lld\n", a, b, a / b, a % b);
	}
	free(result);
}

// 입력 인터페이스 함수.
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


// 계산기 인터페이스 함수.
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

		lld n1 = (lld)a;
		if (s1 % 2 == 0) n1 = -n1;
		lld n2 = (lld)b;
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
	printf("해당 계산기 프로그램은 64비트까지 처리가능하며, 음수 연산 또한 처리 가능합니다..\n");
	printf("보고서를 만들 시간이 없어서.. 프로그램 내에서 프로그램 설명 간략하게 하겠습니다.\n\n");
	printf("과제를 진행함에 있어서 많은 고민을 했지만, 가장 핵심인 부분은 left shift를 구현하는 부분이었습니다.\n");
	printf("이 left shift연산을 통해 모든 사칙연산을 구현했기 때문입니다.\n\n");

	printf("left shift는 배열에 0001, 0010, 0100, 1000 과 값들을 저장함으로서 구현했고, 핵심 로직은 다음과 같습니다.\n");
	printf("1000 을 만들기 위해선, 0111에다 1만 더하면 된다는 생각을 했습니다.\n");
	printf("또 0111을 만들기 위해선 0100 + 0010 + 0001 을 하면 된다는 생각을 했습니다.\n");
	printf("숫자 출현의 규칙성이 보여, \nshift_arr에는 1000, 0100, 0010, 0001 과 같은 값을 저장하고\n");
	printf("  xor_arr에는 0111, 0011, 0001, 0000 과 같은 값을 저장하여 left shift를 구현했습니다.\n");
	printf("0000과 0001을 xor 연산하면 0001이 나옵니다. 1을 더하면 0010 이 나옵니다.\n");
	printf("0010과 0001을 xor 연산하면 0011이 나옵니다. 1을 더하면 0100 이 나옵니다.\n");
	printf("0100과 0011을 xor 연산하면 0111이 나옵니다. 1을 더하면 1000 이 나옵니다.\n");
	printf("이런 로직을 통해 64비트 길이의 shift배열을 만들어 left shift를 구현했습니다.\n");


	printf("\n----------더하기 로직 구현\n");
	printf("left shift를 구현하니, 더하기 로직은 구현하기 쉬웠습니다. carry수를 선언하여 일반 숫자 더하듯이 더하는 로직으로 구현했습니다.\n");
	printf("\n----------빼기 로직 구현\n");
	printf("보수를 구하여 더했습니다. 보수는 not 연산에 +1을 하여 구했습니다.\n");
	printf("\n----------곱하기 로직 구현\n");
	printf("여러번 더하여 구현할까 생각을 많이 했지만, 특정 케이스에 대해 시간이 매우 오래 걸릴 것 같아 일반적인 곱셈 로직을 코드로 구현했습니다.\n");
	printf("\n----------나누기 로직 구현\n");
	printf("좀 어려웠습니다. 일반적인 나누기 로직으로, 양수간의 나눗셈은 가능했지만 음수가 들어가면 수가 어디선가 꼬이는 문제가 발생했습니다. \n");
	printf("아마 보수체계가 들어가서 일반적인 나누기로는 처리가 불가능한 듯 보였습니다.\n");
	printf("그래서 모든 피연산자를 양수로 바꾸어 주고 계산을 한 후에, 적절히 몫 혹은 나머지를 보수로 바꾸어 주는 로직으로 구현했습니다.\n");
}

// 계산기 초기화
void generateCalculator() {
	_init_();
	test();
}

// 메인 함수
int main() {
	generateCalculator();
	calculatorInterface();
}