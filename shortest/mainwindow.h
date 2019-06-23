#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<shortestpath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int c=4;
    int distance[25];
    int distance1[25][25];
    QString display;
    QString colors[25][25];
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
   void paintEvent(QPaintEvent *);

private slots:
    void on_btn_chengdu_clicked();

    void on_btn_kunming_clicked();

    void on_btn_guiyang_clicked();

    void on_btn_guangzhou_clicked();

    void on_btn_nanning_clicked();

    void on_btn_liuzhou_clicked();

    void on_btn_zhuzhou_clicked();

    void on_btn_haerbin_clicked();

    void on_btn_shenzhen_clicked();

    void on_btn_fuzhou_clicked();

    void on_btn_nanchang_clicked();

    void on_btn_shanghai_clicked();

    void on_btn_wuhan_clicked();

    void on_btn_xuzhou_clicked();

    void on_btn_zhengzhou_clicked();

    void on_btn_xian_clicked();

    void on_btn_tianjing_clicked();

    void on_btn_dalian_clicked();

    void on_btn_shenyang_clicked();

    void on_btn_wulumuqi_clicked();

    void on_btn_xining_clicked();

    void on_btn_huhehaote_clicked();

    void on_btn_changchun_clicked();

    void on_btn_beijing_clicked();

    void on_btn_lanzhou_clicked();

    void on_btn_djstl_clicked();

    void on_btn_flyd_clicked();

private:
    Ui::MainWindow *ui;
    shortestpath *shortes;
};

#endif // MAINWINDOW_H
