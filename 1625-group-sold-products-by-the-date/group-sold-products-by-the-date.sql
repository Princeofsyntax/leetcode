# Write your MySQL query statement below
#create a function of feasibility
SELECT 
    sell_date, 
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(
       DISTINCT product
       ORDER BY product
       SEPARATOR ','   #by default it is already taken so u can even ignore it
    ) AS products 
FROM 
    Activities
GROUP BY 
    sell_date
ORDER BY 
    sell_date, product