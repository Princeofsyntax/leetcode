# Write your MySQL query statement below
SELECT 
    v.customer_id, COUNT(customer_id) AS count_no_trans
FROM 
    Visits v # same as Visits AS v
LEFT JOIN
    Transactions t
ON 
    v.visit_id = t.visit_id
WHERE 
    t.transaction_id is NULL
GROUP BY
    v.customer_id