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
	printf("Введите размерность списка: ");
	int n = 0 ;
	scanf_s("%d", &n);
	printf("Список получился вот таким: ");
	s* list1 = create(n);
	show(list1);
	printf("Введите номер элемента, после которого хотите вставить число: ");
	int number = 0;
	scanf_s("%d", &number);
	printf("Введите число, которое будет вставлено: ");
	int p = 0;
	scanf_s("%d", &p);
	s item = { p,NULL };
	list1 = insert(list1, item, number);
	show(list1);
	printf("Введите индексы элементов, которые хотите поменять местами: ");
	printf("\n");
	int one = 0;
	scanf_s("%d", &one);
	int two = 0;
	scanf_s("%d", &two);
	Swap(list1, one-1, two-1);
	show(list1);
	printf("Введите номер элемента, который вы хотите удалить: ");
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
	s* start = malloc(sizeof(s));//создаем первый элемент
	start->a = 1;
	start->next = NULL;
	s* p, * q;//указатели на предыдущий и следующий элемент ЛОС
	p = start;
	for (size_t i = 0; i < n - 1; i++)//создаем в цикле все остальные элементы
	{
		q = malloc(sizeof(s));//инициализируем следующий элемент
		q->a = p->a + 1;
		p->next = q;//поле с указателем предыдущего элемента содержит адрес следующего
		p = q;//предыдущий элемент стал следующим
	}
	p->next = NULL;
	return start;
}
void show(s* list)
{
	while (list)//пока list != NULL
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
		p = list->next;//запомнили следующий
		free(list);//удалили предыдущий
		list = p;//следующий стал первым
	}
	printf("Линейный односвязный список удален...");
}
s* insert(s* list, s item, int k)
{
	s* el = malloc(sizeof(s));//выделяем память под новый элемент списка
	el->a = item.a;//помещаем в него поле из структуры
	if (k == 1)//если мы меняем первый элемент
	{
		el->next = list;
		list = el;
	}
	else // если меняем не первый элемент
	{
		s* start = list;//запоминаем голову списка
		for (size_t i = 0; i < k - 1; i++)
		{
			list = list->next;//сдвигаем на k позиций
			if (!(list->next))
			{
				printf("вы ввели индекс, превышающий размеры списка. МЫ вставим элемент в конец списка\n");
				break;
			}
		}
		void* temp = list->next;//обмен адресами
		list->next = el;
		el->next = temp;
		list = start;//возвращаем голову на место
	}
	return list;
}
