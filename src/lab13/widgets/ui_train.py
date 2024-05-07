# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'train.ui'
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
from PySide6.QtWidgets import (QApplication, QDialog, QLabel, QPushButton,
    QSizePolicy, QVBoxLayout, QWidget)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(600, 400)
        self.verticalLayoutWidget = QWidget(Dialog)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(20, 20, 560, 360))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.trainname = QLabel(self.verticalLayoutWidget)
        self.trainname.setObjectName(u"trainname")
        self.trainname.setLayoutDirection(Qt.LayoutDirection.LeftToRight)
        self.trainname.setStyleSheet(u"font: 700 26pt \"Segoe UI\";")
        self.trainname.setTextFormat(Qt.TextFormat.AutoText)
        self.trainname.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.trainname.setWordWrap(True)

        self.verticalLayout.addWidget(self.trainname)

        self.traintime = QLabel(self.verticalLayoutWidget)
        self.traintime.setObjectName(u"traintime")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.traintime.sizePolicy().hasHeightForWidth())
        self.traintime.setSizePolicy(sizePolicy)
        self.traintime.setStyleSheet(u"font: 16pt \"Segoe UI\";")
        self.traintime.setAlignment(Qt.AlignmentFlag.AlignHCenter|Qt.AlignmentFlag.AlignTop)

        self.verticalLayout.addWidget(self.traintime)

        self.canceltrain = QPushButton(self.verticalLayoutWidget)
        self.canceltrain.setObjectName(u"canceltrain")
        sizePolicy1 = QSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.canceltrain.sizePolicy().hasHeightForWidth())
        self.canceltrain.setSizePolicy(sizePolicy1)
        self.canceltrain.setLayoutDirection(Qt.LayoutDirection.LeftToRight)
        self.canceltrain.setAutoDefault(True)
        self.canceltrain.setFlat(False)

        self.verticalLayout.addWidget(self.canceltrain, 0, Qt.AlignmentFlag.AlignRight)


        self.retranslateUi(Dialog)

        self.canceltrain.setDefault(False)


        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.trainname.setText(QCoreApplication.translate("Dialog", u"\u0422\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0430 \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0430 \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0430", None))
        self.traintime.setText(QCoreApplication.translate("Dialog", u"30 \u0441\u0435\u043a.", None))
        self.canceltrain.setText(QCoreApplication.translate("Dialog", u"\u041e\u0442\u043c\u0435\u043d\u0438\u0442\u044c \u0442\u0440\u0435\u043d\u0438\u0440\u043e\u0432\u043a\u0443", None))
    # retranslateUi

