import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.query('employee_id % 2 == 1 & name.str[0] != "M"')['salary']
    employees['bonus'].fillna(0, inplace=True)
    employees.sort_values(['employee_id'], inplace=True)
    return employees[['employee_id', 'bonus']]