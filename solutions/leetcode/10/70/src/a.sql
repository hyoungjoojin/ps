WITH LaunchYear (product_id, year) AS (
    SELECT
        product_id,
        MIN(year)
    FROM
        Sales
    GROUP BY
        product_id
)
SELECT
    s.product_id AS product_id,
    s.year AS first_year,
    s.quantity AS quantity,
    s.price AS price
FROM
    Sales AS s
    JOIN LaunchYear AS l ON s.product_id = l.product_id
    AND s.year = l.year;
