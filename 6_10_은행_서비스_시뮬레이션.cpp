//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//#define TRUE 1
//#define FALSE 0
//#define MAX_QUEUE_SIZE 100
//
//typedef struct
//{
//	int id;
//	int arrival_time;
//	int service_time;
//}element;
//
//typedef struct QueueType
//{
//	element queue[MAX_QUEUE_SIZE];
//	int front, rear;
//}queuetype;
//
//queuetype queue;
//
//void error()
//{
//	printf("메모리 참조 에러");
//	exit(1);
//}
//
////초기화 함수
//void init(queuetype *q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
//
////공백 상태 검출 함수
//int is_empty(queuetype *q)
//{
//	return (q->front == q->rear);
//}
//
////포화 상태 검출 함수
//int is_full(queuetype *q)
//{
//	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//
//// 삽입 함수
//void enqueue(QueueType *q, element item)
//{
//	if (is_full(q))
//	{
//		error();
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->queue[q->rear] = item;
//
//}
//
////삭제 함수
//element dequeue(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//
//	return q->queue[q->front];
//}
//
////피크 함수
//element peek(QueueType *q)
//{
//	if (is_empty(q))
//		error();
//	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//
////0에서 1 사이의 실수 난수 생성 함수
//double random()
//{
//	return rand() / (double)RAND_MAX;
//}
//
////시뮬레이션에 필요한 여러가지 상태 변수
//int duration = 10;				//시뮬레이션 시간
//double arrival_prob = 0.7;		//하나의 시간 단위에 도착하는 평균 고객의 수
//int max_serv_time = 5;			//하나의 고객에 대한 최대 서비스 시간
//int clock;
//
////시뮬레이션의 결과
//int customers;					//전체 고객의 수
//int served_customers;			//서비스 받은 고객의 수
//int waited_time;				//고객들이 기다린 시간
//
////랜덤 숫자를 생성하여 고객이 도착했는지 도착하지 않았는지를 판단한다.
//int is_customer_arrived()
//{
//	if (random() < arrival_prob)
//		return TRUE;
//	else return FALSE;
//}
//
////새로 도착한 고객을 큐에 삽입
//void insert_customer(int arrival_time)
//{
//	element customer;
//
//	customer.id = customers++;
//	customer.arrival_time = arrival_time;
//	customer.service_time = (int)(max_serv_time * random()) + 1;
//
//	enqueue(&queue, customer);
//
//	printf("고객 %d이 %d분에 들어옵니다. 서비스 시간은 %d분입니다.\n", customer.id, customer.arrival_time, customer.service_time);
//}
//
////큐에서 기다리는 고객을 꺼내어 고객의 서비스 시간을 반환한다.
//int remove_customer()
//{
//	element customer;
//	int service_time = 0;
//
//	if (is_empty(&queue)) return 0;
//	
//	customer = dequeue(&queue);
//	service_time = customer.service_time - 1;
//	served_customers++;
//	waited_time += clock - customer.arrival_time;
//
//	printf("고객 %이 %d분에 서비스를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
//
//	return service_time;
//}
//
////통계치를 출력한다.
//void print_start()
//{
//	printf("서비스받은 고객수 = %d\n", served_customers);
//	printf("전체 대기 시간 = %d분\n", waited_time);
//	printf("1인당 평균 대기 시간 = %f분\n", (double)waited_time / served_customers);
//	printf("아직 대기중인 고개수 = %d\n", customers - served_customers);
//}
//
////시뮬레이션 프로그램
//int main(void)
//{
//	int service_time = 0;
//
//	clock = 0;
//	while (clock < duration)
//	{
//		clock++;
//		printf("현재시각 = %d\n", clock);
//
//		if (is_customer_arrived())
//		{
//			insert_customer(clock);
//		}
//		if (service_time > 0)
//			service_time--;
//		else
//		{
//			service_time = remove_customer();
//		}
//	}
//	print_start();
//
//	return 0;
//}
//
//
