//#define _CRT_SECURE_NO_WARNINGS // fscanf, fprintf 오류 해결
#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial { // 노드 타입
	int coef, expon;
	struct Polynomial* link;
}Polynomial;


// 함수 선언
void error(char* message); // error message 함수
Polynomial* check(Polynomial* plist, int expon); // 기존에 expon과 일치하는 expon이 있는지 검사하는 함수
void insert_node_last(Polynomial** plist, int coef, int expon); // 리스트를 맨뒤에 삽입하는 함수
Polynomial* poly_add(Polynomial* plist1, Polynomial* plist2); // 다항식 덧셈 함수
Polynomial* poly_multi(Polynomial* plist1, Polynomial* plist2); // 다항식 곱셈 함수
Polynomial* poly_sort(Polynomial* plist); // 내림차순 정렬 함수 + 계수가 0인 항이 있을 경우 제거

// main 함수
int main()
{
	printf("11111");
	int coef, expon;
	int len_p1 = 0, len_p2 = 0;
	char c = 0;
	int count = 0;
	char temp[8];
	char less[8];

	Polynomial* plist1 = NULL;
	Polynomial* plist2 = NULL;
	Polynomial* result_add = NULL;
	Polynomial* result_multi = NULL;

	FILE* output = NULL;
	FILE* input = fopen("input.txt", "rt"); // 입력 파일 읽기 전용 개방
	// 입력 파일 불러오기가 정상적으로 작동되었는지 확인
	if (input == NULL)
	{
		error("입력 파일 불러오기에 실패했습니다.");
	}

	// 두 다항식의 길이 계산
	while (1) {  
		fgets(temp, 8, input);// fgets는 개행을 만나면 출력을 종료하므로 행 단위로 길이를 계산한다.
		if (temp[0] == '\n')
			break; //개행으로 시작하는 경우 첫번째 다항식의 길이 계산을 종료한다.
		len_p1++;
	}
	/*
	while (1) {  
		fgets(less, 8, input);// fgets는 개행을 만나면 출력을 종료하므로 행 단위로 길이를 계산한다.
		if (less[0] == '\n')
			break; //개행으로 시작하는 경우 첫번째 다항식의 길이 계산을 종료한다.
		len_p2++;
	}
	*/
	while ((c = fgetc(input)) != EOF) { // 두번째 다항식의 길이를 파일의 끝까지 행 단위로 길이를 계산한다.
		if (c == '\n')
			len_p2++;
	}
	len_p2++;
	printf("%d %d\n",len_p1,len_p2);
	fclose(input); // 입력 파일 닫기


	input = fopen("input.txt", "rt"); // 입력 파일 읽기 전용 개방

	// 입력 파일 불러오기가 정상적으로 작동되었는지 확인
	if (input == NULL)
	{
		error("입력 파일 불러오기에 실패했습니다.");
	}

	// 두 개의 다항식을 구분해서 받아온다.
	for (int i = 0; i < len_p1; i++)
	{
		fscanf(input, "%d %d", &coef, &expon);
		insert_node_last(&plist1, coef, expon);
	}

	for (int i = 0; i < len_p2; i++)
	{
		fscanf(input, "%d %d", &coef, &expon);
		insert_node_last(&plist2, coef, expon);
	}
	fclose(input);

	// 두 다항식의 덧셈과 곱셈 연산 함수를 통해 연산한다.
	result_add = poly_sort(poly_add(plist1, plist2));

	result_multi = poly_sort(poly_multi(plist1, plist2));

	output = fopen("output.txt", "wt"); // 출력 파일 쓰기 전용 개방

	// 출력 파일 불러오기가 정상적으로 작동되었는지 확인
	if (output == NULL)
	{
		fprintf(stderr, "출력 파일 불러오기에 실패했습니다.\n");
		exit(1);
	}

	fprintf(output, "Addition\n");

	while (result_add != NULL)
	{
		fprintf(output, "%d %d\n", result_add->coef, result_add->expon);
		result_add = result_add->link;
		count++;
	}
	if (count == 0)
		fprintf(output, "0\n");

	count = 0;

	fclose(output); // 출력 파일 닫기

	output = fopen("output.txt", "at"); // 출력 파일 쓰기 전용 개방

	// 출력 파일 불러오기가 정상적으로 작동되었는지 확인
	if (output == NULL)
	{
		fprintf(stderr, "출력 파일 불러오기에 실패했습니다.\n");
		exit(1);
	}

	fprintf(output, "Multiplication\n");
	while (result_multi != NULL)
	{
		fprintf(output, "%d %d\n", result_multi->coef, result_multi->expon);
		result_multi = result_multi->link;
		count++;
	}
	if (count == 0)
		fprintf(output, "0\n");

	fclose(output); // 출력 파일 닫기

	return 0;
}

