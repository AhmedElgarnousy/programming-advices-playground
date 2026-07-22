
select Customers.CustomerID, Customers.Name, Orders.Amount from Customers 
LEFT JOIN Orders 
on  Customers.CustomerID = Orders.CustomerID 



--- way design query
SELECT Customers.Name, Customers.CustomerID, Orders.Amount
FROM     Customers LEFT OUTER JOIN
                  Orders ON Customers.CustomerID = Orders.CustomerID