#include "myglwidget.h"

myGLWidget::myGLWidget(int FPS, QWidget *parent, char *name): QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
    if(FPS == 0)
        t_Timer = NULL;
    else
    {
        int seconde = 1000; // 1 seconde = 1000ms
        int timerInterval = seconde / FPS;
        t_Timer = new QTimer(this);
        connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        t_Timer->start(timerInterval);
    }
    b_Fullscreen = false;
}

void myGLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_F1:
        toggleFullWindow();
        break;
    }
}

void myGLWidget::timeOutSlot()
{
    updateGL();
}

void myGLWidget::toggleFullWindow()
{
    if(b_Fullscreen)
    {
        showNormal();
        b_Fullscreen = false;
    }
    else
    {
        showFullScreen();
        b_Fullscreen = true;
    }
}