// error message 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 기존에 expon과 일치하는 expon이 있는지 검사하는 함수
Polynomial* check(Polynomial* plist, int expon)
{
	Polynomial* p = plist;
	while (p != NULL)
	{
		if (p->expon == expon) return p;
		p = p->link;
	}
	return NULL;
}

// 새로운 항을 맨뒤에 삽입하는 함수
void insert_node_last(Polynomial** plist, int coef, int expon)
{
	Polynomial* temp, * pre;
	temp = *plist;
	pre = temp;

	Polynomial* newnode = NULL;
	newnode = (Polynomial*)malloc(sizeof(Polynomial));
	if (newnode == NULL) error("메모리 할당 에러");
	newnode->coef = coef;
	newnode->expon = expon;

	if (*plist == NULL)
	{
		(*plist) = newnode;
		newnode->link = NULL;
	}
	else
	{
		while (temp != NULL)
		{
			pre = temp;
			temp = temp->link;
		}
		newnode->link = NULL;
		pre->link = newnode;
	}
}

// 다항식 덧셈 함수
Polynomial* poly_add(Polynomial* plist1, Polynomial* plist2)
{
	Polynomial* a = plist1;
	Polynomial* b = plist2;
	Polynomial* result = NULL;

	while (a != NULL)
	{
		insert_node_last(&result, a->coef, a->expon);
		a = a->link;
	}
	while (b != NULL)
	{
		if (check(result, b->expon) == NULL) // 기존에 동일한 expon이 없다면 새로 맨뒤에 삽입한다.
		{
			insert_node_last(&result, b->coef, b->expon);
			b = b->link;
		}
		else // 기존에 동일한 expon을 갖는 항이 존재하면 기존 항의 coef에 b의 coef를 더해준다.
		{
			check(result, b->expon)->coef += b->coef;
			b = b->link;
		}
	}

	return result;
}

// 다항식 곱셈 함수
Polynomial* poly_multi(Polynomial* plist1, Polynomial* plist2)
{
	Polynomial* a = plist1;
	Polynomial* b = plist2;
	Polynomial* result = NULL;
	Polynomial* temp = b;

	while (a != NULL)
	{
		while (b != NULL)
		{
			if (check(result, (a->expon) + (b->expon)) == NULL) // 기존에 동일한 expon이 없다면 새로운 항을 맨뒤에 삽입한다.
			{
				insert_node_last(&result, (a->coef) * (b->coef), (a->expon) + (b->expon));
				b = b->link;
			}
			else  // 기존에 동일한 expon을 갖는 항이 존재하면 기존 항의 coef에 a와 b의 coef의 곱을 더해준다.
			{
				check(result, (a->expon) + (b->expon))->coef += (a->coef) * (b->coef);
				b = b->link;
			}
		}
		a = a->link;
		b = temp;
	}
	return result;
}

// 내림차순 정렬 함수 
// 계수가 0인 항이 있을 경우 제거
Polynomial* poly_sort(Polynomial* plist)
{
	Polynomial* p = plist;
	Polynomial* result = NULL;
	Polynomial* max = p;
	int i = 0;

	// 다항식에서 최고차수를 갖는 항을 찾는다.
	while (p != NULL)
	{
		if ((max->expon) < (p->expon))
		{
			max = p;
		}
		p = p->link;
	}
	i = (max->expon);

	// 최고차항부터 0까지의 차수 중 plist에 존재하는 차수를 내림차순으로 정렬한다.
	while (i != -1)
	{
		if (check(plist, i) != NULL && check(plist, i)->coef != 0 && (check(result, i) == NULL))
		{
			insert_node_last(&result, (check(plist, i)->coef), (check(plist, i)->expon));
		}
		i--;
	}
	return result;
}
