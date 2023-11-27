# Write your MySQL query statement below
select e.name, eu.unique_id from Employees e left join EmployeeUNI eu on e.id = eu.id; 