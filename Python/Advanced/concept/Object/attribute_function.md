# Attribure Function

딥러닝 모델의 config를 일반적으로 object의 변수로 설정하여 받아오는 경우가 많다. 큰 규모의 딥러닝 모델의 경우 여러 config를 변경하여 모델을 설정해야 한다. 이때 해당 함수들을 사용하여 코드 내부에서 config를 변경 및 확인 작업을 해줄 수 있다.

함수 종류 : **getattr, hasattr, setattr, delattr**

## 1. getattr()

- Basic Syntax : `getattr(object, attribute_name[, default])`
- object 안에 찾고자하는 attribute의 값을 출력한다. 만약 없을 경우 default를 출력한다.

Code - Employee.py

```python
class Employee:
    emp_comp    = "Google"
    emp_age     = 49
    default_age = 56

    def defaultMethod(self):
        print("This is a default method")
```

Code - getattr.py

```python
from Employee import Employee

e = Employee()
print(getattr(e, 'emp_age'))
print(getattr(e, 'emp_age', 45))
print(getattr(e, 'emp_age_other', 45))
print(getattr(e, 'emp_age_other', e.default_age))
```

![getattr](../../image/Object/getattr.png)