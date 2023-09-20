class Foo:
      value = 1

      def __del__(self):
            print(f'{self.__class__}(0x{id(self):016X}) is being destroyed.')

a = Foo()
a = 1       # Destroy

a = Foo()
b = Foo()
a = b       # 전에 있었던 a의 Foo 객체 Destroy

b = 1
a = 1       # Destroy