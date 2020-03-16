#! /usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import csv
import random
from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QApplication, QWidget, QFileDialog, QInputDialog, QMessageBox
from PyQt5.QtGui import QPainter, QColor, QFont
from ps_window import Ui_MainWindow
import ps_board
import ps_settings
import ps_operation
import subprocess
import sys


class PUSH_SWAP_GUI(QtWidgets.QMainWindow):
    def __init__(self):
        super(PUSH_SWAP_GUI, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.dlg = None
        self.file_path = ""
        self.board = ps_board.StackBoard(self)

        self.ui.action.triggered.connect(self.open_file)
        self.ui.action_2.triggered.connect(self.save_file)
        self.ui.action_3.triggered.connect(self.save_as_file)
        self.ui.action_4.triggered.connect(self.settings)

        self.ui.pushButton.clicked.connect(self.start)
        self.ui.pushButton_2.clicked.connect(self.close_push_swap)

    def open_file(self):
        self.file_path = QFileDialog.getOpenFileName(self, 'Открыть', '/home')[0]
        try:
            with open(self.file_path, "r", errors='ignore', encoding='utf-8') as f:
                self.board.stack_a = list(map(int, f.read().split(' ')))
        except IOError:
            QMessageBox.critical(self, "Error", "IOError")

    def save_file(self):
        try:
            with open(self.file_path, "w", errors='ignore', encoding='utf-8') as f:
                f.write(' '.join(list(map(str, self.board.stack_a))))
        except IOError:
            QMessageBox.critical(self, "Error", "IOError")

    def save_as_file(self):
        self.file_path = QFileDialog.getSaveFileName(self, 'Сохранить как...', '/home')[0]
        self.save_file()

    def start(self):
        ps = subprocess.Popen(["../push_swap", 
            ' '.join(list(map(str, self.board.stack_a)))], stdout=subprocess.PIPE)

        for line in ps.stdout:  
            self.board.list_operations.append(line.rstrip())

        self.board.count_operations = len(self.board.list_operations)
        self.board.timer.timeout.connect(self.board.run)
        self.board.timer.start(100)
        self.board.run()

    def settings(self):
        self.dlg = QtWidgets.QDialog()
        self.dlg_ui = ps_settings.Ui_Dialog()
        self.dlg_ui.setupUi(self.dlg)
        self.dlg.show()

        self.dlg_ui.pushButton.clicked.connect(self.get_settings)
        self.dlg_ui.pushButton_2.clicked.connect(self.dlg.close)

    def combobox_process(self):
        text = self.dlg_ui.comboBox.currentText().lower()
        if text == 'rand':
            try:
                size = int(QInputDialog.getText(self, 'Range', 'Введите диапазон: ')[0])
            except:
                size = ps_operation.DEF_SIZE
            self.board.stack_a = list(range(1, size + 1))
            random.shuffle(self.board.stack_a)
        elif text == 'file':
            self.open_file()
        else:
            nums, ok = QInputDialog.getText(self, 'Input', 'Введите числа: ') 
            if ok:
                self.board.stack_a = list(map(int, nums.split(' ')))
                
        if len(self.board.stack_a) > ps_operation.STACK_MIN_SIZE:
            self.board.stack_size = len(self.board.stack_a)
        self.board.max = max(self.board.stack_a)

    def get_settings(self):
        self.board.clear()
        self.combobox_process()
        self.board.rgb.append(int(self.dlg_ui.lineEdit.text()))
        self.board.rgb.append(int(self.dlg_ui.lineEdit_2.text()))
        self.board.rgb.append(int(self.dlg_ui.lineEdit_3.text()))
        self.dlg.close()

    def close_push_swap(self):
        if self.dlg:
            self.dlg.close()
        self.close()
 

def main():
    app = QtWidgets.QApplication([])
    ps = PUSH_SWAP_GUI()
    ps.show()
    sys.exit(app.exec())

if __name__ == '__main__':
    main()
