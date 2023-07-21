from Employee import Employee

e = Employee()
e1 = Employee()

print(hasattr(e, 'emp_comp'))     
print(hasattr(e1, 'emp_comp'))      
delattr(Employee, 'emp_comp')    
print(hasattr(e, 'emp_comp'))     
print(hasattr(e1, 'emp_comp'))     

print(hasattr(e, 'emp_age'))     
print(hasattr(e1, 'emp_age'))     
del Employee.emp_age                # Same = delattr(Employee, 'emp_age')
print(hasattr(e, 'emp_age'))      
print(hasattr(e1, 'emp_age'))     