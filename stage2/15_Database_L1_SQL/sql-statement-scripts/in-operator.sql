select * from Employees
where DepartmentID = 1 or DepartmentID = 2;

-- in operator
select * from Employees
where DepartmentID in (1,3,2);

select * from Employees
where ID = 351 or  ID = 354 ;

select * from Employees
where ID in (351,354);

-- note no ID equals 3
select * from Employees
where ID = 351 or  ID = 354 or ID = 3;

select * from Employees
where ID in (351,354,3);

-- write a query to get the department names which has employee'salary less than 210

-- select DepartmentID from Employees where MonthlySalary < 210; -- returns list of IDs
-- then gets the department name of each ID

select Name from Departments 
where ID 
in (select DepartmentID from Employees where MonthlySalary < 210);

select Departments.Name from Departments 

