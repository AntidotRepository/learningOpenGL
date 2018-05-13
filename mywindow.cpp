#include "mywindow.h"

myWindow::myWindow(QWidget *parent): myGLWidget(60, parent, "OpenGL learning...")
{
    moveForward = false;
    moveBackward = false;
    moveLeftward = false;
    moveRightward = false;
    rotateDown = false;
    rotateLeft = false;
    rotateRight = false;
    rotateUp = false;

    // Enable mouse move events even if no button is pressed
    setMouseTracking(true);
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

    glEnable(GL_TEXTURE_2D);

    // Create cube
    coord3d_t posCube1 = {0, 0, 0};
    coord3d_t posCube2 = {-5, -5, -10};

    myCube1 = new Cube(posCube1, 1);
    myCube2 = new Cube(posCube2, 10, "res/box.png");
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
    // Get cube position
    //std::vector<faces_4_t>* cube1_faces = myCube1->get_faces();

    myCube1->rotate({1.0, 1.0, 1.0}, 1.0f);
    //myCube1->translate({1.0, 0.0, 0.0}, 0.01f);

    if(moveForward == true)
    {
        myCamera->moveForward(1);
    }
    if(moveBackward == true)
    {
        myCamera->moveBackward(1);
    }
    if(moveLeftward == true)
    {
        myCamera->moveLeftward(1);
    }
    if(moveRightward == true)
    {
        myCamera->moveRightward(1);
    }
    if(rotateUp == true)
    {
        myCamera->rotateCam(0, 1);
    }
    if(rotateDown == true)
    {
        myCamera->rotateCam(0, -1);
    }
    if(rotateLeft == true)
    {
        myCamera->rotateCam(-1, 0);
    }
    if(rotateRight == true)
    {
        myCamera->rotateCam(1, 0);
    }
    myCamera->rotateCam(-rotateXAngle, rotateYAngle);
    rotateXAngle = 0;
    rotateYAngle = 0;

    myCube1->draw();
    myCube2->draw();
}

void myWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
    case Qt::Key_Z:
        moveForward = false;
        break;
    case Qt::Key_S:
        moveBackward = false;
        break;
    case Qt::Key_Q:
        moveLeftward = false;
        break;
    case Qt::Key_D:
        moveRightward = false;
        break;
    case Qt::Key_Up:
        rotateUp = false;
        break;
    case Qt::Key_Down:
        rotateDown = false;
        break;
    case Qt::Key_Left:
        rotateLeft = false;
        break;
    case Qt::Key_Right:
        rotateRight = false;
        break;
    }
}

void myWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_F1:
        toggleFullWindow();
        break;
    case Qt::Key_Z:
        moveForward = true;
        break;
    case Qt::Key_S:
        moveBackward = true;
        break;
    case Qt::Key_Q:
        moveLeftward = true;
        break;
    case Qt::Key_D:
        moveRightward = true;
        break;
    case Qt::Key_Up:
        rotateUp = true;
        break;
    case Qt::Key_Down:
        rotateDown = true;
        break;
    case Qt::Key_Left:
        rotateLeft = true;
        break;
    case Qt::Key_Right:
        rotateRight = true;
        break;
    }
}

void myWindow::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    static int oldXPos = 0;
    static int oldYPos = 0;

    rotateXAngle = oldXPos - mouseEvent->pos().x();
    rotateYAngle = oldYPos - mouseEvent->pos().y();

    oldXPos = mouseEvent->pos().x();
    oldYPos = mouseEvent->pos().y();

}
