#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startInit();
    myCom = NULL;

 #ifdef Q_OS_LINUX
    ui->portNameComboBox->addItem( "ttyUSB0");
    ui->portNameComboBox->addItem( "ttyUSB1");
    ui->portNameComboBox->addItem( "ttyUSB2");
    ui->portNameComboBox->addItem( "ttyUSB3");
    ui->portNameComboBox->addItem( "ttyS0");
    ui->portNameComboBox->addItem( "ttyS1");
    ui->portNameComboBox->addItem( "ttyS2");
    ui->portNameComboBox->addItem( "ttyS3");
    ui->portNameComboBox->addItem( "ttyS4");
    ui->portNameComboBox->addItem( "ttyS5");
    ui->portNameComboBox->addItem( "ttyS6");
#elif defined (Q_OS_WIN)
    ui->portNameComboBox->addItem("COM0");
    ui->portNameComboBox->addItem("COM1");
    ui->portNameComboBox->addItem("COM2");
    ui->portNameComboBox->addItem("COM3");
    ui->portNameComboBox->addItem("COM4");
    ui->portNameComboBox->addItem("COM5");
    ui->portNameComboBox->addItem("COM6");
    ui->portNameComboBox->addItem("COM7");
    ui->portNameComboBox->addItem("COM8");
    ui->portNameComboBox->addItem("COM9");
    ui->portNameComboBox->addItem("COM10");
    ui->portNameComboBox->addItem("COM11");
    ui->portNameComboBox->addItem("COM12");
    ui->portNameComboBox->addItem("COM13");
    ui->portNameComboBox->addItem("COM14");
    ui->portNameComboBox->addItem("COM15");

#endif

    ui->statusBar->showMessage(tr("Q串口助手"));
}

MainWindow::~MainWindow()
{
    if(myCom != NULL){
        if(myCom->isOpen()){
            myCom->close();
        }
        delete myCom;
    }
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::startInit(){
    init_time = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    //this->setWindowTitle(tr("MyComDebug&&Plot"));                //自己设置标题栏
    this->setWindowTitle(tr("ZSL_COMDEBUG&&SERIALPLOT 2015.12.22"));                //自己设置标题栏
    setActionsEnabled(false);
    ui->delayspinBox->setEnabled(false);
    ui->sendmsgBtn->setEnabled(false);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);
    is_huitu = false;
    //初始化连续发送计时器计时间隔
    obotimerdly = OBO_TIMER_INTERVAL;

    //设置连续发送计时器
    obotimer = new QTimer(this);
    connect(obotimer, SIGNAL(timeout()), this, SLOT(sendMsg()));
    initplot();
}

void MainWindow::initplot()
{
    //绘图对象
    //设置绘图更新定时器
    update = new QTimer(this);
    update->setInterval(Huitu_Inteval);//图像40ms更新
    connect(update,SIGNAL(timeout()),this,SLOT(time_update()));
}

void MainWindow::initplot123()
{
    // 设置坐标轴的范围，以看到所有数据,选择左、下轴，并设定范围
    ui->customPlot->xAxis->setVisible(true);
    ui->customPlot->yAxis->setVisible(true);
    ui->customPlot->xAxis->setRange(0, Plot_Count);//显示200秒内情况，那么就决定了QVactoe大小
    ui->customPlot->yAxis->setRange(-1 * Plot1_MaxY, Plot1_MaxY);
    // 为坐标轴添加标签
    ui->customPlot->xAxis->setLabel("time(s)");
    ui->customPlot->yAxis->setLabel("angle(deg)");

    ui->customPlot->addGraph();

    //每次仅用一个graph画
    if(ui->yawradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("yaw");
    }
    if(ui->pitchradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("pitch");
    }
    if(ui->rollradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("roll");
    }
}

