WITH daily_sales AS (
    SELECT
        visited_on,
        SUM(amount) AS sales
    FROM
        Customer
    GROUP BY
        visited_on
),
weekly_sales AS (
    SELECT
        visited_on,
        SUM(sales) OVER (
            ORDER BY
                visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS total_sales
    FROM
        daily_sales
)
SELECT
    visited_on,
    total_sales AS amount,
    ROUND(total_sales / 7, 2) AS average_amount
FROM
    weekly_sales
WHERE
    visited_on >= (
        SELECT
            MIN(visited_on) + INTERVAL '6 DAY'
        FROM
            Customer
    )
ORDER BY
    visited_on;
