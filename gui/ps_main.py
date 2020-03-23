#! /usr/bin/python3
# -*- coding: utf-8 -*-

from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtWidgets import QApplication, QWidget, QFileDialog, QInputDialog, QMessageBox
from PyQt5.QtGui import QPainter, QColor, QFont, QColor, QPalette
from ps_window import Ui_MainWindow
import ps_themes
import ps_board
import ps_settings
import ps_operation
import subprocess
import random
import sys
import csv


class PUSH_SWAP_GUI(QtWidgets.QMainWindow):
    def __init__(self):
        super(PUSH_SWAP_GUI, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.board = ps_board.StackBoard(self)

        # def theme
        self.CURRENT_THEME_WINDOW = ps_themes.DARK_WINDOW 
        self.CURRENT_THEME_FRAME  = ps_themes.DARK_FRAME
        self.CURRENT_THEME_BUTTON = ps_themes.DARK_BUTTON
        self.CURRENT_THEME_LINE   = ps_themes.DARK_LINE
        self.set_theme('QMainWindow')

        self.dlg = None
        self.file_path = ""

        self.ui.action.triggered.connect(self.open_file)
        self.ui.action_2.triggered.connect(self.save_file)
        self.ui.action_3.triggered.connect(self.save_as_file)
        self.ui.action_4.triggered.connect(self.settings)
        self.ui.pushButton.clicked.connect(self.start)
        self.ui.pushButton_2.clicked.connect(self.close_ps)

    def set_theme(self, name_window):
        if name_window == 'QMainWindow':
            self.setStyleSheet(self.CURRENT_THEME_WINDOW % (name_window))
            self.ui.pushButton.setStyleSheet(self.CURRENT_THEME_BUTTON)
            self.ui.pushButton_2.setStyleSheet(self.CURRENT_THEME_BUTTON)

            p = self.board.palette()
            p.setColor(QPalette.Window, QColor(*self.CURRENT_THEME_FRAME))
            self.board.setAutoFillBackground(True)
            self.board.setPalette(p)
        else:
            self.dlg.setStyleSheet(self.CURRENT_THEME_WINDOW % (name_window))
            self.dlg_ui.lineEdit.setStyleSheet(self.CURRENT_THEME_LINE)
            self.dlg_ui.lineEdit_2.setStyleSheet(self.CURRENT_THEME_LINE)
            self.dlg_ui.lineEdit_3.setStyleSheet(self.CURRENT_THEME_LINE)
            self.dlg_ui.pushButton.setStyleSheet(self.CURRENT_THEME_BUTTON)
            self.dlg_ui.pushButton_2.setStyleSheet(self.CURRENT_THEME_BUTTON)
            self.dlg_ui.pushButton_3.setStyleSheet(self.CURRENT_THEME_BUTTON)

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
        self.set_theme('QDialog')
        self.dlg.show()

        self.dlg_ui.pushButton_3.clicked.connect(self.get_image)
        self.dlg_ui.pushButton.clicked.connect(self.get_settings)
        self.dlg_ui.pushButton_2.clicked.connect(self.dlg.close)

    def get_image(self):
        self.img_path = QFileDialog.getOpenFileName(self, 'Сохранить как...', '/home')[0]
        self.board.image = QtGui.QImage(self.img_path)

    def get_fill_stack_mode(self):
        mode = self.dlg_ui.comboBox.currentText().lower()
        if mode == 'rand':
            try:
                size = int(QInputDialog.getText(self, 'Range', 'Введите диапазон: ')[0])
            except:
                size = ps_operation.DEF_SIZE
            self.board.stack_a = list(range(1, size + 1))
            random.shuffle(self.board.stack_a)
        elif mode == 'file':
            self.open_file()
        else:
            nums, ok = QInputDialog.getText(self, 'Input', 'Введите числа: ') 
            if ok:
                self.board.stack_a = list(map(int, nums.split(' ')))
                
        self.board.sort_stack_a = self.board.stack_a.copy()
        self.board.sort_stack_a.sort()
        if len(self.board.stack_a) > ps_operation.STACK_MIN_SIZE:
            self.board.stack_size = len(self.board.stack_a)
        self.board.max = max(self.board.stack_a)

    def get_theme(self):
        theme = self.dlg_ui.comboBox_2.currentText().lower()

        if theme == 'dark':
            self.CURRENT_THEME_WINDOW = ps_themes.DARK_WINDOW 
            self.CURRENT_THEME_FRAME  = ps_themes.DARK_FRAME
            self.CURRENT_THEME_BUTTON = ps_themes.DARK_BUTTON
            self.CURRENT_THEME_LINE   = ps_themes.DARK_LINE
        elif theme == 'blue':
            self.CURRENT_THEME_WINDOW = ps_themes.BLUE_WINDOW 
            self.CURRENT_THEME_FRAME  = ps_themes.BLUE_FRAME
            self.CURRENT_THEME_BUTTON = ps_themes.BLUE_BUTTON
            self.CURRENT_THEME_LINE   = ps_themes.BLUE_LINE
        elif theme == 'green':
            self.CURRENT_THEME_WINDOW = ps_themes.GREEN_WINDOW 
            self.CURRENT_THEME_FRAME  = ps_themes.GREEN_FRAME
            self.CURRENT_THEME_BUTTON = ps_themes.GREEN_BUTTON
            self.CURRENT_THEME_LINE   = ps_themes.GREEN_LINE
        self.set_theme('QMainWindow')


    def get_settings(self):
        self.board.clear()
        self.get_fill_stack_mode()
        self.get_theme()
        self.board.rgb.append(int(self.dlg_ui.lineEdit.text()))
        self.board.rgb.append(int(self.dlg_ui.lineEdit_2.text()))
        self.board.rgb.append(int(self.dlg_ui.lineEdit_3.text()))
        self.dlg.close()

    def close_ps(self):
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
