struct birthDate
{
	int day;
	int month;
	int year;
};

struct Subject
{
	char nameSub[15];
	int rate;
};

struct Student
{
	char name[8];
	char groupe[3];
	Subject sub[3];
	birthDate bdt;
};

