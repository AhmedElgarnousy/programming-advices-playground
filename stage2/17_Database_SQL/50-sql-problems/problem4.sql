-- Problem 4 : Get number vehicles made between 1950 and 2000 per make
--and order them by Number Of Vehicles Descending

SELECT Make, COUNT(*) AS NumberOfVehicles
FROM NumOfVehiclesPerMake -- your view between VehicleDetails and Makes Tables
GROUP BY Make
ORDER BY NumberOfVehicles DESC;


