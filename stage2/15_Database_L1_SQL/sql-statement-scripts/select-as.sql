select A = 3*4, B= 2/1;

--  look at the result
select A = 3*4, B= 2/1  from Employees;

-- make it usefull
select ID,FirstName, ExpectedSalary= MonthlySalary * 1.1  from Employees;

select FirstName + ' ' + LastName as FullName from Employees;


select FirstName + ' ' + LastName as FullName, 
Age = DATEDIFF(year, DateOfBirth, getDate()) from Employees;
