select * from Employees;

insert into Employees (ID, name )
values 
(10, 'Emp10'),
(8, 'Emp8');

delete from Employees where Salary = NULL; --- wrong
delete from Employees where Salary is NULL; 