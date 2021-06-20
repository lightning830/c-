#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct robot{
    char name[100];
    double x;
    double y;
};

double calc(double x, double theta2){
    double l = 0, r = 360;
    while(abs(cos(l*M_PI/180)+cos(l*M_PI + theta2)-x) < 0.000001){
        double c = (l+r)/2;
        if()
    }
    x = L1*cos(theta1) + L2*cos(theta1+theta2)
    x*x + y*y = L1*L1 + L2*L2 + 2*L1*L2*cos(theta2)

}

int main(){
    FILE *fp, *fp2;
    char *f = "sample.csv";
    char *f2 = "print.csv";
    fp = fopen(f, "r");
    fp2 = fopen(f2, "w");
    if(fp == NULL){
        printf("cannot open fp\n");
        return -1;
    }
    if(fp == NULL){
        printf("cannot open fp2\n");
        return -1;
    }
    struct robot robots[100];
    char s[100];
    double x, y, l1, l2;
    scanf("%lf%lf", &l1, &l2);
    
    int n = 0;
    while(fscanf(fp, "%[^,],%lf,%lf\n", s, &x, &y) != EOF) {
        struct robot r;
        strcpy(r.name, s);
        r.x = x;
        r.y = y;
        robots[n] = r;
        n++;

	}

    for(int i = 0; i < n; i++){
        printf("%s, x = %lf, y = %lf\n", robots[i].name, robots[i].x, robots[i].y);
        double xx = robots[i].x, yy = robots[i].y;
        double c = (xx*xx + yy*yy - l1*l1 - l2*l2) / (2*l1*l2);
        if(c >= -1 && c <= 1){
            printf("    can reach\n");
            double theta2 = acos(c)*180/M_PI;
            printf("    theta2 = %lf\n", theta2);
            fprintf(fp2, "%s,theta1,%lf\n", robots[i].name, theta2);
        } 
        else{
            printf("    cannot\n");
            fprintf(fp2, "%s\n", robots[i].name);
        } 
    }

    fclose(fp);

    return 0;
}