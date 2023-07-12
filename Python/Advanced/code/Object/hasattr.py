from Employee import Employee

e = Employee()
e1 = Employee()

print(hasattr(e, 'emp_address'))
setattr(e, 'emp_address', 'Korea')
print(hasattr(e, 'emp_address'))
print(hasattr(e1, 'emp_address'))