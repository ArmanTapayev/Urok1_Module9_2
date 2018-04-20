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
	printf("������ �������� 10 ���������.\n");
	printf("��� ���������� �������� 0.\n");
	int n;
	do
	{

		printf("������� ����� ��������: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*	���� ���������		������
			���������o			���������� �����, ���������� �������� ������ ����� �� ������,
			����				� ���������� ��� �������� � ���.
			��� ������������
			�������������
			*/
		
			int count = 10;
			printf("--- ���������� � ������ ---\n");
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
			printf("���������� � ���������, ������� ������ ����� �� ������.\n");
			printInfoProduct(&pr[maxInd], 1);

			system("pause");
			system("cls");
		}break;

		case 2:
		{
			/*	���� ���������				������
			�������� 					���������� ���������� �����������
			�������						� ������� ����������� ������ ������
			����� ����������� ������	10 ����� � ���������� ��� �������� � ���
			������� DVD ROM
			���������
			*/

			int count = 10, k = 0;
			printf("���������� � �����������:\n");
			Computer *cmp = createComp(&count);
			printf("\n���������� c RAM ������ 10 �����:\n");
			for (int i = 0; i < count; i++)
			{
				if (cmp[i].RAM > 10)
				{
					printInfoComp(&cmp[i], 1);
					k++;
				}
			}
			printf("����������: %d\n", k);

			system("pause");
			system("cls");
		}break;

		case 3:
		{
			/*	���� ���������				������
			������						���������� ���������� ��������� ������ 19-�� ���,
			��� ��������				� ���������� ��� �������� � ���.
			������ �� ������
			������ �� ����������
			������ �� �����������
			*/

			int count = 10, k = 0;
			printf("���������� � ���������:\n");
			Student *cmp = createStudent(&count);
			printf("�������� ������ 19-�� ���:\n");
			for (int i = 0; i < count; i++)
			{
				if ((2018 - cmp[i].bdt.year) > 19)
				{
					printInfoStd(&cmp[i], 1);
					printf("�������: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("����������: %d\n", k);
			system("pause");
			system("cls");
		}break;

		case 4:
		{
			/*	���� ���������		������
			�������				���������� ���������� ���������� ������ 60-�� ���,
			��� ��������		� ���������� ��� �������� � ���.
			���������
			��������
			�����������
			*/
			int count = 10, k = 0;
			printf(" --- ���������� �� ��������� --- \n");
			employee *cmp = createFile(&count);

			printf("��������� ������ 60-�� ���:\n");
			for (int i = 0; i < count; i++)
			{
				if ((2018 - cmp[i].bdt.year) > 60)
				{
					printInfo(&cmp[i], 1);
					printf("�������: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("����������: %d\n", k);

			system("pause");
			system("cls");
		}break;

		case 5:
		{
			/*	���� ���������		������
			���������			���������� ����� ������� �����
			����				�� ������ � ���������� ��� �������� � ���
			��� ������������
			�������������
			*/

			int count = 10;

			printf("--- ���������� � ������ ---\n");
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
			printf("���������� � ����� ������� ������ �� ������.\n");
			printInfoProduct(&pr[maxInd], 1);

			system("pause");
			system("cls");
		}break;

		case 6:
		{
			/*	���� ���������				������
			��������					��������� ������� ��������� ���� �����������
			�������						� ���������� ������������ ����������� � �� ������� ���������.
			����� ����������� ������
			������� DVD ROM
			���������
			*/

			int count = 10, sum = 0;
			printf("���������� � �����������:\n");
			Computer *cmp = createComp(&count);
			for (int i = 0; i < count; i++)
				sum += cmp[i].price;

			printf("������� ��������� �����������: %0.2f\n", (float)sum / count);

			system("pause");
			system("cls");
		}break;

		case 7:
		{
			/*	���� ���������				������
			�������						���������� ���������� ���������� -
			��� ��������				��������� � ���������� ��� �������� � ���.
			���������
			��������
			�����������
			*/

			int count = 10, k = 0;
			printf(" --- ���������� �� ��������� --- \n");
			employee *cmp = createFile(&count);

			printf("��������� - ��������:\n");
			for (int i = 0; i < count; i++)
			{
				if (strcmp(cmp[i].ocp.ocup, "�������") == 0)
				{
					printInfo(&cmp[i], 1);
					printf("�������: %d\n", (2018 - cmp[i].bdt.year));
					k++;
				}
			}
			printf("����������: %d\n", k);
			system("pause");
			system("cls");
		}break;

		case 8:
		{
			/*	���� ���������				������
				�������						��������� ������� ���� ������ ��������� �� ������ � ���������� �������,
				������						��� �������� � ������ �� ����������� ���� ���������
				��� ��������
				������ �� ������
				������ �� ����������
				������ �� �����������
			*/

			int count = 10, sum=0;
			printf(" --- ���������� � ��������� --- \n");
			Student *cmp = createStudent(&count);
			//printf("������� ���� ������ ��������� �� ������:\n");
			for (int i = 0; i < count; i++)
			{
					sum += cmp[i].sub[0].rate;				
					printf("�������: %s, ���� ��������: %d.%d.%d, ������ �� �����������: %d\n",
					cmp[i].name, cmp[i].bdt.day, cmp[i].bdt.month, cmp[i].bdt.year, cmp[i].sub[2].rate);
			}
			printf("������� ���� ������ �� ������: %0.2f\n\n", (float)sum / count);
			system("pause");
			system("cls");
		}break;

		case 9:
		{
			/*	���� ���������				������
				����������					���������� ���������� �������, ������������� ����� ��� ��� ���� �����,
				����						� ���������� ��� �������� � ���
				��� ������������
				�������������
			*/

			int count = 10, k=0;
			Product *pr = createProduct(&count);

			printf("���������� � �������, ������������� ����� ��� ��� ���� �����.\n");
			for (int i = 0; i < count; i++)
			{
				if ((2018 - pr[i].year) > 2)
				{
					printInfoProduct(&pr[i], 1);
					k++;
				}					
			}
					
			printf("����������: %d\n", k);

			system("pause");
			system("cls");
		}break;

		case 10:
		{
			/*	���� ���������				������
			��������					���������� ����������, ������� ����� DVD ROM,
			�������						� ���������� ��� �������� � ���.
			����� ����������� ������
			������� DVD ROM
			���������
			*/

			int count = 10;
			printf("���������� � �����������:\n");
			Computer *cmp = createComp(&count);
			printf("����������, ������� ����� DVD ROM:\n");
			for (int i = 0; i < count; i++)
			{ 
				if(cmp[i].DVD>0)
					printInfoComp(&cmp[i], 1);
			}

			system("pause");
			system("cls");
		}break;
		}
	} while (n != 0);
}