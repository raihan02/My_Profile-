
#include<stdio.h>

struct A
{
    char name[10];
    double credit, gpa, total;
};

void main()
{
    struct A a[100];
    int i,n;
    double Tcr=0, Tcg=0;
    printf("How many subjects in this semester?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter Subject code or Subject name:\n");
        scanf("%s", &a[i].name);
        printf("Enter credit hours for %s:\n", a[i].name);
        scanf("%lf", &a[i].credit);
        printf("Enter GPA of %s:\n", a[i].name);
        scanf("%lf", &a[i].gpa);
        a[i].total= a[i].credit * a[i].gpa;

    }
    int j;
    printf("SL\tSubject\t\tCredits\tGPA\tTotal\n");
    for(j=0; j<i; j++)
    {
        Tcr+=a[j].credit;
        Tcg+=a[j].total;
        printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n",j+1, a[j].name, a[j].credit,a[j].gpa, a[j].total);
    }
    printf("\n\nCGPA for this semester = %.4lf\n", Tcg/Tcr);

}
