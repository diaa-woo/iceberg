class Parent:
    num = 0
    # constructor(생성자)
    def __init__(self, num) -> None :
        self.num = num
        print('Constructor of the parent class was called')
    
class Child(Parent):
    def __init__(self, num) -> None:
        super().__init__(num)
        print('Constructor of the child class was called')
    
    # child에만 추가된 함수
    def displayValue(self):
        print('num : ', self.num)
        
cd = Child(20)
cd.displayValue()