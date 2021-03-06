#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue( this->ui->renderArea->getScale() );
    this->ui->spinInterval->setValue( this->ui->renderArea->getIntervalLength() );
    this->ui->spinCount->setValue( this->ui->renderArea->getStepCount() );
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_bntHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_bntHypoCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCircle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Circle);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnEllipse_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Ellipse);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnFlower_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Flower);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnStarfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCloud1_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud1);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCloud2_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud2);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double intervalLength)
{
    this->ui->renderArea->setIntervalLength(intervalLength);
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinCount_valueChanged(int count)
{
    this->ui->renderArea->setStepCount(count);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnBackgroundColor_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->getBackgroundColor(), this, "Select Color");
    this->ui->renderArea->setBackgroundColor(color);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->getShapeColor(), this, "Select Color");
    this->ui->renderArea->setShapeColor(color);
    this->ui->renderArea->repaint();
}
