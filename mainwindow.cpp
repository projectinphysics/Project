#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>
#include "wopengl.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WOpenGL *GLL = new WOpenGL();
    GLL->setMinimumSize(this->minimumWidth(), this->minimumHeight());
    GLL->setMaximumSize(this->width()-100, this->height());
    GLL->setGeometry(0, 0, 20, 20);
    setCentralWidget(GLL);
}

MainWindow::~MainWindow()
{
    delete ui;
}