void MainWindow::initplot456()
{
    // 设置坐标轴的范围，以看到所有数据,选择左、下轴，并设定范围
    ui->customPlot->xAxis->setVisible(true);
    ui->customPlot->yAxis->setVisible(true);
    ui->customPlot->xAxis->setRange(0, Plot_Count);//显示200秒内情况，那么就决定了QVactoe大小
    ui->customPlot->yAxis->setRange(-1 * Plot2_MaxY, Plot2_MaxY);
    // 为坐标轴添加标签
    ui->customPlot->xAxis->setLabel("time(s)");
    ui->customPlot->yAxis->setLabel("error_angle(deg)");

    ui->customPlot->addGraph();

    if(ui->exradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("ex");
    }
    if(ui->eyradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("ey");
    }
    if(ui->ezradioButton->isChecked())
    {
       ui->customPlot->graph(0)->setName("ez");
    }
}

void MainWindow::setActionsEnabled(bool status)
{
    ui->actionSave->setEnabled(status);
    ui->actionClose->setEnabled(status);
    ui->actionLoadfile->setEnabled(status);
    ui->actionCleanPort->setEnabled(status);
    ui->actionWriteToFile->setEnabled(status);
}

void MainWindow::setComboBoxEnabled(bool status)
{
    ui->portNameComboBox->setEnabled(status);
    ui->baudRateComboBox->setEnabled(status);
    ui->dataBitsComboBox->setEnabled(status);
    ui->parityComboBox->setEnabled(status);
    ui->stopBitsComboBox->setEnabled(status);
}

//打开串口
void MainWindow::on_actionOpen_triggered()
{
    QString portName = ui->portNameComboBox->currentText();   //获取串口名
#ifdef Q_OS_LINUX
    myCom = new QextSerialPort("/dev/" + portName);
#elif defined (Q_OS_WIN)
    myCom = new QextSerialPort(portName);
#endif
    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    //设置波特率
    myCom->setBaudRate((BaudRateType)ui->baudRateComboBox->currentText().toInt());

    //设置数据位
    myCom->setDataBits((DataBitsType)ui->dataBitsComboBox->currentText().toInt());

    //设置校验
    switch(ui->parityComboBox->currentIndex()){
    case 0:
         myCom->setParity(PAR_NONE);
         break;
    case 1:
        myCom->setParity(PAR_ODD);
        break;
    case 2:
        myCom->setParity(PAR_EVEN);
        break;
    default:
        myCom->setParity(PAR_NONE);
        qDebug("set to default : PAR_NONE");
        break;
    }

    //设置停止位
    switch(ui->stopBitsComboBox->currentIndex()){
    case 0:
        myCom->setStopBits(STOP_1);
        break;
    case 1:
 #ifdef Q_OS_WIN
        myCom->setStopBits(STOP_1_5);
 #endif
        break;
    case 2:
        myCom->setStopBits(STOP_2);
        break;
    default:
        myCom->setStopBits(STOP_1);
        qDebug("set to default : STOP_1");
        break;
    }    

    //设置数据流控制
    myCom->setFlowControl(FLOW_OFF);
    //设置延时
    myCom->setTimeout(TIME_OUT);

    if(myCom->open(QIODevice::ReadWrite)){
        QMessageBox::information(this, tr("打开成功"), tr("已成功打开串口") + portName, QMessageBox::Ok);
		//界面控制
		ui->sendmsgBtn->setEnabled(true);
        setComboBoxEnabled(false);

        ui->sendMsgLineEdit->setEnabled(true);

        ui->actionOpen->setEnabled(false);
        ui->sendMsgLineEdit->setFocus();
        ui->obocheckBox->setEnabled(true);
        ui->actionAdd->setEnabled(false);

        setActionsEnabled(true);
    }else{
        QMessageBox::critical(this, tr("打开失败"), tr("未能打开串口 ") + portName + tr("\n该串口设备不存在或已被占用"), QMessageBox::Ok);
        return;
    }

    ui->statusBar->showMessage(tr("打开串口成功"));
}


