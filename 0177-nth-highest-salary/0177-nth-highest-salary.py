import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    employee.drop_duplicates(['salary'], inplace=True)
    employee.sort_values(['salary'], ascending=False, inplace=True)
    if N <= 0 or N > employee.shape[0]:
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
    return pd.DataFrame({f'getNthHighestSalary({N})': [employee.iloc[N - 1, -1]]})