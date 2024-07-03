/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menuFile_create;
    QAction *menuFile_open;
    QAction *menuFile_save;
    QAction *menuFile_saveAs;
    QAction *menuFile_exit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page_create;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_1d;
    QRadioButton *rbtn_2d;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_ysize;
    QLineEdit *lineEdit_setYSize;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_xsize;
    QLineEdit *lineEdit_setXSize;
    QPushButton *pbt_create;
    QLabel *lbl_statusCreate;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_fill;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_DiapMin;
    QLabel *label_2;
    QLineEdit *lineEdit_DiapMax;
    QPushButton *pbt_FillTable;
    QLabel *lbl_statusFill;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_FindMax;
    QLabel *lbl_FindMin;
    QLabel *lbl_FindMid;
    QPushButton *pbt_clear;
    QSpacerItem *verticalSpacer;
    QWidget *page_sort;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_sort1;
    QLabel *lbl_sort2;
    QVBoxLayout *layout_sort1;
    QRadioButton *rbtn_bubble1;
    QRadioButton *rbtn_gnome1;
    QRadioButton *rbtn_quick1;
    QRadioButton *rbtn_comb1;
    QRadioButton *rbtn_bogo1;
    QVBoxLayout *layout_sort2;
    QRadioButton *rbtn_bubble2;
    QRadioButton *rbtn_gnome2;
    QRadioButton *rbtn_quick2;
    QRadioButton *rbtn_comb2;
    QRadioButton *rbtn_bogo2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_maxIters;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_11;
    QGridLayout *gridLayout;
    QPushButton *pbt_dir1u;
    QPushButton *pbt_dir1l;
    QPushButton *pbt_dir1;
    QPushButton *pbt_dir1d;
    QPushButton *pbt_dir1r;
    QGridLayout *gridLayout_2;
    QPushButton *pbt_dir2u;
    QPushButton *pbt_dir2l;
    QPushButton *pbt_dir2;
    QPushButton *pbt_dir2r;
    QPushButton *pbt_dir2d;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbl_qsorts1;
    QLabel *lbl_qsorts2;
    QLabel *lbl_statusSort;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pbt_sort;
    QWidget *page_dublicates;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pbt_deleteCopy;
    QCheckBox *chBox_autosort;
    QLabel *lbl_countUnic;
    QLabel *lbl_statusDelete;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_search;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pbt_finding;
    QLineEdit *lineEdit_finding;
    QLabel *lbl_finding;
    QPushButton *pbt_findingReset;
    QCheckBox *chBox_colorsDiff;
    QSpacerItem *verticalSpacer_5;
    QTableWidget *table_main;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        menuFile_create = new QAction(MainWindow);
        menuFile_create->setObjectName(QString::fromUtf8("menuFile_create"));
        menuFile_open = new QAction(MainWindow);
        menuFile_open->setObjectName(QString::fromUtf8("menuFile_open"));
        menuFile_save = new QAction(MainWindow);
        menuFile_save->setObjectName(QString::fromUtf8("menuFile_save"));
        menuFile_saveAs = new QAction(MainWindow);
        menuFile_saveAs->setObjectName(QString::fromUtf8("menuFile_saveAs"));
        menuFile_exit = new QAction(MainWindow);
        menuFile_exit->setObjectName(QString::fromUtf8("menuFile_exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(20);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMinimumSize(QSize(350, 0));
        toolBox->setMaximumSize(QSize(350, 16777215));
        toolBox->setAutoFillBackground(false);
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        page_create = new QWidget();
        page_create->setObjectName(QString::fromUtf8("page_create"));
        page_create->setGeometry(QRect(0, 0, 350, 642));
        verticalLayout_4 = new QVBoxLayout(page_create);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbtn_1d = new QRadioButton(page_create);
        rbtn_1d->setObjectName(QString::fromUtf8("rbtn_1d"));
        rbtn_1d->setChecked(false);
        rbtn_1d->setAutoExclusive(true);

        verticalLayout->addWidget(rbtn_1d);

        rbtn_2d = new QRadioButton(page_create);
        rbtn_2d->setObjectName(QString::fromUtf8("rbtn_2d"));
        rbtn_2d->setChecked(true);
        rbtn_2d->setAutoExclusive(true);

        verticalLayout->addWidget(rbtn_2d);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lbl_ysize = new QLabel(page_create);
        lbl_ysize->setObjectName(QString::fromUtf8("lbl_ysize"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_ysize->sizePolicy().hasHeightForWidth());
        lbl_ysize->setSizePolicy(sizePolicy1);
        lbl_ysize->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(lbl_ysize);

        lineEdit_setYSize = new QLineEdit(page_create);
        lineEdit_setYSize->setObjectName(QString::fromUtf8("lineEdit_setYSize"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_setYSize->sizePolicy().hasHeightForWidth());
        lineEdit_setYSize->setSizePolicy(sizePolicy2);
        lineEdit_setYSize->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(lineEdit_setYSize);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_xsize = new QLabel(page_create);
        lbl_xsize->setObjectName(QString::fromUtf8("lbl_xsize"));

        horizontalLayout_5->addWidget(lbl_xsize);

        lineEdit_setXSize = new QLineEdit(page_create);
        lineEdit_setXSize->setObjectName(QString::fromUtf8("lineEdit_setXSize"));

        horizontalLayout_5->addWidget(lineEdit_setXSize);


        verticalLayout_4->addLayout(horizontalLayout_5);

        pbt_create = new QPushButton(page_create);
        pbt_create->setObjectName(QString::fromUtf8("pbt_create"));
        pbt_create->setMinimumSize(QSize(0, 50));

        verticalLayout_4->addWidget(pbt_create);

        lbl_statusCreate = new QLabel(page_create);
        lbl_statusCreate->setObjectName(QString::fromUtf8("lbl_statusCreate"));
        sizePolicy1.setHeightForWidth(lbl_statusCreate->sizePolicy().hasHeightForWidth());
        lbl_statusCreate->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(lbl_statusCreate);

        verticalSpacer_2 = new QSpacerItem(20, 411, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        toolBox->addItem(page_create, QString::fromUtf8("\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265"));
        page_fill = new QWidget();
        page_fill->setObjectName(QString::fromUtf8("page_fill"));
        page_fill->setGeometry(QRect(0, 0, 350, 642));
        verticalLayout_3 = new QVBoxLayout(page_fill);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_DiapMin = new QLineEdit(page_fill);
        lineEdit_DiapMin->setObjectName(QString::fromUtf8("lineEdit_DiapMin"));
        lineEdit_DiapMin->setMaxLength(11);

        horizontalLayout_4->addWidget(lineEdit_DiapMin);

        label_2 = new QLabel(page_fill);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_DiapMax = new QLineEdit(page_fill);
        lineEdit_DiapMax->setObjectName(QString::fromUtf8("lineEdit_DiapMax"));
        lineEdit_DiapMax->setMaxLength(11);

        horizontalLayout_4->addWidget(lineEdit_DiapMax);


        verticalLayout_3->addLayout(horizontalLayout_4);

        pbt_FillTable = new QPushButton(page_fill);
        pbt_FillTable->setObjectName(QString::fromUtf8("pbt_FillTable"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbt_FillTable->sizePolicy().hasHeightForWidth());
        pbt_FillTable->setSizePolicy(sizePolicy3);
        pbt_FillTable->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(pbt_FillTable);

        lbl_statusFill = new QLabel(page_fill);
        lbl_statusFill->setObjectName(QString::fromUtf8("lbl_statusFill"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lbl_statusFill->sizePolicy().hasHeightForWidth());
        lbl_statusFill->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(lbl_statusFill);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbl_FindMax = new QLabel(page_fill);
        lbl_FindMax->setObjectName(QString::fromUtf8("lbl_FindMax"));
        sizePolicy1.setHeightForWidth(lbl_FindMax->sizePolicy().hasHeightForWidth());
        lbl_FindMax->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lbl_FindMax);

        lbl_FindMin = new QLabel(page_fill);
        lbl_FindMin->setObjectName(QString::fromUtf8("lbl_FindMin"));
        sizePolicy1.setHeightForWidth(lbl_FindMin->sizePolicy().hasHeightForWidth());
        lbl_FindMin->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lbl_FindMin);

        lbl_FindMid = new QLabel(page_fill);
        lbl_FindMid->setObjectName(QString::fromUtf8("lbl_FindMid"));
        sizePolicy1.setHeightForWidth(lbl_FindMid->sizePolicy().hasHeightForWidth());
        lbl_FindMid->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lbl_FindMid);


        verticalLayout_3->addLayout(verticalLayout_2);

        pbt_clear = new QPushButton(page_fill);
        pbt_clear->setObjectName(QString::fromUtf8("pbt_clear"));
        sizePolicy3.setHeightForWidth(pbt_clear->sizePolicy().hasHeightForWidth());
        pbt_clear->setSizePolicy(sizePolicy3);
        pbt_clear->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(pbt_clear);

        verticalSpacer = new QSpacerItem(20, 390, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        toolBox->addItem(page_fill, QString::fromUtf8("\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265"));
        page_sort = new QWidget();
        page_sort->setObjectName(QString::fromUtf8("page_sort"));
        page_sort->setGeometry(QRect(0, 0, 351, 625));
        formLayout = new QFormLayout(page_sort);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_sort1 = new QLabel(page_sort);
        lbl_sort1->setObjectName(QString::fromUtf8("lbl_sort1"));
        sizePolicy4.setHeightForWidth(lbl_sort1->sizePolicy().hasHeightForWidth());
        lbl_sort1->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(lbl_sort1);

        lbl_sort2 = new QLabel(page_sort);
        lbl_sort2->setObjectName(QString::fromUtf8("lbl_sort2"));
        sizePolicy4.setHeightForWidth(lbl_sort2->sizePolicy().hasHeightForWidth());
        lbl_sort2->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(lbl_sort2);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        layout_sort1 = new QVBoxLayout();
        layout_sort1->setObjectName(QString::fromUtf8("layout_sort1"));
        rbtn_bubble1 = new QRadioButton(page_sort);
        rbtn_bubble1->setObjectName(QString::fromUtf8("rbtn_bubble1"));
        rbtn_bubble1->setChecked(true);
        rbtn_bubble1->setAutoExclusive(true);

        layout_sort1->addWidget(rbtn_bubble1);

        rbtn_gnome1 = new QRadioButton(page_sort);
        rbtn_gnome1->setObjectName(QString::fromUtf8("rbtn_gnome1"));

        layout_sort1->addWidget(rbtn_gnome1);

        rbtn_quick1 = new QRadioButton(page_sort);
        rbtn_quick1->setObjectName(QString::fromUtf8("rbtn_quick1"));

        layout_sort1->addWidget(rbtn_quick1);

        rbtn_comb1 = new QRadioButton(page_sort);
        rbtn_comb1->setObjectName(QString::fromUtf8("rbtn_comb1"));

        layout_sort1->addWidget(rbtn_comb1);

        rbtn_bogo1 = new QRadioButton(page_sort);
        rbtn_bogo1->setObjectName(QString::fromUtf8("rbtn_bogo1"));

        layout_sort1->addWidget(rbtn_bogo1);


        formLayout->setLayout(1, QFormLayout::LabelRole, layout_sort1);

        layout_sort2 = new QVBoxLayout();
        layout_sort2->setObjectName(QString::fromUtf8("layout_sort2"));
        rbtn_bubble2 = new QRadioButton(page_sort);
        rbtn_bubble2->setObjectName(QString::fromUtf8("rbtn_bubble2"));
        rbtn_bubble2->setChecked(true);

        layout_sort2->addWidget(rbtn_bubble2);

        rbtn_gnome2 = new QRadioButton(page_sort);
        rbtn_gnome2->setObjectName(QString::fromUtf8("rbtn_gnome2"));

        layout_sort2->addWidget(rbtn_gnome2);

        rbtn_quick2 = new QRadioButton(page_sort);
        rbtn_quick2->setObjectName(QString::fromUtf8("rbtn_quick2"));

        layout_sort2->addWidget(rbtn_quick2);

        rbtn_comb2 = new QRadioButton(page_sort);
        rbtn_comb2->setObjectName(QString::fromUtf8("rbtn_comb2"));

        layout_sort2->addWidget(rbtn_comb2);

        rbtn_bogo2 = new QRadioButton(page_sort);
        rbtn_bogo2->setObjectName(QString::fromUtf8("rbtn_bogo2"));

        layout_sort2->addWidget(rbtn_bogo2);


        formLayout->setLayout(1, QFormLayout::FieldRole, layout_sort2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(page_sort);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        horizontalLayout_8->addWidget(label_7);

        lineEdit_maxIters = new QLineEdit(page_sort);
        lineEdit_maxIters->setObjectName(QString::fromUtf8("lineEdit_maxIters"));
        sizePolicy3.setHeightForWidth(lineEdit_maxIters->sizePolicy().hasHeightForWidth());
        lineEdit_maxIters->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(lineEdit_maxIters);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(page_sort);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        horizontalLayout_9->addWidget(label_5);

        label_6 = new QLabel(page_sort);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        horizontalLayout_9->addWidget(label_6);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pbt_dir1u = new QPushButton(page_sort);
        pbt_dir1u->setObjectName(QString::fromUtf8("pbt_dir1u"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pbt_dir1u->sizePolicy().hasHeightForWidth());
        pbt_dir1u->setSizePolicy(sizePolicy5);
        pbt_dir1u->setMinimumSize(QSize(60, 30));
        pbt_dir1u->setMaximumSize(QSize(80, 30));
        pbt_dir1u->setCheckable(false);
        pbt_dir1u->setFlat(false);

        gridLayout->addWidget(pbt_dir1u, 0, 1, 1, 1);

        pbt_dir1l = new QPushButton(page_sort);
        pbt_dir1l->setObjectName(QString::fromUtf8("pbt_dir1l"));
        sizePolicy5.setHeightForWidth(pbt_dir1l->sizePolicy().hasHeightForWidth());
        pbt_dir1l->setSizePolicy(sizePolicy5);
        pbt_dir1l->setMinimumSize(QSize(30, 60));
        pbt_dir1l->setMaximumSize(QSize(30, 80));
        pbt_dir1l->setCheckable(false);
        pbt_dir1l->setFlat(false);

        gridLayout->addWidget(pbt_dir1l, 1, 0, 1, 1);

        pbt_dir1 = new QPushButton(page_sort);
        pbt_dir1->setObjectName(QString::fromUtf8("pbt_dir1"));
        sizePolicy5.setHeightForWidth(pbt_dir1->sizePolicy().hasHeightForWidth());
        pbt_dir1->setSizePolicy(sizePolicy5);
        pbt_dir1->setMinimumSize(QSize(60, 60));
        pbt_dir1->setMaximumSize(QSize(80, 80));
        pbt_dir1->setCheckable(false);
        pbt_dir1->setFlat(false);

        gridLayout->addWidget(pbt_dir1, 1, 1, 1, 1);

        pbt_dir1d = new QPushButton(page_sort);
        pbt_dir1d->setObjectName(QString::fromUtf8("pbt_dir1d"));
        sizePolicy5.setHeightForWidth(pbt_dir1d->sizePolicy().hasHeightForWidth());
        pbt_dir1d->setSizePolicy(sizePolicy5);
        pbt_dir1d->setMinimumSize(QSize(60, 30));
        pbt_dir1d->setMaximumSize(QSize(80, 30));
        pbt_dir1d->setCheckable(false);
        pbt_dir1d->setFlat(false);

        gridLayout->addWidget(pbt_dir1d, 2, 1, 1, 1);

        pbt_dir1r = new QPushButton(page_sort);
        pbt_dir1r->setObjectName(QString::fromUtf8("pbt_dir1r"));
        sizePolicy5.setHeightForWidth(pbt_dir1r->sizePolicy().hasHeightForWidth());
        pbt_dir1r->setSizePolicy(sizePolicy5);
        pbt_dir1r->setMinimumSize(QSize(30, 60));
        pbt_dir1r->setMaximumSize(QSize(30, 80));
        pbt_dir1r->setCheckable(false);
        pbt_dir1r->setFlat(false);

        gridLayout->addWidget(pbt_dir1r, 1, 2, 1, 1);


        horizontalLayout_11->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pbt_dir2u = new QPushButton(page_sort);
        pbt_dir2u->setObjectName(QString::fromUtf8("pbt_dir2u"));
        sizePolicy5.setHeightForWidth(pbt_dir2u->sizePolicy().hasHeightForWidth());
        pbt_dir2u->setSizePolicy(sizePolicy5);
        pbt_dir2u->setMinimumSize(QSize(60, 30));
        pbt_dir2u->setMaximumSize(QSize(80, 30));
        pbt_dir2u->setCheckable(false);
        pbt_dir2u->setFlat(false);

        gridLayout_2->addWidget(pbt_dir2u, 0, 1, 1, 1);

        pbt_dir2l = new QPushButton(page_sort);
        pbt_dir2l->setObjectName(QString::fromUtf8("pbt_dir2l"));
        sizePolicy5.setHeightForWidth(pbt_dir2l->sizePolicy().hasHeightForWidth());
        pbt_dir2l->setSizePolicy(sizePolicy5);
        pbt_dir2l->setMinimumSize(QSize(30, 60));
        pbt_dir2l->setMaximumSize(QSize(30, 80));
        pbt_dir2l->setCheckable(false);
        pbt_dir2l->setFlat(false);

        gridLayout_2->addWidget(pbt_dir2l, 1, 0, 1, 1);

        pbt_dir2 = new QPushButton(page_sort);
        pbt_dir2->setObjectName(QString::fromUtf8("pbt_dir2"));
        sizePolicy5.setHeightForWidth(pbt_dir2->sizePolicy().hasHeightForWidth());
        pbt_dir2->setSizePolicy(sizePolicy5);
        pbt_dir2->setMinimumSize(QSize(60, 60));
        pbt_dir2->setMaximumSize(QSize(80, 80));
        pbt_dir2->setCheckable(false);
        pbt_dir2->setFlat(false);

        gridLayout_2->addWidget(pbt_dir2, 1, 1, 1, 1);

        pbt_dir2r = new QPushButton(page_sort);
        pbt_dir2r->setObjectName(QString::fromUtf8("pbt_dir2r"));
        sizePolicy5.setHeightForWidth(pbt_dir2r->sizePolicy().hasHeightForWidth());
        pbt_dir2r->setSizePolicy(sizePolicy5);
        pbt_dir2r->setMinimumSize(QSize(30, 60));
        pbt_dir2r->setMaximumSize(QSize(30, 80));
        pbt_dir2r->setCheckable(false);
        pbt_dir2r->setFlat(false);

        gridLayout_2->addWidget(pbt_dir2r, 1, 2, 1, 1);

        pbt_dir2d = new QPushButton(page_sort);
        pbt_dir2d->setObjectName(QString::fromUtf8("pbt_dir2d"));
        sizePolicy5.setHeightForWidth(pbt_dir2d->sizePolicy().hasHeightForWidth());
        pbt_dir2d->setSizePolicy(sizePolicy5);
        pbt_dir2d->setMinimumSize(QSize(60, 30));
        pbt_dir2d->setMaximumSize(QSize(80, 30));
        pbt_dir2d->setCheckable(false);
        pbt_dir2d->setFlat(false);

        gridLayout_2->addWidget(pbt_dir2d, 2, 1, 1, 1);


        horizontalLayout_11->addLayout(gridLayout_2);


        formLayout->setLayout(4, QFormLayout::SpanningRole, horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lbl_qsorts1 = new QLabel(page_sort);
        lbl_qsorts1->setObjectName(QString::fromUtf8("lbl_qsorts1"));
        sizePolicy4.setHeightForWidth(lbl_qsorts1->sizePolicy().hasHeightForWidth());
        lbl_qsorts1->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(lbl_qsorts1);

        lbl_qsorts2 = new QLabel(page_sort);
        lbl_qsorts2->setObjectName(QString::fromUtf8("lbl_qsorts2"));
        sizePolicy4.setHeightForWidth(lbl_qsorts2->sizePolicy().hasHeightForWidth());
        lbl_qsorts2->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(lbl_qsorts2);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_10);

        lbl_statusSort = new QLabel(page_sort);
        lbl_statusSort->setObjectName(QString::fromUtf8("lbl_statusSort"));
        sizePolicy4.setHeightForWidth(lbl_statusSort->sizePolicy().hasHeightForWidth());
        lbl_statusSort->setSizePolicy(sizePolicy4);

        formLayout->setWidget(7, QFormLayout::LabelRole, lbl_statusSort);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer_3);

        pbt_sort = new QPushButton(page_sort);
        pbt_sort->setObjectName(QString::fromUtf8("pbt_sort"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pbt_sort->sizePolicy().hasHeightForWidth());
        pbt_sort->setSizePolicy(sizePolicy6);
        pbt_sort->setMinimumSize(QSize(0, 30));
        pbt_sort->setMaximumSize(QSize(16777215, 90));

        formLayout->setWidget(5, QFormLayout::SpanningRole, pbt_sort);

        toolBox->addItem(page_sort, QString::fromUtf8("\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260"));
        page_dublicates = new QWidget();
        page_dublicates->setObjectName(QString::fromUtf8("page_dublicates"));
        page_dublicates->setGeometry(QRect(0, 0, 350, 642));
        verticalLayout_7 = new QVBoxLayout(page_dublicates);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pbt_deleteCopy = new QPushButton(page_dublicates);
        pbt_deleteCopy->setObjectName(QString::fromUtf8("pbt_deleteCopy"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pbt_deleteCopy->sizePolicy().hasHeightForWidth());
        pbt_deleteCopy->setSizePolicy(sizePolicy7);
        pbt_deleteCopy->setMinimumSize(QSize(0, 30));
        pbt_deleteCopy->setMaximumSize(QSize(16777215, 90));

        verticalLayout_7->addWidget(pbt_deleteCopy);

        chBox_autosort = new QCheckBox(page_dublicates);
        chBox_autosort->setObjectName(QString::fromUtf8("chBox_autosort"));
        sizePolicy1.setHeightForWidth(chBox_autosort->sizePolicy().hasHeightForWidth());
        chBox_autosort->setSizePolicy(sizePolicy1);
        chBox_autosort->setMinimumSize(QSize(0, 30));
        chBox_autosort->setChecked(true);

        verticalLayout_7->addWidget(chBox_autosort);

        lbl_countUnic = new QLabel(page_dublicates);
        lbl_countUnic->setObjectName(QString::fromUtf8("lbl_countUnic"));
        sizePolicy1.setHeightForWidth(lbl_countUnic->sizePolicy().hasHeightForWidth());
        lbl_countUnic->setSizePolicy(sizePolicy1);
        lbl_countUnic->setMinimumSize(QSize(0, 30));
        lbl_countUnic->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(lbl_countUnic);

        lbl_statusDelete = new QLabel(page_dublicates);
        lbl_statusDelete->setObjectName(QString::fromUtf8("lbl_statusDelete"));
        sizePolicy1.setHeightForWidth(lbl_statusDelete->sizePolicy().hasHeightForWidth());
        lbl_statusDelete->setSizePolicy(sizePolicy1);
        lbl_statusDelete->setMinimumSize(QSize(0, 30));
        lbl_statusDelete->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(lbl_statusDelete);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        toolBox->addItem(page_dublicates, QString::fromUtf8("\320\224\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213"));
        page_search = new QWidget();
        page_search->setObjectName(QString::fromUtf8("page_search"));
        page_search->setGeometry(QRect(0, 0, 350, 642));
        verticalLayout_8 = new QVBoxLayout(page_search);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        pbt_finding = new QPushButton(page_search);
        pbt_finding->setObjectName(QString::fromUtf8("pbt_finding"));
        sizePolicy7.setHeightForWidth(pbt_finding->sizePolicy().hasHeightForWidth());
        pbt_finding->setSizePolicy(sizePolicy7);
        pbt_finding->setMinimumSize(QSize(0, 30));
        pbt_finding->setMaximumSize(QSize(16777215, 90));

        verticalLayout_8->addWidget(pbt_finding);

        lineEdit_finding = new QLineEdit(page_search);
        lineEdit_finding->setObjectName(QString::fromUtf8("lineEdit_finding"));
        sizePolicy2.setHeightForWidth(lineEdit_finding->sizePolicy().hasHeightForWidth());
        lineEdit_finding->setSizePolicy(sizePolicy2);
        lineEdit_finding->setMinimumSize(QSize(0, 30));

        verticalLayout_8->addWidget(lineEdit_finding);

        lbl_finding = new QLabel(page_search);
        lbl_finding->setObjectName(QString::fromUtf8("lbl_finding"));
        sizePolicy2.setHeightForWidth(lbl_finding->sizePolicy().hasHeightForWidth());
        lbl_finding->setSizePolicy(sizePolicy2);
        lbl_finding->setMinimumSize(QSize(0, 30));

        verticalLayout_8->addWidget(lbl_finding);

        pbt_findingReset = new QPushButton(page_search);
        pbt_findingReset->setObjectName(QString::fromUtf8("pbt_findingReset"));
        sizePolicy.setHeightForWidth(pbt_findingReset->sizePolicy().hasHeightForWidth());
        pbt_findingReset->setSizePolicy(sizePolicy);
        pbt_findingReset->setMinimumSize(QSize(0, 30));
        pbt_findingReset->setMaximumSize(QSize(16777215, 90));

        verticalLayout_8->addWidget(pbt_findingReset);

        chBox_colorsDiff = new QCheckBox(page_search);
        chBox_colorsDiff->setObjectName(QString::fromUtf8("chBox_colorsDiff"));
        sizePolicy2.setHeightForWidth(chBox_colorsDiff->sizePolicy().hasHeightForWidth());
        chBox_colorsDiff->setSizePolicy(sizePolicy2);
        chBox_colorsDiff->setMinimumSize(QSize(0, 30));
        chBox_colorsDiff->setMaximumSize(QSize(16777215, 30));

        verticalLayout_8->addWidget(chBox_colorsDiff);

        verticalSpacer_5 = new QSpacerItem(20, 312, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);

        toolBox->addItem(page_search, QString::fromUtf8("\320\237\320\276\320\270\321\201\320\272"));
        splitter->addWidget(toolBox);
        table_main = new QTableWidget(splitter);
        if (table_main->columnCount() < 1)
            table_main->setColumnCount(1);
        if (table_main->rowCount() < 1)
            table_main->setRowCount(1);
        table_main->setObjectName(QString::fromUtf8("table_main"));
        table_main->setRowCount(1);
        table_main->setColumnCount(1);
        splitter->addWidget(table_main);

        verticalLayout_5->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setOrientation(Qt::Horizontal);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(menuFile_create);
        menu->addAction(menuFile_open);
        menu->addAction(menuFile_save);
        menu->addAction(menuFile_saveAs);
        menu->addSeparator();
        menu->addAction(menuFile_exit);
        toolBar->addAction(menuFile_create);
        toolBar->addAction(menuFile_open);
        toolBar->addAction(menuFile_save);
        toolBar->addAction(menuFile_saveAs);
        toolBar->addAction(menuFile_exit);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        menuFile_create->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        menuFile_create->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        menuFile_open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        menuFile_save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile_saveAs->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
#ifndef QT_NO_SHORTCUT
        menuFile_saveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_SHORTCUT
        menuFile_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        rbtn_1d->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 1D", nullptr));
        rbtn_2d->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 2D", nullptr));
        lbl_ysize->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276 y == </p></body></html>", nullptr));
        lbl_xsize->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276 \321\205 == </p></body></html>", nullptr));
        pbt_create->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        lbl_statusCreate->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\320\265\320\275\320\270 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\276 (\320\274\321\201): ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_create), QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">&lt;= \320\227\320\235\320\220\320\247\320\225\320\235\320\230\320\257 &lt; </p></body></html>", nullptr));
        pbt_FillTable->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        lbl_statusFill->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\320\265\320\275\320\270 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\276 (\320\274\321\201): ", nullptr));
        lbl_FindMax->setText(QApplication::translate("MainWindow", "-\320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275-", nullptr));
        lbl_FindMin->setText(QApplication::translate("MainWindow", "-\320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275-", nullptr));
        lbl_FindMid->setText(QApplication::translate("MainWindow", "-\320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275-", nullptr));
        pbt_clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_fill), QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        lbl_sort1->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270 1:", nullptr));
        lbl_sort2->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270 2:", nullptr));
        rbtn_bubble1->setText(QApplication::translate("MainWindow", "\320\237\321\203\320\267\321\213\321\200\321\214\320\272\320\276\320\274", nullptr));
        rbtn_gnome1->setText(QApplication::translate("MainWindow", "\320\223\320\275\320\276\320\274\320\270\320\272\320\276\320\274", nullptr));
        rbtn_quick1->setText(QApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217 \320\245\320\276\320\260\321\200\320\260", nullptr));
        rbtn_comb1->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\201\320\272\320\276\320\271", nullptr));
        rbtn_bogo1->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\267\321\214\321\217\320\275\320\276\320\271 (\320\235\320\225\320\235\320\220\320\224\320\220!)", nullptr));
        rbtn_bubble2->setText(QApplication::translate("MainWindow", "\320\237\321\203\320\267\321\213\321\200\321\214\320\272\320\276\320\274", nullptr));
        rbtn_gnome2->setText(QApplication::translate("MainWindow", "\320\223\320\275\320\276\320\274\320\270\320\272\320\276\320\274", nullptr));
        rbtn_quick2->setText(QApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217 \320\245\320\276\320\260\321\200\320\260", nullptr));
        rbtn_comb2->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\201\320\272\320\276\320\271", nullptr));
        rbtn_bogo2->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\265\320\267\321\214\321\217\320\275\320\276\320\271 (\320\235\320\225\320\235\320\220\320\224\320\220!)", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\277\320\276\320\277\321\213\321\202\320\276\320\272 \320\276\320\261\320\265\320\267\321\214\321\217\320\275\321\213:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270 </p><p>\320\261\320\276\320\273\321\214\321\210\320\270\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271 1:</p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270 </p><p>\320\261\320\276\320\273\321\214\321\210\320\270\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271 2:</p></body></html>", nullptr));
        pbt_dir1u->setText(QApplication::translate("MainWindow", "UP", nullptr));
        pbt_dir1l->setText(QApplication::translate("MainWindow", "L\n"
"E\n"
"F\n"
"T", nullptr));
        pbt_dir1->setText(QString());
        pbt_dir1d->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        pbt_dir1r->setText(QApplication::translate("MainWindow", "R\n"
"I\n"
"G\n"
"H\n"
"T", nullptr));
        pbt_dir2u->setText(QApplication::translate("MainWindow", "UP", nullptr));
        pbt_dir2l->setText(QApplication::translate("MainWindow", "L\n"
"E\n"
"F\n"
"T", nullptr));
        pbt_dir2->setText(QString());
        pbt_dir2r->setText(QApplication::translate("MainWindow", "R\n"
"I\n"
"G\n"
"H\n"
"T", nullptr));
        pbt_dir2d->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        lbl_qsorts1->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\276\320\272 1:<br/></p></body></html>", nullptr));
        lbl_qsorts2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\276\320\272 2:<br/></p></body></html>", nullptr));
        lbl_statusSort->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\320\265\320\275\320\270 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\276 (\320\274\321\201): ", nullptr));
        pbt_sort->setText(QApplication::translate("MainWindow", "\320\241\320\236\320\240\320\242\320\230\320\240\320\236\320\222\320\232\320\220", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_sort), QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        pbt_deleteCopy->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\321\203\320\261\320\273\320\270", nullptr));
        chBox_autosort->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\260\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270 \320\277\320\265\321\200\320\265\320\264 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265\320\274", nullptr));
        lbl_countUnic->setText(QApplication::translate("MainWindow", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\321\205 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262:", nullptr));
        lbl_statusDelete->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\320\265\320\275\320\270 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\276 (\320\274\321\201): ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_dublicates), QApplication::translate("MainWindow", "\320\224\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213", nullptr));
        pbt_finding->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        lbl_finding->setText(QApplication::translate("MainWindow", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\275\320\260\320\271\320\264\320\265\320\275\320\276:", nullptr));
        pbt_findingReset->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", nullptr));
        chBox_colorsDiff->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\320\276\320\262\320\260\321\217 \320\264\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\320\260\321\206\320\270\321\217 (beta)", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_search), QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
