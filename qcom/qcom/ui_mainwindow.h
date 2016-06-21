/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionClearBytes;
    QAction *actionLoadfile;
    QAction *actionCleanPort;
    QAction *actionWriteToFile;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *portNameComboBox;
    QLabel *label_2;
    QComboBox *baudRateComboBox;
    QLabel *label_3;
    QComboBox *dataBitsComboBox;
    QLabel *label_4;
    QComboBox *parityComboBox;
    QLabel *label_5;
    QComboBox *stopBitsComboBox;
    QLabel *label_6;
    QSpinBox *delayspinBox;
    QCheckBox *obocheckBox;
    QPushButton *huitupushButton;
    QLabel *label_7;
    QRadioButton *yawradioButton;
    QRadioButton *pitchradioButton;
    QRadioButton *rollradioButton;
    QRadioButton *exradioButton;
    QRadioButton *eyradioButton;
    QRadioButton *ezradioButton;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *sendAsHexcheckBox;
    QLineEdit *sendMsgLineEdit;
    QPushButton *sendmsgBtn;
    QGroupBox *groupBox_2;
    QFrame *frame_3;
    QRadioButton *ccradioButton;
    QRadioButton *chradioButton;
    QLCDNumber *recvbyteslcdNumber;
    QPushButton *clearUpBtn;
    QTextBrowser *textBrowser;
    QCustomPlot *customPlot;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(869, 707);
        MainWindow->setMinimumSize(QSize(820, 580));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QLatin1String("QDialog{background:rgb(229, 255, 239)}\n"
"QStatusBar{background:url(:/images/header.bmp)}\n"
"QPushButton{background:url(:/images/header.bmp)}\n"
"QLCDNumber{background:url(:/images/lcd.bmp)}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        MainWindow->setIconSize(QSize(16, 16));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->setAnimated(true);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/mesage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionClearBytes = new QAction(MainWindow);
        actionClearBytes->setObjectName(QStringLiteral("actionClearBytes"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/clearbytes.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearBytes->setIcon(icon6);
        actionLoadfile = new QAction(MainWindow);
        actionLoadfile->setObjectName(QStringLiteral("actionLoadfile"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/loadfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadfile->setIcon(icon7);
        actionCleanPort = new QAction(MainWindow);
        actionCleanPort->setObjectName(QStringLiteral("actionCleanPort"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/cleanport.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCleanPort->setIcon(icon8);
        actionWriteToFile = new QAction(MainWindow);
        actionWriteToFile->setObjectName(QStringLiteral("actionWriteToFile"));
        actionWriteToFile->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/write2file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWriteToFile->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 124, 561));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setFlat(false);
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        portNameComboBox = new QComboBox(groupBox);
        portNameComboBox->setObjectName(QStringLiteral("portNameComboBox"));
        portNameComboBox->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::SpanningRole, portNameComboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        baudRateComboBox = new QComboBox(groupBox);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, baudRateComboBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        dataBitsComboBox = new QComboBox(groupBox);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, dataBitsComboBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        parityComboBox = new QComboBox(groupBox);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        formLayout->setWidget(7, QFormLayout::SpanningRole, parityComboBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        stopBitsComboBox = new QComboBox(groupBox);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));

        formLayout->setWidget(9, QFormLayout::SpanningRole, stopBitsComboBox);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_6);

        delayspinBox = new QSpinBox(groupBox);
        delayspinBox->setObjectName(QStringLiteral("delayspinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(delayspinBox->sizePolicy().hasHeightForWidth());
        delayspinBox->setSizePolicy(sizePolicy1);
        delayspinBox->setMinimum(10);
        delayspinBox->setMaximum(5000);
        delayspinBox->setValue(500);

        formLayout->setWidget(11, QFormLayout::LabelRole, delayspinBox);

        obocheckBox = new QCheckBox(groupBox);
        obocheckBox->setObjectName(QStringLiteral("obocheckBox"));

        formLayout->setWidget(12, QFormLayout::LabelRole, obocheckBox);

        huitupushButton = new QPushButton(groupBox);
        huitupushButton->setObjectName(QStringLiteral("huitupushButton"));

        formLayout->setWidget(13, QFormLayout::LabelRole, huitupushButton);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        formLayout->setWidget(14, QFormLayout::LabelRole, label_7);

        yawradioButton = new QRadioButton(groupBox);
        yawradioButton->setObjectName(QStringLiteral("yawradioButton"));

        formLayout->setWidget(15, QFormLayout::LabelRole, yawradioButton);

        pitchradioButton = new QRadioButton(groupBox);
        pitchradioButton->setObjectName(QStringLiteral("pitchradioButton"));

        formLayout->setWidget(16, QFormLayout::LabelRole, pitchradioButton);

        rollradioButton = new QRadioButton(groupBox);
        rollradioButton->setObjectName(QStringLiteral("rollradioButton"));

        formLayout->setWidget(17, QFormLayout::LabelRole, rollradioButton);

        exradioButton = new QRadioButton(groupBox);
        exradioButton->setObjectName(QStringLiteral("exradioButton"));

        formLayout->setWidget(18, QFormLayout::LabelRole, exradioButton);

        eyradioButton = new QRadioButton(groupBox);
        eyradioButton->setObjectName(QStringLiteral("eyradioButton"));

        formLayout->setWidget(19, QFormLayout::LabelRole, eyradioButton);

        ezradioButton = new QRadioButton(groupBox);
        ezradioButton->setObjectName(QStringLiteral("ezradioButton"));

        formLayout->setWidget(20, QFormLayout::LabelRole, ezradioButton);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(130, 500, 711, 60));
        groupBox_4->setStyleSheet(QStringLiteral(""));
        groupBox_4->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendAsHexcheckBox = new QCheckBox(groupBox_4);
        sendAsHexcheckBox->setObjectName(QStringLiteral("sendAsHexcheckBox"));

        horizontalLayout->addWidget(sendAsHexcheckBox);

        sendMsgLineEdit = new QLineEdit(groupBox_4);
        sendMsgLineEdit->setObjectName(QStringLiteral("sendMsgLineEdit"));
        sendMsgLineEdit->setMaxLength(10000);
        sendMsgLineEdit->setDragEnabled(false);

        horizontalLayout->addWidget(sendMsgLineEdit);

        sendmsgBtn = new QPushButton(groupBox_4);
        sendmsgBtn->setObjectName(QStringLiteral("sendmsgBtn"));
        sendmsgBtn->setMinimumSize(QSize(0, 23));
        sendmsgBtn->setMaximumSize(QSize(100, 23));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendmsgBtn->setIcon(icon10);
        sendmsgBtn->setAutoDefault(false);

        horizontalLayout->addWidget(sendmsgBtn);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(122, 11, 741, 491));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setStyleSheet(QStringLiteral(""));
        groupBox_2->setFlat(true);
        frame_3 = new QFrame(groupBox_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(11, 26, 721, 49));
        frame_3->setStyleSheet(QStringLiteral(""));
        frame_3->setFrameShape(QFrame::WinPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(1);
        frame_3->setMidLineWidth(0);
        ccradioButton = new QRadioButton(frame_3);
        ccradioButton->setObjectName(QStringLiteral("ccradioButton"));
        ccradioButton->setGeometry(QRect(13, 15, 117, 19));
        ccradioButton->setChecked(true);
        chradioButton = new QRadioButton(frame_3);
        chradioButton->setObjectName(QStringLiteral("chradioButton"));
        chradioButton->setGeometry(QRect(137, 15, 147, 19));
        recvbyteslcdNumber = new QLCDNumber(frame_3);
        recvbyteslcdNumber->setObjectName(QStringLiteral("recvbyteslcdNumber"));
        recvbyteslcdNumber->setGeometry(QRect(500, 10, 64, 23));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(recvbyteslcdNumber->sizePolicy().hasHeightForWidth());
        recvbyteslcdNumber->setSizePolicy(sizePolicy3);
        recvbyteslcdNumber->setStyleSheet(QStringLiteral(""));
        clearUpBtn = new QPushButton(frame_3);
        clearUpBtn->setObjectName(QStringLiteral("clearUpBtn"));
        clearUpBtn->setGeometry(QRect(580, 10, 93, 23));
        clearUpBtn->setMinimumSize(QSize(0, 23));
        clearUpBtn->setMaximumSize(QSize(100, 23));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearUpBtn->setIcon(icon11);
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 80, 721, 141));
        customPlot = new QCustomPlot(groupBox_2);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 230, 721, 251));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 580, 851, 51));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 821, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setMaximumSize(QSize(16777215, 55));
        QFont font1;
        font1.setPointSize(9);
        mainToolBar->setFont(font1);
        mainToolBar->setCursor(QCursor(Qt::PointingHandCursor));
        mainToolBar->setFocusPolicy(Qt::StrongFocus);
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(20, 20));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionAdd);
        menu->addSeparator();
        menu->addAction(actionOpen);
        menu->addAction(actionClose);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu->addAction(actionLoadfile);
        menu->addAction(actionWriteToFile);
        menu->addSeparator();
        menu->addAction(actionClearBytes);
        menu->addAction(actionCleanPort);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionLoadfile);
        mainToolBar->addAction(actionWriteToFile);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClearBytes);
        mainToolBar->addAction(actionCleanPort);

        retranslateUi(MainWindow);

        baudRateComboBox->setCurrentIndex(12);
        dataBitsComboBox->setCurrentIndex(3);
        sendmsgBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCom\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213 1.0", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAdd->setStatusTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionClose->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Wincom", 0));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216Wincom", 0));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionClearBytes->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
