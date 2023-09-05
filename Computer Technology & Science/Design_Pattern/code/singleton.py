class Singleton(object):
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, '__instance'):
            print("__new__ called!")
            cls.__instance = super().__new__(cls)
        return cls
    
    def __init__(self, data):
        cls = type(self)
        if not hasattr(cls, "__init"):
            print("__init__ is called")
            self.data = data
            cls.__init = True

s1 = Singleton()
s2 = Singleton()
print(s1)
print(s2)
print(s1 is s2)
