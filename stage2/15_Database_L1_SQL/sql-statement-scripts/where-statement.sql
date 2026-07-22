select * from Employees where Gendor='F';

SELECT * FROM Employees WHERE NOT MonthlySalary <= 500;
SELECT * FROM Employees WHERE CountryID = 1;
SELECT * FROM Employees WHERE NOT CountryID = 1;

-- Standard Compliance:
-- The <> operator follows the official ISO/ANSI SQL standard (SQL-92 and newer).
-- The != operator is a non-standard extension.

SELECT * FROM Employees 
WHERE CountryID != 1;

SELECT * FROM Employees 
WHERE CountryID <> 1;

SELECT * FROM Employees 
WHERE DepartmentID = 1 AND Gendor = 'M';

-- return nothing because relationship is one-to-many
SELECT * FROM Employees 
WHERE DepartmentID = 1 AND DepartmentID = 2;

SELECT * FROM Employees
WHERE ExitDate is Null;

SELECT * FROM Employees
WHERE ExitDate = '2014-02-14 00:00:00'



-- print @@identity
