Результаты 100 прогонов лежат в sum_by_rows_results и в sum_by_columns_results

Среднее по строкам:  331939.24 us

Среднее по столбцам: 2167000.69 us

Результаты valgrind:

По строкам:
```
LLd miss rate: 1.6% ( 0.9% + 6.2% )
```
По столбцам:
```
LLd miss rate: 12.9% (13.9% + 6.2% )
```

Видим, что промахи в кэш при непоследовательном обращении в память выше, т.к. блоки в памяти, к которым мы обращаемся при суммировании по столбцам лежат не последовательно.
