/********************************************************************************
** Form generated from reading UI file 'newsample.ui'
**
** Created: Sun Jan 15 22:26:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSAMPLE_H
#define UI_NEWSAMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSample
{
public:
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *frontList;
    QToolButton *selFront;
    QSpacerItem *spacerItem;
    QGridLayout *gridLayout1;
    QLabel *label_2;
    QListWidget *backList;
    QToolButton *selBack;
    QSpacerItem *spacerItem1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewSample)
    {
        if (NewSample->objectName().isEmpty())
            NewSample->setObjectName(QString::fromUtf8("NewSample"));
        NewSample->resize(604, 508);
        vboxLayout = new QVBoxLayout(NewSample);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NewSample);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        frontList = new QListWidget(NewSample);
        frontList->setObjectName(QString::fromUtf8("frontList"));

        gridLayout->addWidget(frontList, 1, 0, 2, 1);

        selFront = new QToolButton(NewSample);
        selFront->setObjectName(QString::fromUtf8("selFront"));

        gridLayout->addWidget(selFront, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 101, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 2, 1, 1, 1);


        vboxLayout1->addLayout(gridLayout);

        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label_2 = new QLabel(NewSample);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout1->addWidget(label_2, 0, 0, 1, 2);

        backList = new QListWidget(NewSample);
        backList->setObjectName(QString::fromUtf8("backList"));

        gridLayout1->addWidget(backList, 1, 0, 2, 1);

        selBack = new QToolButton(NewSample);
        selBack->setObjectName(QString::fromUtf8("selBack"));

        gridLayout1->addWidget(selBack, 1, 1, 1, 1);

        spacerItem1 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem1, 2, 1, 1, 1);


        vboxLayout1->addLayout(gridLayout1);

        buttonBox = new QDialogButtonBox(NewSample);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout1->addWidget(buttonBox);


        vboxLayout->addLayout(vboxLayout1);


        retranslateUi(NewSample);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewSample, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewSample, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewSample);
    } // setupUi

    void retranslateUi(QDialog *NewSample)
    {
        NewSample->setWindowTitle(QApplication::translate("NewSample", "Ajouter de nouveaux \303\251chantillons", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewSample", "\303\211chantillons de face:", 0, QApplication::UnicodeUTF8));
        selFront->setText(QApplication::translate("NewSample", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewSample", "\303\211chantillons de dos:", 0, QApplication::UnicodeUTF8));
        selBack->setText(QApplication::translate("NewSample", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewSample: public Ui_NewSample {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSAMPLE_H
