#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QPainter>
#include<QTime>

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->shortes=new shortestpath;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->shortes->StortPath1(this->shortes->G,this->shortes->P1,this->distance1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter pbk(this);
    pbk.drawPixmap(30,10,881,701,QPixmap("../image/中国地图.jpg"));

    QPen bj_tj_pen;
    QPainter bj_tj_painter(this);
    bj_tj_pen.setWidth(5);
    bj_tj_pen.setColor(QColor(colors[14][15]));
    bj_tj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    bj_tj_painter.setPen(bj_tj_pen);
    bj_tj_painter.drawLine(QPointF(ui->btn_beijing->x()+7,ui->btn_beijing->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));// 绘制直线

    QPen cd_km_pen;
    QPainter cd_km_painter(this);
    cd_km_pen.setWidth(5);
    cd_km_pen.setColor(QColor(colors[0][1]));
    cd_km_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_km_painter.setPen(cd_km_pen);
    cd_km_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_kunming->x()+7, ui->btn_kunming->y()+7));// 绘制直线

    QPen cd_xa_pen;
    QPainter cd_xa_painter(this);
    cd_xa_pen.setWidth(5);
    cd_xa_pen.setColor(QColor(colors[0][20]));
    cd_xa_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_xa_painter.setPen(cd_xa_pen);
    cd_xa_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));// 绘制直线

    QPen cd_gy_pen;
    QPainter cd_gy_painter(this);
    cd_gy_pen.setWidth(5);
    cd_gy_pen.setColor(QColor(colors[0][2]));
    cd_gy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_gy_painter.setPen(cd_gy_pen);
    cd_gy_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_guiyang->x()+7, ui->btn_guiyang->y()+7));// 绘制直线

    QPen km_gy_pen;
    QPainter km_gy_painter(this);
    km_gy_pen.setWidth(5);
    km_gy_pen.setColor(QColor(colors[1][2]));
    km_gy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    km_gy_painter.setPen(km_gy_pen);
    km_gy_painter.drawLine(QPointF(ui->btn_guiyang->x()+7,ui->btn_guiyang->y()+7), QPointF(ui->btn_kunming->x()+7, ui->btn_kunming->y()+7));// 绘制直线


    QPen gy_lz_pen;
    QPainter gy_lz_painter(this);
    gy_lz_pen.setWidth(5);
    gy_lz_pen.setColor(QColor(colors[2][3]));
    gy_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gy_lz_painter.setPen(gy_lz_pen);
    gy_lz_painter.drawLine(QPointF(ui->btn_guiyang->x()+7,ui->btn_guiyang->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线

    QPen lz_nn_pen;
    QPainter lz_nn_painter(this);
    lz_nn_pen.setWidth(5);
    lz_nn_pen.setColor(QColor(colors[3][4]));
    lz_nn_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_nn_painter.setPen(lz_nn_pen);
    lz_nn_painter.drawLine(QPointF(ui->btn_nanning->x()+7,ui->btn_nanning->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线

    QPen lz_zz_pen;
    QPainter lz_zz_painter(this);
    lz_zz_pen.setWidth(5);
    lz_zz_pen.setColor(QColor(colors[3][5]));
    lz_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_zz_painter.setPen(lz_zz_pen);
    lz_zz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线

    QPen gy_zz_pen;
    QPainter gy_zz_painter(this);
    gy_zz_pen.setWidth(5);
    gy_zz_pen.setColor(QColor(colors[2][5]));
    gy_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gy_zz_painter.setPen(gy_zz_pen);
    gy_zz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_guiyang->x()+7, ui->btn_guiyang->y()+7));// 绘制直线

    QPen zz_gz_pen;
    QPainter zz_gz_painter(this);
    zz_gz_pen.setWidth(5);
    zz_gz_pen.setColor(QColor(colors[5][6]));
    zz_gz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_gz_painter.setPen(zz_gz_pen);
    zz_gz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_guangzhou->x()+7, ui->btn_guangzhou->y()+7));// 绘制直线

    QPen gz_sz_pen;
    QPainter gz_sz_painter(this);
    gz_sz_pen.setWidth(5);
    gz_sz_pen.setColor(QColor(colors[6][7]));
    gz_sz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gz_sz_painter.setPen(gz_sz_pen);
    gz_sz_painter.drawLine(QPointF(ui->btn_guangzhou->x()+7,ui->btn_guangzhou->y()+7), QPointF(ui->btn_shenzhen->x()+7, ui->btn_shenzhen->y()+7));// 绘制直线

    QPen zz_nc_pen;
    QPainter zz_nc_painter(this);
    zz_nc_pen.setWidth(5);
    zz_nc_pen.setColor(QColor(colors[5][8]));
    zz_nc_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_nc_painter.setPen(zz_nc_pen);
    zz_nc_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen nc_fz_pen;
    QPainter nc_fz_painter(this);
    nc_fz_pen.setWidth(5);
    nc_fz_pen.setColor(QColor(colors[8][9]));
    nc_fz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_fz_painter.setPen(nc_fz_pen);
    nc_fz_painter.drawLine(QPointF(ui->btn_fuzhou->x()+7,ui->btn_fuzhou->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen nc_sh_pen;
    QPainter nc_sh_painter(this);
    nc_sh_pen.setWidth(5);
    nc_sh_pen.setColor(QColor(colors[8][10]));
    nc_sh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_sh_painter.setPen(nc_sh_pen);
    nc_sh_painter.drawLine(QPointF(ui->btn_shanghai->x()+7,ui->btn_shanghai->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen zz_wh_pen;
    QPainter zz_wh_painter(this);
    zz_wh_pen.setWidth(5);
    zz_wh_pen.setColor(QColor(colors[5][11]));
    zz_wh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_wh_painter.setPen(zz_wh_pen);
    zz_wh_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_wuhan->x()+7, ui->btn_wuhan->y()+7));

    QPen wh_zz_pen;
    QPainter wh_zz_painter(this);
    wh_zz_pen.setWidth(5);
    wh_zz_pen.setColor(QColor(colors[11][13]));
    wh_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    wh_zz_painter.setPen(wh_zz_pen);
    wh_zz_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_wuhan->x()+7, ui->btn_wuhan->y()+7));

    QPen zz_xz_pen;
    QPainter zz_xz_painter(this);
    zz_xz_pen.setWidth(5);
    zz_xz_pen.setColor(QColor(colors[12][13]));
    zz_xz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_xz_painter.setPen(zz_xz_pen);
    zz_xz_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_xuzhou->x()+7, ui->btn_xuzhou->y()+7));

    QPen sh_xz_pen;
    QPainter sh_xz_painter(this);
    sh_xz_pen.setWidth(5);
    sh_xz_pen.setColor(QColor(colors[10][12]));
    sh_xz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sh_xz_painter.setPen(sh_xz_pen);
    sh_xz_painter.drawLine(QPointF(ui->btn_shanghai->x()+7,ui->btn_shanghai->y()+7), QPointF(ui->btn_xuzhou->x()+7, ui->btn_xuzhou->y()+7));

    QPen zz_bj_pen;
    QPainter zz_bj_painter(this);
    zz_bj_pen.setWidth(5);
    zz_bj_pen.setColor(QColor(colors[13][15]));
    zz_bj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_bj_painter.setPen(zz_bj_pen);
    zz_bj_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_beijing->x()+7, ui->btn_beijing->y()+7));

    QPen xz_tj_pen;
    QPainter xz_tj_painter(this);
    xz_tj_pen.setWidth(5);
    xz_tj_pen.setColor(QColor(colors[12][14]));
    xz_tj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xz_tj_painter.setPen(xz_tj_pen);
    xz_tj_painter.drawLine(QPointF(ui->btn_xuzhou->x()+7,ui->btn_xuzhou->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));

    QPen tj_sy_pen;
    QPainter tj_sy_painter(this);
    tj_sy_pen.setWidth(5);
    tj_sy_pen.setColor(QColor(colors[14][16]));
    tj_sy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    tj_sy_painter.setPen(tj_sy_pen);
    tj_sy_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));

    QPen sy_dl_pen;
    QPainter sy_dl_painter(this);
    sy_dl_pen.setWidth(5);
    sy_dl_pen.setColor(QColor(colors[16][17]));
    sy_dl_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sy_dl_painter.setPen(sy_dl_pen);
    sy_dl_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_dalian->x()+7, ui->btn_dalian->y()+7));

    QPen sy_cc_pen;
    QPainter sy_cc_painter(this);
    sy_cc_pen.setWidth(5);
    sy_cc_pen.setColor(QColor(colors[16][18]));
    sy_cc_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sy_cc_painter.setPen(sy_cc_pen);
    sy_cc_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_changchun->x()+7, ui->btn_changchun->y()+7));

    QPen cc_heb_pen;
    QPainter cc_heb_painter(this);
    cc_heb_pen.setWidth(5);
    cc_heb_pen.setColor(QColor(colors[18][19]));
    cc_heb_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cc_heb_painter.setPen(cc_heb_pen);
    cc_heb_painter.drawLine(QPointF(ui->btn_haerbin->x()+7,ui->btn_haerbin->y()+7), QPointF(ui->btn_changchun->x()+7, ui->btn_changchun->y()+7));

    QPen zz_xa_pen;
    QPainter zz_xa_painter(this);
    zz_xa_pen.setWidth(5);
    zz_xa_pen.setColor(QColor(colors[13][20]));
    zz_xa_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_xa_painter.setPen(zz_xa_pen);
    zz_xa_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));

    QPen xa_lz_pen;
    QPainter xa_lz_painter(this);
    xa_lz_pen.setWidth(5);
    xa_lz_pen.setColor(QColor(colors[20][22]));
    xa_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xa_lz_painter.setPen(xa_lz_pen);
    xa_lz_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));

    QPen hhht_lz_pen;
    QPainter hhht_lz_painter(this);
    hhht_lz_pen.setWidth(5);
    hhht_lz_pen.setColor(QColor(colors[21][22]));
    hhht_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    hhht_lz_painter.setPen(hhht_lz_pen);
    hhht_lz_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));

    QPen bj_hhht_pen;
    QPainter bj_hhht_painter(this);
    bj_hhht_pen.setWidth(5);
    bj_hhht_pen.setColor(QColor(colors[15][21]));
    bj_hhht_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    bj_hhht_painter.setPen(bj_hhht_pen);
    bj_hhht_painter.drawLine(QPointF(ui->btn_beijing->x()+7,ui->btn_beijing->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));

    QPen lz_xl_pen;
    QPainter lz_xl_painter(this);
    lz_xl_pen.setWidth(5);
    lz_xl_pen.setColor(QColor(colors[22][23]));
    lz_xl_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_xl_painter.setPen(lz_xl_pen);
    lz_xl_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_xining->x()+7, ui->btn_xining->y()+7));

    QPen lz_wlmq_pen;
    QPainter lz_wlmq_painter(this);
    lz_wlmq_pen.setWidth(5);
    lz_wlmq_pen.setColor(QColor(colors[22][24]));
    lz_wlmq_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_wlmq_painter.setPen(lz_wlmq_pen);
    lz_wlmq_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_wulumuqi->x()+7, ui->btn_wulumuqi->y()+7));
}
void MainWindow::on_btn_chengdu_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("成都");
        this->shortes->starcity="成都";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else
    {
        this->ui->label_over->setText("成都");
        this->shortes->overcity="成都";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="成都")
                {
                    t=i;
                    display="两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_kunming_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("昆明");
        this->shortes->starcity="昆明";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("昆明");
        this->shortes->overcity="昆明";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="昆明")
                {
                    t=i;
                    display="两地最短距离为"+ QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_guiyang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("贵阳");
        this->shortes->starcity="贵阳";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("贵阳");
        this->shortes->overcity="贵阳";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="贵阳")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_guangzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("广州");
        this->shortes->starcity="广州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("广州");
        this->shortes->overcity="广州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="广州")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_nanning_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("南宁");
        this->shortes->starcity="南宁";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("南宁");
        this->shortes->overcity="南宁";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="南宁")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_liuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("柳州");
        this->shortes->starcity="柳州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("柳州");
        this->shortes->overcity="柳州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="柳州")
                {
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                    t=i;
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_zhuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("株州");
        this->shortes->starcity="株州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("株州");
        this->shortes->overcity="株州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="株州")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_haerbin_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_haerbin->text());
        this->shortes->starcity="哈尔";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_haerbin->text());
        this->shortes->overcity="哈尔";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="哈尔")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shenzhen_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("深圳");
        this->shortes->starcity="深圳";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("深圳");
        this->shortes->overcity="深圳";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="深圳")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_fuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("福州");
        this->shortes->starcity="福州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("福州");
        this->shortes->overcity="福州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="福州")
                {
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                    t=i;
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_nanchang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("南昌");
        this->shortes->starcity="南昌";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("南昌");
        this->shortes->overcity="南昌";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="南昌")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shanghai_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("上海");
        this->shortes->starcity="上海";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("上海");
        this->shortes->overcity="上海";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="上海")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_wuhan_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("武汉");
        this->shortes->starcity="武汉";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("武汉");
        this->shortes->overcity="武汉";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="武汉")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("徐州");
        this->shortes->starcity="徐州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("徐州");
        this->shortes->overcity="徐州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="徐州")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_zhengzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("郑州");
        this->shortes->starcity="郑州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("郑州");
        this->shortes->overcity="郑州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="郑州")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xian_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("西安");
        this->shortes->starcity="西安";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("西安");
        this->shortes->overcity="西安";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="西安")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_tianjing_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("天津");
        this->shortes->starcity="天津";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("天津");
        this->shortes->overcity="天津";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="天津")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_dalian_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("大连");
        this->shortes->starcity="大连";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("大连");
        this->shortes->overcity="大连";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="大连")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shenyang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("沈阳");
        this->shortes->starcity="沈阳";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("沈阳");
        this->shortes->overcity="沈阳";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="沈阳")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_wulumuqi_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("乌鲁木齐");
        this->shortes->starcity="乌鲁木齐";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("乌鲁木齐");
        this->shortes->overcity="乌鲁木齐";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="乌鲁木齐")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xining_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("西宁");
        this->shortes->starcity="西宁";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("西宁");
        this->shortes->overcity="西宁";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="西宁")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_huhehaote_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("呼和浩特");
        this->shortes->starcity="呼和浩特";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("呼和浩特");
        this->shortes->overcity="呼和浩特";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="呼和浩特")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_changchun_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("长春");
        this->shortes->starcity="长春";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("长春");
        this->shortes->overcity="长春";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="长春")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_beijing_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("北京");
        this->shortes->starcity="北京";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("北京");
        this->shortes->overcity="北京";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="北京")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)
                                        {colors[n][m] = "red";colors[m][n] = "red";
                                        }
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_lanzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText("兰州");
        this->shortes->starcity="兰州";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText("兰州");
        this->shortes->overcity="兰州";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="兰州")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_djstl_clicked()
{

    this->c=0;
    this->ui->btn_djstl->setStyleSheet("color: rgb(85, 170, 255);""background-color: rgb(189, 240, 255);");
    this->ui->btn_flyd->setStyleSheet("color: rgb(85, 170, 255);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->ui->label_start->setText("");
    this->ui->label_over->setText("");
    this->ui->label_display->setText("");
    this->shortes->starcity="";
    this->shortes->overcity="";
    update();
}

void MainWindow::on_btn_flyd_clicked()
{
    this->c=1;
    this->ui->btn_flyd->setStyleSheet("color: rgb(85, 170, 255);""background-color: rgb(189, 240, 255);");
    this->ui->btn_djstl->setStyleSheet("color: rgb(85, 170, 255);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->ui->label_start->setText("");
    this->ui->label_over->setText("");
    this->ui->label_display->setText("");
    this->shortes->starcity="";
    this->shortes->overcity="";
    update();
}
