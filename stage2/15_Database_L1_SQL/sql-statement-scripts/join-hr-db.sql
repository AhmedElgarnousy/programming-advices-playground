
--This code for HR_Database
--Inner Join two Tables
SELECT        Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName
FROM            Employees INNER JOIN
                         Departments ON Employees.DepartmentID = Departments.ID


--Inner joind with where
SELECT        Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName
FROM            Employees INNER JOIN
                         Departments ON Employees.DepartmentID = Departments.ID
where Departments.Name = 'IT';


--Inner Join Three Tables
SELECT        Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName, Countries.Name AS CountryName
FROM            Employees INNER JOIN
                         Departments ON Employees.DepartmentID = Departments.ID INNER JOIN
                         Countries ON Employees.CountryID = Countries.ID


						 
--Inner Join Three Tables with where
SELECT        Employees.ID, Employees.FirstName, Employees.LastName, Departments.Name as DeptName, Countries.Name AS CountryName
FROM            Employees INNER JOIN
                         Departments ON Employees.DepartmentID = Departments.ID INNER JOIN
                         Countries ON Employees.CountryID = Countries.ID
	where Countries.Name = 'USA';

--- inner join using design query in editor 
SELECT Employees.FirstName, Employees.LastName, Departments.Name as DeptName
FROM     Departments INNER JOIN
                  Employees ON Departments.ID = Employees.DepartmentID