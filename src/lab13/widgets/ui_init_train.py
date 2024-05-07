# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'init_train.ui'
##
## Created by: Qt User Interface Compiler version 6.7.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QDialog, QHBoxLayout, QLabel,
    QPlainTextEdit, QPushButton, QSizePolicy, QVBoxLayout,
    QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(480, 640)
        self.verticalLayoutWidget = QWidget(Dialog)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(20, 20, 440, 600))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.message = QLabel(self.verticalLayoutWidget)
        self.message.setObjectName(u"message")

        self.verticalLayout.addWidget(self.message)

        self.train = QPlainTextEdit(self.verticalLayoutWidget)
        self.train.setObjectName(u"train")

        self.verticalLayout.addWidget(self.train)

        self.begintrain = QPushButton(self.verticalLayoutWidget)
        self.begintrain.setObjectName(u"begintrain")

        self.verticalLayout.addWidget(self.begintrain)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.savetrain = QPushButton(self.verticalLayoutWidget)
        self.savetrain.setObjectName(u"savetrain")

        self.horizontalLayout.addWidget(self.savetrain)

        self.loadtrain = QPushButton(self.verticalLayoutWidget)
        self.loadtrain.setObjectName(u"loadtrain")

        self.horizontalLayout.addWidget(self.loadtrain)


        self.verticalLayout.addLayout(self.horizontalLayout)


        self.retranslateUi(Dialog)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.message.setText(QCoreApplication.translate("Dialog", u"TextLabel", None))
        self.begintrain.setText(QCoreApplication.translate("Dialog", u"\u041d\u0430\u0447\u0430\u0442\u044c \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0443", None))
        self.savetrain.setText(QCoreApplication.translate("Dialog", u"\u0421\u043e\u0445\u0440\u0430\u043d\u0438\u0442\u044c \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0443", None))
        self.loadtrain.setText(QCoreApplication.translate("Dialog", u"\u0417\u0430\u0433\u0440\u0443\u0437\u0438\u0442\u044c \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0443", None))
    # retranslateUi

