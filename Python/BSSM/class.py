class T:
    def __new__(self):      # 힙에 실제 데이터 저장, self는 각 객체의 시작주소
        pass
    
    def __init__(self):     # 인스턴스 변수들 값 초기화
        self.a = None      
    
    def __del__(self):      # 소멸자
        pass
    
    # 위의 함수는 클래스 선언시 자동으로 정의됨
    
    def foo(self): pass
    def foo2(self, n): self.a = n
    def __foo3(self, n): pass  # 외부에서 접근 불가능! Private 자료형
    
class TT(T):    # 상속
    def __init__(self):
        super().__init__()  # 필수!
        self.__b
    
    def foo2(self, a, b):   # 오버라이딩
        self.__b = b        # 자식이 일아서
        super().foo3(a)      # 부모가 알아서(부모 함수는 가려짐)
    
t1 = T()    # 인스턴스 생성, t는 각 객체들의 주소 데이터를 가지고 있음. 그리고 이를 인터프리터가 자동을 인식하고 처리해줌
t2 = T()    # attribute가 다른 자료구조를 각각 저장한다고 생각하믄 편함

t1.foo()    # 저마다 다른 주소를 가르킴 -> self 변수가 있기 때문에! 
t2.foo()  

t1.foo2(10) # self 생략 가능!

t1.a = 100  # 다 다른 공간을 지니고 있음!
t2.a = 200  