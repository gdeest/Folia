/********************************************************************************
** Form generated from reading UI file 'folia.ui'
**
** Created: Sun Jan 15 22:26:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLIA_H
#define UI_FOLIA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FoliaMain
{
public:
    QAction *actionChanger_de_base_de_donn_es;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QTabWidget *tabWidget;
    QWidget *dbTab;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout2;
    QLabel *label;
    QComboBox *classListBox;
    QPushButton *newClassButton;
    QSpacerItem *spacerItem;
    QTabWidget *tabWidget_2;
    QWidget *sampleTab;
    QHBoxLayout *hboxLayout3;
    QHBoxLayout *hboxLayout4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QListView *samplesList;
    QSpacerItem *spacerItem1;
    QToolButton *addSample;
    QGridLayout *gridLayout1;
    QLabel *label_3;
    QTableView *paramsTable;
    QWidget *distTab;
    QHBoxLayout *hboxLayout5;
    QTableView *distTable;
    QWidget *classifyTab;
    QHBoxLayout *hboxLayout6;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout7;
    QLabel *label_4;
    QLabel *fileLabel;
    QSpacerItem *spacerItem2;
    QToolButton *selFileToClassify;
    QRadioButton *radioFront;
    QRadioButton *radioBack;
    QSpacerItem *spacerItem3;
    QPushButton *classifyButton;
    QPushButton *razButton;
    QFrame *line;
    QLabel *image;
    QLabel *idLabel;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FoliaMain)
    {
        if (FoliaMain->objectName().isEmpty())
            FoliaMain->setObjectName(QString::fromUtf8("FoliaMain"));
        FoliaMain->resize(708, 519);
        actionChanger_de_base_de_donn_es = new QAction(FoliaMain);
        actionChanger_de_base_de_donn_es->setObjectName(QString::fromUtf8("actionChanger_de_base_de_donn_es"));
        actionQuitter = new QAction(FoliaMain);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(FoliaMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        dbTab = new QWidget();
        dbTab->setObjectName(QString::fromUtf8("dbTab"));
        hboxLayout1 = new QHBoxLayout(dbTab);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label = new QLabel(dbTab);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout2->addWidget(label);

        classListBox = new QComboBox(dbTab);
        classListBox->setObjectName(QString::fromUtf8("classListBox"));
        classListBox->setMinimumSize(QSize(200, 0));

        hboxLayout2->addWidget(classListBox);

        newClassButton = new QPushButton(dbTab);
        newClassButton->setObjectName(QString::fromUtf8("newClassButton"));

        hboxLayout2->addWidget(newClassButton);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem);


        vboxLayout->addLayout(hboxLayout2);

        tabWidget_2 = new QTabWidget(dbTab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        sampleTab = new QWidget();
        sampleTab->setObjectName(QString::fromUtf8("sampleTab"));
        hboxLayout3 = new QHBoxLayout(sampleTab);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(-1);
        label_2 = new QLabel(sampleTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        samplesList = new QListView(sampleTab);
        samplesList->setObjectName(QString::fromUtf8("samplesList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(samplesList->sizePolicy().hasHeightForWidth());
        samplesList->setSizePolicy(sizePolicy);

        gridLayout->addWidget(samplesList, 1, 0, 1, 2);

        spacerItem1 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 2, 0, 1, 1);

        addSample = new QToolButton(sampleTab);
        addSample->setObjectName(QString::fromUtf8("addSample"));

        gridLayout->addWidget(addSample, 2, 1, 1, 1);


        hboxLayout4->addLayout(gridLayout);

        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label_3 = new QLabel(sampleTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout1->addWidget(label_3, 0, 0, 1, 1);

        paramsTable = new QTableView(sampleTab);
        paramsTable->setObjectName(QString::fromUtf8("paramsTable"));

        gridLayout1->addWidget(paramsTable, 1, 0, 1, 1);


        hboxLayout4->addLayout(gridLayout1);


        hboxLayout3->addLayout(hboxLayout4);

        tabWidget_2->addTab(sampleTab, QString());
        distTab = new QWidget();
        distTab->setObjectName(QString::fromUtf8("distTab"));
        hboxLayout5 = new QHBoxLayout(distTab);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        distTable = new QTableView(distTab);
        distTable->setObjectName(QString::fromUtf8("distTable"));

        hboxLayout5->addWidget(distTable);

        tabWidget_2->addTab(distTab, QString());

        vboxLayout->addWidget(tabWidget_2);


        hboxLayout1->addLayout(vboxLayout);

        tabWidget->addTab(dbTab, QString());
        classifyTab = new QWidget();
        classifyTab->setObjectName(QString::fromUtf8("classifyTab"));
        hboxLayout6 = new QHBoxLayout(classifyTab);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        label_4 = new QLabel(classifyTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        hboxLayout7->addWidget(label_4);

        fileLabel = new QLabel(classifyTab);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));

        hboxLayout7->addWidget(fileLabel);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem2);

        selFileToClassify = new QToolButton(classifyTab);
        selFileToClassify->setObjectName(QString::fromUtf8("selFileToClassify"));

        hboxLayout7->addWidget(selFileToClassify);


        gridLayout2->addLayout(hboxLayout7, 0, 0, 1, 4);

        radioFront = new QRadioButton(classifyTab);
        radioFront->setObjectName(QString::fromUtf8("radioFront"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioFront->sizePolicy().hasHeightForWidth());
        radioFront->setSizePolicy(sizePolicy1);
        radioFront->setMinimumSize(QSize(50, 5));
        radioFront->setChecked(true);

        gridLayout2->addWidget(radioFront, 1, 0, 1, 1);

        radioBack = new QRadioButton(classifyTab);
        radioBack->setObjectName(QString::fromUtf8("radioBack"));
        sizePolicy1.setHeightForWidth(radioBack->sizePolicy().hasHeightForWidth());
        radioBack->setSizePolicy(sizePolicy1);
        radioBack->setMinimumSize(QSize(50, 0));

        gridLayout2->addWidget(radioBack, 1, 1, 1, 2);

        spacerItem3 = new QSpacerItem(381, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacerItem3, 2, 0, 1, 2);

        classifyButton = new QPushButton(classifyTab);
        classifyButton->setObjectName(QString::fromUtf8("classifyButton"));

        gridLayout2->addWidget(classifyButton, 2, 2, 1, 1);

        razButton = new QPushButton(classifyTab);
        razButton->setObjectName(QString::fromUtf8("razButton"));

        gridLayout2->addWidget(razButton, 2, 3, 1, 1);


        vboxLayout1->addLayout(gridLayout2);

        line = new QFrame(classifyTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout1->addWidget(line);

        image = new QLabel(classifyTab);
        image->setObjectName(QString::fromUtf8("image"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy2);

        vboxLayout1->addWidget(image);

        idLabel = new QLabel(classifyTab);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QFont font1;
        font1.setPointSize(24);
        idLabel->setFont(font1);

        vboxLayout1->addWidget(idLabel);


        hboxLayout6->addLayout(vboxLayout1);

        tabWidget->addTab(classifyTab, QString());

        hboxLayout->addWidget(tabWidget);

        FoliaMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FoliaMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 708, 22));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QString::fromUtf8("menu_Fichier"));
        FoliaMain->setMenuBar(menubar);
        statusbar = new QStatusBar(FoliaMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FoliaMain->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(actionChanger_de_base_de_donn_es);
        menu_Fichier->addSeparator();
        menu_Fichier->addAction(actionQuitter);

        retranslateUi(FoliaMain);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FoliaMain);
    } // setupUi

    void retranslateUi(QMainWindow *FoliaMain)
    {
        FoliaMain->setWindowTitle(QApplication::translate("FoliaMain", "Folia", 0, QApplication::UnicodeUTF8));
        actionChanger_de_base_de_donn_es->setText(QApplication::translate("FoliaMain", "Changer de base de donn\303\251es...", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("FoliaMain", "Quitter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FoliaMain", "Classe:", 0, QApplication::UnicodeUTF8));
        newClassButton->setText(QApplication::translate("FoliaMain", "Nouvelle classe", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FoliaMain", "\303\211chantillons:", 0, QApplication::UnicodeUTF8));
        addSample->setText(QApplication::translate("FoliaMain", "Ajouter", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FoliaMain", "Param\303\250tres:", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(sampleTab), QApplication::translate("FoliaMain", "\303\211chantillons", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(distTab), QApplication::translate("FoliaMain", "Distributions", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(dbTab), QApplication::translate("FoliaMain", "Base de donn\303\251es", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FoliaMain", "Fichier:", 0, QApplication::UnicodeUTF8));
        fileLabel->setText(QString());
        selFileToClassify->setText(QApplication::translate("FoliaMain", "...", 0, QApplication::UnicodeUTF8));
        radioFront->setText(QApplication::translate("FoliaMain", "Face", 0, QApplication::UnicodeUTF8));
        radioBack->setText(QApplication::translate("FoliaMain", "Dos", 0, QApplication::UnicodeUTF8));
        classifyButton->setText(QApplication::translate("FoliaMain", "Identifier", 0, QApplication::UnicodeUTF8));
        razButton->setText(QApplication::translate("FoliaMain", "Remize \303\240 z\303\251ro", 0, QApplication::UnicodeUTF8));
        image->setText(QString());
        idLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(classifyTab), QApplication::translate("FoliaMain", "Classification", 0, QApplication::UnicodeUTF8));
        menu_Fichier->setTitle(QApplication::translate("FoliaMain", "&Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FoliaMain: public Ui_FoliaMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLIA_H
