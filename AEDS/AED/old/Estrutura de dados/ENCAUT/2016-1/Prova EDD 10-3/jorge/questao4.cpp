#include<stdio.h>
#include<conio.h>
int divisao(int dividendo,int divisor, int *resto){
	int d;
	int r;
	d=(divisor/dividendo);
	return d;
	if(d%==0){
		return d;
		return r=0;
	}
 else{
 	resto=d%;
 	r=resto;
 	return d;
 	return r;
 }
}

int main(){

int r, d;
 d=divisao(5,2,&r);
printf(" resultado: %d resto:%d",d,r);
getch();
return 0;
}
