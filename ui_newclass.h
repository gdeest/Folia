/********************************************************************************
** Form generated from reading UI file 'newclass.ui'
**
** Created: Sun Jan 15 22:26:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCLASS_H
#define UI_NEWCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewClass
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLineEdit *className;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewClass)
    {
        if (NewClass->objectName().isEmpty())
            NewClass->setObjectName(QString::fromUtf8("NewClass"));
        NewClass->resize(186, 121);
        hboxLayout = new QHBoxLayout(NewClass);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label = new QLabel(NewClass);
        label->setObjectName(QString::fromUtf8("label"));

        vboxLayout->addWidget(label);

        className = new QLineEdit(NewClass);
        className->setObjectName(QString::fromUtf8("className"));
        className->setWindowModality(Qt::ApplicationModal);

        vboxLayout->addWidget(className);

        buttonBox = new QDialogButtonBox(NewClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        hboxLayout->addLayout(vboxLayout);


        retranslateUi(NewClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewClass);
    } // setupUi

    void retranslateUi(QDialog *NewClass)
    {
        NewClass->setWindowTitle(QApplication::translate("NewClass", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewClass", "Nom de la classe:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewClass: public Ui_NewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCLASS_H
