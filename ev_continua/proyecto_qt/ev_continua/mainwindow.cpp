#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <MousePosition.h>
#include <PintarPoligono.h>
#include <Transformaciones.h>


PintarPoligono Pp;
Linea L;
MousePosition MP;
Transformaciones T;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_slider_escalar_valueChanged(int value)
{
    T.scalamiento(MP.pares,value/10.0,value/10.0);
}


void MainWindow::on_slider_rotar_valueChanged(int value)
{
    T.rotacion(MP.pares,value);
}



void MainWindow::on_slider_des_x_valueChanged(int value)
{
    T.desplazamiento(MP.pares,value,0);
}

void MainWindow::on_slider_des_y_valueChanged(int value)
{
    T.desplazamiento(MP.pares,0,value);
}
