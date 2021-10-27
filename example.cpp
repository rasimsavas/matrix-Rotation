#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265359

float sonuc[4][3]={{3,1,1},{8,1,1},{8,4,1},{3,4,1}};        /*  Islemlerin yapildigi matris dizisi  */
float gecici[4][3];
const float ortho=10;                                       /*  10'un Katlarý Girecek Þekilde Deðiþtiriniz. */
const float cozunurluk=600;                                 /*  Pencere Boyutu Ayarlama */

float AciRadyan(float aci){
    return aci*PI/180;
}

void saatYonDon(float matrix[4][3],float a){
    float aci=a;
    double dondur[3][3] = {{cos(a),-sin(a),0},{sin(a),cos(a),0},{0,0,1}};
    float matrisTop=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matrisTop = matrisTop + matrix[i][k]*dondur[k][j];
            }
            gecici[i][j] = matrisTop;
            matrisTop = 0;
        }
    }
    for(int i=0;i<4;i++){
        sonuc[i][0] = gecici[i][0];
        sonuc[i][1] = gecici[i][1];
        sonuc[i][2] = gecici[i][2];
        printf("%f\t %f\t %f\n",sonuc[i][0],sonuc[i][1],sonuc[i][2]);
    }
}

void saatTersDon(float matrix[4][3],float a){
    float aci=a;
    double dondur[3][3] = {{cos(a),sin(a),0},{-sin(a),cos(a),0},{0,0,1}};
    float matrisTop=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matrisTop = matrisTop + matrix[i][k]*dondur[k][j];
            }
            gecici[i][j] = matrisTop;
            matrisTop = 0;
        }
    }
    for(int i=0;i<4;i++){
        sonuc[i][0] = gecici[i][0];
        sonuc[i][1] = gecici[i][1];
        sonuc[i][2] = gecici[i][2];
        printf("%f\t %f\t %f\n",sonuc[i][0],sonuc[i][1],sonuc[i][2]);
    }
}

void oteleme(float matrix[4][3],float a, float b){
    float otele[3][3]={{1,0,0},{0,1,0},{a,b,1}};
    float matrisTop=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matrisTop = matrisTop + matrix[i][k]*otele[k][j];
            }
            gecici[i][j] = matrisTop;
            matrisTop = 0;
        }
    }
    for(int i=0;i<4;i++){
        sonuc[i][0] = gecici[i][0];
        sonuc[i][1] = gecici[i][1];
        sonuc[i][2] = gecici[i][2];
        printf("%f\t %f\t %f\n",sonuc[i][0],sonuc[i][1],sonuc[i][2]);
    }
}

void olcekleme(float matrix[4][3],float a, float b){
    float olcekle[3][3]={{a,0,0},{0,b,0},{0,0,1}};
    float matrisTop=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matrisTop = matrisTop + matrix[i][k]*olcekle[k][j];
            }
            gecici[i][j] = matrisTop;
            matrisTop = 0;
        }
    }
    for(int i=0;i<4;i++){
        sonuc[i][0] = gecici[i][0];
        sonuc[i][1] = gecici[i][1];
        sonuc[i][2] = gecici[i][2];
        printf("%f\t %f\t %f\n",sonuc[i][0],sonuc[i][1],sonuc[i][2]);
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);                           /*  Ekranýn Temizlenip iþlemlerin gösterilmesi  */

    printf("---1.Adim---\n");
    oteleme(sonuc,0,-1);
    printf("---2.Adim---\n");
    saatYonDon(sonuc,1.249046);
    printf("---3.Adim---\n");
    olcekleme(sonuc,1,-1);
    printf("---4.Adim---\n");
    saatTersDon(sonuc,1.249046);
    printf("---5.Adim---\n");
    oteleme(sonuc,0,1);

    glColor3f(0,1,0);
    glBegin(GL_LINES);                                      /*  Yansitilacak olan dogrunun cizilmesi    */
        glVertex2f(((-3*ortho)+1),((-3*ortho)+1));
        glVertex2f(-((-3*ortho)+1),((-3*ortho)+1));
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_QUADS);                                      /*  Ucgenin hesaplanmis son durumunun cizilmesi */
        glVertex3f(sonuc[0][0],sonuc[0][1],sonuc[0][2]);
        glVertex3f(sonuc[1][0],sonuc[1][1],sonuc[1][2]);
        glVertex3f(sonuc[2][0],sonuc[2][1],sonuc[2][2]);
        glVertex3f(sonuc[3][0],sonuc[3][1],sonuc[3][2]);
    glEnd();

    glFlush();
}
void key(unsigned char key, int x, int y){      /*  Klavye Girisini saglayan fonksiyon  */
  if( key == 'q' ) exit(0);                     /*  Q tusuna basildiginda pencereyi kapatan durum   */
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);                      /*  OpenGL Baslatma */

    glutInitWindowSize(cozunurluk,cozunurluk);  /*  Pencere Boyutunu Ayarlama   */
    glutInitWindowPosition(32,32);              /*  Pencere Konumunu Ayarlama   */
    glutCreateWindow("BG1_1160505047_Rasim");   /*  Pencere Ismi Ayarlama   */

    glClearColor(0.0,0.0,0.0,0.0);              /*  Pencere Arkaplaný Ayarlama  */
    gluOrtho2D(-ortho,ortho,-ortho,ortho);      /*  Pencerede Gorulen Alani Ayarlama    */
    glutDisplayFunc(display);                   /*  Pencerede Gozuken Islemleri Gosterme    */
    glutKeyboardFunc(key);                      /*  Klavye girisi saglanmasi icin gerekli fonksiyon */

    glutMainLoop();                             /*  Devamli Bir sekilde cizilenlerin gorulmesini saglamak   */

    return 0;
}
