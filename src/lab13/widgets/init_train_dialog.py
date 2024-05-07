from PySide6.QtWidgets import QDialog, QFileDialog

from src.lab13.models.train_step import TrainStep
from src.lab13.utils.debounce import debounce
from src.lab13.widgets import ui_init_train, train_dialog


class InitTrainDialog(QDialog):
    MESSAGE_NORMAL = "Введите тренировку"
    MESSAGE_INCORRECT = "Формат тренировки неправильный"
    MESSAGE_SAVED = "Тренировка сохранена"
    MESSAGE_YOURE_TYPING = "Вы печатаете..."

    def __init__(self, parent=None):
        super().__init__(parent)
        self.ui = ui_init_train.Ui_Dialog()
        self.ui.setupUi(self)

        self.ui.savetrain.clicked.connect(self.savetrain)
        self.ui.loadtrain.clicked.connect(self.loadtrain)
        self.ui.begintrain.clicked.connect(self.begintrain)
        self.ui.train.textChanged.connect(self.train_text_edit)
        self.ui.message.setText(InitTrainDialog.MESSAGE_NORMAL)

    def train_text_edit(self):
        self.ui.message.setText(InitTrainDialog.MESSAGE_YOURE_TYPING)
        self.train_text_edit_check_syntax()

    @debounce(1)
    def train_text_edit_check_syntax(self):
        if self.check_syntax():
            self.ui.message.setText(InitTrainDialog.MESSAGE_NORMAL)
        else:
            self.ui.message.setText(InitTrainDialog.MESSAGE_INCORRECT)

    def check_syntax(self):
        try:
            train_steps = [TrainStep(" ".join(line.split()[:-1]), int(line.split()[-1])) for line in self.ui.train.toPlainText().strip().splitlines()]

            return train_steps
        except Exception as e:
            return None

    def savetrain(self):
        if not self.check_syntax():
            self.ui.message.setText(InitTrainDialog.MESSAGE_INCORRECT)
            return

        filename = QFileDialog.getSaveFileName(self,
                "Сохранить тренировку", "", "Файлы тренировки (*.train)")

        if len(filename[0]) == 0:
            return

        with open(filename[0], 'w', encoding='utf-8') as f:
            f.write(self.ui.train.toPlainText().strip())

        self.ui.message.setText(InitTrainDialog.MESSAGE_SAVED)

    def loadtrain(self):
        filename = QFileDialog.getOpenFileName(self, "Загрузить тренировку", "", "Файлы тренировки (*.train)")

        if len(filename[0]) == 0:
            return

        with open(filename[0], 'r', encoding='utf-8') as f:
            self.ui.train.setPlainText("".join(list(f.readlines())))

        self.ui.message.setText(InitTrainDialog.MESSAGE_NORMAL)

    def begintrain(self):
        train = self.check_syntax()
        if not train:
            self.ui.message.setText(InitTrainDialog.MESSAGE_INCORRECT)
            return

        self.hide()

        train = train_dialog.TrainDialog(train)
        train.setModal(True)
        train.exec()

        self.show()