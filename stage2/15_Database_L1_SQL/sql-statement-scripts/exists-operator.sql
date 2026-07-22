select x = 'exists operator return yes'
where exists
(
	select * from orders
	where CustomerID = 3 and Amount < 600
)

-- improved syntax that the previous query

SELECT 'exists operator return yes' AS Result
WHERE EXISTS
(
    SELECT 1 FROM Orders
    WHERE CustomerID = 3 AND Amount < 600
);


--
select * from Customers T1
where 
exists 
( 
	select * from Orders
	where customerID= T1.CustomerID and Amount < 600
)

--More optimized and faster
select * from Customers T1
where 
exists 
( 
	select top 1 * from Orders
	where customerID= T1.CustomerID and Amount < 600
)


--More optimized and faster
select * from Customers T1
where 
  exists 
   ( 
	select top 1 R='Y'  from Orders
	where customerID= T1.CustomerID and Amount < 600
	)