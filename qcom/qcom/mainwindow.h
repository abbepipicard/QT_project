#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>

#include "qextserial/qextserialport.h"
#include "aboutdialog.h"
#include "qcustomplot/qcustomplot.h"


//延时，TIME_OUT是串口读写的延时
#define TIME_OUT 10

//连续发送定时器计时间隔,500ms
#define OBO_TIMER_INTERVAL 500

//载入文件时，如果文件大小超过TIP_FILE_SIZE字节则提示文件过大是否继续打开
#define TIP_FILE_SIZE 5000
//载入文件最大长度限制在MAX_FILE_SIZE字节内
#define MAX_FILE_SIZE 10000

//看了一贴http://www.oschina.net/code/snippet_114502_47429，很有帮助
#define TextColor QColor(255,255,255)
#define Plot_NoColor QColor(0,0,0,0)

#define Plot1_LineColor QColor(41,138,220)
#define Plot2_LineColor QColor(246,98,0)
#define Plot3_LineColor QColor(204,250,255,200)
#define Plot4_LineColor QColor(5,189,251)
#define Plot5_LineColor QColor(130,111,255)
#define Plot6_LineColor QColor(99,149,236)

#define TextWidth 1
#define LineWidth 2
#define DotWidth 10

#define Plot_Count 160

#define Plot1_MaxY 500
#define Plot2_MaxY 0.5
#define Huitu_Inteval 10

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startInit();

protected:
    void changeEvent(QEvent *e);
    void setActionsEnabled(bool status);
    void setComboBoxEnabled(bool status);

private:
    Ui::MainWindow *ui;
    AboutDialog aboutdlg;
    QextSerialPort *myCom;
    //QCustomPlot *customPlot;
    QTimer *obotimer;

    QTimer *update;
    unsigned int timerdly;
    unsigned int obotimerdly;
    QString write2fileName;    //写读取的串口数据到该文件
    bool is_huitu;
    qint64 init_time;

    //绘图使用
    QString buf, buf1;
    double sample_time = 0, sample_value = 0;

    void initplot();
    void initplot123();         //init yaw,pitch,roll
    void initplot456();         //init ex,ey,ez

private slots:

    void on_actionWriteToFile_triggered();
    void on_actionCleanPort_triggered();
    void on_actionLoadfile_triggered();
    void on_delayspinBox_valueChanged(int );
    void on_actionAdd_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_obocheckBox_clicked();
    void on_actionClearBytes_triggered();
    void on_actionAbout_triggered();
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_clearUpBtn_clicked();
    void on_sendmsgBtn_clicked();
    void readMyCom();
    void sendMsg();
    void time_update();

    //end by
    void on_delayspinBox_editingFinished();

    void on_huitupushButton_clicked();
};

#endif // MAINWINDOW_H
