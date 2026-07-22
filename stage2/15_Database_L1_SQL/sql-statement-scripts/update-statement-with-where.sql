
UPDATE Employees set Name = 'ahmed-kamal' where name = 'Emp1'

select * from Employees;

--- each employee's salary less than 500$ increare it 200$ 
update Employees 
set Salary = Salary + 200
where Salary < 500;

--- each employee's salary less than 1000$ increare it 10% 
update Employees 
set Salary = Salary * 1.1 
where Salary < 1000;
