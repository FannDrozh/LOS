#include <stdio.h>
struct MyStruct
{
	int a;
	struct MyStruct* next;
};
typedef struct MyStruct s;
void Delete(s* los, size_t i);
void Swap(s* los, size_t i, size_t m);
s* create(int);
void show(s*);
void delete(s*);
s* insert(s*, s, int);
int main(void)
{	
	system("chcp 1251>nul");
	printf("������� ����������� ������: ");
	int n = 0 ;
	scanf_s("%d", &n);
	printf("������ ��������� ��� �����: ");
	s* list1 = create(n);
	show(list1);
	printf("������� ����� ��������, ����� �������� ������ �������� �����: ");
	int number = 0;
	scanf_s("%d", &number);
	printf("������� �����, ������� ����� ���������: ");
	int p = 0;
	scanf_s("%d", &p);
	s item = { p,NULL };
	list1 = insert(list1, item, number);
	show(list1);
	printf("������� ������� ���������, ������� ������ �������� �������: ");
	printf("\n");
	int one = 0;
	scanf_s("%d", &one);
	int two = 0;
	scanf_s("%d", &two);
	Swap(list1, one-1, two-1);
	show(list1);
	printf("������� ����� ��������, ������� �� ������ �������: ");
	int del = 0;
	scanf_s("%d", &del);
	Delete(list1, del-1);
	show(list1);
	delete(list1);
	return 0;
}
void Delete(s* los, size_t i) {
	for (size_t n = 0; n < i - 1; n++)
	{
		los = los->next;
	}
	s* copy = los;
	los = los->next;
	copy->next = los->next;
	free(los);
}
s* create(int n)
{
	s* start = malloc(sizeof(s));//������� ������ �������
	start->a = 1;
	start->next = NULL;
	s* p, * q;//��������� �� ���������� � ��������� ������� ���
	p = start;
	for (size_t i = 0; i < n - 1; i++)//������� � ����� ��� ��������� ��������
	{
		q = malloc(sizeof(s));//�������������� ��������� �������
		q->a = p->a + 1;
		p->next = q;//���� � ���������� ����������� �������� �������� ����� ����������
		p = q;//���������� ������� ���� ���������
	}
	p->next = NULL;
	return start;
}
void show(s* list)
{
	while (list)//���� list != NULL
	{
		printf("%d ", list->a);
		list = list->next;
	}
	printf("\n");
}
void Swap(s* los, size_t i, size_t m) {
	s* min = los;
	s* max = los;
	s* _max = los;
	for (size_t n = 0; n < i-1; n++)
	{
		min = min->next;
	}
	s* l1 = min->next;
	for (size_t n = 0; n < m - 1; n++)
	{
		_max = _max->next;
	}
	s* l2 = _max->next;
	max = l2->next;
	min->next = l2;
	_max->next = l1;
	l2->next = l1->next;
	l1->next = max;

}
void delete(s* list)
{
	s* p = list;
	while (p)
	{
		p = list->next;//��������� ���������
		free(list);//������� ����������
		list = p;//��������� ���� ������
	}
	printf("�������� ����������� ������ ������...");
}
s* insert(s* list, s item, int k)
{
	s* el = malloc(sizeof(s));//�������� ������ ��� ����� ������� ������
	el->a = item.a;//�������� � ���� ���� �� ���������
	if (k == 1)//���� �� ������ ������ �������
	{
		el->next = list;
		list = el;
	}
	else // ���� ������ �� ������ �������
	{
		s* start = list;//���������� ������ ������
		for (size_t i = 0; i < k - 1; i++)
		{
			list = list->next;//�������� �� k �������
			if (!(list->next))
			{
				printf("�� ����� ������, ����������� ������� ������. �� ������� ������� � ����� ������\n");
				break;
			}
		}
		void* temp = list->next;//����� ��������
		list->next = el;
		el->next = temp;
		list = start;//���������� ������ �� �����
	}
	return list;
}
