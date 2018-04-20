#include"01_product.h"
#include"02_computer.h"
#include"03_student.h"
#include"04_employee.h"

/*variant 1*/
void createName(char * name, int len);
void generateProduct(Article *pr, int id);
Product *createProduct(int *count);
void printInfoProduct(Product  * pr, int len);

/*variant 2*/
void generateComp(Maker *cmp);
void printInfoComp(Computer  * cmp, int len);
Computer * createComp(int *count);

/*variant 3*/
void generateSubject(Subject *sub, int num);
void printInfoStd(Student * students, int len);
Student * createStudent(int *count);
void generateDateSt(birthDate *date);

/*variant 4*/
void generatePosition(ocupation * pos);
void generateEducation(education *ed);
void printInfo(employee *file, int len);
employee *createFile(int *count);
