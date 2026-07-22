
-- create view for Active Employees
create view ActiveEmps as 
select * from Employees
where ExitDate is Null

-- usage the ActiveEmps view
select * from ActiveEmps
where MonthlySalary between 500 and 1000
order by FirstName;


-- create view for retired Employees
create view RetiredEmps as 
select * from Employees
where ExitDate is NOT Null


-- usage the RetiredEmps view
select * from RetiredEmps ;

select TotalRetiredEmployees = count(ID) from RetiredEmps
where DepartmentID = 1;



-------------
create view EmployeeInfo  as
select ID, FirstName, LastName, Gendor from Employees

-- usage the created view
select * from EmployeeInfo
where (FirstName  +  ' ' + LastName) = 'Ahmed Kamal'



select * from ActiveEmps 
where ID = 500;