//关闭串口
void MainWindow::on_actionClose_triggered()
{

    myCom->close();
    delete myCom;
    myCom = NULL;

    ui->sendmsgBtn->setEnabled(false);

    setComboBoxEnabled(true);

    ui->actionOpen->setEnabled(true);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);

    setActionsEnabled(false);

    ui->actionWriteToFile->setChecked(false);
    ui->statusBar->showMessage(tr("串口已经关闭"));
}

//关于
void MainWindow::on_actionAbout_triggered()
{
    aboutdlg.show();
    // 在主窗口中间显示
    int x =this->x() + (this->width() - aboutdlg.width()) / 2;
    int y =this->y() + (this->height() - aboutdlg.height()) / 2;
    aboutdlg.move(x, y);
    ui->statusBar->showMessage(tr("关于Wincom"));
}

//读取数据
void MainWindow::readMyCom()
{
    QByteArray temp = myCom->readAll();
    if(!temp.isEmpty())
    {
        ui->textBrowser->setTextColor(Qt::black);
        if(ui->ccradioButton->isChecked())
        {
            buf = temp;
        }
        else if(ui->chradioButton->isChecked())
        {
            QString str;
            for(int i = 0; i < temp.count(); i++)
            {
                QString s;          //转string，定格式
                s.sprintf("0x%02x, ", (unsigned char)temp.at(i));
                buf += s;
            }
        }

        if(!write2fileName.isEmpty())
        {
            QFile file(write2fileName);
            //如果打开失败则给出提示并退出函数
            if(!file.open(QFile::WriteOnly | QIODevice::Text))
            {   //似乎QFile可以从QIODevice中继承
                QMessageBox::warning(this, tr("写入文件"), tr("打开文件 %1 失败, 无法写入\n%2").arg(write2fileName).arg(file.errorString()), QMessageBox::Ok);
                return;
            }
            QTextStream out(&file);
            out<<buf;
            file.close();
        }

        ui->textBrowser->setText(ui->textBrowser->document()->toPlainText() + buf);
        //ui->textBrowser->setText(s);
        //实现在QTextBrowser末尾显示
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textBrowser->setTextCursor(cursor);

        ui->recvbyteslcdNumber->display(ui->recvbyteslcdNumber->value() + temp.size());
        ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
    }
}

