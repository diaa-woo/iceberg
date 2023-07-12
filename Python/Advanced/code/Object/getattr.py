from Employee import Employee

e = Employee()
print(getattr(e, 'emp_age'))
print(getattr(e, 'emp_age', 45))
print(getattr(e, 'emp_age_other', 45))
print(getattr(e, 'emp_age_other', e.default_age))
