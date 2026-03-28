
# include <stdio.h>



 int main()
{

     TipoItem  x1,x2,x3; /* x1 é o disco menor*/

     TipoPilha *p1, *p2,*p3 ; /* p1 é a primeiro pino*/

     Desempilha(TipoPilha *p1,&x1);
     Empilha (TipoItem x1,&p3);
     Desempilha (TipoPilha *p1,&x2);
     Empilha ( TipoItem x2,&p2);
     Empilha ( TipoItem x1,&p2);
     Deempilha ( TipoPilha *p1,&x3);;
     Empilha ( TipoItem x3,&p3);
     Desempilha ( TipoItem *p2,&x1);;
     Empilha ( TipoItem x1,&p1);
     Desempilha ( TipoPilha *p2,&x2);
     Empilha ( TipoItem x2,&p3 );
     Desempilha ( tipoPilha *p1,&x1);
     Empilha ( TipoItem x1,&p3);









}
