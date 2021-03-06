//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_STACK_SIZE 100
//typedef char element;
//
//typedef struct
//{
//	element stack[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
////스택 초기화 함수
//void init(StackType *s)
//{
//	s->top = -1;
//}
//
////공백 상태 검출 함수
//int is_empty(StackType *s)
//{
//	return (s->top == -1);
//}
//
////포화 상태 검출 함수
//int is_full(StackType *s)
//{
//	return (s->top == MAX_STACK_SIZE - 1);
//}
//
////삽입 함수
//void push(StackType *s, element item)
//{
//	if (is_full(s))
//	{
//		printf("메모리 참조 에러");
//		return;
//	}
//	else s->stack[++(s->top)] = item;
//}
//
////삭제 함수
//element pop(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return s->stack[(s->top)--];
//}
//
////피크 함수
//element peek(StackType *s)
//{
//	if (is_empty(s))
//	{
//		printf("메모리 참조 에러");
//		exit(1);
//	}
//	else return s->stack[s->top];
//}
//
////연산자의 우선순위를 반환한다.
//int prec(char op)
//{
//	switch (op)
//	{
//	case '(': case ')': return 0;
//	case '+': case '-': return 1;
//	case '*': case '/': return 2;
//	}
//	return -1;
//}
//
////중위 표기 수식 -> 후위 표기 수식
//void infix_to_postfi(char exp[])
//{
//	int i = 0;
//	char ch, top_op;
//	int len = strlen(exp);
//	
//	StackType s;
//	
//	init(&s);
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		switch (ch)
//		{
//		case '+':case '-': case '*': case'/':	//연산자
//			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))	//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
//			{
//				printf("%c", pop(&s));
//
//			}
//			push(&s, ch);
//			break;
//
//		case '(':
//			push(&s, ch);
//			break;
//		case ')':
//			top_op = pop(&s);
//			//왼쪽 괄호를 만날 때까지 출력
//			while (top_op != '(')
//			{
//				printf("%c", top_op);
//				top_op = pop(&s);
//			}
//			break;
//		default:
//			printf("%c", ch);
//			break;
//		}
//	}
//	while (!is_empty(&s))	printf("%c", pop(&s));	//스택에 저장된 연산자들 출력
//}
////주 함수
//int main(void)
//{
//	char ch[50] = "(2+3)*4+9";
//	infix_to_postfi(ch);
//
//	return 0;
//}