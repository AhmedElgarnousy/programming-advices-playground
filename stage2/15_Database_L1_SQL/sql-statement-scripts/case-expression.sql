select * ,
NewSalaryTobe =
CASE
	WHEN Gendor = 'M' THEN MonthlySalary * 1.1
	WHEN Gendor = 'F' THEN MonthlySalary * 1.15
	ELSE '0'
END
from Employees

select ID, FirstName, LastName, GendorTitle =
CASE
    WHEN Gendor='M' THEN 'Male'
    WHEN Gendor='F' THEN 'Female'
    ELSE 'Unknown'
END

from Employees

-----------------------------------------

select ID, FirstName, LastName,  GendorTitle =
CASE
    WHEN Gendor='M' THEN 'Male'
    WHEN Gendor='F' THEN 'Female'
    ELSE 'Unknown'
END,

Status =
CASE
    WHEN ExitDate is null THEN 'Active'
    WHEN Gendor is Not null THEN 'Resigned'
END
from Employees

-------------------------------------------------------

select ID, FirstName, LastName,MonthlySalary,

NewSalaryToBe =
CASE
    WHEN Gendor='M' THEN MonthlySalary * 1.1
    WHEN Gendor='F' THEN MonthlySalary * 1.15
   
END
from Employees
