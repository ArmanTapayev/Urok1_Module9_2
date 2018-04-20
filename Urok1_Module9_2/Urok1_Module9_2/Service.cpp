#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include "01_product.h"
#include "02_computer.h"
#include "03_student.h"
#include"04_employee.h"


void createName(char * name, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + len) = '\0';
}

void generateDate(birthDate *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1950 + rand() % 30;
}

void generateDateSt(birthDate *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1997 + rand() % 5;
}

/* variant 1 */
void generateProduct(Article *pr, int id)
{
	//int id = 1 + rand() % 20;
	char srnd[3];
	_itoa(id, srnd, 10);
	strcpy(pr->articles, "Продукция ");
	strcat(pr->articles, srnd);
}

void printInfoProduct(Product  * pr, int len)
{
	//printf("--- Информация о товаре ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. %12s: id %d, Количество %d, Цена %d, Год %d, Производитель %s\n",
			i + 1,

			pr[i].art.articles,
			pr[i].id,
			pr[i].quantity,
			pr[i].price,
			pr[i].year,
			pr[i].maker);
	}
}

Product *createProduct(int *count)
{
	Product *pr = (Product*)calloc(*count, sizeof(Product));
	if (pr != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			pr[i].id = 1 + rand() % 20;
			generateProduct(&pr[i].art, pr[i].id);
			pr[i].quantity = 100 + rand() % 1000;
			pr[i].price = 1000 + rand() % 5000;
			pr[i].year = 2014+ rand() % 4;
			createName(pr[i].maker, 10);
		}
		printInfoProduct(pr, *count);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return pr;
}

/* variant 2 */
void generateComp(Maker *cmp)
{
	int rnd = 1 + rand() % 20;
	char srnd[3];
	_itoa(rnd, srnd, 10);
	strcpy(cmp->mkr, "Компьютер #");
	strcat(cmp->mkr, srnd);
}

void printInfoComp(Computer  * cmp, int len)
{
	//printf("--- Информация о компьютере ---\n");
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. %12s: Частота %d, RAM %d, DVD ROM %d, Стоимость %d\n",
			i + 1,
			cmp[i].cmpMkr.mkr,
			cmp[i].frequency,
			cmp[i].RAM,
			cmp[i].DVD,
			cmp[i].price);
	}
}

Computer * createComp(int *count)
{
	Computer *cmp = (Computer*)calloc(*count, sizeof(Computer));
	if (cmp != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			generateComp(&cmp[i].cmpMkr);
			cmp[i].frequency = 1000000 + rand() % 2000000;
			cmp[i].RAM = 5 + rand() % 10;
			cmp[i].DVD = 0 + rand() % 2;
			cmp[i].price = 100000 + rand() % 500000;
		}
		printInfoComp(cmp, *count);
	}
	else
	{
		printf("Ощибка!");
		exit(1);
	}
	return cmp;
}

/* variant 3 */
void generateSubject(Subject *sub, int num)
{
	sub->rate = 2 + rand() % 5;

	switch (num)
	{
	case 0:
		strcpy(sub->nameSub, "Физика ");
		break;

	case 1:
		strcpy(sub->nameSub, "Математика ");
		break;

	case 2:
		strcpy(sub->nameSub, "Информатика ");
		break;
	}
}

void printInfoStd(Student * students, int len)
{
	//printf(" --- Информация по студенту --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d. Фамилия: %s, Группа %s, Год рождения: %d.%d.%d;\n",
			i + 1,
			students[i].name,
			students[i].groupe,
			students[i].bdt.day,
			students[i].bdt.month,
			students[i].bdt.year);
		for (int j = 0; j < 3; j++)
		{
			printf("-->%s\t%d\n",
				students[i].sub[j].nameSub,
				students[i].sub[j].rate);
		}
		printf("\n");
	}
}

Student * createStudent(int *count)
{
	Student *st = (Student*)malloc(*count * sizeof(Student));
	if (st != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(st[i].name, 8);
			createName(st[i].groupe, 3);
			generateDateSt(&st[i].bdt);
			for (int j = 0; j < 3; j++)
			{
				generateSubject(&st[i].sub[j], j);
			}

		}
		printInfoStd(st, *count);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return st;
}

/* variant 4 */

void generatePosition(ocupation * pos)
{
	int rnd = 1 + rand() % 3;
	switch (rnd)
	{
	case 1:
		strcpy(pos->ocup, "Инженер");
		break;

	case 2:
		strcpy(pos->ocup, "Техник");
		break;

	case 3:
		strcpy(pos->ocup, "Рабочий");
		break;
	}
}

void generateEducation(education *ed)
{
	int rnd = 1 + rand() % 3;
	switch (rnd)
	{
	case 1:
		strcpy(ed->grade, "Начальное");
		break;

	case 2:
		strcpy(ed->grade, "Среднее");
		break;

	case 3:
		strcpy(ed->grade, "Высшее");
		break;
	}
}

void printInfo(employee *file, int len)
{
	//printf(" --- Информация по работнику --- \n");
	for (int i = 0; i < len; i++)
	{
		printf("#%d Фамилия: %s; Год рождения: %d.%d.%d; Должность: %s; Зарплата: %d; Образование: %s\n",
			i + 1,
			file[i].lastName,
			file[i].bdt.day,
			file[i].bdt.month,
			file[i].bdt.year,
			file[i].ocp.ocup,
			file[i].salary,
			file[i].ed->grade);
	}
}

employee *createFile(int *count)
{
	employee *file = (employee*)calloc(*count, sizeof(employee));
	if (file != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(file[i].lastName, 10);
			generateDate(&file[i].bdt);
			generatePosition(&file[i].ocp);
			file[i].salary = 100000 + rand() % 500000;
			generateEducation(file[i].ed);
		}
		printInfo(file, 10);
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return file;
}