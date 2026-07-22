
Restore Database HR_Database 
from disk ='E:\general_courses\programming-advices\stage2\15_Database_L1_SQL\HR_Database.bak';

use HR_Database;

EXEC sp_changedbowner 'sa';


select * from Employees;

-- * equivilant to TableName.*
select Employees.* from Employees;

select ID from Employees

-- Employees.ID equivilant to ID
select Employees.ID from Employees

Select ID, FirstName, LastName,MonthlySalary From Employees;

Select ID, FirstName, DateOfBirth From Employees;

Select * from Departments;

Select * from Countries;

