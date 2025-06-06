import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees['total_time'] = employees['out_time'] - employees['in_time']
    employees = employees.groupby(['event_day', 'emp_id'], as_index=False).sum()
    employees = employees.rename(columns={'event_day': 'day'})
    employees = employees.drop(columns=['out_time', 'in_time'])
    employees = employees.sort_values('day')
    return employees