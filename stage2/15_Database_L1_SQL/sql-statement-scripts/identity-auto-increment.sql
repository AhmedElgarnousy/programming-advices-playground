select * from Departments;

--- create the table named Department by SSMS GUI
--- and insert data into this table
--- also add the ID (identity yes , inc by 1, start from 1)

--- second way by script

CREATE TABLE Departments2(
ID int identity(1,1) NOT NULL,
Name nvarchar(200) NOT NULL,
PRIMARY KEY (ID));

---

insert into Departments
values
('Office');

print @@identity --- return last idenity number

--- note if you delete the data it table and start add values again
--- it will start from the last number
--- it will not clear or decrement the identity varible with delete statement

delete Departments where ID = 6



