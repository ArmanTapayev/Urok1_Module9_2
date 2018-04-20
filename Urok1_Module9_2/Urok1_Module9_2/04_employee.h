struct education
{
	char grade[10];
};

struct ocupation
{
	char ocup[30];
};

struct employee
{
	char lastName[10];
	birthDate bdt;
	ocupation ocp;
	int salary;
	education ed[10];
};

