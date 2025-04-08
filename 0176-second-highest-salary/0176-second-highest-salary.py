import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    employee.drop_duplicates(['salary'], inplace=True)
    if employee.shape[0] < 2:
        return pd.DataFrame({f'SecondHighestSalary': [None]})
    employee.sort_values(['salary'], ascending=False, inplace=True)
    return pd.DataFrame({f'SecondHighestSalary': [employee.iloc[1, -1]]})