class PS_Operation():
    @staticmethod
    def ph(a, b):
        a.append(b.pop())
    
    @staticmethod
    def ss(a, b):
        PS_Operation.sx(a);
        PS_Operation.sx(b);
    
    @staticmethod
    def sx(x):
        x.insert(-1, x.pop())
    
    @staticmethod
    def rr(a, b):
        PS_Operation.rx(a);
        PS_Operation.rx(b);
    
    @staticmethod
    def rx(x):
       x.insert(0, x.pop()) 

    @staticmethod
    def rrr(a, b):
        PS_Operation.rrx(a);
        PS_Operation.rrx(b);

    @staticmethod
    def rrx(x):
       x.append(x.pop(0))

STACK_MIN_SIZE  = 10
DEF_SIZE        = 100

