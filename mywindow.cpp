#include "mywindow.h"

myWindow::myWindow(QWidget *parent): myGLWidget(60, parent, "OpenGL learning...")
{

}

void myWindow::initializeGL()
{
    f_x = 0.0;
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Create camera
    myCamera = new Camera();

    loadTexture("res/box.png");
    glEnable(GL_TEXTURE_2D);
}

void myWindow::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    myCamera->look();
    glBegin(GL_QUADS);
    // Face avant
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, -1.0,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0, -1.0,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0,  1.0,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0,  1.0,  1.0f);
    // Face arrière
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0, -1.0, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0,  1.0, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0,  1.0, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0, -1.0, -1.0f);
    // Face haut
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0,  1.0, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0,  1.0,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0,  1.0,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0,  1.0, -1.0f);
    // Face bas
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0, -1.0, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0, -1.0, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0, -1.0,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0, -1.0,  1.0f);
    // Face droite
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0, -1.0, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0,  1.0, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0,  1.0,  1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0, -1.0,  1.0f);
    // Face gauche
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, -1.0, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0, -1.0,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0,  1.0,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0,  1.0, -1.0f);
    glEnd();
}

void myWindow::loadTexture(QString textureName)
{
    QImage qim_Texture;
    QImage qim_TempTexture;
    if(qim_TempTexture.load(textureName))
    {
        qim_Texture = QGLWidget::convertToGLFormat(qim_TempTexture);
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, qim_Texture.width(), qim_Texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cout<<"Could not load texture!";
    }
}
