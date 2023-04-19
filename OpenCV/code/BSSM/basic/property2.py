class Dog:
    def __init__(self) -> None:
        self.__ownername = "default name"
        
    @property
    def name(self):
        return self.__ownername
    
    @name.setter
    def name(self, name):
        self.__ownername = name
        
# get, set도 달라짐
myDog = Dog()
myDog.name = "Happy"
print(myDog.name)