#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#define tam 10

static GLfloat Xrot, Xstep;
static GLfloat Yrot, Ystep;
static GLfloat Zrot, Zstep;
static GLfloat Step = 5.0;
static GLfloat Scale = 1.0;
static GLuint Object;

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
static GLuint
make_object(void)
{
  GLuint list;

  list = glGenLists(1);

  glNewList(list, GL_COMPILE);

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

//  glBegin(GL_LINE_LOOP);
//  glVertex3f(1.0, 0.5, -0.4);
//  glVertex3f(1.0, -0.5, -0.4);
//  glVertex3f(-1.0, -0.5, -0.4);
//  glVertex3f(-1.0, 0.5, -0.4);
//  glEnd();
//
//  glBegin(GL_LINE_LOOP);
//  glVertex3f(1.0, 0.5, 0.4);
//  glVertex3f(1.0, -0.5, 0.4);
//  glVertex3f(-1.0, -0.5, 0.4);
//  glVertex3f(-1.0, 0.5, 0.4);
//  glEnd();

/*
  glBegin(GL_LINES);
  glVertex3f(1.0, 0.5, -0.4);
  glVertex3f(1.0, 0.5, 0.4);
  glVertex3f(1.0, -0.5, -0.4);
  glVertex3f(1.0, -0.5, 0.4);
  glVertex3f(-1.0, -0.5, -0.4);
  glVertex3f(-1.0, -0.5, 0.4);
  glVertex3f(-1.0, 0.5, -0.4);
  glVertex3f(-1.0, 0.5, 0.4);
  glEnd();
*/
  glEndList();

  return list;
}

static void
reshape(int width, int height)
{
  glViewport(0, 0, (GLint) width, (GLint) height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 5.0, 15.0);
  glMatrixMode(GL_MODELVIEW);
}

/* ARGSUSED1 */
static void
key(unsigned char k, int x, int y)
{
  switch (k) {
  case 27:
    exit(0);
  }
}

static void
draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();

  glTranslatef(0.0, 0.0, -10.0);
  glScalef(Scale, Scale, Scale);
  if (Xstep) {
    glRotatef(Xrot, 1.0, 0.0, 0.0);
  } else if (Ystep) {
    glRotatef(Yrot, 0.0, 1.0, 0.0);
  } else {
    glRotatef(Zrot, 0.0, 0.0, 1.0);
  }

  glCallList(Object);

  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}
void update(int i,int j){
    float aux1=cores[i][0],aux2=cores[i][1],aux3=cores[i][2];
    cores[i][0]=cores[j][0];cores[i][1]=cores[j][1];cores[i][2]=cores[j][2];
    cores[j][0]=aux1;cores[j][1]=aux2;cores[j][2]=aux3;
//    drawRects();

//  display();
//  glutPostRedisplay();
//    _sleep(10);
}

void bubblesort(){
    int i,j,aux;
    for(i=0;i<tam;i++){
        for(j=i;j<tam;j++){
            if(vet[i]<vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                update(i,j);
//                printf("%d %d\n",i,j);
            }
        }
    }
}

static void
idle(void)
{
//  Xrot += Xstep;
//  Yrot += Ystep;
//  Zrot += Zstep;
//
//  if (Xrot >= 360.0) {
//    Xrot = Xstep = 0.0;
//    Ystep = Step;
//  } else if (Yrot >= 360.0) {
//    Yrot = Ystep = 0.0;
//    Zstep = Step;
//  } else if (Zrot >= 360.0) {
//    Zrot = Zstep = 0.0;
//    Xstep = Step;
//  }
bubblesort();
  glutPostRedisplay();
  _sleep(10);
}

void
visible(int vis)
{
  if (vis == GLUT_VISIBLE)
    glutIdleFunc(idle);
  else
    glutIdleFunc(NULL);
}

main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (250,250);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Spin");
  Object = make_object();
  glCullFace(GL_BACK);
  glDisable(GL_DITHER);
  glShadeModel(GL_FLAT);

  glColor3f(1.0, 1.0, 1.0);

  Xrot = Yrot = Zrot = 0.0;
  Xstep = Step;
  Ystep = Zstep = 0.0;

  glutReshapeFunc(reshape);
  glutKeyboardFunc(key);
  glutVisibilityFunc(visible);
  glutDisplayFunc(draw);

  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
