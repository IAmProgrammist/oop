from PySide6.QtCore import QTimer
from PySide6.QtWidgets import QDialog

from src.lab13.models.train_step import TrainStep
from src.lab13.widgets import ui_train

import datetime

class TrainDialog(QDialog):
    MESSAGE_READY = 'Приготовиться!'
    MESSAGE_END = 'Тренировка окончена!'
    MESSAGE_END_SEC = 'Вы - молодец!'

    def __init__(self, train, parent=None):
        super().__init__(parent)
        self.ui = ui_train.Ui_Dialog()
        self.ui.setupUi(self)

        self.train = [TrainStep(TrainDialog.MESSAGE_READY, 5)]
        self.train.extend(train)
        self.ui.canceltrain.clicked.connect(self.cancel_train)
        self.start = datetime.datetime.now()
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.tick)
        self.timer.setInterval(100)
        self.timer.start()

    def __del__(self):
        self.timer.stop()

    def cancel_train(self):
        self.timer.stop()
        self.accept()

    def tick(self):
        nowtime = datetime.datetime.now()
        sum_time = 0
        fitting = None

        for item in self.train:
            if datetime.timedelta(seconds=item.time + sum_time) + self.start > nowtime:
                fitting = item
                break
            sum_time += item.time

        if fitting:
            seconds_left = 1 + (datetime.timedelta(seconds=fitting.time + sum_time) + self.start - nowtime).seconds
            self.ui.trainname.setText(fitting.desc)
            self.ui.traintime.setText(f'{seconds_left} сек.')
        else:
            self.ui.trainname.setText(TrainDialog.MESSAGE_END)
            self.ui.traintime.setText(TrainDialog.MESSAGE_END_SEC)
            self.timer.stop()
