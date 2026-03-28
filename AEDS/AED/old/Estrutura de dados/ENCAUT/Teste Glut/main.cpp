/*
 * depth.c
 *
 * Demonstra os diferentes modos de teste de profundidade
 * em OpenGL.
 *          Ting (21/09/08)
 */
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#define tam 10
int vet[] ={10,4,6,8,9,3,2,3,5,1,7};

float cores[10][3]={ {1.0, 0.0, 1.0},//magenta
                     {1.0, 1.0, 0.0},//amarelo
                     {0.0, 1.0, 1.0},//ciano
                     {1.0, 1.0, 1.0},//branco
                     {1.0, 0.0, 0.0},//vermelho
                     {0.0, 1.0, 0.0},//verde
                     {0.0, 0.0, 1.0},//azul
                     {0.5, 0.0, 0.0},//maroon
                     {0.5, 0.5, 0.0},//olive
                     {0.5, 0.0, 0.5},//purple
                     };

//void reshape(int w, int h);
//void init(void);
//void drawRects();
//void update(int i,int j);
//void bubblesort(int vet[]);
//void display(void);


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glDepthRange(0.0, 1.0);  /* The default z mapping */
   glDepthFunc(GL_LESS);
}

void drawRects()
{
   int i=0;
   float x1=0.5f, x2=5.0f, y1=0.5f, y2=1.0f;//posicao de cada vertice do retangulo inferior

   for(i=0;i<10;i++){
    glBegin(GL_QUADS);
    glColor3f(cores[i][0],cores[i][1],cores[i][2]);
    glVertex2d(x1, y1);
    glVertex2d(x1, y2);
    glVertex2d(x2, y2);
    glVertex2d(x2, y1);
    glEnd();

    y1+=0.7f;
    y2+=0.7f;
   }
}
void update(int i,int j){
    float aux1=cores[i][0],aux2=cores[i][1],aux3=cores[i][2];
    cores[i][0]=cores[j][0];cores[i][1]=cores[j][1];cores[i][2]=cores[j][2];
    cores[j][0]=aux1;cores[j][1]=aux2;cores[j][2]=aux3;
//    drawRects();

//  display();
//  glutPostRedisplay();
    _sleep(10);
}

void bubblesort(int b){
    int i,j,aux;
    for(i=0;i<tam;i++){
        for(j=i;j<tam;j++){
            if(vet[i]<vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                update(i,j);
                printf("%d %d\n",i,j);
            }
        }
    }
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   drawRects();
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 8.0, 0.0, 8.0, -0.5, 2.5);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27://faz o esc sair do programa
         exit(0);
         break;
   }
	glutPostRedisplay();
}

/*  Main Loop
 */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (200, 200);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Animacao bubbleSort");
   init();
   glutReshapeFunc(reshape);
//   glutVisibilityFunc(bubblesort);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(33, bubblesort, 1);
   glutMainLoop();
//   bubblesort(vet);
   return 0;
}
