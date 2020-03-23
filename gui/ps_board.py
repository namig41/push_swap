from PyQt5 import QtWidgets, QtCore, QtGui
from PyQt5.QtWidgets import QMessageBox
from ps_operation import PS_Operation
import ps_operation
import random
import time

class StackBoard(QtWidgets.QWidget):
    def __init__(self, parent):
        super(StackBoard, self).__init__(parent)
        self.setGeometry(QtCore.QRect(30, 30, 850, 880))

        self.max = float('-inf')
        self.stack_size = ps_operation.STACK_MIN_SIZE

        self.rgb = []
        self.stack_a = []
        self.stack_b = []
        self.sort_stack_a = []
        self.list_operations = []
        self.w = self.size().width()
        self.h = self.size().height()
        self.timer = QtCore.QTimer(self)

        self.image_path = ""
        self.image = None
        self.finish = False 

    def paintEvent(self, e):
        paint = QtGui.QPainter()

        paint.begin(self)
        if not self.finish or not self.image:
            self.draw_stack(paint)
        else:
            self.show_image(paint)
        paint.end()

    def draw_stack(self, paint):
        k = self.h / self.stack_size;

        if not self.image:
            paint.setBrush(QtGui.QColor(*self.rgb, 160))
            for i in range(self.stack_size):
                if i < len(self.stack_a):
                    paint.drawRect(0, i * k, 
                            self.stack_a[len(self.stack_a) - i - 1] / self.max * (self.w >> 1), k)
                if i < len(self.stack_b):
                    paint.drawRect(self.w, i * k, 
                            -self.stack_b[len(self.stack_b) - i - 1] / self.max * (self.w >> 1), k)
        
        else:
            for i in range(self.stack_size):
                if i < len(self.stack_a):
                    elem = self.stack_a[len(self.stack_a) - i - 1]
                    rect_a = QtCore.QRect(0, i * k, elem / self.max * (self.w >> 1), k)
                    img_rect_a = QtCore.QRect(0, self.sort_stack_a.index(elem) * k,
                                                elem / self.max * (self.w >> 1), k)

                    paint.drawImage(rect_a, self.image.copy(img_rect_a))
                if i < len(self.stack_b):
                    elem = self.stack_b[len(self.stack_b) - i - 1]
                    off = elem / self.max * (self.w >> 1)
                    rect_b = QtCore.QRect(self.w - off, i * k, off, k)
                    img_rect_b = QtCore.QRect(0, self.sort_stack_a.index(elem) * k,
                                                elem / self.max * (self.w >> 1), k)

                    paint.drawImage(rect_b, self.image.copy(img_rect_b))


    def show_image(self, paint):
        if self.image:
            rect = QtCore.QRect(0, 0, self.w, self.h)
            paint.drawImage(rect, self.image.copy(rect))

    def run(self):
        if len(self.list_operations) == 0:
            self.timer.stop()
            QMessageBox.information(self, "Результат", "Количество операций: " + str(self.count_operations))
            self.finish = True
        else:
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
        self.max = float('-inf')
        self.stack_size = ps_operation.STACK_MIN_SIZE

        self.rgb = []
        self.stack_a = []
        self.sort_stack_a = []

        self.image_path = ""
        self.image = None
        self.finish = False 