#ifndef QT_NO_TOOLTIP
        actionClearBytes->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearBytes->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_STATUSTIP
        actionLoadfile->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionLoadfile->setToolTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionLoadfile->setStatusTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_STATUSTIP
        actionCleanPort->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionCleanPort->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCleanPort->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionWriteToFile->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionWriteToFile->setToolTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionWriteToFile->setStatusTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        baudRateComboBox->clear();
        baudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", 0)
         << QApplication::translate("MainWindow", "75", 0)
         << QApplication::translate("MainWindow", "110", 0)
         << QApplication::translate("MainWindow", "134", 0)
         << QApplication::translate("MainWindow", "150", 0)
         << QApplication::translate("MainWindow", "200", 0)
         << QApplication::translate("MainWindow", "300", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "1800", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "14400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "56000", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "76800", 0)
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "128000", 0)
         << QApplication::translate("MainWindow", "256000", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        dataBitsComboBox->clear();
        dataBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        parityComboBox->clear();
        parityComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", 0)
         << QApplication::translate("MainWindow", "\345\245\207", 0)
         << QApplication::translate("MainWindow", "\345\201\266", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        stopBitsComboBox->clear();
        stopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "1.5", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "\351\227\264\351\232\224(\346\257\253\347\247\222)", 0));
        obocheckBox->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\217\221\351\200\201", 0));
        huitupushButton->setText(QApplication::translate("MainWindow", "\347\273\230\345\233\276", 0));
        label_7->setText(QApplication::translate("MainWindow", "\347\273\230\345\233\276\351\200\211\346\213\251", 0));
        yawradioButton->setText(QApplication::translate("MainWindow", "yaw", 0));
        pitchradioButton->setText(QApplication::translate("MainWindow", "pitch", 0));
        rollradioButton->setText(QApplication::translate("MainWindow", "roll", 0));
        exradioButton->setText(QApplication::translate("MainWindow", "ex", 0));
        eyradioButton->setText(QApplication::translate("MainWindow", "ey", 0));
        ezradioButton->setText(QApplication::translate("MainWindow", "ez", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        sendAsHexcheckBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\345\217\221\351\200\201\346\225\260\346\215\256\357\274\210\351\273\230\350\256\244\344\270\272\345\255\227\347\254\246\346\226\271\345\274\217\357\274\211</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendAsHexcheckBox->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        sendmsgBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        ccradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\255\227\347\254\246\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        ccradioButton->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\345\275\242\345\274\217\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        chradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        chradioButton->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\275\242\345\274\217\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        recvbyteslcdNumber->setToolTip(QApplication::translate("MainWindow", "\345\267\262\346\216\245\346\224\266\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        clearUpBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\240\207\345\277\227", 0));
        label_8->setText(QApplication::translate("MainWindow", "Comdebug && serial ploter used by robot,Based on oter.com's qcom.               ZSL.2015.12.22", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&C)", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
