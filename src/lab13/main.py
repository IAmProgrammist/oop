import sys

from PySide6.QtWidgets import QApplication

from widgets.init_train_dialog import InitTrainDialog

if __name__ == "__main__":
    app = QApplication(sys.argv)
    dialog = InitTrainDialog()
    dialog.show()
    sys.exit(app.exec())