//发送数据
void MainWindow::sendMsg()
{
    QByteArray buf;
    if(ui->sendAsHexcheckBox->isChecked()){
        QString str;
        bool ok;
        char data;
        QStringList list;
        str = ui->sendMsgLineEdit->text();
        list = str.split(" ");
        for(int i = 0; i < list.count(); i++){
            if(list.at(i) == " ")
                continue;
            if(list.at(i).isEmpty())
                continue;
            data = (char)list.at(i).toInt(&ok, 16);
            if(!ok){
                QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
                if(obotimer != NULL)
                    obotimer->stop();
                ui->sendmsgBtn->setText(tr("发送"));
                ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
                return;
            }
            buf.append(data);
        }
    }else{
#if QT_VERSION < 0x050000
        buf = ui->sendMsgLineEdit->text().toAscii();
#else
        buf = ui->sendMsgLineEdit->text().toLocal8Bit();
#endif
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

//发送数据按钮
void MainWindow::on_sendmsgBtn_clicked()
{
    //如果当前正在连续发送数据，暂停发送
    if(ui->sendmsgBtn->text() == tr("暂停")){
        obotimer->stop();
        ui->sendmsgBtn->setText(tr("发送"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
        return;
    }
    //如果发送数据为空，给出提示并返回
    if(ui->sendMsgLineEdit->text().isEmpty()){
        QMessageBox::information(this, tr("提示消息"), tr("没有需要发送的数据"), QMessageBox::Ok);
        return;
    }

    //如果不是连续发送
    if(!ui->obocheckBox->isChecked()){
        ui->sendMsgLineEdit->setFocus();
        //发送数据
        sendMsg();
    }else{ //连续发送
        obotimer->start(obotimerdly);
        ui->sendmsgBtn->setText(tr("暂停"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/pause.png"));
    }
}
//清空记录
void MainWindow::on_clearUpBtn_clicked()
{
    ui->textBrowser->clear();
    ui->statusBar->showMessage(tr("记录已经清空"));
}

//计数器清零
void MainWindow::on_actionClearBytes_triggered()
{
    if(ui->recvbyteslcdNumber->value() == 0){
        QMessageBox::information(this, tr("提示消息"), tr("貌似已经清零了呀:)"), QMessageBox::Ok);
    }else{
        ui->recvbyteslcdNumber->display(0);
        ui->statusBar->showMessage(tr("计数器已经清零"));
    }
}

//单击连续发送checkBox
void MainWindow::on_obocheckBox_clicked()
{
    if(ui->obocheckBox->isChecked()){
        ui->delayspinBox->setEnabled(true);
        //检查是否有数据，如有则启动定时器
        ui->statusBar->showMessage(tr("启用连续发送"));
    }else{
        ui->delayspinBox->setEnabled(false);
        //若定时器已经启动则关闭它
        ui->statusBar->showMessage(tr("停止连续发送"));
    }
}

//保存textBrowser中的内容
void MainWindow::on_actionSave_triggered()
{

    if(ui->textBrowser->toPlainText().isEmpty()){
        QMessageBox::information(this, "提示消息", tr("貌似还没有数据! 您需要在发送编辑框中输入要发送的数据"), QMessageBox::Ok);
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"));
    QFile file(filename);
    //如果用户取消了保存则直接退出函数
    if(file.fileName().isEmpty()){
        return;
    }
    //如果打开失败则给出提示并退出函数
    if(!file.open(QFile::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
        return;
    }
    //写数据到文件
    QTextStream out(&file);
    out<<ui->textBrowser->toPlainText();
    file.close();
    //修改窗口标题为保存文件路径
    setWindowTitle("saved: " + QFileInfo(filename).canonicalFilePath());

}

//退出程序
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//添加串口
void MainWindow::on_actionAdd_triggered()
{
    bool ok = false;
    QString portname;

    portname = QInputDialog::getText(this, tr("添加串口"), tr("设备文件名"), QLineEdit::Normal, 0, &ok);
    if(ok && !portname.isEmpty()){
        ui->portNameComboBox->addItem(portname);
        ui->statusBar->showMessage(tr("添加串口成功"));
    }
}

//调整连续发送时间间隔
void MainWindow::on_delayspinBox_valueChanged(int )
{
    obotimerdly = ui->delayspinBox->value();
}

//载入外部文件
void MainWindow::on_actionLoadfile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("读取文件"), 0, tr("保存为 (*.txt *.log)"));  //添加更多的文件类型
    QFile file(filename);

    //如果取消打开则退出函数
    if(file.fileName().isEmpty()){
        return;
    }

    //如果打开失败则提示并退出函数
    if(!file.open(QFile::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("打开失败"),
                             tr("抱歉! Wincom未能打开此文件, 这可能是由于没有足够的权限造成的. 您可以尝试使用chmod命令修改文件权限."),
                             QMessageBox::Ok);
        return;
    }

    //文件大小超过限制
    if(file.size() > MAX_FILE_SIZE){
        QMessageBox::critical(this, tr("载入失败"), tr("文件大小为 %1 字节, 超过限制大小 10000 字节").arg(file.size()), QMessageBox::Ok);
        return;
    }
    //文件太大时提示是否继续打开
    if(file.size() > TIP_FILE_SIZE){
        if(QMessageBox::question(this, tr("提示消息"), tr("您要打开的文件过大, 这将消耗更多一些的时间,要继续打开么?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){

            return;
        }
    }

    //读取数据并加入到发送数据编辑框
    QByteArray line;
    while(!file.atEnd()){
        line = file.readLine();
        ui->sendMsgLineEdit->setText(ui->sendMsgLineEdit->text() + tr(line));

    }
    file.close();
    ui->statusBar->showMessage(tr("已经成功读取文件中的数据"));
}

//清空串口中的I/O数据
void MainWindow::on_actionCleanPort_triggered()
{
    myCom->flush();
}

//写入文件菜单
void MainWindow::on_actionWriteToFile_triggered()
{
    if(ui->actionWriteToFile->isChecked()){
        QString filename = QFileDialog::getSaveFileName(this, tr("写入文件"), 0, tr("保存为 (*.*)"));  //添加更多的文件类型
        if(filename.isEmpty()){
            ui->actionWriteToFile->setChecked(false);
        }else{
            write2fileName = filename;
            //ui->textBrowser->setEnabled(false);
            ui->actionWriteToFile->setToolTip(tr("停止写入到文件"));
        }
    }else{
        write2fileName.clear();
        //ui->textBrowser->setEnabled(true);
        ui->actionWriteToFile->setToolTip(tr("将读取数据写入到文件"));
    }

}

//newly added
void MainWindow::on_huitupushButton_clicked()
{
    is_huitu = !is_huitu;
    if(is_huitu)
        update->start();
    else
        update->stop();
}

//在定时器中更新图像，绘图不管接收部分，只管画出time和选择的图像
void MainWindow::time_update()
{	
    int i;
    sample_time = (QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0) - init_time;
    if(ui->yawradioButton->isChecked()||ui->pitchradioButton->isChecked()||ui->rollradioButton->isChecked())
    {
        this->initplot123();
        if(ui->yawradioButton->isChecked())
        {
            buf1 = "yaw";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 4),5);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
        if(ui->pitchradioButton->isChecked())
        {
            buf1 = "pitch";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 6),5);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
        if(ui->rollradioButton->isChecked())
        {
            buf1 = "roll";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 5),5);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
    }
    if(ui->exradioButton->isChecked()||ui->eyradioButton->isChecked()||ui->ezradioButton->isChecked())
    {
        this->initplot456();
        if(ui->exradioButton->isChecked())
        {
            buf1 = "ex";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 3),7);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
        if(ui->eyradioButton->isChecked())
        {
            buf1 = "ey";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 3),7);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
        if(ui->ezradioButton->isChecked())
        {
            buf1 = "ez";
            i = buf.indexOf(buf1);
            buf1 = buf.mid((i + 3),7);
            sample_value = buf1.toDouble();
            ui->customPlot->graph(0)->addData(sample_time,sample_value);
            ui->customPlot->graph(0)->removeDataBefore(sample_time - Plot_Count - 1);
            ui->customPlot->xAxis->setRange(sample_time, Plot_Count, Qt::AlignRight);
            ui->customPlot->replot();
        }
    }
}



void MainWindow::on_delayspinBox_editingFinished()
{

}

void MainWindow::on_forwardpushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 a1 01 64 F9";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}



void MainWindow::on_leftpushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 a1 03 64 f7";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_rightpushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 a1 04 64 f6";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_backpushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 a1 02 64 F8";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_stoppushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 01 a2 5d";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_zeropushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 00 00 df";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_thirtypushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 01 2c b2";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_sixtypushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 02 58 85";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_ninetypushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 03 84 58";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_yibaierpushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 04 b0 2b";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_yibaiwupushButton_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 05 dc fe";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_yibaiwupushButton_2_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 06 fe db";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_thirtypushButton_2_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 fe d4 0d";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_sixtypushButton_2_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 fd ab 37";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_ninetypushButton_2_clicked()
{
    QByteArray buf;
    QString str;
    bool ok;
    char data;
    QStringList list;
    str = "55 aa 1e 01 03 20 fc 7c 67";
    list = str.split(" ");
    for(int i = 0; i < list.count(); i++){
        if(list.at(i) == " ")
            continue;
        if(list.at(i).isEmpty())
            continue;
        data = (char)list.at(i).toInt(&ok, 16);
        if(!ok){
            QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
            if(obotimer != NULL)
                obotimer->stop();
            ui->sendmsgBtn->setText(tr("发送"));
            ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
            return;
        }
        buf.append(data);
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("前进"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

