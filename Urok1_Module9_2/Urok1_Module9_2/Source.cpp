#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include"totalService.h"

/*_CRT_SECURE_NO_WARNINGS */

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	printf("Работа содержит 10 вариантов.\n");
	printf("Для завершения наберите 0.\n");
	int n;
	do
	{

		printf("Введите номер варианта: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*	Поля структуры		Задача
			Количествo			Определить товар, количество которого больше всего на складе,
			Цена				и напечатать все сведения о нем.
			Год изготовления
			Производитель
			*/
		
			int count = 10;
			Product *pr = createProduct(&count);
			int max = 0, maxInd;
			for (int i = 0; i < count; i++)
			{
				if (pr[i].quantity > max)
				{
					max = pr[i].quantity;
					maxInd = i;
				}
			}
			printf("Информация о продукции, которой больше всего на складе.\n");
			printInfoProduct(&pr[maxInd], 1);

			system("pause");
			system("cls");
		}break;

		case 2:
		{
			/*	Поля структуры				Задача
			Название 					Определить количество компьютеров
			Частота						с объемом оперативной памяти больше
			Объем оперативной памяти	10 Гбайт и напечатать все сведения о них
			Наличие DVD ROM
			Стоимость
			*/

			int count = 10, k = 0;
			printf("Информация о компьютерах:\n");
			Computer *cmp = createComp(&count);
			printf("\nКомпьютеры c RAM больше 10 Гбайт:\n");
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].RAM > 10)
				{
					printInfoComp(&cmp[i], 1);
					k++;
				}
			}
			printf("Количество: %d\n", k);

			system("pause");
			system("cls");
		}break;

		case 3:
		{
			/*	Поля структуры				Задача
			Группа						Определить количество студентов старше 19-ти лет,
			Год рождения				и напечатать все сведения о них.
			оценка по физике
			оценка по математике
			оценка по информатике
			*/

			int count = 10, k = 0;
			printf("Информация о студентах:\n");
			Student *cmp = createStudent(&count);
			printf("Студенты старше 19-ти лет:\n");
			for (int i = 0; i < count; i++)
			{
				if ((2018 - cmp[i].bdt.year) > 19)
				{
					printInfoStd(&cmp[i], 1);
					printf("Возраст: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("Количество: %d\n", k);
			system("pause");
			system("cls");
		}break;

		case 4:
		{
			/*	Поля структуры		Задача
			Фамилия				Определить количество работников старше 60-ти лет,
			Год рождения		и напечатать все сведения о них.
			Должность
			Зарплата
			Образование
			*/
			int count = 10, k = 0;
			printf(" --- Информация по работнику --- \n");
			employee *cmp = createFile(&count);

			printf("Работники старше 60-ти лет:\n");
			for (int i = 0; i < count; i++)
			{
				if ((2018 - cmp[i].bdt.year) > 60)
				{
					printInfo(&cmp[i], 1);
					printf("Возраст: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("Количество: %d\n", k);

			system("pause");
			system("cls");
		}break;

		case 5:
		{
			/*	Поля структуры		Задача
			Количеств			Определить самый дорогой товар
			Цена				на складе и напечатать все сведения о нем
			Год изготовления
			Производитель
			*/

			int count = 10;

			printf("--- Информация о товаре ---\n");
			Product *pr = createProduct(&count);

			int max = 0, maxInd;
			for (int i = 0; i < count; i++)
			{
				if (pr[i].price > max)
				{
					max = pr[i].price;
					maxInd = i;
				}
			}
			printf("Информация о самом дорогом товаре на складе.\n");
			printInfoProduct(&pr[maxInd], 1);

			system("pause");
			system("cls");
		}break;

		case 6:
		{
			/*	Поля структуры				Задача
			Название					Вычислить среднюю стоимость всех компьютеров
			Частота						и напечатать наименования компьютеров и их среднюю стоимость.
			Объем оперативной памяти
			Наличие DVD ROM
			Стоимость
			*/

			int count = 10, sum = 0;
			printf("Информация о компьютерах:\n");
			Computer *cmp = createComp(&count);
			for (int i = 0; i < count; i++)
				sum += cmp[i].price;

			printf("Средняя стоимость компьютеров: %0.2f\n", (float)sum / count);

			system("pause");
			system("cls");
		}break;

		case 7:
		{
			/*	Поля структуры				Задача
			Фамилия						Определить количество работников -
			Год рождения				инженеров и напечатать все сведения о них.
			Должность
			Зарплата
			Образование
			*/

			int count = 10, k = 0;
			printf(" --- Информация по работнику --- \n");
			employee *cmp = createFile(&count);

			printf("Работники - инженеры:\n");
			for (int i = 0; i < count; i++)
			{
				if (strcmp(cmp[i].ocp.ocup, "Инженер") == 0)
				{
					printInfo(&cmp[i], 1);
					printf("Возраст: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("Количество: %d\n", k);
			system("pause");
			system("cls");
		}break;

		case 8:
		{
			/*	Поля структуры				Задача
			Фамилия						Вычислить средний балл оценок студентов по физике и напечатать фамилии,
			Группа						год рождения и оценки по информатике всех студентов
			Год рождения
			оценка по физике
			оценка по математике
			оценка по информатике
			*/

			int count = 10;
			Student *cmp = createStudent(&count);

			system("pause");
			system("cls");
		}break;

		case 9:
		{
			/*	Поля структуры				Задача
			Количество					Определить количество товаров, произведенных более чем два года назад,
			Цена						и напечатать все сведения о них
			Год изготовления
			Производитель
			*/

			int count = 10;
			Product *pr = createProduct(&count);



			system("pause");
			system("cls");
		}break;

		case 10:
		{
			/*	Поля структуры				Задача
			Название					Определить компьютеры, которые имеют DVD ROM,
			Частота						и напечатать все сведения о них.
			Объем оперативной памяти
			Наличие DVD ROM
			Стоимость
			*/

			int count = 10;
			Computer *cmp = createComp(&count);

			system("pause");
			system("cls");
		}break;
		}
	} while (n != 0);
}