select ID,FirstName, MonthlySalary from Employees
where DepartmentID = 1
ORDER BY FirstName; -- By Default Order Ascending(ASC) NOT descending(DESC)

select ID,FirstName, MonthlySalary from Employees
where DepartmentID = 1
ORDER BY FirstName DESC;

select ID,FirstName, MonthlySalary from Employees
where DepartmentID = 1
ORDER BY FirstName, MonthlySalary; -- order by 2 categories

select ID,FirstName, MonthlySalary from Employees
where DepartmentID = 1
ORDER BY FirstName ASC, MonthlySalary DESC; 