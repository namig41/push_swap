import random
from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtWidgets import QMessageBox
import ps_operation
from ps_operation import PS_Operation
import time

class StackBoard(QtWidgets.QWidget):
    def __init__(self, parent):
        super(StackBoard, self).__init__(parent)
        self.setGeometry(QtCore.QRect(30, 30, 600, 630))

        self.setAutoFillBackground(True)
        p = self.palette()
        p.setColor(self.backgroundRole(), QtGui.QColor(43, 35, 35))
        self.setPalette(p)

        self.rgb = []
        self.stack_a = []
        self.stack_b = []
        self.list_operations = []
        self.w = self.size().width()
        self.h = self.size().height()
        self.stack_size = ps_operation.STACK_MIN_SIZE
        self.timer = QtCore.QTimer(self)

    def paintEvent(self, e):
        paint = QtGui.QPainter()

        paint.begin(self)
        self.draw_stack(paint)
        paint.end()

    def draw_stack(self, paint):
        k = self.h // self.stack_size;

        print(k)
        paint.setBrush(QtGui.QColor(*self.rgb, 160))
        for i in range(self.stack_size):
            if i < len(self.stack_a):
                paint.drawRect(0, i * k, 
                        self.stack_a[len(self.stack_a) - i - 1] / max(self.stack_a) * (self.w >> 1), k)
            if i < len(self.stack_b):
                paint.drawRect(self.w, i * k, 
                        -self.stack_b[len(self.stack_b) - i - 1] / max(self.stack_b) * (self.w >> 1), k)

    def run(self):
        if len(self.list_operations) == 0:
            self.timer.stop()
            QMessageBox.information(self, "Результат", "Количество операций: " + str(self.count_operations))
            return 

        i = self.list_operations.pop(0) 
        if i == b'pb':
            PS_Operation.ph(self.stack_b, self.stack_a)
        elif i == b'pa':
            PS_Operation.ph(self.stack_a, self.stack_b)
        elif i == b'ss':
            PS_Operation.ss(self.stack_a, self.stack_b)
        elif i == b'sa':
            PS_Operation.sx(self.stack_a)
        elif i == b'sb':
            PS_Operation.sx(self.stack_b)
        elif i == b'rr':
            PS_Operation.rr(self.stack_a, self.stack_b)
        elif i == b'ra':
            PS_Operation.rx(self.stack_a)
        elif i == b'rb':
            PS_Operation.rx(self.stack_b)
        elif i == b'rrr':
            PS_Operation.rrr(self.stack_a, self.stack_b)
        elif i == b'rra':
            PS_Operation.rrx(self.stack_a)
        elif i == b'rrb':
            PS_Operation.rrx(self.stack_b)
        self.update()

    def clear(self):
        self.rgb = []
        self.stack_a = []

