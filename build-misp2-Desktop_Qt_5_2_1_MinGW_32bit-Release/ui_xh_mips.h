/********************************************************************************
** Form generated from reading UI file 'xh_mips.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XH_MIPS_H
#define UI_XH_MIPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XH_mips
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionFind;
    QAction *actionBuild;
    QAction *actionBuild_coe;
    QAction *actionNew;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_2;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu;
    QMenu *menu_R;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *XH_mips)
    {
        if (XH_mips->objectName().isEmpty())
            XH_mips->setObjectName(QStringLiteral("XH_mips"));
        XH_mips->resize(1030, 393);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(XH_mips->sizePolicy().hasHeightForWidth());
        XH_mips->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("YaHei Consolas Hybrid"));
        font.setBold(false);
        font.setWeight(50);
        XH_mips->setFont(font);
        XH_mips->setFocusPolicy(Qt::StrongFocus);
        XH_mips->setLayoutDirection(Qt::LeftToRight);
        XH_mips->setAutoFillBackground(true);
        actionOpen = new QAction(XH_mips);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(XH_mips);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(XH_mips);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionFind = new QAction(XH_mips);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        actionBuild = new QAction(XH_mips);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        actionBuild_coe = new QAction(XH_mips);
        actionBuild_coe->setObjectName(QStringLiteral("actionBuild_coe"));
        actionNew = new QAction(XH_mips);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(XH_mips);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 32)
            tableWidget->setColumnCount(32);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(24, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(25, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(26, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(27, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(28, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(29, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(30, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(31, __qtablewidgetitem31);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem33);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 240, 981, 101));
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setDefaultSectionSize(29);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 981, 214));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(5, -1, 5, -1);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, 5, -1);
        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 220, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 220, 61, 16));
        XH_mips->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(XH_mips);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 23));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_R = new QMenu(menuBar);
        menu_R->setObjectName(QStringLiteral("menu_R"));
        XH_mips->setMenuBar(menuBar);
        statusBar = new QStatusBar(XH_mips);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        XH_mips->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_R->menuAction());
        menu_F->addAction(actionOpen);
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSave_as);
        menu->addAction(actionFind);
        menu_R->addAction(actionBuild);
        menu_R->addAction(actionBuild_coe);

        retranslateUi(XH_mips);

        QMetaObject::connectSlotsByName(XH_mips);
    } // setupUi

    void retranslateUi(QMainWindow *XH_mips)
    {
        XH_mips->setWindowTitle(QApplication::translate("XH_mips", "XH_mips", 0));
        actionOpen->setText(QApplication::translate("XH_mips", "open", 0));
        actionOpen->setShortcut(QApplication::translate("XH_mips", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("XH_mips", "save", 0));
        actionSave->setShortcut(QApplication::translate("XH_mips", "Ctrl+S", 0));
        actionSave_as->setText(QApplication::translate("XH_mips", "save as", 0));
        actionFind->setText(QApplication::translate("XH_mips", "find", 0));
        actionFind->setShortcut(QApplication::translate("XH_mips", "Ctrl+F", 0));
        actionBuild->setText(QApplication::translate("XH_mips", "run by step", 0));
        actionBuild->setShortcut(QApplication::translate("XH_mips", "F7", 0));
        actionBuild_coe->setText(QApplication::translate("XH_mips", "build coe", 0));
        actionBuild_coe->setShortcut(QApplication::translate("XH_mips", "Ctrl+R", 0));
        actionNew->setText(QApplication::translate("XH_mips", "new", 0));
        actionNew->setShortcut(QApplication::translate("XH_mips", "Ctrl+N", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("XH_mips", "0", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("XH_mips", "1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("XH_mips", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("XH_mips", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("XH_mips", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("XH_mips", "5", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("XH_mips", "6", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("XH_mips", "7", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("XH_mips", "8", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("XH_mips", "9", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("XH_mips", "10", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("XH_mips", "11", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("XH_mips", "12", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("XH_mips", "13", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("XH_mips", "14", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("XH_mips", "15", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("XH_mips", "16", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("XH_mips", "17", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("XH_mips", "18", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("XH_mips", "19", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("XH_mips", "20", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("XH_mips", "21", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("XH_mips", "22", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QApplication::translate("XH_mips", "23", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(24);
        ___qtablewidgetitem24->setText(QApplication::translate("XH_mips", "24", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(25);
        ___qtablewidgetitem25->setText(QApplication::translate("XH_mips", "25", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(26);
        ___qtablewidgetitem26->setText(QApplication::translate("XH_mips", "26", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->horizontalHeaderItem(27);
        ___qtablewidgetitem27->setText(QApplication::translate("XH_mips", "27", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->horizontalHeaderItem(28);
        ___qtablewidgetitem28->setText(QApplication::translate("XH_mips", "28", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->horizontalHeaderItem(29);
        ___qtablewidgetitem29->setText(QApplication::translate("XH_mips", "29", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->horizontalHeaderItem(30);
        ___qtablewidgetitem30->setText(QApplication::translate("XH_mips", "30", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->horizontalHeaderItem(31);
        ___qtablewidgetitem31->setText(QApplication::translate("XH_mips", "31", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("XH_mips", "\345\217\230\351\207\217\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("XH_mips", "\346\225\260\346\215\256", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("XH_mips", "\346\261\207\347\274\226\344\273\243\347\240\201", 0)
         << QApplication::translate("XH_mips", "2\350\277\233\345\210\266", 0)
         << QApplication::translate("XH_mips", "16\350\277\233\345\210\266", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("XH_mips", "2\350\277\233\345\210\266", 0)
         << QApplication::translate("XH_mips", "16\350\277\233\345\210\266", 0)
         << QApplication::translate("XH_mips", "\346\261\207\347\274\226\344\273\243\347\240\201", 0)
        );
        label->setText(QApplication::translate("XH_mips", "\350\277\220\350\241\214\345\210\260\350\241\214\346\225\260", 0));
        menu_F->setTitle(QApplication::translate("XH_mips", "\346\226\207\344\273\266(&F)", 0));
        menu->setTitle(QApplication::translate("XH_mips", "\350\260\203\350\257\225(&D)", 0));
        menu_R->setTitle(QApplication::translate("XH_mips", "\350\277\220\350\241\214(&R)", 0));
    } // retranslateUi

};

namespace Ui {
    class XH_mips: public Ui_XH_mips {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XH_MIPS_H
