#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btnCycloid_clicked();

    void on_bntHuygens_clicked();

    void on_bntHypoCycloid_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_spinInterval_valueChanged(double arg1);

    void on_spinCount_valueChanged(int arg1);

    void on_btnBackgroundColor_clicked();

    void on_btnLineColor_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

    void on_btnFlower_clicked();

    void on_btnStarfish_clicked();

    void on_btnCloud1_clicked();

    void on_btnCloud2_clicked();

private:
    Ui::MainWindow *ui;

    void update_ui();
};

#endif // MAINWINDOW_H
