from Employee import Employee

e = Employee()

print(getattr(e, 'emp_age'))
setattr(e, 'emp_age', 100)
print(getattr(e, 'emp_age', 45))

setattr(e, 'emp_sex', 'man')
print(getattr(e, 'emp_sex', 'woman'))

