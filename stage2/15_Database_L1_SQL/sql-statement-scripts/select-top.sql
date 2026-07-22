select top 5 * from Employees;

select FirstName, MonthlySalary from Employees
ORDER BY MonthlySalary DESC;


select top 10 FirstName, MonthlySalary from Employees
ORDER BY MonthlySalary DESC;




--- say to me the employee'names that have the top 3 salaries
select FirstName, MonthlySalary from Employees
where MonthlySalary
in (select DISTINCT TOP 3 MonthlySalary from Employees
ORDER BY MonthlySalary DESC);



select DISTINCT TOP 3 MonthlySalary from Employees
ORDER BY MonthlySalary DESC;

select top 5 PERCENT * from Employees;
