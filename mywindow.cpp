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

    // Create cube
    myCube = new Cube();

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

    // Refresh camera position
    myCamera->look();
    std::vector<faces_4_t>* cube_faces = myCube->get_faces();
    glBegin(GL_QUADS);
    // Face avant
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(0).edge1.X, cube_faces->at(0).edge1.Y, cube_faces->at(0).edge1.Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(0).edge2.X, cube_faces->at(0).edge2.Y, cube_faces->at(0).edge2.Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(0).edge3.X, cube_faces->at(0).edge3.Y, cube_faces->at(0).edge3.Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(0).edge4.X, cube_faces->at(0).edge4.Y, cube_faces->at(0).edge4.Z);
    // Face arrière
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(1).edge1.X, cube_faces->at(1).edge1.Y, cube_faces->at(1).edge1.Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(1).edge2.X, cube_faces->at(1).edge2.Y, cube_faces->at(1).edge2.Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(1).edge3.X, cube_faces->at(1).edge3.Y, cube_faces->at(1).edge3.Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(1).edge4.X, cube_faces->at(1).edge4.Y, cube_faces->at(1).edge4.Z);
    // Face haut
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(2).edge1.X, cube_faces->at(2).edge1.Y, cube_faces->at(2).edge1.Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(2).edge2.X, cube_faces->at(2).edge2.Y, cube_faces->at(2).edge2.Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(2).edge3.X, cube_faces->at(2).edge3.Y, cube_faces->at(2).edge3.Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(2).edge4.X, cube_faces->at(2).edge4.Y, cube_faces->at(2).edge4.Z);
    // Face bas
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(3).edge1.X, cube_faces->at(3).edge1.Y, cube_faces->at(3).edge1.Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(3).edge2.X, cube_faces->at(3).edge2.Y, cube_faces->at(3).edge2.Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(3).edge3.X, cube_faces->at(3).edge3.Y, cube_faces->at(3).edge3.Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(3).edge4.X, cube_faces->at(3).edge4.Y, cube_faces->at(3).edge4.Z);
    // Face droite
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(4).edge1.X, cube_faces->at(4).edge1.Y, cube_faces->at(4).edge1.Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(4).edge2.X, cube_faces->at(4).edge2.Y, cube_faces->at(4).edge2.Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(4).edge3.X, cube_faces->at(4).edge3.Y, cube_faces->at(4).edge3.Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(4).edge4.X, cube_faces->at(4).edge4.Y, cube_faces->at(4).edge4.Z);
    // Face gauche
    glTexCoord2f(0.0f, 0.0f); glVertex3f(cube_faces->at(5).edge1.X, cube_faces->at(5).edge1.Y, cube_faces->at(5).edge1.Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(cube_faces->at(5).edge2.X, cube_faces->at(5).edge2.Y, cube_faces->at(5).edge2.Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(cube_faces->at(5).edge3.X, cube_faces->at(5).edge3.Y, cube_faces->at(5).edge3.Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(cube_faces->at(5).edge4.X, cube_faces->at(5).edge4.Y, cube_faces->at(5).edge4.Z);
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
