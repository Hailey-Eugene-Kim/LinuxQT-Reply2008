/********************************************************************************
** Form generated from reading UI file 'playerdialog.ui'
**
** Created: Thu Apr 7 10:04:22 2022
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERDIALOG_H
#define UI_PLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PlayerDialog
{
public:

    void setupUi(QDialog *PlayerDialog)
    {
        if (PlayerDialog->objectName().isEmpty())
            PlayerDialog->setObjectName(QString::fromUtf8("PlayerDialog"));
        PlayerDialog->resize(400, 300);

        retranslateUi(PlayerDialog);

        QMetaObject::connectSlotsByName(PlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerDialog)
    {
        PlayerDialog->setWindowTitle(QApplication::translate("PlayerDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlayerDialog: public Ui_PlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERDIALOG_H
