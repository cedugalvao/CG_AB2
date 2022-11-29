#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include "stb_image.h"

float speedX, speedY, auxSpeedX, auxSpeedY, rotateBall = 0.0, ballAngle = 0.05;
int time1, time2 = 0, he = 3, xc = 2, yc = 0;
GLuint idTexturas[3];

bool dia = true;

using namespace std;
void field2(GLuint id)
{
    glBindTexture(GL_TEXTURE_2D, id);

    GLfloat color[] = { 0.0, 0.6, 0.2 };
    GLfloat pointsField[4][3] = {
        {-5.0, -5.5, -0.02},
        {-5.0, 5.5, -0.02},
        {5.0, 5.5, -0.02},
        {5.0, -5.5, -0.02},
    };

    glColor3fv(color);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(pointsField[0]);
    glTexCoord2f(1.0, 0.0);
    glVertex3fv(pointsField[1]);
    glTexCoord2f(1.0, 5.0);
    glVertex3fv(pointsField[2]);
    glTexCoord2f(0.0, 5.0);
    glVertex3fv(pointsField[3]);
    glEnd();
}


void field(GLuint id, GLuint id2)
{
    glBindTexture(GL_TEXTURE_2D, id2);

    GLfloat color[] = { 0.0, 0.6, 0.2 };
    GLfloat pointsField[4][3] = {
        {-2.0, -2.5, -0.01},
        {-2.0, 2.5, -0.01},
        {2.0, 2.5, -0.01},
        {2.0, -2.5, -0.01},
    };

    glColor3fv(color);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(pointsField[0]);
    glTexCoord2f(1.0, 0.0);
    glVertex3fv(pointsField[1]);
    glTexCoord2f(1.0, 1.0);
    glVertex3fv(pointsField[2]);
    glTexCoord2f(0.0, 1.0);
    glVertex3fv(pointsField[3]);
    glEnd();

    GLfloat color2[] = { 0.0, 0.55, 0.2 };
    GLfloat pointsField2[4][3] = {
        {-2.0, -2.5, 0},
        {-2.0, -1.5, 0},
        {2.0, -1.5, 0},
        {2.0, -2.5, 0},
    };
    glBindTexture (GL_TEXTURE_2D, id);
    glColor3fv(color2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(pointsField2[0]);
    glTexCoord2f(1.0, 0.0);
    glVertex3fv(pointsField2[1]);
    glTexCoord2f(1.0, 3.0);
    glVertex3fv(pointsField2[2]);
    glTexCoord2f(0.0, 3.0);
    glVertex3fv(pointsField2[3]);
    glEnd();

    GLfloat pointsField3[4][3] = {
        {-2.0, -0.5, 0},
        {-2.0, 0.5, 0},
        {2.0, 0.5, 0},
        {2.0, -0.5, 0},
    };
    glColor3fv(color2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(pointsField3[0]);
    glTexCoord2f(1.0, 0.0);
    glVertex3fv(pointsField3[1]);
    glTexCoord2f(1.0, 3.0);
    glVertex3fv(pointsField3[2]);
    glTexCoord2f(0.0, 3.0);
    glVertex3fv(pointsField3[3]);
    glEnd();

    GLfloat pointsField4[4][3] = {
        {-2.0, 2.5, 0},
        {-2.0, 1.5, 0},
        {2.0, 1.5, 0},
        {2.0, 2.5, 0},
    };
    glColor3fv(color2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3fv(pointsField4[0]);
    glTexCoord2f(1.0, 0.0);
    glVertex3fv(pointsField4[1]);
    glTexCoord2f(1.0, 3.0);
    glVertex3fv(pointsField4[2]);
    glTexCoord2f(0.0, 3.0);
    glVertex3fv(pointsField4[3]);
    glEnd();
}

void setView()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(95, w / h, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt
    (
        xc, yc, he,
        xc - 1, yc, 0,
        0, 0, 1
    );
}

void drawString(char* message) {
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(2.3, -0.5, 1);
    glScalef(0.001, 0.001, 0.001);
    glRotated(90, 0, 0, 1);
    for (int i = 0; i < strlen(message); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
    glPopMatrix();
}

void traves()
{
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.45, -2.1, 0.3);
    glScalef(0.2, 0.2, 3.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.4, -2.1, 0.3);
    glScalef(0.2, 0.2, 3.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.02, -2.1, 0.62);
    glScalef(4.5, 0.2, 0.2);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.45, 2.1, 0.3);
    glScalef(0.2, 0.2, 3.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.4, 2.1, 0.3);
    glScalef(0.2, 0.2, 3.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.02, 2.1, 0.62);
    glScalef(4.5, 0.2, 0.2);
    glutSolidCube(.2);
    glPopMatrix();
}

void drawPerson(float x, float y, float z){
    glPushMatrix();
    glColor3f(0.3, 0.5, 0.7);
    glTranslatef(x, y, z);
    glScalef(1.0, 1.0, 1.4);
    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.7, 0.7, 0.0);
    glTranslatef(x, y, z + 0.2);
    glScalef(0.10, 0.10, 0.10);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
}



void arquibancada_esquerdo(GLuint id)
{
    glPushMatrix();
    for (float qnt = 0; qnt < 0.25 * 3; qnt+=0.25)
    {
        if (qnt != 0)   glTranslatef(0, -0.25, 0);

        GLfloat color[] = { 0.0, 0.6, 0.2 };

        //baixo
        GLfloat pointsBleacher1[4][3] = {
            {-2.0, -3.25, -0.01},
            {-2.0, -3, -0.01},
            {2.0, -3, -0.01},
            {2.0, -3.25, -0.01},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher1[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher1[1]);
        glTexCoord2f(1.0, 1.0);
        glVertex3fv(pointsBleacher1[2]);
        glTexCoord2f(0.0, 1.0);
        glVertex3fv(pointsBleacher1[3]);
        glEnd();

        // cima
        GLfloat pointsBleacher2[4][3] = {
            {-2.0, -3.25, 0.1},
            {-2.0, -3, 0.1},
            {2.0, -3, 0.1},
            {2.0, -3.25, 0.1},
        };

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(pointsBleacher2[0][0], pointsBleacher2[0][1], pointsBleacher2[0][2] + qnt);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(pointsBleacher2[1][0], pointsBleacher2[1][1], pointsBleacher2[1][2] + qnt);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher2[2][0], pointsBleacher2[2][1], pointsBleacher2[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher2[3][0], pointsBleacher2[3][1], pointsBleacher2[3][2] + qnt);
        glEnd();

        // esquerda
        GLfloat pointsBleacher3[4][3] = {
            {2.0, -3.25, -0.01},
            {-2.0, -3.25, -0.01},
            {-2.0, -3.25, 0.1},
            {2.0, -3.25, 0.1},
        };


        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher3[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher3[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher3[2][0], pointsBleacher3[2][1], pointsBleacher3[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher3[3][0], pointsBleacher3[3][1], pointsBleacher3[3][2] + qnt);
        glEnd();

        // direita
        GLfloat pointsBleacher4[4][3] = {
            {2.0, -3, -0.01},
            {-2.0, -3, -0.01},
            {-2.0, -3, 0.1},
            {2.0, -3, 0.1},
        };


        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher4[0]);
        glTexCoord2f(0.0, 5.0);
        glVertex3fv(pointsBleacher4[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher4[2][0], pointsBleacher4[2][1], pointsBleacher4[2][2] + qnt);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(pointsBleacher4[3][0], pointsBleacher4[3][1], pointsBleacher4[3][2] + qnt);
        glEnd();

        // frente
        GLfloat pointsBleacher5[4][3] = {
            {-2.0, -3.25, -0.01},
            {-2.0, -3, -0.01},
            {-2.0, -3, 0.1},
            {-2.0, -3.25, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher5[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher5[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher5[2][0], pointsBleacher5[2][1], pointsBleacher5[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher5[3][0], pointsBleacher5[3][1], pointsBleacher5[3][2] + qnt);
        glEnd();

        // tras
        GLfloat pointsBleacher6[4][3] = {
            {2.0, -3.25, -0.01},
            {2.0, -3, -0.01},
            {2.0, -3, 0.1},
            {2.0, -3.25, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher6[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher6[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher6[2][0], pointsBleacher6[2][1], pointsBleacher6[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher6[3][0], pointsBleacher6[3][1], pointsBleacher6[3][2] + qnt);
        glEnd();
    }
    glPopMatrix();
}

void arquibancada_direito(GLuint id)
{
    glPushMatrix();
    for (float qnt = 0; qnt < 0.25 * 3; qnt += 0.25)
    {
        if (qnt != 0)   glTranslatef(0, 0.25, 0);

        GLfloat color[] = { 0.0, 0.6, 0.2 };

        //baixo
        GLfloat pointsBleacher1[4][3] = {
            {-2.0, 3.25, -0.01},
            {-2.0, 3, -0.01},
            {2.0, 3, -0.01},
            {2.0, 3.25, -0.01},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher1[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher1[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3fv(pointsBleacher1[2]);
        glTexCoord2f(0.0, 5.0);
        glVertex3fv(pointsBleacher1[3]);
        glEnd();

        // cima
        GLfloat pointsBleacher2[4][3] = {
            {-2.0, 3.25, 0.1},
            {-2.0, 3, 0.1},
            {2.0, 3, 0.1},
            {2.0, 3.25, 0.1},
        };

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(pointsBleacher2[0][0], pointsBleacher2[0][1], pointsBleacher2[0][2] + qnt);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(pointsBleacher2[1][0], pointsBleacher2[1][1], pointsBleacher2[1][2] + qnt);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher2[2][0], pointsBleacher2[2][1], pointsBleacher2[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher2[3][0], pointsBleacher2[3][1], pointsBleacher2[3][2] + qnt);
        glEnd();

        // esquerda
        GLfloat pointsBleacher3[4][3] = {
            {2.0, 3.25, -0.01},
            {-2.0, 3.25, -0.01},
            {-2.0, 3.25, 0.1},
            {2.0, 3.25, 0.1},
        };


        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher3[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher3[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher3[2][0], pointsBleacher3[2][1], pointsBleacher3[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher3[3][0], pointsBleacher3[3][1], pointsBleacher3[3][2] + qnt);
        glEnd();

        // direita
        GLfloat pointsBleacher4[4][3] = {
            {2.0, 3, -0.01},
            {-2.0, 3, -0.01},
            {-2.0, 3, 0.1},
            {2.0, 3, 0.1},
        };


        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher4[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher4[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher4[2][0], pointsBleacher4[2][1], pointsBleacher4[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher4[3][0], pointsBleacher4[3][1], pointsBleacher4[3][2] + qnt);
        glEnd();

        // frente
        GLfloat pointsBleacher5[4][3] = {
            {-2.0, 3.25, -0.01},
            {-2.0, 3, -0.01},
            {-2.0, 3, 0.1},
            {-2.0, 3.25, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher5[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher5[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher5[2][0], pointsBleacher5[2][1], pointsBleacher5[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher5[3][0], pointsBleacher5[3][1], pointsBleacher5[3][2] + qnt);
        glEnd();

        // tras
        GLfloat pointsBleacher6[4][3] = {
            {2.0, 3.25, -0.01},
            {2.0, 3, -0.01},
            {2.0, 3, 0.1},
            {2.0, 3.25, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher6[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher6[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher6[2][0], pointsBleacher6[2][1], pointsBleacher6[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher6[3][0], pointsBleacher6[3][1], pointsBleacher6[3][2] + qnt);
        glEnd();
    }
    glPopMatrix();
}

void arquibancada_cima(GLuint id)
{
    glPushMatrix();
    for (float qnt = 0; qnt < 0.25 * 3; qnt += 0.25)
    {
        //if (qnt != 0) break;
        if (qnt != 0)   glTranslatef(-0.25, 0, 0);
        
        GLfloat color[] = { 0.0, 0.6, 0.2 };

        //baixo
        GLfloat pointsBleacher1[4][3] = {
            {-2.5, -2.5, -0.01},
            {-2.5, 2.5, -0.01},
            {-2.75, 2.5, -0.01},
            {-2.75, -2.5, -0.01},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher1[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher1[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3fv(pointsBleacher1[2]);
        glTexCoord2f(0.0, 5.0);
        glVertex3fv(pointsBleacher1[3]);
        glEnd();

        //cima
        GLfloat pointsBleacher2[4][3] = {
            {-2.5, -2.5, 0.1},
            {-2.5, 2.5, 0.1},
            {-2.75, 2.5, 0.1},
            {-2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(pointsBleacher2[0][0], pointsBleacher2[0][1], pointsBleacher2[0][2] + qnt);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(pointsBleacher2[1][0], pointsBleacher2[1][1], pointsBleacher2[1][2] + qnt);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher2[2][0], pointsBleacher2[2][1], pointsBleacher2[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher2[3][0], pointsBleacher2[3][1], pointsBleacher2[3][2] + qnt);
        glEnd();

        //esquerda
        GLfloat pointsBleacher3[4][3] = {
            {-2.75, -2.5, -0.01},
            {-2.5, -2.5, -0.01},
            {-2.5, -2.5, 0.1},
            {-2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher3[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher3[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher3[2][0], pointsBleacher3[2][1], pointsBleacher3[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher3[3][0], pointsBleacher3[3][1], pointsBleacher3[3][2] + qnt);
        glEnd();

        //direita
        GLfloat pointsBleacher4[4][3] = {
            {-2.75, 2.5, -0.01},
            {-2.5, 2.5, -0.01},
            {-2.5, 2.5, 0.1},
            {-2.75, 2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glVertex3fv(pointsBleacher4[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher4[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher4[2][0], pointsBleacher4[2][1], pointsBleacher4[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher4[3][0], pointsBleacher4[3][1], pointsBleacher4[3][2] + qnt);
        glEnd();

        //frente
        GLfloat pointsBleacher5[4][3] = {
            {-2.5, -2.5, -0.01},
            {-2.5, 2.5, -0.01},
            {-2.5, 2.5, 0.1},
            {-2.5, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher5[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher5[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher5[2][0], pointsBleacher5[2][1], pointsBleacher5[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher5[3][0], pointsBleacher5[3][1], pointsBleacher5[3][2] + qnt);
        glEnd();

        //tras
        GLfloat pointsBleacher6[4][3] = {
            {-2.75, -2.5, -0.01},
            {-2.75, 2.5, -0.01},
            {-2.75, 2.5, 0.1},
            {-2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher6[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher6[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher6[2][0], pointsBleacher6[2][1], pointsBleacher6[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher6[3][0], pointsBleacher6[3][1], pointsBleacher6[3][2] + qnt);
        glEnd();
    }
    glPopMatrix();
}

void arquibancada_baixo(GLuint id)
{
    glPushMatrix();
    for (float qnt = 0; qnt < 0.25 * 3; qnt += 0.25)
    {
        //if (qnt != 0) break;
        if (qnt != 0)   glTranslatef(0.25, 0, 0);

        GLfloat color[] = { 0.0, 0.6, 0.2 };

        //baixo
        GLfloat pointsBleacher1[4][3] = {
            {2.5, -2.5, -0.01},
            {2.5, 2.5, -0.01},
            {2.75, 2.5, -0.01},
            {2.75, -2.5, -0.01},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher1[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher1[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3fv(pointsBleacher1[2]);
        glTexCoord2f(0.0, 5.0);
        glVertex3fv(pointsBleacher1[3]);
        glEnd();

        //cima
        GLfloat pointsBleacher2[4][3] = {
            {2.5, -2.5, 0.1},
            {2.5, 2.5, 0.1},
            {2.75, 2.5, 0.1},
            {2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(pointsBleacher2[0][0], pointsBleacher2[0][1], pointsBleacher2[0][2] + qnt);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(pointsBleacher2[1][0], pointsBleacher2[1][1], pointsBleacher2[1][2] + qnt);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher2[2][0], pointsBleacher2[2][1], pointsBleacher2[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher2[3][0], pointsBleacher2[3][1], pointsBleacher2[3][2] + qnt);
        glEnd();

        //esquerda
        GLfloat pointsBleacher3[4][3] = {
            {2.75, -2.5, -0.01},
            {2.5, -2.5, -0.01},
            {2.5, -2.5, 0.1},
            {2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher3[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher3[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher3[2][0], pointsBleacher3[2][1], pointsBleacher3[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher3[3][0], pointsBleacher3[3][1], pointsBleacher3[3][2] + qnt);
        glEnd();

        //direita
        GLfloat pointsBleacher4[4][3] = {
            {2.75, 2.5, -0.01},
            {2.5, 2.5, -0.01},
            {2.5, 2.5, 0.1},
            {2.75, 2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glVertex3fv(pointsBleacher4[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher4[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher4[2][0], pointsBleacher4[2][1], pointsBleacher4[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher4[3][0], pointsBleacher4[3][1], pointsBleacher4[3][2] + qnt);
        glEnd();

        //frente
        GLfloat pointsBleacher5[4][3] = {
            {2.5, -2.5, -0.01},
            {2.5, 2.5, -0.01},
            {2.5, 2.5, 0.1},
            {2.5, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher5[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher5[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher5[2][0], pointsBleacher5[2][1], pointsBleacher5[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher5[3][0], pointsBleacher5[3][1], pointsBleacher5[3][2] + qnt);
        glEnd();

        //tras
        GLfloat pointsBleacher6[4][3] = {
            {2.75, -2.5, -0.01},
            {2.75, 2.5, -0.01},
            {2.75, 2.5, 0.1},
            {2.75, -2.5, 0.1},
        };

        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(pointsBleacher6[0]);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(pointsBleacher6[1]);
        glTexCoord2f(1.0, 5.0);
        glVertex3f(pointsBleacher6[2][0], pointsBleacher6[2][1], pointsBleacher6[2][2] + qnt);
        glTexCoord2f(0.0, 5.0);
        glVertex3f(pointsBleacher6[3][0], pointsBleacher6[3][1], pointsBleacher6[3][2] + qnt);
        glEnd();
    }
    glPopMatrix();
}

void arquibancada(GLuint id)
{
    glBindTexture(GL_TEXTURE_2D, id);
    arquibancada_esquerdo(id);
    arquibancada_direito(id);
    arquibancada_cima(id);
    arquibancada_baixo(id);
}

void torcida(){
    // Torcida 1
    drawPerson(2.66, 0.0, 0.6);
    drawPerson(2.66, 0.3, 0.6);
    drawPerson(2.66, 1.0, 0.6);
    drawPerson(2.66, -0.8, 0.6);
    drawPerson(2.66, -0.35, 0.6);

    drawPerson(3.1, -0.35, 0.8);
    drawPerson(3.1, -0.9, 0.8);
    drawPerson(3.1, 1.1, 0.8);
    drawPerson(3.1, 0.6, 0.8);

    // Torcida 2
    drawPerson(-2.66, 0.0, 0.8);
    drawPerson(-2.66, 0.3, 0.8);
    drawPerson(-2.66, 1.0, 0.8);
    drawPerson(-2.66, -0.8, 0.8);
    drawPerson(-2.66, -0.35, 0.8);

    drawPerson(-3.1, -0.35, 0.9);
    drawPerson(-3.1, -0.9, 0.9);
    drawPerson(-3.1, 1.1, 0.9);
    drawPerson(-3.1, 0.6, 0.9);

    // Torcida 3
    drawPerson(0.0, 3.0, 0.5);
    drawPerson(0.8, 3.0, 0.5);
    drawPerson(-0.7, 3.0, 0.5);

    // Torcida 4
    drawPerson(0.0, -3.0, 0.4);
    drawPerson(0.8, -3.0, 0.4);
    drawPerson(-0.7, -3.0, 0.4);
}

void draw_pixel(float x, float y, float z)
{
    glPointSize(2.0);
    GLfloat lines[] = { 1, 1, 1 };
    glColor3fv(lines);
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}

void bresenhamLine(int xa, int ya, int xb, int yb)
{
    int dx = xb - xa;
    int dy = yb - ya;
    int x = xa;
    int y = ya;


    int d = 2 * dy - dx;
    int de = 2 * dy;
    int dne = 2 * (dy - dx);

    while (x < xb) {
        if (d <= 0) {
            d = d + de;
            x = x + 1;
        }
        else {
            d = d + dne;
            y = y + 1;
            x = x + 1;
        }

        draw_pixel((float)x / 100, (float)y / 100, 0.1);
        draw_pixel((float)x / 100, (float)-y / 100, 0.1);
    }

}

void fastLine(int xa, int ya, int xb, int yb)
{
    int x = xa;
    int y = ya;

    if (ya == yb) {
        while (x < xb) {
            draw_pixel((float)x / 100, (float)y / 100, 0.1);
            x = x + 1;
        }
    }

    else if (xa == xb) {
        while (y < yb) {
            draw_pixel((float)x / 100, (float)y / 100, 0.1);
            y = y + 1;
        }
    }
}

void drawSemiCircle(float xc, float yc, float x, float y, int p) {
    if (p == 1) {
        draw_pixel(xc + x, yc + y, 0.1);
        draw_pixel(xc - x, yc + y, 0.1);
        draw_pixel(xc + y, yc + x, 0.1);
        draw_pixel(xc - y, yc + x, 0.1);
    }
    else {
        draw_pixel(xc + x, yc - y, 0.1);
        draw_pixel(xc - x, yc - y, 0.1);
        draw_pixel(xc + y, yc - x, 0.1);
        draw_pixel(xc - y, yc - x, 0.1);
    }
}

void drawCircle(float xc, float yc, float x, float y)
{
    draw_pixel(xc + x, yc + y, 0.1);
    draw_pixel(xc - x, yc + y, 0.1);

    draw_pixel(xc + x, yc - y, 0.1);
    draw_pixel(xc - x, yc - y, 0.1);

    draw_pixel(xc + y, yc + x, 0.1);
    draw_pixel(xc - y, yc + x, 0.1);

    draw_pixel(xc + y, yc - x, 0.1);
    draw_pixel(xc - y, yc - x, 0.1);

}

void semiCircleBres(int xc, int yc, int r, int p) {
    int x = 0, y = r;
    float d = 5 / 4 - r;
    drawCircle(xc, yc, x, y);
    while (y > x)
    {
        if (d < 0) {
            d = d + 2 * x + 3;
            x++;
        }
        else {
            d = d + 2 * (x - y) + 5;
            x++;
            y--;
        }
        drawSemiCircle((float)xc / 100, (float)yc / 100, (float)x / 100, (float)y / 100, p);
    }
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    float d = 5 / 4 - r;
    drawCircle(xc, yc, x, y);
    while (y > x)
    {
        if (d < 0) {
            d = d + 2 * x + 3;
            x++;
        }
        else {
            d = d + 2 * (x - y) + 5;
            x++;
            y--;
        }
        drawCircle((float)xc / 100, (float)yc / 100, (float)x / 100, (float)y / 100);
    }
}

void drawThings()
{
    fastLine(-1.5 * 100, 2.1 * 100, 1.5 * 100, 2.1 * 100);
    fastLine(-1.5 * 100, -2.1 * 100, 1.5 * 100, -2.1 * 100);
    fastLine(-1.5 * 100, -2.1 * 100, -1.5 * 100, 2.1 * 100);
    fastLine(1.5 * 100, -2.1 * 100, 1.5 * 100, 2.1 * 100);
    fastLine(-1.5 * 100, 0 * 100, 1.5 * 100, 0 * 100);
    fastLine(0.8 * 100, 1.25 * 100, 0.8 * 100, 2.1 * 100);
    fastLine(-0.8 * 100, 1.25 * 100, -0.8 * 100, 2.1 * 100);
    fastLine(-0.8 * 100, 1.25 * 100, 0.8 * 100, 1.25 * 100);
    fastLine(0.4 * 100, 1.7 * 100, 0.4 * 100, 2.1 * 100);
    fastLine(-0.4 * 100, 1.7 * 100, -0.4 * 100, 2.1 * 100);
    fastLine(-0.4 * 100, 1.7 * 100, 0.4 * 100, 1.7 * 100);

    fastLine(0.8 * 100, -2.1 * 100, 0.8 * 100, -1.25 * 100);
    fastLine(-0.8 * 100, -2.1 * 100, -0.8 * 100, -1.25 * 100);
    fastLine(-0.8 * 100, -1.25 * 100, 0.8 * 100, -1.25 * 100);
    fastLine(0.4 * 100, -2.1 * 100, 0.4 * 100, -1.7 * 100);
    fastLine(-0.4 * 100, -2.1 * 100, -0.4 * 100, -1.7 * 100);
    fastLine(-0.4 * 100, -1.7 * 100, 0.4 * 100, -1.7 * 100);

    bresenhamLine(1.2 * 100, -2.1 * 100, 1.5 * 100, -1.9 * 100);
    bresenhamLine(-1.5 * 100, 1.9 * 100, -1.2 * 100, 2.1 * 100);

    semiCircleBres(0 * 100, -1.25 * 100, 30, 1);
    semiCircleBres(0 * 100, 1.25 * 100, 30, 0);

    circleBres(0, 0, 60);
}

void ball()
{
    glPushMatrix();
    glTranslatef(speedX, speedY, 0.08);
    glRotatef(rotateBall, 0, 0, 1);
    glColor3f(0.0, 0.9, 0.9);
    glScalef(0.06, 0.06, 0.06);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
}

void placar()
{
    char str[30];
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0);
    sprintf(str, "%d X %d", time1, time2);

    drawString(str);
}

void light()
{
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    float light_diffuse[4];
    float light_specular[4];
    float light_ambient[4];
    float light_position[4];

    if (dia)
    {
        light_diffuse[0] = 0.5;
        light_diffuse[1] = 0.5;
        light_diffuse[2] = 0.5;
        light_diffuse[3] = 1.0;

        light_specular[0] = 1.0;
        light_specular[1] = 1.0;
        light_specular[2] = 1.0;
        light_specular[3] = 1.0;

        light_ambient[0] = 0.3;
        light_ambient[1] = 0.3;
        light_ambient[2] = 0.3;
        light_ambient[3] = 1.0;

        light_position[0] = 0.0;
        light_position[1] = 0.0;
        light_position[2] = 500.0;
        light_position[3] = 1.0;
    }
    else
    {
        light_diffuse[0] = 0.01;
        light_diffuse[1] = 0.01;
        light_diffuse[2] = 0.01;
        light_diffuse[3] = 1.0;

        light_specular[0] = 1.0;
        light_specular[1] = 1.0;
        light_specular[2] = 1.0;
        light_specular[3] = 1.0;

        light_ambient[0] = 0.1;
        light_ambient[1] = 0.1;
        light_ambient[2] = 0.1;
        light_ambient[3] = 1.0;

        light_position[0] = 0.0;
        light_position[1] = 0.0;
        light_position[2] = -500.0;
        light_position[3] = 1.0;
    }
    field2(idTexturas[2]);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (dia) {
        glClearColor(.4, .4, .9, .8);
    }
    else {
        glClearColor(.0, .2, 1.0, .8);
    }
    setView();
    
    light();

    glEnable(GL_TEXTURE_2D);
    field(idTexturas[1], idTexturas[1]);
    
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    arquibancada(idTexturas[0]);
    glDisable(GL_TEXTURE_2D);

    //drawLines();
    drawThings();
    torcida();
    traves();
    //curves();
    ball();
    placar();
    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 97:
        auxSpeedY = -0.025;
        break;
    case 100:
        auxSpeedY = 0.025;
        break;
    case 115:
        auxSpeedX = 0.025;
        break;
    case 119:
        auxSpeedX = -0.025;
        break;
    case 104:
        he = he + 1;
        break;
    case  110:
        he = he - 1;
        break;
    case 105:
        xc = xc - 1;
        break;
    case 107:
        xc = xc + 1;
        break;
    case 106:
        yc = yc - 1;
        break;
    case 108:
        yc = yc + 1;
        break;
    case 'y':
        dia = !dia;
        break;
    
    case 27:
        exit(0);

        glutPostRedisplay();
    }
}

void KeyboardUpHandler(unsigned char key, int x, int y) {
    switch (key) {
    case 97:
        auxSpeedY = 0;
        break;
    case 100:
        auxSpeedY = 0;
        break;
    case 115:
        auxSpeedX = 0;
        break;
    case 119:
        auxSpeedX = 0;
        break;
    case 27:
        exit(0);
    }
}

void update(int value)
{
    speedX += auxSpeedX;
    speedY += auxSpeedY;

    if (auxSpeedY != 0 || auxSpeedX != 0)
    {
        rotateBall += ballAngle;
    }

    if (rotateBall > 8 || rotateBall < -8)
    {
        ballAngle = -ballAngle;
    }

    if ((speedX > -0.4 && speedX < 0.3) && speedY <= -2.1)
    {
        time2 += 1;
        speedX = speedY = 0;
    }

    if ((speedX > -0.4 && speedX < 0.3) && speedY >= 2.1)
    {
        time1 += 1;
        speedX = speedY = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void LoadTexture(string file, GLuint id)
{
    unsigned char* imagem;

    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    imagem = stbi_load(file.c_str(), &width, &height, &channels, 4);

    if(imagem)
    {
        glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagem);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        stbi_image_free(imagem);
    }
    else
    {
        cout << "erro ao carregar a textura" << endl;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("FIFA");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glGenTextures(3, idTexturas);
    LoadTexture("./Imagens/wood.png", idTexturas[0]);
    LoadTexture("./Imagens/grass3.png", idTexturas[1]);
    LoadTexture("./Imagens/mud.png", idTexturas[2]);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);

    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(KeyboardUpHandler);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    glDeleteTextures(1, idTexturas);
    return 0;
}